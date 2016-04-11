/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CoupledTanks_sfun.h"
#include "c1_CoupledTanks.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CoupledTanks_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[17] = { "emergency_instance",
  "call_count", "rssi", "resultz", "end_to_end_delivery_result_aggregated",
  "delay", "network_delay", "i_yg", "nargin", "nargout", "ymea", "ymea1",
  "ydelay", "ynetwork_delay", "delay1", "i", "last_emergency_instance" };

static const char * c1_b_debug_family_names[7] = { "result_num", "sz_y", "i_rn",
  "nargin", "nargout", "result", "delay" };

/* Function Declarations */
static void initialize_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance);
static void initialize_params_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance);
static void enable_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance);
static void disable_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_CoupledTanks
  (SFc1_CoupledTanksInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_CoupledTanks
  (SFc1_CoupledTanksInstanceStruct *chartInstance);
static void set_sim_state_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance);
static void sf_gateway_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance);
static void initSimStructsc1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static void c1_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_transpose, const char_T *c1_identifier, real_T c1_y[4]);
static void c1_b_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static boolean_T c1_c_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_isempty, const char_T *c1_identifier);
static boolean_T c1_d_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_result, const char_T *c1_identifier, real_T c1_y[6]);
static void c1_f_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[6]);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_b_last_emergency_instance, const char_T *c1_identifier,
  real_T c1_y[3]);
static void c1_h_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_i_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_b_i, const char_T *c1_identifier);
static real_T c1_j_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_k_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_b_delay1, const char_T *c1_identifier, real_T c1_y[4]);
static void c1_l_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_m_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_ynetwork_delay, const char_T *c1_identifier, real_T c1_y[3]);
static void c1_n_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_o_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_p_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_q_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_r_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, int32_T c1_y[15]);
static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_s_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_CoupledTanks, const char_T
  *c1_identifier);
static uint8_T c1_t_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static int32_T c1_get_counter_global(SFc1_CoupledTanksInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_counter_global(SFc1_CoupledTanksInstanceStruct *chartInstance,
  uint32_T c1_b, int32_T c1_c);
static int32_T *c1_access_counter_global(SFc1_CoupledTanksInstanceStruct
  *chartInstance, uint32_T c1_b);
static int32_T c1_get_ydelay_global(SFc1_CoupledTanksInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_ydelay_global(SFc1_CoupledTanksInstanceStruct *chartInstance,
  uint32_T c1_b, int32_T c1_c);
static int32_T *c1_access_ydelay_global(SFc1_CoupledTanksInstanceStruct
  *chartInstance, uint32_T c1_b);
static void init_dsm_address_info(SFc1_CoupledTanksInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_delay1_not_empty = false;
  chartInstance->c1_i_not_empty = false;
  chartInstance->c1_last_emergency_instance_not_empty = false;
  chartInstance->c1_is_active_c1_CoupledTanks = 0U;
}

static void initialize_params_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_CoupledTanks
  (SFc1_CoupledTanksInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_CoupledTanks
  (SFc1_CoupledTanksInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[4];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i1;
  real_T c1_b_u[3];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i2;
  real_T c1_c_u[3];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i3;
  real_T c1_d_u[4];
  const mxArray *c1_e_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  int32_T c1_i4;
  real_T c1_f_u[3];
  const mxArray *c1_g_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T (*c1_ynetwork_delay)[3];
  real_T (*c1_ymea1)[3];
  real_T (*c1_ydelay)[4];
  c1_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ydelay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(7, 1), false);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    c1_u[c1_i0] = (*c1_ydelay)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_b_u[c1_i1] = (*c1_ymea1)[c1_i1];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    c1_c_u[c1_i2] = (*c1_ynetwork_delay)[c1_i2];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    c1_d_u[c1_i3] = chartInstance->c1_delay1[c1_i3];
  }

  c1_e_y = NULL;
  if (!chartInstance->c1_delay1_not_empty) {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1, 4),
                  false);
  }

  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_hoistedGlobal = chartInstance->c1_i;
  c1_e_u = c1_hoistedGlobal;
  c1_f_y = NULL;
  if (!chartInstance->c1_i_not_empty) {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c1_y, 4, c1_f_y);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    c1_f_u[c1_i4] = chartInstance->c1_last_emergency_instance[c1_i4];
  }

  c1_g_y = NULL;
  if (!chartInstance->c1_last_emergency_instance_not_empty) {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 2, 1, 3),
                  false);
  }

  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_CoupledTanks;
  c1_g_u = c1_b_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[4];
  int32_T c1_i5;
  real_T c1_dv1[3];
  int32_T c1_i6;
  real_T c1_dv2[3];
  int32_T c1_i7;
  real_T c1_dv3[4];
  int32_T c1_i8;
  real_T c1_dv4[3];
  int32_T c1_i9;
  real_T (*c1_ydelay)[4];
  real_T (*c1_ymea1)[3];
  real_T (*c1_ynetwork_delay)[3];
  c1_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ydelay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "ydelay", c1_dv0);
  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    (*c1_ydelay)[c1_i5] = c1_dv0[c1_i5];
  }

  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "ymea1", c1_dv1);
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    (*c1_ymea1)[c1_i6] = c1_dv1[c1_i6];
  }

  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "ynetwork_delay", c1_dv2);
  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    (*c1_ynetwork_delay)[c1_i7] = c1_dv2[c1_i7];
  }

  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
                        "delay1", c1_dv3);
  for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
    chartInstance->c1_delay1[c1_i8] = c1_dv3[c1_i8];
  }

  chartInstance->c1_i = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 4)), "i");
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
                        "last_emergency_instance", c1_dv4);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    chartInstance->c1_last_emergency_instance[c1_i9] = c1_dv4[c1_i9];
  }

  chartInstance->c1_is_active_c1_CoupledTanks = c1_s_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
     "is_active_c1_CoupledTanks");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_CoupledTanks(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance)
{
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T (*c1_ynetwork_delay)[3];
  real_T (*c1_ydelay)[4];
  real_T (*c1_ymea)[3];
  real_T (*c1_ymea1)[3];
  c1_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ydelay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c1_ymea1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_CoupledTanks(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CoupledTanksMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    _SFD_DATA_RANGE_CHECK((*c1_ymea1)[c1_i10], 0U);
  }

  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    _SFD_DATA_RANGE_CHECK((*c1_ymea)[c1_i11], 1U);
  }

  for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
    _SFD_DATA_RANGE_CHECK((*c1_ydelay)[c1_i12], 2U);
  }

  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    _SFD_DATA_RANGE_CHECK((*c1_ynetwork_delay)[c1_i13], 5U);
  }
}

