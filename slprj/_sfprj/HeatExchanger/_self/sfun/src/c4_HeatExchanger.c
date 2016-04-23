/* Include files */

#include <stddef.h>
#include "blas.h"
#include "HeatExchanger_sfun.h"
#include "c4_HeatExchanger.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "HeatExchanger_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[18] = { "iterations", "text", "result",
  "line_num", "ysensor_value", "resultz", "sensor_value_tmp",
  "network_delay_tmp", "h_yg", "nargin", "nargout", "control_actual_value",
  "control_actual_value1", "control_ysensor_value", "control_ynetwork_delay",
  "sensor_value", "i", "network_array" };

static const char * c4_b_debug_family_names[7] = { "result_num", "sz_y", "i_rn",
  "nargin", "nargout", "result", "value" };

static const char * c4_c_debug_family_names[7] = { "result_num", "sz_y", "i_rn",
  "nargin", "nargout", "result", "delay" };

/* Function Declarations */
static void initialize_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance);
static void initialize_params_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct *
  chartInstance);
static void enable_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance);
static void disable_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_HeatExchanger
  (SFc4_HeatExchangerInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_HeatExchanger
  (SFc4_HeatExchangerInstanceStruct *chartInstance);
static void set_sim_state_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance);
static void sf_gateway_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance);
static void c4_chartstep_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance);
static void initSimStructsc4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static boolean_T c4_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_ischar, const char_T *c4_identifier);
static boolean_T c4_b_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_str2num, const char_T *c4_identifier, real_T
  c4_y[2]);
static void c4_d_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[2]);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_e_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_b_network_array, const char_T *c4_identifier,
  real_T c4_y[6002]);
static void c4_f_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[6002]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_g_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_b_i, const char_T *c4_identifier);
static real_T c4_h_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_i_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_b_sensor_value, const char_T *c4_identifier);
static real_T c4_j_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_k_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_control_ynetwork_delay, const char_T
  *c4_identifier);
static real_T c4_l_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_m_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[2]);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_n_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_o_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  int32_T c4_y[10]);
static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_p_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_HeatExchanger, const char_T
  *c4_identifier);
static uint8_T c4_q_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static int32_T c4_get_counter_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_counter_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b, int32_T c4_c);
static int32_T *c4_access_counter_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b);
static int32_T c4_get_ydelay_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_ydelay_global(SFc4_HeatExchangerInstanceStruct *chartInstance,
  uint32_T c4_b, int32_T c4_c);
static int32_T *c4_access_ydelay_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b);
static void init_dsm_address_info(SFc4_HeatExchangerInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_sensor_value_not_empty = false;
  chartInstance->c4_i_not_empty = false;
  chartInstance->c4_network_array_not_empty = false;
  chartInstance->c4_is_active_c4_HeatExchanger = 0U;
}

