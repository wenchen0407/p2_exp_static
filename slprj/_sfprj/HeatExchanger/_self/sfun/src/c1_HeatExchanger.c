/* Include files */

#include <stddef.h>
#include "blas.h"
#include "HeatExchanger_sfun.h"
#include "c1_HeatExchanger.h"
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
static const char * c1_debug_family_names[17] = { "iterations", "text", "result",
  "line_num", "resultz", "sensor_value_tmp", "network_delay_tmp", "h_yg",
  "nargin", "nargout", "actual_value", "actual_value1", "ysensor_value",
  "ynetwork_delay", "sensor_value", "i", "network_array" };

static const char * c1_b_debug_family_names[7] = { "result_num", "sz_y", "i_rn",
  "nargin", "nargout", "result", "value" };

static const char * c1_c_debug_family_names[7] = { "result_num", "sz_y", "i_rn",
  "nargin", "nargout", "result", "delay" };

/* Function Declarations */
static void initialize_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance);
static void initialize_params_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct *
  chartInstance);
static void enable_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance);
static void disable_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_HeatExchanger
  (SFc1_HeatExchangerInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_HeatExchanger
  (SFc1_HeatExchangerInstanceStruct *chartInstance);
static void set_sim_state_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance);
static void sf_gateway_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance);
static void initSimStructsc1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static boolean_T c1_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_ischar, const char_T *c1_identifier);
static boolean_T c1_b_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_str2num, const char_T *c1_identifier, real_T
  c1_y[6]);
static void c1_d_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6]);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_b_network_array, const char_T *c1_identifier,
  real_T c1_y[18006]);
static void c1_f_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[18006]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_g_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_b_i, const char_T *c1_identifier);
static real_T c1_h_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_i_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_b_sensor_value, const char_T *c1_identifier,
  real_T c1_y[3]);
static void c1_j_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_k_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_ynetwork_delay, const char_T *c1_identifier,
  real_T c1_y[3]);
static void c1_l_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_m_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_n_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_o_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_p_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_q_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  int32_T c1_y[10]);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_r_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_HeatExchanger, const char_T
  *c1_identifier);
static uint8_T c1_s_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static int32_T c1_get_counter_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_counter_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b, int32_T c1_c);
static int32_T *c1_access_counter_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b);
static int32_T c1_get_ydelay_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_ydelay_global(SFc1_HeatExchangerInstanceStruct *chartInstance,
  uint32_T c1_b, int32_T c1_c);
static int32_T *c1_access_ydelay_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b);
static void init_dsm_address_info(SFc1_HeatExchangerInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_sensor_value_not_empty = false;
  chartInstance->c1_i_not_empty = false;
  chartInstance->c1_network_array_not_empty = false;
  chartInstance->c1_is_active_c1_HeatExchanger = 0U;
}