static void c1_chartstep_c1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
  *chartInstance)
{
  int32_T c1_i14;
  real_T c1_ymea[3];
  uint32_T c1_debug_family_var_map[17];
  real_T c1_emergency_instance[3];
  real_T c1_call_count;
  real_T c1_rssi;
  const mxArray *c1_resultz = NULL;
  const mxArray *c1_end_to_end_delivery_result_aggregated = NULL;
  const mxArray *c1_delay = NULL;
  real_T c1_network_delay[3];
  real_T c1_i_yg;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 3.0;
  real_T c1_ymea1[3];
  real_T c1_ydelay[4];
  real_T c1_ynetwork_delay[3];
  int32_T c1_i15;
  static real_T c1_dv5[4] = { 1.0, 0.0, 0.0, 0.0 };

  int32_T c1_i16;
  int32_T c1_i17;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_i18;
  real_T c1_c_u[3];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i19;
  static char_T c1_cv0[37] = { 'e', 'n', 'd', '_', 't', 'o', '_', 'e', 'n', 'd',
    '_', 'd', 'e', 'l', 'i', 'v', 'e', 'r', 'y', '_', 'r', 'e', 's', 'u', 'l',
    't', '_', 'a', 'g', 'g', 'r', 'e', 'g', 'a', 't', 'e', 'd' };

  char_T c1_d_u[37];
  const mxArray *c1_d_y = NULL;
  real_T c1_dv6[4];
  int32_T c1_i20;
  const mxArray *c1_result;
  uint32_T c1_b_debug_family_var_map[7];
  real_T c1_result_num[6];
  real_T c1_sz_y;
  real_T c1_i_rn;
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_i21;
  real_T c1_dv7[6];
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_b_i_rn;
  int32_T c1_i24;
  static char_T c1_cv1[6] = { 'r', 'e', 's', 'u', 'l', 't' };

  char_T c1_e_u[6];
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  static char_T c1_cv2[13] = { 'n', 'e', 't', 'w', 'o', 'r', 'k', ' ', 'd', 'e',
    'l', 'a', 'y' };

  char_T c1_g_u[13];
  const mxArray *c1_g_y = NULL;
  int32_T c1_i28;
  real_T c1_h_u[3];
  const mxArray *c1_h_y = NULL;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_b_i_yg;
  real_T c1_d0;
  int32_T c1_i33;
  int32_T c1_i34;
  static char_T c1_cv3[39] = { 'P', 'l', 'a', 'n', 't', ' ', '1', ',', ' ', 'T',
    'O', 'S', 'S', 'I', 'M', ' ', 'U', 'p', 'l', 'i', 'n', 'k', ' ', 'B', 'l',
    'o', 'c', 'k', ',', ' ', 'i', 's', ' ', 'c', 'a', 'l', 'l', 'e', 'd' };

  char_T c1_i_u[39];
  const mxArray *c1_i_y = NULL;
  int64_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  real_T (*c1_b_ymea1)[3];
  real_T (*c1_b_ydelay)[4];
  real_T (*c1_b_ynetwork_delay)[3];
  real_T (*c1_b_ymea)[3];
  c1_b_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_ydelay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_ymea = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_ymea1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_ymea[c1_i14] = (*c1_b_ymea)[c1_i14];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_emergency_instance, 0U,
    c1_g_sf_marshallOut, c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_call_count, 1U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_rssi, 2U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_resultz, 3U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_end_to_end_delivery_result_aggregated, 4U,
    c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_delay, 5U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_network_delay, 6U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_yg, 7U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 8U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 9U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_ymea, 10U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ymea1, 11U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ydelay, 12U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ynetwork_delay, 13U,
    c1_d_sf_marshallOut, c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_delay1, 14U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_i, 15U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_last_emergency_instance,
    16U, c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c1_i_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
    chartInstance->c1_i = 0.0;
    chartInstance->c1_i_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
  for (c1_i15 = 0; c1_i15 < 4; c1_i15++) {
    c1_ydelay[c1_i15] = c1_dv5[c1_i15];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_ynetwork_delay[c1_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
    c1_emergency_instance[c1_i17] = c1_ymea[c1_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
  c1_call_count = 20.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
  c1_rssi = -74.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
  c1_u = c1_call_count;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  c1_b_u = c1_rssi;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c1_i18 = 0; c1_i18 < 3; c1_i18++) {
    c1_c_u[c1_i18] = c1_emergency_instance[c1_i18];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 3),
                false);
  sf_mex_assign(&c1_resultz, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "ps_aggregation", 1U, 3U, 14, c1_y, 14, c1_b_y, 14, c1_c_y), false);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
  sf_mex_printf("%s =\\n", "resultz");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, sf_mex_dup
                    (c1_resultz));
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
  sf_mex_assign(&c1_end_to_end_delivery_result_aggregated, sf_mex_call_debug
                (sfGlobalDebugInstanceStruct, "sum", 1U, 1U, 14, sf_mex_dup
                 (c1_resultz)), false);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
  for (c1_i19 = 0; c1_i19 < 37; c1_i19++) {
    c1_d_u[c1_i19] = c1_cv0[c1_i19];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 10, 0U, 1U, 0U, 2, 1, 37),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_d_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, sf_mex_dup
                    (c1_end_to_end_delivery_result_aggregated));
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
  sf_mex_assign(&c1_delay, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "delay_summary", 1U, 1U, 14, sf_mex_dup
    (c1_end_to_end_delivery_result_aggregated)), false);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
  c1_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "transpose", 1U, 1U, 14,
                       sf_mex_dup(c1_delay)), "transpose", c1_dv6);
  for (c1_i20 = 0; c1_i20 < 4; c1_i20++) {
    c1_ydelay[c1_i20] = c1_dv6[c1_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
  c1_result = sf_mex_dup(c1_end_to_end_delivery_result_aggregated);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_b_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_result_num, 0U, c1_i_sf_marshallOut,
    c1_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_sz_y, 1U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_rn, 2U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 3U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 4U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_result, 5U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_network_delay, 6U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  if (CV_SCRIPT_IF(0, 0, CV_SCRIPT_MCDC(0, 0, !CV_SCRIPT_COND(0, 0,
         c1_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
          (sfGlobalDebugInstanceStruct, "isempty", 1U, 1U, 14, sf_mex_dup
           (c1_result)), "isempty"))))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 5);
    for (c1_i21 = 0; c1_i21 < 6; c1_i21++) {
      c1_result_num[c1_i21] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
    c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_result), "result", c1_dv7);
    for (c1_i22 = 0; c1_i22 < 6; c1_i22++) {
      c1_result_num[c1_i22] = c1_dv7[c1_i22];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
    c1_sz_y = 3.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
    for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
      c1_network_delay[c1_i23] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
    c1_i_rn = 1.0;
    c1_b_i_rn = 0;
    while (c1_b_i_rn < 3) {
      c1_i_rn = 1.0 + (real_T)c1_b_i_rn;
      CV_SCRIPT_FOR(0, 0, 1);
      _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
      for (c1_i24 = 0; c1_i24 < 6; c1_i24++) {
        c1_e_u[c1_i24] = c1_cv1[c1_i24];
      }

      c1_e_y = NULL;
      sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 10, 0U, 1U, 0U, 2, 1, 6),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_e_y);
      _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 12);
      c1_f_u = c1_result_num[_SFD_EML_ARRAY_BOUNDS_CHECK("result_num", (int32_T)
        _SFD_INTEGER_CHECK("3+i_rn", 3.0 + c1_i_rn), 1, 6, 1, 0) - 1];
      c1_f_y = NULL;
      sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_f_y);
      _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 13);
      if (CV_SCRIPT_IF(0, 1, c1_result_num[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "result_num", (int32_T)_SFD_INTEGER_CHECK("3+i_rn", 3.0 + c1_i_rn),
            1, 6, 1, 0) - 1] >= 0.0)) {
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 14);
        c1_network_delay[_SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
          _SFD_INTEGER_CHECK("i_rn", c1_i_rn), 1, 3, 2, 0) - 1] =
          c1_result_num[_SFD_EML_ARRAY_BOUNDS_CHECK("result_num", (int32_T)
          _SFD_INTEGER_CHECK("3+i_rn", 3.0 + c1_i_rn), 1, 6, 1, 0) - 1];
      } else {
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 16);
        c1_network_delay[_SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
          _SFD_INTEGER_CHECK("i_rn", c1_i_rn), 1, 3, 2, 0) - 1] =
          c1_network_delay[_SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
          _SFD_INTEGER_CHECK("i_rn", c1_i_rn), 1, 3, 2, 0) - 1];
      }

      c1_b_i_rn++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_SCRIPT_FOR(0, 0, 0);
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 20);
    for (c1_i25 = 0; c1_i25 < 3; c1_i25++) {
      c1_network_delay[c1_i25] = 0.0;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c1_result);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
  for (c1_i26 = 0; c1_i26 < 3; c1_i26++) {
    c1_ynetwork_delay[c1_i26] = c1_network_delay[c1_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
  for (c1_i27 = 0; c1_i27 < 13; c1_i27++) {
    c1_g_u[c1_i27] = c1_cv2[c1_i27];
  }

  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_g_u, 10, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_g_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
  for (c1_i28 = 0; c1_i28 < 3; c1_i28++) {
    c1_h_u[c1_i28] = c1_ynetwork_delay[c1_i28];
  }

  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_h_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_h_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
  for (c1_i29 = 0; c1_i29 < 3; c1_i29++) {
    chartInstance->c1_last_emergency_instance[c1_i29] = c1_ymea[c1_i29];
  }

  chartInstance->c1_last_emergency_instance_not_empty = true;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
  for (c1_i30 = 0; c1_i30 < 4; c1_i30++) {
    chartInstance->c1_delay1[c1_i30] = c1_ydelay[c1_i30];
  }

  chartInstance->c1_delay1_not_empty = true;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 58);
  chartInstance->c1_i++;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
  for (c1_i31 = 0; c1_i31 < 3; c1_i31++) {
    c1_ymea1[c1_i31] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
  for (c1_i32 = 0; c1_i32 < 3; c1_i32++) {
    c1_ymea1[c1_i32] = c1_ymea[c1_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 69);
  c1_i_yg = 1.0;
  c1_b_i_yg = 0;
  while (c1_b_i_yg < 4) {
    c1_i_yg = 1.0 + (real_T)c1_b_i_yg;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 70);
    c1_d0 = muDoubleScalarRound(c1_ydelay[_SFD_EML_ARRAY_BOUNDS_CHECK("ydelay",
                                 (int32_T)_SFD_INTEGER_CHECK("i_yg", c1_i_yg), 1,
      4, 1, 0) - 1]);
    if (c1_d0 < 2.147483648E+9) {
      if (CV_SATURATION_EVAL(4, 0, 0, 1, c1_d0 >= -2.147483648E+9)) {
        c1_i33 = (int32_T)c1_d0;
      } else {
        c1_i33 = MIN_int32_T;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c1_d0 >= 2.147483648E+9)) {
      c1_i33 = MAX_int32_T;
    } else {
      c1_i33 = 0;
    }

    c1_set_ydelay_global(chartInstance, _SFD_EML_ARRAY_BOUNDS_CHECK(
      "ydelay_global", (int32_T)_SFD_INTEGER_CHECK("i_yg", c1_i_yg), 1, 15, 1, 0)
                         - 1, c1_i33);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    c1_b_i_yg++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 73);
  for (c1_i34 = 0; c1_i34 < 39; c1_i34++) {
    c1_i_u[c1_i34] = c1_cv3[c1_i34];
  }

  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_i_u, 10, 0U, 1U, 0U, 2, 1, 39),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_i_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 74);
  c1_i35 = (int64_T)c1_get_counter_global(chartInstance, 0) + 1L;
  if (c1_i35 > 2147483647L) {
    CV_SATURATION_EVAL(4, 0, 1, 0, 1);
    c1_i35 = 2147483647L;
  } else {
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c1_i35 < -2147483648L)) {
      c1_i35 = -2147483648L;
    }
  }

  c1_set_counter_global(chartInstance, 0, (int32_T)c1_i35);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -74);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c1_resultz);
  sf_mex_destroy(&c1_end_to_end_delivery_result_aggregated);
  sf_mex_destroy(&c1_delay);
  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    (*c1_b_ymea1)[c1_i36] = c1_ymea1[c1_i36];
  }

  for (c1_i37 = 0; c1_i37 < 4; c1_i37++) {
    (*c1_b_ydelay)[c1_i37] = c1_ydelay[c1_i37];
  }

  for (c1_i38 = 0; c1_i38 < 3; c1_i38++) {
    (*c1_b_ynetwork_delay)[c1_i38] = c1_ynetwork_delay[c1_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_CoupledTanks(SFc1_CoupledTanksInstanceStruct
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
    "/Users/wangwenchen/wcps_apps/simple_example/network_delay_summary.m"));
}