static void initialize_params_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_HeatExchanger
  (SFc4_HeatExchangerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_HeatExchanger
  (SFc4_HeatExchangerInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  int32_T c4_i0;
  real_T c4_e_u[6002];
  const mxArray *c4_f_y = NULL;
  real_T c4_e_hoistedGlobal;
  real_T c4_f_u;
  const mxArray *c4_g_y = NULL;
  uint8_T c4_f_hoistedGlobal;
  uint8_T c4_g_u;
  const mxArray *c4_h_y = NULL;
  real_T *c4_control_actual_value1;
  real_T *c4_control_ynetwork_delay;
  real_T *c4_control_ysensor_value;
  c4_control_ynetwork_delay = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    3);
  c4_control_ysensor_value = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_control_actual_value1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(7, 1), false);
  c4_hoistedGlobal = *c4_control_actual_value1;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_control_ynetwork_delay;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_control_ysensor_value;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = chartInstance->c4_i;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  if (!chartInstance->c4_i_not_empty) {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 3, c4_e_y);
  for (c4_i0 = 0; c4_i0 < 6002; c4_i0++) {
    c4_e_u[c4_i0] = chartInstance->c4_network_array[c4_i0];
  }

  c4_f_y = NULL;
  if (!chartInstance->c4_network_array_not_empty) {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_e_u, 0, 0U, 1U, 0U, 2, 3001, 2),
                  false);
  }

  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_e_hoistedGlobal = chartInstance->c4_sensor_value;
  c4_f_u = c4_e_hoistedGlobal;
  c4_g_y = NULL;
  if (!chartInstance->c4_sensor_value_not_empty) {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_f_hoistedGlobal = chartInstance->c4_is_active_c4_HeatExchanger;
  c4_g_u = c4_f_hoistedGlobal;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[6002];
  int32_T c4_i1;
  real_T *c4_control_actual_value1;
  real_T *c4_control_ynetwork_delay;
  real_T *c4_control_ysensor_value;
  c4_control_ynetwork_delay = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    3);
  c4_control_ysensor_value = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_control_actual_value1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *c4_control_actual_value1 = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "control_actual_value1");
  *c4_control_ynetwork_delay = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "control_ynetwork_delay");
  *c4_control_ysensor_value = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "control_ysensor_value");
  chartInstance->c4_i = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "i");
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
                        "network_array", c4_dv0);
  for (c4_i1 = 0; c4_i1 < 6002; c4_i1++) {
    chartInstance->c4_network_array[c4_i1] = c4_dv0[c4_i1];
  }

  chartInstance->c4_sensor_value = c4_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 5)), "sensor_value");
  chartInstance->c4_is_active_c4_HeatExchanger = c4_p_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 6)),
     "is_active_c4_HeatExchanger");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_HeatExchanger(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance)
{
  real_T *c4_control_actual_value1;
  real_T *c4_control_actual_value;
  real_T *c4_control_ysensor_value;
  real_T *c4_control_ynetwork_delay;
  c4_control_ynetwork_delay = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    3);
  c4_control_ysensor_value = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_control_actual_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_control_actual_value1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_HeatExchanger(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_HeatExchangerMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c4_control_actual_value1, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_control_actual_value, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_control_ysensor_value, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_control_ynetwork_delay, 5U);
}

