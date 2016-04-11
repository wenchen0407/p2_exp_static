#ifndef __c3_CoupledTanks_WCPS_v3_h__
#define __c3_CoupledTanks_WCPS_v3_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  real_T c3_delay[8];
  real_T c3_numAct;
  real_T c3_uin[2];
  real_T c3_uin_all[20002];
  real_T c3_uin_d[2];
  int32_T c3_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_delay_not_empty;
  boolean_T c3_doneDoubleBufferReInit;
  boolean_T c3_isStable;
  boolean_T c3_numAct_not_empty;
  boolean_T c3_uin_all_not_empty;
  boolean_T c3_uin_d_not_empty;
  boolean_T c3_uin_not_empty;
  uint8_T c3_is_active_c3_CoupledTanks_WCPS_v3;
  ChartInfoStruct chartInfo;
} SFc3_CoupledTanks_WCPS_v3InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_CoupledTanks_WCPS_v3_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_CoupledTanks_WCPS_v3_get_check_sum(mxArray *plhs[]);
extern void c3_CoupledTanks_WCPS_v3_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
