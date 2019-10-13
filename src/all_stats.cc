#include "all_stats.h"
#include "statsEnums.h"

all_stats_c::all_stats_c(ProcessorStatistics *procStat) {
  // ============= ../def/alloc.stat.def =============
  m_ALLOC_COUNT = new COUNT_Stat("ALLOC_COUNT", "alloc.stat.out", ALLOC_COUNT);

  // ============= ../def/bp.stat.def =============
  m_DIST_BP_ON_PATH_CORRECT = new DIST_Stat("BP_ON_PATH_CORRECT", "bp.stat.out",
                                            BP_ON_PATH_CORRECT, procStat);
  m_BP_ON_PATH_CORRECT =
      (COUNT_Stat *)new DISTMember_Stat("BP_ON_PATH_CORRECT", "bp.stat.out",
                                        BP_ON_PATH_CORRECT, BP_ON_PATH_CORRECT);
  m_BP_ON_PATH_MISPREDICT = (COUNT_Stat *)new DISTMember_Stat(
      "BP_ON_PATH_MISPREDICT", "bp.stat.out", BP_ON_PATH_MISPREDICT,
      BP_ON_PATH_CORRECT);
  m_BP_ON_PATH_MISFETCH = (COUNT_Stat *)new DISTMember_Stat(
      "BP_ON_PATH_MISFETCH", "bp.stat.out", BP_ON_PATH_MISFETCH,
      BP_ON_PATH_CORRECT);
  m_DIST_BP_OFF_PATH_CORRECT = new DIST_Stat(
      "BP_OFF_PATH_CORRECT", "bp.stat.out", BP_OFF_PATH_CORRECT, procStat);
  m_BP_OFF_PATH_CORRECT = (COUNT_Stat *)new DISTMember_Stat(
      "BP_OFF_PATH_CORRECT", "bp.stat.out", BP_OFF_PATH_CORRECT,
      BP_OFF_PATH_CORRECT);
  m_BP_OFF_PATH_MISPREDICT = (COUNT_Stat *)new DISTMember_Stat(
      "BP_OFF_PATH_MISPREDICT", "bp.stat.out", BP_OFF_PATH_MISPREDICT,
      BP_OFF_PATH_CORRECT);
  m_BP_OFF_PATH_MISFETCH = (COUNT_Stat *)new DISTMember_Stat(
      "BP_OFF_PATH_MISFETCH", "bp.stat.out", BP_OFF_PATH_MISFETCH,
      BP_OFF_PATH_CORRECT);
  m_BP_MISPRED_STALL =
      new COUNT_Stat("BP_MISPRED_STALL", "bp.stat.out", BP_MISPRED_STALL);
  m_BP_RESOLVED = new COUNT_Stat("BP_RESOLVED", "bp.stat.out", BP_RESOLVED);
  m_BP_REDIRECT_RESOLVED = new COUNT_Stat("BP_REDIRECT_RESOLVED", "bp.stat.out",
                                          BP_REDIRECT_RESOLVED);
  m_PERFECT_TARGET_PRED =
      new COUNT_Stat("PERFECT_TARGET_PRED", "bp.stat.out", PERFECT_TARGET_PRED);

  // ============= ../def/core.stat.def =============
  m_DIST_SCHED_FAILED_REASON_SUCCESS =
      new DIST_Stat("SCHED_FAILED_REASON_SUCCESS", "core.stat.out",
                    SCHED_FAILED_REASON_SUCCESS, procStat);
  m_SCHED_FAILED_REASON_SUCCESS = (COUNT_Stat *)new DISTMember_Stat(
      "SCHED_FAILED_REASON_SUCCESS", "core.stat.out",
      SCHED_FAILED_REASON_SUCCESS, SCHED_FAILED_REASON_SUCCESS);
  m_SCHED_FAILED_OPERANDS_NOT_READY = (COUNT_Stat *)new DISTMember_Stat(
      "SCHED_FAILED_OPERANDS_NOT_READY", "core.stat.out",
      SCHED_FAILED_OPERANDS_NOT_READY, SCHED_FAILED_REASON_SUCCESS);
  m_SCHED_FAILED_NO_PORTS = (COUNT_Stat *)new DISTMember_Stat(
      "SCHED_FAILED_NO_PORTS", "core.stat.out", SCHED_FAILED_NO_PORTS,
      SCHED_FAILED_REASON_SUCCESS);
  m_SCHED_FAILED_FENCE_ACTIVE = (COUNT_Stat *)new DISTMember_Stat(
      "SCHED_FAILED_FENCE_ACTIVE", "core.stat.out", SCHED_FAILED_FENCE_ACTIVE,
      SCHED_FAILED_REASON_SUCCESS);
  m_NUM_SAMPLES = new COUNT_Stat("NUM_SAMPLES", "core.stat.out", NUM_SAMPLES);
  m_NUM_ACTIVE_BLOCKS =
      new RATIO_Stat("NUM_ACTIVE_BLOCKS", "core.stat.out", NUM_ACTIVE_BLOCKS,
                     NUM_SAMPLES, procStat);
  m_NUM_ACTIVE_THREADS =
      new RATIO_Stat("NUM_ACTIVE_THREADS", "core.stat.out", NUM_ACTIVE_THREADS,
                     NUM_SAMPLES, procStat);
  m_NUM_SCHED_IDLE_CYCLE = new COUNT_Stat(
      "NUM_SCHED_IDLE_CYCLE", "core.stat.out", NUM_SCHED_IDLE_CYCLE);
  m_NUM_NO_SCHED_CYCLE =
      new COUNT_Stat("NUM_NO_SCHED_CYCLE", "core.stat.out", NUM_NO_SCHED_CYCLE);
  m_DISPATCHED_INST =
      new COUNT_Stat("DISPATCHED_INST", "core.stat.out", DISPATCHED_INST);
  m_DISPATCH_WAIT = new RATIO_Stat("DISPATCH_WAIT", "core.stat.out",
                                   DISPATCH_WAIT, DISPATCHED_INST, procStat);
  m_CORE_DISPATCHED_INST = new COUNT_Stat(
      "CORE_DISPATCHED_INST", "core.stat.out", CORE_DISPATCHED_INST);
  m_CORE_DISPATCH_WAIT =
      new RATIO_Stat("CORE_DISPATCH_WAIT", "core.stat.out", CORE_DISPATCH_WAIT,
                     CORE_DISPATCHED_INST, procStat);
  m_CORE_CYCLES = new COUNT_Stat("CORE_CYCLES", "core.stat.out", CORE_CYCLES);
  m_CORE_SCHED_THREADS =
      new RATIO_Stat("CORE_SCHED_THREADS", "core.stat.out", CORE_SCHED_THREADS,
                     CORE_CYCLES, procStat);
  m_NUM_NO_FETCH_CYCLES = new COUNT_Stat("NUM_NO_FETCH_CYCLES", "core.stat.out",
                                         NUM_NO_FETCH_CYCLES);
  m_CORE_NUM_NO_FETCH_CYCLES = new COUNT_Stat(
      "CORE_NUM_NO_FETCH_CYCLES", "core.stat.out", CORE_NUM_NO_FETCH_CYCLES);
  m_CORE_NUM_NO_FETCH_CYCLES_WITH_READY_THREADS = new COUNT_Stat(
      "CORE_NUM_NO_FETCH_CYCLES_WITH_READY_THREADS", "core.stat.out",
      CORE_NUM_NO_FETCH_CYCLES_WITH_READY_THREADS);
  m_CORE_NUM_FETCH_CYCLES = new COUNT_Stat(
      "CORE_NUM_FETCH_CYCLES", "core.stat.out", CORE_NUM_FETCH_CYCLES);
  m_CORE_FETCH_DELTA =
      new RATIO_Stat("CORE_FETCH_DELTA", "core.stat.out", CORE_FETCH_DELTA,
                     CORE_NUM_FETCH_CYCLES, procStat);
  m_CORE_NUM_RETIRE_CYCLES = new COUNT_Stat(
      "CORE_NUM_RETIRE_CYCLES", "core.stat.out", CORE_NUM_RETIRE_CYCLES);
  m_CORE_RETIRE_DELTA =
      new RATIO_Stat("CORE_RETIRE_DELTA", "core.stat.out", CORE_RETIRE_DELTA,
                     CORE_NUM_RETIRE_CYCLES, procStat);
  m_AVG_CORE_IDLE_CYCLE = new COUNT_Stat("AVG_CORE_IDLE_CYCLE", "core.stat.out",
                                         AVG_CORE_IDLE_CYCLE);
  m_FENCE_PREF_REQ =
      new COUNT_Stat("FENCE_PREF_REQ", "core.stat.out", FENCE_PREF_REQ);
  m_FENCE_WAITING =
      new COUNT_Stat("FENCE_WAITING", "core.stat.out", FENCE_WAITING);
  m_DYN_FENCE_NUM =
      new COUNT_Stat("DYN_FENCE_NUM", "core.stat.out", DYN_FENCE_NUM);
  m_WB_ORDERING_STALL =
      new COUNT_Stat("WB_ORDERING_STALL", "core.stat.out", WB_ORDERING_STALL);
  m_WB_FULL = new COUNT_Stat("WB_FULL", "core.stat.out", WB_FULL);
  m_REEXEC_NUM = new COUNT_Stat("REEXEC_NUM", "core.stat.out", REEXEC_NUM);
  m_INV_MATCH_NUM =
      new COUNT_Stat("INV_MATCH_NUM", "core.stat.out", INV_MATCH_NUM);
  m_EARLY_PERM_NUM =
      new COUNT_Stat("EARLY_PERM_NUM", "core.stat.out", EARLY_PERM_NUM);
  m_PERM_MATCH_NUM =
      new COUNT_Stat("PERM_MATCH_NUM", "core.stat.out", PERM_MATCH_NUM);
  m_RETIRE_SPECLD_NUM =
      new COUNT_Stat("RETIRE_SPECLD_NUM", "core.stat.out", RETIRE_SPECLD_NUM);
  m_RETIRE_SPECST_NUM =
      new COUNT_Stat("RETIRE_SPECST_NUM", "core.stat.out", RETIRE_SPECST_NUM);
  m_FENCE_HEAD_ROB_WAIT = new COUNT_Stat("FENCE_HEAD_ROB_WAIT", "core.stat.out",
                                         FENCE_HEAD_ROB_WAIT);
  m_FENCE_TOT_CYCLES =
      new COUNT_Stat("FENCE_TOT_CYCLES", "core.stat.out", FENCE_TOT_CYCLES);
  m_FENCE_EXEC_CYCLES =
      new COUNT_Stat("FENCE_EXEC_CYCLES", "core.stat.out", FENCE_EXEC_CYCLES);
  m_STORE_RES = new COUNT_Stat("STORE_RES", "core.stat.out", STORE_RES);
  m_STORE_NUM = new COUNT_Stat("STORE_NUM", "core.stat.out", STORE_NUM);
  m_STORE_WB_FREE =
      new COUNT_Stat("STORE_WB_FREE", "core.stat.out", STORE_WB_FREE);

  // ============= ../def/core_trace.stat.def =============

  // ============= ../def/dram.stat.def =============
  m_DRAM_PRECHARGE =
      new COUNT_Stat("DRAM_PRECHARGE", "dram.stat.out", DRAM_PRECHARGE);
  m_DRAM_ACTIVATE =
      new COUNT_Stat("DRAM_ACTIVATE", "dram.stat.out", DRAM_ACTIVATE);
  m_DRAM_COLUMN = new COUNT_Stat("DRAM_COLUMN", "dram.stat.out", DRAM_COLUMN);
  m_DRAM_AVG_LATENCY_BASE = new COUNT_Stat(
      "DRAM_AVG_LATENCY_BASE", "dram.stat.out", DRAM_AVG_LATENCY_BASE);
  m_DRAM_AVG_LATENCY =
      new RATIO_Stat("DRAM_AVG_LATENCY", "dram.stat.out", DRAM_AVG_LATENCY,
                     DRAM_AVG_LATENCY_BASE, procStat);
  m_BANDWIDTH_TOT =
      new COUNT_Stat("BANDWIDTH_TOT", "dram.stat.out", BANDWIDTH_TOT);
  m_DRAM_CHANNEL0_BANDWIDTH_SATURATED =
      new COUNT_Stat("DRAM_CHANNEL0_BANDWIDTH_SATURATED", "dram.stat.out",
                     DRAM_CHANNEL0_BANDWIDTH_SATURATED);
  m_DRAM_CHANNEL1_BANDWIDTH_SATURATED =
      new COUNT_Stat("DRAM_CHANNEL1_BANDWIDTH_SATURATED", "dram.stat.out",
                     DRAM_CHANNEL1_BANDWIDTH_SATURATED);
  m_DRAM_CHANNEL2_BANDWIDTH_SATURATED =
      new COUNT_Stat("DRAM_CHANNEL2_BANDWIDTH_SATURATED", "dram.stat.out",
                     DRAM_CHANNEL2_BANDWIDTH_SATURATED);
  m_DRAM_CHANNEL3_BANDWIDTH_SATURATED =
      new COUNT_Stat("DRAM_CHANNEL3_BANDWIDTH_SATURATED", "dram.stat.out",
                     DRAM_CHANNEL3_BANDWIDTH_SATURATED);
  m_DRAM_CHANNEL4_BANDWIDTH_SATURATED =
      new COUNT_Stat("DRAM_CHANNEL4_BANDWIDTH_SATURATED", "dram.stat.out",
                     DRAM_CHANNEL4_BANDWIDTH_SATURATED);
  m_DRAM_CHANNEL5_BANDWIDTH_SATURATED =
      new COUNT_Stat("DRAM_CHANNEL5_BANDWIDTH_SATURATED", "dram.stat.out",
                     DRAM_CHANNEL5_BANDWIDTH_SATURATED);
  m_DRAM_CHANNEL6_BANDWIDTH_SATURATED =
      new COUNT_Stat("DRAM_CHANNEL6_BANDWIDTH_SATURATED", "dram.stat.out",
                     DRAM_CHANNEL6_BANDWIDTH_SATURATED);
  m_DRAM_CHANNEL7_BANDWIDTH_SATURATED =
      new COUNT_Stat("DRAM_CHANNEL7_BANDWIDTH_SATURATED", "dram.stat.out",
                     DRAM_CHANNEL7_BANDWIDTH_SATURATED);
  m_DRAM_CHANNEL0_DBUS_IDLE = new COUNT_Stat(
      "DRAM_CHANNEL0_DBUS_IDLE", "dram.stat.out", DRAM_CHANNEL0_DBUS_IDLE);
  m_DRAM_CHANNEL1_DBUS_IDLE = new COUNT_Stat(
      "DRAM_CHANNEL1_DBUS_IDLE", "dram.stat.out", DRAM_CHANNEL1_DBUS_IDLE);
  m_DRAM_CHANNEL2_DBUS_IDLE = new COUNT_Stat(
      "DRAM_CHANNEL2_DBUS_IDLE", "dram.stat.out", DRAM_CHANNEL2_DBUS_IDLE);
  m_DRAM_CHANNEL3_DBUS_IDLE = new COUNT_Stat(
      "DRAM_CHANNEL3_DBUS_IDLE", "dram.stat.out", DRAM_CHANNEL3_DBUS_IDLE);
  m_DRAM_CHANNEL4_DBUS_IDLE = new COUNT_Stat(
      "DRAM_CHANNEL4_DBUS_IDLE", "dram.stat.out", DRAM_CHANNEL4_DBUS_IDLE);
  m_DRAM_CHANNEL5_DBUS_IDLE = new COUNT_Stat(
      "DRAM_CHANNEL5_DBUS_IDLE", "dram.stat.out", DRAM_CHANNEL5_DBUS_IDLE);
  m_DRAM_CHANNEL6_DBUS_IDLE = new COUNT_Stat(
      "DRAM_CHANNEL6_DBUS_IDLE", "dram.stat.out", DRAM_CHANNEL6_DBUS_IDLE);
  m_DRAM_CHANNEL7_DBUS_IDLE = new COUNT_Stat(
      "DRAM_CHANNEL7_DBUS_IDLE", "dram.stat.out", DRAM_CHANNEL7_DBUS_IDLE);

  // ============= ../def/dyfr.stat.def =============

  // ============= ../def/general.stat.def =============
  m_INST_COUNT_TOT =
      new COUNT_Stat("INST_COUNT_TOT", "general.stat.out", INST_COUNT_TOT);
  m_INST_COUNT = new COUNT_Stat("INST_COUNT", "general.stat.out", INST_COUNT);
  m_UOP_COUNT_TOT =
      new COUNT_Stat("UOP_COUNT_TOT", "general.stat.out", UOP_COUNT_TOT);
  m_UOP_COUNT = new COUNT_Stat("UOP_COUNT", "general.stat.out", UOP_COUNT);
  m_CYC_COUNT_TOT =
      new COUNT_Stat("CYC_COUNT_TOT", "general.stat.out", CYC_COUNT_TOT);
  m_CYC_COUNT = new COUNT_Stat("CYC_COUNT", "general.stat.out", CYC_COUNT);
  m_EXE_TIME = new COUNT_Stat("EXE_TIME", "general.stat.out", EXE_TIME);
  m_NUM_REPEAT = new COUNT_Stat("NUM_REPEAT", "general.stat.out", NUM_REPEAT);
  m_DIST_FF_CYC_COUNT =
      new DIST_Stat("FF_CYC_COUNT", "general.stat.out", FF_CYC_COUNT, procStat);
  m_FF_CYC_COUNT = (COUNT_Stat *)new DISTMember_Stat(
      "FF_CYC_COUNT", "general.stat.out", FF_CYC_COUNT, FF_CYC_COUNT);
  m_NON_FF_CYC_COUNT = (COUNT_Stat *)new DISTMember_Stat(
      "NON_FF_CYC_COUNT", "general.stat.out", NON_FF_CYC_COUNT, FF_CYC_COUNT);
  m_CYC_COUNT_X86 =
      new COUNT_Stat("CYC_COUNT_X86", "general.stat.out", CYC_COUNT_X86);
  m_CYC_COUNT_PTX =
      new COUNT_Stat("CYC_COUNT_PTX", "general.stat.out", CYC_COUNT_PTX);
  m_AVG_BLOCK_EXE_CYCLE = new COUNT_Stat(
      "AVG_BLOCK_EXE_CYCLE", "general.stat.out", AVG_BLOCK_EXE_CYCLE);
  m_AVG_BLOCK_EXE_CYCLE_BASE = new COUNT_Stat(
      "AVG_BLOCK_EXE_CYCLE_BASE", "general.stat.out", AVG_BLOCK_EXE_CYCLE_BASE);
  m_PROGRESS_ERROR =
      new COUNT_Stat("PROGRESS_ERROR", "general.stat.out", PROGRESS_ERROR);
  m_FILE_OPEN_ERROR =
      new COUNT_Stat("FILE_OPEN_ERROR", "general.stat.out", FILE_OPEN_ERROR);
  m_NUM_THREAD = new COUNT_Stat("NUM_THREAD", "general.stat.out", NUM_THREAD);
  m_APPL_CYC_COUNT_BASE0 = new COUNT_Stat(
      "APPL_CYC_COUNT_BASE0", "general.stat.out", APPL_CYC_COUNT_BASE0);
  m_APPL_CYC_COUNT_BASE1 = new COUNT_Stat(
      "APPL_CYC_COUNT_BASE1", "general.stat.out", APPL_CYC_COUNT_BASE1);
  m_APPL_CYC_COUNT_BASE2 = new COUNT_Stat(
      "APPL_CYC_COUNT_BASE2", "general.stat.out", APPL_CYC_COUNT_BASE2);
  m_APPL_CYC_COUNT_BASE3 = new COUNT_Stat(
      "APPL_CYC_COUNT_BASE3", "general.stat.out", APPL_CYC_COUNT_BASE3);
  m_APPL_CYC_COUNT_BASE4 = new COUNT_Stat(
      "APPL_CYC_COUNT_BASE4", "general.stat.out", APPL_CYC_COUNT_BASE4);
  m_APPL_CYC_COUNT0 =
      new RATIO_Stat("APPL_CYC_COUNT0", "general.stat.out", APPL_CYC_COUNT0,
                     APPL_CYC_COUNT_BASE0, procStat);
  m_APPL_CYC_COUNT1 =
      new RATIO_Stat("APPL_CYC_COUNT1", "general.stat.out", APPL_CYC_COUNT1,
                     APPL_CYC_COUNT_BASE1, procStat);
  m_APPL_CYC_COUNT2 =
      new RATIO_Stat("APPL_CYC_COUNT2", "general.stat.out", APPL_CYC_COUNT2,
                     APPL_CYC_COUNT_BASE2, procStat);
  m_APPL_CYC_COUNT3 =
      new RATIO_Stat("APPL_CYC_COUNT3", "general.stat.out", APPL_CYC_COUNT3,
                     APPL_CYC_COUNT_BASE3, procStat);
  m_APPL_CYC_COUNT4 =
      new RATIO_Stat("APPL_CYC_COUNT4", "general.stat.out", APPL_CYC_COUNT4,
                     APPL_CYC_COUNT_BASE4, procStat);
  m_CPI_DELTA_BASE0 =
      new COUNT_Stat("CPI_DELTA_BASE0", "general.stat.out", CPI_DELTA_BASE0);
  m_CPI_DELTA_BASE1 =
      new COUNT_Stat("CPI_DELTA_BASE1", "general.stat.out", CPI_DELTA_BASE1);
  m_CPI_DELTA_BASE2 =
      new COUNT_Stat("CPI_DELTA_BASE2", "general.stat.out", CPI_DELTA_BASE2);
  m_CPI_DELTA_BASE3 =
      new COUNT_Stat("CPI_DELTA_BASE3", "general.stat.out", CPI_DELTA_BASE3);
  m_CPI_DELTA_BASE4 =
      new COUNT_Stat("CPI_DELTA_BASE4", "general.stat.out", CPI_DELTA_BASE4);
  m_CPI_DELTA0 = new RATIO_Stat("CPI_DELTA0", "general.stat.out", CPI_DELTA0,
                                CPI_DELTA_BASE0, procStat);
  m_CPI_DELTA1 = new RATIO_Stat("CPI_DELTA1", "general.stat.out", CPI_DELTA1,
                                CPI_DELTA_BASE1, procStat);
  m_CPI_DELTA2 = new RATIO_Stat("CPI_DELTA2", "general.stat.out", CPI_DELTA2,
                                CPI_DELTA_BASE2, procStat);
  m_CPI_DELTA3 = new RATIO_Stat("CPI_DELTA3", "general.stat.out", CPI_DELTA3,
                                CPI_DELTA_BASE3, procStat);
  m_CPI_DELTA4 = new RATIO_Stat("CPI_DELTA4", "general.stat.out", CPI_DELTA4,
                                CPI_DELTA_BASE4, procStat);
  m_CYCLE_CPU = new COUNT_Stat("CYCLE_CPU", "general.stat.out", CYCLE_CPU);
  m_CYCLE_GPU = new COUNT_Stat("CYCLE_GPU", "general.stat.out", CYCLE_GPU);

  // ============= ../def/hmc.stat.def =============
  m_HMC_INST_COUNT_TOT =
      new COUNT_Stat("HMC_INST_COUNT_TOT", "hmc.stat.out", HMC_INST_COUNT_TOT);
  m_HMC_INST_COUNT =
      new COUNT_Stat("HMC_INST_COUNT", "hmc.stat.out", HMC_INST_COUNT);
  m_HMC_UOP_COUNT =
      new COUNT_Stat("HMC_UOP_COUNT", "hmc.stat.out", HMC_UOP_COUNT);
  m_HMC_REMOVE_INST_COUNT = new COUNT_Stat(
      "HMC_REMOVE_INST_COUNT", "hmc.stat.out", HMC_REMOVE_INST_COUNT);
  m_HMC_REMOVE_INST_COUNT_TOT = new COUNT_Stat(
      "HMC_REMOVE_INST_COUNT_TOT", "hmc.stat.out", HMC_REMOVE_INST_COUNT_TOT);
  m_HMC_FENCE_INST_COUNT = new COUNT_Stat("HMC_FENCE_INST_COUNT",
                                          "hmc.stat.out", HMC_FENCE_INST_COUNT);
  m_HMC_FENCE_INST_COUNT_TOT = new COUNT_Stat(
      "HMC_FENCE_INST_COUNT_TOT", "hmc.stat.out", HMC_FENCE_INST_COUNT_TOT);
  m_HMC_ADD_OVERHEAD_COUNT = new COUNT_Stat(
      "HMC_ADD_OVERHEAD_COUNT", "hmc.stat.out", HMC_ADD_OVERHEAD_COUNT);
  m_HMC_DEP_UOP_CYC_TOT = new COUNT_Stat("HMC_DEP_UOP_CYC_TOT", "hmc.stat.out",
                                         HMC_DEP_UOP_CYC_TOT);
  m_HMC_DEP_UOP_RETIRE_COUNT = new COUNT_Stat(
      "HMC_DEP_UOP_RETIRE_COUNT", "hmc.stat.out", HMC_DEP_UOP_RETIRE_COUNT);
  m_HMC_INST_COUNT_CAS_equal_16B =
      new COUNT_Stat("HMC_INST_COUNT_CAS_equal_16B", "hmc.stat.out",
                     HMC_INST_COUNT_CAS_equal_16B);
  m_HMC_INST_COUNT_CAS_zero_16B =
      new COUNT_Stat("HMC_INST_COUNT_CAS_zero_16B", "hmc.stat.out",
                     HMC_INST_COUNT_CAS_zero_16B);
  m_HMC_INST_COUNT_CAS_greater_16B =
      new COUNT_Stat("HMC_INST_COUNT_CAS_greater_16B", "hmc.stat.out",
                     HMC_INST_COUNT_CAS_greater_16B);
  m_HMC_INST_COUNT_CAS_less_16B =
      new COUNT_Stat("HMC_INST_COUNT_CAS_less_16B", "hmc.stat.out",
                     HMC_INST_COUNT_CAS_less_16B);
  m_HMC_INST_COUNT_ADD_16B = new COUNT_Stat(
      "HMC_INST_COUNT_ADD_16B", "hmc.stat.out", HMC_INST_COUNT_ADD_16B);
  m_HMC_INST_COUNT_ADD_8B = new COUNT_Stat(
      "HMC_INST_COUNT_ADD_8B", "hmc.stat.out", HMC_INST_COUNT_ADD_8B);
  m_HMC_INST_COUNT_ADD_DUAL = new COUNT_Stat(
      "HMC_INST_COUNT_ADD_DUAL", "hmc.stat.out", HMC_INST_COUNT_ADD_DUAL);
  m_HMC_INST_COUNT_SWAP = new COUNT_Stat("HMC_INST_COUNT_SWAP", "hmc.stat.out",
                                         HMC_INST_COUNT_SWAP);
  m_HMC_INST_COUNT_BIT_WR = new COUNT_Stat(
      "HMC_INST_COUNT_BIT_WR", "hmc.stat.out", HMC_INST_COUNT_BIT_WR);
  m_HMC_INST_COUNT_AND =
      new COUNT_Stat("HMC_INST_COUNT_AND", "hmc.stat.out", HMC_INST_COUNT_AND);
  m_HMC_INST_COUNT_NAND = new COUNT_Stat("HMC_INST_COUNT_NAND", "hmc.stat.out",
                                         HMC_INST_COUNT_NAND);
  m_HMC_INST_COUNT_OR =
      new COUNT_Stat("HMC_INST_COUNT_OR", "hmc.stat.out", HMC_INST_COUNT_OR);
  m_HMC_INST_COUNT_XOR =
      new COUNT_Stat("HMC_INST_COUNT_XOR", "hmc.stat.out", HMC_INST_COUNT_XOR);
  m_HMC_INST_COUNT_FP_ADD = new COUNT_Stat(
      "HMC_INST_COUNT_FP_ADD", "hmc.stat.out", HMC_INST_COUNT_FP_ADD);
  m_HMC_INST_COUNT_COMP_greater =
      new COUNT_Stat("HMC_INST_COUNT_COMP_greater", "hmc.stat.out",
                     HMC_INST_COUNT_COMP_greater);
  m_HMC_INST_COUNT_COMP_less = new COUNT_Stat(
      "HMC_INST_COUNT_COMP_less", "hmc.stat.out", HMC_INST_COUNT_COMP_less);
  m_HMC_INST_COUNT_COMP_equal = new COUNT_Stat(
      "HMC_INST_COUNT_COMP_equal", "hmc.stat.out", HMC_INST_COUNT_COMP_equal);
  m_HMC_INST_COUNT_CANDIDATE = new COUNT_Stat(
      "HMC_INST_COUNT_CANDIDATE", "hmc.stat.out", HMC_INST_COUNT_CANDIDATE);
  m_HMC_INST_COUNT_HOOK = new COUNT_Stat("HMC_INST_COUNT_HOOK", "hmc.stat.out",
                                         HMC_INST_COUNT_HOOK);
  m_HMC_INST_COUNT_UNHOOK = new COUNT_Stat(
      "HMC_INST_COUNT_UNHOOK", "hmc.stat.out", HMC_INST_COUNT_UNHOOK);
  m_HMC_INST_COUNT_TRANS_BEG = new COUNT_Stat(
      "HMC_INST_COUNT_TRANS_BEG", "hmc.stat.out", HMC_INST_COUNT_TRANS_BEG);
  m_HMC_INST_COUNT_TRANS_MID = new COUNT_Stat(
      "HMC_INST_COUNT_TRANS_MID", "hmc.stat.out", HMC_INST_COUNT_TRANS_MID);
  m_HMC_INST_COUNT_TRANS_END = new COUNT_Stat(
      "HMC_INST_COUNT_TRANS_END", "hmc.stat.out", HMC_INST_COUNT_TRANS_END);

  // ============= ../def/inst.stat.def =============
  m_DIST_OP_CAT_XED_CATEGORY_INVALID =
      new DIST_Stat("OP_CAT_XED_CATEGORY_INVALID", "inst.stat.out",
                    OP_CAT_XED_CATEGORY_INVALID, procStat);
  m_OP_CAT_XED_CATEGORY_INVALID = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_INVALID", "inst.stat.out",
      OP_CAT_XED_CATEGORY_INVALID, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_3DNOW = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_3DNOW", "inst.stat.out", OP_CAT_XED_CATEGORY_3DNOW,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_AES = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_AES", "inst.stat.out", OP_CAT_XED_CATEGORY_AES,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_AVX = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_AVX", "inst.stat.out", OP_CAT_XED_CATEGORY_AVX,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_AVX2 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_AVX2", "inst.stat.out", OP_CAT_XED_CATEGORY_AVX2,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_AVX2GATHER = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_AVX2GATHER", "inst.stat.out",
      OP_CAT_XED_CATEGORY_AVX2GATHER, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_BDW = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_BDW", "inst.stat.out", OP_CAT_XED_CATEGORY_BDW,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_BINARY = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_BINARY", "inst.stat.out", OP_CAT_XED_CATEGORY_BINARY,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_BITBYTE = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_BITBYTE", "inst.stat.out",
      OP_CAT_XED_CATEGORY_BITBYTE, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_BMI1 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_BMI1", "inst.stat.out", OP_CAT_XED_CATEGORY_BMI1,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_BMI2 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_BMI2", "inst.stat.out", OP_CAT_XED_CATEGORY_BMI2,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_BROADCAST = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_BROADCAST", "inst.stat.out",
      OP_CAT_XED_CATEGORY_BROADCAST, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_CALL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_CALL", "inst.stat.out", OP_CAT_XED_CATEGORY_CALL,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_CMOV = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_CMOV", "inst.stat.out", OP_CAT_XED_CATEGORY_CMOV,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_COND_BR = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_COND_BR", "inst.stat.out",
      OP_CAT_XED_CATEGORY_COND_BR, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_CONVERT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_CONVERT", "inst.stat.out",
      OP_CAT_XED_CATEGORY_CONVERT, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_DATAXFER = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_DATAXFER", "inst.stat.out",
      OP_CAT_XED_CATEGORY_DATAXFER, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_DECIMAL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_DECIMAL", "inst.stat.out",
      OP_CAT_XED_CATEGORY_DECIMAL, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_FCMOV = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_FCMOV", "inst.stat.out", OP_CAT_XED_CATEGORY_FCMOV,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_FLAGOP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_FLAGOP", "inst.stat.out", OP_CAT_XED_CATEGORY_FLAGOP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_FMA4 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_FMA4", "inst.stat.out", OP_CAT_XED_CATEGORY_FMA4,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_INTERRUPT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_INTERRUPT", "inst.stat.out",
      OP_CAT_XED_CATEGORY_INTERRUPT, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_IO = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_IO", "inst.stat.out", OP_CAT_XED_CATEGORY_IO,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_IOSTRINGOP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_IOSTRINGOP", "inst.stat.out",
      OP_CAT_XED_CATEGORY_IOSTRINGOP, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_LOGICAL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_LOGICAL", "inst.stat.out",
      OP_CAT_XED_CATEGORY_LOGICAL, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_LZCNT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_LZCNT", "inst.stat.out", OP_CAT_XED_CATEGORY_LZCNT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_MISC = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_MISC", "inst.stat.out", OP_CAT_XED_CATEGORY_MISC,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_MMX = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_MMX", "inst.stat.out", OP_CAT_XED_CATEGORY_MMX,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_NOP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_NOP", "inst.stat.out", OP_CAT_XED_CATEGORY_NOP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_PCLMULQDQ = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_PCLMULQDQ", "inst.stat.out",
      OP_CAT_XED_CATEGORY_PCLMULQDQ, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_POP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_POP", "inst.stat.out", OP_CAT_XED_CATEGORY_POP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_PREFETCH = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_PREFETCH", "inst.stat.out",
      OP_CAT_XED_CATEGORY_PREFETCH, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_PUSH = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_PUSH", "inst.stat.out", OP_CAT_XED_CATEGORY_PUSH,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_RDRAND = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_RDRAND", "inst.stat.out", OP_CAT_XED_CATEGORY_RDRAND,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_RDSEED = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_RDSEED", "inst.stat.out", OP_CAT_XED_CATEGORY_RDSEED,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_RDWRFSGS = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_RDWRFSGS", "inst.stat.out",
      OP_CAT_XED_CATEGORY_RDWRFSGS, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_RET = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_RET", "inst.stat.out", OP_CAT_XED_CATEGORY_RET,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_ROTATE = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_ROTATE", "inst.stat.out", OP_CAT_XED_CATEGORY_ROTATE,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_SEGOP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_SEGOP", "inst.stat.out", OP_CAT_XED_CATEGORY_SEGOP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_SEMAPHORE = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_SEMAPHORE", "inst.stat.out",
      OP_CAT_XED_CATEGORY_SEMAPHORE, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_SHIFT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_SHIFT", "inst.stat.out", OP_CAT_XED_CATEGORY_SHIFT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_SSE = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_SSE", "inst.stat.out", OP_CAT_XED_CATEGORY_SSE,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_STRINGOP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_STRINGOP", "inst.stat.out",
      OP_CAT_XED_CATEGORY_STRINGOP, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_STTNI = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_STTNI", "inst.stat.out", OP_CAT_XED_CATEGORY_STTNI,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_SYSCALL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_SYSCALL", "inst.stat.out",
      OP_CAT_XED_CATEGORY_SYSCALL, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_SYSRET = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_SYSRET", "inst.stat.out", OP_CAT_XED_CATEGORY_SYSRET,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_SYSTEM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_SYSTEM", "inst.stat.out", OP_CAT_XED_CATEGORY_SYSTEM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_TBM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_TBM", "inst.stat.out", OP_CAT_XED_CATEGORY_TBM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_UNCOND_BR = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_UNCOND_BR", "inst.stat.out",
      OP_CAT_XED_CATEGORY_UNCOND_BR, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_VFMA = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_VFMA", "inst.stat.out", OP_CAT_XED_CATEGORY_VFMA,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_VTX = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_VTX", "inst.stat.out", OP_CAT_XED_CATEGORY_VTX,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_WIDENOP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_WIDENOP", "inst.stat.out",
      OP_CAT_XED_CATEGORY_WIDENOP, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_X87_ALU = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_X87_ALU", "inst.stat.out",
      OP_CAT_XED_CATEGORY_X87_ALU, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_XOP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_XOP", "inst.stat.out", OP_CAT_XED_CATEGORY_XOP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_XSAVE = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_XSAVE", "inst.stat.out", OP_CAT_XED_CATEGORY_XSAVE,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_XED_CATEGORY_XSAVEOPT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_XED_CATEGORY_XSAVEOPT", "inst.stat.out",
      OP_CAT_XED_CATEGORY_XSAVEOPT, OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_TR_MUL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_TR_MUL", "inst.stat.out", OP_CAT_TR_MUL,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_TR_DIV = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_TR_DIV", "inst.stat.out", OP_CAT_TR_DIV,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_TR_FMUL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_TR_FMUL", "inst.stat.out", OP_CAT_TR_FMUL,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_TR_FDIV = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_TR_FDIV", "inst.stat.out", OP_CAT_TR_FDIV,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_TR_NOP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_TR_NOP", "inst.stat.out", OP_CAT_TR_NOP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_PREFETCH_NTA = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_PREFETCH_NTA", "inst.stat.out", OP_CAT_PREFETCH_NTA,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_PREFETCH_T0 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_PREFETCH_T0", "inst.stat.out", OP_CAT_PREFETCH_T0,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_PREFETCH_T1 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_PREFETCH_T1", "inst.stat.out", OP_CAT_PREFETCH_T1,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_PREFETCH_T2 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_PREFETCH_T2", "inst.stat.out", OP_CAT_PREFETCH_T2,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_EN = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_EN", "inst.stat.out", OP_CAT_GPU_EN,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_INVALID = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_INVALID", "inst.stat.out", OP_CAT_GPU_INVALID,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ABS = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ABS", "inst.stat.out", OP_CAT_GPU_ABS,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ABS64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ABS64", "inst.stat.out", OP_CAT_GPU_ABS64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ADD = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ADD", "inst.stat.out", OP_CAT_GPU_ADD,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ADD64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ADD64", "inst.stat.out", OP_CAT_GPU_ADD64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ADDC = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ADDC", "inst.stat.out", OP_CAT_GPU_ADDC,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_AND = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_AND", "inst.stat.out", OP_CAT_GPU_AND,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_AND64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_AND64", "inst.stat.out", OP_CAT_GPU_AND64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ATOM_GM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ATOM_GM", "inst.stat.out", OP_CAT_GPU_ATOM_GM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ATOM_SM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ATOM_SM", "inst.stat.out", OP_CAT_GPU_ATOM_SM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ATOM64_GM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ATOM64_GM", "inst.stat.out", OP_CAT_GPU_ATOM64_GM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ATOM64_SM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ATOM64_SM", "inst.stat.out", OP_CAT_GPU_ATOM64_SM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BAR_ARRIVE = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BAR_ARRIVE", "inst.stat.out", OP_CAT_GPU_BAR_ARRIVE,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BAR_SYNC = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BAR_SYNC", "inst.stat.out", OP_CAT_GPU_BAR_SYNC,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BAR_RED = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BAR_RED", "inst.stat.out", OP_CAT_GPU_BAR_RED,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BFE = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BFE", "inst.stat.out", OP_CAT_GPU_BFE,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BFE64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BFE64", "inst.stat.out", OP_CAT_GPU_BFE64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BFI = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BFI", "inst.stat.out", OP_CAT_GPU_BFI,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BFI64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BFI64", "inst.stat.out", OP_CAT_GPU_BFI64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BFIND = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BFIND", "inst.stat.out", OP_CAT_GPU_BFIND,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BFIND64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BFIND64", "inst.stat.out", OP_CAT_GPU_BFIND64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BRA = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BRA", "inst.stat.out", OP_CAT_GPU_BRA,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BREV = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BREV", "inst.stat.out", OP_CAT_GPU_BREV,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BREV64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BREV64", "inst.stat.out", OP_CAT_GPU_BREV64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_BRKPT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_BRKPT", "inst.stat.out", OP_CAT_GPU_BRKPT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_CALL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_CALL", "inst.stat.out", OP_CAT_GPU_CALL,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_CLZ = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_CLZ", "inst.stat.out", OP_CAT_GPU_CLZ,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_CLZ64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_CLZ64", "inst.stat.out", OP_CAT_GPU_CLZ64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_CNOT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_CNOT", "inst.stat.out", OP_CAT_GPU_CNOT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_CNOT64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_CNOT64", "inst.stat.out", OP_CAT_GPU_CNOT64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_COPYSIGN = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_COPYSIGN", "inst.stat.out", OP_CAT_GPU_COPYSIGN,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_COPYSIGN64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_COPYSIGN64", "inst.stat.out", OP_CAT_GPU_COPYSIGN64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_COS = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_COS", "inst.stat.out", OP_CAT_GPU_COS,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_CVT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_CVT", "inst.stat.out", OP_CAT_GPU_CVT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_CVT64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_CVT64", "inst.stat.out", OP_CAT_GPU_CVT64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_CVTA = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_CVTA", "inst.stat.out", OP_CAT_GPU_CVTA,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_CVTA64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_CVTA64", "inst.stat.out", OP_CAT_GPU_CVTA64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_DIV = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_DIV", "inst.stat.out", OP_CAT_GPU_DIV,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_DIV64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_DIV64", "inst.stat.out", OP_CAT_GPU_DIV64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_EX2 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_EX2", "inst.stat.out", OP_CAT_GPU_EX2,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_EXIT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_EXIT", "inst.stat.out", OP_CAT_GPU_EXIT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_FMA = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_FMA", "inst.stat.out", OP_CAT_GPU_FMA,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_FMA64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_FMA64", "inst.stat.out", OP_CAT_GPU_FMA64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ISSPACEP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ISSPACEP", "inst.stat.out", OP_CAT_GPU_ISSPACEP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_LD = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_LD", "inst.stat.out", OP_CAT_GPU_LD,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_LD64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_LD64", "inst.stat.out", OP_CAT_GPU_LD64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_LDU = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_LDU", "inst.stat.out", OP_CAT_GPU_LDU,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_LDU64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_LDU64", "inst.stat.out", OP_CAT_GPU_LDU64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_LG2 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_LG2", "inst.stat.out", OP_CAT_GPU_LG2,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MAD24 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MAD24", "inst.stat.out", OP_CAT_GPU_MAD24,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MAD = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MAD", "inst.stat.out", OP_CAT_GPU_MAD,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MAD64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MAD64", "inst.stat.out", OP_CAT_GPU_MAD64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MADC = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MADC", "inst.stat.out", OP_CAT_GPU_MADC,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MADC64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MADC64", "inst.stat.out", OP_CAT_GPU_MADC64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MAX = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MAX", "inst.stat.out", OP_CAT_GPU_MAX,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MAX64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MAX64", "inst.stat.out", OP_CAT_GPU_MAX64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEMBAR_CTA = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEMBAR_CTA", "inst.stat.out", OP_CAT_GPU_MEMBAR_CTA,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEMBAR_GL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEMBAR_GL", "inst.stat.out", OP_CAT_GPU_MEMBAR_GL,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEMBAR_SYS = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEMBAR_SYS", "inst.stat.out", OP_CAT_GPU_MEMBAR_SYS,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MIN = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MIN", "inst.stat.out", OP_CAT_GPU_MIN,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MIN64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MIN64", "inst.stat.out", OP_CAT_GPU_MIN64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MOV = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MOV", "inst.stat.out", OP_CAT_GPU_MOV,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MOV64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MOV64", "inst.stat.out", OP_CAT_GPU_MOV64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MUL24 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MUL24", "inst.stat.out", OP_CAT_GPU_MUL24,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MUL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MUL", "inst.stat.out", OP_CAT_GPU_MUL,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MUL64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MUL64", "inst.stat.out", OP_CAT_GPU_MUL64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_NEG = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_NEG", "inst.stat.out", OP_CAT_GPU_NEG,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_NEG64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_NEG64", "inst.stat.out", OP_CAT_GPU_NEG64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_NOT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_NOT", "inst.stat.out", OP_CAT_GPU_NOT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_NOT64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_NOT64", "inst.stat.out", OP_CAT_GPU_NOT64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_OR = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_OR", "inst.stat.out", OP_CAT_GPU_OR,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_OR64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_OR64", "inst.stat.out", OP_CAT_GPU_OR64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_PMEVENT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_PMEVENT", "inst.stat.out", OP_CAT_GPU_PMEVENT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_POPC = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_POPC", "inst.stat.out", OP_CAT_GPU_POPC,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_POPC64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_POPC64", "inst.stat.out", OP_CAT_GPU_POPC64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_PREFETCH = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_PREFETCH", "inst.stat.out", OP_CAT_GPU_PREFETCH,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_PREFETCHU = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_PREFETCHU", "inst.stat.out", OP_CAT_GPU_PREFETCHU,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_PRMT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_PRMT", "inst.stat.out", OP_CAT_GPU_PRMT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RCP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RCP", "inst.stat.out", OP_CAT_GPU_RCP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RCP64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RCP64", "inst.stat.out", OP_CAT_GPU_RCP64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RED_GM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RED_GM", "inst.stat.out", OP_CAT_GPU_RED_GM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RED_SM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RED_SM", "inst.stat.out", OP_CAT_GPU_RED_SM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RED64_GM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RED64_GM", "inst.stat.out", OP_CAT_GPU_RED64_GM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RED64_SM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RED64_SM", "inst.stat.out", OP_CAT_GPU_RED64_SM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_REM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_REM", "inst.stat.out", OP_CAT_GPU_REM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_REM64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_REM64", "inst.stat.out", OP_CAT_GPU_REM64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RET = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RET", "inst.stat.out", OP_CAT_GPU_RET,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RSQRT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RSQRT", "inst.stat.out", OP_CAT_GPU_RSQRT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RSQRT64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RSQRT64", "inst.stat.out", OP_CAT_GPU_RSQRT64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SAD = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SAD", "inst.stat.out", OP_CAT_GPU_SAD,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SAD64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SAD64", "inst.stat.out", OP_CAT_GPU_SAD64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SELP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SELP", "inst.stat.out", OP_CAT_GPU_SELP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SELP64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SELP64", "inst.stat.out", OP_CAT_GPU_SELP64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SET = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SET", "inst.stat.out", OP_CAT_GPU_SET,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SET64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SET64", "inst.stat.out", OP_CAT_GPU_SET64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SETP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SETP", "inst.stat.out", OP_CAT_GPU_SETP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SETP64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SETP64", "inst.stat.out", OP_CAT_GPU_SETP64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SHFL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SHFL", "inst.stat.out", OP_CAT_GPU_SHFL,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SHFL64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SHFL64", "inst.stat.out", OP_CAT_GPU_SHFL64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SHL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SHL", "inst.stat.out", OP_CAT_GPU_SHL,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SHL64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SHL64", "inst.stat.out", OP_CAT_GPU_SHL64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SHR = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SHR", "inst.stat.out", OP_CAT_GPU_SHR,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SHR64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SHR64", "inst.stat.out", OP_CAT_GPU_SHR64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SIN = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SIN", "inst.stat.out", OP_CAT_GPU_SIN,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SLCT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SLCT", "inst.stat.out", OP_CAT_GPU_SLCT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SLCT64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SLCT64", "inst.stat.out", OP_CAT_GPU_SLCT64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SQRT = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SQRT", "inst.stat.out", OP_CAT_GPU_SQRT,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SQRT64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SQRT64", "inst.stat.out", OP_CAT_GPU_SQRT64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ST = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ST", "inst.stat.out", OP_CAT_GPU_ST,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_ST64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_ST64", "inst.stat.out", OP_CAT_GPU_ST64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SUB = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SUB", "inst.stat.out", OP_CAT_GPU_SUB,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SUB64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SUB64", "inst.stat.out", OP_CAT_GPU_SUB64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SUBC = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SUBC", "inst.stat.out", OP_CAT_GPU_SUBC,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SULD = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SULD", "inst.stat.out", OP_CAT_GPU_SULD,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SULD64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SULD64", "inst.stat.out", OP_CAT_GPU_SULD64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SURED = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SURED", "inst.stat.out", OP_CAT_GPU_SURED,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SURED64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SURED64", "inst.stat.out", OP_CAT_GPU_SURED64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SUST = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SUST", "inst.stat.out", OP_CAT_GPU_SUST,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SUST64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SUST64", "inst.stat.out", OP_CAT_GPU_SUST64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_SUQ = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_SUQ", "inst.stat.out", OP_CAT_GPU_SUQ,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_TESTP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_TESTP", "inst.stat.out", OP_CAT_GPU_TESTP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_TESTP64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_TESTP64", "inst.stat.out", OP_CAT_GPU_TESTP64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_TEX = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_TEX", "inst.stat.out", OP_CAT_GPU_TEX,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_TLD4 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_TLD4", "inst.stat.out", OP_CAT_GPU_TLD4,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_TXQ = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_TXQ", "inst.stat.out", OP_CAT_GPU_TXQ,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_TRAP = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_TRAP", "inst.stat.out", OP_CAT_GPU_TRAP,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VABSDIFF = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VABSDIFF", "inst.stat.out", OP_CAT_GPU_VABSDIFF,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VADD = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VADD", "inst.stat.out", OP_CAT_GPU_VADD,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VMAD = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VMAD", "inst.stat.out", OP_CAT_GPU_VMAD,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VMAX = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VMAX", "inst.stat.out", OP_CAT_GPU_VMAX,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VMIN = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VMIN", "inst.stat.out", OP_CAT_GPU_VMIN,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VSET = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VSET", "inst.stat.out", OP_CAT_GPU_VSET,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VSHL = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VSHL", "inst.stat.out", OP_CAT_GPU_VSHL,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VSHR = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VSHR", "inst.stat.out", OP_CAT_GPU_VSHR,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VSUB = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VSUB", "inst.stat.out", OP_CAT_GPU_VSUB,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_VOTE = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_VOTE", "inst.stat.out", OP_CAT_GPU_VOTE,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_XOR = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_XOR", "inst.stat.out", OP_CAT_GPU_XOR,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_XOR64 = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_XOR64", "inst.stat.out", OP_CAT_GPU_XOR64,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_RECONVERGE = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_RECONVERGE", "inst.stat.out", OP_CAT_GPU_RECONVERGE,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_PHI = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_PHI", "inst.stat.out", OP_CAT_GPU_PHI,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_LD_GM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_LD_GM", "inst.stat.out", OP_CAT_GPU_MEM_LD_GM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_LD_LM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_LD_LM", "inst.stat.out", OP_CAT_GPU_MEM_LD_LM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_LD_SM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_LD_SM", "inst.stat.out", OP_CAT_GPU_MEM_LD_SM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_LD_CM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_LD_CM", "inst.stat.out", OP_CAT_GPU_MEM_LD_CM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_LD_TM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_LD_TM", "inst.stat.out", OP_CAT_GPU_MEM_LD_TM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_LD_PM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_LD_PM", "inst.stat.out", OP_CAT_GPU_MEM_LD_PM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_LDU_GM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_LDU_GM", "inst.stat.out", OP_CAT_GPU_MEM_LDU_GM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_ST_GM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_ST_GM", "inst.stat.out", OP_CAT_GPU_MEM_ST_GM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_ST_LM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_ST_LM", "inst.stat.out", OP_CAT_GPU_MEM_ST_LM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_MEM_ST_SM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_MEM_ST_SM", "inst.stat.out", OP_CAT_GPU_MEM_ST_SM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_DATA_XFER_GM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_DATA_XFER_GM", "inst.stat.out", OP_CAT_GPU_DATA_XFER_GM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_DATA_XFER_LM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_DATA_XFER_LM", "inst.stat.out", OP_CAT_GPU_DATA_XFER_LM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_OP_CAT_GPU_DATA_XFER_SM = (COUNT_Stat *)new DISTMember_Stat(
      "OP_CAT_GPU_DATA_XFER_SM", "inst.stat.out", OP_CAT_GPU_DATA_XFER_SM,
      OP_CAT_XED_CATEGORY_INVALID);
  m_FP_OPS_TOT = new COUNT_Stat("FP_OPS_TOT", "inst.stat.out", FP_OPS_TOT);
  m_FP_OPS = new COUNT_Stat("FP_OPS", "inst.stat.out", FP_OPS);

  // ============= ../def/internal.stat.def =============

  // ============= ../def/memory.stat.def =============
  m_AVG_MEMORY_LATENCY_BASE = new COUNT_Stat(
      "AVG_MEMORY_LATENCY_BASE", "memory.stat.out", AVG_MEMORY_LATENCY_BASE);
  m_AVG_MEMORY_LATENCY =
      new RATIO_Stat("AVG_MEMORY_LATENCY", "memory.stat.out",
                     AVG_MEMORY_LATENCY, AVG_MEMORY_LATENCY_BASE, procStat);
  m_MSHR_FULL = new COUNT_Stat("MSHR_FULL", "memory.stat.out", MSHR_FULL);
  m_TOTAL_MEMORY =
      new COUNT_Stat("TOTAL_MEMORY", "memory.stat.out", TOTAL_MEMORY);
  m_TOTAL_MEMORY_MERGE =
      new RATIO_Stat("TOTAL_MEMORY_MERGE", "memory.stat.out",
                     TOTAL_MEMORY_MERGE, TOTAL_MEMORY, procStat);
  m_TOTAL_WB = new RATIO_Stat("TOTAL_WB", "memory.stat.out", TOTAL_WB,
                              TOTAL_MEMORY, procStat);
  m_L1_WB =
      new RATIO_Stat("L1_WB", "memory.stat.out", L1_WB, TOTAL_WB, procStat);
  m_L2_WB =
      new RATIO_Stat("L2_WB", "memory.stat.out", L2_WB, TOTAL_WB, procStat);
  m_L3_WB =
      new RATIO_Stat("L3_WB", "memory.stat.out", L3_WB, TOTAL_WB, procStat);
  m_TOTAL_DRAM = new COUNT_Stat("TOTAL_DRAM", "memory.stat.out", TOTAL_DRAM);
  m_TOTAL_DRAM_MERGE = new RATIO_Stat("TOTAL_DRAM_MERGE", "memory.stat.out",
                                      TOTAL_DRAM_MERGE, TOTAL_DRAM, procStat);
  m_L1_HIT_CPU = new COUNT_Stat("L1_HIT_CPU", "memory.stat.out", L1_HIT_CPU);
  m_L1_HIT_GPU = new COUNT_Stat("L1_HIT_GPU", "memory.stat.out", L1_HIT_GPU);
  m_L1_MISS_CPU = new COUNT_Stat("L1_MISS_CPU", "memory.stat.out", L1_MISS_CPU);
  m_L1_MISS_GPU = new COUNT_Stat("L1_MISS_GPU", "memory.stat.out", L1_MISS_GPU);
  m_L2_HIT_CPU = new COUNT_Stat("L2_HIT_CPU", "memory.stat.out", L2_HIT_CPU);
  m_L2_HIT_GPU = new COUNT_Stat("L2_HIT_GPU", "memory.stat.out", L2_HIT_GPU);
  m_L2_MISS_CPU = new COUNT_Stat("L2_MISS_CPU", "memory.stat.out", L2_MISS_CPU);
  m_L2_MISS_GPU = new COUNT_Stat("L2_MISS_GPU", "memory.stat.out", L2_MISS_GPU);
  m_L3_HIT_CPU = new COUNT_Stat("L3_HIT_CPU", "memory.stat.out", L3_HIT_CPU);
  m_L3_HIT_GPU = new COUNT_Stat("L3_HIT_GPU", "memory.stat.out", L3_HIT_GPU);
  m_L3_MISS_CPU = new COUNT_Stat("L3_MISS_CPU", "memory.stat.out", L3_MISS_CPU);
  m_L3_MISS_GPU = new COUNT_Stat("L3_MISS_GPU", "memory.stat.out", L3_MISS_GPU);
  m_L3_HIT_PROMOTION_CPU = new COUNT_Stat(
      "L3_HIT_PROMOTION_CPU", "memory.stat.out", L3_HIT_PROMOTION_CPU);
  m_L3_HIT_PROMOTION_GPU = new COUNT_Stat(
      "L3_HIT_PROMOTION_GPU", "memory.stat.out", L3_HIT_PROMOTION_GPU);
  m_DIST_ICACHE_HIT =
      new DIST_Stat("ICACHE_HIT", "memory.stat.out", ICACHE_HIT, procStat);
  m_ICACHE_HIT = (COUNT_Stat *)new DISTMember_Stat(
      "ICACHE_HIT", "memory.stat.out", ICACHE_HIT, ICACHE_HIT);
  m_ICACHE_MISS = (COUNT_Stat *)new DISTMember_Stat(
      "ICACHE_MISS", "memory.stat.out", ICACHE_MISS, ICACHE_HIT);
  m_FETCH_THREAD_SKIP_LD_WAIT =
      new COUNT_Stat("FETCH_THREAD_SKIP_LD_WAIT", "memory.stat.out",
                     FETCH_THREAD_SKIP_LD_WAIT);
  m_FETCH_THREAD_SKIP_BR_WAIT =
      new COUNT_Stat("FETCH_THREAD_SKIP_BR_WAIT", "memory.stat.out",
                     FETCH_THREAD_SKIP_BR_WAIT);
  m_FETCH_THREAD_SKIP_SCHED_WAIT =
      new COUNT_Stat("FETCH_THREAD_SKIP_SCHED_WAIT", "memory.stat.out",
                     FETCH_THREAD_SKIP_SCHED_WAIT);
  m_DIST_COAL_INST =
      new DIST_Stat("COAL_INST", "memory.stat.out", COAL_INST, procStat);
  m_COAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "COAL_INST", "memory.stat.out", COAL_INST, COAL_INST);
  m_UNCOAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "UNCOAL_INST", "memory.stat.out", UNCOAL_INST, COAL_INST);
  m_DIST_COAL_INST_SINGLE_TRANS =
      new DIST_Stat("COAL_INST_SINGLE_TRANS", "memory.stat.out",
                    COAL_INST_SINGLE_TRANS, procStat);
  m_COAL_INST_SINGLE_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "COAL_INST_SINGLE_TRANS", "memory.stat.out", COAL_INST_SINGLE_TRANS,
      COAL_INST_SINGLE_TRANS);
  m_COAL_INST_MUL_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "COAL_INST_MUL_TRANS", "memory.stat.out", COAL_INST_MUL_TRANS,
      COAL_INST_SINGLE_TRANS);
  m_UNCOAL_INST_MUL_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "UNCOAL_INST_MUL_TRANS", "memory.stat.out", UNCOAL_INST_MUL_TRANS,
      COAL_INST_SINGLE_TRANS);
  m_DIST_SM_COAL_INST =
      new DIST_Stat("SM_COAL_INST", "memory.stat.out", SM_COAL_INST, procStat);
  m_SM_COAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "SM_COAL_INST", "memory.stat.out", SM_COAL_INST, SM_COAL_INST);
  m_CM_COAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "CM_COAL_INST", "memory.stat.out", CM_COAL_INST, SM_COAL_INST);
  m_TM_COAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "TM_COAL_INST", "memory.stat.out", TM_COAL_INST, SM_COAL_INST);
  m_DM_COAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "DM_COAL_INST", "memory.stat.out", DM_COAL_INST, SM_COAL_INST);
  m_DIST_SM_UNCOAL_INST = new DIST_Stat("SM_UNCOAL_INST", "memory.stat.out",
                                        SM_UNCOAL_INST, procStat);
  m_SM_UNCOAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "SM_UNCOAL_INST", "memory.stat.out", SM_UNCOAL_INST, SM_UNCOAL_INST);
  m_CM_UNCOAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "CM_UNCOAL_INST", "memory.stat.out", CM_UNCOAL_INST, SM_UNCOAL_INST);
  m_TM_UNCOAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "TM_UNCOAL_INST", "memory.stat.out", TM_UNCOAL_INST, SM_UNCOAL_INST);
  m_DM_UNCOAL_INST = (COUNT_Stat *)new DISTMember_Stat(
      "DM_UNCOAL_INST", "memory.stat.out", DM_UNCOAL_INST, SM_UNCOAL_INST);
  m_DIST_SM_COAL_INST_SINGLE_TRANS =
      new DIST_Stat("SM_COAL_INST_SINGLE_TRANS", "memory.stat.out",
                    SM_COAL_INST_SINGLE_TRANS, procStat);
  m_SM_COAL_INST_SINGLE_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "SM_COAL_INST_SINGLE_TRANS", "memory.stat.out", SM_COAL_INST_SINGLE_TRANS,
      SM_COAL_INST_SINGLE_TRANS);
  m_CM_COAL_INST_SINGLE_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "CM_COAL_INST_SINGLE_TRANS", "memory.stat.out", CM_COAL_INST_SINGLE_TRANS,
      SM_COAL_INST_SINGLE_TRANS);
  m_TM_COAL_INST_SINGLE_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "TM_COAL_INST_SINGLE_TRANS", "memory.stat.out", TM_COAL_INST_SINGLE_TRANS,
      SM_COAL_INST_SINGLE_TRANS);
  m_DM_COAL_INST_SINGLE_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "DM_COAL_INST_SINGLE_TRANS", "memory.stat.out", DM_COAL_INST_SINGLE_TRANS,
      SM_COAL_INST_SINGLE_TRANS);
  m_DIST_SM_COAL_INST_MUL_TRANS =
      new DIST_Stat("SM_COAL_INST_MUL_TRANS", "memory.stat.out",
                    SM_COAL_INST_MUL_TRANS, procStat);
  m_SM_COAL_INST_MUL_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "SM_COAL_INST_MUL_TRANS", "memory.stat.out", SM_COAL_INST_MUL_TRANS,
      SM_COAL_INST_MUL_TRANS);
  m_CM_COAL_INST_MUL_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "CM_COAL_INST_MUL_TRANS", "memory.stat.out", CM_COAL_INST_MUL_TRANS,
      SM_COAL_INST_MUL_TRANS);
  m_TM_COAL_INST_MUL_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "TM_COAL_INST_MUL_TRANS", "memory.stat.out", TM_COAL_INST_MUL_TRANS,
      SM_COAL_INST_MUL_TRANS);
  m_DM_COAL_INST_MUL_TRANS = (COUNT_Stat *)new DISTMember_Stat(
      "DM_COAL_INST_MUL_TRANS", "memory.stat.out", DM_COAL_INST_MUL_TRANS,
      SM_COAL_INST_MUL_TRANS);
  m_NUM_MUL_TRANS_CM_TM_DM_INST =
      new COUNT_Stat("NUM_MUL_TRANS_CM_TM_DM_INST", "memory.stat.out",
                     NUM_MUL_TRANS_CM_TM_DM_INST);
  m_NUM_MUL_TRANS_CM_TM_DM = new RATIO_Stat(
      "NUM_MUL_TRANS_CM_TM_DM", "memory.stat.out", NUM_MUL_TRANS_CM_TM_DM,
      NUM_MUL_TRANS_CM_TM_DM_INST, procStat);
  m_CONST_CACHE_HIT =
      new COUNT_Stat("CONST_CACHE_HIT", "memory.stat.out", CONST_CACHE_HIT);
  m_CONST_CACHE_MISS =
      new COUNT_Stat("CONST_CACHE_MISS", "memory.stat.out", CONST_CACHE_MISS);
  m_CONST_CACHE_MISS_NO_EXECUTE =
      new COUNT_Stat("CONST_CACHE_MISS_NO_EXECUTE", "memory.stat.out",
                     CONST_CACHE_MISS_NO_EXECUTE);
  m_CONST_CACHE_ACCESS = new COUNT_Stat("CONST_CACHE_ACCESS", "memory.stat.out",
                                        CONST_CACHE_ACCESS);
  m_TEXTURE_CACHE_HIT =
      new COUNT_Stat("TEXTURE_CACHE_HIT", "memory.stat.out", TEXTURE_CACHE_HIT);
  m_TEXTURE_CACHE_MISS = new COUNT_Stat("TEXTURE_CACHE_MISS", "memory.stat.out",
                                        TEXTURE_CACHE_MISS);
  m_TEXTURE_CACHE_NO_EXECUTE = new COUNT_Stat(
      "TEXTURE_CACHE_NO_EXECUTE", "memory.stat.out", TEXTURE_CACHE_NO_EXECUTE);
  m_TEXTURE_CACHE_ACCESS = new COUNT_Stat(
      "TEXTURE_CACHE_ACCESS", "memory.stat.out", TEXTURE_CACHE_ACCESS);
  m_SHARED_MEM_INST =
      new COUNT_Stat("SHARED_MEM_INST", "memory.stat.out", SHARED_MEM_INST);
  m_SHARED_MEM_ACCESS =
      new COUNT_Stat("SHARED_MEM_ACCESS", "memory.stat.out", SHARED_MEM_ACCESS);
  m_DIST_LD_NO_FORWARD = new DIST_Stat("LD_NO_FORWARD", "memory.stat.out",
                                       LD_NO_FORWARD, procStat);
  m_LD_NO_FORWARD = (COUNT_Stat *)new DISTMember_Stat(
      "LD_NO_FORWARD", "memory.stat.out", LD_NO_FORWARD, LD_NO_FORWARD);
  m_FORWARDED_LD = (COUNT_Stat *)new DISTMember_Stat(
      "FORWARDED_LD", "memory.stat.out", FORWARDED_LD, LD_NO_FORWARD);
  m_MEM_STALL_CYCLE =
      new COUNT_Stat("MEM_STALL_CYCLE", "memory.stat.out", MEM_STALL_CYCLE);
  m_CACHE_BANK_BUSY =
      new COUNT_Stat("CACHE_BANK_BUSY", "memory.stat.out", CACHE_BANK_BUSY);
  m_ICACHE_MISS_TOTAL =
      new COUNT_Stat("ICACHE_MISS_TOTAL", "memory.stat.out", ICACHE_MISS_TOTAL);
  m_ICACHE_FILL = new COUNT_Stat("ICACHE_FILL", "memory.stat.out", ICACHE_FILL);
  m_TOTAL_CAGE_PERIOD =
      new COUNT_Stat("TOTAL_CAGE_PERIOD", "memory.stat.out", TOTAL_CAGE_PERIOD);
  m_TOTAL_CAGE_APPL0 =
      new RATIO_Stat("TOTAL_CAGE_APPL0", "memory.stat.out", TOTAL_CAGE_APPL0,
                     TOTAL_CAGE_PERIOD, procStat);
  m_TOTAL_CAGE_APPL1 =
      new RATIO_Stat("TOTAL_CAGE_APPL1", "memory.stat.out", TOTAL_CAGE_APPL1,
                     TOTAL_CAGE_PERIOD, procStat);
  m_TOTAL_CAGE_APPL2 =
      new RATIO_Stat("TOTAL_CAGE_APPL2", "memory.stat.out", TOTAL_CAGE_APPL2,
                     TOTAL_CAGE_PERIOD, procStat);
  m_TOTAL_CAGE_APPL3 =
      new RATIO_Stat("TOTAL_CAGE_APPL3", "memory.stat.out", TOTAL_CAGE_APPL3,
                     TOTAL_CAGE_PERIOD, procStat);
  m_TOTAL_CAGE_APPL4 =
      new RATIO_Stat("TOTAL_CAGE_APPL4", "memory.stat.out", TOTAL_CAGE_APPL4,
                     TOTAL_CAGE_PERIOD, procStat);
  m_ABIP_AVG_RATIO_BASE = new COUNT_Stat(
      "ABIP_AVG_RATIO_BASE", "memory.stat.out", ABIP_AVG_RATIO_BASE);
  m_ABIP_AVG_RATIO =
      new RATIO_Stat("ABIP_AVG_RATIO", "memory.stat.out", ABIP_AVG_RATIO,
                     ABIP_AVG_RATIO_BASE, procStat);
  m_NUM_WRITE_ACKS =
      new COUNT_Stat("NUM_WRITE_ACKS", "memory.stat.out", NUM_WRITE_ACKS);
  m_NUM_WRITES = new COUNT_Stat("NUM_WRITES", "memory.stat.out", NUM_WRITES);
  m_TOTAL_WRITE_ACKS =
      new COUNT_Stat("TOTAL_WRITE_ACKS", "memory.stat.out", TOTAL_WRITE_ACKS);
  m_TOTAL_WRITES =
      new COUNT_Stat("TOTAL_WRITES", "memory.stat.out", TOTAL_WRITES);
  m_NUM_PHYSICAL_PAGES = new COUNT_Stat("NUM_PHYSICAL_PAGES", "memory.stat.out",
                                        NUM_PHYSICAL_PAGES);

  // ============= ../def/network.stat.def =============
  m_TOTAL_PACKET_CPU =
      new COUNT_Stat("TOTAL_PACKET_CPU", "network.stat.out", TOTAL_PACKET_CPU);
  m_TOTAL_PACKET_GPU =
      new COUNT_Stat("TOTAL_PACKET_GPU", "network.stat.out", TOTAL_PACKET_GPU);
  m_NOC_AVG_LATENCY_BASE = new COUNT_Stat(
      "NOC_AVG_LATENCY_BASE", "network.stat.out", NOC_AVG_LATENCY_BASE);
  m_NOC_AVG_LATENCY_BASE_CPU = new COUNT_Stat(
      "NOC_AVG_LATENCY_BASE_CPU", "network.stat.out", NOC_AVG_LATENCY_BASE_CPU);
  m_NOC_AVG_LATENCY_BASE_GPU = new COUNT_Stat(
      "NOC_AVG_LATENCY_BASE_GPU", "network.stat.out", NOC_AVG_LATENCY_BASE_GPU);
  m_NOC_AVG_LATENCY =
      new RATIO_Stat("NOC_AVG_LATENCY", "network.stat.out", NOC_AVG_LATENCY,
                     NOC_AVG_LATENCY_BASE, procStat);
  m_NOC_AVG_LATENCY_CPU =
      new RATIO_Stat("NOC_AVG_LATENCY_CPU", "network.stat.out",
                     NOC_AVG_LATENCY_CPU, NOC_AVG_LATENCY_BASE_CPU, procStat);
  m_NOC_AVG_LATENCY_GPU =
      new RATIO_Stat("NOC_AVG_LATENCY_GPU", "network.stat.out",
                     NOC_AVG_LATENCY_GPU, NOC_AVG_LATENCY_BASE_GPU, procStat);
  m_NOC_AVG_ACTIVE_PACKET_BASE =
      new COUNT_Stat("NOC_AVG_ACTIVE_PACKET_BASE", "network.stat.out",
                     NOC_AVG_ACTIVE_PACKET_BASE);
  m_NOC_AVG_ACTIVE_PACKET_BASE_CPU =
      new COUNT_Stat("NOC_AVG_ACTIVE_PACKET_BASE_CPU", "network.stat.out",
                     NOC_AVG_ACTIVE_PACKET_BASE_CPU);
  m_NOC_AVG_ACTIVE_PACKET_BASE_GPU =
      new COUNT_Stat("NOC_AVG_ACTIVE_PACKET_BASE_GPU", "network.stat.out",
                     NOC_AVG_ACTIVE_PACKET_BASE_GPU);
  m_NOC_AVG_ACTIVE_PACKET = new RATIO_Stat(
      "NOC_AVG_ACTIVE_PACKET", "network.stat.out", NOC_AVG_ACTIVE_PACKET,
      NOC_AVG_ACTIVE_PACKET_BASE, procStat);
  m_NOC_AVG_ACTIVE_PACKET_CPU = new RATIO_Stat(
      "NOC_AVG_ACTIVE_PACKET_CPU", "network.stat.out",
      NOC_AVG_ACTIVE_PACKET_CPU, NOC_AVG_ACTIVE_PACKET_BASE_CPU, procStat);
  m_NOC_AVG_ACTIVE_PACKET_GPU = new RATIO_Stat(
      "NOC_AVG_ACTIVE_PACKET_GPU", "network.stat.out",
      NOC_AVG_ACTIVE_PACKET_GPU, NOC_AVG_ACTIVE_PACKET_BASE_GPU, procStat);
  m_NOC_IDLE_CHANNEL =
      new COUNT_Stat("NOC_IDLE_CHANNEL", "network.stat.out", NOC_IDLE_CHANNEL);
  m_NOC_IDLE_CHANNEL_CPU = new COUNT_Stat(
      "NOC_IDLE_CHANNEL_CPU", "network.stat.out", NOC_IDLE_CHANNEL_CPU);
  m_NOC_IDLE_CHANNEL_GPU = new COUNT_Stat(
      "NOC_IDLE_CHANNEL_GPU", "network.stat.out", NOC_IDLE_CHANNEL_GPU);
  m_NOC_IDLE_CHANNEL_L3 = new COUNT_Stat(
      "NOC_IDLE_CHANNEL_L3", "network.stat.out", NOC_IDLE_CHANNEL_L3);
  m_NOC_IDLE_CHANNEL_MC = new COUNT_Stat(
      "NOC_IDLE_CHANNEL_MC", "network.stat.out", NOC_IDLE_CHANNEL_MC);
  m_NOC_AVG_WAIT_IN_ROUTER_BASE =
      new COUNT_Stat("NOC_AVG_WAIT_IN_ROUTER_BASE", "network.stat.out",
                     NOC_AVG_WAIT_IN_ROUTER_BASE);
  m_NOC_AVG_WAIT_IN_ROUTER_BASE_CPU =
      new COUNT_Stat("NOC_AVG_WAIT_IN_ROUTER_BASE_CPU", "network.stat.out",
                     NOC_AVG_WAIT_IN_ROUTER_BASE_CPU);
  m_NOC_AVG_WAIT_IN_ROUTER_BASE_GPU =
      new COUNT_Stat("NOC_AVG_WAIT_IN_ROUTER_BASE_GPU", "network.stat.out",
                     NOC_AVG_WAIT_IN_ROUTER_BASE_GPU);
  m_NOC_AVG_WAIT_IN_ROUTER_BASE_L3 =
      new COUNT_Stat("NOC_AVG_WAIT_IN_ROUTER_BASE_L3", "network.stat.out",
                     NOC_AVG_WAIT_IN_ROUTER_BASE_L3);
  m_NOC_AVG_WAIT_IN_ROUTER_BASE_MC =
      new COUNT_Stat("NOC_AVG_WAIT_IN_ROUTER_BASE_MC", "network.stat.out",
                     NOC_AVG_WAIT_IN_ROUTER_BASE_MC);
  m_NOC_AVG_WAIT_IN_ROUTER = new RATIO_Stat(
      "NOC_AVG_WAIT_IN_ROUTER", "network.stat.out", NOC_AVG_WAIT_IN_ROUTER,
      NOC_AVG_WAIT_IN_ROUTER_BASE, procStat);
  m_NOC_AVG_WAIT_IN_ROUTER_CPU = new RATIO_Stat(
      "NOC_AVG_WAIT_IN_ROUTER_CPU", "network.stat.out",
      NOC_AVG_WAIT_IN_ROUTER_CPU, NOC_AVG_WAIT_IN_ROUTER_BASE_CPU, procStat);
  m_NOC_AVG_WAIT_IN_ROUTER_GPU = new RATIO_Stat(
      "NOC_AVG_WAIT_IN_ROUTER_GPU", "network.stat.out",
      NOC_AVG_WAIT_IN_ROUTER_GPU, NOC_AVG_WAIT_IN_ROUTER_BASE_GPU, procStat);
  m_NOC_AVG_WAIT_IN_ROUTER_L3 = new RATIO_Stat(
      "NOC_AVG_WAIT_IN_ROUTER_L3", "network.stat.out",
      NOC_AVG_WAIT_IN_ROUTER_L3, NOC_AVG_WAIT_IN_ROUTER_BASE_L3, procStat);
  m_NOC_AVG_WAIT_IN_ROUTER_MC = new RATIO_Stat(
      "NOC_AVG_WAIT_IN_ROUTER_MC", "network.stat.out",
      NOC_AVG_WAIT_IN_ROUTER_MC, NOC_AVG_WAIT_IN_ROUTER_BASE_MC, procStat);
  m_NOC_LINK_ACTIVE =
      new COUNT_Stat("NOC_LINK_ACTIVE", "network.stat.out", NOC_LINK_ACTIVE);

  // ============= ../def/power_units.stat.def =============
  m_POWER_BLOCK_STATES_R = new COUNT_Stat(
      "POWER_BLOCK_STATES_R", "power_units.stat.out", POWER_BLOCK_STATES_R);
  m_POWER_BLOCK_STATES_W = new COUNT_Stat(
      "POWER_BLOCK_STATES_W", "power_units.stat.out", POWER_BLOCK_STATES_W);
  m_POWER_FETCH_QUEUE_R = new COUNT_Stat(
      "POWER_FETCH_QUEUE_R", "power_units.stat.out", POWER_FETCH_QUEUE_R);
  m_POWER_FETCH_QUEUE_W = new COUNT_Stat(
      "POWER_FETCH_QUEUE_W", "power_units.stat.out", POWER_FETCH_QUEUE_W);
  m_POWER_INST_QUEUE_R = new COUNT_Stat(
      "POWER_INST_QUEUE_R", "power_units.stat.out", POWER_INST_QUEUE_R);
  m_POWER_INST_QUEUE_W = new COUNT_Stat(
      "POWER_INST_QUEUE_W", "power_units.stat.out", POWER_INST_QUEUE_W);
  m_POWER_BR_PRED_R = new COUNT_Stat("POWER_BR_PRED_R", "power_units.stat.out",
                                     POWER_BR_PRED_R);
  m_POWER_BR_PRED_W = new COUNT_Stat("POWER_BR_PRED_W", "power_units.stat.out",
                                     POWER_BR_PRED_W);
  m_POWER_RAS_R =
      new COUNT_Stat("POWER_RAS_R", "power_units.stat.out", POWER_RAS_R);
  m_POWER_RAS_W =
      new COUNT_Stat("POWER_RAS_W", "power_units.stat.out", POWER_RAS_W);
  m_POWER_ICACHE_R =
      new COUNT_Stat("POWER_ICACHE_R", "power_units.stat.out", POWER_ICACHE_R);
  m_POWER_ICACHE_W =
      new COUNT_Stat("POWER_ICACHE_W", "power_units.stat.out", POWER_ICACHE_W);
  m_POWER_ICACHE_R_TAG = new COUNT_Stat(
      "POWER_ICACHE_R_TAG", "power_units.stat.out", POWER_ICACHE_R_TAG);
  m_POWER_ICACHE_MISS_BUF_R =
      new COUNT_Stat("POWER_ICACHE_MISS_BUF_R", "power_units.stat.out",
                     POWER_ICACHE_MISS_BUF_R);
  m_POWER_ICACHE_MISS_BUF_W =
      new COUNT_Stat("POWER_ICACHE_MISS_BUF_W", "power_units.stat.out",
                     POWER_ICACHE_MISS_BUF_W);
  m_POWER_ICACHE_MISS_BUF_R_TAG =
      new COUNT_Stat("POWER_ICACHE_MISS_BUF_R_TAG", "power_units.stat.out",
                     POWER_ICACHE_MISS_BUF_R_TAG);
  m_POWER_ICACHE_MISS_BUF_W_TAG =
      new COUNT_Stat("POWER_ICACHE_MISS_BUF_W_TAG", "power_units.stat.out",
                     POWER_ICACHE_MISS_BUF_W_TAG);
  m_POWER_ICACHE_TOT_ACC = new COUNT_Stat(
      "POWER_ICACHE_TOT_ACC", "power_units.stat.out", POWER_ICACHE_TOT_ACC);
  m_POWER_ICACHE_CONF = new COUNT_Stat(
      "POWER_ICACHE_CONF", "power_units.stat.out", POWER_ICACHE_CONF);
  m_POWER_INST_DECODER_R = new COUNT_Stat(
      "POWER_INST_DECODER_R", "power_units.stat.out", POWER_INST_DECODER_R);
  m_POWER_INST_DECODER_W = new COUNT_Stat(
      "POWER_INST_DECODER_W", "power_units.stat.out", POWER_INST_DECODER_W);
  m_POWER_MICRO_OP_SEQ_R = new COUNT_Stat(
      "POWER_MICRO_OP_SEQ_R", "power_units.stat.out", POWER_MICRO_OP_SEQ_R);
  m_POWER_MICRO_OP_SEQ_W = new COUNT_Stat(
      "POWER_MICRO_OP_SEQ_W", "power_units.stat.out", POWER_MICRO_OP_SEQ_W);
  m_POWER_OPERAND_DECODER_R =
      new COUNT_Stat("POWER_OPERAND_DECODER_R", "power_units.stat.out",
                     POWER_OPERAND_DECODER_R);
  m_POWER_OPERAND_DECODER_W =
      new COUNT_Stat("POWER_OPERAND_DECODER_W", "power_units.stat.out",
                     POWER_OPERAND_DECODER_W);
  m_POWER_UOP_QUEUE_R = new COUNT_Stat(
      "POWER_UOP_QUEUE_R", "power_units.stat.out", POWER_UOP_QUEUE_R);
  m_POWER_UOP_QUEUE_W = new COUNT_Stat(
      "POWER_UOP_QUEUE_W", "power_units.stat.out", POWER_UOP_QUEUE_W);
  m_POWER_REG_RENAMING_TABLE_R =
      new COUNT_Stat("POWER_REG_RENAMING_TABLE_R", "power_units.stat.out",
                     POWER_REG_RENAMING_TABLE_R);
  m_POWER_REG_RENAMING_TABLE_W =
      new COUNT_Stat("POWER_REG_RENAMING_TABLE_W", "power_units.stat.out",
                     POWER_REG_RENAMING_TABLE_W);
  m_POWER_DEP_CHECK_LOGIC_R =
      new COUNT_Stat("POWER_DEP_CHECK_LOGIC_R", "power_units.stat.out",
                     POWER_DEP_CHECK_LOGIC_R);
  m_POWER_FREELIST_R = new COUNT_Stat("POWER_FREELIST_R",
                                      "power_units.stat.out", POWER_FREELIST_R);
  m_POWER_FREELIST_W = new COUNT_Stat("POWER_FREELIST_W",
                                      "power_units.stat.out", POWER_FREELIST_W);
  m_POWER_RESERVATION_STATION_R =
      new COUNT_Stat("POWER_RESERVATION_STATION_R", "power_units.stat.out",
                     POWER_RESERVATION_STATION_R);
  m_POWER_RESERVATION_STATION_W =
      new COUNT_Stat("POWER_RESERVATION_STATION_W", "power_units.stat.out",
                     POWER_RESERVATION_STATION_W);
  m_POWER_RESERVATION_STATION_R_TAG =
      new COUNT_Stat("POWER_RESERVATION_STATION_R_TAG", "power_units.stat.out",
                     POWER_RESERVATION_STATION_R_TAG);
  m_POWER_RESERVATION_STATION_W_TAG =
      new COUNT_Stat("POWER_RESERVATION_STATION_W_TAG", "power_units.stat.out",
                     POWER_RESERVATION_STATION_W_TAG);
  m_POWER_INST_ISSUE_SEL_LOGIC_R =
      new COUNT_Stat("POWER_INST_ISSUE_SEL_LOGIC_R", "power_units.stat.out",
                     POWER_INST_ISSUE_SEL_LOGIC_R);
  m_POWER_INST_ISSUE_SEL_LOGIC_W =
      new COUNT_Stat("POWER_INST_ISSUE_SEL_LOGIC_W", "power_units.stat.out",
                     POWER_INST_ISSUE_SEL_LOGIC_W);
  m_POWER_PAYLOAD_RAM_R = new COUNT_Stat(
      "POWER_PAYLOAD_RAM_R", "power_units.stat.out", POWER_PAYLOAD_RAM_R);
  m_POWER_PAYLOAD_RAM_W = new COUNT_Stat(
      "POWER_PAYLOAD_RAM_W", "power_units.stat.out", POWER_PAYLOAD_RAM_W);
  m_POWER_EX_ALU_R =
      new COUNT_Stat("POWER_EX_ALU_R", "power_units.stat.out", POWER_EX_ALU_R);
  m_POWER_EX_FPU_R =
      new COUNT_Stat("POWER_EX_FPU_R", "power_units.stat.out", POWER_EX_FPU_R);
  m_POWER_EX_MUL_R =
      new COUNT_Stat("POWER_EX_MUL_R", "power_units.stat.out", POWER_EX_MUL_R);
  m_POWER_EX_SFU_R =
      new COUNT_Stat("POWER_EX_SFU_R", "power_units.stat.out", POWER_EX_SFU_R);
  m_POWER_REORDER_BUF_R = new COUNT_Stat(
      "POWER_REORDER_BUF_R", "power_units.stat.out", POWER_REORDER_BUF_R);
  m_POWER_REORDER_BUF_W = new COUNT_Stat(
      "POWER_REORDER_BUF_W", "power_units.stat.out", POWER_REORDER_BUF_W);
  m_POWER_INST_COMMIT_SEL_LOGIC_R =
      new COUNT_Stat("POWER_INST_COMMIT_SEL_LOGIC_R", "power_units.stat.out",
                     POWER_INST_COMMIT_SEL_LOGIC_R);
  m_POWER_INST_COMMIT_SEL_LOGIC_W =
      new COUNT_Stat("POWER_INST_COMMIT_SEL_LOGIC_W", "power_units.stat.out",
                     POWER_INST_COMMIT_SEL_LOGIC_W);
  m_POWER_FP_RENAME_R = new COUNT_Stat(
      "POWER_FP_RENAME_R", "power_units.stat.out", POWER_FP_RENAME_R);
  m_POWER_FP_RENAME_W = new COUNT_Stat(
      "POWER_FP_RENAME_W", "power_units.stat.out", POWER_FP_RENAME_W);
  m_POWER_LOAD_QUEUE_R = new COUNT_Stat(
      "POWER_LOAD_QUEUE_R", "power_units.stat.out", POWER_LOAD_QUEUE_R);
  m_POWER_LOAD_QUEUE_W = new COUNT_Stat(
      "POWER_LOAD_QUEUE_W", "power_units.stat.out", POWER_LOAD_QUEUE_W);
  m_POWER_LOAD_QUEUE_R_TAG = new COUNT_Stat(
      "POWER_LOAD_QUEUE_R_TAG", "power_units.stat.out", POWER_LOAD_QUEUE_R_TAG);
  m_POWER_LOAD_QUEUE_W_TAG = new COUNT_Stat(
      "POWER_LOAD_QUEUE_W_TAG", "power_units.stat.out", POWER_LOAD_QUEUE_W_TAG);
  m_POWER_STORE_QUEUE_R = new COUNT_Stat(
      "POWER_STORE_QUEUE_R", "power_units.stat.out", POWER_STORE_QUEUE_R);
  m_POWER_STORE_QUEUE_W = new COUNT_Stat(
      "POWER_STORE_QUEUE_W", "power_units.stat.out", POWER_STORE_QUEUE_W);
  m_POWER_STORE_QUEUE_R_TAG =
      new COUNT_Stat("POWER_STORE_QUEUE_R_TAG", "power_units.stat.out",
                     POWER_STORE_QUEUE_R_TAG);
  m_POWER_STORE_QUEUE_W_TAG =
      new COUNT_Stat("POWER_STORE_QUEUE_W_TAG", "power_units.stat.out",
                     POWER_STORE_QUEUE_W_TAG);
  m_POWER_DATA_TLB_R = new COUNT_Stat("POWER_DATA_TLB_R",
                                      "power_units.stat.out", POWER_DATA_TLB_R);
  m_POWER_DATA_TLB_W = new COUNT_Stat("POWER_DATA_TLB_W",
                                      "power_units.stat.out", POWER_DATA_TLB_W);
  m_POWER_DATA_TLB_R_TAG = new COUNT_Stat(
      "POWER_DATA_TLB_R_TAG", "power_units.stat.out", POWER_DATA_TLB_R_TAG);
  m_POWER_DATA_TLB_W_TAG = new COUNT_Stat(
      "POWER_DATA_TLB_W_TAG", "power_units.stat.out", POWER_DATA_TLB_W_TAG);
  m_POWER_INT_REGFILE_R = new COUNT_Stat(
      "POWER_INT_REGFILE_R", "power_units.stat.out", POWER_INT_REGFILE_R);
  m_POWER_INT_REGFILE_W = new COUNT_Stat(
      "POWER_INT_REGFILE_W", "power_units.stat.out", POWER_INT_REGFILE_W);
  m_POWER_FP_REGFILE_R = new COUNT_Stat(
      "POWER_FP_REGFILE_R", "power_units.stat.out", POWER_FP_REGFILE_R);
  m_POWER_FP_REGFILE_W = new COUNT_Stat(
      "POWER_FP_REGFILE_W", "power_units.stat.out", POWER_FP_REGFILE_W);
  m_POWER_GP_REGISTER_R = new COUNT_Stat(
      "POWER_GP_REGISTER_R", "power_units.stat.out", POWER_GP_REGISTER_R);
  m_POWER_GP_REGISTER_W = new COUNT_Stat(
      "POWER_GP_REGISTER_W", "power_units.stat.out", POWER_GP_REGISTER_W);
  m_POWER_FP_REGISTER_R = new COUNT_Stat(
      "POWER_FP_REGISTER_R", "power_units.stat.out", POWER_FP_REGISTER_R);
  m_POWER_FP_REGISTER_W = new COUNT_Stat(
      "POWER_FP_REGISTER_W", "power_units.stat.out", POWER_FP_REGISTER_W);
  m_POWER_SEGMENT_REGISTER_R =
      new COUNT_Stat("POWER_SEGMENT_REGISTER_R", "power_units.stat.out",
                     POWER_SEGMENT_REGISTER_R);
  m_POWER_SEGMENT_REGISTER_W =
      new COUNT_Stat("POWER_SEGMENT_REGISTER_W", "power_units.stat.out",
                     POWER_SEGMENT_REGISTER_W);
  m_POWER_CONTROL_REGISTER_R =
      new COUNT_Stat("POWER_CONTROL_REGISTER_R", "power_units.stat.out",
                     POWER_CONTROL_REGISTER_R);
  m_POWER_CONTROL_REGISTER_W =
      new COUNT_Stat("POWER_CONTROL_REGISTER_W", "power_units.stat.out",
                     POWER_CONTROL_REGISTER_W);
  m_POWER_FLAG_REGISTER_R = new COUNT_Stat(
      "POWER_FLAG_REGISTER_R", "power_units.stat.out", POWER_FLAG_REGISTER_R);
  m_POWER_FLAG_REGISTER_W = new COUNT_Stat(
      "POWER_FLAG_REGISTER_W", "power_units.stat.out", POWER_FLAG_REGISTER_W);
  m_POWER_EXEC_BYPASS = new COUNT_Stat(
      "POWER_EXEC_BYPASS", "power_units.stat.out", POWER_EXEC_BYPASS);
  m_POWER_LOAD_BYPASS = new COUNT_Stat(
      "POWER_LOAD_BYPASS", "power_units.stat.out", POWER_LOAD_BYPASS);
  m_POWER_PIPELINE =
      new COUNT_Stat("POWER_PIPELINE", "power_units.stat.out", POWER_PIPELINE);
  m_POWER_DCACHE_MISS_BUF_R =
      new COUNT_Stat("POWER_DCACHE_MISS_BUF_R", "power_units.stat.out",
                     POWER_DCACHE_MISS_BUF_R);
  m_POWER_DCACHE_MISS_BUF_R_TAG =
      new COUNT_Stat("POWER_DCACHE_MISS_BUF_R_TAG", "power_units.stat.out",
                     POWER_DCACHE_MISS_BUF_R_TAG);
  m_POWER_DCACHE_MISS_BUF_W =
      new COUNT_Stat("POWER_DCACHE_MISS_BUF_W", "power_units.stat.out",
                     POWER_DCACHE_MISS_BUF_W);
  m_POWER_DCACHE_MISS_BUF_W_TAG =
      new COUNT_Stat("POWER_DCACHE_MISS_BUF_W_TAG", "power_units.stat.out",
                     POWER_DCACHE_MISS_BUF_W_TAG);
  m_POWER_DCACHE_LINEFILL_BUF_R =
      new COUNT_Stat("POWER_DCACHE_LINEFILL_BUF_R", "power_units.stat.out",
                     POWER_DCACHE_LINEFILL_BUF_R);
  m_POWER_L2CACHE_LINEFILL_BUF_R =
      new COUNT_Stat("POWER_L2CACHE_LINEFILL_BUF_R", "power_units.stat.out",
                     POWER_L2CACHE_LINEFILL_BUF_R);
  m_POWER_L3CACHE_LINEFILL_BUF_R =
      new COUNT_Stat("POWER_L3CACHE_LINEFILL_BUF_R", "power_units.stat.out",
                     POWER_L3CACHE_LINEFILL_BUF_R);
  m_POWER_DCACHE_LINEFILL_BUF_W =
      new COUNT_Stat("POWER_DCACHE_LINEFILL_BUF_W", "power_units.stat.out",
                     POWER_DCACHE_LINEFILL_BUF_W);
  m_POWER_L2CACHE_LINEFILL_BUF_W =
      new COUNT_Stat("POWER_L2CACHE_LINEFILL_BUF_W", "power_units.stat.out",
                     POWER_L2CACHE_LINEFILL_BUF_W);
  m_POWER_L3CACHE_LINEFILL_BUF_W =
      new COUNT_Stat("POWER_L3CACHE_LINEFILL_BUF_W", "power_units.stat.out",
                     POWER_L3CACHE_LINEFILL_BUF_W);
  m_POWER_DCACHE_LINEFILL_BUF_R_TAG =
      new COUNT_Stat("POWER_DCACHE_LINEFILL_BUF_R_TAG", "power_units.stat.out",
                     POWER_DCACHE_LINEFILL_BUF_R_TAG);
  m_POWER_L2CACHE_LINEFILL_BUF_R_TAG =
      new COUNT_Stat("POWER_L2CACHE_LINEFILL_BUF_R_TAG", "power_units.stat.out",
                     POWER_L2CACHE_LINEFILL_BUF_R_TAG);
  m_POWER_L3CACHE_LINEFILL_BUF_R_TAG =
      new COUNT_Stat("POWER_L3CACHE_LINEFILL_BUF_R_TAG", "power_units.stat.out",
                     POWER_L3CACHE_LINEFILL_BUF_R_TAG);
  m_POWER_DCACHE_LINEFILL_BUF_W_TAG =
      new COUNT_Stat("POWER_DCACHE_LINEFILL_BUF_W_TAG", "power_units.stat.out",
                     POWER_DCACHE_LINEFILL_BUF_W_TAG);
  m_POWER_DCACHE_WB_BUF_R = new COUNT_Stat(
      "POWER_DCACHE_WB_BUF_R", "power_units.stat.out", POWER_DCACHE_WB_BUF_R);
  m_POWER_L2CACHE_WB_BUF_R = new COUNT_Stat(
      "POWER_L2CACHE_WB_BUF_R", "power_units.stat.out", POWER_L2CACHE_WB_BUF_R);
  m_POWER_L3CACHE_WB_BUF_R = new COUNT_Stat(
      "POWER_L3CACHE_WB_BUF_R", "power_units.stat.out", POWER_L3CACHE_WB_BUF_R);
  m_POWER_DCACHE_WB_BUF_W = new COUNT_Stat(
      "POWER_DCACHE_WB_BUF_W", "power_units.stat.out", POWER_DCACHE_WB_BUF_W);
  m_POWER_L2CACHE_WB_BUF_W = new COUNT_Stat(
      "POWER_L2CACHE_WB_BUF_W", "power_units.stat.out", POWER_L2CACHE_WB_BUF_W);
  m_POWER_L3CACHE_WB_BUF_W = new COUNT_Stat(
      "POWER_L3CACHE_WB_BUF_W", "power_units.stat.out", POWER_L3CACHE_WB_BUF_W);
  m_POWER_DCACHE_WB_BUF_R_TAG =
      new COUNT_Stat("POWER_DCACHE_WB_BUF_R_TAG", "power_units.stat.out",
                     POWER_DCACHE_WB_BUF_R_TAG);
  m_POWER_L2CACHE_WB_BUF_R_TAG =
      new COUNT_Stat("POWER_L2CACHE_WB_BUF_R_TAG", "power_units.stat.out",
                     POWER_L2CACHE_WB_BUF_R_TAG);
  m_POWER_L3CACHE_WB_BUF_R_TAG =
      new COUNT_Stat("POWER_L3CACHE_WB_BUF_R_TAG", "power_units.stat.out",
                     POWER_L3CACHE_WB_BUF_R_TAG);
  m_POWER_DCACHE_WB_BUF_W_TAG =
      new COUNT_Stat("POWER_DCACHE_WB_BUF_W_TAG", "power_units.stat.out",
                     POWER_DCACHE_WB_BUF_W_TAG);
  m_POWER_DCACHE_R =
      new COUNT_Stat("POWER_DCACHE_R", "power_units.stat.out", POWER_DCACHE_R);
  m_POWER_L2CACHE_R = new COUNT_Stat("POWER_L2CACHE_R", "power_units.stat.out",
                                     POWER_L2CACHE_R);
  m_POWER_L3CACHE_R = new COUNT_Stat("POWER_L3CACHE_R", "power_units.stat.out",
                                     POWER_L3CACHE_R);
  m_POWER_DCACHE_W =
      new COUNT_Stat("POWER_DCACHE_W", "power_units.stat.out", POWER_DCACHE_W);
  m_POWER_L2CACHE_W = new COUNT_Stat("POWER_L2CACHE_W", "power_units.stat.out",
                                     POWER_L2CACHE_W);
  m_POWER_L3CACHE_W = new COUNT_Stat("POWER_L3CACHE_W", "power_units.stat.out",
                                     POWER_L3CACHE_W);
  m_POWER_DCACHE_R_TAG = new COUNT_Stat(
      "POWER_DCACHE_R_TAG", "power_units.stat.out", POWER_DCACHE_R_TAG);
  m_POWER_L2CACHE_R_TAG = new COUNT_Stat(
      "POWER_L2CACHE_R_TAG", "power_units.stat.out", POWER_L2CACHE_R_TAG);
  m_POWER_L3CACHE_R_TAG = new COUNT_Stat(
      "POWER_L3CACHE_R_TAG", "power_units.stat.out", POWER_L3CACHE_R_TAG);
  m_POWER_MC_R =
      new COUNT_Stat("POWER_MC_R", "power_units.stat.out", POWER_MC_R);
  m_POWER_MC_W =
      new COUNT_Stat("POWER_MC_W", "power_units.stat.out", POWER_MC_W);
  m_POWER_CONST_CACHE_R = new COUNT_Stat(
      "POWER_CONST_CACHE_R", "power_units.stat.out", POWER_CONST_CACHE_R);
  m_POWER_CONST_CACHE_W = new COUNT_Stat(
      "POWER_CONST_CACHE_W", "power_units.stat.out", POWER_CONST_CACHE_W);
  m_POWER_CONST_CACHE_R_TAG =
      new COUNT_Stat("POWER_CONST_CACHE_R_TAG", "power_units.stat.out",
                     POWER_CONST_CACHE_R_TAG);
  m_POWER_CONST_CACHE_W_TAG =
      new COUNT_Stat("POWER_CONST_CACHE_W_TAG", "power_units.stat.out",
                     POWER_CONST_CACHE_W_TAG);
  m_POWER_TEXTURE_CACHE_R = new COUNT_Stat(
      "POWER_TEXTURE_CACHE_R", "power_units.stat.out", POWER_TEXTURE_CACHE_R);
  m_POWER_TEXTURE_CACHE_W = new COUNT_Stat(
      "POWER_TEXTURE_CACHE_W", "power_units.stat.out", POWER_TEXTURE_CACHE_W);
  m_POWER_TEXTURE_CACHE_R_TAG =
      new COUNT_Stat("POWER_TEXTURE_CACHE_R_TAG", "power_units.stat.out",
                     POWER_TEXTURE_CACHE_R_TAG);
  m_POWER_TEXTURE_CACHE_W_TAG =
      new COUNT_Stat("POWER_TEXTURE_CACHE_W_TAG", "power_units.stat.out",
                     POWER_TEXTURE_CACHE_W_TAG);
  m_POWER_SHARED_MEM_R = new COUNT_Stat(
      "POWER_SHARED_MEM_R", "power_units.stat.out", POWER_SHARED_MEM_R);
  m_POWER_SHARED_MEM_W = new COUNT_Stat(
      "POWER_SHARED_MEM_W", "power_units.stat.out", POWER_SHARED_MEM_W);
  m_POWER_SHARED_MEM_R_TAG = new COUNT_Stat(
      "POWER_SHARED_MEM_R_TAG", "power_units.stat.out", POWER_SHARED_MEM_R_TAG);
  m_POWER_SHARED_MEM_W_TAG = new COUNT_Stat(
      "POWER_SHARED_MEM_W_TAG", "power_units.stat.out", POWER_SHARED_MEM_W_TAG);

  // ============= ../def/pref.stat.def =============
  m_DIST_PREF_ACC_1 =
      new DIST_Stat("PREF_ACC_1", "pref.stat.out", PREF_ACC_1, procStat);
  m_PREF_ACC_1 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_1", "pref.stat.out", PREF_ACC_1, PREF_ACC_1);
  m_PREF_ACC_2 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_2", "pref.stat.out", PREF_ACC_2, PREF_ACC_1);
  m_PREF_ACC_3 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_3", "pref.stat.out", PREF_ACC_3, PREF_ACC_1);
  m_PREF_ACC_4 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_4", "pref.stat.out", PREF_ACC_4, PREF_ACC_1);
  m_PREF_ACC_5 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_5", "pref.stat.out", PREF_ACC_5, PREF_ACC_1);
  m_PREF_ACC_6 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_6", "pref.stat.out", PREF_ACC_6, PREF_ACC_1);
  m_PREF_ACC_7 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_7", "pref.stat.out", PREF_ACC_7, PREF_ACC_1);
  m_PREF_ACC_8 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_8", "pref.stat.out", PREF_ACC_8, PREF_ACC_1);
  m_PREF_ACC_9 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_9", "pref.stat.out", PREF_ACC_9, PREF_ACC_1);
  m_PREF_ACC_10 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC_10", "pref.stat.out", PREF_ACC_10, PREF_ACC_1);
  m_DIST_PREF_TIMELY_1 =
      new DIST_Stat("PREF_TIMELY_1", "pref.stat.out", PREF_TIMELY_1, procStat);
  m_PREF_TIMELY_1 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_1", "pref.stat.out", PREF_TIMELY_1, PREF_TIMELY_1);
  m_PREF_TIMELY_2 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_2", "pref.stat.out", PREF_TIMELY_2, PREF_TIMELY_1);
  m_PREF_TIMELY_3 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_3", "pref.stat.out", PREF_TIMELY_3, PREF_TIMELY_1);
  m_PREF_TIMELY_4 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_4", "pref.stat.out", PREF_TIMELY_4, PREF_TIMELY_1);
  m_PREF_TIMELY_5 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_5", "pref.stat.out", PREF_TIMELY_5, PREF_TIMELY_1);
  m_PREF_TIMELY_6 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_6", "pref.stat.out", PREF_TIMELY_6, PREF_TIMELY_1);
  m_PREF_TIMELY_7 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_7", "pref.stat.out", PREF_TIMELY_7, PREF_TIMELY_1);
  m_PREF_TIMELY_8 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_8", "pref.stat.out", PREF_TIMELY_8, PREF_TIMELY_1);
  m_PREF_TIMELY_9 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_9", "pref.stat.out", PREF_TIMELY_9, PREF_TIMELY_1);
  m_PREF_TIMELY_10 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_TIMELY_10", "pref.stat.out", PREF_TIMELY_10, PREF_TIMELY_1);
  m_DIST_PREF_POL_1 =
      new DIST_Stat("PREF_POL_1", "pref.stat.out", PREF_POL_1, procStat);
  m_PREF_POL_1 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_1", "pref.stat.out", PREF_POL_1, PREF_POL_1);
  m_PREF_POL_2 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_2", "pref.stat.out", PREF_POL_2, PREF_POL_1);
  m_PREF_POL_3 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_3", "pref.stat.out", PREF_POL_3, PREF_POL_1);
  m_PREF_POL_4 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_4", "pref.stat.out", PREF_POL_4, PREF_POL_1);
  m_PREF_POL_5 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_5", "pref.stat.out", PREF_POL_5, PREF_POL_1);
  m_PREF_POL_6 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_6", "pref.stat.out", PREF_POL_6, PREF_POL_1);
  m_PREF_POL_7 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_7", "pref.stat.out", PREF_POL_7, PREF_POL_1);
  m_PREF_POL_8 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_8", "pref.stat.out", PREF_POL_8, PREF_POL_1);
  m_PREF_POL_9 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_9", "pref.stat.out", PREF_POL_9, PREF_POL_1);
  m_PREF_POL_10 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_POL_10", "pref.stat.out", PREF_POL_10, PREF_POL_1);
  m_DIST_PREF_ACC1_HT_HP = new DIST_Stat("PREF_ACC1_HT_HP", "pref.stat.out",
                                         PREF_ACC1_HT_HP, procStat);
  m_PREF_ACC1_HT_HP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC1_HT_HP", "pref.stat.out", PREF_ACC1_HT_HP, PREF_ACC1_HT_HP);
  m_PREF_ACC1_HT_LP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC1_HT_LP", "pref.stat.out", PREF_ACC1_HT_LP, PREF_ACC1_HT_HP);
  m_PREF_ACC1_LT_HP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC1_LT_HP", "pref.stat.out", PREF_ACC1_LT_HP, PREF_ACC1_HT_HP);
  m_PREF_ACC1_LT_LP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC1_LT_LP", "pref.stat.out", PREF_ACC1_LT_LP, PREF_ACC1_HT_HP);
  m_PREF_ACC2_HT_HP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC2_HT_HP", "pref.stat.out", PREF_ACC2_HT_HP, PREF_ACC1_HT_HP);
  m_PREF_ACC2_HT_LP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC2_HT_LP", "pref.stat.out", PREF_ACC2_HT_LP, PREF_ACC1_HT_HP);
  m_PREF_ACC2_LT_HP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC2_LT_HP", "pref.stat.out", PREF_ACC2_LT_HP, PREF_ACC1_HT_HP);
  m_PREF_ACC2_LT_LP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC2_LT_LP", "pref.stat.out", PREF_ACC2_LT_LP, PREF_ACC1_HT_HP);
  m_PREF_ACC3_HT_HP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC3_HT_HP", "pref.stat.out", PREF_ACC3_HT_HP, PREF_ACC1_HT_HP);
  m_PREF_ACC3_HT_LP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC3_HT_LP", "pref.stat.out", PREF_ACC3_HT_LP, PREF_ACC1_HT_HP);
  m_PREF_ACC3_LT_HP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC3_LT_HP", "pref.stat.out", PREF_ACC3_LT_HP, PREF_ACC1_HT_HP);
  m_PREF_ACC3_LT_LP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC3_LT_LP", "pref.stat.out", PREF_ACC3_LT_LP, PREF_ACC1_HT_HP);
  m_PREF_ACC4_HT_HP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC4_HT_HP", "pref.stat.out", PREF_ACC4_HT_HP, PREF_ACC1_HT_HP);
  m_PREF_ACC4_HT_LP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC4_HT_LP", "pref.stat.out", PREF_ACC4_HT_LP, PREF_ACC1_HT_HP);
  m_PREF_ACC4_LT_HP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC4_LT_HP", "pref.stat.out", PREF_ACC4_LT_HP, PREF_ACC1_HT_HP);
  m_PREF_ACC4_LT_LP = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_ACC4_LT_LP", "pref.stat.out", PREF_ACC4_LT_LP, PREF_ACC1_HT_HP);
  m_DIST_PREF_DISTANCE_1 = new DIST_Stat("PREF_DISTANCE_1", "pref.stat.out",
                                         PREF_DISTANCE_1, procStat);
  m_PREF_DISTANCE_1 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_DISTANCE_1", "pref.stat.out", PREF_DISTANCE_1, PREF_DISTANCE_1);
  m_PREF_DISTANCE_2 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_DISTANCE_2", "pref.stat.out", PREF_DISTANCE_2, PREF_DISTANCE_1);
  m_PREF_DISTANCE_3 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_DISTANCE_3", "pref.stat.out", PREF_DISTANCE_3, PREF_DISTANCE_1);
  m_PREF_DISTANCE_4 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_DISTANCE_4", "pref.stat.out", PREF_DISTANCE_4, PREF_DISTANCE_1);
  m_PREF_DISTANCE_5 = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_DISTANCE_5", "pref.stat.out", PREF_DISTANCE_5, PREF_DISTANCE_1);
  m_PREF_PFPOL = new COUNT_Stat("PREF_PFPOL", "pref.stat.out", PREF_PFPOL);
  m_PREF_DL0REQ_QUEUE_HIT_BY_DEMAND =
      new COUNT_Stat("PREF_DL0REQ_QUEUE_HIT_BY_DEMAND", "pref.stat.out",
                     PREF_DL0REQ_QUEUE_HIT_BY_DEMAND);
  m_PREF_UL2REQ_QUEUE_HIT_BY_DEMAND =
      new COUNT_Stat("PREF_UL2REQ_QUEUE_HIT_BY_DEMAND", "pref.stat.out",
                     PREF_UL2REQ_QUEUE_HIT_BY_DEMAND);
  m_PREF_DL0REQ_QUEUE_FULL = new COUNT_Stat(
      "PREF_DL0REQ_QUEUE_FULL", "pref.stat.out", PREF_DL0REQ_QUEUE_FULL);
  m_PREF_UL2REQ_QUEUE_FULL = new COUNT_Stat(
      "PREF_UL2REQ_QUEUE_FULL", "pref.stat.out", PREF_UL2REQ_QUEUE_FULL);
  m_PREF_UL2REQ_SEND_QUEUE_STALL =
      new COUNT_Stat("PREF_UL2REQ_SEND_QUEUE_STALL", "pref.stat.out",
                     PREF_UL2REQ_SEND_QUEUE_STALL);
  m_PREF_UL2REQ_QUEUE_MATCHED_REQ =
      new COUNT_Stat("PREF_UL2REQ_QUEUE_MATCHED_REQ", "pref.stat.out",
                     PREF_UL2REQ_QUEUE_MATCHED_REQ);
  m_PREF_DL0REQ_QUEUE_MATCHED_REQ =
      new COUNT_Stat("PREF_DL0REQ_QUEUE_MATCHED_REQ", "pref.stat.out",
                     PREF_DL0REQ_QUEUE_MATCHED_REQ);
  m_PREF_UL2REQ_QUEUE_SENTREQ = new COUNT_Stat(
      "PREF_UL2REQ_QUEUE_SENTREQ", "pref.stat.out", PREF_UL2REQ_QUEUE_SENTREQ);
  m_PREF_UNUSED_EVICT =
      new COUNT_Stat("PREF_UNUSED_EVICT", "pref.stat.out", PREF_UNUSED_EVICT);
  m_PREF_REGION_SENT =
      new COUNT_Stat("PREF_REGION_SENT", "pref.stat.out", PREF_REGION_SENT);
  m_PREF_REGION_USEFUL =
      new COUNT_Stat("PREF_REGION_USEFUL", "pref.stat.out", PREF_REGION_USEFUL);
  m_PREF_REGION_EVICT =
      new COUNT_Stat("PREF_REGION_EVICT", "pref.stat.out", PREF_REGION_EVICT);
  m_PREF_PHASE_OVERWRITE_PAGE = new COUNT_Stat(
      "PREF_PHASE_OVERWRITE_PAGE", "pref.stat.out", PREF_PHASE_OVERWRITE_PAGE);
  m_PREF_UPDATE_COUNT =
      new COUNT_Stat("PREF_UPDATE_COUNT", "pref.stat.out", PREF_UPDATE_COUNT);
  m_DIST_PREF_HYBRID_SEL_0 = new DIST_Stat("PREF_HYBRID_SEL_0", "pref.stat.out",
                                           PREF_HYBRID_SEL_0, procStat);
  m_PREF_HYBRID_SEL_0 =
      (COUNT_Stat *)new DISTMember_Stat("PREF_HYBRID_SEL_0", "pref.stat.out",
                                        PREF_HYBRID_SEL_0, PREF_HYBRID_SEL_0);
  m_PREF_HYBRID_SEL_1 =
      (COUNT_Stat *)new DISTMember_Stat("PREF_HYBRID_SEL_1", "pref.stat.out",
                                        PREF_HYBRID_SEL_1, PREF_HYBRID_SEL_0);
  m_PREF_HYBRID_SEL_2 =
      (COUNT_Stat *)new DISTMember_Stat("PREF_HYBRID_SEL_2", "pref.stat.out",
                                        PREF_HYBRID_SEL_2, PREF_HYBRID_SEL_0);
  m_PREF_HYBRID_SEL_3 =
      (COUNT_Stat *)new DISTMember_Stat("PREF_HYBRID_SEL_3", "pref.stat.out",
                                        PREF_HYBRID_SEL_3, PREF_HYBRID_SEL_0);
  m_PREF_HYBRID_SEL_4 =
      (COUNT_Stat *)new DISTMember_Stat("PREF_HYBRID_SEL_4", "pref.stat.out",
                                        PREF_HYBRID_SEL_4, PREF_HYBRID_SEL_0);
  m_PREF_HYBRID_SEL_5 =
      (COUNT_Stat *)new DISTMember_Stat("PREF_HYBRID_SEL_5", "pref.stat.out",
                                        PREF_HYBRID_SEL_5, PREF_HYBRID_SEL_0);
  m_PREF_HYBRID_SEL_6 =
      (COUNT_Stat *)new DISTMember_Stat("PREF_HYBRID_SEL_6", "pref.stat.out",
                                        PREF_HYBRID_SEL_6, PREF_HYBRID_SEL_0);

  // ============= ../def/stream.stat.def =============
  m_DCACHE_PREF_HIT =
      new COUNT_Stat("DCACHE_PREF_HIT", "stream.stat.out", DCACHE_PREF_HIT);
  m_DIST_IFETCH_WB_FIRST_SCHEDULE =
      new DIST_Stat("IFETCH_WB_FIRST_SCHEDULE", "stream.stat.out",
                    IFETCH_WB_FIRST_SCHEDULE, procStat);
  m_IFETCH_WB_FIRST_SCHEDULE = (COUNT_Stat *)new DISTMember_Stat(
      "IFETCH_WB_FIRST_SCHEDULE", "stream.stat.out", IFETCH_WB_FIRST_SCHEDULE,
      IFETCH_WB_FIRST_SCHEDULE);
  m_PREFETCH_LAST_SCHEDULE = (COUNT_Stat *)new DISTMember_Stat(
      "PREFETCH_LAST_SCHEDULE", "stream.stat.out", PREFETCH_LAST_SCHEDULE,
      IFETCH_WB_FIRST_SCHEDULE);
  m_DEMAND_PASS_PREF_SCHEDULE = (COUNT_Stat *)new DISTMember_Stat(
      "DEMAND_PASS_PREF_SCHEDULE", "stream.stat.out", DEMAND_PASS_PREF_SCHEDULE,
      IFETCH_WB_FIRST_SCHEDULE);
  m_DEMAND_PASS_LOW_OP_SCHEDULE = (COUNT_Stat *)new DISTMember_Stat(
      "DEMAND_PASS_LOW_OP_SCHEDULE", "stream.stat.out",
      DEMAND_PASS_LOW_OP_SCHEDULE, IFETCH_WB_FIRST_SCHEDULE);
  m_DEMAND_LAST_SCHEDULE = (COUNT_Stat *)new DISTMember_Stat(
      "DEMAND_LAST_SCHEDULE", "stream.stat.out", DEMAND_LAST_SCHEDULE,
      IFETCH_WB_FIRST_SCHEDULE);
  m_STREAM_BUFFER_REQ =
      new COUNT_Stat("STREAM_BUFFER_REQ", "stream.stat.out", STREAM_BUFFER_REQ);
  m_DIST_PREF_SEND_TO_MEM_REQ =
      new DIST_Stat("PREF_SEND_TO_MEM_REQ", "stream.stat.out",
                    PREF_SEND_TO_MEM_REQ, procStat);
  m_PREF_SEND_TO_MEM_REQ = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_SEND_TO_MEM_REQ", "stream.stat.out", PREF_SEND_TO_MEM_REQ,
      PREF_SEND_TO_MEM_REQ);
  m_PREF_SEND_TO_MEM_REQ_FAIL = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_SEND_TO_MEM_REQ_FAIL", "stream.stat.out", PREF_SEND_TO_MEM_REQ_FAIL,
      PREF_SEND_TO_MEM_REQ);
  m_DIST_HIT_TRAIN_STREAM = new DIST_Stat("HIT_TRAIN_STREAM", "stream.stat.out",
                                          HIT_TRAIN_STREAM, procStat);
  m_HIT_TRAIN_STREAM =
      (COUNT_Stat *)new DISTMember_Stat("HIT_TRAIN_STREAM", "stream.stat.out",
                                        HIT_TRAIN_STREAM, HIT_TRAIN_STREAM);
  m_MISS_TRAIN_STREAM =
      (COUNT_Stat *)new DISTMember_Stat("MISS_TRAIN_STREAM", "stream.stat.out",
                                        MISS_TRAIN_STREAM, HIT_TRAIN_STREAM);
  m_STREAM_TRAIN_CREATE = new COUNT_Stat(
      "STREAM_TRAIN_CREATE", "stream.stat.out", STREAM_TRAIN_CREATE);
  m_DIST_MEM_REQ_MISS_HWP_PREF_Q =
      new DIST_Stat("MEM_REQ_MISS_HWP_PREF_Q", "stream.stat.out",
                    MEM_REQ_MISS_HWP_PREF_Q, procStat);
  m_MEM_REQ_MISS_HWP_PREF_Q = (COUNT_Stat *)new DISTMember_Stat(
      "MEM_REQ_MISS_HWP_PREF_Q", "stream.stat.out", MEM_REQ_MISS_HWP_PREF_Q,
      MEM_REQ_MISS_HWP_PREF_Q);
  m_MEM_REQ_MISS_SW_PREF_Q = (COUNT_Stat *)new DISTMember_Stat(
      "MEM_REQ_MISS_SW_PREF_Q", "stream.stat.out", MEM_REQ_MISS_SW_PREF_Q,
      MEM_REQ_MISS_HWP_PREF_Q);
  m_MEM_REQ_MISS_IFETCH_Q = (COUNT_Stat *)new DISTMember_Stat(
      "MEM_REQ_MISS_IFETCH_Q", "stream.stat.out", MEM_REQ_MISS_IFETCH_Q,
      MEM_REQ_MISS_HWP_PREF_Q);
  m_MEM_REQ_MISS_DFETCH_Q = (COUNT_Stat *)new DISTMember_Stat(
      "MEM_REQ_MISS_DFETCH_Q", "stream.stat.out", MEM_REQ_MISS_DFETCH_Q,
      MEM_REQ_MISS_HWP_PREF_Q);
  m_MEM_REQ_MISS_DSTORE_Q = (COUNT_Stat *)new DISTMember_Stat(
      "MEM_REQ_MISS_DSTORE_Q", "stream.stat.out", MEM_REQ_MISS_DSTORE_Q,
      MEM_REQ_MISS_HWP_PREF_Q);
  m_MEM_REQ_MISS_DPRF_Q = (COUNT_Stat *)new DISTMember_Stat(
      "MEM_REQ_MISS_DPRF_Q", "stream.stat.out", MEM_REQ_MISS_DPRF_Q,
      MEM_REQ_MISS_HWP_PREF_Q);
  m_MEM_REQ_MISS_WB_Q = (COUNT_Stat *)new DISTMember_Stat(
      "MEM_REQ_MISS_WB_Q", "stream.stat.out", MEM_REQ_MISS_WB_Q,
      MEM_REQ_MISS_HWP_PREF_Q);
  m_DIST_PREF_HIT_BY_DEMAND_IFETCH =
      new DIST_Stat("PREF_HIT_BY_DEMAND_IFETCH", "stream.stat.out",
                    PREF_HIT_BY_DEMAND_IFETCH, procStat);
  m_PREF_HIT_BY_DEMAND_IFETCH = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_BY_DEMAND_IFETCH", "stream.stat.out", PREF_HIT_BY_DEMAND_IFETCH,
      PREF_HIT_BY_DEMAND_IFETCH);
  m_PREF_HIT_BY_DEMAND_DFETCH = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_BY_DEMAND_DFETCH", "stream.stat.out", PREF_HIT_BY_DEMAND_DFETCH,
      PREF_HIT_BY_DEMAND_IFETCH);
  m_PREF_HIT_BY_DEMAND_DSTORE = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_BY_DEMAND_DSTORE", "stream.stat.out", PREF_HIT_BY_DEMAND_DSTORE,
      PREF_HIT_BY_DEMAND_IFETCH);
  m_PREF_HIT_BY_DEMAND_IPREF = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_BY_DEMAND_IPREF", "stream.stat.out", PREF_HIT_BY_DEMAND_IPREF,
      PREF_HIT_BY_DEMAND_IFETCH);
  m_PREF_HIT_BY_DEMAND_DPRF = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_BY_DEMAND_DPRF", "stream.stat.out", PREF_HIT_BY_DEMAND_DPRF,
      PREF_HIT_BY_DEMAND_IFETCH);
  m_PREF_HIT_BY_DEMAND_WB = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_BY_DEMAND_WB", "stream.stat.out", PREF_HIT_BY_DEMAND_WB,
      PREF_HIT_BY_DEMAND_IFETCH);
  m_PREF_HIT_BY_PREF = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_BY_PREF", "stream.stat.out", PREF_HIT_BY_PREF,
      PREF_HIT_BY_DEMAND_IFETCH);
  m_DIST_PREF_HIT_DEMAND_IFETCH =
      new DIST_Stat("PREF_HIT_DEMAND_IFETCH", "stream.stat.out",
                    PREF_HIT_DEMAND_IFETCH, procStat);
  m_PREF_HIT_DEMAND_IFETCH = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_DEMAND_IFETCH", "stream.stat.out", PREF_HIT_DEMAND_IFETCH,
      PREF_HIT_DEMAND_IFETCH);
  m_PREF_HIT_DEMAND_DFETCH = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_DEMAND_DFETCH", "stream.stat.out", PREF_HIT_DEMAND_DFETCH,
      PREF_HIT_DEMAND_IFETCH);
  m_PREF_HIT_DEMAND_DSTORE = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_DEMAND_DSTORE", "stream.stat.out", PREF_HIT_DEMAND_DSTORE,
      PREF_HIT_DEMAND_IFETCH);
  m_PREF_HIT_DEMAND_IPREF = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_DEMAND_IPREF", "stream.stat.out", PREF_HIT_DEMAND_IPREF,
      PREF_HIT_DEMAND_IFETCH);
  m_PREF_HIT_DEMAND_DPRF = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_DEMAND_DPRF", "stream.stat.out", PREF_HIT_DEMAND_DPRF,
      PREF_HIT_DEMAND_IFETCH);
  m_PREF_HIT_DEMAND_WB = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_HIT_DEMAND_WB", "stream.stat.out", PREF_HIT_DEMAND_WB,
      PREF_HIT_DEMAND_IFETCH);
  m_DIST_PREF_L2_FILL =
      new DIST_Stat("PREF_L2_FILL", "stream.stat.out", PREF_L2_FILL, procStat);
  m_PREF_L2_FILL = (COUNT_Stat *)new DISTMember_Stat(
      "PREF_L2_FILL", "stream.stat.out", PREF_L2_FILL, PREF_L2_FILL);
  m_DEMAND_L2_FILL = (COUNT_Stat *)new DISTMember_Stat(
      "DEMAND_L2_FILL", "stream.stat.out", DEMAND_L2_FILL, PREF_L2_FILL);
  m_PREF_REQ_QUE_FULL =
      new COUNT_Stat("PREF_REQ_QUE_FULL", "stream.stat.out", PREF_REQ_QUE_FULL);
  m_STREAM_REQ_QUEUE_HIT_BY_DEMAND =
      new COUNT_Stat("STREAM_REQ_QUEUE_HIT_BY_DEMAND", "stream.stat.out",
                     STREAM_REQ_QUEUE_HIT_BY_DEMAND);
  m_L2HIT_STREAM_PREF_REQ_QUE_FULL =
      new COUNT_Stat("L2HIT_STREAM_PREF_REQ_QUE_FULL", "stream.stat.out",
                     L2HIT_STREAM_PREF_REQ_QUE_FULL);
  m_DIST_L2HIT_HIT_TRAIN_STREAM =
      new DIST_Stat("L2HIT_HIT_TRAIN_STREAM", "stream.stat.out",
                    L2HIT_HIT_TRAIN_STREAM, procStat);
  m_L2HIT_HIT_TRAIN_STREAM = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_HIT_TRAIN_STREAM", "stream.stat.out", L2HIT_HIT_TRAIN_STREAM,
      L2HIT_HIT_TRAIN_STREAM);
  m_L2HIT_MISS_TRAIN_STREAM = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_MISS_TRAIN_STREAM", "stream.stat.out", L2HIT_MISS_TRAIN_STREAM,
      L2HIT_HIT_TRAIN_STREAM);
  m_L2HIT_STREAM_TRAIN_CREATE =
      new COUNT_Stat("L2HIT_STREAM_TRAIN_CREATE", "stream.stat.out",
                     L2HIT_STREAM_TRAIN_CREATE);
  m_L2HIT_STREAM_BUFFER_REQ = new COUNT_Stat(
      "L2HIT_STREAM_BUFFER_REQ", "stream.stat.out", L2HIT_STREAM_BUFFER_REQ);
  m_DIST_L2HIT_STREAM_PREF_DCACHE_HIT =
      new DIST_Stat("L2HIT_STREAM_PREF_DCACHE_HIT", "stream.stat.out",
                    L2HIT_STREAM_PREF_DCACHE_HIT, procStat);
  m_L2HIT_STREAM_PREF_DCACHE_HIT = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_STREAM_PREF_DCACHE_HIT", "stream.stat.out",
      L2HIT_STREAM_PREF_DCACHE_HIT, L2HIT_STREAM_PREF_DCACHE_HIT);
  m_L2HIT_STREAM_PREF_DCACHE_INSERT = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_STREAM_PREF_DCACHE_INSERT", "stream.stat.out",
      L2HIT_STREAM_PREF_DCACHE_INSERT, L2HIT_STREAM_PREF_DCACHE_HIT);
  m_L2HIT_STREAM_L2_MISS = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_STREAM_L2_MISS", "stream.stat.out", L2HIT_STREAM_L2_MISS,
      L2HIT_STREAM_PREF_DCACHE_HIT);
  m_L2HIT_STREAM_DCACHE_PORT_FULL =
      new COUNT_Stat("L2HIT_STREAM_DCACHE_PORT_FULL", "stream.stat.out",
                     L2HIT_STREAM_DCACHE_PORT_FULL);
  m_L2HIT_STREAM_PREF_L2_PORT_FULL =
      new COUNT_Stat("L2HIT_STREAM_PREF_L2_PORT_FULL", "stream.stat.out",
                     L2HIT_STREAM_PREF_L2_PORT_FULL);
  m_DIST_L2HIT_TRAIN_HIT_DEMAND =
      new DIST_Stat("L2HIT_TRAIN_HIT_DEMAND", "stream.stat.out",
                    L2HIT_TRAIN_HIT_DEMAND, procStat);
  m_L2HIT_TRAIN_HIT_DEMAND = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_TRAIN_HIT_DEMAND", "stream.stat.out", L2HIT_TRAIN_HIT_DEMAND,
      L2HIT_TRAIN_HIT_DEMAND);
  m_L2HIT_TRAIN_MISS_REQ = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_TRAIN_MISS_REQ", "stream.stat.out", L2HIT_TRAIN_MISS_REQ,
      L2HIT_TRAIN_HIT_DEMAND);
  m_DIST_L2HIT_TRAIN_FILTER_MISS =
      new DIST_Stat("L2HIT_TRAIN_FILTER_MISS", "stream.stat.out",
                    L2HIT_TRAIN_FILTER_MISS, procStat);
  m_L2HIT_TRAIN_FILTER_MISS = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_TRAIN_FILTER_MISS", "stream.stat.out", L2HIT_TRAIN_FILTER_MISS,
      L2HIT_TRAIN_FILTER_MISS);
  m_L2HIT_TRAIN_FILTER_HIT = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_TRAIN_FILTER_HIT", "stream.stat.out", L2HIT_TRAIN_FILTER_HIT,
      L2HIT_TRAIN_FILTER_MISS);
  m_DIST_L2HIT_PREF_REQ_DCACHE_HIT =
      new DIST_Stat("L2HIT_PREF_REQ_DCACHE_HIT", "stream.stat.out",
                    L2HIT_PREF_REQ_DCACHE_HIT, procStat);
  m_L2HIT_PREF_REQ_DCACHE_HIT = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_PREF_REQ_DCACHE_HIT", "stream.stat.out", L2HIT_PREF_REQ_DCACHE_HIT,
      L2HIT_PREF_REQ_DCACHE_HIT);
  m_L2HIT_PREF_REQ_DCACHE_MISS = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_PREF_REQ_DCACHE_MISS", "stream.stat.out",
      L2HIT_PREF_REQ_DCACHE_MISS, L2HIT_PREF_REQ_DCACHE_HIT);
  m_DIST_L2HIT_L2SEND_Q_FULL = new DIST_Stat(
      "L2HIT_L2SEND_Q_FULL", "stream.stat.out", L2HIT_L2SEND_Q_FULL, procStat);
  m_L2HIT_L2SEND_Q_FULL = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_L2SEND_Q_FULL", "stream.stat.out", L2HIT_L2SEND_Q_FULL,
      L2HIT_L2SEND_Q_FULL);
  m_L2HIT_L2SEND_Q_ENTER = (COUNT_Stat *)new DISTMember_Stat(
      "L2HIT_L2SEND_Q_ENTER", "stream.stat.out", L2HIT_L2SEND_Q_ENTER,
      L2HIT_L2SEND_Q_FULL);
  m_L2HIT_MEM_REQ =
      new COUNT_Stat("L2HIT_MEM_REQ", "stream.stat.out", L2HIT_MEM_REQ);
  m_REMOVE_REDUNDANT_STREAM_STAT =
      new COUNT_Stat("REMOVE_REDUNDANT_STREAM_STAT", "stream.stat.out",
                     REMOVE_REDUNDANT_STREAM_STAT);
  m_REPLACE_OLD_STREAM = new COUNT_Stat("REPLACE_OLD_STREAM", "stream.stat.out",
                                        REPLACE_OLD_STREAM);
  m_REQ_SEND_QUEUE_STALL = new COUNT_Stat(
      "REQ_SEND_QUEUE_STALL", "stream.stat.out", REQ_SEND_QUEUE_STALL);
  m_DIST_STREAM_LENGTH_0 = new DIST_Stat("STREAM_LENGTH_0", "stream.stat.out",
                                         STREAM_LENGTH_0, procStat);
  m_STREAM_LENGTH_0 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_0", "stream.stat.out", STREAM_LENGTH_0, STREAM_LENGTH_0);
  m_STREAM_LENGTH_10 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_10", "stream.stat.out", STREAM_LENGTH_10, STREAM_LENGTH_0);
  m_STREAM_LENGTH_20 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_20", "stream.stat.out", STREAM_LENGTH_20, STREAM_LENGTH_0);
  m_STREAM_LENGTH_30 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_30", "stream.stat.out", STREAM_LENGTH_30, STREAM_LENGTH_0);
  m_STREAM_LENGTH_40 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_40", "stream.stat.out", STREAM_LENGTH_40, STREAM_LENGTH_0);
  m_STREAM_LENGTH_50 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_50", "stream.stat.out", STREAM_LENGTH_50, STREAM_LENGTH_0);
  m_STREAM_LENGTH_60 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_60", "stream.stat.out", STREAM_LENGTH_60, STREAM_LENGTH_0);
  m_STREAM_LENGTH_70 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_70", "stream.stat.out", STREAM_LENGTH_70, STREAM_LENGTH_0);
  m_STREAM_LENGTH_80 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_80", "stream.stat.out", STREAM_LENGTH_80, STREAM_LENGTH_0);
  m_STREAM_LENGTH_90 = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_90", "stream.stat.out", STREAM_LENGTH_90, STREAM_LENGTH_0);
  m_STREAM_LENGTH_100_P = (COUNT_Stat *)new DISTMember_Stat(
      "STREAM_LENGTH_100_P", "stream.stat.out", STREAM_LENGTH_100_P,
      STREAM_LENGTH_0);
  m_STREAM_ENTER_RA =
      new COUNT_Stat("STREAM_ENTER_RA", "stream.stat.out", STREAM_ENTER_RA);

  // ============= ../def/trace.stat.def =============
  m_TRACE_READ_COUNT =
      new COUNT_Stat("TRACE_READ_COUNT", "trace.stat.out", TRACE_READ_COUNT);
}

