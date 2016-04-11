#ifndef __c1_CoupledTanks_WCPS_v3_h__
#define __c1_CoupledTanks_WCPS_v3_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  real_T c1_delay1[8];
  real_T c1_i;
  int32_T c1_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_delay1_not_empty;
  boolean_T c1_doneDoubleBufferReInit;
  boolean_T c1_i_not_empty;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_CoupledTanks_WCPS_v3;
  ChartInfoStruct chartInfo;
} SFc1_CoupledTanks_WCPS_v3InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_CoupledTanks_WCPS_v3_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_CoupledTanks_WCPS_v3_get_check_sum(mxArray *plhs[]);
extern void c1_CoupledTanks_WCPS_v3_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