static void initialize_params_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_HeatExchanger
  (SFc1_HeatExchangerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_HeatExchanger
  (SFc1_HeatExchangerInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[3];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i1;
  real_T c1_b_u[3];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i2;
  real_T c1_c_u[3];
  const mxArray *c1_d_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  int32_T c1_i3;
  real_T c1_e_u[18006];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i4;
  real_T c1_f_u[3];
  const mxArray *c1_g_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T (*c1_ysensor_value)[3];
  real_T (*c1_ynetwork_delay)[3];
  real_T (*c1_actual_value1)[3];
  c1_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ysensor_value = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_actual_value1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(7, 1), false);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    c1_u[c1_i0] = (*c1_actual_value1)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_b_u[c1_i1] = (*c1_ynetwork_delay)[c1_i1];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    c1_c_u[c1_i2] = (*c1_ysensor_value)[c1_i2];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_hoistedGlobal = chartInstance->c1_i;
  c1_d_u = c1_hoistedGlobal;
  c1_e_y = NULL;
  if (!chartInstance->c1_i_not_empty) {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c1_y, 3, c1_e_y);
  for (c1_i3 = 0; c1_i3 < 18006; c1_i3++) {
    c1_e_u[c1_i3] = chartInstance->c1_network_array[c1_i3];
  }

  c1_f_y = NULL;
  if (!chartInstance->c1_network_array_not_empty) {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 2, 3001, 6),
                  false);
  }

  sf_mex_setcell(c1_y, 4, c1_f_y);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    c1_f_u[c1_i4] = chartInstance->c1_sensor_value[c1_i4];
  }

  c1_g_y = NULL;
  if (!chartInstance->c1_sensor_value_not_empty) {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 1, 3),
                  false);
  }

  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_HeatExchanger;
  c1_g_u = c1_b_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i5;
  real_T c1_dv1[3];
  int32_T c1_i6;
  real_T c1_dv2[3];
  int32_T c1_i7;
  static real_T c1_dv3[18006];
  int32_T c1_i8;
  real_T c1_dv4[3];
  int32_T c1_i9;
  real_T (*c1_actual_value1)[3];
  real_T (*c1_ynetwork_delay)[3];
  real_T (*c1_ysensor_value)[3];
  c1_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ysensor_value = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_actual_value1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "actual_value1", c1_dv0);
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    (*c1_actual_value1)[c1_i5] = c1_dv0[c1_i5];
  }

  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "ynetwork_delay", c1_dv1);
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    (*c1_ynetwork_delay)[c1_i6] = c1_dv1[c1_i6];
  }

  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "ysensor_value", c1_dv2);
  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    (*c1_ysensor_value)[c1_i7] = c1_dv2[c1_i7];
  }

  chartInstance->c1_i = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "i");
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
                        "network_array", c1_dv3);
  for (c1_i8 = 0; c1_i8 < 18006; c1_i8++) {
    chartInstance->c1_network_array[c1_i8] = c1_dv3[c1_i8];
  }

  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
                        "sensor_value", c1_dv4);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    chartInstance->c1_sensor_value[c1_i9] = c1_dv4[c1_i9];
  }

  chartInstance->c1_is_active_c1_HeatExchanger = c1_r_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
     "is_active_c1_HeatExchanger");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_HeatExchanger(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance)
{
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T (*c1_ynetwork_delay)[3];
  real_T (*c1_ysensor_value)[3];
  real_T (*c1_actual_value)[3];
  real_T (*c1_actual_value1)[3];
  c1_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ysensor_value = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_actual_value = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c1_actual_value1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_HeatExchanger(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_HeatExchangerMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    _SFD_DATA_RANGE_CHECK((*c1_actual_value1)[c1_i10], 0U);
  }

  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    _SFD_DATA_RANGE_CHECK((*c1_actual_value)[c1_i11], 1U);
  }

  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    _SFD_DATA_RANGE_CHECK((*c1_ysensor_value)[c1_i12], 2U);
  }

  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    _SFD_DATA_RANGE_CHECK((*c1_ynetwork_delay)[c1_i13], 5U);
  }
}