static void c4_chartstep_c4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_control_actual_value;
  uint32_T c4_debug_family_var_map[18];
  real_T c4_iterations;
  const mxArray *c4_text = NULL;
  const mxArray *c4_result = NULL;
  real_T c4_line_num;
  real_T c4_ysensor_value;
  real_T c4_resultz[2];
  real_T c4_sensor_value_tmp;
  real_T c4_network_delay_tmp;
  real_T c4_h_yg;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 3.0;
  real_T c4_control_actual_value1;
  real_T c4_control_ysensor_value;
  real_T c4_control_ynetwork_delay;
  int32_T c4_i2;
  int32_T c4_i3;
  static char_T c4_cv0[33] = { 'c', 'o', 'n', 't', 'r', 'o', 'l', '_', 'a', 'c',
    't', 'i', 'o', 'n', '_', 'n', 'o', 'n', 'C', 'o', 'n', 's', 'e', 'c', 'u',
    't', 'i', 'v', 'e', '.', 't', 'x', 't' };

  char_T c4_u[33];
  const mxArray *c4_y = NULL;
  real_T c4_dv1[2];
  int32_T c4_b_line_num;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  real_T c4_b_result[2];
  uint32_T c4_b_debug_family_var_map[7];
  real_T c4_result_num[2];
  real_T c4_sz_y;
  real_T c4_i_rn;
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i10;
  real_T c4_c_result[2];
  real_T c4_b_result_num[2];
  real_T c4_b_sz_y;
  real_T c4_b_i_rn;
  real_T c4_c_nargin = 1.0;
  real_T c4_c_nargout = 1.0;
  int32_T c4_i11;
  int32_T c4_i12;
  real_T c4_d0;
  int32_T c4_i13;
  int32_T c4_i14;
  static char_T c4_cv1[50] = { 'H', 'e', 'a', 't', ' ', 'e', 'x', 'c', 'h', 'a',
    'n', 'g', 'e', 'r', ' ', '1', ',', ' ', 'T', 'O', 'S', 'S', 'I', 'M', ' ',
    'D', 'o', 'w', 'n', 'l', 'i', 'n', 'k', ' ', 'B', 'l', 'o', 'c', 'k', ',',
    ' ', 'i', 's', ' ', 'c', 'a', 'l', 'l', 'e', 'd' };

  char_T c4_b_u[50];
  const mxArray *c4_b_y = NULL;
  int64_T c4_i15;
  real_T *c4_b_control_actual_value;
  real_T *c4_b_control_actual_value1;
  real_T *c4_b_control_ysensor_value;
  real_T *c4_b_control_ynetwork_delay;
  boolean_T exitg1;
  c4_b_control_ynetwork_delay = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    3);
  c4_b_control_ysensor_value = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    2);
  c4_b_control_actual_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_b_control_actual_value1 = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_control_actual_value;
  c4_control_actual_value = c4_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_iterations, 0U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_text, 1U, c4_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_result, 2U, c4_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_line_num, 3U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ysensor_value, 4U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_resultz, 5U, c4_e_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_sensor_value_tmp, 6U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_network_delay_tmp, 7U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_h_yg, 8U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 9U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 10U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_control_actual_value, 11U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_control_actual_value1, 12U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_control_ysensor_value, 13U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_control_ynetwork_delay, 14U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_sensor_value, 15U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_i, 16U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c4_network_array, 17U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  c4_iterations = 3001.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 27);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 29);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 30);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c4_i_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 33);
    chartInstance->c4_i = 0.0;
    chartInstance->c4_i_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 36);
    for (c4_i2 = 0; c4_i2 < 6002; c4_i2++) {
      chartInstance->c4_network_array[c4_i2] = 0.0;
    }

    chartInstance->c4_network_array_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
    for (c4_i3 = 0; c4_i3 < 33; c4_i3++) {
      c4_u[c4_i3] = c4_cv0[c4_i3];
    }

    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    sf_mex_assign(&c4_text, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "fopen", 1U, 1U, 14, c4_y), false);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 39);
    sf_mex_assign(&c4_result, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "fgets", 1U, 1U, 14, sf_mex_dup(c4_text)), false);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 43);
    c4_line_num = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
    exitg1 = false;
    while ((exitg1 == false) && CV_EML_WHILE(0, 1, 0, c4_emlrt_marshallIn
            (chartInstance, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
              "ischar", 1U, 1U, 14, sf_mex_dup(c4_result)), "ischar"))) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 45);
      if (CV_EML_IF(0, 1, 1, c4_line_num <= c4_iterations)) {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 46);
        c4_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                              (sfGlobalDebugInstanceStruct, "str2num", 1U, 1U,
          14, sf_mex_dup(c4_result)), "str2num", c4_dv1);
        c4_b_line_num = _SFD_EML_ARRAY_BOUNDS_CHECK("network_array", (int32_T)
          _SFD_INTEGER_CHECK("line_num", c4_line_num), 1, 3001, 1, 0) - 1;
        for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
          chartInstance->c4_network_array[c4_b_line_num + 3001 * c4_i4] =
            c4_dv1[c4_i4];
        }

        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 47);
        sf_mex_assign(&c4_result, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "fgets", 1U, 1U, 14, sf_mex_dup(c4_text)), false);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 52);
        c4_line_num++;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 49);
        exitg1 = true;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 55);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "fclose", 0U, 1U, 14,
                      sf_mex_dup(c4_text));
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 61);
  c4_ysensor_value = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 62);
  c4_control_ynetwork_delay = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 69);
  chartInstance->c4_i++;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 71);
  c4_i5 = _SFD_EML_ARRAY_BOUNDS_CHECK("network_array", (int32_T)
    _SFD_INTEGER_CHECK("i", chartInstance->c4_i), 1, 3001, 1, 0) - 1;
  for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
    c4_resultz[c4_i6] = chartInstance->c4_network_array[c4_i5 + 3001 * c4_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 76);
  for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
    c4_b_result[c4_i7] = c4_resultz[c4_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c4_b_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_result_num, 0U, c4_e_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_sz_y, 1U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_i_rn, 2U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 3U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_result, 5U, c4_e_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_sensor_value_tmp, 6U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 5);
  CV_SCRIPT_COND(0, 0, false);
  CV_SCRIPT_MCDC(0, 0, true);
  CV_SCRIPT_IF(0, 0, true);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
    c4_result_num[c4_i8] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  for (c4_i9 = 0; c4_i9 < 2; c4_i9++) {
    c4_result_num[c4_i9] = c4_b_result[c4_i9];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_sz_y = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_sensor_value_tmp = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_i_rn = 1.0;
  CV_SCRIPT_FOR(0, 0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 12);
  if (CV_SCRIPT_IF(0, 1, c4_result_num[0] >= 1.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 13);
    c4_sensor_value_tmp = 1.0;
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 15);
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 77);
  c4_control_ysensor_value = c4_sensor_value_tmp;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 79);
  for (c4_i10 = 0; c4_i10 < 2; c4_i10++) {
    c4_c_result[c4_i10] = c4_resultz[c4_i10];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c4_c_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_result_num, 0U, c4_e_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_sz_y, 1U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_i_rn, 2U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 3U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_c_result, 5U, c4_e_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_network_delay_tmp, 6U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 4);
  CV_SCRIPT_COND(1, 0, false);
  CV_SCRIPT_MCDC(1, 0, true);
  CV_SCRIPT_IF(1, 0, true);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 5);
  for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
    c4_b_result_num[c4_i11] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 6);
  for (c4_i12 = 0; c4_i12 < 2; c4_i12++) {
    c4_b_result_num[c4_i12] = c4_c_result[c4_i12];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 7);
  c4_b_sz_y = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 9);
  c4_network_delay_tmp = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 10);
  c4_b_i_rn = 1.0;
  CV_SCRIPT_FOR(1, 0, 1);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 13);
  if (CV_SCRIPT_IF(1, 1, c4_b_result_num[1] > 0.0)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 14);
    c4_network_delay_tmp = c4_b_result_num[1];
  } else {
    _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 16);
  }

  CV_SCRIPT_FOR(1, 0, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 81);
  c4_control_ynetwork_delay = c4_network_delay_tmp;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 91);
  chartInstance->c4_sensor_value = c4_control_ysensor_value;
  chartInstance->c4_sensor_value_not_empty = true;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 94);
  c4_control_actual_value1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 95);
  c4_control_actual_value1 = c4_control_actual_value;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 98);
  c4_h_yg = 1.0;
  CV_EML_FOR(0, 1, 0, 1);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 99);
  c4_d0 = muDoubleScalarRound(c4_control_ysensor_value);
  if (c4_d0 < 2.147483648E+9) {
    if (CV_SATURATION_EVAL(4, 0, 0, 1, c4_d0 >= -2.147483648E+9)) {
      c4_i13 = (int32_T)c4_d0;
    } else {
      c4_i13 = MIN_int32_T;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c4_d0 >= 2.147483648E+9)) {
    c4_i13 = MAX_int32_T;
  } else {
    c4_i13 = 0;
  }

  c4_set_ydelay_global(chartInstance, 0, c4_i13);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 102);
  for (c4_i14 = 0; c4_i14 < 50; c4_i14++) {
    c4_b_u[c4_i14] = c4_cv1[c4_i14];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_u, 10, 0U, 1U, 0U, 2, 1, 50),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_b_y);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 103);
  c4_i15 = (int64_T)c4_get_counter_global(chartInstance, 0) + 1L;
  if (c4_i15 > 2147483647L) {
    CV_SATURATION_EVAL(4, 0, 1, 0, 1);
    c4_i15 = 2147483647L;
  } else {
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c4_i15 < -2147483648L)) {
      c4_i15 = -2147483648L;
    }
  }

  c4_set_counter_global(chartInstance, 0, (int32_T)c4_i15);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -103);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c4_text);
  sf_mex_destroy(&c4_result);
  *c4_b_control_actual_value1 = c4_control_actual_value1;
  *c4_b_control_ysensor_value = c4_control_ysensor_value;
  *c4_b_control_ynetwork_delay = c4_control_ynetwork_delay;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_HeatExchanger(SFc4_HeatExchangerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 0U,
    sf_debug_get_script_id(
    "/Users/wangwenchen/github/paper2_experiment/control_value_summary.m"));
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 1U,
    sf_debug_get_script_id(
    "/Users/wangwenchen/github/paper2_experiment/control_network_delay_summary.m"));
}