static void c1_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_transpose, const char_T *c1_identifier, real_T c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_transpose), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_transpose);
}

static void c1_b_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv8[4];
  int32_T c1_i39;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv8, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i39 = 0; c1_i39 < 4; c1_i39++) {
    c1_y[c1_i39] = c1_dv8[c1_i39];
  }

  sf_mex_destroy(&c1_u);
}

static boolean_T c1_c_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_isempty, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_isempty), &c1_thisId);
  sf_mex_destroy(&c1_isempty);
  return c1_y;
}

static boolean_T c1_d_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
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

static void c1_e_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_result, const char_T *c1_identifier, real_T c1_y[6])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_result), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_result);
}

static void c1_f_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[6])
{
  real_T c1_dv9[6];
  int32_T c1_i40;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv9, 1, 0, 0U, 1, 0U, 2, 1, 6);
  for (c1_i40 = 0; c1_i40 < 6; c1_i40++) {
    c1_y[c1_i40] = c1_dv9[c1_i40];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i41;
  real_T c1_b_inData[3];
  int32_T c1_i42;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i41 = 0; c1_i41 < 3; c1_i41++) {
    c1_b_inData[c1_i41] = (*(real_T (*)[3])c1_inData)[c1_i41];
  }

  for (c1_i42 = 0; c1_i42 < 3; c1_i42++) {
    c1_u[c1_i42] = c1_b_inData[c1_i42];
  }

  c1_y = NULL;
  if (!chartInstance->c1_last_emergency_instance_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_b_last_emergency_instance, const char_T *c1_identifier,
  real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_last_emergency_instance),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_last_emergency_instance);
}