all_stats_c::~all_stats_c() {
  delete m_ALLOC_COUNT;
  delete m_DIST_BP_ON_PATH_CORRECT;
  delete m_BP_ON_PATH_CORRECT;
  delete m_BP_ON_PATH_MISPREDICT;
  delete m_BP_ON_PATH_MISFETCH;
  delete m_DIST_BP_OFF_PATH_CORRECT;
  delete m_BP_OFF_PATH_CORRECT;
  delete m_BP_OFF_PATH_MISPREDICT;
  delete m_BP_OFF_PATH_MISFETCH;
  delete m_BP_MISPRED_STALL;
  delete m_BP_RESOLVED;
  delete m_BP_REDIRECT_RESOLVED;
  delete m_PERFECT_TARGET_PRED;
  delete m_DIST_SCHED_FAILED_REASON_SUCCESS;
  delete m_SCHED_FAILED_REASON_SUCCESS;
  delete m_SCHED_FAILED_OPERANDS_NOT_READY;
  delete m_SCHED_FAILED_NO_PORTS;
  delete m_SCHED_FAILED_FENCE_ACTIVE;
  delete m_NUM_SAMPLES;
  delete m_NUM_ACTIVE_BLOCKS;
  delete m_NUM_ACTIVE_THREADS;
  delete m_NUM_SCHED_IDLE_CYCLE;
  delete m_NUM_NO_SCHED_CYCLE;
  delete m_DISPATCHED_INST;
  delete m_DISPATCH_WAIT;
  delete m_CORE_DISPATCHED_INST;
  delete m_CORE_DISPATCH_WAIT;
  delete m_CORE_CYCLES;
  delete m_CORE_SCHED_THREADS;
  delete m_NUM_NO_FETCH_CYCLES;
  delete m_CORE_NUM_NO_FETCH_CYCLES;
  delete m_CORE_NUM_NO_FETCH_CYCLES_WITH_READY_THREADS;
  delete m_CORE_NUM_FETCH_CYCLES;
  delete m_CORE_FETCH_DELTA;
  delete m_CORE_NUM_RETIRE_CYCLES;
  delete m_CORE_RETIRE_DELTA;
  delete m_AVG_CORE_IDLE_CYCLE;
  delete m_FENCE_PREF_REQ;
  delete m_FENCE_WAITING;
  delete m_DYN_FENCE_NUM;
  delete m_WB_ORDERING_STALL;
  delete m_WB_FULL;
  delete m_REEXEC_NUM;
  delete m_INV_MATCH_NUM;
  delete m_EARLY_PERM_NUM;
  delete m_PERM_MATCH_NUM;
  delete m_RETIRE_SPECLD_NUM;
  delete m_RETIRE_SPECST_NUM;
  delete m_FENCE_HEAD_ROB_WAIT;
  delete m_FENCE_TOT_CYCLES;
  delete m_FENCE_EXEC_CYCLES;
  delete m_STORE_RES;
  delete m_STORE_NUM;
  delete m_STORE_WB_FREE;
  delete m_DRAM_PRECHARGE;
  delete m_DRAM_ACTIVATE;
  delete m_DRAM_COLUMN;
  delete m_DRAM_AVG_LATENCY_BASE;
  delete m_DRAM_AVG_LATENCY;
  delete m_BANDWIDTH_TOT;
  delete m_DRAM_CHANNEL0_BANDWIDTH_SATURATED;
  delete m_DRAM_CHANNEL1_BANDWIDTH_SATURATED;
  delete m_DRAM_CHANNEL2_BANDWIDTH_SATURATED;
  delete m_DRAM_CHANNEL3_BANDWIDTH_SATURATED;
  delete m_DRAM_CHANNEL4_BANDWIDTH_SATURATED;
  delete m_DRAM_CHANNEL5_BANDWIDTH_SATURATED;
  delete m_DRAM_CHANNEL6_BANDWIDTH_SATURATED;
  delete m_DRAM_CHANNEL7_BANDWIDTH_SATURATED;
  delete m_DRAM_CHANNEL0_DBUS_IDLE;
  delete m_DRAM_CHANNEL1_DBUS_IDLE;
  delete m_DRAM_CHANNEL2_DBUS_IDLE;
  delete m_DRAM_CHANNEL3_DBUS_IDLE;
  delete m_DRAM_CHANNEL4_DBUS_IDLE;
  delete m_DRAM_CHANNEL5_DBUS_IDLE;
  delete m_DRAM_CHANNEL6_DBUS_IDLE;
  delete m_DRAM_CHANNEL7_DBUS_IDLE;
  delete m_INST_COUNT_TOT;
  delete m_INST_COUNT;
  delete m_UOP_COUNT_TOT;
  delete m_UOP_COUNT;
  delete m_CYC_COUNT_TOT;
  delete m_CYC_COUNT;
  delete m_EXE_TIME;
  delete m_NUM_REPEAT;
  delete m_DIST_FF_CYC_COUNT;
  delete m_FF_CYC_COUNT;
  delete m_NON_FF_CYC_COUNT;
  delete m_CYC_COUNT_X86;
  delete m_CYC_COUNT_PTX;
  delete m_AVG_BLOCK_EXE_CYCLE;
  delete m_AVG_BLOCK_EXE_CYCLE_BASE;
  delete m_PROGRESS_ERROR;
  delete m_FILE_OPEN_ERROR;
  delete m_NUM_THREAD;
  delete m_APPL_CYC_COUNT_BASE0;
  delete m_APPL_CYC_COUNT_BASE1;
  delete m_APPL_CYC_COUNT_BASE2;
  delete m_APPL_CYC_COUNT_BASE3;
  delete m_APPL_CYC_COUNT_BASE4;
  delete m_APPL_CYC_COUNT0;
  delete m_APPL_CYC_COUNT1;
  delete m_APPL_CYC_COUNT2;
  delete m_APPL_CYC_COUNT3;
  delete m_APPL_CYC_COUNT4;
  delete m_CPI_DELTA_BASE0;
  delete m_CPI_DELTA_BASE1;
  delete m_CPI_DELTA_BASE2;
  delete m_CPI_DELTA_BASE3;
  delete m_CPI_DELTA_BASE4;
  delete m_CPI_DELTA0;
  delete m_CPI_DELTA1;
  delete m_CPI_DELTA2;
  delete m_CPI_DELTA3;
  delete m_CPI_DELTA4;
  delete m_CYCLE_CPU;
  delete m_CYCLE_GPU;
  delete m_HMC_INST_COUNT_TOT;
  delete m_HMC_INST_COUNT;
  delete m_HMC_UOP_COUNT;
  delete m_HMC_REMOVE_INST_COUNT;
  delete m_HMC_REMOVE_INST_COUNT_TOT;
  delete m_HMC_FENCE_INST_COUNT;
  delete m_HMC_FENCE_INST_COUNT_TOT;
  delete m_HMC_ADD_OVERHEAD_COUNT;
  delete m_HMC_DEP_UOP_CYC_TOT;
  delete m_HMC_DEP_UOP_RETIRE_COUNT;
  delete m_HMC_INST_COUNT_CAS_equal_16B;
  delete m_HMC_INST_COUNT_CAS_zero_16B;
  delete m_HMC_INST_COUNT_CAS_greater_16B;
  delete m_HMC_INST_COUNT_CAS_less_16B;
  delete m_HMC_INST_COUNT_ADD_16B;
  delete m_HMC_INST_COUNT_ADD_8B;
  delete m_HMC_INST_COUNT_ADD_DUAL;
  delete m_HMC_INST_COUNT_SWAP;
  delete m_HMC_INST_COUNT_BIT_WR;
  delete m_HMC_INST_COUNT_AND;
  delete m_HMC_INST_COUNT_NAND;
  delete m_HMC_INST_COUNT_OR;
  delete m_HMC_INST_COUNT_XOR;
  delete m_HMC_INST_COUNT_FP_ADD;
  delete m_HMC_INST_COUNT_COMP_greater;
  delete m_HMC_INST_COUNT_COMP_less;
  delete m_HMC_INST_COUNT_COMP_equal;
  delete m_HMC_INST_COUNT_CANDIDATE;
  delete m_HMC_INST_COUNT_HOOK;
  delete m_HMC_INST_COUNT_UNHOOK;
  delete m_HMC_INST_COUNT_TRANS_BEG;
  delete m_HMC_INST_COUNT_TRANS_MID;
  delete m_HMC_INST_COUNT_TRANS_END;
  delete m_DIST_OP_CAT_XED_CATEGORY_INVALID;
  delete m_OP_CAT_XED_CATEGORY_INVALID;
  delete m_OP_CAT_XED_CATEGORY_3DNOW;
  delete m_OP_CAT_XED_CATEGORY_AES;
  delete m_OP_CAT_XED_CATEGORY_AVX;
  delete m_OP_CAT_XED_CATEGORY_AVX2;
  delete m_OP_CAT_XED_CATEGORY_AVX2GATHER;
  delete m_OP_CAT_XED_CATEGORY_BDW;
  delete m_OP_CAT_XED_CATEGORY_BINARY;
  delete m_OP_CAT_XED_CATEGORY_BITBYTE;
  delete m_OP_CAT_XED_CATEGORY_BMI1;
  delete m_OP_CAT_XED_CATEGORY_BMI2;
  delete m_OP_CAT_XED_CATEGORY_BROADCAST;
  delete m_OP_CAT_XED_CATEGORY_CALL;
  delete m_OP_CAT_XED_CATEGORY_CMOV;
  delete m_OP_CAT_XED_CATEGORY_COND_BR;
  delete m_OP_CAT_XED_CATEGORY_CONVERT;
  delete m_OP_CAT_XED_CATEGORY_DATAXFER;
  delete m_OP_CAT_XED_CATEGORY_DECIMAL;
  delete m_OP_CAT_XED_CATEGORY_FCMOV;
  delete m_OP_CAT_XED_CATEGORY_FLAGOP;
  delete m_OP_CAT_XED_CATEGORY_FMA4;
  delete m_OP_CAT_XED_CATEGORY_INTERRUPT;
  delete m_OP_CAT_XED_CATEGORY_IO;
  delete m_OP_CAT_XED_CATEGORY_IOSTRINGOP;
  delete m_OP_CAT_XED_CATEGORY_LOGICAL;
  delete m_OP_CAT_XED_CATEGORY_LZCNT;
  delete m_OP_CAT_XED_CATEGORY_MISC;
  delete m_OP_CAT_XED_CATEGORY_MMX;
  delete m_OP_CAT_XED_CATEGORY_NOP;
  delete m_OP_CAT_XED_CATEGORY_PCLMULQDQ;
  delete m_OP_CAT_XED_CATEGORY_POP;
  delete m_OP_CAT_XED_CATEGORY_PREFETCH;
  delete m_OP_CAT_XED_CATEGORY_PUSH;
  delete m_OP_CAT_XED_CATEGORY_RDRAND;
  delete m_OP_CAT_XED_CATEGORY_RDSEED;
  delete m_OP_CAT_XED_CATEGORY_RDWRFSGS;
  delete m_OP_CAT_XED_CATEGORY_RET;
  delete m_OP_CAT_XED_CATEGORY_ROTATE;
  delete m_OP_CAT_XED_CATEGORY_SEGOP;
  delete m_OP_CAT_XED_CATEGORY_SEMAPHORE;
  delete m_OP_CAT_XED_CATEGORY_SHIFT;
  delete m_OP_CAT_XED_CATEGORY_SSE;
  delete m_OP_CAT_XED_CATEGORY_STRINGOP;
  delete m_OP_CAT_XED_CATEGORY_STTNI;
  delete m_OP_CAT_XED_CATEGORY_SYSCALL;
  delete m_OP_CAT_XED_CATEGORY_SYSRET;
  delete m_OP_CAT_XED_CATEGORY_SYSTEM;
  delete m_OP_CAT_XED_CATEGORY_TBM;
  delete m_OP_CAT_XED_CATEGORY_UNCOND_BR;
  delete m_OP_CAT_XED_CATEGORY_VFMA;
  delete m_OP_CAT_XED_CATEGORY_VTX;
  delete m_OP_CAT_XED_CATEGORY_WIDENOP;
  delete m_OP_CAT_XED_CATEGORY_X87_ALU;
  delete m_OP_CAT_XED_CATEGORY_XOP;
  delete m_OP_CAT_XED_CATEGORY_XSAVE;
  delete m_OP_CAT_XED_CATEGORY_XSAVEOPT;
  delete m_OP_CAT_TR_MUL;
  delete m_OP_CAT_TR_DIV;
  delete m_OP_CAT_TR_FMUL;
  delete m_OP_CAT_TR_FDIV;
  delete m_OP_CAT_TR_NOP;
  delete m_OP_CAT_PREFETCH_NTA;
  delete m_OP_CAT_PREFETCH_T0;
  delete m_OP_CAT_PREFETCH_T1;
  delete m_OP_CAT_PREFETCH_T2;
  delete m_OP_CAT_GPU_EN;
  delete m_OP_CAT_GPU_INVALID;
  delete m_OP_CAT_GPU_ABS;
  delete m_OP_CAT_GPU_ABS64;
  delete m_OP_CAT_GPU_ADD;
  delete m_OP_CAT_GPU_ADD64;
  delete m_OP_CAT_GPU_ADDC;
  delete m_OP_CAT_GPU_AND;
  delete m_OP_CAT_GPU_AND64;
  delete m_OP_CAT_GPU_ATOM_GM;
  delete m_OP_CAT_GPU_ATOM_SM;
  delete m_OP_CAT_GPU_ATOM64_GM;
  delete m_OP_CAT_GPU_ATOM64_SM;
  delete m_OP_CAT_GPU_BAR_ARRIVE;
  delete m_OP_CAT_GPU_BAR_SYNC;
  delete m_OP_CAT_GPU_BAR_RED;
  delete m_OP_CAT_GPU_BFE;
  delete m_OP_CAT_GPU_BFE64;
  delete m_OP_CAT_GPU_BFI;
  delete m_OP_CAT_GPU_BFI64;
  delete m_OP_CAT_GPU_BFIND;
  delete m_OP_CAT_GPU_BFIND64;
  delete m_OP_CAT_GPU_BRA;
  delete m_OP_CAT_GPU_BREV;
  delete m_OP_CAT_GPU_BREV64;
  delete m_OP_CAT_GPU_BRKPT;
  delete m_OP_CAT_GPU_CALL;
  delete m_OP_CAT_GPU_CLZ;
  delete m_OP_CAT_GPU_CLZ64;
  delete m_OP_CAT_GPU_CNOT;
  delete m_OP_CAT_GPU_CNOT64;
  delete m_OP_CAT_GPU_COPYSIGN;
  delete m_OP_CAT_GPU_COPYSIGN64;
  delete m_OP_CAT_GPU_COS;
  delete m_OP_CAT_GPU_CVT;
  delete m_OP_CAT_GPU_CVT64;
  delete m_OP_CAT_GPU_CVTA;
  delete m_OP_CAT_GPU_CVTA64;
  delete m_OP_CAT_GPU_DIV;
  delete m_OP_CAT_GPU_DIV64;
  delete m_OP_CAT_GPU_EX2;
  delete m_OP_CAT_GPU_EXIT;
  delete m_OP_CAT_GPU_FMA;
  delete m_OP_CAT_GPU_FMA64;
  delete m_OP_CAT_GPU_ISSPACEP;
  delete m_OP_CAT_GPU_LD;
  delete m_OP_CAT_GPU_LD64;
  delete m_OP_CAT_GPU_LDU;
  delete m_OP_CAT_GPU_LDU64;
  delete m_OP_CAT_GPU_LG2;
  delete m_OP_CAT_GPU_MAD24;
  delete m_OP_CAT_GPU_MAD;
  delete m_OP_CAT_GPU_MAD64;
  delete m_OP_CAT_GPU_MADC;
  delete m_OP_CAT_GPU_MADC64;
  delete m_OP_CAT_GPU_MAX;
  delete m_OP_CAT_GPU_MAX64;
  delete m_OP_CAT_GPU_MEMBAR_CTA;
  delete m_OP_CAT_GPU_MEMBAR_GL;
  delete m_OP_CAT_GPU_MEMBAR_SYS;
  delete m_OP_CAT_GPU_MIN;
  delete m_OP_CAT_GPU_MIN64;
  delete m_OP_CAT_GPU_MOV;
  delete m_OP_CAT_GPU_MOV64;
  delete m_OP_CAT_GPU_MUL24;
  delete m_OP_CAT_GPU_MUL;
  delete m_OP_CAT_GPU_MUL64;
  delete m_OP_CAT_GPU_NEG;
  delete m_OP_CAT_GPU_NEG64;
  delete m_OP_CAT_GPU_NOT;
  delete m_OP_CAT_GPU_NOT64;
  delete m_OP_CAT_GPU_OR;
  delete m_OP_CAT_GPU_OR64;
  delete m_OP_CAT_GPU_PMEVENT;
  delete m_OP_CAT_GPU_POPC;
  delete m_OP_CAT_GPU_POPC64;
  delete m_OP_CAT_GPU_PREFETCH;
  delete m_OP_CAT_GPU_PREFETCHU;
  delete m_OP_CAT_GPU_PRMT;
  delete m_OP_CAT_GPU_RCP;
  delete m_OP_CAT_GPU_RCP64;
  delete m_OP_CAT_GPU_RED_GM;
  delete m_OP_CAT_GPU_RED_SM;
  delete m_OP_CAT_GPU_RED64_GM;
  delete m_OP_CAT_GPU_RED64_SM;
  delete m_OP_CAT_GPU_REM;
  delete m_OP_CAT_GPU_REM64;
  delete m_OP_CAT_GPU_RET;
  delete m_OP_CAT_GPU_RSQRT;
  delete m_OP_CAT_GPU_RSQRT64;
  delete m_OP_CAT_GPU_SAD;
  delete m_OP_CAT_GPU_SAD64;
  delete m_OP_CAT_GPU_SELP;
  delete m_OP_CAT_GPU_SELP64;
  delete m_OP_CAT_GPU_SET;
  delete m_OP_CAT_GPU_SET64;
  delete m_OP_CAT_GPU_SETP;
  delete m_OP_CAT_GPU_SETP64;
  delete m_OP_CAT_GPU_SHFL;
  delete m_OP_CAT_GPU_SHFL64;
  delete m_OP_CAT_GPU_SHL;
  delete m_OP_CAT_GPU_SHL64;
  delete m_OP_CAT_GPU_SHR;
  delete m_OP_CAT_GPU_SHR64;
  delete m_OP_CAT_GPU_SIN;
  delete m_OP_CAT_GPU_SLCT;
  delete m_OP_CAT_GPU_SLCT64;
  delete m_OP_CAT_GPU_SQRT;
  delete m_OP_CAT_GPU_SQRT64;
  delete m_OP_CAT_GPU_ST;
  delete m_OP_CAT_GPU_ST64;
  delete m_OP_CAT_GPU_SUB;
  delete m_OP_CAT_GPU_SUB64;
  delete m_OP_CAT_GPU_SUBC;
  delete m_OP_CAT_GPU_SULD;
  delete m_OP_CAT_GPU_SULD64;
  delete m_OP_CAT_GPU_SURED;
  delete m_OP_CAT_GPU_SURED64;
  delete m_OP_CAT_GPU_SUST;
  delete m_OP_CAT_GPU_SUST64;
  delete m_OP_CAT_GPU_SUQ;
  delete m_OP_CAT_GPU_TESTP;
  delete m_OP_CAT_GPU_TESTP64;
  delete m_OP_CAT_GPU_TEX;
  delete m_OP_CAT_GPU_TLD4;
  delete m_OP_CAT_GPU_TXQ;
  delete m_OP_CAT_GPU_TRAP;
  delete m_OP_CAT_GPU_VABSDIFF;
  delete m_OP_CAT_GPU_VADD;
  delete m_OP_CAT_GPU_VMAD;
  delete m_OP_CAT_GPU_VMAX;
  delete m_OP_CAT_GPU_VMIN;
  delete m_OP_CAT_GPU_VSET;
  delete m_OP_CAT_GPU_VSHL;
  delete m_OP_CAT_GPU_VSHR;
  delete m_OP_CAT_GPU_VSUB;
  delete m_OP_CAT_GPU_VOTE;
  delete m_OP_CAT_GPU_XOR;
  delete m_OP_CAT_GPU_XOR64;
  delete m_OP_CAT_GPU_RECONVERGE;
  delete m_OP_CAT_GPU_PHI;
  delete m_OP_CAT_GPU_MEM_LD_GM;
  delete m_OP_CAT_GPU_MEM_LD_LM;
  delete m_OP_CAT_GPU_MEM_LD_SM;
  delete m_OP_CAT_GPU_MEM_LD_CM;
  delete m_OP_CAT_GPU_MEM_LD_TM;
  delete m_OP_CAT_GPU_MEM_LD_PM;
  delete m_OP_CAT_GPU_MEM_LDU_GM;
  delete m_OP_CAT_GPU_MEM_ST_GM;
  delete m_OP_CAT_GPU_MEM_ST_LM;
  delete m_OP_CAT_GPU_MEM_ST_SM;
  delete m_OP_CAT_GPU_DATA_XFER_GM;
  delete m_OP_CAT_GPU_DATA_XFER_LM;
  delete m_OP_CAT_GPU_DATA_XFER_SM;
  delete m_FP_OPS_TOT;
  delete m_FP_OPS;
  delete m_AVG_MEMORY_LATENCY_BASE;
  delete m_AVG_MEMORY_LATENCY;
  delete m_MSHR_FULL;
  delete m_TOTAL_MEMORY;
  delete m_TOTAL_MEMORY_MERGE;
  delete m_TOTAL_WB;
  delete m_L1_WB;
  delete m_L2_WB;
  delete m_L3_WB;
  delete m_TOTAL_DRAM;
  delete m_TOTAL_DRAM_MERGE;
  delete m_L1_HIT_CPU;
  delete m_L1_HIT_GPU;
  delete m_L1_MISS_CPU;
  delete m_L1_MISS_GPU;
  delete m_L2_HIT_CPU;
  delete m_L2_HIT_GPU;
  delete m_L2_MISS_CPU;
  delete m_L2_MISS_GPU;
  delete m_L3_HIT_CPU;
  delete m_L3_HIT_GPU;
  delete m_L3_MISS_CPU;
  delete m_L3_MISS_GPU;
  delete m_L3_HIT_PROMOTION_CPU;
  delete m_L3_HIT_PROMOTION_GPU;
  delete m_DIST_ICACHE_HIT;
  delete m_ICACHE_HIT;
  delete m_ICACHE_MISS;
  delete m_FETCH_THREAD_SKIP_LD_WAIT;
  delete m_FETCH_THREAD_SKIP_BR_WAIT;
  delete m_FETCH_THREAD_SKIP_SCHED_WAIT;
  delete m_DIST_COAL_INST;
  delete m_COAL_INST;
  delete m_UNCOAL_INST;
  delete m_DIST_COAL_INST_SINGLE_TRANS;
  delete m_COAL_INST_SINGLE_TRANS;
  delete m_COAL_INST_MUL_TRANS;
  delete m_UNCOAL_INST_MUL_TRANS;
  delete m_DIST_SM_COAL_INST;
  delete m_SM_COAL_INST;
  delete m_CM_COAL_INST;
  delete m_TM_COAL_INST;
  delete m_DM_COAL_INST;
  delete m_DIST_SM_UNCOAL_INST;
  delete m_SM_UNCOAL_INST;
  delete m_CM_UNCOAL_INST;
  delete m_TM_UNCOAL_INST;
  delete m_DM_UNCOAL_INST;
  delete m_DIST_SM_COAL_INST_SINGLE_TRANS;
  delete m_SM_COAL_INST_SINGLE_TRANS;
  delete m_CM_COAL_INST_SINGLE_TRANS;
  delete m_TM_COAL_INST_SINGLE_TRANS;
  delete m_DM_COAL_INST_SINGLE_TRANS;
  delete m_DIST_SM_COAL_INST_MUL_TRANS;
  delete m_SM_COAL_INST_MUL_TRANS;
  delete m_CM_COAL_INST_MUL_TRANS;
  delete m_TM_COAL_INST_MUL_TRANS;
  delete m_DM_COAL_INST_MUL_TRANS;
  delete m_NUM_MUL_TRANS_CM_TM_DM_INST;
  delete m_NUM_MUL_TRANS_CM_TM_DM;
  delete m_CONST_CACHE_HIT;
  delete m_CONST_CACHE_MISS;
  delete m_CONST_CACHE_MISS_NO_EXECUTE;
  delete m_CONST_CACHE_ACCESS;
  delete m_TEXTURE_CACHE_HIT;
  delete m_TEXTURE_CACHE_MISS;
  delete m_TEXTURE_CACHE_NO_EXECUTE;
  delete m_TEXTURE_CACHE_ACCESS;
  delete m_SHARED_MEM_INST;
  delete m_SHARED_MEM_ACCESS;
  delete m_DIST_LD_NO_FORWARD;
  delete m_LD_NO_FORWARD;
  delete m_FORWARDED_LD;
  delete m_MEM_STALL_CYCLE;
  delete m_CACHE_BANK_BUSY;
  delete m_ICACHE_MISS_TOTAL;
  delete m_ICACHE_FILL;
  delete m_TOTAL_CAGE_PERIOD;
  delete m_TOTAL_CAGE_APPL0;
  delete m_TOTAL_CAGE_APPL1;
  delete m_TOTAL_CAGE_APPL2;
  delete m_TOTAL_CAGE_APPL3;
  delete m_TOTAL_CAGE_APPL4;
  delete m_ABIP_AVG_RATIO_BASE;
  delete m_ABIP_AVG_RATIO;
  delete m_NUM_WRITE_ACKS;
  delete m_NUM_WRITES;
  delete m_TOTAL_WRITE_ACKS;
  delete m_TOTAL_WRITES;
  delete m_NUM_PHYSICAL_PAGES;
  delete m_TOTAL_PACKET_CPU;
  delete m_TOTAL_PACKET_GPU;
  delete m_NOC_AVG_LATENCY_BASE;
  delete m_NOC_AVG_LATENCY_BASE_CPU;
  delete m_NOC_AVG_LATENCY_BASE_GPU;
  delete m_NOC_AVG_LATENCY;
  delete m_NOC_AVG_LATENCY_CPU;
  delete m_NOC_AVG_LATENCY_GPU;
  delete m_NOC_AVG_ACTIVE_PACKET_BASE;
  delete m_NOC_AVG_ACTIVE_PACKET_BASE_CPU;
  delete m_NOC_AVG_ACTIVE_PACKET_BASE_GPU;
  delete m_NOC_AVG_ACTIVE_PACKET;
  delete m_NOC_AVG_ACTIVE_PACKET_CPU;
  delete m_NOC_AVG_ACTIVE_PACKET_GPU;
  delete m_NOC_IDLE_CHANNEL;
  delete m_NOC_IDLE_CHANNEL_CPU;
  delete m_NOC_IDLE_CHANNEL_GPU;
  delete m_NOC_IDLE_CHANNEL_L3;
  delete m_NOC_IDLE_CHANNEL_MC;
  delete m_NOC_AVG_WAIT_IN_ROUTER_BASE;
  delete m_NOC_AVG_WAIT_IN_ROUTER_BASE_CPU;
  delete m_NOC_AVG_WAIT_IN_ROUTER_BASE_GPU;
  delete m_NOC_AVG_WAIT_IN_ROUTER_BASE_L3;
  delete m_NOC_AVG_WAIT_IN_ROUTER_BASE_MC;
  delete m_NOC_AVG_WAIT_IN_ROUTER;
  delete m_NOC_AVG_WAIT_IN_ROUTER_CPU;
  delete m_NOC_AVG_WAIT_IN_ROUTER_GPU;
  delete m_NOC_AVG_WAIT_IN_ROUTER_L3;
  delete m_NOC_AVG_WAIT_IN_ROUTER_MC;
  delete m_NOC_LINK_ACTIVE;
  delete m_POWER_BLOCK_STATES_R;
  delete m_POWER_BLOCK_STATES_W;
  delete m_POWER_FETCH_QUEUE_R;
  delete m_POWER_FETCH_QUEUE_W;
  delete m_POWER_INST_QUEUE_R;
  delete m_POWER_INST_QUEUE_W;
  delete m_POWER_BR_PRED_R;
  delete m_POWER_BR_PRED_W;
  delete m_POWER_RAS_R;
  delete m_POWER_RAS_W;
  delete m_POWER_ICACHE_R;
  delete m_POWER_ICACHE_W;
  delete m_POWER_ICACHE_R_TAG;
  delete m_POWER_ICACHE_MISS_BUF_R;
  delete m_POWER_ICACHE_MISS_BUF_W;
  delete m_POWER_ICACHE_MISS_BUF_R_TAG;
  delete m_POWER_ICACHE_MISS_BUF_W_TAG;
  delete m_POWER_ICACHE_TOT_ACC;
  delete m_POWER_ICACHE_CONF;
  delete m_POWER_INST_DECODER_R;
  delete m_POWER_INST_DECODER_W;
  delete m_POWER_MICRO_OP_SEQ_R;
  delete m_POWER_MICRO_OP_SEQ_W;
  delete m_POWER_OPERAND_DECODER_R;
  delete m_POWER_OPERAND_DECODER_W;
  delete m_POWER_UOP_QUEUE_R;
  delete m_POWER_UOP_QUEUE_W;
  delete m_POWER_REG_RENAMING_TABLE_R;
  delete m_POWER_REG_RENAMING_TABLE_W;
  delete m_POWER_DEP_CHECK_LOGIC_R;
  delete m_POWER_FREELIST_R;
  delete m_POWER_FREELIST_W;
  delete m_POWER_RESERVATION_STATION_R;
  delete m_POWER_RESERVATION_STATION_W;
  delete m_POWER_RESERVATION_STATION_R_TAG;
  delete m_POWER_RESERVATION_STATION_W_TAG;
  delete m_POWER_INST_ISSUE_SEL_LOGIC_R;
  delete m_POWER_INST_ISSUE_SEL_LOGIC_W;
  delete m_POWER_PAYLOAD_RAM_R;
  delete m_POWER_PAYLOAD_RAM_W;
  delete m_POWER_EX_ALU_R;
  delete m_POWER_EX_FPU_R;
  delete m_POWER_EX_MUL_R;
  delete m_POWER_EX_SFU_R;
  delete m_POWER_REORDER_BUF_R;
  delete m_POWER_REORDER_BUF_W;
  delete m_POWER_INST_COMMIT_SEL_LOGIC_R;
  delete m_POWER_INST_COMMIT_SEL_LOGIC_W;
  delete m_POWER_FP_RENAME_R;
  delete m_POWER_FP_RENAME_W;
  delete m_POWER_LOAD_QUEUE_R;
  delete m_POWER_LOAD_QUEUE_W;
  delete m_POWER_LOAD_QUEUE_R_TAG;
  delete m_POWER_LOAD_QUEUE_W_TAG;
  delete m_POWER_STORE_QUEUE_R;
  delete m_POWER_STORE_QUEUE_W;
  delete m_POWER_STORE_QUEUE_R_TAG;
  delete m_POWER_STORE_QUEUE_W_TAG;
  delete m_POWER_DATA_TLB_R;
  delete m_POWER_DATA_TLB_W;
  delete m_POWER_DATA_TLB_R_TAG;
  delete m_POWER_DATA_TLB_W_TAG;
  delete m_POWER_INT_REGFILE_R;
  delete m_POWER_INT_REGFILE_W;
  delete m_POWER_FP_REGFILE_R;
  delete m_POWER_FP_REGFILE_W;
  delete m_POWER_GP_REGISTER_R;
  delete m_POWER_GP_REGISTER_W;
  delete m_POWER_FP_REGISTER_R;
  delete m_POWER_FP_REGISTER_W;
  delete m_POWER_SEGMENT_REGISTER_R;
  delete m_POWER_SEGMENT_REGISTER_W;
  delete m_POWER_CONTROL_REGISTER_R;
  delete m_POWER_CONTROL_REGISTER_W;
  delete m_POWER_FLAG_REGISTER_R;
  delete m_POWER_FLAG_REGISTER_W;
  delete m_POWER_EXEC_BYPASS;
  delete m_POWER_LOAD_BYPASS;
  delete m_POWER_PIPELINE;
  delete m_POWER_DCACHE_MISS_BUF_R;
  delete m_POWER_DCACHE_MISS_BUF_R_TAG;
  delete m_POWER_DCACHE_MISS_BUF_W;
  delete m_POWER_DCACHE_MISS_BUF_W_TAG;
  delete m_POWER_DCACHE_LINEFILL_BUF_R;
  delete m_POWER_L2CACHE_LINEFILL_BUF_R;
  delete m_POWER_L3CACHE_LINEFILL_BUF_R;
  delete m_POWER_DCACHE_LINEFILL_BUF_W;
  delete m_POWER_L2CACHE_LINEFILL_BUF_W;
  delete m_POWER_L3CACHE_LINEFILL_BUF_W;
  delete m_POWER_DCACHE_LINEFILL_BUF_R_TAG;
  delete m_POWER_L2CACHE_LINEFILL_BUF_R_TAG;
  delete m_POWER_L3CACHE_LINEFILL_BUF_R_TAG;
  delete m_POWER_DCACHE_LINEFILL_BUF_W_TAG;
  delete m_POWER_DCACHE_WB_BUF_R;
  delete m_POWER_L2CACHE_WB_BUF_R;
  delete m_POWER_L3CACHE_WB_BUF_R;
  delete m_POWER_DCACHE_WB_BUF_W;
  delete m_POWER_L2CACHE_WB_BUF_W;
  delete m_POWER_L3CACHE_WB_BUF_W;
  delete m_POWER_DCACHE_WB_BUF_R_TAG;
  delete m_POWER_L2CACHE_WB_BUF_R_TAG;
  delete m_POWER_L3CACHE_WB_BUF_R_TAG;
  delete m_POWER_DCACHE_WB_BUF_W_TAG;
  delete m_POWER_DCACHE_R;
  delete m_POWER_L2CACHE_R;
  delete m_POWER_L3CACHE_R;
  delete m_POWER_DCACHE_W;
  delete m_POWER_L2CACHE_W;
  delete m_POWER_L3CACHE_W;
  delete m_POWER_DCACHE_R_TAG;
  delete m_POWER_L2CACHE_R_TAG;
  delete m_POWER_L3CACHE_R_TAG;
  delete m_POWER_MC_R;
  delete m_POWER_MC_W;
  delete m_POWER_CONST_CACHE_R;
  delete m_POWER_CONST_CACHE_W;
  delete m_POWER_CONST_CACHE_R_TAG;
  delete m_POWER_CONST_CACHE_W_TAG;
  delete m_POWER_TEXTURE_CACHE_R;
  delete m_POWER_TEXTURE_CACHE_W;
  delete m_POWER_TEXTURE_CACHE_R_TAG;
  delete m_POWER_TEXTURE_CACHE_W_TAG;
  delete m_POWER_SHARED_MEM_R;
  delete m_POWER_SHARED_MEM_W;
  delete m_POWER_SHARED_MEM_R_TAG;
  delete m_POWER_SHARED_MEM_W_TAG;
  delete m_DIST_PREF_ACC_1;
  delete m_PREF_ACC_1;
  delete m_PREF_ACC_2;
  delete m_PREF_ACC_3;
  delete m_PREF_ACC_4;
  delete m_PREF_ACC_5;
  delete m_PREF_ACC_6;
  delete m_PREF_ACC_7;
  delete m_PREF_ACC_8;
  delete m_PREF_ACC_9;
  delete m_PREF_ACC_10;
  delete m_DIST_PREF_TIMELY_1;
  delete m_PREF_TIMELY_1;
  delete m_PREF_TIMELY_2;
  delete m_PREF_TIMELY_3;
  delete m_PREF_TIMELY_4;
  delete m_PREF_TIMELY_5;
  delete m_PREF_TIMELY_6;
  delete m_PREF_TIMELY_7;
  delete m_PREF_TIMELY_8;
  delete m_PREF_TIMELY_9;
  delete m_PREF_TIMELY_10;
  delete m_DIST_PREF_POL_1;
  delete m_PREF_POL_1;
  delete m_PREF_POL_2;
  delete m_PREF_POL_3;
  delete m_PREF_POL_4;
  delete m_PREF_POL_5;
  delete m_PREF_POL_6;
  delete m_PREF_POL_7;
  delete m_PREF_POL_8;
  delete m_PREF_POL_9;
  delete m_PREF_POL_10;
  delete m_DIST_PREF_ACC1_HT_HP;
  delete m_PREF_ACC1_HT_HP;
  delete m_PREF_ACC1_HT_LP;
  delete m_PREF_ACC1_LT_HP;
  delete m_PREF_ACC1_LT_LP;
  delete m_PREF_ACC2_HT_HP;
  delete m_PREF_ACC2_HT_LP;
  delete m_PREF_ACC2_LT_HP;
  delete m_PREF_ACC2_LT_LP;
  delete m_PREF_ACC3_HT_HP;
  delete m_PREF_ACC3_HT_LP;
  delete m_PREF_ACC3_LT_HP;
  delete m_PREF_ACC3_LT_LP;
  delete m_PREF_ACC4_HT_HP;
  delete m_PREF_ACC4_HT_LP;
  delete m_PREF_ACC4_LT_HP;
  delete m_PREF_ACC4_LT_LP;
  delete m_DIST_PREF_DISTANCE_1;
  delete m_PREF_DISTANCE_1;
  delete m_PREF_DISTANCE_2;
  delete m_PREF_DISTANCE_3;
  delete m_PREF_DISTANCE_4;
  delete m_PREF_DISTANCE_5;
  delete m_PREF_PFPOL;
  delete m_PREF_DL0REQ_QUEUE_HIT_BY_DEMAND;
  delete m_PREF_UL2REQ_QUEUE_HIT_BY_DEMAND;
  delete m_PREF_DL0REQ_QUEUE_FULL;
  delete m_PREF_UL2REQ_QUEUE_FULL;
  delete m_PREF_UL2REQ_SEND_QUEUE_STALL;
  delete m_PREF_UL2REQ_QUEUE_MATCHED_REQ;
  delete m_PREF_DL0REQ_QUEUE_MATCHED_REQ;
  delete m_PREF_UL2REQ_QUEUE_SENTREQ;
  delete m_PREF_UNUSED_EVICT;
  delete m_PREF_REGION_SENT;
  delete m_PREF_REGION_USEFUL;
  delete m_PREF_REGION_EVICT;
  delete m_PREF_PHASE_OVERWRITE_PAGE;
  delete m_PREF_UPDATE_COUNT;
  delete m_DIST_PREF_HYBRID_SEL_0;
  delete m_PREF_HYBRID_SEL_0;
  delete m_PREF_HYBRID_SEL_1;
  delete m_PREF_HYBRID_SEL_2;
  delete m_PREF_HYBRID_SEL_3;
  delete m_PREF_HYBRID_SEL_4;
  delete m_PREF_HYBRID_SEL_5;
  delete m_PREF_HYBRID_SEL_6;
  delete m_DCACHE_PREF_HIT;
  delete m_DIST_IFETCH_WB_FIRST_SCHEDULE;
  delete m_IFETCH_WB_FIRST_SCHEDULE;
  delete m_PREFETCH_LAST_SCHEDULE;
  delete m_DEMAND_PASS_PREF_SCHEDULE;
  delete m_DEMAND_PASS_LOW_OP_SCHEDULE;
  delete m_DEMAND_LAST_SCHEDULE;
  delete m_STREAM_BUFFER_REQ;
  delete m_DIST_PREF_SEND_TO_MEM_REQ;
  delete m_PREF_SEND_TO_MEM_REQ;
  delete m_PREF_SEND_TO_MEM_REQ_FAIL;
  delete m_DIST_HIT_TRAIN_STREAM;
  delete m_HIT_TRAIN_STREAM;
  delete m_MISS_TRAIN_STREAM;
  delete m_STREAM_TRAIN_CREATE;
  delete m_DIST_MEM_REQ_MISS_HWP_PREF_Q;
  delete m_MEM_REQ_MISS_HWP_PREF_Q;
  delete m_MEM_REQ_MISS_SW_PREF_Q;
  delete m_MEM_REQ_MISS_IFETCH_Q;
  delete m_MEM_REQ_MISS_DFETCH_Q;
  delete m_MEM_REQ_MISS_DSTORE_Q;
  delete m_MEM_REQ_MISS_DPRF_Q;
  delete m_MEM_REQ_MISS_WB_Q;
  delete m_DIST_PREF_HIT_BY_DEMAND_IFETCH;
  delete m_PREF_HIT_BY_DEMAND_IFETCH;
  delete m_PREF_HIT_BY_DEMAND_DFETCH;
  delete m_PREF_HIT_BY_DEMAND_DSTORE;
  delete m_PREF_HIT_BY_DEMAND_IPREF;
  delete m_PREF_HIT_BY_DEMAND_DPRF;
  delete m_PREF_HIT_BY_DEMAND_WB;
  delete m_PREF_HIT_BY_PREF;
  delete m_DIST_PREF_HIT_DEMAND_IFETCH;
  delete m_PREF_HIT_DEMAND_IFETCH;
  delete m_PREF_HIT_DEMAND_DFETCH;
  delete m_PREF_HIT_DEMAND_DSTORE;
  delete m_PREF_HIT_DEMAND_IPREF;
  delete m_PREF_HIT_DEMAND_DPRF;
  delete m_PREF_HIT_DEMAND_WB;
  delete m_DIST_PREF_L2_FILL;
  delete m_PREF_L2_FILL;
  delete m_DEMAND_L2_FILL;
  delete m_PREF_REQ_QUE_FULL;
  delete m_STREAM_REQ_QUEUE_HIT_BY_DEMAND;
  delete m_L2HIT_STREAM_PREF_REQ_QUE_FULL;
  delete m_DIST_L2HIT_HIT_TRAIN_STREAM;
  delete m_L2HIT_HIT_TRAIN_STREAM;
  delete m_L2HIT_MISS_TRAIN_STREAM;
  delete m_L2HIT_STREAM_TRAIN_CREATE;
  delete m_L2HIT_STREAM_BUFFER_REQ;
  delete m_DIST_L2HIT_STREAM_PREF_DCACHE_HIT;
  delete m_L2HIT_STREAM_PREF_DCACHE_HIT;
  delete m_L2HIT_STREAM_PREF_DCACHE_INSERT;
  delete m_L2HIT_STREAM_L2_MISS;
  delete m_L2HIT_STREAM_DCACHE_PORT_FULL;
  delete m_L2HIT_STREAM_PREF_L2_PORT_FULL;
  delete m_DIST_L2HIT_TRAIN_HIT_DEMAND;
  delete m_L2HIT_TRAIN_HIT_DEMAND;
  delete m_L2HIT_TRAIN_MISS_REQ;
  delete m_DIST_L2HIT_TRAIN_FILTER_MISS;
  delete m_L2HIT_TRAIN_FILTER_MISS;
  delete m_L2HIT_TRAIN_FILTER_HIT;
  delete m_DIST_L2HIT_PREF_REQ_DCACHE_HIT;
  delete m_L2HIT_PREF_REQ_DCACHE_HIT;
  delete m_L2HIT_PREF_REQ_DCACHE_MISS;
  delete m_DIST_L2HIT_L2SEND_Q_FULL;
  delete m_L2HIT_L2SEND_Q_FULL;
  delete m_L2HIT_L2SEND_Q_ENTER;
  delete m_L2HIT_MEM_REQ;
  delete m_REMOVE_REDUNDANT_STREAM_STAT;
  delete m_REPLACE_OLD_STREAM;
  delete m_REQ_SEND_QUEUE_STALL;
  delete m_DIST_STREAM_LENGTH_0;
  delete m_STREAM_LENGTH_0;
  delete m_STREAM_LENGTH_10;
  delete m_STREAM_LENGTH_20;
  delete m_STREAM_LENGTH_30;
  delete m_STREAM_LENGTH_40;
  delete m_STREAM_LENGTH_50;
  delete m_STREAM_LENGTH_60;
  delete m_STREAM_LENGTH_70;
  delete m_STREAM_LENGTH_80;
  delete m_STREAM_LENGTH_90;
  delete m_STREAM_LENGTH_100_P;
  delete m_STREAM_ENTER_RA;
  delete m_TRACE_READ_COUNT;
}

