#ifndef __c2_SIMUL_step_delay_Embed_integrated_v3_h__
#define __c2_SIMUL_step_delay_Embed_integrated_v3_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char *context;
  const char *name;
  const char *dominantType;
  const char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c2_ResolvedFunctionInfo;

#ifndef struct_struct_ycoAwLxjCdherhpZ5VA6GG_tag
#define struct_struct_ycoAwLxjCdherhpZ5VA6GG_tag

typedef struct struct_ycoAwLxjCdherhpZ5VA6GG_tag {
  real_T i;
  real_T count;
  real_T yin[4];
  real_T yin_d[4];
  real_T delay1[50005];
  real_T ranD[4];
} c2_struct_ycoAwLxjCdherhpZ5VA6GG;

#else

typedef struct struct_ycoAwLxjCdherhpZ5VA6GG_tag
  c2_struct_ycoAwLxjCdherhpZ5VA6GG;

#endif

typedef struct {
  c2_struct_ycoAwLxjCdherhpZ5VA6GG c2_structure;
  SimStruct *S;
  real_T c2_count1;
  real_T c2_delay[5];
  real_T c2_delay1[50005];
  real_T c2_i;
  real_T c2_num;
  real_T c2_yin[4];
  real_T c2_yin_all[40004];
  real_T c2_yin_d[4];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_count1_not_empty;
  boolean_T c2_delay1_not_empty;
  boolean_T c2_delay_not_empty;
  boolean_T c2_doneDoubleBufferReInit;
  boolean_T c2_i_not_empty;
  boolean_T c2_isStable;
  boolean_T c2_num_not_empty;
  boolean_T c2_yin_all_not_empty;
  boolean_T c2_yin_d_not_empty;
  boolean_T c2_yin_not_empty;
  uint8_T c2_is_active_c2_SIMUL_step_delay_Embed_integrated_v3;
  ChartInfoStruct chartInfo;
} SFc2_SIMUL_step_delay_Embed_integrated_v3InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_SIMUL_step_delay_Embed_integrated_v3_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_SIMUL_step_delay_Embed_integrated_v3_get_check_sum(mxArray
  *plhs[]);
extern void c2_SIMUL_step_delay_Embed_integrated_v3_method_dispatcher(SimStruct *
  S, int_T method, void *data);

#endif