static void c1_h_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv10[3];
  int32_T c1_i43;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_last_emergency_instance_not_empty = false;
  } else {
    chartInstance->c1_last_emergency_instance_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv10, 1, 0, 0U, 1, 0U, 2, 1,
                  3);
    for (c1_i43 = 0; c1_i43 < 3; c1_i43++) {
      c1_y[c1_i43] = c1_dv10[c1_i43];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_last_emergency_instance;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i44;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_b_last_emergency_instance = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_last_emergency_instance),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_last_emergency_instance);
  for (c1_i44 = 0; c1_i44 < 3; c1_i44++) {
    (*(real_T (*)[3])c1_outData)[c1_i44] = c1_y[c1_i44];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
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

static real_T c1_i_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_b_i, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_i), &c1_thisId);
  sf_mex_destroy(&c1_b_i);
  return c1_y;
}

static real_T c1_j_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
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
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_b_i = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_i), &c1_thisId);
  sf_mex_destroy(&c1_b_i);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i45;
  real_T c1_b_inData[4];
  int32_T c1_i46;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i45 = 0; c1_i45 < 4; c1_i45++) {
    c1_b_inData[c1_i45] = (*(real_T (*)[4])c1_inData)[c1_i45];
  }

  for (c1_i46 = 0; c1_i46 < 4; c1_i46++) {
    c1_u[c1_i46] = c1_b_inData[c1_i46];
  }

  c1_y = NULL;
  if (!chartInstance->c1_delay1_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), false);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_k_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_b_delay1, const char_T *c1_identifier, real_T c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_delay1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_delay1);
}

