#include "all_knobs.h"

#include <string>

all_knobs_c::all_knobs_c() {
  // =========== ../def/bp.param.def ===========
  KNOB_BP_HIST_LENGTH = new KnobTemplate<uns>("bp_hist_length", 5);
  KNOB_PHT_CTR_BITS = new KnobTemplate<uns>("pht_ctr_bits", 2);
  KNOB_BP_DIR_MECH = new KnobTemplate<string>("bp_dir_mech", "gshare");
  KNOB_EXTRA_RECOVERY_CYCLES =
      new KnobTemplate<uns>("extra_recovery_cycles", 0);
  KNOB_USE_BRANCH_PREDICTION =
      new KnobTemplate<bool>("use_branch_prediction", true);
  KNOB_PERFECT_BP = new KnobTemplate<bool>("perfect_bp", false);
  KNOB_PERFECT_BTB = new KnobTemplate<bool>("perfect_btb", true);
  KNOB_BTB_ENTRIES = new KnobTemplate<uns>("btb_entries", 1024);
  KNOB_BTB_ASSOC = new KnobTemplate<uns>("btb_assoc", 4);
  KNOB_BTB_BANK_NUM = new KnobTemplate<uns>("btb_bank_num", 1);
  KNOB_ENABLE_BTB = new KnobTemplate<bool>("enable_btb", false);

  // =========== ../def/core.param.def ===========
  KNOB_FE_SIZE = new KnobTemplate<uns32>("fe_size", 256);
  KNOB_SCHED_CLOCK = new KnobTemplate<uns32>("sched_clock", 1);
  KNOB_ALLOC_TO_EXEC_LATENCY =
      new KnobTemplate<uns32>("alloc_to_exec_latency", 1);
  KNOB_GIAQ_SIZE = new KnobTemplate<uns32>("giaq_size", 32);
  KNOB_MIAQ_SIZE = new KnobTemplate<uns32>("miaq_size", 16);
  KNOB_FQ_SIZE = new KnobTemplate<uns32>("fq_size", 32);
  KNOB_GIAQ_MEDIUM_SIZE =
      new KnobTemplate<uns32>("giaq_medium_size", 32, "giaq_size");
  KNOB_MIAQ_MEDIUM_SIZE =
      new KnobTemplate<uns32>("miaq_medium_size", 16, "miaq_size");
  KNOB_FQ_MEDIUM_SIZE =
      new KnobTemplate<uns32>("fq_medium_size", 32, "fq_size");
  KNOB_GIAQ_LARGE_SIZE =
      new KnobTemplate<uns32>("giaq_large_size", 32, "giaq_size");
  KNOB_MIAQ_LARGE_SIZE =
      new KnobTemplate<uns32>("miaq_large_size", 16, "miaq_size");
  KNOB_FQ_LARGE_SIZE = new KnobTemplate<uns32>("fq_large_size", 32, "fq_size");
  KNOB_GEN_ALLOCQ_INDEX = new KnobTemplate<int>("giaq_index", 0);
  KNOB_MEM_ALLOCQ_INDEX = new KnobTemplate<int>("miaq_index", 1);
  KNOB_FLOAT_ALLOCQ_INDEX = new KnobTemplate<int>("fiaq_index", 2);
  KNOB_ONE_CYCLE_EXEC = new KnobTemplate<bool>("one_cycle_exec", 0);
  KNOB_MAX_INSTS = new KnobTemplate<uns32>("max_insts", 1000);
  KNOB_SIM_CYCLE_COUNT = new KnobTemplate<uns32>("sim_cycle_count", 1000000);
  KNOB_FORWARD_PROGRESS_LIMIT =
      new KnobTemplate<uns64>("forward_progress_limit", 100000);
  KNOB_MAX_BLOCK_PER_CORE_SUPER =
      new KnobTemplate<int>("max_block_per_core_super", 0);
  KNOB_ROB_SIZE = new KnobTemplate<uns16>("rob_size", 128);
  KNOB_ROB_MEDIUM_SIZE =
      new KnobTemplate<uns16>("rob_medium_size", 128, "rob_size");
  KNOB_ROB_LARGE_SIZE =
      new KnobTemplate<uns16>("rob_large_size", 128, "rob_size");
  KNOB_INT_REGFILE_SIZE = new KnobTemplate<uns16>("int_regfile_size", 128);
  KNOB_FP_REGFILE_SIZE = new KnobTemplate<uns16>("fp_regfile_size", 128);
  KNOB_MEU_NSB = new KnobTemplate<uns16>("meu_nsb", 64);
  KNOB_MEU_NLB = new KnobTemplate<uns16>("meu_nlb", 64);
  KNOB_MEU_MEDIUM_NSB =
      new KnobTemplate<uns16>("meu_medium_nsb", 64, "meu_nsb");
  KNOB_MEU_MEDIUM_NLB =
      new KnobTemplate<uns16>("meu_medium_nlb", 64, "meu_nlb");
  KNOB_MEU_LARGE_NSB = new KnobTemplate<uns16>("meu_large_nsb", 64, "meu_nsb");
  KNOB_MEU_LARGE_NLB = new KnobTemplate<uns16>("meu_large_nlb", 64, "meu_nlb");
  KNOB_WIDTH = new KnobTemplate<uns16>("width", 2);
  KNOB_MEDIUM_WIDTH = new KnobTemplate<uns16>("medium_width", 2, "width");
  KNOB_LARGE_WIDTH = new KnobTemplate<uns16>("large_width", 2, "width");
  KNOB_EXEC_RETIRE_LATENCY = new KnobTemplate<int>("exec_retire_latency", 1);
  KNOB_MEM_OBEY_STORE_DEP = new KnobTemplate<bool>("mem_obey_store_dep", true);
  KNOB_MEM_OOO_STORES = new KnobTemplate<bool>("mem_ooo_stores", true);
  KNOB_USE_NEW_ORACLE = new KnobTemplate<bool>("use_new_oracle", false);
  KNOB_IGNORE_DEP = new KnobTemplate<bool>("ignore_dep", false);
  KNOB_HEARTBEAT_INTERVAL = new KnobTemplate<uns>("heartbeat_interval", false);
  KNOB_GPU_FETCH_RATIO = new KnobTemplate<int>("fetch_ratio", 1);
  KNOB_GPU_SCHEDULE_RATIO = new KnobTemplate<int>("schedule_ratio", 1);
  KNOB_CPU_FETCH_RATIO = new KnobTemplate<int>("cpu_fetch_ratio", 1);
  KNOB_PTX_EXEC_RATIO = new KnobTemplate<int>("ptx_exec_ratio", 4);
  KNOB_PTX_INST_LATENCY = new KnobTemplate<int>("ptx_inst_latency", 20);
  KNOB_PTX_DISPATCH_LATENCY_FACTOR =
      new KnobTemplate<int>("ptx_dispatch_latency_factor", 2);
  KNOB_NUM_SIM_CORES = new KnobTemplate<int>("num_sim_cores", 80);
  KNOB_CORE_TYPE = new KnobTemplate<string>("core_type", "x86");
  KNOB_MEDIUM_CORE_TYPE = new KnobTemplate<string>("medium_core_type", "x86");
  KNOB_LARGE_CORE_TYPE = new KnobTemplate<string>("large_core_type", "x86");
  KNOB_NUM_SIM_SMALL_CORES =
      new KnobTemplate<int>("num_sim_small_cores", 80, "num_sim_cores");
  KNOB_NUM_SIM_LARGE_CORES = new KnobTemplate<int>("num_sim_large_cores", 0);
  KNOB_NUM_SIM_MEDIUM_CORES = new KnobTemplate<int>("num_sim_medium_cores", 0);
  KNOB_MAX_THREADS_PER_CORE = new KnobTemplate<int>("max_threads_per_core", 3);
  KNOB_MAX_THREADS_PER_MEDIUM_CORE = new KnobTemplate<int>(
      "max_threads_per_medium_core", 3, "max_threads_per_core");
  KNOB_MAX_THREADS_PER_LARGE_CORE = new KnobTemplate<int>(
      "max_threads_per_large_core", 3, "max_threads_per_core");
  KNOB_SCHEDULE = new KnobTemplate<string>("schedule", "io");
  KNOB_MEDIUM_CORE_SCHEDULE =
      new KnobTemplate<string>("medium_core_schedule", "io");
  KNOB_LARGE_CORE_SCHEDULE =
      new KnobTemplate<string>("large_core_schedule", "io");
  KNOB_FETCH_LATENCY = new KnobTemplate<uns32>("fetch_latency", 1);
  KNOB_ALLOC_LATENCY = new KnobTemplate<uns32>("alloc_latency", 1);
  KNOB_MEDIUM_CORE_ALLOC_LATENCY =
      new KnobTemplate<uns32>("medium_core_alloc_latency", 1);
  KNOB_MEDIUM_CORE_FETCH_LATENCY =
      new KnobTemplate<uns32>("medium_core_fetch_latency", 1);
  KNOB_LARGE_CORE_ALLOC_LATENCY =
      new KnobTemplate<uns32>("large_core_alloc_latency", 1);
  KNOB_LARGE_CORE_FETCH_LATENCY =
      new KnobTemplate<uns32>("large_core_fetch_latency", 1);
  KNOB_PRINT_HEARTBEAT = new KnobTemplate<bool>("print_heartbeat", true);
  KNOB_GPU_SCHED = new KnobTemplate<bool>("gpu_sched", false);
  KNOB_GPU_USE_SINGLE_ALLOCQ_TYPE =
      new KnobTemplate<bool>("gpu_use_single_iaq_type", true);
  KNOB_GPU_SHARE_ALLOCQS_BETWEEN_THREADS =
      new KnobTemplate<bool>("gpu_share_iaqs_between_threads", true);
  KNOB_MAX_WARP_PER_SM = new KnobTemplate<int>("max_warp_per_sm", 48);
  KNOB_SP_PER_SM = new KnobTemplate<int>("sp_per_sm", 32);
  KNOB_SFU_PER_SM = new KnobTemplate<int>("sfu_per_sm", 4);
  KNOB_LDST_PER_SM = new KnobTemplate<int>("ldst_per_sm", 16);
  KNOB_32_64_ISA = new KnobTemplate<int>("32_64_isa", 32);
  KNOB_PHY_ADDR_WIDTH = new KnobTemplate<int>("phy_addr_width", 32);
  KNOB_FEATURE_SIZE = new KnobTemplate<int>("feature_size", 32);
  KNOB_PCIE_BUS_SIZE = new KnobTemplate<int>("pcie_bus_size", 1);
  KNOB_PCIE_TR = new KnobTemplate<int>("pcie_tr", 16);
  KNOB_PCIE_INIT = new KnobTemplate<int>("pcie_init", 33250);
  KNOB_INST_LENGTH = new KnobTemplate<int>("inst_length", 32);
  KNOB_OPCODE_WIDTH = new KnobTemplate<int>("opcode_width", 16);
  KNOB_MICRO_OPCODE_WIDTH = new KnobTemplate<int>("micro_opcode_width", 8);
  KNOB_INST_BUF_SIZE = new KnobTemplate<int>("inst_buf_size", 32);
  KNOB_DEC_STREAM_BUF_SIZE = new KnobTemplate<int>("dec_stream_buf_size", 16);
  KNOB_FP_INST_WINDOW_SIZE = new KnobTemplate<int>("fp_inst_window_size", 64);
  KNOB_RAS_SIZE = new KnobTemplate<int>("ras_size", 64);
  KNOB_IFU_DUTY_CYCLE = new KnobTemplate<float>("ifu_duty_cycle", 1.0);
  KNOB_LSU_DUTY_CYCLE = new KnobTemplate<float>("lsu_duty_cycle", 0.5);
  KNOB_MEM_I_DUTY_CYCLE = new KnobTemplate<float>("mem_i_duty_cycle", 1.0);
  KNOB_MEM_D_DUTY_CYCLE = new KnobTemplate<float>("mem_d_duty_cycle", 0.5);
  KNOB_ALU_DUTY_CYCLE = new KnobTemplate<float>("alu_duty_cycle", 1.0);
  KNOB_MUL_DUTY_CYCLE = new KnobTemplate<float>("mul_duty_cycle", 0.3);
  KNOB_FPU_DUTY_CYCLE = new KnobTemplate<float>("fpu_duty_cycle", 0.3);
  KNOB_ALU_CDB_DUTY_CYCLE = new KnobTemplate<float>("alu_cdb_duty_cycle", 1.0);
  KNOB_MUL_CDB_DUTY_CYCLE = new KnobTemplate<float>("mul_cdb_duty_cycle", 0.3);
  KNOB_FPU_CDB_DUTY_CYCLE = new KnobTemplate<float>("fpu_cdb_duty_cycle", 0.3);
  KNOB_ICACHE_THROUGHPUT = new KnobTemplate<int>("icache_throughput", 8);
  KNOB_DCACHE_THROUGHPUT = new KnobTemplate<int>("dcache_throughput", 3);
  KNOB_L2_THROUGHPUT = new KnobTemplate<int>("l2_throughput", 8);
  KNOB_L3_THROUGHPUT = new KnobTemplate<int>("l3_throughput", 16);
  KNOB_L2_CLOCKRATE = new KnobTemplate<float>("l2_clockrate", 3.4);
  KNOB_L3_CLOCKRATE = new KnobTemplate<float>("l3_clockrate", 0.85);
  KNOB_DRAM_CLOCKRATE = new KnobTemplate<float>("dram_clockrate", 0.2);
  KNOB_IS_GPU = new KnobTemplate<int>("is_gpu", 0);
  KNOB_GPU_WIDTH = new KnobTemplate<int>("gpu_width", 32);
  KNOB_ORIG_PIPELINE_STAGES = new KnobTemplate<int>("orig_pipeline_stages", 20);
  KNOB_EI_DECODE_WIDTH =
      new KnobTemplate<int>("ei_decode_width", 2, "large_width");
  KNOB_EI_ISSUE_WIDTH =
      new KnobTemplate<int>("ei_issue_width", 2, "large_width");
  KNOB_EI_EXEC_WIDTH = new KnobTemplate<int>("ei_exec_width", 2, "large_width");
  KNOB_EI_COMMIT_WIDTH =
      new KnobTemplate<int>("ei_commit_width", 2, "large_width");
  KNOB_IS_FERMI = new KnobTemplate<bool>("is_fermi", 1);
  KNOB_FENCE_ENABLE = new KnobTemplate<bool>("fence_enable", 0);
  KNOB_FENCE_PREF_ENABLE = new KnobTemplate<bool>("fence_pref_enable", 0);
  KNOB_ACQ_REL = new KnobTemplate<bool>("acq_rel", 0);
  KNOB_USE_WB = new KnobTemplate<bool>("use_wb", 0);
  KNOB_WB_SIZE = new KnobTemplate<int>("wb_size", 32);
  KNOB_WB_FIFO = new KnobTemplate<bool>("wb_fifo", 0);
  KNOB_QSIM_STATE = new KnobTemplate<string>("qsim_state", "'state.1'");
  KNOB_QSIM_BENCH = new KnobTemplate<string>("qsim_bench", ""
                                                           "");

  // =========== ../def/debug.param.def ===========
  KNOB_DEBUG_CYCLE_START = new KnobTemplate<uns>("debug_cycle_start", 0);
  KNOB_DEBUG_CYCLE_STOP = new KnobTemplate<uns>("debug_cycle_stop", 0);
  KNOB_DEBUG_INST_START = new KnobTemplate<uns>("debug_inst_start", 0);
  KNOB_DEBUG_INST_STOP = new KnobTemplate<uns>("debug_inst_stop", 0);
  KNOB_DEBUG_FRONT_STAGE = new KnobTemplate<uns>("debug_front_stage", 0);
  KNOB_DEBUG_ALLOC_STAGE = new KnobTemplate<uns>("debug_alloc_stage", 0);
  KNOB_DEBUG_SCHEDULE_STAGE = new KnobTemplate<uns>("debug_schedule_stage", 0);
  KNOB_DEBUG_EXEC_STAGE = new KnobTemplate<uns>("debug_exec_stage", 0);
  KNOB_DEBUG_DCU_STAGE = new KnobTemplate<uns>("debug_dcu_stage", 0);
  KNOB_DEBUG_RETIRE_STAGE = new KnobTemplate<uns>("debug_retire_stage", 0);
  KNOB_DEBUG_MEM = new KnobTemplate<uns>("debug_mem", 0);
  KNOB_DEBUG_TRACE_READ = new KnobTemplate<uns>("debug_trace_read", 0);
  KNOB_DEBUG_SIM = new KnobTemplate<uns>("debug_sim", 1);
  KNOB_DEBUG_CACHE_LIB = new KnobTemplate<uns>("debug_cache_lib", 0);
  KNOB_DEBUG_BP_DIR = new KnobTemplate<uns>("debug_bp_dir", 0);
  KNOB_DEBUG_BTB = new KnobTemplate<uns>("debug_btb", 0);
  KNOB_DEBUG_MAP_STAGE = new KnobTemplate<uns>("debug_map_stage", 0);
  KNOB_DEBUG_PORT = new KnobTemplate<uns>("debug_port", 0);
  KNOB_DEBUG_CORE_ID = new KnobTemplate<int>("debug_core_id", 0);
  KNOB_DEBUG_SIM_THREAD_SCHEDULE =
      new KnobTemplate<uns>("debug_sim_thread_schedule", 0);
  KNOB_DEBUG_DRAM = new KnobTemplate<uns>("debug_dram", 0);
  KNOB_DEBUG_PRINT_TRACE = new KnobTemplate<uns>("debug_print_trace", 0);
  KNOB_DEBUG_MEM_TRACE = new KnobTemplate<bool>("debug_mem_trace", false);
  KNOB_DEBUG_NOC = new KnobTemplate<bool>("debug_noc", false);
  KNOB_DEBUG_HMC = new KnobTemplate<bool>("debug_hmc", false);

  // =========== ../def/dyfr.param.def ===========
  KNOB_ENABLE_DYFR = new KnobTemplate<bool>("enable_dyfr", false);
  KNOB_NUM_CPU_APPLICATION = new KnobTemplate<int>("num_cpu_application", 4);
  KNOB_DYFR_GPU_FREQ_MIN = new KnobTemplate<int>("dyfr_gpu_freq_min", 6);
  KNOB_DYFR_GPU_FREQ_MAX = new KnobTemplate<int>("dyfr_gpu_freq_max", 21);
  KNOB_DYFR_CPU_FREQ_MIN = new KnobTemplate<int>("dyfr_cpu_freq_min", 15);
  KNOB_DYFR_CPU_FREQ_MAX = new KnobTemplate<int>("dyfr_cpu_freq_max", 40);
  KNOB_DYFR_SAMPLE_PERIOD =
      new KnobTemplate<int>("dyfr_sample_period", 4000000);
  KNOB_DYFR_PLL_LOCK = new KnobTemplate<int>("dyfr_pll_lock", 100000);
  KNOB_DYFR_CPU_BUDGET = new KnobTemplate<int>("dyfr_cpu_budget", 30);
  KNOB_DYFR_GPU_BUDGET = new KnobTemplate<int>("dyfr_gpu_budget", 30);
  KNOB_DYFR_MEM_BUDGET = new KnobTemplate<int>("dyfr_mem_budget", 40);

  // =========== ../def/frontend.param.def ===========
  KNOB_FETCH_WDITH = new KnobTemplate<uns16>("fetch_wdith", 4);
  KNOB_FETCH_MEDIUM_WDITH =
      new KnobTemplate<uns16>("fetch_medium_wdith", 4, "fetch_wdith");
  KNOB_FETCH_LARGE_WDITH =
      new KnobTemplate<uns16>("fetch_large_wdith", 4, "fetch_wdith");
  KNOB_FETCH_ONLY_LOAD_READY =
      new KnobTemplate<bool>("fetch_only_load_ready", false);
  KNOB_FETCH_ONLY_SCHED_READY =
      new KnobTemplate<bool>("fetch_only_sched_ready", false);
  KNOB_MT_NO_FETCH_BR = new KnobTemplate<bool>("mt_no_fetch_br", false);
  KNOB_NO_FETCH_ON_ICACHE_MISS =
      new KnobTemplate<bool>("no_fetch_on_icache_miss", false);
  KNOB_FETCH_POLICY = new KnobTemplate<string>("fetch_policy", "rr");
  KNOB_DEC_RR_FREQ = new KnobTemplate<uns>("dec_rr_freq", 1);
  KNOB_MT_STOP_FAIR_INIT = new KnobTemplate<uns>("mt_stop_fair_init", 1);
  KNOB_FETCH_FAIR_PERIOD = new KnobTemplate<uns>("fetch_fair_period", 200);
  KNOB_FETCH_FAIR_MERGE_TH = new KnobTemplate<uns>("fetch_fair_merge_th", 3);
  KNOB_FETCH_FAIR_TSHARE_TH = new KnobTemplate<uns>("fetch_fair_tshare_th", 3);
  KNOB_FETCH_FAIR_MERGE = new KnobTemplate<bool>("fetch_fair_merge", false);
  KNOB_FETCH_FAIR_TSHARE = new KnobTemplate<bool>("fetch_fair_tshare", false);
  KNOB_BLOCK_KEY_SIZE = new KnobTemplate<uns>("block_key_size", 103);
  KNOB_FETCH_FAIR_TSHARE_FREQ =
      new KnobTemplate<uns>("fetch_fair_tshare_freq", 5);
  KNOB_NUM_INST_TO_FETCH_AFTER_LOAD =
      new KnobTemplate<int>("num_inst_to_fetch_after_load", 1);

  // =========== ../def/general.param.def ===========
  KNOB_ENABLE_ENERGY_INTROSPECTOR =
      new KnobTemplate<bool>("enable_energy_introspector", false);
  KNOB_POWER_PRINT_LEVEL = new KnobTemplate<int>("power_print_level", 2);
  KNOB_BLOCKS_TO_SIMULATE = new KnobTemplate<uns>("blocks_to_simulate", 0);
  KNOB_SIMULATE_LAST_BLOCKS =
      new KnobTemplate<bool>("simulate_last_blocks", false);
  KNOB_REPEAT_TRACE = new KnobTemplate<bool>("repeat_trace", false);
  KNOB_REPEAT_TRACE_N = new KnobTemplate<int>("repeat_trace_n", 0);
  KNOB_MAX_NUM_CORE_PER_APPL =
      new KnobTemplate<int>("max_num_core_per_appl", 0);
  KNOB_MAX_BLOCKS_TO_SIMULATE =
      new KnobTemplate<int>("max_blocks_to_simulate", 0);
  KNOB_STDERR_FILE = new KnobTemplate<string>("stderr", "NULL");
  KNOB_STDOUT_FILE = new KnobTemplate<string>("stdout", "NULL");
  KNOB_FILE_TAG = new KnobTemplate<string>("file_tag", "NULL");
  KNOB_STATISTICS_OUT_DIRECTORY = new KnobTemplate<string>("out", ".");
  KNOB_MAX_BLOCK_PER_CORE = new KnobTemplate<int>("max_block_per_core", 4);
  KNOB_MAX_INSTS1 = new KnobTemplate<uns64>("max_insts1", 10000000000);
  KNOB_ENABLE_CONDITIONAL_EXECUTION =
      new KnobTemplate<bool>("enable_conditional_execution", false);
  KNOB_TEMPERATURE = new KnobTemplate<int>("temperature", 320);
  KNOB_ASSIGN_BLOCKS_GREEDILY_INITIALLY =
      new KnobTemplate<bool>("assign_blocks_greedily_initially", false);
  KNOB_CLOCK_CPU = new KnobTemplate<float>("clock_cpu", 4.0);
  KNOB_CLOCK_GPU = new KnobTemplate<float>("clock_gpu", 1.5);
  KNOB_CLOCK_L3 = new KnobTemplate<float>("clock_l3", 1.0);
  KNOB_CLOCK_NOC = new KnobTemplate<float>("clock_noc", 1.0);
  KNOB_CLOCK_MC = new KnobTemplate<float>("clock_mc", 0.8);
  KNOB_COMPUTE_CAPABILITY = new KnobTemplate<float>("compute_capability", 2.0);
  KNOB_GPU_WARP_SIZE = new KnobTemplate<int>("gpu_warp_size", 32);
  KNOB_TRACE_USES_64_BIT_ADDR =
      new KnobTemplate<bool>("trace_uses_64_bit_addr", true);
  KNOB_ENABLE_FAST_FORWARD_MODE =
      new KnobTemplate<bool>("enable_fast_forward_mode", false);
  KNOB_FAST_FORWARD_MODE_THRESHOLD =
      new KnobTemplate<uns>("fast_forward_mode_threshold", 1000);

  // =========== ../def/hmc.param.def ===========
  KNOB_ENABLE_HMC_INST = new KnobTemplate<bool>("enable_hmc_inst", 0);
  KNOB_ENABLE_HMC_INST_SKIP = new KnobTemplate<bool>("enable_hmc_inst_skip", 0);
  KNOB_ENABLE_HMC_BYPASS_CACHE =
      new KnobTemplate<bool>("enable_hmc_bypass_cache", 1);
  KNOB_ENABLE_NONHMC_STAT = new KnobTemplate<bool>("enable_nonhmc_stat", 0);
  KNOB_ENABLE_LOCK_SKIP = new KnobTemplate<bool>("enable_lock_skip", 0);
  KNOB_ENABLE_HMC_TRANS = new KnobTemplate<bool>("enable_hmc_trans", 0);
  KNOB_ENABLE_HMC_FENCE = new KnobTemplate<bool>("enable_hmc_fence", 0);
  KNOB_ENABLE_HMC_DOUBLE_FENCE =
      new KnobTemplate<bool>("enable_hmc_double_fence", 0);
  KNOB_COUNT_HMC_REMOVED_IN_MAX_INSTS =
      new KnobTemplate<bool>("count_hmc_removed_in_max_insts", 0);
  KNOB_HMC_ADD_DEP = new KnobTemplate<bool>("hmc_add_dep", 1);
  KNOB_ENABLE_TRACE_MAX_THREAD =
      new KnobTemplate<bool>("enable_trace_max_thread", 0);
  KNOB_TRACE_MAX_THREAD_COUNT =
      new KnobTemplate<int>("trace_max_thread_count", 8);
  KNOB_HMC_TEST_OVERHEAD = new KnobTemplate<int>("hmc_test_overhead", 8);

  // =========== ../def/memory.param.def ===========
  KNOB_PERFECT_ICACHE = new KnobTemplate<bool>("perfect_icache", false);
  KNOB_ICACHE_NUM_SET = new KnobTemplate<uns>("icache_num_set", 64);
  KNOB_ICACHE_ASSOC = new KnobTemplate<uns>("icache_assoc", 8);
  KNOB_ICACHE_LINE_SIZE = new KnobTemplate<uns>("icache_line_size", 64);
  KNOB_ICACHE_BANKS = new KnobTemplate<uns>("icache_banks", 32);
  KNOB_ICACHE_BY_PASS = new KnobTemplate<bool>("icache_by_pass", false);
  KNOB_ICACHE_CYCLES = new KnobTemplate<uns>("icache_cycles", 1);
  KNOB_ICACHE_MEDIUM_NUM_SET =
      new KnobTemplate<uns>("icache_medium_num_set", 64, "icache_num_set");
  KNOB_ICACHE_MEDIUM_ASSOC =
      new KnobTemplate<uns>("icache_medium_assoc", 8, "icache_assoc");
  KNOB_ICACHE_MEDIUM_LINE_SIZE =
      new KnobTemplate<uns>("icache_medium_line_size", 64, "icache_line_size");
  KNOB_ICACHE_MEDIUM_BANKS =
      new KnobTemplate<uns>("icache_medium_banks", 32, "icache_banks");
  KNOB_ICACHE_MEDIUM_BY_PASS =
      new KnobTemplate<bool>("icache_medium_by_pass", false);
  KNOB_ICACHE_MEDIUM_CYCLES = new KnobTemplate<uns>("icache_medium_cycles", 1);
  KNOB_ICACHE_LARGE_NUM_SET =
      new KnobTemplate<uns>("icache_large_num_set", 64, "icache_num_set");
  KNOB_ICACHE_LARGE_ASSOC =
      new KnobTemplate<uns>("icache_large_assoc", 8, "icache_assoc");
  KNOB_ICACHE_LARGE_LINE_SIZE =
      new KnobTemplate<uns>("icache_large_line_size", 64, "icache_line_size");
  KNOB_ICACHE_LARGE_BANKS =
      new KnobTemplate<uns>("icache_large_banks", 32, "icache_banks");
  KNOB_ICACHE_LARGE_BY_PASS =
      new KnobTemplate<bool>("icache_large_by_pass", false);
  KNOB_ICACHE_LARGE_CYCLES = new KnobTemplate<uns>("icache_large_cycles", 1);
  KNOB_ICACHE_READ_PORTS = new KnobTemplate<uns>("icache_read_ports", 1);
  KNOB_ICACHE_WRITE_PORTS = new KnobTemplate<uns>("icache_write_ports", 1);
  KNOB_PERFECT_DCACHE = new KnobTemplate<bool>("perfect_dcache", false);
  KNOB_L1_READ_PORTS = new KnobTemplate<int>("l1_read_ports", 4);
  KNOB_L2_READ_PORTS = new KnobTemplate<int>("l2_read_ports", 2);
  KNOB_L3_READ_PORTS = new KnobTemplate<int>("l3_read_ports", 1);
  KNOB_L1_WRITE_PORTS = new KnobTemplate<int>("l1_write_ports", 4);
  KNOB_L2_WRITE_PORTS = new KnobTemplate<int>("l2_write_ports", 2);
  KNOB_L3_WRITE_PORTS = new KnobTemplate<int>("l3_write_ports", 1);
  KNOB_L1_SMALL_NUM_SET = new KnobTemplate<int>("l1_small_num_set", 64);
  KNOB_L1_SMALL_ASSOC = new KnobTemplate<int>("l1_small_assoc", 8);
  KNOB_L1_SMALL_LINE_SIZE = new KnobTemplate<int>("l1_small_line_size", 64);
  KNOB_L1_SMALL_NUM_BANK = new KnobTemplate<int>("l1_small_num_bank", 4);
  KNOB_L1_SMALL_LATENCY = new KnobTemplate<int>("l1_small_latency", 3);
  KNOB_L1_SMALL_BYPASS = new KnobTemplate<bool>("l1_small_bypass", false);
  KNOB_L2_SMALL_NUM_SET = new KnobTemplate<int>("l2_small_num_set", 512);
  KNOB_L2_SMALL_ASSOC = new KnobTemplate<int>("l2_small_assoc", 8);
  KNOB_L2_SMALL_LINE_SIZE = new KnobTemplate<int>("l2_small_line_size", 64);
  KNOB_L2_SMALL_NUM_BANK = new KnobTemplate<int>("l2_small_num_bank", 8);
  KNOB_L2_SMALL_LATENCY = new KnobTemplate<int>("l2_small_latency", 8);
  KNOB_L2_SMALL_BYPASS = new KnobTemplate<bool>("l2_small_bypass", false);
  KNOB_L1_MEDIUM_NUM_SET = new KnobTemplate<int>("l1_medium_num_set", 64);
  KNOB_L1_MEDIUM_ASSOC = new KnobTemplate<int>("l1_medium_assoc", 8);
  KNOB_L1_MEDIUM_LINE_SIZE = new KnobTemplate<int>("l1_medium_line_size", 64);
  KNOB_L1_MEDIUM_NUM_BANK = new KnobTemplate<int>("l1_medium_num_bank", 4);
  KNOB_L1_MEDIUM_LATENCY = new KnobTemplate<int>("l1_medium_latency", 3);
  KNOB_L1_MEDIUM_BYPASS = new KnobTemplate<bool>("l1_medium_bypass", false);
  KNOB_L2_MEDIUM_NUM_SET = new KnobTemplate<int>("l2_medium_num_set", 512);
  KNOB_L2_MEDIUM_ASSOC = new KnobTemplate<int>("l2_medium_assoc", 8);
  KNOB_L2_MEDIUM_LINE_SIZE = new KnobTemplate<int>("l2_medium_line_size", 64);
  KNOB_L2_MEDIUM_NUM_BANK = new KnobTemplate<int>("l2_medium_num_bank", 8);
  KNOB_L2_MEDIUM_LATENCY = new KnobTemplate<int>("l2_medium_latency", 8);
  KNOB_L2_MEDIUM_BYPASS = new KnobTemplate<bool>("l2_medium_bypass", false);
  KNOB_L1_LARGE_NUM_SET = new KnobTemplate<int>("l1_large_num_set", 64);
  KNOB_L1_LARGE_ASSOC = new KnobTemplate<int>("l1_large_assoc", 8);
  KNOB_L1_LARGE_LINE_SIZE = new KnobTemplate<int>("l1_large_line_size", 64);
  KNOB_L1_LARGE_NUM_BANK = new KnobTemplate<int>("l1_large_num_bank", 4);
  KNOB_L1_LARGE_LATENCY = new KnobTemplate<int>("l1_large_latency", 3);
  KNOB_L1_LARGE_BYPASS = new KnobTemplate<bool>("l1_large_bypass", false);
  KNOB_L2_LARGE_NUM_SET = new KnobTemplate<int>("l2_large_num_set", 512);
  KNOB_L2_LARGE_ASSOC = new KnobTemplate<int>("l2_large_assoc", 8);
  KNOB_L2_LARGE_LINE_SIZE = new KnobTemplate<int>("l2_large_line_size", 64);
  KNOB_L2_LARGE_NUM_BANK = new KnobTemplate<int>("l2_large_num_bank", 8);
  KNOB_L2_LARGE_LATENCY = new KnobTemplate<int>("l2_large_latency", 8);
  KNOB_L2_LARGE_BYPASS = new KnobTemplate<bool>("l2_large_bypass", false);
  KNOB_NUM_L3 = new KnobTemplate<int>("num_l3", 1);
  KNOB_L3_INTERLEAVE_FACTOR = new KnobTemplate<int>("l3_interleave_factor", 64);
  KNOB_L3_NUM_SET = new KnobTemplate<int>("l3_num_set", 8192);
  KNOB_L3_ASSOC = new KnobTemplate<int>("l3_assoc", 16);
  KNOB_L3_LINE_SIZE = new KnobTemplate<int>("l3_line_size", 64);
  KNOB_L3_NUM_BANK = new KnobTemplate<int>("l3_num_bank", 16);
  KNOB_L3_LATENCY = new KnobTemplate<int>("l3_latency", 25);
  KNOB_DCACHE_INFINITE_PORT =
      new KnobTemplate<bool>("dcache_infinite_port", false);
  KNOB_SIMPLESSD_CONFIG = new KnobTemplate<string>(
      "simplessd_config", "src/simplessd/config/intel750_400gb.cfg");
  KNOB_DRAM_BUFFER_SIZE = new KnobTemplate<int>("dram_buffer_size", 128);
  KNOB_DRAM_BANK_XOR_INDEX =
      new KnobTemplate<bool>("dram_bank_xor_index", true);
  KNOB_DRAM_MERGE_REQUESTS =
      new KnobTemplate<bool>("dram_merge_requests", true);
  KNOB_DRAM_ROWBUFFER_SIZE = new KnobTemplate<int>("dram_rowbuffer_size", 2048);
  KNOB_DRAM_SCHEDULING_POLICY =
      new KnobTemplate<string>("dram_scheduling_policy", "FRFCFS");
  KNOB_DRAM_NUM_CHANNEL = new KnobTemplate<int>("dram_num_channel", 1);
  KNOB_DRAM_NUM_BANKS = new KnobTemplate<int>("dram_num_banks", 8);
  KNOB_DRAM_ONE_CYCLE = new KnobTemplate<uns>("dram_one_cycle", 10);
  KNOB_DRAM_DDR_FACTOR = new KnobTemplate<uns>("dram_ddr_factor", 2);
  KNOB_DRAM_BUS_WIDTH = new KnobTemplate<uns>("dram_bus_width", 8);
  KNOB_DRAM_COLUMN = new KnobTemplate<uns>("dram_column", 6);
  KNOB_DRAM_PRECHARGE = new KnobTemplate<uns>("dram_precharge", 6);
  KNOB_DRAM_ACTIVATE = new KnobTemplate<uns>("dram_activate", 6);
  KNOB_DRAM_NUM_MC = new KnobTemplate<int>("dram_num_mc", 1);
  KNOB_DRAM_INTERLEAVE_FACTOR =
      new KnobTemplate<int>("dram_interleave_factor", 128);
  KNOB_DRAM_ADDITIONAL_LATENCY =
      new KnobTemplate<int>("dram_additional_latency", 0);
  KNOB_MEMORY_TYPE = new KnobTemplate<string>("memory_type", "l3_cn");
  KNOB_MEM_MSHR_SIZE = new KnobTemplate<int>("mem_mshr_size", 128);
  KNOB_MEM_QUEUE_SIZE = new KnobTemplate<int>("mem_queue_size", 128);
  KNOB_ENABLE_PREF_SMALL_CORE =
      new KnobTemplate<bool>("enable_pref_small_core", false);
  KNOB_ENABLE_PREF_MEDIUM_CORE =
      new KnobTemplate<bool>("enable_pref_medium_core", false);
  KNOB_ENABLE_PREF_LARGE_CORE =
      new KnobTemplate<bool>("enable_pref_large_core", false);
  KNOB_MEM_SIZE_AMP = new KnobTemplate<int>("mem_size_amp", 1);
  KNOB_PTX_COMMON_CACHE = new KnobTemplate<bool>("ptx_common_cache", false);
  KNOB_MAX_TRANSACTION_SIZE = new KnobTemplate<int>("max_transaction_size", 64);
  KNOB_BYTE_LEVEL_ACCESS = new KnobTemplate<bool>("byte_level_access", false);
  KNOB_INFINITE_PORT = new KnobTemplate<bool>("infinite_port", false);
  KNOB_EXTRA_LD_LATENCY = new KnobTemplate<int>("extra_ld_latency", 0);
  KNOB_USE_CONST_AND_TEX_CACHES =
      new KnobTemplate<bool>("use_const_and_tex_caches", true);
  KNOB_CONST_CACHE_SIZE = new KnobTemplate<uns32>("const_cache_size", 1024);
  KNOB_CONST_CACHE_ASSOC = new KnobTemplate<uns8>("const_cache_assoc", 8);
  KNOB_CONST_CACHE_LINE_SIZE =
      new KnobTemplate<uns8>("const_cache_line_size", 64);
  KNOB_CONST_CACHE_BANKS = new KnobTemplate<uns8>("const_cache_banks", 8);
  KNOB_CONST_CACHE_CYCLES = new KnobTemplate<uns8>("const_cache_cycles", 4);
  KNOB_TEXTURE_CACHE_SIZE = new KnobTemplate<uns32>("texture_cache_size", 256);
  KNOB_TEXTURE_CACHE_ASSOC = new KnobTemplate<uns8>("texture_cache_assoc", 8);
  KNOB_TEXTURE_CACHE_LINE_SIZE =
      new KnobTemplate<uns8>("texture_cache_line_size", 64);
  KNOB_TEXTURE_CACHE_BANKS = new KnobTemplate<uns8>("texture_cache_banks", 8);
  KNOB_TEXTURE_CACHE_CYCLES = new KnobTemplate<uns8>("texture_cache_cycles", 4);
  KNOB_SHARED_MEM_SIZE = new KnobTemplate<uns32>("shared_mem_size", 4096);
  KNOB_SHARED_MEM_ASSOC = new KnobTemplate<uns8>("shared_mem_assoc", 8);
  KNOB_SHARED_MEM_LINE_SIZE = new KnobTemplate<uns8>("shared_mem_line_size", 4);
  KNOB_SHARED_MEM_BANKS = new KnobTemplate<uns8>("shared_mem_banks", 16);
  KNOB_SHARED_MEM_CYCLES = new KnobTemplate<uns8>("shared_mem_cycles", 4);
  KNOB_SHARED_MEM_PORTS = new KnobTemplate<uns>("shared_mem_ports", 2);
  KNOB_ENABLE_CACHE_COHERENCE =
      new KnobTemplate<bool>("enable_cache_coherence", false);
  KNOB_LLC_TYPE = new KnobTemplate<string>("llc_type", "default");
  KNOB_COLLECT_CACHE_INFO = new KnobTemplate<int>("collect_cache_info", 0);
  KNOB_HETERO_STATIC_CACHE_PARTITION =
      new KnobTemplate<bool>("hetero_static_cache_partition", false);
  KNOB_HETERO_STATIC_CPU_PARTITION =
      new KnobTemplate<int>("hetero_static_cpu_partition", 1);
  KNOB_HETERO_STATIC_GPU_PARTITION =
      new KnobTemplate<int>("hetero_static_gpu_partition", 1);
  KNOB_HETERO_GPU_CORE_DISABLE =
      new KnobTemplate<int>("hetero_gpu_core_disable", -2);
  KNOB_HETERO_NOC_USE_SAME_QUEUE =
      new KnobTemplate<bool>("hetero_noc_use_same_queue", true);
  KNOB_HETERO_MEM_PRIORITY_CPU =
      new KnobTemplate<bool>("hetero_mem_priority_cpu", false);
  KNOB_HETERO_MEM_PRIORITY_GPU =
      new KnobTemplate<bool>("hetero_mem_priority_gpu", false);
  KNOB_CACHE_USE_PSEUDO_LRU =
      new KnobTemplate<bool>("cache_use_pseudo_lru", false);
  KNOB_LOAD_BUF_SIZE = new KnobTemplate<int>("load_buf_size", 16);
  KNOB_STORE_BUF_SIZE = new KnobTemplate<int>("store_buf_size", 12);
  KNOB_USE_INCOMING_TID_CID_FOR_WB =
      new KnobTemplate<bool>("use_incoming_tid_cid_for_wb", false);
  KNOB_DEFAULT_INTERLEAVING =
      new KnobTemplate<bool>("default_interleaving", true);
  KNOB_NEW_INTERLEAVING_SAME_GRANULARITY =
      new KnobTemplate<bool>("new_interleaving_same_granularity", false);
  KNOB_NEW_INTERLEAVING_DIFF_GRANULARITY =
      new KnobTemplate<bool>("new_interleaving_diff_granularity", false);
  KNOB_USE_NEW_COALESCING = new KnobTemplate<bool>("use_new_coalescing", false);
  KNOB_ENABLE_PHYSICAL_MAPPING =
      new KnobTemplate<bool>("enable_physical_mapping", false);
  KNOB_PAGE_SIZE = new KnobTemplate<int>("page_size", 4096);
  KNOB_REGION_SIZE = new KnobTemplate<int>("region_size", 1048576);
  KNOB_PAGE_MAPPING_POLICY =
      new KnobTemplate<string>("page_mapping_policy", "REGION_FCFS");
  KNOB_USE_MEMHIERARCHY = new KnobTemplate<bool>("use_memhierarchy", false);
  KNOB_USE_VAULTSIM_LINK = new KnobTemplate<bool>("use_vaultsim_link", false);

  // =========== ../def/network.param.def ===========
  KNOB_ENABLE_IRIS = new KnobTemplate<bool>("enable_iris", false);
  KNOB_IRIS_TOPOLOGY = new KnobTemplate<string>("iris_topology", "ring");
  KNOB_IRIS_GRIDSIZE = new KnobTemplate<string>("iris_gridsize", "3");
  KNOB_IRIS_NUM_VC = new KnobTemplate<string>("iris_num_vc", "4");
  KNOB_IRIS_CREDIT = new KnobTemplate<string>("iris_credit", "4");
  KNOB_IRIS_INT_BUFF_WIDTH =
      new KnobTemplate<string>("iris_int_buff_width", "4");
  KNOB_IRIS_LINK_WIDTH = new KnobTemplate<string>("iris_link_width", "128");
  KNOB_IRIS_RC_METHOD =
      new KnobTemplate<string>("iris_rc_method", "ring_routing");
  KNOB_IRIS_SELF_ASSIGN_DEST_ID =
      new KnobTemplate<string>("iris_self_assign_dest_id", "1");
  KNOB_IRIS_RESP_PAYLOAD_LEN =
      new KnobTemplate<string>("iris_resp_payload_len", "1");
  KNOB_IRIS_MEMORY_LATENCY =
      new KnobTemplate<string>("iris_memory_latencY", "1");
  KNOB_ENABLE_NEW_NOC = new KnobTemplate<bool>("enable_new_noc", true);
  KNOB_NUM_VC = new KnobTemplate<int>("num_vc", 4);
  KNOB_NUM_PORT = new KnobTemplate<int>("num_port", 3);
  KNOB_LINK_LATENCY = new KnobTemplate<int>("link_latency", 1);
  KNOB_LINK_WIDTH = new KnobTemplate<int>("link_width", 16);
  KNOB_NOC_DIMENSION = new KnobTemplate<int>("noc_dimension", 1);
  KNOB_NOC_TOPOLOGY = new KnobTemplate<string>("noc_topology", "ring");
  KNOB_ENABLE_HETEROGENEOUS_LINK =
      new KnobTemplate<bool>("enable_heterogeneous_link", false);
  KNOB_NUM_SWITCH = new KnobTemplate<int>("num_switch", 1);
  KNOB_NUM_SWITCH_CPU = new KnobTemplate<int>("num_switch_cpu", 1);
  KNOB_NUM_SWITCH_GPU = new KnobTemplate<int>("num_switch_gpu", 1);
  KNOB_NUM_SWITCH_MEM = new KnobTemplate<int>("num_switch_mem", 1);
  KNOB_ENABLE_HETEROGENEOUS_LINK_WIDTH =
      new KnobTemplate<bool>("enable_heterogeneous_link_width", false);
  KNOB_NUM_SWITCH_ITER = new KnobTemplate<int>("num_switch_iter", 1);
  KNOB_NUM_SWITCH_ITER_CPU = new KnobTemplate<int>("num_switch_iter_cpu", 1);
  KNOB_NUM_SWITCH_ITER_GPU = new KnobTemplate<int>("num_switch_iter_gpu", 1);
  KNOB_NUM_SWITCH_ITER_MEM = new KnobTemplate<int>("num_switch_iter_mem", 1);
  KNOB_ENABLE_NOC_VC_PARTITION =
      new KnobTemplate<bool>("enable_noc_vc_partition", false);
  KNOB_CPU_VC_PARTITION = new KnobTemplate<int>("cpu_vc_partition", 2);
  KNOB_GPU_VC_PARTITION = new KnobTemplate<int>("gpu_vc_partition", 2);
  KNOB_ENABLE_CHANNEL_PARTITION =
      new KnobTemplate<bool>("enable_channel_partition", false);
  KNOB_NUM_CHANNEL_CPU = new KnobTemplate<int>("num_channel_cpu", 1);
  KNOB_NUM_CHANNEL_GPU = new KnobTemplate<int>("num_channel_gpu", 1);
  KNOB_ENABLE_ADAPTIVE_RING_ROUTING =
      new KnobTemplate<bool>("enable_adaptive_ring_routing", false);
  KNOB_ARR_THRESHOLD = new KnobTemplate<int>("arr_threshold", 50);
  KNOB_ARR_DELTA = new KnobTemplate<bool>("arr_delta", false);
  KNOB_ARR_ADV = new KnobTemplate<bool>("arr_adv", false);
  KNOB_ARR_100 = new KnobTemplate<bool>("arr_100", false);
  KNOB_ARBITRATION_POLICY = new KnobTemplate<int>("arbitration_policy", 0);
  KNOB_ROUTER_PLACEMENT = new KnobTemplate<int>("router_placement", 0);
  KNOB_CORE_ENABLE_BEGIN = new KnobTemplate<int>("core_enable_begin", 0);
  KNOB_CORE_ENABLE_END = new KnobTemplate<int>("core_enable_end", 0);
  KNOB_IDEAL_NOC = new KnobTemplate<bool>("ideal_noc", false);
  KNOB_IDEAL_NOC_LATENCY = new KnobTemplate<int>("ideal_noc_latency", 2);
  KNOB_USE_ZERO_LATENCY_NOC =
      new KnobTemplate<bool>("use_zero_latency_noc", false);

  // =========== ../def/pref.param.def ===========
  KNOB_PREF_FRAMEWORK_ON = new KnobTemplate<bool>("pref_framework_on", false);
  KNOB_PREF_TRACE_ON = new KnobTemplate<bool>("pref_trace_on", false);
  KNOB_DEBUG_PREF = new KnobTemplate<bool>("debug_pref", false);
  KNOB_PREF_DL0REQ_QUEUE_SIZE =
      new KnobTemplate<int>("pref_dl0req_queue_size", 32);
  KNOB_PREF_UL1REQ_QUEUE_SIZE =
      new KnobTemplate<int>("pref_ul1req_queue_size", 128);
  KNOB_PREF_DL0_MISS_ON = new KnobTemplate<bool>("pref_dl0_miss_on", true);
  KNOB_PREF_DL0_HIT_ON = new KnobTemplate<bool>("pref_dl0_hit_on", true);
  KNOB_PREF_DL0REQ_QUEUE_FILTER_ON =
      new KnobTemplate<bool>("pref_dl0req_queue_filter_on", true);
  KNOB_PREF_UL1REQ_QUEUE_FILTER_ON =
      new KnobTemplate<bool>("pref_ul1req_queue_filter_on", true);
  KNOB_PREF_DL0REQ_ADD_FILTER_ON =
      new KnobTemplate<bool>("pref_dl0req_add_filter_on", true);
  KNOB_PREF_UL1REQ_ADD_FILTER_ON =
      new KnobTemplate<bool>("pref_ul1req_add_fillter_on", true);
  KNOB_PREF_DL0REQ_QUEUE_OVERWRITE_ON_FULL =
      new KnobTemplate<bool>("pref_dl0req_queue_overwrite_on_full", false);
  KNOB_PREF_UL1REQ_QUEUE_OVERWRITE_ON_FULL =
      new KnobTemplate<bool>("pref_ul1req_queue_overwrite_on_full", false);
  KNOB_PREF_DL0SCHEDULE_NUM = new KnobTemplate<int>("pref_dl0schedule_num", 4);
  KNOB_PREF_UL1SCHEDULE_NUM = new KnobTemplate<int>("pref_ul1schedule_num", 4);
  KNOB_PREF_REGION_ON = new KnobTemplate<bool>("pref_region_on", false);
  KNOB_PREF_USEREGION_TOCALC_ACC =
      new KnobTemplate<bool>("pref_useregion_tocalc_acc", false);
  KNOB_PREF_NUMTRACKING_REGIONS =
      new KnobTemplate<int>("pref_numtracking_regions", 2048);
  KNOB_PREF_REGION_SIZE = new KnobTemplate<int>("pref_region_size", 256);
  KNOB_PREF_HYBRID_ON = new KnobTemplate<bool>("pref_hybrid_on", false);
  KNOB_PREF_HYBRID_DEFAULT = new KnobTemplate<uns8>("pref_hybrid_default", 1);
  KNOB_PREF_HYBRID_DEFAULT_TIMEPERIOD =
      new KnobTemplate<uns64>("pref_hybrid_default_timeperiod", 100000);
  KNOB_PREF_HYBRID_UPDATE_MULTIPLE =
      new KnobTemplate<uns>("pref_hybrid_update_multiple", 100);
  KNOB_PREF_HYBRID_MIN_SENT = new KnobTemplate<uns>("pref_hybrid_min_sent", 10);
  KNOB_PREF_HYBRID_MIN_MEMUSED =
      new KnobTemplate<uns>("pref_hybrid_min_memused", 10);
  KNOB_PREF_HYBRID_SORT_ON_ACC =
      new KnobTemplate<bool>("pref_hybrid_sort_on_acc", true);
  KNOB_PREF_HYBRID_SORT_ON_COV =
      new KnobTemplate<bool>("pref_hybrid_sort_on_cov", false);
  KNOB_PREF_ACC_THRESH_1 = new KnobTemplate<float>("pref_acc_thresh_1", 0.90);
  KNOB_PREF_ACC_THRESH_2 = new KnobTemplate<float>("pref_acc_thresh_2", 0.70);
  KNOB_PREF_ACC_THRESH_3 = new KnobTemplate<float>("pref_acc_thresh_3", 0.60);
  KNOB_PREF_UPDATE_INTERVAL =
      new KnobTemplate<uns64>("pref_update_interval", 0);
  KNOB_PREF_ACC_STUDY = new KnobTemplate<bool>("pref_acc_study", false);
  KNOB_PREF_ACC_UPDATE_INTERVAL =
      new KnobTemplate<uns64>("pref_acc_update_interval", 1000000);
  KNOB_PREF_ANALYZE_LOAD = new KnobTemplate<bool>("pref_analyze_load", false);
  KNOB_PREF_POL_THRESH_1 = new KnobTemplate<float>("pref_pol_thresh_1", 0.25);
  KNOB_PREF_POL_THRESH_2 = new KnobTemplate<float>("pref_pol_thresh_2", 0.10);
  KNOB_PREF_POLBV_ON = new KnobTemplate<bool>("pref_polbv_on", false);
  KNOB_PREF_POLBV_SIZE = new KnobTemplate<uns>("pref_polbv_size", 1024);
  KNOB_LOG2_PREF_POLBV_SIZE = new KnobTemplate<uns>("log2_pref_polbv_size", 10);
  KNOB_PREF_TIMELY_THRESH = new KnobTemplate<float>("pref_timely_thresh", 0.05);
  KNOB_PREF_POLPF_THRESH = new KnobTemplate<float>("pref_polpf_thresh", 0.01);
  KNOB_PREF_DEGFB_USEONLYACC =
      new KnobTemplate<bool>("pref_degfb_useonlyacc", false);
  KNOB_PREF_DEGFB_USEONLYPOL =
      new KnobTemplate<bool>("pref_degfb_useonlypol", false);
  KNOB_PREF_DEGFB_USEONLYLATE =
      new KnobTemplate<bool>("pref_degfb_useonlylate", false);
  KNOB_PREF_TIMELY_THRESH_2 =
      new KnobTemplate<float>("pref_timely_thresh_2", 0.005);
  KNOB_PREF_DEGFB_STATPHASEFILE =
      new KnobTemplate<bool>("pref_degfb_statphasefile", false);
  KNOB_PREF_DHAL = new KnobTemplate<bool>("pref_dhal", false);
  KNOB_PREF_DHAL_SENTTHRESH = new KnobTemplate<uns>("pref_dhal_sentthresh", 16);
  KNOB_PREF_DHAL_USETHRESH_MAX =
      new KnobTemplate<uns>("pref_dhal_usethresh_max", 12);
  KNOB_PREF_DHAL_USETHRESH_MIN2 =
      new KnobTemplate<uns>("pref_dhal_usethresh_min2", 8);
  KNOB_PREF_DHAL_USETHRESH_MIN1 =
      new KnobTemplate<uns>("pref_dhal_usethresh_min1", 4);
  KNOB_PREF_DHAL_MAXDEG = new KnobTemplate<uns>("pref_dhal_maxdeg", 64);
  KNOB_PREF_THREAD_INDEX = new KnobTemplate<bool>("pref_thread_index", false);
  KNOB_PREF_TRAIN_INST_ONCE =
      new KnobTemplate<bool>("pref_train_inst_once", false);
  KNOB_DEBUG_PREF_STRIDE = new KnobTemplate<bool>("debug_pref_stride", false);
  KNOB_PREF_STRIDE_TABLE_N = new KnobTemplate<int>("pref_stride_table_n", 256);
  KNOB_PREF_STRIDE_REGION_BITS =
      new KnobTemplate<uns>("pref_stride_region_bits", 16);
  KNOB_PREF_STRIDE_DEGREE = new KnobTemplate<int>("pref_stride_degree", 4);
  KNOB_PREF_STRIDE_DISTANCE = new KnobTemplate<int>("pref_stride_distance", 16);
  KNOB_PREF_STRIDE_STARTDISTANCE =
      new KnobTemplate<int>("pref_stride_startdistance", 1);
  KNOB_PREF_STRIDE_SINGLE_THRESH =
      new KnobTemplate<int>("pref_stride_single_thresh", 6);
  KNOB_PREF_STRIDE_MULTI_THRESH =
      new KnobTemplate<int>("pref_stride_multi_thresh", 6);
  KNOB_PREF_STRIDE_SINGLE_STRIDE_MODE =
      new KnobTemplate<bool>("pref_stride_single_stride_mode", false);
  KNOB_PREF_STRIDE_ON = new KnobTemplate<bool>("pref_stride_on", false);
  KNOB_PREF_STRIDE_ON_MEDIUM_CORE =
      new KnobTemplate<bool>("pref_stride_on_medium_core", false);
  KNOB_PREF_STRIDE_ON_LARGE_CORE =
      new KnobTemplate<bool>("pref_stride_on_large_core", false);

  // =========== ../def/ramulator.param.def ===========
  KNOB_RAMULATOR_CONFIG_FILE = new KnobTemplate<string>(
      "ramulator_config_file", "../src/ramulator/configs/GDDR5-config.cfg");
  KNOB_RAMULATOR_CACHELINE_SIZE =
      new KnobTemplate<int>("ramulator_cacheline_size", 128);

  // =========== ../def/schedule.param.def ===========
  KNOB_ISCHED_SIZE = new KnobTemplate<uns16>("isched_size", 16);
  KNOB_MSCHED_SIZE = new KnobTemplate<uns16>("msched_size", 8);
  KNOB_FSCHED_SIZE = new KnobTemplate<uns16>("fsched_size", 24);
  KNOB_ISCHED_MEDIUM_SIZE =
      new KnobTemplate<uns16>("isched_medium_size", 16, "isched_size");
  KNOB_MSCHED_MEDIUM_SIZE =
      new KnobTemplate<uns16>("msched_medium_size", 8, "msched_size");
  KNOB_FSCHED_MEDIUM_SIZE =
      new KnobTemplate<uns16>("fsched_medium_size", 24, "fsched_size");
  KNOB_ISCHED_LARGE_SIZE =
      new KnobTemplate<uns16>("isched_large_size", 16, "isched_size");
  KNOB_MSCHED_LARGE_SIZE =
      new KnobTemplate<uns16>("msched_large_size", 8, "msched_size");
  KNOB_FSCHED_LARGE_SIZE =
      new KnobTemplate<uns16>("fsched_large_size", 24, "fsched_size");
  KNOB_ISCHED_RATE = new KnobTemplate<uns16>("isched_rate", 2);
  KNOB_MSCHED_RATE = new KnobTemplate<uns16>("msched_rate", 1);
  KNOB_FSCHED_RATE = new KnobTemplate<uns16>("fsched_rate", 2);
  KNOB_ISCHED_MEDIUM_RATE =
      new KnobTemplate<uns16>("isched_medium_rate", 2, "isched_rate");
  KNOB_MSCHED_MEDIUM_RATE =
      new KnobTemplate<uns16>("msched_medium_rate", 1, "msched_rate");
  KNOB_FSCHED_MEDIUM_RATE =
      new KnobTemplate<uns16>("fsched_medium_rate", 2, "fsched_rate");
  KNOB_ISCHED_LARGE_RATE =
      new KnobTemplate<uns16>("isched_large_rate", 2, "isched_rate");
  KNOB_MSCHED_LARGE_RATE =
      new KnobTemplate<uns16>("msched_large_rate", 1, "msched_rate");
  KNOB_FSCHED_LARGE_RATE =
      new KnobTemplate<uns16>("fsched_large_rate", 2, "fsched_rate");
  KNOB_SCHED_TO_WIDTH = new KnobTemplate<uns16>("sched_to_width", 2);
  KNOB_SCHED_TO_MEDIUM_WIDTH =
      new KnobTemplate<uns16>("sched_to_medium_width", 2, "sched_to_width");
  KNOB_SCHED_TO_LARGE_WIDTH =
      new KnobTemplate<uns16>("sched_to_large_width", 2, "sched_to_width");
  KNOB_TRACE_NAME_FILE =
      new KnobTemplate<string>("trace_name_file", "trace_file_list");
  KNOB_NUM_WARP_SCHEDULER = new KnobTemplate<int>("num_warp_scheduler", 1);

  // =========== ../def/utils.param.def ===========
  KNOB_BUG_DETECTOR_ENABLE =
      new KnobTemplate<bool>("bug_detector_enable", false);
  KNOB_COLLECT_CPI_INFO = new KnobTemplate<int>("collect_cpi_info", 0);
  KNOB_COLLECT_CPI_INFO_FOR_MULTI_GPU =
      new KnobTemplate<int>("collect_cpi_info_for_multi_gpu", 0);
}