static void c1_chartstep_c1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance)
{
  int32_T c1_i14;
  real_T c1_actual_value[3];
  uint32_T c1_debug_family_var_map[17];
  real_T c1_iterations;
  const mxArray *c1_text = NULL;
  const mxArray *c1_result = NULL;
  real_T c1_line_num;
  real_T c1_resultz[6];
  real_T c1_sensor_value_tmp[3];
  real_T c1_network_delay_tmp[3];
  real_T c1_h_yg;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 3.0;
  real_T c1_actual_value1[3];
  real_T c1_ysensor_value[3];
  real_T c1_ynetwork_delay[3];
  int32_T c1_i15;
  int32_T c1_i16;
  static char_T c1_cv0[25] = { 'n', 'o', 'n', 'C', 'o', 'n', 's', 'e', 'c', 'u',
    't', 'i', 'v', 'e', 'L', 'o', 's', 't', '0', '.', '5', '.', 't', 'x', 't' };

  char_T c1_u[25];
  const mxArray *c1_y = NULL;
  real_T c1_dv5[6];
  int32_T c1_b_line_num;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  real_T c1_b_result[6];
  uint32_T c1_b_debug_family_var_map[7];
  real_T c1_result_num[6];
  real_T c1_sz_y;
  real_T c1_i_rn;
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_b_i_rn;
  int32_T c1_i26;
  int32_T c1_i27;
  real_T c1_c_result[6];
  real_T c1_b_result_num[6];
  real_T c1_b_sz_y;
  real_T c1_c_i_rn;
  real_T c1_c_nargin = 1.0;
  real_T c1_c_nargout = 1.0;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_d_i_rn;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_b_h_yg;
  real_T c1_d0;
  int32_T c1_i35;
  int32_T c1_i36;
  static char_T c1_cv1[48] = { 'H', 'e', 'a', 't', ' ', 'e', 'x', 'c', 'h', 'a',
    'n', 'g', 'e', 'r', ' ', '1', ',', ' ', 'T', 'O', 'S', 'S', 'I', 'M', ' ',
    'U', 'p', 'l', 'i', 'n', 'k', ' ', 'B', 'l', 'o', 'c', 'k', ',', ' ', 'i',
    's', ' ', 'c', 'a', 'l', 'l', 'e', 'd' };

  char_T c1_b_u[48];
  const mxArray *c1_b_y = NULL;
  int64_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  real_T (*c1_b_actual_value1)[3];
  real_T (*c1_b_ysensor_value)[3];
  real_T (*c1_b_ynetwork_delay)[3];
  real_T (*c1_b_actual_value)[3];
  boolean_T exitg1;
  c1_b_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_ysensor_value = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_actual_value = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_actual_value1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_actual_value[c1_i14] = (*c1_b_actual_value)[c1_i14];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_iterations, 0U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_text, 1U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_result, 2U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_line_num, 3U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_resultz, 4U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_sensor_value_tmp, 5U,
    c1_f_sf_marshallOut, c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_network_delay_tmp, 6U,
    c1_f_sf_marshallOut, c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_yg, 7U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 8U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 9U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_actual_value, 10U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_actual_value1, 11U,
    c1_d_sf_marshallOut, c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ysensor_value, 12U,
    c1_d_sf_marshallOut, c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ynetwork_delay, 13U,
    c1_d_sf_marshallOut, c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_sensor_value, 14U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_i, 15U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_network_array, 16U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_iterations = 3001.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c1_i_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
    chartInstance->c1_i = 0.0;
    chartInstance->c1_i_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
    for (c1_i15 = 0; c1_i15 < 18006; c1_i15++) {
      chartInstance->c1_network_array[c1_i15] = 0.0;
    }

    chartInstance->c1_network_array_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
    for (c1_i16 = 0; c1_i16 < 25; c1_i16++) {
      c1_u[c1_i16] = c1_cv0[c1_i16];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_assign(&c1_text, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "fopen", 1U, 1U, 14, c1_y), false);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
    sf_mex_assign(&c1_result, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "fgets", 1U, 1U, 14, sf_mex_dup(c1_text)), false);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
    c1_line_num = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
    exitg1 = false;
    while ((exitg1 == false) && CV_EML_WHILE(0, 1, 0, c1_emlrt_marshallIn
            (chartInstance, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
              "ischar", 1U, 1U, 14, sf_mex_dup(c1_result)), "ischar"))) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
      if (CV_EML_IF(0, 1, 1, c1_line_num <= c1_iterations)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
        c1_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                              (sfGlobalDebugInstanceStruct, "str2num", 1U, 1U,
          14, sf_mex_dup(c1_result)), "str2num", c1_dv5);
        c1_b_line_num = _SFD_EML_ARRAY_BOUNDS_CHECK("network_array", (int32_T)
          _SFD_INTEGER_CHECK("line_num", c1_line_num), 1, 3001, 1, 0) - 1;
        for (c1_i17 = 0; c1_i17 < 6; c1_i17++) {
          chartInstance->c1_network_array[c1_b_line_num + 3001 * c1_i17] =
            c1_dv5[c1_i17];
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
        sf_mex_assign(&c1_result, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "fgets", 1U, 1U, 14, sf_mex_dup(c1_text)), false);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
        c1_line_num++;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
        exitg1 = true;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "fclose", 0U, 1U, 14,
                      sf_mex_dup(c1_text));
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
  for (c1_i18 = 0; c1_i18 < 3; c1_i18++) {
    c1_ysensor_value[c1_i18] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 62);
  for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
    c1_ynetwork_delay[c1_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 69);
  chartInstance->c1_i++;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 71);
  c1_i20 = _SFD_EML_ARRAY_BOUNDS_CHECK("network_array", (int32_T)
    _SFD_INTEGER_CHECK("i", chartInstance->c1_i), 1, 3001, 1, 0) - 1;
  for (c1_i21 = 0; c1_i21 < 6; c1_i21++) {
    c1_resultz[c1_i21] = chartInstance->c1_network_array[c1_i20 + 3001 * c1_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 76);
  for (c1_i22 = 0; c1_i22 < 6; c1_i22++) {
    c1_b_result[c1_i22] = c1_resultz[c1_i22];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_b_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_result_num, 0U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_sz_y, 1U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_rn, 2U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 3U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 4U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_result, 5U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_sensor_value_tmp, 6U,
    c1_f_sf_marshallOut, c1_f_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 5);
  CV_SCRIPT_COND(0, 0, false);
  CV_SCRIPT_MCDC(0, 0, true);
  CV_SCRIPT_IF(0, 0, true);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i23 = 0; c1_i23 < 6; c1_i23++) {
    c1_result_num[c1_i23] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  for (c1_i24 = 0; c1_i24 < 6; c1_i24++) {
    c1_result_num[c1_i24] = c1_b_result[c1_i24];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_sz_y = 3.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i25 = 0; c1_i25 < 3; c1_i25++) {
    c1_sensor_value_tmp[c1_i25] = 88.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_i_rn = 1.0;
  c1_b_i_rn = 0;
  while (c1_b_i_rn < 3) {
    c1_i_rn = 1.0 + (real_T)c1_b_i_rn;
    CV_SCRIPT_FOR(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 12);
    if (CV_SCRIPT_IF(0, 1, c1_result_num[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "result_num", (int32_T)_SFD_INTEGER_CHECK("i_rn", c1_i_rn), 1, 6, 1, 0)
                     - 1] >= 1.0)) {
      _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 13);
      c1_sensor_value_tmp[_SFD_EML_ARRAY_BOUNDS_CHECK("value", (int32_T)
        _SFD_INTEGER_CHECK("i_rn", c1_i_rn), 1, 3, 2, 0) - 1] = 1.0;
    } else {
      _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 15);
      c1_sensor_value_tmp[_SFD_EML_ARRAY_BOUNDS_CHECK("value", (int32_T)
        _SFD_INTEGER_CHECK("i_rn", c1_i_rn), 1, 3, 2, 0) - 1] =
        c1_sensor_value_tmp[_SFD_EML_ARRAY_BOUNDS_CHECK("value", (int32_T)
        _SFD_INTEGER_CHECK("i_rn", c1_i_rn), 1, 3, 2, 0) - 1];
    }

    c1_b_i_rn++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 77);
  for (c1_i26 = 0; c1_i26 < 3; c1_i26++) {
    c1_ysensor_value[c1_i26] = c1_sensor_value_tmp[c1_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 79);
  for (c1_i27 = 0; c1_i27 < 6; c1_i27++) {
    c1_c_result[c1_i27] = c1_resultz[c1_i27];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_c_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_result_num, 0U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_sz_y, 1U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_i_rn, 2U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 3U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 4U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_c_result, 5U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_network_delay_tmp, 6U,
    c1_f_sf_marshallOut, c1_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 4);
  CV_SCRIPT_COND(1, 0, false);
  CV_SCRIPT_MCDC(1, 0, true);
  CV_SCRIPT_IF(1, 0, true);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 5);
  for (c1_i28 = 0; c1_i28 < 6; c1_i28++) {
    c1_b_result_num[c1_i28] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 6);
  for (c1_i29 = 0; c1_i29 < 6; c1_i29++) {
    c1_b_result_num[c1_i29] = c1_c_result[c1_i29];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 7);
  c1_b_sz_y = 3.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 9);
  for (c1_i30 = 0; c1_i30 < 3; c1_i30++) {
    c1_network_delay_tmp[c1_i30] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 10);
  c1_c_i_rn = 1.0;
  c1_d_i_rn = 0;
  while (c1_d_i_rn < 3) {
    c1_c_i_rn = 1.0 + (real_T)c1_d_i_rn;
    CV_SCRIPT_FOR(1, 0, 1);
    _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 13);
    if (CV_SCRIPT_IF(1, 1, c1_b_result_num[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "result_num", (int32_T)_SFD_INTEGER_CHECK("3+i_rn", 3.0 + c1_c_i_rn),
          1, 6, 1, 0) - 1] > 0.0)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 14);
      c1_network_delay_tmp[_SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
        _SFD_INTEGER_CHECK("i_rn", c1_c_i_rn), 1, 3, 2, 0) - 1] =
        c1_b_result_num[_SFD_EML_ARRAY_BOUNDS_CHECK("result_num", (int32_T)
        _SFD_INTEGER_CHECK("3+i_rn", 3.0 + c1_c_i_rn), 1, 6, 1, 0) - 1];
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 16);
      c1_network_delay_tmp[_SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
        _SFD_INTEGER_CHECK("i_rn", c1_c_i_rn), 1, 3, 2, 0) - 1] =
        c1_network_delay_tmp[_SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
        _SFD_INTEGER_CHECK("i_rn", c1_c_i_rn), 1, 3, 2, 0) - 1];
    }

    c1_d_i_rn++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(1, 0, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 81);
  for (c1_i31 = 0; c1_i31 < 3; c1_i31++) {
    c1_ynetwork_delay[c1_i31] = c1_network_delay_tmp[c1_i31];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 91);
  for (c1_i32 = 0; c1_i32 < 3; c1_i32++) {
    chartInstance->c1_sensor_value[c1_i32] = c1_ysensor_value[c1_i32];
  }

  chartInstance->c1_sensor_value_not_empty = true;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 94);
  for (c1_i33 = 0; c1_i33 < 3; c1_i33++) {
    c1_actual_value1[c1_i33] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 95);
  for (c1_i34 = 0; c1_i34 < 3; c1_i34++) {
    c1_actual_value1[c1_i34] = c1_actual_value[c1_i34];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 98);
  c1_h_yg = 1.0;
  c1_b_h_yg = 0;
  while (c1_b_h_yg < 3) {
    c1_h_yg = 1.0 + (real_T)c1_b_h_yg;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 99);
    c1_d0 = muDoubleScalarRound(c1_ysensor_value[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "ysensor_value", (int32_T)_SFD_INTEGER_CHECK("h_yg", c1_h_yg), 1, 3, 1, 0)
      - 1]);
    if (c1_d0 < 2.147483648E+9) {
      if (CV_SATURATION_EVAL(4, 0, 0, 1, c1_d0 >= -2.147483648E+9)) {
        c1_i35 = (int32_T)c1_d0;
      } else {
        c1_i35 = MIN_int32_T;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c1_d0 >= 2.147483648E+9)) {
      c1_i35 = MAX_int32_T;
    } else {
      c1_i35 = 0;
    }

    c1_set_ydelay_global(chartInstance, _SFD_EML_ARRAY_BOUNDS_CHECK(
      "ydelay_global", (int32_T)_SFD_INTEGER_CHECK("h_yg", c1_h_yg), 1, 10, 1, 0)
                         - 1, c1_i35);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    c1_b_h_yg++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 102);
  for (c1_i36 = 0; c1_i36 < 48; c1_i36++) {
    c1_b_u[c1_i36] = c1_cv1[c1_i36];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 48),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 103);
  c1_i37 = (int64_T)c1_get_counter_global(chartInstance, 0) + 1L;
  if (c1_i37 > 2147483647L) {
    CV_SATURATION_EVAL(4, 0, 1, 0, 1);
    c1_i37 = 2147483647L;
  } else {
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c1_i37 < -2147483648L)) {
      c1_i37 = -2147483648L;
    }
  }

  c1_set_counter_global(chartInstance, 0, (int32_T)c1_i37);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -103);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c1_text);
  sf_mex_destroy(&c1_result);
  for (c1_i38 = 0; c1_i38 < 3; c1_i38++) {
    (*c1_b_actual_value1)[c1_i38] = c1_actual_value1[c1_i38];
  }

  for (c1_i39 = 0; c1_i39 < 3; c1_i39++) {
    (*c1_b_ysensor_value)[c1_i39] = c1_ysensor_value[c1_i39];
  }

  for (c1_i40 = 0; c1_i40 < 3; c1_i40++) {
    (*c1_b_ynetwork_delay)[c1_i40] = c1_ynetwork_delay[c1_i40];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_HeatExchanger(SFc1_HeatExchangerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(
    "/Users/wangwenchen/github/paper2_experiment/value_summary.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 1U,
    sf_debug_get_script_id(
    "/Users/wangwenchen/github/paper2_experiment/network_delay_summary.m"));
}

static boolean_T c1_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_ischar, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ischar), &c1_thisId);
  sf_mex_destroy(&c1_ischar);
  return c1_y;
}