static void c1_l_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv11[4];
  int32_T c1_i47;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_delay1_not_empty = false;
  } else {
    chartInstance->c1_delay1_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv11, 1, 0, 0U, 1, 0U, 1, 4);
    for (c1_i47 = 0; c1_i47 < 4; c1_i47++) {
      c1_y[c1_i47] = c1_dv11[c1_i47];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_delay1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i48;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_b_delay1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_delay1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_delay1);
  for (c1_i48 = 0; c1_i48 < 4; c1_i48++) {
    (*(real_T (*)[4])c1_outData)[c1_i48] = c1_y[c1_i48];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i49;
  real_T c1_b_inData[3];
  int32_T c1_i50;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i49 = 0; c1_i49 < 3; c1_i49++) {
    c1_b_inData[c1_i49] = (*(real_T (*)[3])c1_inData)[c1_i49];
  }

  for (c1_i50 = 0; c1_i50 < 3; c1_i50++) {
    c1_u[c1_i50] = c1_b_inData[c1_i50];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_m_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_ynetwork_delay, const char_T *c1_identifier, real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ynetwork_delay), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_ynetwork_delay);
}

static void c1_n_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv12[3];
  int32_T c1_i51;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv12, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i51 = 0; c1_i51 < 3; c1_i51++) {
    c1_y[c1_i51] = c1_dv12[c1_i51];
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
  int32_T c1_i52;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_ynetwork_delay = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ynetwork_delay), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_ynetwork_delay);
  for (c1_i52 = 0; c1_i52 < 3; c1_i52++) {
    (*(real_T (*)[3])c1_outData)[c1_i52] = c1_y[c1_i52];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i53;
  real_T c1_b_inData[4];
  int32_T c1_i54;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i53 = 0; c1_i53 < 4; c1_i53++) {
    c1_b_inData[c1_i53] = (*(real_T (*)[4])c1_inData)[c1_i53];
  }

  for (c1_i54 = 0; c1_i54 < 4; c1_i54++) {
    c1_u[c1_i54] = c1_b_inData[c1_i54];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_transpose;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i55;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_transpose = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_transpose), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_transpose);
  for (c1_i55 = 0; c1_i55 < 4; c1_i55++) {
    (*(real_T (*)[4])c1_outData)[c1_i55] = c1_y[c1_i55];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_o_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
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

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i56;
  real_T c1_b_inData[3];
  int32_T c1_i57;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i56 = 0; c1_i56 < 3; c1_i56++) {
    c1_b_inData[c1_i56] = (*(real_T (*)[3])c1_inData)[c1_i56];
  }

  for (c1_i57 = 0; c1_i57 < 3; c1_i57++) {
    c1_u[c1_i57] = c1_b_inData[c1_i57];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_p_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv13[3];
  int32_T c1_i58;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv13, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i58 = 0; c1_i58 < 3; c1_i58++) {
    c1_y[c1_i58] = c1_dv13[c1_i58];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_network_delay;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i59;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_network_delay = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_network_delay), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_network_delay);
  for (c1_i59 = 0; c1_i59 < 3; c1_i59++) {
    (*(real_T (*)[3])c1_outData)[c1_i59] = c1_y[c1_i59];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  const mxArray *c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = sf_mex_dup(*(const mxArray **)c1_inData);
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i60;
  real_T c1_b_inData[6];
  int32_T c1_i61;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i60 = 0; c1_i60 < 6; c1_i60++) {
    c1_b_inData[c1_i60] = (*(real_T (*)[6])c1_inData)[c1_i60];
  }

  for (c1_i61 = 0; c1_i61 < 6; c1_i61++) {
    c1_u[c1_i61] = c1_b_inData[c1_i61];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_result;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[6];
  int32_T c1_i62;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_result = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_result), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_result);
  for (c1_i62 = 0; c1_i62 < 6; c1_i62++) {
    (*(real_T (*)[6])c1_outData)[c1_i62] = c1_y[c1_i62];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_CoupledTanks_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
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
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("sum"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mxArray"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("network_delay_summary"),
                  "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mxArray"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]/Users/wangwenchen/wcps_apps/simple_example/network_delay_summary.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1452289429U), "fileTimeLo",
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]/Users/wangwenchen/wcps_apps/simple_example/network_delay_summary.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("disp"), "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]/Users/wangwenchen/wcps_apps/simple_example/network_delay_summary.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("disp"), "name", "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
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

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_q_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i63;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i63, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i63;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i64;
  int32_T c1_b_inData[15];
  int32_T c1_i65;
  int32_T c1_u[15];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i64 = 0; c1_i64 < 15; c1_i64++) {
    c1_b_inData[c1_i64] = (*(int32_T (*)[15])c1_inData)[c1_i64];
  }

  for (c1_i65 = 0; c1_i65 < 15; c1_i65++) {
    c1_u[c1_i65] = c1_b_inData[c1_i65];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 6, 0U, 1U, 0U, 1, 15), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_r_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, int32_T c1_y[15])
{
  int32_T c1_iv0[15];
  int32_T c1_i66;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_iv0, 1, 6, 0U, 1, 0U, 1, 15);
  for (c1_i66 = 0; c1_i66 < 15; c1_i66++) {
    c1_y[c1_i66] = c1_iv0[c1_i66];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_ydelay_global;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y[15];
  int32_T c1_i67;
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c1_ydelay_global = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ydelay_global), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_ydelay_global);
  for (c1_i67 = 0; c1_i67 < 15; c1_i67++) {
    (*(int32_T (*)[15])c1_outData)[c1_i67] = c1_y[c1_i67];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_s_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_CoupledTanks, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_t_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_CoupledTanks), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_CoupledTanks);
  return c1_y;
}

