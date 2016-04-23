#ifndef __c5_HeatExchanger_h__
#define __c5_HeatExchanger_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_sL6LJlPlxhdTxZzXh5NTaQC
#define struct_sL6LJlPlxhdTxZzXh5NTaQC

struct sL6LJlPlxhdTxZzXh5NTaQC
{
  int32_T intNumBits;
};

#endif                                 /*struct_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_c5_sL6LJlPlxhdTxZzXh5NTaQC
#define typedef_c5_sL6LJlPlxhdTxZzXh5NTaQC

typedef struct sL6LJlPlxhdTxZzXh5NTaQC c5_sL6LJlPlxhdTxZzXh5NTaQC;

#endif                                 /*typedef_c5_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef struct_struct_GS2RmkGZ5GnB7UItqpfzDB_tag
#define struct_struct_GS2RmkGZ5GnB7UItqpfzDB_tag

struct struct_GS2RmkGZ5GnB7UItqpfzDB_tag
{
  real_T i;
  real_T count;
  real_T sen_num;
  real_T yin[3];
  real_T yin_d[3];
  real_T delay_v[3];
  real_T ynd_tmp[3];
  real_T ranD[5];
};

#endif                                 /*struct_struct_GS2RmkGZ5GnB7UItqpfzDB_tag*/

#ifndef typedef_c5_struct_GS2RmkGZ5GnB7UItqpfzDB
#define typedef_c5_struct_GS2RmkGZ5GnB7UItqpfzDB

typedef struct struct_GS2RmkGZ5GnB7UItqpfzDB_tag
  c5_struct_GS2RmkGZ5GnB7UItqpfzDB;

#endif                                 /*typedef_c5_struct_GS2RmkGZ5GnB7UItqpfzDB*/

#ifndef typedef_SFc5_HeatExchangerInstanceStruct
#define typedef_SFc5_HeatExchangerInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_HeatExchanger;
  c5_struct_GS2RmkGZ5GnB7UItqpfzDB c5_structure;
  real_T c5_i;
  boolean_T c5_i_not_empty;
  real_T c5_yin_d[3];
  boolean_T c5_yin_d_not_empty;
  real_T c5_delay_v[3];
  boolean_T c5_delay_v_not_empty;
  real_T c5_yin[3];
  boolean_T c5_yin_not_empty;
  real_T c5_sensor_value;
  boolean_T c5_sensor_value_not_empty;
  real_T c5_num;
  boolean_T c5_num_not_empty;
  real_T c5_ynd_tmp[3];
  boolean_T c5_ynd_tmp_not_empty;
  real_T c5_last_senReading;
  boolean_T c5_last_senReading_not_empty;
  real_T c5_last_senDelay;
  boolean_T c5_last_senDelay_not_empty;
} SFc5_HeatExchangerInstanceStruct;

#endif                                 /*typedef_SFc5_HeatExchangerInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_HeatExchanger_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_HeatExchanger_get_check_sum(mxArray *plhs[]);
extern void c5_HeatExchanger_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