static boolean_T c1_b_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_str2num, const char_T *c1_identifier, real_T
  c1_y[6])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_str2num), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_str2num);
}

static void c1_d_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6])
{
  real_T c1_dv6[6];
  int32_T c1_i41;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv6, 0, 0, 0U, 1, 0U, 2, 1, 6);
  for (c1_i41 = 0; c1_i41 < 6; c1_i41++) {
    c1_y[c1_i41] = c1_dv6[c1_i41];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  static real_T c1_b_inData[18006];
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  real_T c1_u[18006];
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i42 = 0;
  for (c1_i43 = 0; c1_i43 < 6; c1_i43++) {
    for (c1_i44 = 0; c1_i44 < 3001; c1_i44++) {
      c1_b_inData[c1_i44 + c1_i42] = (*(real_T (*)[18006])c1_inData)[c1_i44 +
        c1_i42];
    }

    c1_i42 += 3001;
  }

  c1_i45 = 0;
  for (c1_i46 = 0; c1_i46 < 6; c1_i46++) {
    for (c1_i47 = 0; c1_i47 < 3001; c1_i47++) {
      c1_u[c1_i47 + c1_i45] = c1_b_inData[c1_i47 + c1_i45];
    }

    c1_i45 += 3001;
  }

  c1_y = NULL;
  if (!chartInstance->c1_network_array_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3001, 6),
                  false);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_b_network_array, const char_T *c1_identifier,
  real_T c1_y[18006])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_network_array),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_network_array);
}