static boolean_T c4_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_ischar, const char_T *c4_identifier)
{
  boolean_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ischar), &c4_thisId);
  sf_mex_destroy(&c4_ischar);
  return c4_y;
}

static boolean_T c4_b_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  boolean_T c4_y;
  boolean_T c4_b0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b0, 1, 11, 0U, 0, 0U, 0);
  c4_y = c4_b0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_str2num, const char_T *c4_identifier, real_T
  c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_str2num), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_str2num);
}

static void c4_d_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[2])
{
  real_T c4_dv2[2];
  int32_T c4_i16;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv2, 0, 0, 0U, 1, 0U, 2, 1, 2);
  for (c4_i16 = 0; c4_i16 < 2; c4_i16++) {
    c4_y[c4_i16] = c4_dv2[c4_i16];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  real_T c4_b_inData[6002];
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  real_T c4_u[6002];
  const mxArray *c4_y = NULL;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i17 = 0;
  for (c4_i18 = 0; c4_i18 < 2; c4_i18++) {
    for (c4_i19 = 0; c4_i19 < 3001; c4_i19++) {
      c4_b_inData[c4_i19 + c4_i17] = (*(real_T (*)[6002])c4_inData)[c4_i19 +
        c4_i17];
    }

    c4_i17 += 3001;
  }

  c4_i20 = 0;
  for (c4_i21 = 0; c4_i21 < 2; c4_i21++) {
    for (c4_i22 = 0; c4_i22 < 3001; c4_i22++) {
      c4_u[c4_i22 + c4_i20] = c4_b_inData[c4_i22 + c4_i20];
    }

    c4_i20 += 3001;
  }

  c4_y = NULL;
  if (!chartInstance->c4_network_array_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3001, 2),
                  false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_e_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_b_network_array, const char_T *c4_identifier,
  real_T c4_y[6002])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_network_array),
                        &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_network_array);
}