static uint8_T c1_t_emlrt_marshallIn(SFc1_CoupledTanksInstanceStruct
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

static int32_T c1_get_counter_global(SFc1_CoupledTanksInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#28) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_counter_global_address;
}

static void c1_set_counter_global(SFc1_CoupledTanksInstanceStruct *chartInstance,
  uint32_T c1_b, int32_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#28) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_counter_global_address = c1_c;
}

static int32_T *c1_access_counter_global(SFc1_CoupledTanksInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  int32_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c1_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#28) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_counter_global_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c1_c;
}

static int32_T c1_get_ydelay_global(SFc1_CoupledTanksInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#27) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_ydelay_global_address)[c1_b];
}

static void c1_set_ydelay_global(SFc1_CoupledTanksInstanceStruct *chartInstance,
  uint32_T c1_b, int32_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#27) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_ydelay_global_address)[c1_b] = c1_c;
}

static int32_T *c1_access_ydelay_global(SFc1_CoupledTanksInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  int32_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c1_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#27) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_ydelay_global_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c1_c;
}

static void init_dsm_address_info(SFc1_CoupledTanksInstanceStruct *chartInstance)
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

void sf_c1_CoupledTanks_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1499496779U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3565761188U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2076458442U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3034217160U);
}

mxArray *sf_c1_CoupledTanks_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NdYmIJQmAP9ZaU9RBN8yNE");
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
      pr[0] = (double)(4);
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

