#ifndef __c1_CoupledTanks_WCPS_Event_h__
#define __c1_CoupledTanks_WCPS_Event_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_CoupledTanks_WCPS_EventInstanceStruct
#define typedef_SFc1_CoupledTanks_WCPS_EventInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_CoupledTanks_WCPS_Event;
  real_T c1_delay1[8];
  boolean_T c1_delay1_not_empty;
  real_T c1_i;
  boolean_T c1_i_not_empty;
  real_T c1_last_emergency_instance[5];
  boolean_T c1_last_emergency_instance_not_empty;
  real_T c1_RetransCounter[5];
  boolean_T c1_RetransCounter_not_empty;
} SFc1_CoupledTanks_WCPS_EventInstanceStruct;

#endif                                 /*typedef_SFc1_CoupledTanks_WCPS_EventInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_CoupledTanks_WCPS_Event_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_CoupledTanks_WCPS_Event_get_check_sum(mxArray *plhs[]);
extern void c1_CoupledTanks_WCPS_Event_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