static void c1_f_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[18006])
{
  real_T c1_dv7[18006];
  int32_T c1_i48;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_network_array_not_empty = false;
  } else {
    chartInstance->c1_network_array_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv7, 1, 0, 0U, 1, 0U, 2,
                  3001, 6);
    for (c1_i48 = 0; c1_i48 < 18006; c1_i48++) {
      c1_y[c1_i48] = c1_dv7[c1_i48];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_network_array;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  static real_T c1_y[18006];
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_b_network_array = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_network_array),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_network_array);
  c1_i49 = 0;
  for (c1_i50 = 0; c1_i50 < 6; c1_i50++) {
    for (c1_i51 = 0; c1_i51 < 3001; c1_i51++) {
      (*(real_T (*)[18006])c1_outData)[c1_i51 + c1_i49] = c1_y[c1_i51 + c1_i49];
    }

    c1_i49 += 3001;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_i_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_g_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_b_i, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_i), &c1_thisId);
  sf_mex_destroy(&c1_b_i);
  return c1_y;
}

static real_T c1_h_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_i_not_empty = false;
  } else {
    chartInstance->c1_i_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d1;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_i;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_b_i = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_i), &c1_thisId);
  sf_mex_destroy(&c1_b_i);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i52;
  real_T c1_b_inData[3];
  int32_T c1_i53;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i52 = 0; c1_i52 < 3; c1_i52++) {
    c1_b_inData[c1_i52] = (*(real_T (*)[3])c1_inData)[c1_i52];
  }

  for (c1_i53 = 0; c1_i53 < 3; c1_i53++) {
    c1_u[c1_i53] = c1_b_inData[c1_i53];
  }

  c1_y = NULL;
  if (!chartInstance->c1_sensor_value_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), false);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_i_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_b_sensor_value, const char_T *c1_identifier,
  real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sensor_value), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_sensor_value);
}