mxArray *sf_c1_CoupledTanks_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_CoupledTanks_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_CoupledTanks(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"ydelay\",},{M[1],M[7],T\"ymea1\",},{M[1],M[13],T\"ynetwork_delay\",},{M[4],M[0],T\"delay1\",S'l','i','p'{{M1x2[184 190],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[216 217],M[0],}}},{M[4],M[0],T\"last_emergency_instance\",S'l','i','p'{{M1x2[238 261],M[0],}}},{M[8],M[0],T\"is_active_c1_CoupledTanks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_CoupledTanks_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_CoupledTanksInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_CoupledTanksInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CoupledTanksMachineNumber_,
           1,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_CoupledTanksMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CoupledTanksMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CoupledTanksMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"ymea1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ymea");
          _SFD_SET_DATA_PROPS(2,2,0,1,"ydelay");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,2,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2105);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,1973,-1,2013);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,2086,-1,2104);
        _SFD_CV_INIT_EML_IF(0,1,0,598,611,-1,626);
        _SFD_CV_INIT_EML_FOR(0,1,0,1954,1969,2018);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,1,0,1,1);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"network_delay_summary",0,-1,624);
        _SFD_CV_INIT_SCRIPT_IF(0,0,136,156,597,624);
        _SFD_CV_INIT_SCRIPT_IF(0,1,423,449,515,584);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,329,347,596);

        {
          static int condStart[] = { 140 };

          static int condEnd[] = { 155 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,139,155,1,0,&(condStart[0]),&(condEnd[0]),
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
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 15;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_k_sf_marshallOut,(MexInFcnForType)
            c1_j_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)c1_i_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          real_T (*c1_ymea1)[3];
          real_T (*c1_ymea)[3];
          real_T (*c1_ydelay)[4];
          real_T (*c1_ynetwork_delay)[3];
          c1_ynetwork_delay = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 3);
          c1_ydelay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_ymea = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          c1_ymea1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_ymea1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_ymea);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_ydelay);
          _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c1_ydelay_global_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c1_counter_global_address);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_ynetwork_delay);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CoupledTanksMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "o2gn8ZtKQDm9vZ7T2bL4VH";
}