all_knobs_c::~all_knobs_c() {
  delete KNOB_BP_HIST_LENGTH;
  delete KNOB_PHT_CTR_BITS;
  delete KNOB_BP_DIR_MECH;
  delete KNOB_EXTRA_RECOVERY_CYCLES;
  delete KNOB_USE_BRANCH_PREDICTION;
  delete KNOB_PERFECT_BP;
  delete KNOB_PERFECT_BTB;
  delete KNOB_BTB_ENTRIES;
  delete KNOB_BTB_ASSOC;
  delete KNOB_BTB_BANK_NUM;
  delete KNOB_ENABLE_BTB;
  delete KNOB_FE_SIZE;
  delete KNOB_SCHED_CLOCK;
  delete KNOB_ALLOC_TO_EXEC_LATENCY;
  delete KNOB_GIAQ_SIZE;
  delete KNOB_MIAQ_SIZE;
  delete KNOB_FQ_SIZE;
  delete KNOB_GIAQ_MEDIUM_SIZE;
  delete KNOB_MIAQ_MEDIUM_SIZE;
  delete KNOB_FQ_MEDIUM_SIZE;
  delete KNOB_GIAQ_LARGE_SIZE;
  delete KNOB_MIAQ_LARGE_SIZE;
  delete KNOB_FQ_LARGE_SIZE;
  delete KNOB_GEN_ALLOCQ_INDEX;
  delete KNOB_MEM_ALLOCQ_INDEX;
  delete KNOB_FLOAT_ALLOCQ_INDEX;
  delete KNOB_ONE_CYCLE_EXEC;
  delete KNOB_MAX_INSTS;
  delete KNOB_SIM_CYCLE_COUNT;
  delete KNOB_FORWARD_PROGRESS_LIMIT;
  delete KNOB_MAX_BLOCK_PER_CORE_SUPER;
  delete KNOB_ROB_SIZE;
  delete KNOB_ROB_MEDIUM_SIZE;
  delete KNOB_ROB_LARGE_SIZE;
  delete KNOB_INT_REGFILE_SIZE;
  delete KNOB_FP_REGFILE_SIZE;
  delete KNOB_MEU_NSB;
  delete KNOB_MEU_NLB;
  delete KNOB_MEU_MEDIUM_NSB;
  delete KNOB_MEU_MEDIUM_NLB;
  delete KNOB_MEU_LARGE_NSB;
  delete KNOB_MEU_LARGE_NLB;
  delete KNOB_WIDTH;
  delete KNOB_MEDIUM_WIDTH;
  delete KNOB_LARGE_WIDTH;
  delete KNOB_EXEC_RETIRE_LATENCY;
  delete KNOB_MEM_OBEY_STORE_DEP;
  delete KNOB_MEM_OOO_STORES;
  delete KNOB_USE_NEW_ORACLE;
  delete KNOB_IGNORE_DEP;
  delete KNOB_HEARTBEAT_INTERVAL;
  delete KNOB_GPU_FETCH_RATIO;
  delete KNOB_GPU_SCHEDULE_RATIO;
  delete KNOB_CPU_FETCH_RATIO;
  delete KNOB_PTX_EXEC_RATIO;
  delete KNOB_PTX_INST_LATENCY;
  delete KNOB_PTX_DISPATCH_LATENCY_FACTOR;
  delete KNOB_NUM_SIM_CORES;
  delete KNOB_CORE_TYPE;
  delete KNOB_MEDIUM_CORE_TYPE;
  delete KNOB_LARGE_CORE_TYPE;
  delete KNOB_NUM_SIM_SMALL_CORES;
  delete KNOB_NUM_SIM_LARGE_CORES;
  delete KNOB_NUM_SIM_MEDIUM_CORES;
  delete KNOB_MAX_THREADS_PER_CORE;
  delete KNOB_MAX_THREADS_PER_MEDIUM_CORE;
  delete KNOB_MAX_THREADS_PER_LARGE_CORE;
  delete KNOB_SCHEDULE;
  delete KNOB_MEDIUM_CORE_SCHEDULE;
  delete KNOB_LARGE_CORE_SCHEDULE;
  delete KNOB_FETCH_LATENCY;
  delete KNOB_ALLOC_LATENCY;
  delete KNOB_MEDIUM_CORE_ALLOC_LATENCY;
  delete KNOB_MEDIUM_CORE_FETCH_LATENCY;
  delete KNOB_LARGE_CORE_ALLOC_LATENCY;
  delete KNOB_LARGE_CORE_FETCH_LATENCY;
  delete KNOB_PRINT_HEARTBEAT;
  delete KNOB_GPU_SCHED;
  delete KNOB_GPU_USE_SINGLE_ALLOCQ_TYPE;
  delete KNOB_GPU_SHARE_ALLOCQS_BETWEEN_THREADS;
  delete KNOB_MAX_WARP_PER_SM;
  delete KNOB_SP_PER_SM;
  delete KNOB_SFU_PER_SM;
  delete KNOB_LDST_PER_SM;
  delete KNOB_32_64_ISA;
  delete KNOB_PHY_ADDR_WIDTH;
  delete KNOB_FEATURE_SIZE;
  delete KNOB_PCIE_BUS_SIZE;
  delete KNOB_PCIE_TR;
  delete KNOB_PCIE_INIT;
  delete KNOB_INST_LENGTH;
  delete KNOB_OPCODE_WIDTH;
  delete KNOB_MICRO_OPCODE_WIDTH;
  delete KNOB_INST_BUF_SIZE;
  delete KNOB_DEC_STREAM_BUF_SIZE;
  delete KNOB_FP_INST_WINDOW_SIZE;
  delete KNOB_RAS_SIZE;
  delete KNOB_IFU_DUTY_CYCLE;
  delete KNOB_LSU_DUTY_CYCLE;
  delete KNOB_MEM_I_DUTY_CYCLE;
  delete KNOB_MEM_D_DUTY_CYCLE;
  delete KNOB_ALU_DUTY_CYCLE;
  delete KNOB_MUL_DUTY_CYCLE;
  delete KNOB_FPU_DUTY_CYCLE;
  delete KNOB_ALU_CDB_DUTY_CYCLE;
  delete KNOB_MUL_CDB_DUTY_CYCLE;
  delete KNOB_FPU_CDB_DUTY_CYCLE;
  delete KNOB_ICACHE_THROUGHPUT;
  delete KNOB_DCACHE_THROUGHPUT;
  delete KNOB_L2_THROUGHPUT;
  delete KNOB_L3_THROUGHPUT;
  delete KNOB_L2_CLOCKRATE;
  delete KNOB_L3_CLOCKRATE;
  delete KNOB_DRAM_CLOCKRATE;
  delete KNOB_IS_GPU;
  delete KNOB_GPU_WIDTH;
  delete KNOB_ORIG_PIPELINE_STAGES;
  delete KNOB_EI_DECODE_WIDTH;
  delete KNOB_EI_ISSUE_WIDTH;
  delete KNOB_EI_EXEC_WIDTH;
  delete KNOB_EI_COMMIT_WIDTH;
  delete KNOB_IS_FERMI;
  delete KNOB_FENCE_ENABLE;
  delete KNOB_FENCE_PREF_ENABLE;
  delete KNOB_ACQ_REL;
  delete KNOB_USE_WB;
  delete KNOB_WB_SIZE;
  delete KNOB_WB_FIFO;
  delete KNOB_QSIM_STATE;
  delete KNOB_QSIM_BENCH;
  delete KNOB_DEBUG_CYCLE_START;
  delete KNOB_DEBUG_CYCLE_STOP;
  delete KNOB_DEBUG_INST_START;
  delete KNOB_DEBUG_INST_STOP;
  delete KNOB_DEBUG_FRONT_STAGE;
  delete KNOB_DEBUG_ALLOC_STAGE;
  delete KNOB_DEBUG_SCHEDULE_STAGE;
  delete KNOB_DEBUG_EXEC_STAGE;
  delete KNOB_DEBUG_DCU_STAGE;
  delete KNOB_DEBUG_RETIRE_STAGE;
  delete KNOB_DEBUG_MEM;
  delete KNOB_DEBUG_TRACE_READ;
  delete KNOB_DEBUG_SIM;
  delete KNOB_DEBUG_CACHE_LIB;
  delete KNOB_DEBUG_BP_DIR;
  delete KNOB_DEBUG_BTB;
  delete KNOB_DEBUG_MAP_STAGE;
  delete KNOB_DEBUG_PORT;
  delete KNOB_DEBUG_CORE_ID;
  delete KNOB_DEBUG_SIM_THREAD_SCHEDULE;
  delete KNOB_DEBUG_DRAM;
  delete KNOB_DEBUG_PRINT_TRACE;
  delete KNOB_DEBUG_MEM_TRACE;
  delete KNOB_DEBUG_NOC;
  delete KNOB_DEBUG_HMC;
  delete KNOB_ENABLE_DYFR;
  delete KNOB_NUM_CPU_APPLICATION;
  delete KNOB_DYFR_GPU_FREQ_MIN;
  delete KNOB_DYFR_GPU_FREQ_MAX;
  delete KNOB_DYFR_CPU_FREQ_MIN;
  delete KNOB_DYFR_CPU_FREQ_MAX;
  delete KNOB_DYFR_SAMPLE_PERIOD;
  delete KNOB_DYFR_PLL_LOCK;
  delete KNOB_DYFR_CPU_BUDGET;
  delete KNOB_DYFR_GPU_BUDGET;
  delete KNOB_DYFR_MEM_BUDGET;
  delete KNOB_FETCH_WDITH;
  delete KNOB_FETCH_MEDIUM_WDITH;
  delete KNOB_FETCH_LARGE_WDITH;
  delete KNOB_FETCH_ONLY_LOAD_READY;
  delete KNOB_FETCH_ONLY_SCHED_READY;
  delete KNOB_MT_NO_FETCH_BR;
  delete KNOB_NO_FETCH_ON_ICACHE_MISS;
  delete KNOB_FETCH_POLICY;
  delete KNOB_DEC_RR_FREQ;
  delete KNOB_MT_STOP_FAIR_INIT;
  delete KNOB_FETCH_FAIR_PERIOD;
  delete KNOB_FETCH_FAIR_MERGE_TH;
  delete KNOB_FETCH_FAIR_TSHARE_TH;
  delete KNOB_FETCH_FAIR_MERGE;
  delete KNOB_FETCH_FAIR_TSHARE;
  delete KNOB_BLOCK_KEY_SIZE;
  delete KNOB_FETCH_FAIR_TSHARE_FREQ;
  delete KNOB_NUM_INST_TO_FETCH_AFTER_LOAD;
  delete KNOB_ENABLE_ENERGY_INTROSPECTOR;
  delete KNOB_POWER_PRINT_LEVEL;
  delete KNOB_BLOCKS_TO_SIMULATE;
  delete KNOB_SIMULATE_LAST_BLOCKS;
  delete KNOB_REPEAT_TRACE;
  delete KNOB_REPEAT_TRACE_N;
  delete KNOB_MAX_NUM_CORE_PER_APPL;
  delete KNOB_MAX_BLOCKS_TO_SIMULATE;
  delete KNOB_STDERR_FILE;
  delete KNOB_STDOUT_FILE;
  delete KNOB_FILE_TAG;
  delete KNOB_STATISTICS_OUT_DIRECTORY;
  delete KNOB_MAX_BLOCK_PER_CORE;
  delete KNOB_MAX_INSTS1;
  delete KNOB_ENABLE_CONDITIONAL_EXECUTION;
  delete KNOB_TEMPERATURE;
  delete KNOB_ASSIGN_BLOCKS_GREEDILY_INITIALLY;
  delete KNOB_CLOCK_CPU;
  delete KNOB_CLOCK_GPU;
  delete KNOB_CLOCK_L3;
  delete KNOB_CLOCK_NOC;
  delete KNOB_CLOCK_MC;
  delete KNOB_COMPUTE_CAPABILITY;
  delete KNOB_GPU_WARP_SIZE;
  delete KNOB_TRACE_USES_64_BIT_ADDR;
  delete KNOB_ENABLE_FAST_FORWARD_MODE;
  delete KNOB_FAST_FORWARD_MODE_THRESHOLD;
  delete KNOB_ENABLE_HMC_INST;
  delete KNOB_ENABLE_HMC_INST_SKIP;
  delete KNOB_ENABLE_HMC_BYPASS_CACHE;
  delete KNOB_ENABLE_NONHMC_STAT;
  delete KNOB_ENABLE_LOCK_SKIP;
  delete KNOB_ENABLE_HMC_TRANS;
  delete KNOB_ENABLE_HMC_FENCE;
  delete KNOB_ENABLE_HMC_DOUBLE_FENCE;
  delete KNOB_COUNT_HMC_REMOVED_IN_MAX_INSTS;
  delete KNOB_HMC_ADD_DEP;
  delete KNOB_ENABLE_TRACE_MAX_THREAD;
  delete KNOB_TRACE_MAX_THREAD_COUNT;
  delete KNOB_HMC_TEST_OVERHEAD;
  delete KNOB_PERFECT_ICACHE;
  delete KNOB_ICACHE_NUM_SET;
  delete KNOB_ICACHE_ASSOC;
  delete KNOB_ICACHE_LINE_SIZE;
  delete KNOB_ICACHE_BANKS;
  delete KNOB_ICACHE_BY_PASS;
  delete KNOB_ICACHE_CYCLES;
  delete KNOB_ICACHE_MEDIUM_NUM_SET;
  delete KNOB_ICACHE_MEDIUM_ASSOC;
  delete KNOB_ICACHE_MEDIUM_LINE_SIZE;
  delete KNOB_ICACHE_MEDIUM_BANKS;
  delete KNOB_ICACHE_MEDIUM_BY_PASS;
  delete KNOB_ICACHE_MEDIUM_CYCLES;
  delete KNOB_ICACHE_LARGE_NUM_SET;
  delete KNOB_ICACHE_LARGE_ASSOC;
  delete KNOB_ICACHE_LARGE_LINE_SIZE;
  delete KNOB_ICACHE_LARGE_BANKS;
  delete KNOB_ICACHE_LARGE_BY_PASS;
  delete KNOB_ICACHE_LARGE_CYCLES;
  delete KNOB_ICACHE_READ_PORTS;
  delete KNOB_ICACHE_WRITE_PORTS;
  delete KNOB_PERFECT_DCACHE;
  delete KNOB_L1_READ_PORTS;
  delete KNOB_L2_READ_PORTS;
  delete KNOB_L3_READ_PORTS;
  delete KNOB_L1_WRITE_PORTS;
  delete KNOB_L2_WRITE_PORTS;
  delete KNOB_L3_WRITE_PORTS;
  delete KNOB_L1_SMALL_NUM_SET;
  delete KNOB_L1_SMALL_ASSOC;
  delete KNOB_L1_SMALL_LINE_SIZE;
  delete KNOB_L1_SMALL_NUM_BANK;
  delete KNOB_L1_SMALL_LATENCY;
  delete KNOB_L1_SMALL_BYPASS;
  delete KNOB_L2_SMALL_NUM_SET;
  delete KNOB_L2_SMALL_ASSOC;
  delete KNOB_L2_SMALL_LINE_SIZE;
  delete KNOB_L2_SMALL_NUM_BANK;
  delete KNOB_L2_SMALL_LATENCY;
  delete KNOB_L2_SMALL_BYPASS;
  delete KNOB_L1_MEDIUM_NUM_SET;
  delete KNOB_L1_MEDIUM_ASSOC;
  delete KNOB_L1_MEDIUM_LINE_SIZE;
  delete KNOB_L1_MEDIUM_NUM_BANK;
  delete KNOB_L1_MEDIUM_LATENCY;
  delete KNOB_L1_MEDIUM_BYPASS;
  delete KNOB_L2_MEDIUM_NUM_SET;
  delete KNOB_L2_MEDIUM_ASSOC;
  delete KNOB_L2_MEDIUM_LINE_SIZE;
  delete KNOB_L2_MEDIUM_NUM_BANK;
  delete KNOB_L2_MEDIUM_LATENCY;
  delete KNOB_L2_MEDIUM_BYPASS;
  delete KNOB_L1_LARGE_NUM_SET;
  delete KNOB_L1_LARGE_ASSOC;
  delete KNOB_L1_LARGE_LINE_SIZE;
  delete KNOB_L1_LARGE_NUM_BANK;
  delete KNOB_L1_LARGE_LATENCY;
  delete KNOB_L1_LARGE_BYPASS;
  delete KNOB_L2_LARGE_NUM_SET;
  delete KNOB_L2_LARGE_ASSOC;
  delete KNOB_L2_LARGE_LINE_SIZE;
  delete KNOB_L2_LARGE_NUM_BANK;
  delete KNOB_L2_LARGE_LATENCY;
  delete KNOB_L2_LARGE_BYPASS;
  delete KNOB_NUM_L3;
  delete KNOB_L3_INTERLEAVE_FACTOR;
  delete KNOB_L3_NUM_SET;
  delete KNOB_L3_ASSOC;
  delete KNOB_L3_LINE_SIZE;
  delete KNOB_L3_NUM_BANK;
  delete KNOB_L3_LATENCY;
  delete KNOB_DCACHE_INFINITE_PORT;
  delete KNOB_SIMPLESSD_CONFIG;
  delete KNOB_DRAM_BUFFER_SIZE;
  delete KNOB_DRAM_BANK_XOR_INDEX;
  delete KNOB_DRAM_MERGE_REQUESTS;
  delete KNOB_DRAM_ROWBUFFER_SIZE;
  delete KNOB_DRAM_SCHEDULING_POLICY;
  delete KNOB_DRAM_NUM_CHANNEL;
  delete KNOB_DRAM_NUM_BANKS;
  delete KNOB_DRAM_ONE_CYCLE;
  delete KNOB_DRAM_DDR_FACTOR;
  delete KNOB_DRAM_BUS_WIDTH;
  delete KNOB_DRAM_COLUMN;
  delete KNOB_DRAM_PRECHARGE;
  delete KNOB_DRAM_ACTIVATE;
  delete KNOB_DRAM_NUM_MC;
  delete KNOB_DRAM_INTERLEAVE_FACTOR;
  delete KNOB_DRAM_ADDITIONAL_LATENCY;
  delete KNOB_MEMORY_TYPE;
  delete KNOB_MEM_MSHR_SIZE;
  delete KNOB_MEM_QUEUE_SIZE;
  delete KNOB_ENABLE_PREF_SMALL_CORE;
  delete KNOB_ENABLE_PREF_MEDIUM_CORE;
  delete KNOB_ENABLE_PREF_LARGE_CORE;
  delete KNOB_MEM_SIZE_AMP;
  delete KNOB_PTX_COMMON_CACHE;
  delete KNOB_MAX_TRANSACTION_SIZE;
  delete KNOB_BYTE_LEVEL_ACCESS;
  delete KNOB_INFINITE_PORT;
  delete KNOB_EXTRA_LD_LATENCY;
  delete KNOB_USE_CONST_AND_TEX_CACHES;
  delete KNOB_CONST_CACHE_SIZE;
  delete KNOB_CONST_CACHE_ASSOC;
  delete KNOB_CONST_CACHE_LINE_SIZE;
  delete KNOB_CONST_CACHE_BANKS;
  delete KNOB_CONST_CACHE_CYCLES;
  delete KNOB_TEXTURE_CACHE_SIZE;
  delete KNOB_TEXTURE_CACHE_ASSOC;
  delete KNOB_TEXTURE_CACHE_LINE_SIZE;
  delete KNOB_TEXTURE_CACHE_BANKS;
  delete KNOB_TEXTURE_CACHE_CYCLES;
  delete KNOB_SHARED_MEM_SIZE;
  delete KNOB_SHARED_MEM_ASSOC;
  delete KNOB_SHARED_MEM_LINE_SIZE;
  delete KNOB_SHARED_MEM_BANKS;
  delete KNOB_SHARED_MEM_CYCLES;
  delete KNOB_SHARED_MEM_PORTS;
  delete KNOB_ENABLE_CACHE_COHERENCE;
  delete KNOB_LLC_TYPE;
  delete KNOB_COLLECT_CACHE_INFO;
  delete KNOB_HETERO_STATIC_CACHE_PARTITION;
  delete KNOB_HETERO_STATIC_CPU_PARTITION;
  delete KNOB_HETERO_STATIC_GPU_PARTITION;
  delete KNOB_HETERO_GPU_CORE_DISABLE;
  delete KNOB_HETERO_NOC_USE_SAME_QUEUE;
  delete KNOB_HETERO_MEM_PRIORITY_CPU;
  delete KNOB_HETERO_MEM_PRIORITY_GPU;
  delete KNOB_CACHE_USE_PSEUDO_LRU;
  delete KNOB_LOAD_BUF_SIZE;
  delete KNOB_STORE_BUF_SIZE;
  delete KNOB_USE_INCOMING_TID_CID_FOR_WB;
  delete KNOB_DEFAULT_INTERLEAVING;
  delete KNOB_NEW_INTERLEAVING_SAME_GRANULARITY;
  delete KNOB_NEW_INTERLEAVING_DIFF_GRANULARITY;
  delete KNOB_USE_NEW_COALESCING;
  delete KNOB_ENABLE_PHYSICAL_MAPPING;
  delete KNOB_PAGE_SIZE;
  delete KNOB_REGION_SIZE;
  delete KNOB_PAGE_MAPPING_POLICY;
  delete KNOB_USE_MEMHIERARCHY;
  delete KNOB_USE_VAULTSIM_LINK;
  delete KNOB_ENABLE_IRIS;
  delete KNOB_IRIS_TOPOLOGY;
  delete KNOB_IRIS_GRIDSIZE;
  delete KNOB_IRIS_NUM_VC;
  delete KNOB_IRIS_CREDIT;
  delete KNOB_IRIS_INT_BUFF_WIDTH;
  delete KNOB_IRIS_LINK_WIDTH;
  delete KNOB_IRIS_RC_METHOD;
  delete KNOB_IRIS_SELF_ASSIGN_DEST_ID;
  delete KNOB_IRIS_RESP_PAYLOAD_LEN;
  delete KNOB_IRIS_MEMORY_LATENCY;
  delete KNOB_ENABLE_NEW_NOC;
  delete KNOB_NUM_VC;
  delete KNOB_NUM_PORT;
  delete KNOB_LINK_LATENCY;
  delete KNOB_LINK_WIDTH;
  delete KNOB_NOC_DIMENSION;
  delete KNOB_NOC_TOPOLOGY;
  delete KNOB_ENABLE_HETEROGENEOUS_LINK;
  delete KNOB_NUM_SWITCH;
  delete KNOB_NUM_SWITCH_CPU;
  delete KNOB_NUM_SWITCH_GPU;
  delete KNOB_NUM_SWITCH_MEM;
  delete KNOB_ENABLE_HETEROGENEOUS_LINK_WIDTH;
  delete KNOB_NUM_SWITCH_ITER;
  delete KNOB_NUM_SWITCH_ITER_CPU;
  delete KNOB_NUM_SWITCH_ITER_GPU;
  delete KNOB_NUM_SWITCH_ITER_MEM;
  delete KNOB_ENABLE_NOC_VC_PARTITION;
  delete KNOB_CPU_VC_PARTITION;
  delete KNOB_GPU_VC_PARTITION;
  delete KNOB_ENABLE_CHANNEL_PARTITION;
  delete KNOB_NUM_CHANNEL_CPU;
  delete KNOB_NUM_CHANNEL_GPU;
  delete KNOB_ENABLE_ADAPTIVE_RING_ROUTING;
  delete KNOB_ARR_THRESHOLD;
  delete KNOB_ARR_DELTA;
  delete KNOB_ARR_ADV;
  delete KNOB_ARR_100;
  delete KNOB_ARBITRATION_POLICY;
  delete KNOB_ROUTER_PLACEMENT;
  delete KNOB_CORE_ENABLE_BEGIN;
  delete KNOB_CORE_ENABLE_END;
  delete KNOB_IDEAL_NOC;
  delete KNOB_IDEAL_NOC_LATENCY;
  delete KNOB_USE_ZERO_LATENCY_NOC;
  delete KNOB_PREF_FRAMEWORK_ON;
  delete KNOB_PREF_TRACE_ON;
  delete KNOB_DEBUG_PREF;
  delete KNOB_PREF_DL0REQ_QUEUE_SIZE;
  delete KNOB_PREF_UL1REQ_QUEUE_SIZE;
  delete KNOB_PREF_DL0_MISS_ON;
  delete KNOB_PREF_DL0_HIT_ON;
  delete KNOB_PREF_DL0REQ_QUEUE_FILTER_ON;
  delete KNOB_PREF_UL1REQ_QUEUE_FILTER_ON;
  delete KNOB_PREF_DL0REQ_ADD_FILTER_ON;
  delete KNOB_PREF_UL1REQ_ADD_FILTER_ON;
  delete KNOB_PREF_DL0REQ_QUEUE_OVERWRITE_ON_FULL;
  delete KNOB_PREF_UL1REQ_QUEUE_OVERWRITE_ON_FULL;
  delete KNOB_PREF_DL0SCHEDULE_NUM;
  delete KNOB_PREF_UL1SCHEDULE_NUM;
  delete KNOB_PREF_REGION_ON;
  delete KNOB_PREF_USEREGION_TOCALC_ACC;
  delete KNOB_PREF_NUMTRACKING_REGIONS;
  delete KNOB_PREF_REGION_SIZE;
  delete KNOB_PREF_HYBRID_ON;
  delete KNOB_PREF_HYBRID_DEFAULT;
  delete KNOB_PREF_HYBRID_DEFAULT_TIMEPERIOD;
  delete KNOB_PREF_HYBRID_UPDATE_MULTIPLE;
  delete KNOB_PREF_HYBRID_MIN_SENT;
  delete KNOB_PREF_HYBRID_MIN_MEMUSED;
  delete KNOB_PREF_HYBRID_SORT_ON_ACC;
  delete KNOB_PREF_HYBRID_SORT_ON_COV;
  delete KNOB_PREF_ACC_THRESH_1;
  delete KNOB_PREF_ACC_THRESH_2;
  delete KNOB_PREF_ACC_THRESH_3;
  delete KNOB_PREF_UPDATE_INTERVAL;
  delete KNOB_PREF_ACC_STUDY;
  delete KNOB_PREF_ACC_UPDATE_INTERVAL;
  delete KNOB_PREF_ANALYZE_LOAD;
  delete KNOB_PREF_POL_THRESH_1;
  delete KNOB_PREF_POL_THRESH_2;
  delete KNOB_PREF_POLBV_ON;
  delete KNOB_PREF_POLBV_SIZE;
  delete KNOB_LOG2_PREF_POLBV_SIZE;
  delete KNOB_PREF_TIMELY_THRESH;
  delete KNOB_PREF_POLPF_THRESH;
  delete KNOB_PREF_DEGFB_USEONLYACC;
  delete KNOB_PREF_DEGFB_USEONLYPOL;
  delete KNOB_PREF_DEGFB_USEONLYLATE;
  delete KNOB_PREF_TIMELY_THRESH_2;
  delete KNOB_PREF_DEGFB_STATPHASEFILE;
  delete KNOB_PREF_DHAL;
  delete KNOB_PREF_DHAL_SENTTHRESH;
  delete KNOB_PREF_DHAL_USETHRESH_MAX;
  delete KNOB_PREF_DHAL_USETHRESH_MIN2;
  delete KNOB_PREF_DHAL_USETHRESH_MIN1;
  delete KNOB_PREF_DHAL_MAXDEG;
  delete KNOB_PREF_THREAD_INDEX;
  delete KNOB_PREF_TRAIN_INST_ONCE;
  delete KNOB_DEBUG_PREF_STRIDE;
  delete KNOB_PREF_STRIDE_TABLE_N;
  delete KNOB_PREF_STRIDE_REGION_BITS;
  delete KNOB_PREF_STRIDE_DEGREE;
  delete KNOB_PREF_STRIDE_DISTANCE;
  delete KNOB_PREF_STRIDE_STARTDISTANCE;
  delete KNOB_PREF_STRIDE_SINGLE_THRESH;
  delete KNOB_PREF_STRIDE_MULTI_THRESH;
  delete KNOB_PREF_STRIDE_SINGLE_STRIDE_MODE;
  delete KNOB_PREF_STRIDE_ON;
  delete KNOB_PREF_STRIDE_ON_MEDIUM_CORE;
  delete KNOB_PREF_STRIDE_ON_LARGE_CORE;
  delete KNOB_RAMULATOR_CONFIG_FILE;
  delete KNOB_RAMULATOR_CACHELINE_SIZE;
  delete KNOB_ISCHED_SIZE;
  delete KNOB_MSCHED_SIZE;
  delete KNOB_FSCHED_SIZE;
  delete KNOB_ISCHED_MEDIUM_SIZE;
  delete KNOB_MSCHED_MEDIUM_SIZE;
  delete KNOB_FSCHED_MEDIUM_SIZE;
  delete KNOB_ISCHED_LARGE_SIZE;
  delete KNOB_MSCHED_LARGE_SIZE;
  delete KNOB_FSCHED_LARGE_SIZE;
  delete KNOB_ISCHED_RATE;
  delete KNOB_MSCHED_RATE;
  delete KNOB_FSCHED_RATE;
  delete KNOB_ISCHED_MEDIUM_RATE;
  delete KNOB_MSCHED_MEDIUM_RATE;
  delete KNOB_FSCHED_MEDIUM_RATE;
  delete KNOB_ISCHED_LARGE_RATE;
  delete KNOB_MSCHED_LARGE_RATE;
  delete KNOB_FSCHED_LARGE_RATE;
  delete KNOB_SCHED_TO_WIDTH;
  delete KNOB_SCHED_TO_MEDIUM_WIDTH;
  delete KNOB_SCHED_TO_LARGE_WIDTH;
  delete KNOB_TRACE_NAME_FILE;
  delete KNOB_NUM_WARP_SCHEDULER;
  delete KNOB_BUG_DETECTOR_ENABLE;
  delete KNOB_COLLECT_CPI_INFO;
  delete KNOB_COLLECT_CPI_INFO_FOR_MULTI_GPU;
}

