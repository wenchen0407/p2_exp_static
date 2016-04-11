#ifndef __c1_HeatExchanger_h__
#define __c1_HeatExchanger_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_HeatExchangerInstanceStruct
#define typedef_SFc1_HeatExchangerInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_HeatExchanger;
  real_T c1_sensor_value[3];
  boolean_T c1_sensor_value_not_empty;
  real_T c1_i;
  boolean_T c1_i_not_empty;
  real_T c1_network_array[18006];
  boolean_T c1_network_array_not_empty;
  int32_T *c1_counter_global_address;
  int32_T c1_counter_global_index;
  int32_T (*c1_ydelay_global_address)[10];
  int32_T c1_ydelay_global_index;
} SFc1_HeatExchangerInstanceStruct;

#endif                                 /*typedef_SFc1_HeatExchangerInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_HeatExchanger_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_HeatExchanger_get_check_sum(mxArray *plhs[]);
extern void c1_HeatExchanger_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