static void sf_opaque_initialize_c1_CoupledTanks(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_CoupledTanksInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_CoupledTanks((SFc1_CoupledTanksInstanceStruct*)
    chartInstanceVar);
  initialize_c1_CoupledTanks((SFc1_CoupledTanksInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_CoupledTanks(void *chartInstanceVar)
{
  enable_c1_CoupledTanks((SFc1_CoupledTanksInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_CoupledTanks(void *chartInstanceVar)
{
  disable_c1_CoupledTanks((SFc1_CoupledTanksInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_CoupledTanks(void *chartInstanceVar)
{
  sf_gateway_c1_CoupledTanks((SFc1_CoupledTanksInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_CoupledTanks(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_CoupledTanks
    ((SFc1_CoupledTanksInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_CoupledTanks();/* state var info */
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

extern void sf_internal_set_sim_state_c1_CoupledTanks(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_CoupledTanks();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_CoupledTanks((SFc1_CoupledTanksInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_CoupledTanks(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_CoupledTanks(S);
}

static void sf_opaque_set_sim_state_c1_CoupledTanks(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c1_CoupledTanks(S, st);
}

static void sf_opaque_terminate_c1_CoupledTanks(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_CoupledTanksInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CoupledTanks_optimization_info();
    }

    finalize_c1_CoupledTanks((SFc1_CoupledTanksInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_CoupledTanks((SFc1_CoupledTanksInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_CoupledTanks(SimStruct *S)
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
    initialize_params_c1_CoupledTanks((SFc1_CoupledTanksInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_CoupledTanks(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CoupledTanks_optimization_info();
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
  ssSetChecksum0(S,(3796494999U));
  ssSetChecksum1(S,(1377710539U));
  ssSetChecksum2(S,(3834853998U));
  ssSetChecksum3(S,(780023139U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c1_CoupledTanks(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_CoupledTanks(SimStruct *S)
{
  SFc1_CoupledTanksInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_CoupledTanksInstanceStruct *)utMalloc(sizeof
    (SFc1_CoupledTanksInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_CoupledTanksInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_CoupledTanks;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_CoupledTanks;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_CoupledTanks;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_CoupledTanks;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_CoupledTanks;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_CoupledTanks;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_CoupledTanks;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_CoupledTanks;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_CoupledTanks;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_CoupledTanks;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_CoupledTanks;
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

void c1_CoupledTanks_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_CoupledTanks(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_CoupledTanks(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_CoupledTanks(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_CoupledTanks_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
