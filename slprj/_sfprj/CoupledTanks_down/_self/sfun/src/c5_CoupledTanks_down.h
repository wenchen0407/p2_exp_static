#ifndef __c5_CoupledTanks_down_h__
#define __c5_CoupledTanks_down_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc5_CoupledTanks_downInstanceStruct
#define typedef_SFc5_CoupledTanks_downInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_CoupledTanks_down;
  real_T c5_delay1[15];
  boolean_T c5_delay1_not_empty;
  real_T c5_i;
  boolean_T c5_i_not_empty;
  boolean_T c5_last_emergency_instance_not_empty;
  boolean_T c5_RetransCounter_not_empty;
  int32_T *c5_counter_global_address;
  int32_T c5_counter_global_index;
  int32_T (*c5_ydelay_global_address)[15];
  int32_T c5_ydelay_global_index;
} SFc5_CoupledTanks_downInstanceStruct;

#endif                                 /*typedef_SFc5_CoupledTanks_downInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_CoupledTanks_down_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_CoupledTanks_down_get_check_sum(mxArray *plhs[]);
extern void c5_CoupledTanks_down_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
