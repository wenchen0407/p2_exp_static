#ifndef __c2_CoupledTanks_WCPS_v2_h__
#define __c2_CoupledTanks_WCPS_v2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_struct_oh4EmTugatBrDkw1stRYdE_tag
#define struct_struct_oh4EmTugatBrDkw1stRYdE_tag

struct struct_oh4EmTugatBrDkw1stRYdE_tag
{
  real_T i;
  real_T count;
  real_T yin[5];
  real_T yin_d[5];
  real_T delay1[2406];
  real_T ranD[5];
};

#endif                                 /*struct_struct_oh4EmTugatBrDkw1stRYdE_tag*/

#ifndef typedef_c2_struct_oh4EmTugatBrDkw1stRYdE
#define typedef_c2_struct_oh4EmTugatBrDkw1stRYdE

typedef struct struct_oh4EmTugatBrDkw1stRYdE_tag
  c2_struct_oh4EmTugatBrDkw1stRYdE;

#endif                                 /*typedef_c2_struct_oh4EmTugatBrDkw1stRYdE*/

#ifndef typedef_SFc2_CoupledTanks_WCPS_v2InstanceStruct
#define typedef_SFc2_CoupledTanks_WCPS_v2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_CoupledTanks_WCPS_v2;
  c2_struct_oh4EmTugatBrDkw1stRYdE c2_structure;
  real_T c2_i;
  boolean_T c2_i_not_empty;
  real_T c2_yin_d[5];
  boolean_T c2_yin_d_not_empty;
  real_T c2_yin[5];
  boolean_T c2_yin_not_empty;
  real_T c2_delay[6];
  boolean_T c2_delay_not_empty;
  real_T c2_yin_all[50005];
  boolean_T c2_yin_all_not_empty;
  real_T c2_num;
  boolean_T c2_num_not_empty;
} SFc2_CoupledTanks_WCPS_v2InstanceStruct;

#endif                                 /*typedef_SFc2_CoupledTanks_WCPS_v2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_CoupledTanks_WCPS_v2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_CoupledTanks_WCPS_v2_get_check_sum(mxArray *plhs[]);
extern void c2_CoupledTanks_WCPS_v2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
