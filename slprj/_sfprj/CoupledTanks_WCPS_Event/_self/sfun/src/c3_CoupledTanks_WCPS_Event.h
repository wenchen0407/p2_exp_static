#ifndef __c3_CoupledTanks_WCPS_Event_h__
#define __c3_CoupledTanks_WCPS_Event_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc3_CoupledTanks_WCPS_EventInstanceStruct
#define typedef_SFc3_CoupledTanks_WCPS_EventInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_CoupledTanks_WCPS_Event;
  boolean_T c3_i_not_empty;
  real_T c3_uin_d[2];
  boolean_T c3_uin_d_not_empty;
  real_T c3_uin[2];
  boolean_T c3_uin_not_empty;
  real_T c3_delay[8];
  boolean_T c3_delay_not_empty;
  real_T c3_uin_all[20002];
  boolean_T c3_uin_all_not_empty;
  real_T c3_numAct;
  boolean_T c3_numAct_not_empty;
} SFc3_CoupledTanks_WCPS_EventInstanceStruct;

#endif                                 /*typedef_SFc3_CoupledTanks_WCPS_EventInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_CoupledTanks_WCPS_Event_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_CoupledTanks_WCPS_Event_get_check_sum(mxArray *plhs[]);
extern void c3_CoupledTanks_WCPS_Event_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
