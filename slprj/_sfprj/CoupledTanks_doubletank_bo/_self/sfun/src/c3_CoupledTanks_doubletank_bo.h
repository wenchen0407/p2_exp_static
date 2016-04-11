#ifndef __c3_CoupledTanks_doubletank_bo_h__
#define __c3_CoupledTanks_doubletank_bo_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_struct_WeKnf7Jk8GwbDfKwFHL9aD_tag
#define struct_struct_WeKnf7Jk8GwbDfKwFHL9aD_tag

struct struct_WeKnf7Jk8GwbDfKwFHL9aD_tag
{
  real_T i;
  real_T count;
  real_T yin[5];
  real_T yin_d[5];
  real_T delay1[306];
  real_T ranD[5];
};

#endif                                 /*struct_struct_WeKnf7Jk8GwbDfKwFHL9aD_tag*/

#ifndef typedef_c3_struct_WeKnf7Jk8GwbDfKwFHL9aD
#define typedef_c3_struct_WeKnf7Jk8GwbDfKwFHL9aD

typedef struct struct_WeKnf7Jk8GwbDfKwFHL9aD_tag
  c3_struct_WeKnf7Jk8GwbDfKwFHL9aD;

#endif                                 /*typedef_c3_struct_WeKnf7Jk8GwbDfKwFHL9aD*/

#ifndef typedef_SFc3_CoupledTanks_doubletank_boInstanceStruct
#define typedef_SFc3_CoupledTanks_doubletank_boInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_CoupledTanks_doubletank_bo;
  c3_struct_WeKnf7Jk8GwbDfKwFHL9aD c3_structure;
  real_T c3_i;
  boolean_T c3_i_not_empty;
  real_T c3_yin_d[5];
  boolean_T c3_yin_d_not_empty;
  real_T c3_yin[5];
  boolean_T c3_yin_not_empty;
  real_T c3_delay_data[15];
  int32_T c3_delay_sizes[2];
  boolean_T c3_delay_not_empty;
  real_T c3_yin_all[4000005];
  boolean_T c3_yin_all_not_empty;
  real_T c3_num;
  boolean_T c3_num_not_empty;
} SFc3_CoupledTanks_doubletank_boInstanceStruct;

#endif                                 /*typedef_SFc3_CoupledTanks_doubletank_boInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_CoupledTanks_doubletank_bo_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_CoupledTanks_doubletank_bo_get_check_sum(mxArray *plhs[]);
extern void c3_CoupledTanks_doubletank_bo_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