static void c4_f_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[6002])
{
  real_T c4_dv3[6002];
  int32_T c4_i23;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_network_array_not_empty = false;
  } else {
    chartInstance->c4_network_array_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv3, 1, 0, 0U, 1, 0U, 2,
                  3001, 2);
    for (c4_i23 = 0; c4_i23 < 6002; c4_i23++) {
      c4_y[c4_i23] = c4_dv3[c4_i23];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_network_array;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[6002];
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_b_network_array = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_network_array),
                        &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_network_array);
  c4_i24 = 0;
  for (c4_i25 = 0; c4_i25 < 2; c4_i25++) {
    for (c4_i26 = 0; c4_i26 < 3001; c4_i26++) {
      (*(real_T (*)[6002])c4_outData)[c4_i26 + c4_i24] = c4_y[c4_i26 + c4_i24];
    }

    c4_i24 += 3001;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_i_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_g_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_b_i, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_i), &c4_thisId);
  sf_mex_destroy(&c4_b_i);
  return c4_y;
}

static real_T c4_h_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_i_not_empty = false;
  } else {
    chartInstance->c4_i_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d1;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_i;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_b_i = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_i), &c4_thisId);
  sf_mex_destroy(&c4_b_i);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_sensor_value_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_i_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_b_sensor_value, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sensor_value),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sensor_value);
  return c4_y;
}

static real_T c4_j_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d2;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_sensor_value_not_empty = false;
  } else {
    chartInstance->c4_sensor_value_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d2, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d2;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sensor_value;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_b_sensor_value = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sensor_value),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sensor_value);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_k_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_control_ynetwork_delay, const char_T
  *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_control_ynetwork_delay), &c4_thisId);
  sf_mex_destroy(&c4_control_ynetwork_delay);
  return c4_y;
}

static real_T c4_l_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d3;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d3, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d3;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_control_ynetwork_delay;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_control_ynetwork_delay = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_control_ynetwork_delay), &c4_thisId);
  sf_mex_destroy(&c4_control_ynetwork_delay);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i27;
  real_T c4_b_inData[2];
  int32_T c4_i28;
  real_T c4_u[2];
  const mxArray *c4_y = NULL;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i27 = 0; c4_i27 < 2; c4_i27++) {
    c4_b_inData[c4_i27] = (*(real_T (*)[2])c4_inData)[c4_i27];
  }

  for (c4_i28 = 0; c4_i28 < 2; c4_i28++) {
    c4_u[c4_i28] = c4_b_inData[c4_i28];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_m_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[2])
{
  real_T c4_dv4[2];
  int32_T c4_i29;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv4, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c4_i29 = 0; c4_i29 < 2; c4_i29++) {
    c4_y[c4_i29] = c4_dv4[c4_i29];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_resultz;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[2];
  int32_T c4_i30;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_resultz = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_resultz), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_resultz);
  for (c4_i30 = 0; c4_i30 < 2; c4_i30++) {
    (*(real_T (*)[2])c4_outData)[c4_i30] = c4_y[c4_i30];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  const mxArray *c4_u;
  const mxArray *c4_y = NULL;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = sf_mex_dup(*(const mxArray **)c4_inData);
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u), false);
  sf_mex_destroy(&c4_u);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_HeatExchanger_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  const mxArray *c4_rhs2 = NULL;
  const mxArray *c4_lhs2 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("fclose"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mxArray"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("control_value_summary"),
                  "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]/Users/wangwenchen/github/paper2_experiment/control_value_summary.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1460407427U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("control_network_delay_summary"),
                  "name", "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]/Users/wangwenchen/github/paper2_experiment/control_network_delay_summary.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1460407460U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c4_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs2), "lhs", "lhs", 2);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
}