void all_knobs_c::registerKnobs(KnobsContainer *container) {
  // =========== ../def/bp.param.def ===========
  container->insertKnob(KNOB_BP_HIST_LENGTH);
  container->insertKnob(KNOB_PHT_CTR_BITS);
  container->insertKnob(KNOB_BP_DIR_MECH);
  container->insertKnob(KNOB_EXTRA_RECOVERY_CYCLES);
  container->insertKnob(KNOB_USE_BRANCH_PREDICTION);
  container->insertKnob(KNOB_PERFECT_BP);
  container->insertKnob(KNOB_PERFECT_BTB);
  container->insertKnob(KNOB_BTB_ENTRIES);
  container->insertKnob(KNOB_BTB_ASSOC);
  container->insertKnob(KNOB_BTB_BANK_NUM);
  container->insertKnob(KNOB_ENABLE_BTB);

  // =========== ../def/core.param.def ===========
  container->insertKnob(KNOB_FE_SIZE);
  container->insertKnob(KNOB_SCHED_CLOCK);
  container->insertKnob(KNOB_ALLOC_TO_EXEC_LATENCY);
  container->insertKnob(KNOB_GIAQ_SIZE);
  container->insertKnob(KNOB_MIAQ_SIZE);
  container->insertKnob(KNOB_FQ_SIZE);
  container->insertKnob(KNOB_GIAQ_MEDIUM_SIZE);
  container->insertKnob(KNOB_MIAQ_MEDIUM_SIZE);
  container->insertKnob(KNOB_FQ_MEDIUM_SIZE);
  container->insertKnob(KNOB_GIAQ_LARGE_SIZE);
  container->insertKnob(KNOB_MIAQ_LARGE_SIZE);
  container->insertKnob(KNOB_FQ_LARGE_SIZE);
  container->insertKnob(KNOB_GEN_ALLOCQ_INDEX);
  container->insertKnob(KNOB_MEM_ALLOCQ_INDEX);
  container->insertKnob(KNOB_FLOAT_ALLOCQ_INDEX);
  container->insertKnob(KNOB_ONE_CYCLE_EXEC);
  container->insertKnob(KNOB_MAX_INSTS);
  container->insertKnob(KNOB_SIM_CYCLE_COUNT);
  container->insertKnob(KNOB_FORWARD_PROGRESS_LIMIT);
  container->insertKnob(KNOB_MAX_BLOCK_PER_CORE_SUPER);
  container->insertKnob(KNOB_ROB_SIZE);
  container->insertKnob(KNOB_ROB_MEDIUM_SIZE);
  container->insertKnob(KNOB_ROB_LARGE_SIZE);
  container->insertKnob(KNOB_INT_REGFILE_SIZE);
  container->insertKnob(KNOB_FP_REGFILE_SIZE);
  container->insertKnob(KNOB_MEU_NSB);
  container->insertKnob(KNOB_MEU_NLB);
  container->insertKnob(KNOB_MEU_MEDIUM_NSB);
  container->insertKnob(KNOB_MEU_MEDIUM_NLB);
  container->insertKnob(KNOB_MEU_LARGE_NSB);
  container->insertKnob(KNOB_MEU_LARGE_NLB);
  container->insertKnob(KNOB_WIDTH);
  container->insertKnob(KNOB_MEDIUM_WIDTH);
  container->insertKnob(KNOB_LARGE_WIDTH);
  container->insertKnob(KNOB_EXEC_RETIRE_LATENCY);
  container->insertKnob(KNOB_MEM_OBEY_STORE_DEP);
  container->insertKnob(KNOB_MEM_OOO_STORES);
  container->insertKnob(KNOB_USE_NEW_ORACLE);
  container->insertKnob(KNOB_IGNORE_DEP);
  container->insertKnob(KNOB_HEARTBEAT_INTERVAL);
  container->insertKnob(KNOB_GPU_FETCH_RATIO);
  container->insertKnob(KNOB_GPU_SCHEDULE_RATIO);
  container->insertKnob(KNOB_CPU_FETCH_RATIO);
  container->insertKnob(KNOB_PTX_EXEC_RATIO);
  container->insertKnob(KNOB_PTX_INST_LATENCY);
  container->insertKnob(KNOB_PTX_DISPATCH_LATENCY_FACTOR);
  container->insertKnob(KNOB_NUM_SIM_CORES);
  container->insertKnob(KNOB_CORE_TYPE);
  container->insertKnob(KNOB_MEDIUM_CORE_TYPE);
  container->insertKnob(KNOB_LARGE_CORE_TYPE);
  container->insertKnob(KNOB_NUM_SIM_SMALL_CORES);
  container->insertKnob(KNOB_NUM_SIM_LARGE_CORES);
  container->insertKnob(KNOB_NUM_SIM_MEDIUM_CORES);
  container->insertKnob(KNOB_MAX_THREADS_PER_CORE);
  container->insertKnob(KNOB_MAX_THREADS_PER_MEDIUM_CORE);
  container->insertKnob(KNOB_MAX_THREADS_PER_LARGE_CORE);
  container->insertKnob(KNOB_SCHEDULE);
  container->insertKnob(KNOB_MEDIUM_CORE_SCHEDULE);
  container->insertKnob(KNOB_LARGE_CORE_SCHEDULE);
  container->insertKnob(KNOB_FETCH_LATENCY);
  container->insertKnob(KNOB_ALLOC_LATENCY);
  container->insertKnob(KNOB_MEDIUM_CORE_ALLOC_LATENCY);
  container->insertKnob(KNOB_MEDIUM_CORE_FETCH_LATENCY);
  container->insertKnob(KNOB_LARGE_CORE_ALLOC_LATENCY);
  container->insertKnob(KNOB_LARGE_CORE_FETCH_LATENCY);
  container->insertKnob(KNOB_PRINT_HEARTBEAT);
  container->insertKnob(KNOB_GPU_SCHED);
  container->insertKnob(KNOB_GPU_USE_SINGLE_ALLOCQ_TYPE);
  container->insertKnob(KNOB_GPU_SHARE_ALLOCQS_BETWEEN_THREADS);
  container->insertKnob(KNOB_MAX_WARP_PER_SM);
  container->insertKnob(KNOB_SP_PER_SM);
  container->insertKnob(KNOB_SFU_PER_SM);
  container->insertKnob(KNOB_LDST_PER_SM);
  container->insertKnob(KNOB_32_64_ISA);
  container->insertKnob(KNOB_PHY_ADDR_WIDTH);
  container->insertKnob(KNOB_FEATURE_SIZE);
  container->insertKnob(KNOB_PCIE_BUS_SIZE);
  container->insertKnob(KNOB_PCIE_TR);
  container->insertKnob(KNOB_PCIE_INIT);
  container->insertKnob(KNOB_INST_LENGTH);
  container->insertKnob(KNOB_OPCODE_WIDTH);
  container->insertKnob(KNOB_MICRO_OPCODE_WIDTH);
  container->insertKnob(KNOB_INST_BUF_SIZE);
  container->insertKnob(KNOB_DEC_STREAM_BUF_SIZE);
  container->insertKnob(KNOB_FP_INST_WINDOW_SIZE);
  container->insertKnob(KNOB_RAS_SIZE);
  container->insertKnob(KNOB_IFU_DUTY_CYCLE);
  container->insertKnob(KNOB_LSU_DUTY_CYCLE);
  container->insertKnob(KNOB_MEM_I_DUTY_CYCLE);
  container->insertKnob(KNOB_MEM_D_DUTY_CYCLE);
  container->insertKnob(KNOB_ALU_DUTY_CYCLE);
  container->insertKnob(KNOB_MUL_DUTY_CYCLE);
  container->insertKnob(KNOB_FPU_DUTY_CYCLE);
  container->insertKnob(KNOB_ALU_CDB_DUTY_CYCLE);
  container->insertKnob(KNOB_MUL_CDB_DUTY_CYCLE);
  container->insertKnob(KNOB_FPU_CDB_DUTY_CYCLE);
  container->insertKnob(KNOB_ICACHE_THROUGHPUT);
  container->insertKnob(KNOB_DCACHE_THROUGHPUT);
  container->insertKnob(KNOB_L2_THROUGHPUT);
  container->insertKnob(KNOB_L3_THROUGHPUT);
  container->insertKnob(KNOB_L2_CLOCKRATE);
  container->insertKnob(KNOB_L3_CLOCKRATE);
  container->insertKnob(KNOB_DRAM_CLOCKRATE);
  container->insertKnob(KNOB_IS_GPU);
  container->insertKnob(KNOB_GPU_WIDTH);
  container->insertKnob(KNOB_ORIG_PIPELINE_STAGES);
  container->insertKnob(KNOB_EI_DECODE_WIDTH);
  container->insertKnob(KNOB_EI_ISSUE_WIDTH);
  container->insertKnob(KNOB_EI_EXEC_WIDTH);
  container->insertKnob(KNOB_EI_COMMIT_WIDTH);
  container->insertKnob(KNOB_IS_FERMI);
  container->insertKnob(KNOB_FENCE_ENABLE);
  container->insertKnob(KNOB_FENCE_PREF_ENABLE);
  container->insertKnob(KNOB_ACQ_REL);
  container->insertKnob(KNOB_USE_WB);
  container->insertKnob(KNOB_WB_SIZE);
  container->insertKnob(KNOB_WB_FIFO);
  container->insertKnob(KNOB_QSIM_STATE);
  container->insertKnob(KNOB_QSIM_BENCH);

  // =========== ../def/debug.param.def ===========
  container->insertKnob(KNOB_DEBUG_CYCLE_START);
  container->insertKnob(KNOB_DEBUG_CYCLE_STOP);
  container->insertKnob(KNOB_DEBUG_INST_START);
  container->insertKnob(KNOB_DEBUG_INST_STOP);
  container->insertKnob(KNOB_DEBUG_FRONT_STAGE);
  container->insertKnob(KNOB_DEBUG_ALLOC_STAGE);
  container->insertKnob(KNOB_DEBUG_SCHEDULE_STAGE);
  container->insertKnob(KNOB_DEBUG_EXEC_STAGE);
  container->insertKnob(KNOB_DEBUG_DCU_STAGE);
  container->insertKnob(KNOB_DEBUG_RETIRE_STAGE);
  container->insertKnob(KNOB_DEBUG_MEM);
  container->insertKnob(KNOB_DEBUG_TRACE_READ);
  container->insertKnob(KNOB_DEBUG_SIM);
  container->insertKnob(KNOB_DEBUG_CACHE_LIB);
  container->insertKnob(KNOB_DEBUG_BP_DIR);
  container->insertKnob(KNOB_DEBUG_BTB);
  container->insertKnob(KNOB_DEBUG_MAP_STAGE);
  container->insertKnob(KNOB_DEBUG_PORT);
  container->insertKnob(KNOB_DEBUG_CORE_ID);
  container->insertKnob(KNOB_DEBUG_SIM_THREAD_SCHEDULE);
  container->insertKnob(KNOB_DEBUG_DRAM);
  container->insertKnob(KNOB_DEBUG_PRINT_TRACE);
  container->insertKnob(KNOB_DEBUG_MEM_TRACE);
  container->insertKnob(KNOB_DEBUG_NOC);
  container->insertKnob(KNOB_DEBUG_HMC);

  // =========== ../def/dyfr.param.def ===========
  container->insertKnob(KNOB_ENABLE_DYFR);
  container->insertKnob(KNOB_NUM_CPU_APPLICATION);
  container->insertKnob(KNOB_DYFR_GPU_FREQ_MIN);
  container->insertKnob(KNOB_DYFR_GPU_FREQ_MAX);
  container->insertKnob(KNOB_DYFR_CPU_FREQ_MIN);
  container->insertKnob(KNOB_DYFR_CPU_FREQ_MAX);
  container->insertKnob(KNOB_DYFR_SAMPLE_PERIOD);
  container->insertKnob(KNOB_DYFR_PLL_LOCK);
  container->insertKnob(KNOB_DYFR_CPU_BUDGET);
  container->insertKnob(KNOB_DYFR_GPU_BUDGET);
  container->insertKnob(KNOB_DYFR_MEM_BUDGET);

  // =========== ../def/frontend.param.def ===========
  container->insertKnob(KNOB_FETCH_WDITH);
  container->insertKnob(KNOB_FETCH_MEDIUM_WDITH);
  container->insertKnob(KNOB_FETCH_LARGE_WDITH);
  container->insertKnob(KNOB_FETCH_ONLY_LOAD_READY);
  container->insertKnob(KNOB_FETCH_ONLY_SCHED_READY);
  container->insertKnob(KNOB_MT_NO_FETCH_BR);
  container->insertKnob(KNOB_NO_FETCH_ON_ICACHE_MISS);
  container->insertKnob(KNOB_FETCH_POLICY);
  container->insertKnob(KNOB_DEC_RR_FREQ);
  container->insertKnob(KNOB_MT_STOP_FAIR_INIT);
  container->insertKnob(KNOB_FETCH_FAIR_PERIOD);
  container->insertKnob(KNOB_FETCH_FAIR_MERGE_TH);
  container->insertKnob(KNOB_FETCH_FAIR_TSHARE_TH);
  container->insertKnob(KNOB_FETCH_FAIR_MERGE);
  container->insertKnob(KNOB_FETCH_FAIR_TSHARE);
  container->insertKnob(KNOB_BLOCK_KEY_SIZE);
  container->insertKnob(KNOB_FETCH_FAIR_TSHARE_FREQ);
  container->insertKnob(KNOB_NUM_INST_TO_FETCH_AFTER_LOAD);

  // =========== ../def/general.param.def ===========
  container->insertKnob(KNOB_ENABLE_ENERGY_INTROSPECTOR);
  container->insertKnob(KNOB_POWER_PRINT_LEVEL);
  container->insertKnob(KNOB_BLOCKS_TO_SIMULATE);
  container->insertKnob(KNOB_SIMULATE_LAST_BLOCKS);
  container->insertKnob(KNOB_REPEAT_TRACE);
  container->insertKnob(KNOB_REPEAT_TRACE_N);
  container->insertKnob(KNOB_MAX_NUM_CORE_PER_APPL);
  container->insertKnob(KNOB_MAX_BLOCKS_TO_SIMULATE);
  container->insertKnob(KNOB_STDERR_FILE);
  container->insertKnob(KNOB_STDOUT_FILE);
  container->insertKnob(KNOB_FILE_TAG);
  container->insertKnob(KNOB_STATISTICS_OUT_DIRECTORY);
  container->insertKnob(KNOB_MAX_BLOCK_PER_CORE);
  container->insertKnob(KNOB_MAX_INSTS1);
  container->insertKnob(KNOB_ENABLE_CONDITIONAL_EXECUTION);
  container->insertKnob(KNOB_TEMPERATURE);
  container->insertKnob(KNOB_ASSIGN_BLOCKS_GREEDILY_INITIALLY);
  container->insertKnob(KNOB_CLOCK_CPU);
  container->insertKnob(KNOB_CLOCK_GPU);
  container->insertKnob(KNOB_CLOCK_L3);
  container->insertKnob(KNOB_CLOCK_NOC);
  container->insertKnob(KNOB_CLOCK_MC);
  container->insertKnob(KNOB_COMPUTE_CAPABILITY);
  container->insertKnob(KNOB_GPU_WARP_SIZE);
  container->insertKnob(KNOB_TRACE_USES_64_BIT_ADDR);
  container->insertKnob(KNOB_ENABLE_FAST_FORWARD_MODE);
  container->insertKnob(KNOB_FAST_FORWARD_MODE_THRESHOLD);

  // =========== ../def/hmc.param.def ===========
  container->insertKnob(KNOB_ENABLE_HMC_INST);
  container->insertKnob(KNOB_ENABLE_HMC_INST_SKIP);
  container->insertKnob(KNOB_ENABLE_HMC_BYPASS_CACHE);
  container->insertKnob(KNOB_ENABLE_NONHMC_STAT);
  container->insertKnob(KNOB_ENABLE_LOCK_SKIP);
  container->insertKnob(KNOB_ENABLE_HMC_TRANS);
  container->insertKnob(KNOB_ENABLE_HMC_FENCE);
  container->insertKnob(KNOB_ENABLE_HMC_DOUBLE_FENCE);
  container->insertKnob(KNOB_COUNT_HMC_REMOVED_IN_MAX_INSTS);
  container->insertKnob(KNOB_HMC_ADD_DEP);
  container->insertKnob(KNOB_ENABLE_TRACE_MAX_THREAD);
  container->insertKnob(KNOB_TRACE_MAX_THREAD_COUNT);
  container->insertKnob(KNOB_HMC_TEST_OVERHEAD);

  // =========== ../def/memory.param.def ===========
  container->insertKnob(KNOB_PERFECT_ICACHE);
  container->insertKnob(KNOB_ICACHE_NUM_SET);
  container->insertKnob(KNOB_ICACHE_ASSOC);
  container->insertKnob(KNOB_ICACHE_LINE_SIZE);
  container->insertKnob(KNOB_ICACHE_BANKS);
  container->insertKnob(KNOB_ICACHE_BY_PASS);
  container->insertKnob(KNOB_ICACHE_CYCLES);
  container->insertKnob(KNOB_ICACHE_MEDIUM_NUM_SET);
  container->insertKnob(KNOB_ICACHE_MEDIUM_ASSOC);
  container->insertKnob(KNOB_ICACHE_MEDIUM_LINE_SIZE);
  container->insertKnob(KNOB_ICACHE_MEDIUM_BANKS);
  container->insertKnob(KNOB_ICACHE_MEDIUM_BY_PASS);
  container->insertKnob(KNOB_ICACHE_MEDIUM_CYCLES);
  container->insertKnob(KNOB_ICACHE_LARGE_NUM_SET);
  container->insertKnob(KNOB_ICACHE_LARGE_ASSOC);
  container->insertKnob(KNOB_ICACHE_LARGE_LINE_SIZE);
  container->insertKnob(KNOB_ICACHE_LARGE_BANKS);
  container->insertKnob(KNOB_ICACHE_LARGE_BY_PASS);
  container->insertKnob(KNOB_ICACHE_LARGE_CYCLES);
  container->insertKnob(KNOB_ICACHE_READ_PORTS);
  container->insertKnob(KNOB_ICACHE_WRITE_PORTS);
  container->insertKnob(KNOB_PERFECT_DCACHE);
  container->insertKnob(KNOB_L1_READ_PORTS);
  container->insertKnob(KNOB_L2_READ_PORTS);
  container->insertKnob(KNOB_L3_READ_PORTS);
  container->insertKnob(KNOB_L1_WRITE_PORTS);
  container->insertKnob(KNOB_L2_WRITE_PORTS);
  container->insertKnob(KNOB_L3_WRITE_PORTS);
  container->insertKnob(KNOB_L1_SMALL_NUM_SET);
  container->insertKnob(KNOB_L1_SMALL_ASSOC);
  container->insertKnob(KNOB_L1_SMALL_LINE_SIZE);
  container->insertKnob(KNOB_L1_SMALL_NUM_BANK);
  container->insertKnob(KNOB_L1_SMALL_LATENCY);
  container->insertKnob(KNOB_L1_SMALL_BYPASS);
  container->insertKnob(KNOB_L2_SMALL_NUM_SET);
  container->insertKnob(KNOB_L2_SMALL_ASSOC);
  container->insertKnob(KNOB_L2_SMALL_LINE_SIZE);
  container->insertKnob(KNOB_L2_SMALL_NUM_BANK);
  container->insertKnob(KNOB_L2_SMALL_LATENCY);
  container->insertKnob(KNOB_L2_SMALL_BYPASS);
  container->insertKnob(KNOB_L1_MEDIUM_NUM_SET);
  container->insertKnob(KNOB_L1_MEDIUM_ASSOC);
  container->insertKnob(KNOB_L1_MEDIUM_LINE_SIZE);
  container->insertKnob(KNOB_L1_MEDIUM_NUM_BANK);
  container->insertKnob(KNOB_L1_MEDIUM_LATENCY);
  container->insertKnob(KNOB_L1_MEDIUM_BYPASS);
  container->insertKnob(KNOB_L2_MEDIUM_NUM_SET);
  container->insertKnob(KNOB_L2_MEDIUM_ASSOC);
  container->insertKnob(KNOB_L2_MEDIUM_LINE_SIZE);
  container->insertKnob(KNOB_L2_MEDIUM_NUM_BANK);
  container->insertKnob(KNOB_L2_MEDIUM_LATENCY);
  container->insertKnob(KNOB_L2_MEDIUM_BYPASS);
  container->insertKnob(KNOB_L1_LARGE_NUM_SET);
  container->insertKnob(KNOB_L1_LARGE_ASSOC);
  container->insertKnob(KNOB_L1_LARGE_LINE_SIZE);
  container->insertKnob(KNOB_L1_LARGE_NUM_BANK);
  container->insertKnob(KNOB_L1_LARGE_LATENCY);
  container->insertKnob(KNOB_L1_LARGE_BYPASS);
  container->insertKnob(KNOB_L2_LARGE_NUM_SET);
  container->insertKnob(KNOB_L2_LARGE_ASSOC);
  container->insertKnob(KNOB_L2_LARGE_LINE_SIZE);
  container->insertKnob(KNOB_L2_LARGE_NUM_BANK);
  container->insertKnob(KNOB_L2_LARGE_LATENCY);
  container->insertKnob(KNOB_L2_LARGE_BYPASS);
  container->insertKnob(KNOB_NUM_L3);
  container->insertKnob(KNOB_L3_INTERLEAVE_FACTOR);
  container->insertKnob(KNOB_L3_NUM_SET);
  container->insertKnob(KNOB_L3_ASSOC);
  container->insertKnob(KNOB_L3_LINE_SIZE);
  container->insertKnob(KNOB_L3_NUM_BANK);
  container->insertKnob(KNOB_L3_LATENCY);
  container->insertKnob(KNOB_DCACHE_INFINITE_PORT);
  container->insertKnob(KNOB_SIMPLESSD_CONFIG);
  container->insertKnob(KNOB_DRAM_BUFFER_SIZE);
  container->insertKnob(KNOB_DRAM_BANK_XOR_INDEX);
  container->insertKnob(KNOB_DRAM_MERGE_REQUESTS);
  container->insertKnob(KNOB_DRAM_ROWBUFFER_SIZE);
  container->insertKnob(KNOB_DRAM_SCHEDULING_POLICY);
  container->insertKnob(KNOB_DRAM_NUM_CHANNEL);
  container->insertKnob(KNOB_DRAM_NUM_BANKS);
  container->insertKnob(KNOB_DRAM_ONE_CYCLE);
  container->insertKnob(KNOB_DRAM_DDR_FACTOR);
  container->insertKnob(KNOB_DRAM_BUS_WIDTH);
  container->insertKnob(KNOB_DRAM_COLUMN);
  container->insertKnob(KNOB_DRAM_PRECHARGE);
  container->insertKnob(KNOB_DRAM_ACTIVATE);
  container->insertKnob(KNOB_DRAM_NUM_MC);
  container->insertKnob(KNOB_DRAM_INTERLEAVE_FACTOR);
  container->insertKnob(KNOB_DRAM_ADDITIONAL_LATENCY);
  container->insertKnob(KNOB_MEMORY_TYPE);
  container->insertKnob(KNOB_MEM_MSHR_SIZE);
  container->insertKnob(KNOB_MEM_QUEUE_SIZE);
  container->insertKnob(KNOB_ENABLE_PREF_SMALL_CORE);
  container->insertKnob(KNOB_ENABLE_PREF_MEDIUM_CORE);
  container->insertKnob(KNOB_ENABLE_PREF_LARGE_CORE);
  container->insertKnob(KNOB_MEM_SIZE_AMP);
  container->insertKnob(KNOB_PTX_COMMON_CACHE);
  container->insertKnob(KNOB_MAX_TRANSACTION_SIZE);
  container->insertKnob(KNOB_BYTE_LEVEL_ACCESS);
  container->insertKnob(KNOB_INFINITE_PORT);
  container->insertKnob(KNOB_EXTRA_LD_LATENCY);
  container->insertKnob(KNOB_USE_CONST_AND_TEX_CACHES);
  container->insertKnob(KNOB_CONST_CACHE_SIZE);
  container->insertKnob(KNOB_CONST_CACHE_ASSOC);
  container->insertKnob(KNOB_CONST_CACHE_LINE_SIZE);
  container->insertKnob(KNOB_CONST_CACHE_BANKS);
  container->insertKnob(KNOB_CONST_CACHE_CYCLES);
  container->insertKnob(KNOB_TEXTURE_CACHE_SIZE);
  container->insertKnob(KNOB_TEXTURE_CACHE_ASSOC);
  container->insertKnob(KNOB_TEXTURE_CACHE_LINE_SIZE);
  container->insertKnob(KNOB_TEXTURE_CACHE_BANKS);
  container->insertKnob(KNOB_TEXTURE_CACHE_CYCLES);
  container->insertKnob(KNOB_SHARED_MEM_SIZE);
  container->insertKnob(KNOB_SHARED_MEM_ASSOC);
  container->insertKnob(KNOB_SHARED_MEM_LINE_SIZE);
  container->insertKnob(KNOB_SHARED_MEM_BANKS);
  container->insertKnob(KNOB_SHARED_MEM_CYCLES);
  container->insertKnob(KNOB_SHARED_MEM_PORTS);
  container->insertKnob(KNOB_ENABLE_CACHE_COHERENCE);
  container->insertKnob(KNOB_LLC_TYPE);
  container->insertKnob(KNOB_COLLECT_CACHE_INFO);
  container->insertKnob(KNOB_HETERO_STATIC_CACHE_PARTITION);
  container->insertKnob(KNOB_HETERO_STATIC_CPU_PARTITION);
  container->insertKnob(KNOB_HETERO_STATIC_GPU_PARTITION);
  container->insertKnob(KNOB_HETERO_GPU_CORE_DISABLE);
  container->insertKnob(KNOB_HETERO_NOC_USE_SAME_QUEUE);
  container->insertKnob(KNOB_HETERO_MEM_PRIORITY_CPU);
  container->insertKnob(KNOB_HETERO_MEM_PRIORITY_GPU);
  container->insertKnob(KNOB_CACHE_USE_PSEUDO_LRU);
  container->insertKnob(KNOB_LOAD_BUF_SIZE);
  container->insertKnob(KNOB_STORE_BUF_SIZE);
  container->insertKnob(KNOB_USE_INCOMING_TID_CID_FOR_WB);
  container->insertKnob(KNOB_DEFAULT_INTERLEAVING);
  container->insertKnob(KNOB_NEW_INTERLEAVING_SAME_GRANULARITY);
  container->insertKnob(KNOB_NEW_INTERLEAVING_DIFF_GRANULARITY);
  container->insertKnob(KNOB_USE_NEW_COALESCING);
  container->insertKnob(KNOB_ENABLE_PHYSICAL_MAPPING);
  container->insertKnob(KNOB_PAGE_SIZE);
  container->insertKnob(KNOB_REGION_SIZE);
  container->insertKnob(KNOB_PAGE_MAPPING_POLICY);
  container->insertKnob(KNOB_USE_MEMHIERARCHY);
  container->insertKnob(KNOB_USE_VAULTSIM_LINK);

  // =========== ../def/network.param.def ===========
  container->insertKnob(KNOB_ENABLE_IRIS);
  container->insertKnob(KNOB_IRIS_TOPOLOGY);
  container->insertKnob(KNOB_IRIS_GRIDSIZE);
  container->insertKnob(KNOB_IRIS_NUM_VC);
  container->insertKnob(KNOB_IRIS_CREDIT);
  container->insertKnob(KNOB_IRIS_INT_BUFF_WIDTH);
  container->insertKnob(KNOB_IRIS_LINK_WIDTH);
  container->insertKnob(KNOB_IRIS_RC_METHOD);
  container->insertKnob(KNOB_IRIS_SELF_ASSIGN_DEST_ID);
  container->insertKnob(KNOB_IRIS_RESP_PAYLOAD_LEN);
  container->insertKnob(KNOB_IRIS_MEMORY_LATENCY);
  container->insertKnob(KNOB_ENABLE_NEW_NOC);
  container->insertKnob(KNOB_NUM_VC);
  container->insertKnob(KNOB_NUM_PORT);
  container->insertKnob(KNOB_LINK_LATENCY);
  container->insertKnob(KNOB_LINK_WIDTH);
  container->insertKnob(KNOB_NOC_DIMENSION);
  container->insertKnob(KNOB_NOC_TOPOLOGY);
  container->insertKnob(KNOB_ENABLE_HETEROGENEOUS_LINK);
  container->insertKnob(KNOB_NUM_SWITCH);
  container->insertKnob(KNOB_NUM_SWITCH_CPU);
  container->insertKnob(KNOB_NUM_SWITCH_GPU);
  container->insertKnob(KNOB_NUM_SWITCH_MEM);
  container->insertKnob(KNOB_ENABLE_HETEROGENEOUS_LINK_WIDTH);
  container->insertKnob(KNOB_NUM_SWITCH_ITER);
  container->insertKnob(KNOB_NUM_SWITCH_ITER_CPU);
  container->insertKnob(KNOB_NUM_SWITCH_ITER_GPU);
  container->insertKnob(KNOB_NUM_SWITCH_ITER_MEM);
  container->insertKnob(KNOB_ENABLE_NOC_VC_PARTITION);
  container->insertKnob(KNOB_CPU_VC_PARTITION);
  container->insertKnob(KNOB_GPU_VC_PARTITION);
  container->insertKnob(KNOB_ENABLE_CHANNEL_PARTITION);
  container->insertKnob(KNOB_NUM_CHANNEL_CPU);
  container->insertKnob(KNOB_NUM_CHANNEL_GPU);
  container->insertKnob(KNOB_ENABLE_ADAPTIVE_RING_ROUTING);
  container->insertKnob(KNOB_ARR_THRESHOLD);
  container->insertKnob(KNOB_ARR_DELTA);
  container->insertKnob(KNOB_ARR_ADV);
  container->insertKnob(KNOB_ARR_100);
  container->insertKnob(KNOB_ARBITRATION_POLICY);
  container->insertKnob(KNOB_ROUTER_PLACEMENT);
  container->insertKnob(KNOB_CORE_ENABLE_BEGIN);
  container->insertKnob(KNOB_CORE_ENABLE_END);
  container->insertKnob(KNOB_IDEAL_NOC);
  container->insertKnob(KNOB_IDEAL_NOC_LATENCY);
  container->insertKnob(KNOB_USE_ZERO_LATENCY_NOC);

  // =========== ../def/pref.param.def ===========
  container->insertKnob(KNOB_PREF_FRAMEWORK_ON);
  container->insertKnob(KNOB_PREF_TRACE_ON);
  container->insertKnob(KNOB_DEBUG_PREF);
  container->insertKnob(KNOB_PREF_DL0REQ_QUEUE_SIZE);
  container->insertKnob(KNOB_PREF_UL1REQ_QUEUE_SIZE);
  container->insertKnob(KNOB_PREF_DL0_MISS_ON);
  container->insertKnob(KNOB_PREF_DL0_HIT_ON);
  container->insertKnob(KNOB_PREF_DL0REQ_QUEUE_FILTER_ON);
  container->insertKnob(KNOB_PREF_UL1REQ_QUEUE_FILTER_ON);
  container->insertKnob(KNOB_PREF_DL0REQ_ADD_FILTER_ON);
  container->insertKnob(KNOB_PREF_UL1REQ_ADD_FILTER_ON);
  container->insertKnob(KNOB_PREF_DL0REQ_QUEUE_OVERWRITE_ON_FULL);
  container->insertKnob(KNOB_PREF_UL1REQ_QUEUE_OVERWRITE_ON_FULL);
  container->insertKnob(KNOB_PREF_DL0SCHEDULE_NUM);
  container->insertKnob(KNOB_PREF_UL1SCHEDULE_NUM);
  container->insertKnob(KNOB_PREF_REGION_ON);
  container->insertKnob(KNOB_PREF_USEREGION_TOCALC_ACC);
  container->insertKnob(KNOB_PREF_NUMTRACKING_REGIONS);
  container->insertKnob(KNOB_PREF_REGION_SIZE);
  container->insertKnob(KNOB_PREF_HYBRID_ON);
  container->insertKnob(KNOB_PREF_HYBRID_DEFAULT);
  container->insertKnob(KNOB_PREF_HYBRID_DEFAULT_TIMEPERIOD);
  container->insertKnob(KNOB_PREF_HYBRID_UPDATE_MULTIPLE);
  container->insertKnob(KNOB_PREF_HYBRID_MIN_SENT);
  container->insertKnob(KNOB_PREF_HYBRID_MIN_MEMUSED);
  container->insertKnob(KNOB_PREF_HYBRID_SORT_ON_ACC);
  container->insertKnob(KNOB_PREF_HYBRID_SORT_ON_COV);
  container->insertKnob(KNOB_PREF_ACC_THRESH_1);
  container->insertKnob(KNOB_PREF_ACC_THRESH_2);
  container->insertKnob(KNOB_PREF_ACC_THRESH_3);
  container->insertKnob(KNOB_PREF_UPDATE_INTERVAL);
  container->insertKnob(KNOB_PREF_ACC_STUDY);
  container->insertKnob(KNOB_PREF_ACC_UPDATE_INTERVAL);
  container->insertKnob(KNOB_PREF_ANALYZE_LOAD);
  container->insertKnob(KNOB_PREF_POL_THRESH_1);
  container->insertKnob(KNOB_PREF_POL_THRESH_2);
  container->insertKnob(KNOB_PREF_POLBV_ON);
  container->insertKnob(KNOB_PREF_POLBV_SIZE);
  container->insertKnob(KNOB_LOG2_PREF_POLBV_SIZE);
  container->insertKnob(KNOB_PREF_TIMELY_THRESH);
  container->insertKnob(KNOB_PREF_POLPF_THRESH);
  container->insertKnob(KNOB_PREF_DEGFB_USEONLYACC);
  container->insertKnob(KNOB_PREF_DEGFB_USEONLYPOL);
  container->insertKnob(KNOB_PREF_DEGFB_USEONLYLATE);
  container->insertKnob(KNOB_PREF_TIMELY_THRESH_2);
  container->insertKnob(KNOB_PREF_DEGFB_STATPHASEFILE);
  container->insertKnob(KNOB_PREF_DHAL);
  container->insertKnob(KNOB_PREF_DHAL_SENTTHRESH);
  container->insertKnob(KNOB_PREF_DHAL_USETHRESH_MAX);
  container->insertKnob(KNOB_PREF_DHAL_USETHRESH_MIN2);
  container->insertKnob(KNOB_PREF_DHAL_USETHRESH_MIN1);
  container->insertKnob(KNOB_PREF_DHAL_MAXDEG);
  container->insertKnob(KNOB_PREF_THREAD_INDEX);
  container->insertKnob(KNOB_PREF_TRAIN_INST_ONCE);
  container->insertKnob(KNOB_DEBUG_PREF_STRIDE);
  container->insertKnob(KNOB_PREF_STRIDE_TABLE_N);
  container->insertKnob(KNOB_PREF_STRIDE_REGION_BITS);
  container->insertKnob(KNOB_PREF_STRIDE_DEGREE);
  container->insertKnob(KNOB_PREF_STRIDE_DISTANCE);
  container->insertKnob(KNOB_PREF_STRIDE_STARTDISTANCE);
  container->insertKnob(KNOB_PREF_STRIDE_SINGLE_THRESH);
  container->insertKnob(KNOB_PREF_STRIDE_MULTI_THRESH);
  container->insertKnob(KNOB_PREF_STRIDE_SINGLE_STRIDE_MODE);
  container->insertKnob(KNOB_PREF_STRIDE_ON);
  container->insertKnob(KNOB_PREF_STRIDE_ON_MEDIUM_CORE);
  container->insertKnob(KNOB_PREF_STRIDE_ON_LARGE_CORE);

  // =========== ../def/ramulator.param.def ===========
  container->insertKnob(KNOB_RAMULATOR_CONFIG_FILE);
  container->insertKnob(KNOB_RAMULATOR_CACHELINE_SIZE);

  // =========== ../def/schedule.param.def ===========
  container->insertKnob(KNOB_ISCHED_SIZE);
  container->insertKnob(KNOB_MSCHED_SIZE);
  container->insertKnob(KNOB_FSCHED_SIZE);
  container->insertKnob(KNOB_ISCHED_MEDIUM_SIZE);
  container->insertKnob(KNOB_MSCHED_MEDIUM_SIZE);
  container->insertKnob(KNOB_FSCHED_MEDIUM_SIZE);
  container->insertKnob(KNOB_ISCHED_LARGE_SIZE);
  container->insertKnob(KNOB_MSCHED_LARGE_SIZE);
  container->insertKnob(KNOB_FSCHED_LARGE_SIZE);
  container->insertKnob(KNOB_ISCHED_RATE);
  container->insertKnob(KNOB_MSCHED_RATE);
  container->insertKnob(KNOB_FSCHED_RATE);
  container->insertKnob(KNOB_ISCHED_MEDIUM_RATE);
  container->insertKnob(KNOB_MSCHED_MEDIUM_RATE);
  container->insertKnob(KNOB_FSCHED_MEDIUM_RATE);
  container->insertKnob(KNOB_ISCHED_LARGE_RATE);
  container->insertKnob(KNOB_MSCHED_LARGE_RATE);
  container->insertKnob(KNOB_FSCHED_LARGE_RATE);
  container->insertKnob(KNOB_SCHED_TO_WIDTH);
  container->insertKnob(KNOB_SCHED_TO_MEDIUM_WIDTH);
  container->insertKnob(KNOB_SCHED_TO_LARGE_WIDTH);
  container->insertKnob(KNOB_TRACE_NAME_FILE);
  container->insertKnob(KNOB_NUM_WARP_SCHEDULER);

  // =========== ../def/utils.param.def ===========
  container->insertKnob(KNOB_BUG_DETECTOR_ENABLE);
  container->insertKnob(KNOB_COLLECT_CPI_INFO);
  container->insertKnob(KNOB_COLLECT_CPI_INFO_FOR_MULTI_GPU);
}
