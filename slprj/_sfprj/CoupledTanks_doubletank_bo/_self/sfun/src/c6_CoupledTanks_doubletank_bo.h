#ifndef __c6_CoupledTanks_doubletank_bo_h__
#define __c6_CoupledTanks_doubletank_bo_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc6_CoupledTanks_doubletank_boInstanceStruct
#define typedef_SFc6_CoupledTanks_doubletank_boInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_CoupledTanks_doubletank_bo;
  boolean_T c6_i_not_empty;
  real_T c6_uin_d[2];
  boolean_T c6_uin_d_not_empty;
  real_T c6_uin[2];
  boolean_T c6_uin_not_empty;
  real_T c6_delay[15];
  boolean_T c6_delay_not_empty;
  real_T c6_uin_all[1600002];
  boolean_T c6_uin_all_not_empty;
  real_T c6_numAct;
  boolean_T c6_numAct_not_empty;
} SFc6_CoupledTanks_doubletank_boInstanceStruct;

#endif                                 /*typedef_SFc6_CoupledTanks_doubletank_boInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c6_CoupledTanks_doubletank_bo_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_CoupledTanks_doubletank_bo_get_check_sum(mxArray *plhs[]);
extern void c6_CoupledTanks_doubletank_bo_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