static void c1_j_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv8[3];
  int32_T c1_i54;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_sensor_value_not_empty = false;
  } else {
    chartInstance->c1_sensor_value_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv8, 1, 0, 0U, 1, 0U, 1, 3);
    for (c1_i54 = 0; c1_i54 < 3; c1_i54++) {
      c1_y[c1_i54] = c1_dv8[c1_i54];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sensor_value;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i55;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_b_sensor_value = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sensor_value), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_sensor_value);
  for (c1_i55 = 0; c1_i55 < 3; c1_i55++) {
    (*(real_T (*)[3])c1_outData)[c1_i55] = c1_y[c1_i55];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i56;
  real_T c1_b_inData[3];
  int32_T c1_i57;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i56 = 0; c1_i56 < 3; c1_i56++) {
    c1_b_inData[c1_i56] = (*(real_T (*)[3])c1_inData)[c1_i56];
  }

  for (c1_i57 = 0; c1_i57 < 3; c1_i57++) {
    c1_u[c1_i57] = c1_b_inData[c1_i57];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_k_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_ynetwork_delay, const char_T *c1_identifier,
  real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ynetwork_delay), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_ynetwork_delay);
}

static void c1_l_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv9[3];
  int32_T c1_i58;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv9, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i58 = 0; c1_i58 < 3; c1_i58++) {
    c1_y[c1_i58] = c1_dv9[c1_i58];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_ynetwork_delay;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i59;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_ynetwork_delay = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ynetwork_delay), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_ynetwork_delay);
  for (c1_i59 = 0; c1_i59 < 3; c1_i59++) {
    (*(real_T (*)[3])c1_outData)[c1_i59] = c1_y[c1_i59];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_m_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i60;
  real_T c1_b_inData[3];
  int32_T c1_i61;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i60 = 0; c1_i60 < 3; c1_i60++) {
    c1_b_inData[c1_i60] = (*(real_T (*)[3])c1_inData)[c1_i60];
  }

  for (c1_i61 = 0; c1_i61 < 3; c1_i61++) {
    c1_u[c1_i61] = c1_b_inData[c1_i61];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_n_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv10[3];
  int32_T c1_i62;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv10, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i62 = 0; c1_i62 < 3; c1_i62++) {
    c1_y[c1_i62] = c1_dv10[c1_i62];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_network_delay_tmp;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i63;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_network_delay_tmp = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_network_delay_tmp),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_network_delay_tmp);
  for (c1_i63 = 0; c1_i63 < 3; c1_i63++) {
    (*(real_T (*)[3])c1_outData)[c1_i63] = c1_y[c1_i63];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i64;
  real_T c1_b_inData[6];
  int32_T c1_i65;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i64 = 0; c1_i64 < 6; c1_i64++) {
    c1_b_inData[c1_i64] = (*(real_T (*)[6])c1_inData)[c1_i64];
  }

  for (c1_i65 = 0; c1_i65 < 6; c1_i65++) {
    c1_u[c1_i65] = c1_b_inData[c1_i65];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_o_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6])
{
  real_T c1_dv11[6];
  int32_T c1_i66;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv11, 1, 0, 0U, 1, 0U, 2, 1, 6);
  for (c1_i66 = 0; c1_i66 < 6; c1_i66++) {
    c1_y[c1_i66] = c1_dv11[c1_i66];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_resultz;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[6];
  int32_T c1_i67;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_resultz = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_resultz), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_resultz);
  for (c1_i67 = 0; c1_i67 < 6; c1_i67++) {
    (*(real_T (*)[6])c1_outData)[c1_i67] = c1_y[c1_i67];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  const mxArray *c1_u;
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = sf_mex_dup(*(const mxArray **)c1_inData);
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_HeatExchanger_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("fclose"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mxArray"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("value_summary"), "name",
                  "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]/Users/wangwenchen/github/paper2_experiment/value_summary.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1454627813U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("network_delay_summary"),
                  "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]/Users/wangwenchen/github/paper2_experiment/network_delay_summary.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1454627777U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_p_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i68;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i68, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i68;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i69;
  int32_T c1_b_inData[10];
  int32_T c1_i70;
  int32_T c1_u[10];
  const mxArray *c1_y = NULL;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i69 = 0; c1_i69 < 10; c1_i69++) {
    c1_b_inData[c1_i69] = (*(int32_T (*)[10])c1_inData)[c1_i69];
  }

  for (c1_i70 = 0; c1_i70 < 10; c1_i70++) {
    c1_u[c1_i70] = c1_b_inData[c1_i70];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 6, 0U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_q_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  int32_T c1_y[10])
{
  int32_T c1_iv0[10];
  int32_T c1_i71;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_iv0, 1, 6, 0U, 1, 0U, 1, 10);
  for (c1_i71 = 0; c1_i71 < 10; c1_i71++) {
    c1_y[c1_i71] = c1_iv0[c1_i71];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_ydelay_global;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y[10];
  int32_T c1_i72;
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c1_ydelay_global = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ydelay_global), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_ydelay_global);
  for (c1_i72 = 0; c1_i72 < 10; c1_i72++) {
    (*(int32_T (*)[10])c1_outData)[c1_i72] = c1_y[c1_i72];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_r_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_HeatExchanger, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_HeatExchanger), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_HeatExchanger);
  return c1_y;
}