void all_stats_c::initialize(ProcessorStatistics *m_ProcessorStats,
                             CoreStatistics *m_coreStatsTemplate) {
  m_ProcessorStats->globalStats()->addStatistic(m_ALLOC_COUNT);
  m_ProcessorStats->globalStats()->addStatistic(m_DISPATCHED_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_DISPATCH_WAIT);
  m_ProcessorStats->globalStats()->addStatistic(m_NUM_NO_FETCH_CYCLES);
  m_ProcessorStats->globalStats()->addStatistic(m_AVG_CORE_IDLE_CYCLE);
  m_ProcessorStats->globalStats()->addStatistic(m_REEXEC_NUM);
  m_ProcessorStats->globalStats()->addStatistic(m_INV_MATCH_NUM);
  m_ProcessorStats->globalStats()->addStatistic(m_EARLY_PERM_NUM);
  m_ProcessorStats->globalStats()->addStatistic(m_PERM_MATCH_NUM);
  m_ProcessorStats->globalStats()->addStatistic(m_RETIRE_SPECLD_NUM);
  m_ProcessorStats->globalStats()->addStatistic(m_RETIRE_SPECST_NUM);
  m_ProcessorStats->globalStats()->addStatistic(m_FENCE_HEAD_ROB_WAIT);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_PRECHARGE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_ACTIVATE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_COLUMN);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_AVG_LATENCY_BASE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_AVG_LATENCY);
  m_ProcessorStats->globalStats()->addStatistic(m_BANDWIDTH_TOT);
  m_ProcessorStats->globalStats()->addStatistic(
      m_DRAM_CHANNEL0_BANDWIDTH_SATURATED);
  m_ProcessorStats->globalStats()->addStatistic(
      m_DRAM_CHANNEL1_BANDWIDTH_SATURATED);
  m_ProcessorStats->globalStats()->addStatistic(
      m_DRAM_CHANNEL2_BANDWIDTH_SATURATED);
  m_ProcessorStats->globalStats()->addStatistic(
      m_DRAM_CHANNEL3_BANDWIDTH_SATURATED);
  m_ProcessorStats->globalStats()->addStatistic(
      m_DRAM_CHANNEL4_BANDWIDTH_SATURATED);
  m_ProcessorStats->globalStats()->addStatistic(
      m_DRAM_CHANNEL5_BANDWIDTH_SATURATED);
  m_ProcessorStats->globalStats()->addStatistic(
      m_DRAM_CHANNEL6_BANDWIDTH_SATURATED);
  m_ProcessorStats->globalStats()->addStatistic(
      m_DRAM_CHANNEL7_BANDWIDTH_SATURATED);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_CHANNEL0_DBUS_IDLE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_CHANNEL1_DBUS_IDLE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_CHANNEL2_DBUS_IDLE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_CHANNEL3_DBUS_IDLE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_CHANNEL4_DBUS_IDLE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_CHANNEL5_DBUS_IDLE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_CHANNEL6_DBUS_IDLE);
  m_ProcessorStats->globalStats()->addStatistic(m_DRAM_CHANNEL7_DBUS_IDLE);
  m_ProcessorStats->globalStats()->addStatistic(m_INST_COUNT_TOT);
  m_ProcessorStats->globalStats()->addStatistic(m_UOP_COUNT_TOT);
  m_ProcessorStats->globalStats()->addStatistic(m_CYC_COUNT_TOT);
  m_ProcessorStats->globalStats()->addStatistic(m_EXE_TIME);
  m_ProcessorStats->globalStats()->addStatistic(m_NUM_REPEAT);
  m_ProcessorStats->globalStats()->addStatistic(m_FF_CYC_COUNT);
  m_ProcessorStats->globalStats()->addStatistic(m_NON_FF_CYC_COUNT);
  m_ProcessorStats->globalStats()->addStatistic(m_CYC_COUNT_X86);
  m_ProcessorStats->globalStats()->addStatistic(m_CYC_COUNT_PTX);
  m_ProcessorStats->globalStats()->addStatistic(m_AVG_BLOCK_EXE_CYCLE);
  m_ProcessorStats->globalStats()->addStatistic(m_AVG_BLOCK_EXE_CYCLE_BASE);
  m_ProcessorStats->globalStats()->addStatistic(m_PROGRESS_ERROR);
  m_ProcessorStats->globalStats()->addStatistic(m_FILE_OPEN_ERROR);
  m_ProcessorStats->globalStats()->addStatistic(m_NUM_THREAD);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT_BASE0);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT_BASE1);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT_BASE2);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT_BASE3);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT_BASE4);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT0);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT1);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT2);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT3);
  m_ProcessorStats->globalStats()->addStatistic(m_APPL_CYC_COUNT4);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA_BASE0);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA_BASE1);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA_BASE2);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA_BASE3);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA_BASE4);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA0);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA1);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA2);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA3);
  m_ProcessorStats->globalStats()->addStatistic(m_CPI_DELTA4);
  m_ProcessorStats->globalStats()->addStatistic(m_CYCLE_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_CYCLE_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_HMC_INST_COUNT_TOT);
  m_ProcessorStats->globalStats()->addStatistic(m_HMC_REMOVE_INST_COUNT_TOT);
  m_ProcessorStats->globalStats()->addStatistic(m_HMC_FENCE_INST_COUNT_TOT);
  m_ProcessorStats->globalStats()->addStatistic(m_FP_OPS_TOT);
  m_ProcessorStats->globalStats()->addStatistic(m_AVG_MEMORY_LATENCY_BASE);
  m_ProcessorStats->globalStats()->addStatistic(m_AVG_MEMORY_LATENCY);
  m_ProcessorStats->globalStats()->addStatistic(m_MSHR_FULL);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_MEMORY);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_MEMORY_MERGE);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_WB);
  m_ProcessorStats->globalStats()->addStatistic(m_L1_WB);
  m_ProcessorStats->globalStats()->addStatistic(m_L2_WB);
  m_ProcessorStats->globalStats()->addStatistic(m_L3_WB);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_DRAM);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_DRAM_MERGE);
  m_ProcessorStats->globalStats()->addStatistic(m_L1_HIT_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L1_HIT_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L1_MISS_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L1_MISS_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L2_HIT_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L2_HIT_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L2_MISS_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L2_MISS_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L3_HIT_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L3_HIT_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L3_MISS_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L3_MISS_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L3_HIT_PROMOTION_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_L3_HIT_PROMOTION_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_FETCH_THREAD_SKIP_LD_WAIT);
  m_ProcessorStats->globalStats()->addStatistic(m_FETCH_THREAD_SKIP_BR_WAIT);
  m_ProcessorStats->globalStats()->addStatistic(m_FETCH_THREAD_SKIP_SCHED_WAIT);
  m_ProcessorStats->globalStats()->addStatistic(m_COAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_UNCOAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_COAL_INST_SINGLE_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_COAL_INST_MUL_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_UNCOAL_INST_MUL_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_SM_COAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_CM_COAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_TM_COAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_DM_COAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_SM_UNCOAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_CM_UNCOAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_TM_UNCOAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_DM_UNCOAL_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_SM_COAL_INST_SINGLE_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_CM_COAL_INST_SINGLE_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_TM_COAL_INST_SINGLE_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_DM_COAL_INST_SINGLE_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_SM_COAL_INST_MUL_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_CM_COAL_INST_MUL_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_TM_COAL_INST_MUL_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_DM_COAL_INST_MUL_TRANS);
  m_ProcessorStats->globalStats()->addStatistic(m_NUM_MUL_TRANS_CM_TM_DM_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_NUM_MUL_TRANS_CM_TM_DM);
  m_ProcessorStats->globalStats()->addStatistic(m_CONST_CACHE_HIT);
  m_ProcessorStats->globalStats()->addStatistic(m_CONST_CACHE_MISS);
  m_ProcessorStats->globalStats()->addStatistic(m_CONST_CACHE_MISS_NO_EXECUTE);
  m_ProcessorStats->globalStats()->addStatistic(m_CONST_CACHE_ACCESS);
  m_ProcessorStats->globalStats()->addStatistic(m_TEXTURE_CACHE_HIT);
  m_ProcessorStats->globalStats()->addStatistic(m_TEXTURE_CACHE_MISS);
  m_ProcessorStats->globalStats()->addStatistic(m_TEXTURE_CACHE_NO_EXECUTE);
  m_ProcessorStats->globalStats()->addStatistic(m_TEXTURE_CACHE_ACCESS);
  m_ProcessorStats->globalStats()->addStatistic(m_SHARED_MEM_INST);
  m_ProcessorStats->globalStats()->addStatistic(m_SHARED_MEM_ACCESS);
  m_ProcessorStats->globalStats()->addStatistic(m_LD_NO_FORWARD);
  m_ProcessorStats->globalStats()->addStatistic(m_FORWARDED_LD);
  m_ProcessorStats->globalStats()->addStatistic(m_CACHE_BANK_BUSY);
  m_ProcessorStats->globalStats()->addStatistic(m_ICACHE_MISS_TOTAL);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_CAGE_PERIOD);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_CAGE_APPL0);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_CAGE_APPL1);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_CAGE_APPL2);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_CAGE_APPL3);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_CAGE_APPL4);
  m_ProcessorStats->globalStats()->addStatistic(m_ABIP_AVG_RATIO_BASE);
  m_ProcessorStats->globalStats()->addStatistic(m_ABIP_AVG_RATIO);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_WRITE_ACKS);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_WRITES);
  m_ProcessorStats->globalStats()->addStatistic(m_NUM_PHYSICAL_PAGES);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_PACKET_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_TOTAL_PACKET_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_LATENCY_BASE);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_LATENCY_BASE_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_LATENCY_BASE_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_LATENCY);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_LATENCY_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_LATENCY_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_ACTIVE_PACKET_BASE);
  m_ProcessorStats->globalStats()->addStatistic(
      m_NOC_AVG_ACTIVE_PACKET_BASE_CPU);
  m_ProcessorStats->globalStats()->addStatistic(
      m_NOC_AVG_ACTIVE_PACKET_BASE_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_ACTIVE_PACKET);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_ACTIVE_PACKET_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_ACTIVE_PACKET_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_IDLE_CHANNEL);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_IDLE_CHANNEL_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_IDLE_CHANNEL_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_IDLE_CHANNEL_L3);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_IDLE_CHANNEL_MC);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_WAIT_IN_ROUTER_BASE);
  m_ProcessorStats->globalStats()->addStatistic(
      m_NOC_AVG_WAIT_IN_ROUTER_BASE_CPU);
  m_ProcessorStats->globalStats()->addStatistic(
      m_NOC_AVG_WAIT_IN_ROUTER_BASE_GPU);
  m_ProcessorStats->globalStats()->addStatistic(
      m_NOC_AVG_WAIT_IN_ROUTER_BASE_L3);
  m_ProcessorStats->globalStats()->addStatistic(
      m_NOC_AVG_WAIT_IN_ROUTER_BASE_MC);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_WAIT_IN_ROUTER);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_WAIT_IN_ROUTER_CPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_WAIT_IN_ROUTER_GPU);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_WAIT_IN_ROUTER_L3);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_AVG_WAIT_IN_ROUTER_MC);
  m_ProcessorStats->globalStats()->addStatistic(m_NOC_LINK_ACTIVE);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_L3CACHE_LINEFILL_BUF_R);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_L3CACHE_LINEFILL_BUF_W);
  m_ProcessorStats->globalStats()->addStatistic(
      m_POWER_L3CACHE_LINEFILL_BUF_R_TAG);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_L3CACHE_WB_BUF_R);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_L3CACHE_WB_BUF_W);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_L3CACHE_WB_BUF_R_TAG);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_L3CACHE_R);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_L3CACHE_W);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_L3CACHE_R_TAG);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_MC_R);
  m_ProcessorStats->globalStats()->addStatistic(m_POWER_MC_W);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_1);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_2);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_3);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_4);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_5);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_6);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_7);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_8);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_9);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC_10);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_1);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_2);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_3);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_4);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_5);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_6);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_7);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_8);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_9);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_TIMELY_10);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_1);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_2);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_3);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_4);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_5);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_6);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_7);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_8);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_9);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_POL_10);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC1_HT_HP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC1_HT_LP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC1_LT_HP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC1_LT_LP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC2_HT_HP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC2_HT_LP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC2_LT_HP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC2_LT_LP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC3_HT_HP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC3_HT_LP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC3_LT_HP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC3_LT_LP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC4_HT_HP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC4_HT_LP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC4_LT_HP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_ACC4_LT_LP);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_DISTANCE_1);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_DISTANCE_2);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_DISTANCE_3);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_DISTANCE_4);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_DISTANCE_5);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_PFPOL);
  m_ProcessorStats->globalStats()->addStatistic(
      m_PREF_DL0REQ_QUEUE_HIT_BY_DEMAND);
  m_ProcessorStats->globalStats()->addStatistic(
      m_PREF_UL2REQ_QUEUE_HIT_BY_DEMAND);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_DL0REQ_QUEUE_FULL);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_UL2REQ_QUEUE_FULL);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_UL2REQ_SEND_QUEUE_STALL);
  m_ProcessorStats->globalStats()->addStatistic(
      m_PREF_UL2REQ_QUEUE_MATCHED_REQ);
  m_ProcessorStats->globalStats()->addStatistic(
      m_PREF_DL0REQ_QUEUE_MATCHED_REQ);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_UL2REQ_QUEUE_SENTREQ);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_UNUSED_EVICT);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_REGION_SENT);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_REGION_USEFUL);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_REGION_EVICT);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_PHASE_OVERWRITE_PAGE);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_UPDATE_COUNT);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HYBRID_SEL_0);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HYBRID_SEL_1);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HYBRID_SEL_2);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HYBRID_SEL_3);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HYBRID_SEL_4);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HYBRID_SEL_5);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HYBRID_SEL_6);
  m_ProcessorStats->globalStats()->addStatistic(m_DCACHE_PREF_HIT);
  m_ProcessorStats->globalStats()->addStatistic(m_IFETCH_WB_FIRST_SCHEDULE);
  m_ProcessorStats->globalStats()->addStatistic(m_PREFETCH_LAST_SCHEDULE);
  m_ProcessorStats->globalStats()->addStatistic(m_DEMAND_PASS_PREF_SCHEDULE);
  m_ProcessorStats->globalStats()->addStatistic(m_DEMAND_PASS_LOW_OP_SCHEDULE);
  m_ProcessorStats->globalStats()->addStatistic(m_DEMAND_LAST_SCHEDULE);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_BUFFER_REQ);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_SEND_TO_MEM_REQ);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_SEND_TO_MEM_REQ_FAIL);
  m_ProcessorStats->globalStats()->addStatistic(m_HIT_TRAIN_STREAM);
  m_ProcessorStats->globalStats()->addStatistic(m_MISS_TRAIN_STREAM);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_TRAIN_CREATE);
  m_ProcessorStats->globalStats()->addStatistic(m_MEM_REQ_MISS_HWP_PREF_Q);
  m_ProcessorStats->globalStats()->addStatistic(m_MEM_REQ_MISS_SW_PREF_Q);
  m_ProcessorStats->globalStats()->addStatistic(m_MEM_REQ_MISS_IFETCH_Q);
  m_ProcessorStats->globalStats()->addStatistic(m_MEM_REQ_MISS_DFETCH_Q);
  m_ProcessorStats->globalStats()->addStatistic(m_MEM_REQ_MISS_DSTORE_Q);
  m_ProcessorStats->globalStats()->addStatistic(m_MEM_REQ_MISS_DPRF_Q);
  m_ProcessorStats->globalStats()->addStatistic(m_MEM_REQ_MISS_WB_Q);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_BY_DEMAND_IFETCH);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_BY_DEMAND_DFETCH);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_BY_DEMAND_DSTORE);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_BY_DEMAND_IPREF);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_BY_DEMAND_DPRF);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_BY_DEMAND_WB);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_BY_PREF);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_DEMAND_IFETCH);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_DEMAND_DFETCH);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_DEMAND_DSTORE);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_DEMAND_IPREF);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_DEMAND_DPRF);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_HIT_DEMAND_WB);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_L2_FILL);
  m_ProcessorStats->globalStats()->addStatistic(m_DEMAND_L2_FILL);
  m_ProcessorStats->globalStats()->addStatistic(m_PREF_REQ_QUE_FULL);
  m_ProcessorStats->globalStats()->addStatistic(
      m_STREAM_REQ_QUEUE_HIT_BY_DEMAND);
  m_ProcessorStats->globalStats()->addStatistic(
      m_L2HIT_STREAM_PREF_REQ_QUE_FULL);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_HIT_TRAIN_STREAM);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_MISS_TRAIN_STREAM);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_STREAM_TRAIN_CREATE);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_STREAM_BUFFER_REQ);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_STREAM_PREF_DCACHE_HIT);
  m_ProcessorStats->globalStats()->addStatistic(
      m_L2HIT_STREAM_PREF_DCACHE_INSERT);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_STREAM_L2_MISS);
  m_ProcessorStats->globalStats()->addStatistic(
      m_L2HIT_STREAM_DCACHE_PORT_FULL);
  m_ProcessorStats->globalStats()->addStatistic(
      m_L2HIT_STREAM_PREF_L2_PORT_FULL);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_TRAIN_HIT_DEMAND);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_TRAIN_MISS_REQ);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_TRAIN_FILTER_MISS);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_TRAIN_FILTER_HIT);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_PREF_REQ_DCACHE_HIT);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_PREF_REQ_DCACHE_MISS);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_L2SEND_Q_FULL);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_L2SEND_Q_ENTER);
  m_ProcessorStats->globalStats()->addStatistic(m_L2HIT_MEM_REQ);
  m_ProcessorStats->globalStats()->addStatistic(m_REMOVE_REDUNDANT_STREAM_STAT);
  m_ProcessorStats->globalStats()->addStatistic(m_REPLACE_OLD_STREAM);
  m_ProcessorStats->globalStats()->addStatistic(m_REQ_SEND_QUEUE_STALL);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_0);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_10);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_20);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_30);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_40);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_50);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_60);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_70);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_80);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_90);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_LENGTH_100_P);
  m_ProcessorStats->globalStats()->addStatistic(m_STREAM_ENTER_RA);
  m_ProcessorStats->globalStats()->addStatistic(m_TRACE_READ_COUNT);

  m_DIST_FF_CYC_COUNT->addMember(FF_CYC_COUNT);
  m_DIST_FF_CYC_COUNT->addMember(NON_FF_CYC_COUNT);
  m_DIST_COAL_INST->addMember(COAL_INST);
  m_DIST_COAL_INST->addMember(UNCOAL_INST);
  m_DIST_COAL_INST_SINGLE_TRANS->addMember(COAL_INST_SINGLE_TRANS);
  m_DIST_COAL_INST_SINGLE_TRANS->addMember(COAL_INST_MUL_TRANS);
  m_DIST_COAL_INST_SINGLE_TRANS->addMember(UNCOAL_INST_MUL_TRANS);
  m_DIST_SM_COAL_INST->addMember(SM_COAL_INST);
  m_DIST_SM_COAL_INST->addMember(CM_COAL_INST);
  m_DIST_SM_COAL_INST->addMember(TM_COAL_INST);
  m_DIST_SM_COAL_INST->addMember(DM_COAL_INST);
  m_DIST_SM_UNCOAL_INST->addMember(SM_UNCOAL_INST);
  m_DIST_SM_UNCOAL_INST->addMember(CM_UNCOAL_INST);
  m_DIST_SM_UNCOAL_INST->addMember(TM_UNCOAL_INST);
  m_DIST_SM_UNCOAL_INST->addMember(DM_UNCOAL_INST);
  m_DIST_SM_COAL_INST_SINGLE_TRANS->addMember(SM_COAL_INST_SINGLE_TRANS);
  m_DIST_SM_COAL_INST_SINGLE_TRANS->addMember(CM_COAL_INST_SINGLE_TRANS);
  m_DIST_SM_COAL_INST_SINGLE_TRANS->addMember(TM_COAL_INST_SINGLE_TRANS);
  m_DIST_SM_COAL_INST_SINGLE_TRANS->addMember(DM_COAL_INST_SINGLE_TRANS);
  m_DIST_SM_COAL_INST_MUL_TRANS->addMember(SM_COAL_INST_MUL_TRANS);
  m_DIST_SM_COAL_INST_MUL_TRANS->addMember(CM_COAL_INST_MUL_TRANS);
  m_DIST_SM_COAL_INST_MUL_TRANS->addMember(TM_COAL_INST_MUL_TRANS);
  m_DIST_SM_COAL_INST_MUL_TRANS->addMember(DM_COAL_INST_MUL_TRANS);
  m_DIST_LD_NO_FORWARD->addMember(LD_NO_FORWARD);
  m_DIST_LD_NO_FORWARD->addMember(FORWARDED_LD);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_1);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_2);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_3);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_4);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_5);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_6);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_7);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_8);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_9);
  m_DIST_PREF_ACC_1->addMember(PREF_ACC_10);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_1);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_2);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_3);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_4);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_5);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_6);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_7);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_8);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_9);
  m_DIST_PREF_TIMELY_1->addMember(PREF_TIMELY_10);
  m_DIST_PREF_POL_1->addMember(PREF_POL_1);
  m_DIST_PREF_POL_1->addMember(PREF_POL_2);
  m_DIST_PREF_POL_1->addMember(PREF_POL_3);
  m_DIST_PREF_POL_1->addMember(PREF_POL_4);
  m_DIST_PREF_POL_1->addMember(PREF_POL_5);
  m_DIST_PREF_POL_1->addMember(PREF_POL_6);
  m_DIST_PREF_POL_1->addMember(PREF_POL_7);
  m_DIST_PREF_POL_1->addMember(PREF_POL_8);
  m_DIST_PREF_POL_1->addMember(PREF_POL_9);
  m_DIST_PREF_POL_1->addMember(PREF_POL_10);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC1_HT_HP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC1_HT_LP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC1_LT_HP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC1_LT_LP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC2_HT_HP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC2_HT_LP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC2_LT_HP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC2_LT_LP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC3_HT_HP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC3_HT_LP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC3_LT_HP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC3_LT_LP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC4_HT_HP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC4_HT_LP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC4_LT_HP);
  m_DIST_PREF_ACC1_HT_HP->addMember(PREF_ACC4_LT_LP);
  m_DIST_PREF_DISTANCE_1->addMember(PREF_DISTANCE_1);
  m_DIST_PREF_DISTANCE_1->addMember(PREF_DISTANCE_2);
  m_DIST_PREF_DISTANCE_1->addMember(PREF_DISTANCE_3);
  m_DIST_PREF_DISTANCE_1->addMember(PREF_DISTANCE_4);
  m_DIST_PREF_DISTANCE_1->addMember(PREF_DISTANCE_5);
  m_DIST_PREF_HYBRID_SEL_0->addMember(PREF_HYBRID_SEL_0);
  m_DIST_PREF_HYBRID_SEL_0->addMember(PREF_HYBRID_SEL_1);
  m_DIST_PREF_HYBRID_SEL_0->addMember(PREF_HYBRID_SEL_2);
  m_DIST_PREF_HYBRID_SEL_0->addMember(PREF_HYBRID_SEL_3);
  m_DIST_PREF_HYBRID_SEL_0->addMember(PREF_HYBRID_SEL_4);
  m_DIST_PREF_HYBRID_SEL_0->addMember(PREF_HYBRID_SEL_5);
  m_DIST_PREF_HYBRID_SEL_0->addMember(PREF_HYBRID_SEL_6);
  m_DIST_IFETCH_WB_FIRST_SCHEDULE->addMember(IFETCH_WB_FIRST_SCHEDULE);
  m_DIST_IFETCH_WB_FIRST_SCHEDULE->addMember(PREFETCH_LAST_SCHEDULE);
  m_DIST_IFETCH_WB_FIRST_SCHEDULE->addMember(DEMAND_PASS_PREF_SCHEDULE);
  m_DIST_IFETCH_WB_FIRST_SCHEDULE->addMember(DEMAND_PASS_LOW_OP_SCHEDULE);
  m_DIST_IFETCH_WB_FIRST_SCHEDULE->addMember(DEMAND_LAST_SCHEDULE);
  m_DIST_PREF_SEND_TO_MEM_REQ->addMember(PREF_SEND_TO_MEM_REQ);
  m_DIST_PREF_SEND_TO_MEM_REQ->addMember(PREF_SEND_TO_MEM_REQ_FAIL);
  m_DIST_HIT_TRAIN_STREAM->addMember(HIT_TRAIN_STREAM);
  m_DIST_HIT_TRAIN_STREAM->addMember(MISS_TRAIN_STREAM);
  m_DIST_MEM_REQ_MISS_HWP_PREF_Q->addMember(MEM_REQ_MISS_HWP_PREF_Q);
  m_DIST_MEM_REQ_MISS_HWP_PREF_Q->addMember(MEM_REQ_MISS_SW_PREF_Q);
  m_DIST_MEM_REQ_MISS_HWP_PREF_Q->addMember(MEM_REQ_MISS_IFETCH_Q);
  m_DIST_MEM_REQ_MISS_HWP_PREF_Q->addMember(MEM_REQ_MISS_DFETCH_Q);
  m_DIST_MEM_REQ_MISS_HWP_PREF_Q->addMember(MEM_REQ_MISS_DSTORE_Q);
  m_DIST_MEM_REQ_MISS_HWP_PREF_Q->addMember(MEM_REQ_MISS_DPRF_Q);
  m_DIST_MEM_REQ_MISS_HWP_PREF_Q->addMember(MEM_REQ_MISS_WB_Q);
  m_DIST_PREF_HIT_BY_DEMAND_IFETCH->addMember(PREF_HIT_BY_DEMAND_IFETCH);
  m_DIST_PREF_HIT_BY_DEMAND_IFETCH->addMember(PREF_HIT_BY_DEMAND_DFETCH);
  m_DIST_PREF_HIT_BY_DEMAND_IFETCH->addMember(PREF_HIT_BY_DEMAND_DSTORE);
  m_DIST_PREF_HIT_BY_DEMAND_IFETCH->addMember(PREF_HIT_BY_DEMAND_IPREF);
  m_DIST_PREF_HIT_BY_DEMAND_IFETCH->addMember(PREF_HIT_BY_DEMAND_DPRF);
  m_DIST_PREF_HIT_BY_DEMAND_IFETCH->addMember(PREF_HIT_BY_DEMAND_WB);
  m_DIST_PREF_HIT_BY_DEMAND_IFETCH->addMember(PREF_HIT_BY_PREF);
  m_DIST_PREF_HIT_DEMAND_IFETCH->addMember(PREF_HIT_DEMAND_IFETCH);
  m_DIST_PREF_HIT_DEMAND_IFETCH->addMember(PREF_HIT_DEMAND_DFETCH);
  m_DIST_PREF_HIT_DEMAND_IFETCH->addMember(PREF_HIT_DEMAND_DSTORE);
  m_DIST_PREF_HIT_DEMAND_IFETCH->addMember(PREF_HIT_DEMAND_IPREF);
  m_DIST_PREF_HIT_DEMAND_IFETCH->addMember(PREF_HIT_DEMAND_DPRF);
  m_DIST_PREF_HIT_DEMAND_IFETCH->addMember(PREF_HIT_DEMAND_WB);
  m_DIST_PREF_L2_FILL->addMember(PREF_L2_FILL);
  m_DIST_PREF_L2_FILL->addMember(DEMAND_L2_FILL);
  m_DIST_L2HIT_HIT_TRAIN_STREAM->addMember(L2HIT_HIT_TRAIN_STREAM);
  m_DIST_L2HIT_HIT_TRAIN_STREAM->addMember(L2HIT_MISS_TRAIN_STREAM);
  m_DIST_L2HIT_STREAM_PREF_DCACHE_HIT->addMember(L2HIT_STREAM_PREF_DCACHE_HIT);
  m_DIST_L2HIT_STREAM_PREF_DCACHE_HIT->addMember(
      L2HIT_STREAM_PREF_DCACHE_INSERT);
  m_DIST_L2HIT_STREAM_PREF_DCACHE_HIT->addMember(L2HIT_STREAM_L2_MISS);
  m_DIST_L2HIT_TRAIN_HIT_DEMAND->addMember(L2HIT_TRAIN_HIT_DEMAND);
  m_DIST_L2HIT_TRAIN_HIT_DEMAND->addMember(L2HIT_TRAIN_MISS_REQ);
  m_DIST_L2HIT_TRAIN_FILTER_MISS->addMember(L2HIT_TRAIN_FILTER_MISS);
  m_DIST_L2HIT_TRAIN_FILTER_MISS->addMember(L2HIT_TRAIN_FILTER_HIT);
  m_DIST_L2HIT_PREF_REQ_DCACHE_HIT->addMember(L2HIT_PREF_REQ_DCACHE_HIT);
  m_DIST_L2HIT_PREF_REQ_DCACHE_HIT->addMember(L2HIT_PREF_REQ_DCACHE_MISS);
  m_DIST_L2HIT_L2SEND_Q_FULL->addMember(L2HIT_L2SEND_Q_FULL);
  m_DIST_L2HIT_L2SEND_Q_FULL->addMember(L2HIT_L2SEND_Q_ENTER);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_0);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_10);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_20);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_30);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_40);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_50);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_60);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_70);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_80);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_90);
  m_DIST_STREAM_LENGTH_0->addMember(STREAM_LENGTH_100_P);

  m_ProcessorStats->globalStats()->addDistribution(m_DIST_FF_CYC_COUNT);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_COAL_INST);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_COAL_INST_SINGLE_TRANS);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_SM_COAL_INST);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_SM_UNCOAL_INST);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_SM_COAL_INST_SINGLE_TRANS);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_SM_COAL_INST_MUL_TRANS);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_LD_NO_FORWARD);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_PREF_ACC_1);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_PREF_TIMELY_1);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_PREF_POL_1);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_PREF_ACC1_HT_HP);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_PREF_DISTANCE_1);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_PREF_HYBRID_SEL_0);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_IFETCH_WB_FIRST_SCHEDULE);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_PREF_SEND_TO_MEM_REQ);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_HIT_TRAIN_STREAM);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_MEM_REQ_MISS_HWP_PREF_Q);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_PREF_HIT_BY_DEMAND_IFETCH);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_PREF_HIT_DEMAND_IFETCH);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_PREF_L2_FILL);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_L2HIT_HIT_TRAIN_STREAM);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_L2HIT_STREAM_PREF_DCACHE_HIT);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_L2HIT_TRAIN_HIT_DEMAND);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_L2HIT_TRAIN_FILTER_MISS);
  m_ProcessorStats->globalStats()->addDistribution(
      m_DIST_L2HIT_PREF_REQ_DCACHE_HIT);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_L2HIT_L2SEND_Q_FULL);
  m_ProcessorStats->globalStats()->addDistribution(m_DIST_STREAM_LENGTH_0);

  m_coreStatsTemplate->addStatistic(m_BP_ON_PATH_CORRECT);
  m_coreStatsTemplate->addStatistic(m_BP_ON_PATH_MISPREDICT);
  m_coreStatsTemplate->addStatistic(m_BP_ON_PATH_MISFETCH);
  m_coreStatsTemplate->addStatistic(m_BP_OFF_PATH_CORRECT);
  m_coreStatsTemplate->addStatistic(m_BP_OFF_PATH_MISPREDICT);
  m_coreStatsTemplate->addStatistic(m_BP_OFF_PATH_MISFETCH);
  m_coreStatsTemplate->addStatistic(m_BP_MISPRED_STALL);
  m_coreStatsTemplate->addStatistic(m_BP_RESOLVED);
  m_coreStatsTemplate->addStatistic(m_BP_REDIRECT_RESOLVED);
  m_coreStatsTemplate->addStatistic(m_PERFECT_TARGET_PRED);
  m_coreStatsTemplate->addStatistic(m_SCHED_FAILED_REASON_SUCCESS);
  m_coreStatsTemplate->addStatistic(m_SCHED_FAILED_OPERANDS_NOT_READY);
  m_coreStatsTemplate->addStatistic(m_SCHED_FAILED_NO_PORTS);
  m_coreStatsTemplate->addStatistic(m_SCHED_FAILED_FENCE_ACTIVE);
  m_coreStatsTemplate->addStatistic(m_NUM_SAMPLES);
  m_coreStatsTemplate->addStatistic(m_NUM_ACTIVE_BLOCKS);
  m_coreStatsTemplate->addStatistic(m_NUM_ACTIVE_THREADS);
  m_coreStatsTemplate->addStatistic(m_NUM_SCHED_IDLE_CYCLE);
  m_coreStatsTemplate->addStatistic(m_NUM_NO_SCHED_CYCLE);
  m_coreStatsTemplate->addStatistic(m_CORE_DISPATCHED_INST);
  m_coreStatsTemplate->addStatistic(m_CORE_DISPATCH_WAIT);
  m_coreStatsTemplate->addStatistic(m_CORE_CYCLES);
  m_coreStatsTemplate->addStatistic(m_CORE_SCHED_THREADS);
  m_coreStatsTemplate->addStatistic(m_CORE_NUM_NO_FETCH_CYCLES);
  m_coreStatsTemplate->addStatistic(
      m_CORE_NUM_NO_FETCH_CYCLES_WITH_READY_THREADS);
  m_coreStatsTemplate->addStatistic(m_CORE_NUM_FETCH_CYCLES);
  m_coreStatsTemplate->addStatistic(m_CORE_FETCH_DELTA);
  m_coreStatsTemplate->addStatistic(m_CORE_NUM_RETIRE_CYCLES);
  m_coreStatsTemplate->addStatistic(m_CORE_RETIRE_DELTA);
  m_coreStatsTemplate->addStatistic(m_FENCE_PREF_REQ);
  m_coreStatsTemplate->addStatistic(m_FENCE_WAITING);
  m_coreStatsTemplate->addStatistic(m_DYN_FENCE_NUM);
  m_coreStatsTemplate->addStatistic(m_WB_ORDERING_STALL);
  m_coreStatsTemplate->addStatistic(m_WB_FULL);
  m_coreStatsTemplate->addStatistic(m_FENCE_TOT_CYCLES);
  m_coreStatsTemplate->addStatistic(m_FENCE_EXEC_CYCLES);
  m_coreStatsTemplate->addStatistic(m_STORE_RES);
  m_coreStatsTemplate->addStatistic(m_STORE_NUM);
  m_coreStatsTemplate->addStatistic(m_STORE_WB_FREE);
  m_coreStatsTemplate->addStatistic(m_INST_COUNT);
  m_coreStatsTemplate->addStatistic(m_UOP_COUNT);
  m_coreStatsTemplate->addStatistic(m_CYC_COUNT);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT);
  m_coreStatsTemplate->addStatistic(m_HMC_UOP_COUNT);
  m_coreStatsTemplate->addStatistic(m_HMC_REMOVE_INST_COUNT);
  m_coreStatsTemplate->addStatistic(m_HMC_FENCE_INST_COUNT);
  m_coreStatsTemplate->addStatistic(m_HMC_ADD_OVERHEAD_COUNT);
  m_coreStatsTemplate->addStatistic(m_HMC_DEP_UOP_CYC_TOT);
  m_coreStatsTemplate->addStatistic(m_HMC_DEP_UOP_RETIRE_COUNT);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_CAS_equal_16B);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_CAS_zero_16B);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_CAS_greater_16B);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_CAS_less_16B);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_ADD_16B);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_ADD_8B);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_ADD_DUAL);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_SWAP);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_BIT_WR);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_AND);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_NAND);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_OR);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_XOR);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_FP_ADD);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_COMP_greater);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_COMP_less);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_COMP_equal);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_CANDIDATE);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_HOOK);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_UNHOOK);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_TRANS_BEG);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_TRANS_MID);
  m_coreStatsTemplate->addStatistic(m_HMC_INST_COUNT_TRANS_END);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_INVALID);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_3DNOW);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_AES);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_AVX);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_AVX2);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_AVX2GATHER);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_BDW);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_BINARY);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_BITBYTE);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_BMI1);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_BMI2);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_BROADCAST);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_CALL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_CMOV);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_COND_BR);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_CONVERT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_DATAXFER);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_DECIMAL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_FCMOV);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_FLAGOP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_FMA4);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_INTERRUPT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_IO);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_IOSTRINGOP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_LOGICAL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_LZCNT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_MISC);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_MMX);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_NOP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_PCLMULQDQ);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_POP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_PREFETCH);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_PUSH);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_RDRAND);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_RDSEED);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_RDWRFSGS);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_RET);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_ROTATE);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_SEGOP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_SEMAPHORE);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_SHIFT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_SSE);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_STRINGOP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_STTNI);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_SYSCALL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_SYSRET);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_SYSTEM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_TBM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_UNCOND_BR);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_VFMA);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_VTX);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_WIDENOP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_X87_ALU);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_XOP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_XSAVE);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_XED_CATEGORY_XSAVEOPT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_TR_MUL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_TR_DIV);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_TR_FMUL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_TR_FDIV);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_TR_NOP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_PREFETCH_NTA);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_PREFETCH_T0);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_PREFETCH_T1);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_PREFETCH_T2);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_EN);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_INVALID);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ABS);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ABS64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ADD);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ADD64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ADDC);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_AND);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_AND64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ATOM_GM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ATOM_SM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ATOM64_GM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ATOM64_SM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BAR_ARRIVE);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BAR_SYNC);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BAR_RED);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BFE);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BFE64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BFI);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BFI64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BFIND);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BFIND64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BRA);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BREV);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BREV64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_BRKPT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_CALL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_CLZ);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_CLZ64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_CNOT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_CNOT64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_COPYSIGN);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_COPYSIGN64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_COS);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_CVT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_CVT64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_CVTA);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_CVTA64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_DIV);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_DIV64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_EX2);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_EXIT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_FMA);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_FMA64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ISSPACEP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_LD);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_LD64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_LDU);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_LDU64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_LG2);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MAD24);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MAD);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MAD64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MADC);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MADC64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MAX);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MAX64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEMBAR_CTA);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEMBAR_GL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEMBAR_SYS);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MIN);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MIN64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MOV);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MOV64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MUL24);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MUL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MUL64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_NEG);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_NEG64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_NOT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_NOT64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_OR);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_OR64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_PMEVENT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_POPC);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_POPC64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_PREFETCH);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_PREFETCHU);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_PRMT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RCP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RCP64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RED_GM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RED_SM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RED64_GM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RED64_SM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_REM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_REM64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RET);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RSQRT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RSQRT64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SAD);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SAD64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SELP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SELP64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SET);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SET64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SETP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SETP64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SHFL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SHFL64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SHL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SHL64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SHR);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SHR64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SIN);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SLCT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SLCT64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SQRT);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SQRT64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ST);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_ST64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SUB);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SUB64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SUBC);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SULD);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SULD64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SURED);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SURED64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SUST);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SUST64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_SUQ);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_TESTP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_TESTP64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_TEX);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_TLD4);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_TXQ);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_TRAP);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VABSDIFF);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VADD);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VMAD);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VMAX);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VMIN);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VSET);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VSHL);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VSHR);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VSUB);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_VOTE);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_XOR);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_XOR64);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_RECONVERGE);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_PHI);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_LD_GM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_LD_LM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_LD_SM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_LD_CM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_LD_TM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_LD_PM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_LDU_GM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_ST_GM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_ST_LM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_MEM_ST_SM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_DATA_XFER_GM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_DATA_XFER_LM);
  m_coreStatsTemplate->addStatistic(m_OP_CAT_GPU_DATA_XFER_SM);
  m_coreStatsTemplate->addStatistic(m_FP_OPS);
  m_coreStatsTemplate->addStatistic(m_ICACHE_HIT);
  m_coreStatsTemplate->addStatistic(m_ICACHE_MISS);
  m_coreStatsTemplate->addStatistic(m_MEM_STALL_CYCLE);
  m_coreStatsTemplate->addStatistic(m_ICACHE_FILL);
  m_coreStatsTemplate->addStatistic(m_NUM_WRITE_ACKS);
  m_coreStatsTemplate->addStatistic(m_NUM_WRITES);
  m_coreStatsTemplate->addStatistic(m_POWER_BLOCK_STATES_R);
  m_coreStatsTemplate->addStatistic(m_POWER_BLOCK_STATES_W);
  m_coreStatsTemplate->addStatistic(m_POWER_FETCH_QUEUE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_FETCH_QUEUE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_INST_QUEUE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_INST_QUEUE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_BR_PRED_R);
  m_coreStatsTemplate->addStatistic(m_POWER_BR_PRED_W);
  m_coreStatsTemplate->addStatistic(m_POWER_RAS_R);
  m_coreStatsTemplate->addStatistic(m_POWER_RAS_W);
  m_coreStatsTemplate->addStatistic(m_POWER_ICACHE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_ICACHE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_ICACHE_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_ICACHE_MISS_BUF_R);
  m_coreStatsTemplate->addStatistic(m_POWER_ICACHE_MISS_BUF_W);
  m_coreStatsTemplate->addStatistic(m_POWER_ICACHE_MISS_BUF_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_ICACHE_MISS_BUF_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_ICACHE_TOT_ACC);
  m_coreStatsTemplate->addStatistic(m_POWER_ICACHE_CONF);
  m_coreStatsTemplate->addStatistic(m_POWER_INST_DECODER_R);
  m_coreStatsTemplate->addStatistic(m_POWER_INST_DECODER_W);
  m_coreStatsTemplate->addStatistic(m_POWER_MICRO_OP_SEQ_R);
  m_coreStatsTemplate->addStatistic(m_POWER_MICRO_OP_SEQ_W);
  m_coreStatsTemplate->addStatistic(m_POWER_OPERAND_DECODER_R);
  m_coreStatsTemplate->addStatistic(m_POWER_OPERAND_DECODER_W);
  m_coreStatsTemplate->addStatistic(m_POWER_UOP_QUEUE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_UOP_QUEUE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_REG_RENAMING_TABLE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_REG_RENAMING_TABLE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_DEP_CHECK_LOGIC_R);
  m_coreStatsTemplate->addStatistic(m_POWER_FREELIST_R);
  m_coreStatsTemplate->addStatistic(m_POWER_FREELIST_W);
  m_coreStatsTemplate->addStatistic(m_POWER_RESERVATION_STATION_R);
  m_coreStatsTemplate->addStatistic(m_POWER_RESERVATION_STATION_W);
  m_coreStatsTemplate->addStatistic(m_POWER_RESERVATION_STATION_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_RESERVATION_STATION_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_INST_ISSUE_SEL_LOGIC_R);
  m_coreStatsTemplate->addStatistic(m_POWER_INST_ISSUE_SEL_LOGIC_W);
  m_coreStatsTemplate->addStatistic(m_POWER_PAYLOAD_RAM_R);
  m_coreStatsTemplate->addStatistic(m_POWER_PAYLOAD_RAM_W);
  m_coreStatsTemplate->addStatistic(m_POWER_EX_ALU_R);
  m_coreStatsTemplate->addStatistic(m_POWER_EX_FPU_R);
  m_coreStatsTemplate->addStatistic(m_POWER_EX_MUL_R);
  m_coreStatsTemplate->addStatistic(m_POWER_EX_SFU_R);
  m_coreStatsTemplate->addStatistic(m_POWER_REORDER_BUF_R);
  m_coreStatsTemplate->addStatistic(m_POWER_REORDER_BUF_W);
  m_coreStatsTemplate->addStatistic(m_POWER_INST_COMMIT_SEL_LOGIC_R);
  m_coreStatsTemplate->addStatistic(m_POWER_INST_COMMIT_SEL_LOGIC_W);
  m_coreStatsTemplate->addStatistic(m_POWER_FP_RENAME_R);
  m_coreStatsTemplate->addStatistic(m_POWER_FP_RENAME_W);
  m_coreStatsTemplate->addStatistic(m_POWER_LOAD_QUEUE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_LOAD_QUEUE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_LOAD_QUEUE_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_LOAD_QUEUE_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_STORE_QUEUE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_STORE_QUEUE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_STORE_QUEUE_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_STORE_QUEUE_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_DATA_TLB_R);
  m_coreStatsTemplate->addStatistic(m_POWER_DATA_TLB_W);
  m_coreStatsTemplate->addStatistic(m_POWER_DATA_TLB_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_DATA_TLB_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_INT_REGFILE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_INT_REGFILE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_FP_REGFILE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_FP_REGFILE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_GP_REGISTER_R);
  m_coreStatsTemplate->addStatistic(m_POWER_GP_REGISTER_W);
  m_coreStatsTemplate->addStatistic(m_POWER_FP_REGISTER_R);
  m_coreStatsTemplate->addStatistic(m_POWER_FP_REGISTER_W);
  m_coreStatsTemplate->addStatistic(m_POWER_SEGMENT_REGISTER_R);
  m_coreStatsTemplate->addStatistic(m_POWER_SEGMENT_REGISTER_W);
  m_coreStatsTemplate->addStatistic(m_POWER_CONTROL_REGISTER_R);
  m_coreStatsTemplate->addStatistic(m_POWER_CONTROL_REGISTER_W);
  m_coreStatsTemplate->addStatistic(m_POWER_FLAG_REGISTER_R);
  m_coreStatsTemplate->addStatistic(m_POWER_FLAG_REGISTER_W);
  m_coreStatsTemplate->addStatistic(m_POWER_EXEC_BYPASS);
  m_coreStatsTemplate->addStatistic(m_POWER_LOAD_BYPASS);
  m_coreStatsTemplate->addStatistic(m_POWER_PIPELINE);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_MISS_BUF_R);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_MISS_BUF_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_MISS_BUF_W);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_MISS_BUF_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_LINEFILL_BUF_R);
  m_coreStatsTemplate->addStatistic(m_POWER_L2CACHE_LINEFILL_BUF_R);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_LINEFILL_BUF_W);
  m_coreStatsTemplate->addStatistic(m_POWER_L2CACHE_LINEFILL_BUF_W);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_LINEFILL_BUF_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_L2CACHE_LINEFILL_BUF_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_LINEFILL_BUF_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_WB_BUF_R);
  m_coreStatsTemplate->addStatistic(m_POWER_L2CACHE_WB_BUF_R);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_WB_BUF_W);
  m_coreStatsTemplate->addStatistic(m_POWER_L2CACHE_WB_BUF_W);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_WB_BUF_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_L2CACHE_WB_BUF_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_WB_BUF_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_L2CACHE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_L2CACHE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_DCACHE_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_L2CACHE_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_CONST_CACHE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_CONST_CACHE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_CONST_CACHE_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_CONST_CACHE_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_TEXTURE_CACHE_R);
  m_coreStatsTemplate->addStatistic(m_POWER_TEXTURE_CACHE_W);
  m_coreStatsTemplate->addStatistic(m_POWER_TEXTURE_CACHE_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_TEXTURE_CACHE_W_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_SHARED_MEM_R);
  m_coreStatsTemplate->addStatistic(m_POWER_SHARED_MEM_W);
  m_coreStatsTemplate->addStatistic(m_POWER_SHARED_MEM_R_TAG);
  m_coreStatsTemplate->addStatistic(m_POWER_SHARED_MEM_W_TAG);

  m_DIST_BP_ON_PATH_CORRECT->addMember(BP_ON_PATH_CORRECT);
  m_DIST_BP_ON_PATH_CORRECT->addMember(BP_ON_PATH_MISPREDICT);
  m_DIST_BP_ON_PATH_CORRECT->addMember(BP_ON_PATH_MISFETCH);
  m_DIST_BP_OFF_PATH_CORRECT->addMember(BP_OFF_PATH_CORRECT);
  m_DIST_BP_OFF_PATH_CORRECT->addMember(BP_OFF_PATH_MISPREDICT);
  m_DIST_BP_OFF_PATH_CORRECT->addMember(BP_OFF_PATH_MISFETCH);
  m_DIST_SCHED_FAILED_REASON_SUCCESS->addMember(SCHED_FAILED_REASON_SUCCESS);
  m_DIST_SCHED_FAILED_REASON_SUCCESS->addMember(
      SCHED_FAILED_OPERANDS_NOT_READY);
  m_DIST_SCHED_FAILED_REASON_SUCCESS->addMember(SCHED_FAILED_NO_PORTS);
  m_DIST_SCHED_FAILED_REASON_SUCCESS->addMember(SCHED_FAILED_FENCE_ACTIVE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_INVALID);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_3DNOW);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_AES);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_AVX);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_AVX2);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_AVX2GATHER);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_BDW);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_BINARY);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_BITBYTE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_BMI1);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_BMI2);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_BROADCAST);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_CALL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_CMOV);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_COND_BR);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_CONVERT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_DATAXFER);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_DECIMAL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_FCMOV);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_FLAGOP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_FMA4);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_INTERRUPT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_IO);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_IOSTRINGOP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_LOGICAL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_LZCNT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_MISC);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_MMX);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_NOP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_PCLMULQDQ);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_POP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_PREFETCH);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_PUSH);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_RDRAND);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_RDSEED);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_RDWRFSGS);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_RET);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_ROTATE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_SEGOP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_SEMAPHORE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_SHIFT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_SSE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_STRINGOP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_STTNI);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_SYSCALL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_SYSRET);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_SYSTEM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_TBM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_UNCOND_BR);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_VFMA);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_VTX);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_WIDENOP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_X87_ALU);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_XOP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_XSAVE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_XED_CATEGORY_XSAVEOPT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_TR_MUL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_TR_DIV);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_TR_FMUL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_TR_FDIV);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_TR_NOP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_PREFETCH_NTA);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_PREFETCH_T0);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_PREFETCH_T1);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_PREFETCH_T2);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_EN);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_INVALID);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ABS);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ABS64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ADD);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ADD64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ADDC);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_AND);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_AND64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ATOM_GM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ATOM_SM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ATOM64_GM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ATOM64_SM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BAR_ARRIVE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BAR_SYNC);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BAR_RED);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BFE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BFE64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BFI);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BFI64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BFIND);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BFIND64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BRA);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BREV);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BREV64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_BRKPT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_CALL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_CLZ);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_CLZ64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_CNOT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_CNOT64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_COPYSIGN);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_COPYSIGN64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_COS);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_CVT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_CVT64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_CVTA);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_CVTA64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_DIV);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_DIV64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_EX2);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_EXIT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_FMA);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_FMA64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ISSPACEP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_LD);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_LD64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_LDU);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_LDU64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_LG2);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MAD24);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MAD);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MAD64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MADC);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MADC64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MAX);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MAX64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEMBAR_CTA);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEMBAR_GL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEMBAR_SYS);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MIN);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MIN64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MOV);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MOV64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MUL24);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MUL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MUL64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_NEG);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_NEG64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_NOT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_NOT64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_OR);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_OR64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_PMEVENT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_POPC);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_POPC64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_PREFETCH);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_PREFETCHU);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_PRMT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RCP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RCP64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RED_GM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RED_SM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RED64_GM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RED64_SM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_REM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_REM64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RET);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RSQRT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RSQRT64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SAD);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SAD64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SELP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SELP64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SET);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SET64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SETP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SETP64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SHFL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SHFL64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SHL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SHL64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SHR);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SHR64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SIN);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SLCT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SLCT64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SQRT);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SQRT64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ST);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_ST64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SUB);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SUB64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SUBC);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SULD);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SULD64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SURED);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SURED64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SUST);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SUST64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_SUQ);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_TESTP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_TESTP64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_TEX);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_TLD4);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_TXQ);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_TRAP);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VABSDIFF);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VADD);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VMAD);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VMAX);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VMIN);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VSET);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VSHL);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VSHR);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VSUB);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_VOTE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_XOR);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_XOR64);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_RECONVERGE);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_PHI);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_LD_GM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_LD_LM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_LD_SM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_LD_CM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_LD_TM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_LD_PM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_LDU_GM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_ST_GM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_ST_LM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_MEM_ST_SM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_DATA_XFER_GM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_DATA_XFER_LM);
  m_DIST_OP_CAT_XED_CATEGORY_INVALID->addMember(OP_CAT_GPU_DATA_XFER_SM);
  m_DIST_ICACHE_HIT->addMember(ICACHE_HIT);
  m_DIST_ICACHE_HIT->addMember(ICACHE_MISS);

  m_coreStatsTemplate->addDistribution(m_DIST_BP_ON_PATH_CORRECT);
  m_coreStatsTemplate->addDistribution(m_DIST_BP_OFF_PATH_CORRECT);
  m_coreStatsTemplate->addDistribution(m_DIST_SCHED_FAILED_REASON_SUCCESS);
  m_coreStatsTemplate->addDistribution(m_DIST_OP_CAT_XED_CATEGORY_INVALID);
  m_coreStatsTemplate->addDistribution(m_DIST_ICACHE_HIT);
}
