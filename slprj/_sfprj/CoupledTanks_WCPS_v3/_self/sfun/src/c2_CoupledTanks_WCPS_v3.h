#ifndef __c2_CoupledTanks_WCPS_v3_h__
#define __c2_CoupledTanks_WCPS_v3_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_struct_oh4EmTugatBrDkw1stRYdE_tag
#define struct_struct_oh4EmTugatBrDkw1stRYdE_tag

typedef struct struct_oh4EmTugatBrDkw1stRYdE_tag
{
  real_T i;
  real_T count;
  real_T yin[5];
  real_T yin_d[5];
  real_T delay1[2406];
  real_T ranD[5];
} c2_struct_oh4EmTugatBrDkw1stRYdE;

#else

typedef struct struct_oh4EmTugatBrDkw1stRYdE_tag
  c2_struct_oh4EmTugatBrDkw1stRYdE;

#endif

typedef struct {
  c2_struct_oh4EmTugatBrDkw1stRYdE c2_structure;
  SimStruct *S;
  real_T c2_delay[8];
  real_T c2_i;
  real_T c2_num;
  real_T c2_yin[5];
  real_T c2_yin_all[50005];
  real_T c2_yin_d[5];
  int32_T c2_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_delay_not_empty;
  boolean_T c2_doneDoubleBufferReInit;
  boolean_T c2_i_not_empty;
  boolean_T c2_isStable;
  boolean_T c2_num_not_empty;
  boolean_T c2_yin_all_not_empty;
  boolean_T c2_yin_d_not_empty;
  boolean_T c2_yin_not_empty;
  uint8_T c2_is_active_c2_CoupledTanks_WCPS_v3;
  ChartInfoStruct chartInfo;
} SFc2_CoupledTanks_WCPS_v3InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_CoupledTanks_WCPS_v3_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_CoupledTanks_WCPS_v3_get_check_sum(mxArray *plhs[]);
extern void c2_CoupledTanks_WCPS_v3_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
