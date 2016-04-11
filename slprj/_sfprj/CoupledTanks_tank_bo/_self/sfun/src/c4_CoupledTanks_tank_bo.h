#ifndef __c4_CoupledTanks_tank_bo_h__
#define __c4_CoupledTanks_tank_bo_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc4_CoupledTanks_tank_boInstanceStruct
#define typedef_SFc4_CoupledTanks_tank_boInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_CoupledTanks_tank_bo;
  boolean_T c4_i_not_empty;
  real_T c4_uin_d[2];
  boolean_T c4_uin_d_not_empty;
  real_T c4_uin[2];
  boolean_T c4_uin_not_empty;
  real_T c4_delay[15];
  boolean_T c4_delay_not_empty;
  real_T c4_uin_all[20002];
  boolean_T c4_uin_all_not_empty;
  real_T c4_numAct;
  boolean_T c4_numAct_not_empty;
} SFc4_CoupledTanks_tank_boInstanceStruct;

#endif                                 /*typedef_SFc4_CoupledTanks_tank_boInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_CoupledTanks_tank_bo_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c4_CoupledTanks_tank_bo_get_check_sum(mxArray *plhs[]);
extern void c4_CoupledTanks_tank_bo_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