static const mxArray *c4_emlrt_marshallOut(const char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), false);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), false);
  return c4_y;
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_n_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i31;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i31, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i31;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i32;
  int32_T c4_b_inData[10];
  int32_T c4_i33;
  int32_T c4_u[10];
  const mxArray *c4_y = NULL;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i32 = 0; c4_i32 < 10; c4_i32++) {
    c4_b_inData[c4_i32] = (*(int32_T (*)[10])c4_inData)[c4_i32];
  }

  for (c4_i33 = 0; c4_i33 < 10; c4_i33++) {
    c4_u[c4_i33] = c4_b_inData[c4_i33];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 6, 0U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_o_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  int32_T c4_y[10])
{
  int32_T c4_iv0[10];
  int32_T c4_i34;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_iv0, 1, 6, 0U, 1, 0U, 1, 10);
  for (c4_i34 = 0; c4_i34 < 10; c4_i34++) {
    c4_y[c4_i34] = c4_iv0[c4_i34];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_ydelay_global;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y[10];
  int32_T c4_i35;
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c4_ydelay_global = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ydelay_global), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_ydelay_global);
  for (c4_i35 = 0; c4_i35 < 10; c4_i35++) {
    (*(int32_T (*)[10])c4_outData)[c4_i35] = c4_y[c4_i35];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_p_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_HeatExchanger, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_HeatExchanger), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_HeatExchanger);
  return c4_y;
}

static uint8_T c4_q_emlrt_marshallIn(SFc4_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static int32_T c4_get_counter_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#137) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_counter_global_address;
}

static void c4_set_counter_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b, int32_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#137) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_counter_global_address = c4_c;
}

static int32_T *c4_access_counter_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  int32_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c4_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#137) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_counter_global_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c4_c;
}

static int32_T c4_get_ydelay_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#136) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c4_ydelay_global_address)[c4_b];
}

static void c4_set_ydelay_global(SFc4_HeatExchangerInstanceStruct *chartInstance,
  uint32_T c4_b, int32_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#136) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c4_ydelay_global_address)[c4_b] = c4_c;
}

static int32_T *c4_access_ydelay_global(SFc4_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  int32_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c4_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#136) in the initialization routine of the chart.\n");
  }

  c4_c = *chartInstance->c4_ydelay_global_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c4_c;
}

static void init_dsm_address_info(SFc4_HeatExchangerInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "counter_global", (void **)
    &chartInstance->c4_counter_global_address,
    &chartInstance->c4_counter_global_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "ydelay_global", (void **)
    &chartInstance->c4_ydelay_global_address,
    &chartInstance->c4_ydelay_global_index);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c4_HeatExchanger_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1876016598U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(892134852U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2727065003U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1477223290U);
}