static uint8_T c1_s_emlrt_marshallIn(SFc1_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static int32_T c1_get_counter_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#94) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_counter_global_address;
}

static void c1_set_counter_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b, int32_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#94) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_counter_global_address = c1_c;
}

static int32_T *c1_access_counter_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  int32_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c1_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#94) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_counter_global_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c1_c;
}

static int32_T c1_get_ydelay_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#93) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_ydelay_global_address)[c1_b];
}

static void c1_set_ydelay_global(SFc1_HeatExchangerInstanceStruct *chartInstance,
  uint32_T c1_b, int32_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#93) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_ydelay_global_address)[c1_b] = c1_c;
}

static int32_T *c1_access_ydelay_global(SFc1_HeatExchangerInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  int32_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c1_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#93) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_ydelay_global_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c1_c;
}

static void init_dsm_address_info(SFc1_HeatExchangerInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "counter_global", (void **)
    &chartInstance->c1_counter_global_address,
    &chartInstance->c1_counter_global_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "ydelay_global", (void **)
    &chartInstance->c1_ydelay_global_address,
    &chartInstance->c1_ydelay_global_index);
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

void sf_c1_HeatExchanger_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2523435304U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1177438388U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1221069351U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(866971764U);
}

mxArray *sf_c1_HeatExchanger_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ntBTLjqEg1GhBNd5Rc0lQH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

