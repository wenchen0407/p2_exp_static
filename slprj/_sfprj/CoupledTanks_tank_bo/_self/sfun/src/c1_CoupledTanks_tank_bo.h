#ifndef __c1_CoupledTanks_tank_bo_h__
#define __c1_CoupledTanks_tank_bo_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_CoupledTanks_tank_boInstanceStruct
#define typedef_SFc1_CoupledTanks_tank_boInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_CoupledTanks_tank_bo;
  real_T c1_delay1[15];
  boolean_T c1_delay1_not_empty;
  real_T c1_i;
  boolean_T c1_i_not_empty;
  real_T c1_last_emergency_instance[5];
  boolean_T c1_last_emergency_instance_not_empty;
  boolean_T c1_RetransCounter_not_empty;
} SFc1_CoupledTanks_tank_boInstanceStruct;

#endif                                 /*typedef_SFc1_CoupledTanks_tank_boInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_CoupledTanks_tank_bo_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_CoupledTanks_tank_bo_get_check_sum(mxArray *plhs[]);
extern void c1_CoupledTanks_tank_bo_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
