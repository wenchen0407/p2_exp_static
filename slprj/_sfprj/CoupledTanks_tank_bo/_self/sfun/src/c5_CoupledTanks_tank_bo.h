#ifndef __c5_CoupledTanks_tank_bo_h__
#define __c5_CoupledTanks_tank_bo_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc5_CoupledTanks_tank_boInstanceStruct
#define typedef_SFc5_CoupledTanks_tank_boInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_CoupledTanks_tank_bo;
  real_T c5_delay1[15];
  boolean_T c5_delay1_not_empty;
  real_T c5_i;
  boolean_T c5_i_not_empty;
  boolean_T c5_last_emergency_instance_not_empty;
  boolean_T c5_RetransCounter_not_empty;
} SFc5_CoupledTanks_tank_boInstanceStruct;

#endif                                 /*typedef_SFc5_CoupledTanks_tank_boInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_CoupledTanks_tank_bo_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_CoupledTanks_tank_bo_get_check_sum(mxArray *plhs[]);
extern void c5_CoupledTanks_tank_bo_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
