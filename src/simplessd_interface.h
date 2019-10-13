#ifndef SIMPLESSD_INTERFACE_H_
#define SIMPLESSD_INTERFACE_H_
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

#include "dram.h"
#include "global_defs.h"
#include "global_types.h"
#include "macsim.h"

#include "simplessd/hil/hil.hh"

class simplessd_interface_c : public dram_c {
 public:
  simplessd_interface_c(macsim_c *simBase);
  ~simplessd_interface_c();
  void init(int id);
  void run_a_cycle(bool);
  void send(void);
  void receive(void);
  void print_req(void);
  bool insert_new_req(mem_req_s *);

 private:
  SimpleSSD::ConfigReader configReader;
  SimpleSSD::HIL::HIL *pHIL;
  uint64_t totalLogicalPages;
  uint32_t logicalPageSize;

  float clock_freq;
  map<unsigned long long, mem_req_s *> *m_output_buffer;
  map<unsigned long long, mem_req_s *> *m_input_buffer;
};

#endif
