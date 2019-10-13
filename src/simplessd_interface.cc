#include "assert_macros.h"
#include "bug_detector.h"
#include "debug_macros.h"
#include "dram_ctrl.h"
#include "memory.h"
#include "memreq_info.h"
#include "network.h"
#include "progress_checker.h"
#include "utils.h"

#include "all_knobs.h"
#include "statistics.h"

#include <cstdio>
#include "simplessd_interface.h"

#include "simplessd/log/log.hh"

#define DEBUG(args...) _DEBUG(*m_simBase->m_knobs->KNOB_DEBUG_DRAM, ##args)

dram_c *simplessd_interface(macsim_c *simBase) {
  dram_c *simplessd_interface_tmp = new simplessd_interface_c(simBase);
  return simplessd_interface_tmp;
}

simplessd_interface_c::simplessd_interface_c(macsim_c *simBase)
    : dram_c(simBase) {
  m_cycle = 0;
  SimpleSSD::Logger::initLogSystem(std::cout, std::cerr, [this]() -> uint64_t {
    return m_cycle * 1000 / clock_freq;
  });

  if (!configReader.init((string)*m_simBase->m_knobs->KNOB_SIMPLESSD_CONFIG)) {
    printf("Failed to read SimpleSSD configuration file!\n");

    terminate();
  }

  clock_freq = *m_simBase->m_knobs->KNOB_CLOCK_MC;

  pHIL = new SimpleSSD::HIL::HIL(&configReader);
  m_output_buffer = new map<unsigned long long, mem_req_s *>;
  m_input_buffer = new map<unsigned long long, mem_req_s *>;

  pHIL->getLPNInfo(totalLogicalPages, logicalPageSize);
}

simplessd_interface_c::~simplessd_interface_c() {
  delete pHIL;
  delete m_output_buffer;
  delete m_input_buffer;
}

void simplessd_interface_c::init(int id) {
  m_id = id;
}

void simplessd_interface_c::send(void) {
  bool req_type_checked[2];
  req_type_checked[0] = false;
  req_type_checked[1] = false;

  bool req_type_allowed[2];
  req_type_allowed[0] = true;
  req_type_allowed[1] = true;

  int max_iter = 1;
  if (*KNOB(KNOB_ENABLE_NOC_VC_PARTITION))
    max_iter = 2;

  // when virtual channels are partitioned for CPU and GPU requests,
  // we need to check individual buffer entries
  // if not, sequential search would be good enough
  for (int ii = 0; ii < max_iter; ++ii) {
    req_type_allowed[0] = !req_type_checked[0];
    req_type_allowed[1] = !req_type_checked[1];
    // check both CPU and GPU requests
    if (req_type_checked[0] == true && req_type_checked[1] == true)
      break;
    for (auto I = m_output_buffer->begin(), E = m_output_buffer->end();
         I != E;) {
      if (I->first > m_cycle)
        break;

      mem_req_s *req = I->second;
      if (req_type_allowed[req->m_ptx] == false) {
        ++I;
        continue;
      }

      req_type_checked[req->m_ptx] = true;
      req->m_msg_type = NOC_FILL;

      bool insert_packet =
          NETWORK->send(req, MEM_MC, m_id, MEM_L3, req->m_cache_id[MEM_L3]);

      if (!insert_packet) {
        DEBUG("MC[%d] req:%d addr:0x%llx type:%s noc busy\n", m_id, req->m_id,
              req->m_addr, mem_req_c::mem_req_type_name[req->m_type]);
        break;
      }

      if (*KNOB(KNOB_BUG_DETECTOR_ENABLE) && *KNOB(KNOB_ENABLE_NEW_NOC)) {
        m_simBase->m_bug_detector->allocate_noc(req);
      }
      I = m_output_buffer->erase(I);

      m_simBase->m_progress_checker->decrement_outstanding_requests();
      m_simBase->m_progress_checker->update_dram_progress_info(
          m_simBase->m_simulation_cycle);
    }
  }
}