mxArray *sf_c4_HeatExchanger_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YrelT0eykAyDSDeQKg011");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_HeatExchanger_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_HeatExchanger_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_HeatExchanger(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[7],T\"control_actual_value1\",},{M[1],M[13],T\"control_ynetwork_delay\",},{M[1],M[5],T\"control_ysensor_value\",},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[277 278],M[0],}}},{M[4],M[0],T\"network_array\",S'l','i','p'{{M1x2[292 305],M[0],}}},{M[4],M[0],T\"sensor_value\",S'l','i','p'{{M1x2[239 251],M[0],}}},{M[8],M[0],T\"is_active_c4_HeatExchanger\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_HeatExchanger_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_HeatExchangerInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_HeatExchangerInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _HeatExchangerMachineNumber_,
           4,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_HeatExchangerMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_HeatExchangerMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _HeatExchangerMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"control_actual_value1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"control_actual_value");
          _SFD_SET_DATA_PROPS(2,2,0,1,"control_ysensor_value");
          _SFD_SET_DATA_PROPS(3,11,0,0,"ydelay_global");
          _SFD_SET_DATA_PROPS(4,11,0,0,"counter_global");
          _SFD_SET_DATA_PROPS(5,2,0,1,"control_ynetwork_delay");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,2,0,2,0,1,1,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2428);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,2270,-1,2325);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,2409,-1,2427);
        _SFD_CV_INIT_EML_IF(0,1,0,730,743,-1,1289);
        _SFD_CV_INIT_EML_IF(0,1,1,1038,1064,1165,1200);
        _SFD_CV_INIT_EML_FOR(0,1,0,2251,2266,2330);
        _SFD_CV_INIT_EML_WHILE(0,1,0,1009,1030,1241);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,1,0,1,1);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"control_value_summary",0,-1,496);
        _SFD_CV_INIT_SCRIPT_IF(0,0,98,118,472,496);
        _SFD_CV_INIT_SCRIPT_IF(0,1,317,341,390,459);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,287,305,471);

        {
          static int condStart[] = { 102 };

          static int condEnd[] = { 117 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,101,117,1,0,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(1,1,2,0,0,0,1,0,1,1);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"control_network_delay_summary",0,-1,585);
        _SFD_CV_INIT_SCRIPT_IF(1,0,105,125,562,585);
        _SFD_CV_INIT_SCRIPT_IF(1,1,389,414,480,549);
        _SFD_CV_INIT_SCRIPT_FOR(1,0,293,311,561);

        {
          static int condStart[] = { 109 };

          static int condEnd[] = { 124 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(1,0,108,124,1,0,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)c4_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)c4_d_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_h_sf_marshallOut,(MexInFcnForType)
            c4_g_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_g_sf_marshallOut,(MexInFcnForType)c4_f_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)c4_d_sf_marshallIn);

        {
          real_T *c4_control_actual_value1;
          real_T *c4_control_actual_value;
          real_T *c4_control_ysensor_value;
          real_T *c4_control_ynetwork_delay;
          c4_control_ynetwork_delay = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 3);
          c4_control_ysensor_value = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 2);
          c4_control_actual_value = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 0);
          c4_control_actual_value1 = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_control_actual_value1);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_control_actual_value);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_control_ysensor_value);
          _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c4_ydelay_global_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c4_counter_global_address);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_control_ynetwork_delay);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _HeatExchangerMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "6wZltbN9nEeN9SBodkluN";
}

static void sf_opaque_initialize_c4_HeatExchanger(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_HeatExchangerInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_HeatExchanger((SFc4_HeatExchangerInstanceStruct*)
    chartInstanceVar);
  initialize_c4_HeatExchanger((SFc4_HeatExchangerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_HeatExchanger(void *chartInstanceVar)
{
  enable_c4_HeatExchanger((SFc4_HeatExchangerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_HeatExchanger(void *chartInstanceVar)
{
  disable_c4_HeatExchanger((SFc4_HeatExchangerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_HeatExchanger(void *chartInstanceVar)
{
  sf_gateway_c4_HeatExchanger((SFc4_HeatExchangerInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_HeatExchanger(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_HeatExchanger
    ((SFc4_HeatExchangerInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_HeatExchanger();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c4_HeatExchanger(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_HeatExchanger();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_HeatExchanger((SFc4_HeatExchangerInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_HeatExchanger(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_HeatExchanger(S);
}

static void sf_opaque_set_sim_state_c4_HeatExchanger(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c4_HeatExchanger(S, st);
}

static void sf_opaque_terminate_c4_HeatExchanger(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_HeatExchangerInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_HeatExchanger_optimization_info();
    }

    finalize_c4_HeatExchanger((SFc4_HeatExchangerInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_HeatExchanger((SFc4_HeatExchangerInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_HeatExchanger(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c4_HeatExchanger((SFc4_HeatExchangerInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_HeatExchanger(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_HeatExchanger_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1364363504U));
  ssSetChecksum1(S,(1869221291U));
  ssSetChecksum2(S,(1090303435U));
  ssSetChecksum3(S,(1932304148U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c4_HeatExchanger(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_HeatExchanger(SimStruct *S)
{
  SFc4_HeatExchangerInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_HeatExchangerInstanceStruct *)utMalloc(sizeof
    (SFc4_HeatExchangerInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_HeatExchangerInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_HeatExchanger;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_HeatExchanger;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_HeatExchanger;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_HeatExchanger;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_HeatExchanger;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_HeatExchanger;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_HeatExchanger;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_HeatExchanger;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_HeatExchanger;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_HeatExchanger;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_HeatExchanger;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c4_HeatExchanger_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_HeatExchanger(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_HeatExchanger(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_HeatExchanger(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_HeatExchanger_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
