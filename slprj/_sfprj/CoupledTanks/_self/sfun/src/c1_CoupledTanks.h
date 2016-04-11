#ifndef __c1_CoupledTanks_h__
#define __c1_CoupledTanks_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_CoupledTanksInstanceStruct
#define typedef_SFc1_CoupledTanksInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_CoupledTanks;
  real_T c1_delay1[4];
  boolean_T c1_delay1_not_empty;
  real_T c1_i;
  boolean_T c1_i_not_empty;
  real_T c1_last_emergency_instance[3];
  boolean_T c1_last_emergency_instance_not_empty;
  int32_T *c1_counter_global_address;
  int32_T c1_counter_global_index;
  int32_T (*c1_ydelay_global_address)[15];
  int32_T c1_ydelay_global_index;
} SFc1_CoupledTanksInstanceStruct;

#endif                                 /*typedef_SFc1_CoupledTanksInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_CoupledTanks_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_CoupledTanks_get_check_sum(mxArray *plhs[]);
extern void c1_CoupledTanks_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