void simplessd_interface_c::receive(void) {
  // check router queue every cycle
  mem_req_s *req = NETWORK->receive(MEM_MC, m_id);
  if (req){
    SimpleSSD::ICL::Request request;

    request.reqID = req->m_id;
    request.offset = req->m_addr % logicalPageSize;
    request.length = req->m_size;
    request.range.slpn = req->m_addr / logicalPageSize;
    request.range.nlp = (req->m_size + request.offset + logicalPageSize - 1) /
                        logicalPageSize;
  
    uint64_t finishTick =
        static_cast<unsigned long long>(m_cycle * 1000 / clock_freq); 
    pHIL->checkAvailableTime(request, finishTick);
    if (finishTick <= static_cast<unsigned long long>(m_cycle * 1000 / clock_freq))
      insert_new_req(req);
    else{
      finishTick = finishTick * clock_freq / 1000;
      while (1){
        auto iter = m_input_buffer->find(finishTick);
        if (iter != m_input_buffer->end()) finishTick++;
        else break;
      }
      m_input_buffer->insert( pair<unsigned long long, mem_req_s *>(
            finishTick, req));     
    }
    NETWORK->receive_pop(MEM_MC, m_id);
    if (*KNOB(KNOB_BUG_DETECTOR_ENABLE)) {
      m_simBase->m_bug_detector->deallocate_noc(req);
    }

    m_simBase->m_progress_checker->increment_outstanding_requests();
  }

  auto I = m_input_buffer->begin();
  auto E = m_input_buffer->end();
  if ((I != E) && (I->first <= m_cycle)){
    SimpleSSD::ICL::Request request;

    request.reqID = (I->second)->m_id;
    request.offset = (I->second)->m_addr % logicalPageSize;
    request.length = (I->second)->m_size;
    request.range.slpn = (I->second)->m_addr / logicalPageSize;
    request.range.nlp = ((I->second)->m_size + request.offset + logicalPageSize - 1) /
                        logicalPageSize;
  
    uint64_t finishTick =
        static_cast<unsigned long long>(m_cycle * 1000 / clock_freq); 
    pHIL->checkAvailableTime(request, finishTick);   
    if (finishTick <= static_cast<unsigned long long>(m_cycle * 1000 / clock_freq)){
      insert_new_req(I->second);
      m_input_buffer->erase(I);
    }
    else{
        finishTick = finishTick * clock_freq / 1000;
        while (1){
          auto iter = m_input_buffer->find(finishTick);
          if (iter != m_input_buffer->end()) finishTick++;
          else break;
        }
        mem_req_s * tmp_req = I->second;
        m_input_buffer->erase(I);
        m_input_buffer->insert( pair<unsigned long long, mem_req_s *>(
              finishTick, tmp_req)); 
    }
  }
}

bool simplessd_interface_c::insert_new_req(mem_req_s *mem_req) {
  SimpleSSD::ICL::Request request;

  request.reqID = mem_req->m_id;
  request.offset = mem_req->m_addr % logicalPageSize;
  request.length = mem_req->m_size;
  request.range.slpn = mem_req->m_addr / logicalPageSize;
  request.range.nlp = (mem_req->m_size + request.offset + logicalPageSize - 1) /
                      logicalPageSize;
  request.pc = mem_req->m_pc;
  request.thread_id = mem_req->m_thread_id;

  uint64_t finishTick =
      static_cast<unsigned long long>(m_cycle * 1000 / clock_freq);

  // cout << "Jie: warp " << mem_req->m_thread_id << " pc " << mem_req->m_pc << " addr " 
  //      << mem_req->m_addr << " page " << request.range.slpn 
  //      << " cta " << mem_req->m_block_id << endl;

  SimpleSSD::Logger::info("Request arrived at %lu cycle (%" PRIu64 " ps)",
                          m_cycle, finishTick);

  if (mem_req->m_dirty)
    pHIL->write(request, finishTick);
  else
    pHIL->read(request, finishTick);

  finishTick = finishTick * clock_freq / 1000 ;
  SimpleSSD::Logger::info("Request finished at %lu cycle, delay %d cycle", 
                                    finishTick, finishTick - m_cycle);
  if (mem_req->m_type == MRT_WB){
    MEMORY->free_req(mem_req->m_core_id, mem_req);     
  }
  else{
    while (1){
      auto iter = m_output_buffer->find(finishTick);
      if (iter != m_output_buffer->end()) finishTick++;
      else break;
    }

    m_output_buffer->insert(pair<unsigned long long, mem_req_s *>(
        static_cast<unsigned long long>(finishTick), mem_req));
  }
  return true;
}

// tick a cycle
void simplessd_interface_c::run_a_cycle(bool pll_lock) {
  if (pll_lock) {
    ++m_cycle;
    return;
  }
  send();

  receive();

  ++m_cycle;
}

void simplessd_interface_c::print_req(void) {
  FILE *fp = fopen("bug_detect_dram.out", "w");

  fprintf(fp, "Current cycle:%llu\n", m_cycle);
  // fprintf(fp, "Total req:%d\n", m_total_req);
  fprintf(fp, "\n");
  fclose(fp);

  //  g_memory->print_mshr();
}
