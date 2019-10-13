/*
Copyright (c) <2012>, <Georgia Institute of Technology> All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

Neither the name of the <Georgia Institue of Technology> nor the names of its
contributors may be used to endorse or promote products derived from this
software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**********************************************************************************************
 * File         : progress_checker.h
 * Author       : Hyojong Kim
 * Date         : 2/5/2018
 * Description  : Progress Checker
 *********************************************************************************************/

#ifndef PROGRESS_CHECKER_H_INCLUDED
#define PROGRESS_CHECKER_H_INCLUDED

#include "global_defs.h"
#include "global_types.h"
#include "macsim.h"

class progress_checker_c {
 public:
  progress_checker_c(macsim_c *simBase);
  ~progress_checker_c();

  // return true when every core has nothing to do, otherwise, return false
  bool inspect(Counter curr_cycle);

  void update_frontend_progress_info(Counter cycle) {
    m_frontend_stage_last_active_cycle = cycle;
  }

  void update_allocate_progress_info(Counter cycle) {
    m_allocate_stage_last_active_cycle = cycle;
  }

  void update_schedule_progress_info(Counter cycle) {
    m_schedule_stage_last_active_cycle = cycle;
  }

  void update_retire_progress_info(Counter cycle) {
    m_retire_stage_last_active_cycle = cycle;
  }

  void update_dram_progress_info(Counter cycle) {
    m_dram_last_active_cycle = cycle;
  }

  void increment_outstanding_requests() { ++m_outstanding_requests; }

  void decrement_outstanding_requests() { --m_outstanding_requests; }

 private:
  Counter m_threshold;

  Counter m_frontend_stage_last_active_cycle;
  Counter m_allocate_stage_last_active_cycle;
  Counter m_schedule_stage_last_active_cycle;
  Counter m_retire_stage_last_active_cycle;
  Counter m_dram_last_active_cycle;

  Counter m_outstanding_requests;

  bool m_fast_forward_mode;

  macsim_c *m_simBase; /**< pointer to the simulation base class */
};
#endif
