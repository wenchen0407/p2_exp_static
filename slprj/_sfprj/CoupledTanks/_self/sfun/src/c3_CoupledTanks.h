#ifndef __c3_CoupledTanks_h__
#define __c3_CoupledTanks_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_struct_jgcRFG32RbuET2w4s7dLLB_tag
#define struct_struct_jgcRFG32RbuET2w4s7dLLB_tag

struct struct_jgcRFG32RbuET2w4s7dLLB_tag
{
  real_T i;
  real_T count;
  real_T yin[3];
  real_T yin_d[3];
  real_T delay1[804];
  real_T ranD[5];
};

#endif                                 /*struct_struct_jgcRFG32RbuET2w4s7dLLB_tag*/

#ifndef typedef_c3_struct_jgcRFG32RbuET2w4s7dLLB
#define typedef_c3_struct_jgcRFG32RbuET2w4s7dLLB

typedef struct struct_jgcRFG32RbuET2w4s7dLLB_tag
  c3_struct_jgcRFG32RbuET2w4s7dLLB;

#endif                                 /*typedef_c3_struct_jgcRFG32RbuET2w4s7dLLB*/

#ifndef typedef_SFc3_CoupledTanksInstanceStruct
#define typedef_SFc3_CoupledTanksInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_CoupledTanks;
  c3_struct_jgcRFG32RbuET2w4s7dLLB c3_structure;
  real_T c3_i;
  boolean_T c3_i_not_empty;
  real_T c3_yin_d[3];
  boolean_T c3_yin_d_not_empty;
  real_T c3_yin[3];
  boolean_T c3_yin_not_empty;
  real_T c3_delay_data[11];
  int32_T c3_delay_sizes[2];
  boolean_T c3_delay_not_empty;
  real_T c3_yin_all[2400003];
  boolean_T c3_yin_all_not_empty;
  real_T c3_num;
  boolean_T c3_num_not_empty;
} SFc3_CoupledTanksInstanceStruct;

#endif                                 /*typedef_SFc3_CoupledTanksInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_CoupledTanks_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_CoupledTanks_get_check_sum(mxArray *plhs[]);
extern void c3_CoupledTanks_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