mxArray *sf_c1_HeatExchanger_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_HeatExchanger_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_HeatExchanger(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[7],T\"actual_value1\",},{M[1],M[13],T\"ynetwork_delay\",},{M[1],M[5],T\"ysensor_value\",},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[245 246],M[0],}}},{M[4],M[0],T\"network_array\",S'l','i','p'{{M1x2[260 273],M[0],}}},{M[4],M[0],T\"sensor_value\",S'l','i','p'{{M1x2[207 219],M[0],}}},{M[8],M[0],T\"is_active_c1_HeatExchanger\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_HeatExchanger_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_HeatExchangerInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_HeatExchangerInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _HeatExchangerMachineNumber_,
           1,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"actual_value1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"actual_value");
          _SFD_SET_DATA_PROPS(2,2,0,1,"ysensor_value");
          _SFD_SET_DATA_PROPS(3,11,0,0,"ydelay_global");
          _SFD_SET_DATA_PROPS(4,11,0,0,"counter_global");
          _SFD_SET_DATA_PROPS(5,2,0,1,"ynetwork_delay");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2310);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,2162,-1,2209);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,2291,-1,2309);
        _SFD_CV_INIT_EML_IF(0,1,0,698,711,-1,1249);
        _SFD_CV_INIT_EML_IF(0,1,1,998,1024,1125,1160);
        _SFD_CV_INIT_EML_FOR(0,1,0,2143,2158,2214);
        _SFD_CV_INIT_EML_WHILE(0,1,0,969,990,1201);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,1,0,1,1);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"value_summary",0,-1,500);
        _SFD_CV_INIT_SCRIPT_IF(0,0,90,110,470,500);
        _SFD_CV_INIT_SCRIPT_IF(0,1,315,339,388,457);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,285,303,469);

        {
          static int condStart[] = { 94 };

          static int condEnd[] = { 109 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,93,109,1,0,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(1,1,2,0,0,0,1,0,1,1);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"network_delay_summary",0,-1,585);
        _SFD_CV_INIT_SCRIPT_IF(1,0,97,117,558,585);
        _SFD_CV_INIT_SCRIPT_IF(1,1,385,410,476,545);
        _SFD_CV_INIT_SCRIPT_FOR(1,0,289,307,557);

        {
          static int condStart[] = { 101 };

          static int condEnd[] = { 116 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(1,0,100,116,1,0,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)
            c1_i_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_i_sf_marshallOut,(MexInFcnForType)c1_h_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          real_T (*c1_actual_value1)[3];
          real_T (*c1_actual_value)[3];
          real_T (*c1_ysensor_value)[3];
          real_T (*c1_ynetwork_delay)[3];
          c1_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 3);
          c1_ysensor_value = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c1_actual_value = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            0);
          c1_actual_value1 = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_actual_value1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_actual_value);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_ysensor_value);
          _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c1_ydelay_global_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c1_counter_global_address);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_ynetwork_delay);
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
  return "b2Y5s5CnzrLPOryBipdrAD";
}

static void sf_opaque_initialize_c1_HeatExchanger(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_HeatExchangerInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_HeatExchanger((SFc1_HeatExchangerInstanceStruct*)
    chartInstanceVar);
  initialize_c1_HeatExchanger((SFc1_HeatExchangerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_HeatExchanger(void *chartInstanceVar)
{
  enable_c1_HeatExchanger((SFc1_HeatExchangerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_HeatExchanger(void *chartInstanceVar)
{
  disable_c1_HeatExchanger((SFc1_HeatExchangerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_HeatExchanger(void *chartInstanceVar)
{
  sf_gateway_c1_HeatExchanger((SFc1_HeatExchangerInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_HeatExchanger(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_HeatExchanger
    ((SFc1_HeatExchangerInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_HeatExchanger();/* state var info */
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

extern void sf_internal_set_sim_state_c1_HeatExchanger(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_HeatExchanger();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_HeatExchanger((SFc1_HeatExchangerInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_HeatExchanger(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_HeatExchanger(S);
}

static void sf_opaque_set_sim_state_c1_HeatExchanger(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_HeatExchanger(S, st);
}

static void sf_opaque_terminate_c1_HeatExchanger(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_HeatExchangerInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_HeatExchanger_optimization_info();
    }

    finalize_c1_HeatExchanger((SFc1_HeatExchangerInstanceStruct*)
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
  initSimStructsc1_HeatExchanger((SFc1_HeatExchangerInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_HeatExchanger(SimStruct *S)
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
    initialize_params_c1_HeatExchanger((SFc1_HeatExchangerInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_HeatExchanger(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_HeatExchanger_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4096130216U));
  ssSetChecksum1(S,(716375280U));
  ssSetChecksum2(S,(809507613U));
  ssSetChecksum3(S,(2318795482U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c1_HeatExchanger(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_HeatExchanger(SimStruct *S)
{
  SFc1_HeatExchangerInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_HeatExchangerInstanceStruct *)utMalloc(sizeof
    (SFc1_HeatExchangerInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_HeatExchangerInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_HeatExchanger;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_HeatExchanger;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_HeatExchanger;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_HeatExchanger;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_HeatExchanger;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_HeatExchanger;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_HeatExchanger;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_HeatExchanger;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_HeatExchanger;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_HeatExchanger;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_HeatExchanger;
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

void c1_HeatExchanger_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_HeatExchanger(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_HeatExchanger(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_HeatExchanger(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_HeatExchanger_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
