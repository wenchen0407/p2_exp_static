/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CoupledTanks_WCPS_Event_sfun.h"
#include "c1_CoupledTanks_WCPS_Event.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CoupledTanks_WCPS_Event_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[14] = { "emergency_instance", "emgi",
  "result", "status", "delay", "nargin", "nargout", "ymea", "ymea1", "ydelay",
  "delay1", "i", "last_emergency_instance", "RetransCounter" };

/* Function Declarations */
static void initialize_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void initialize_params_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void enable_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void disable_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void set_sim_state_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void sf_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void c1_chartstep_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void initSimStructsc1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void registerMessagesc1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_b_RetransCounter, const char_T
  *c1_identifier, real_T c1_y[5]);
static void c1_b_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_b_last_emergency_instance, const char_T
  *c1_identifier, real_T c1_y[5]);
static void c1_d_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_b_i, const char_T *c1_identifier);
static real_T c1_f_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_b_delay1, const char_T *c1_identifier,
  real_T c1_y[8]);
static void c1_h_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_i_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_ymea1, const char_T *c1_identifier, real_T
  c1_y[5]);
static void c1_j_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_k_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_l_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[60]);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_m_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5]);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_n_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_transpose, const char_T *c1_identifier,
  real_T c1_y[8]);
static void c1_o_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8]);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_p_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_q_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_CoupledTanks_WCPS_Event, const
  char_T *c1_identifier);
static uint8_T c1_r_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_delay1_not_empty = FALSE;
  chartInstance->c1_i_not_empty = FALSE;
  chartInstance->c1_last_emergency_instance_not_empty = FALSE;
  chartInstance->c1_RetransCounter_not_empty = FALSE;
  chartInstance->c1_is_active_c1_CoupledTanks_WCPS_Event = 0U;
}

static void initialize_params_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void enable_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[8];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i1;
  real_T c1_b_u[5];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i2;
  real_T c1_c_u[5];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i3;
  real_T c1_d_u[8];
  const mxArray *c1_e_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  int32_T c1_i4;
  real_T c1_f_u[5];
  const mxArray *c1_g_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T (*c1_ymea1)[5];
  real_T (*c1_ydelay)[8];
  c1_ydelay = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea1 = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(7), FALSE);
  for (c1_i0 = 0; c1_i0 < 8; c1_i0++) {
    c1_u[c1_i0] = (*c1_ydelay)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 8), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i1 = 0; c1_i1 < 5; c1_i1++) {
    c1_b_u[c1_i1] = (*c1_ymea1)[c1_i1];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i2 = 0; c1_i2 < 5; c1_i2++) {
    c1_c_u[c1_i2] = chartInstance->c1_RetransCounter[c1_i2];
  }

  c1_d_y = NULL;
  if (!chartInstance->c1_RetransCounter_not_empty) {
    sf_mex_assign(&c1_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 2, c1_d_y);
  for (c1_i3 = 0; c1_i3 < 8; c1_i3++) {
    c1_d_u[c1_i3] = chartInstance->c1_delay1[c1_i3];
  }

  c1_e_y = NULL;
  if (!chartInstance->c1_delay1_not_empty) {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1, 8),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_hoistedGlobal = chartInstance->c1_i;
  c1_e_u = c1_hoistedGlobal;
  c1_f_y = NULL;
  if (!chartInstance->c1_i_not_empty) {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 4, c1_f_y);
  for (c1_i4 = 0; c1_i4 < 5; c1_i4++) {
    c1_f_u[c1_i4] = chartInstance->c1_last_emergency_instance[c1_i4];
  }

  c1_g_y = NULL;
  if (!chartInstance->c1_last_emergency_instance_not_empty) {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_CoupledTanks_WCPS_Event;
  c1_g_u = c1_b_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[8];
  int32_T c1_i5;
  real_T c1_dv1[5];
  int32_T c1_i6;
  real_T c1_dv2[5];
  int32_T c1_i7;
  real_T c1_dv3[8];
  int32_T c1_i8;
  real_T c1_dv4[5];
  int32_T c1_i9;
  real_T (*c1_ydelay)[8];
  real_T (*c1_ymea1)[5];
  c1_ydelay = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea1 = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "ydelay", c1_dv0);
  for (c1_i5 = 0; c1_i5 < 8; c1_i5++) {
    (*c1_ydelay)[c1_i5] = c1_dv0[c1_i5];
  }

  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "ymea1", c1_dv1);
  for (c1_i6 = 0; c1_i6 < 5; c1_i6++) {
    (*c1_ymea1)[c1_i6] = c1_dv1[c1_i6];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                      "RetransCounter", c1_dv2);
  for (c1_i7 = 0; c1_i7 < 5; c1_i7++) {
    chartInstance->c1_RetransCounter[c1_i7] = c1_dv2[c1_i7];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
                        "delay1", c1_dv3);
  for (c1_i8 = 0; c1_i8 < 8; c1_i8++) {
    chartInstance->c1_delay1[c1_i8] = c1_dv3[c1_i8];
  }

  chartInstance->c1_i = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 4)), "i");
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
                        "last_emergency_instance", c1_dv4);
  for (c1_i9 = 0; c1_i9 < 5; c1_i9++) {
    chartInstance->c1_last_emergency_instance[c1_i9] = c1_dv4[c1_i9];
  }

  chartInstance->c1_is_active_c1_CoupledTanks_WCPS_Event = c1_q_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
     "is_active_c1_CoupledTanks_WCPS_Event");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_CoupledTanks_WCPS_Event(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void sf_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  real_T (*c1_ydelay)[8];
  real_T (*c1_ymea)[5];
  real_T (*c1_ymea1)[5];
  c1_ydelay = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  c1_ymea1 = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i10 = 0; c1_i10 < 5; c1_i10++) {
    _SFD_DATA_RANGE_CHECK((*c1_ymea1)[c1_i10], 0U);
  }

  for (c1_i11 = 0; c1_i11 < 5; c1_i11++) {
    _SFD_DATA_RANGE_CHECK((*c1_ymea)[c1_i11], 1U);
  }

  for (c1_i12 = 0; c1_i12 < 8; c1_i12++) {
    _SFD_DATA_RANGE_CHECK((*c1_ydelay)[c1_i12], 2U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_CoupledTanks_WCPS_Event(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CoupledTanks_WCPS_EventMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  int32_T c1_i13;
  real_T c1_ymea[5];
  uint32_T c1_debug_family_var_map[14];
  real_T c1_emergency_instance[5];
  real_T c1_emgi;
  const mxArray *c1_result = NULL;
  const mxArray *c1_status = NULL;
  const mxArray *c1_delay = NULL;
  char_T c1_b_result[60];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 2.0;
  real_T c1_ymea1[5];
  real_T c1_ydelay[8];
  int32_T c1_i14;
  int32_T c1_i15;
  real_T c1_hoistedGlobal[5];
  int32_T c1_i16;
  real_T c1_u[5];
  const mxArray *c1_y = NULL;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  real_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i20;
  static real_T c1_dv5[8] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c1_i21;
  int32_T c1_b_emgi;
  int32_T c1_c_emgi;
  int32_T c1_i22;
  static char_T c1_cv0[16] = { 't', 'o', 's', 's', 'i', 'm', '-', 'c', 'l', 'i',
    'e', 'n', 't', '.', 'p', 'y' };

  char_T c1_c_u[16];
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_b_status = NULL;
  const mxArray *c1_c_result = NULL;
  int32_T c1_i23;
  static char_T c1_cv1[60] = { '5', ',', ' ', '8', ',', ' ', '1', '7', '3', ',',
    ' ', '1', '6', '9', ',', ' ', '2', '4', ',', ' ', '7', ',', ' ', '2', '2',
    ',', ' ', '1', '7', '0', ',', ' ', '1', '5', '7', ',', ' ', '2', '4', ',',
    ' ', '6', ',', ' ', '2', '2', ',', ' ', '1', '7', '2', ',', ' ', '1', '8',
    '0', ',', ' ', '2', '3' };

  int32_T c1_i24;
  char_T c1_i_u[60];
  const mxArray *c1_i_y = NULL;
  real_T c1_dv6[8];
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  real_T (*c1_b_ymea1)[5];
  real_T (*c1_b_ydelay)[8];
  real_T (*c1_b_ymea)[5];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c1_b_ydelay = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_ymea = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_ymea1 = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i13 = 0; c1_i13 < 5; c1_i13++) {
    c1_ymea[c1_i13] = (*c1_b_ymea)[c1_i13];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 15U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_emergency_instance, 0U,
    c1_j_sf_marshallOut, c1_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_emgi, 1U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_result, MAX_uint32_T, c1_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_status, 3U, c1_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_delay, 4U, c1_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_result, MAX_uint32_T,
    c1_h_sf_marshallOut, c1_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 5U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 6U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_ymea, 7U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ymea1, 8U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ydelay, 9U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_delay1, 10U,
    c1_d_sf_marshallOut, c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_i, 11U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_last_emergency_instance,
    12U, c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_RetransCounter, 13U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c1_i_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
    chartInstance->c1_i = 0.0;
    chartInstance->c1_i_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c1_last_emergency_instance_not_empty))
  {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
    for (c1_i14 = 0; c1_i14 < 5; c1_i14++) {
      chartInstance->c1_last_emergency_instance[c1_i14] = 0.0;
    }

    chartInstance->c1_last_emergency_instance_not_empty = TRUE;
    sf_mex_printf("%s =\\n", "last_emergency_instance");
    for (c1_i15 = 0; c1_i15 < 5; c1_i15++) {
      c1_hoistedGlobal[c1_i15] = chartInstance->
        c1_last_emergency_instance[c1_i15];
    }

    for (c1_i16 = 0; c1_i16 < 5; c1_i16++) {
      c1_u[c1_i16] = c1_hoistedGlobal[c1_i16];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
    sf_mex_call_debug("disp", 0U, 1U, 14, c1_y);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c1_RetransCounter_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
    for (c1_i17 = 0; c1_i17 < 5; c1_i17++) {
      chartInstance->c1_RetransCounter[c1_i17] = 0.0;
    }

    chartInstance->c1_RetransCounter_not_empty = TRUE;
    sf_mex_printf("%s =\\n", "RetransCounter");
    for (c1_i18 = 0; c1_i18 < 5; c1_i18++) {
      c1_hoistedGlobal[c1_i18] = chartInstance->c1_RetransCounter[c1_i18];
    }

    for (c1_i19 = 0; c1_i19 < 5; c1_i19++) {
      c1_b_u[c1_i19] = c1_hoistedGlobal[c1_i19];
    }

    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("disp", 0U, 1U, 14, c1_b_y);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  for (c1_i20 = 0; c1_i20 < 8; c1_i20++) {
    c1_ydelay[c1_i20] = c1_dv5[c1_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
  for (c1_i21 = 0; c1_i21 < 5; c1_i21++) {
    c1_emergency_instance[c1_i21] = c1_ymea[c1_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_emgi = 1.0;
  c1_b_emgi = 0;
  while (c1_b_emgi < 4) {
    c1_emgi = 1.0 + (real_T)c1_b_emgi;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
    guard1 = FALSE;
    guard2 = FALSE;
    guard3 = FALSE;
    guard4 = FALSE;
    if (CV_EML_COND(0, 1, 0, chartInstance->c1_last_emergency_instance[(int32_T)
                    (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "last_emergency_instance", (int32_T)_SFD_INTEGER_CHECK("emgi", c1_emgi),
          1, 5, 2, 0) - 1] == 1.0)) {
      if (CV_EML_COND(0, 1, 1, c1_emergency_instance[(int32_T)(real_T)
                      _SFD_EML_ARRAY_BOUNDS_CHECK("emergency_instance", (int32_T)
            _SFD_INTEGER_CHECK("emgi", c1_emgi), 1, 5, 2, 0) - 1] == 0.0)) {
        guard3 = TRUE;
      } else {
        guard4 = TRUE;
      }
    } else {
      guard4 = TRUE;
    }

    if (guard4 == TRUE) {
      if (CV_EML_COND(0, 1, 2, chartInstance->c1_last_emergency_instance
                      [(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
            "last_emergency_instance", (int32_T)_SFD_INTEGER_CHECK("emgi",
             c1_emgi), 1, 5, 2, 0) - 1] == 0.0)) {
        if (CV_EML_COND(0, 1, 3, c1_emergency_instance[(int32_T)(real_T)
                        _SFD_EML_ARRAY_BOUNDS_CHECK("emergency_instance",
              (int32_T)_SFD_INTEGER_CHECK("emgi", c1_emgi), 1, 5, 2, 0) - 1] ==
                        1.0)) {
          guard3 = TRUE;
        } else {
          guard2 = TRUE;
        }
      } else {
        guard2 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      if (CV_EML_COND(0, 1, 4, chartInstance->c1_RetransCounter[(int32_T)(real_T)
                      _SFD_EML_ARRAY_BOUNDS_CHECK("RetransCounter", (int32_T)
            _SFD_INTEGER_CHECK("emgi", c1_emgi), 1, 5, 2, 0) - 1] == 0.0)) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 3, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
        chartInstance->c1_RetransCounter[(int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("RetransCounter", (int32_T)
          _SFD_INTEGER_CHECK("emgi", c1_emgi), 1, 5, 2, 0) - 1] = 3.0;
      } else {
        guard1 = TRUE;
      }
    }

    if (guard2 == TRUE) {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 3, FALSE);
    }

    c1_b_emgi++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
  c1_emgi = 1.0;
  c1_c_emgi = 0;
  while (c1_c_emgi < 4) {
    c1_emgi = 1.0 + (real_T)c1_c_emgi;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
    if (CV_EML_IF(0, 1, 4, chartInstance->c1_RetransCounter[(int32_T)(real_T)
                  _SFD_EML_ARRAY_BOUNDS_CHECK("RetransCounter", (int32_T)
          _SFD_INTEGER_CHECK("emgi", c1_emgi), 1, 5, 2, 0) - 1] > 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
      c1_emergency_instance[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "emergency_instance", (int32_T)_SFD_INTEGER_CHECK("emgi", c1_emgi), 1, 5,
        2, 0) - 1] = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
      chartInstance->c1_RetransCounter[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("RetransCounter", (int32_T)
        _SFD_INTEGER_CHECK("emgi", c1_emgi), 1, 5, 2, 0) - 1] =
        chartInstance->c1_RetransCounter[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("RetransCounter", (int32_T)
        _SFD_INTEGER_CHECK("emgi", c1_emgi), 1, 5, 2, 0) - 1] - 1.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
      c1_emergency_instance[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "emergency_instance", (int32_T)_SFD_INTEGER_CHECK("emgi", c1_emgi), 1, 5,
        2, 0) - 1] = 0.0;
    }

    c1_c_emgi++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
  for (c1_i22 = 0; c1_i22 < 16; c1_i22++) {
    c1_c_u[c1_i22] = c1_cv0[c1_i22];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 10, 0U, 1U, 0U, 2, 1, 16),
                FALSE);
  c1_d_u = -74.0;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  c1_e_u = c1_emergency_instance[0];
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  c1_f_u = c1_emergency_instance[1];
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  c1_g_u = c1_emergency_instance[2];
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  c1_h_u = c1_emergency_instance[3];
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("python", 2U, 6U, 14, c1_c_y, 14, sf_mex_call_debug(
    "num2str", 1U, 1U, 14, c1_d_y), 14, sf_mex_call_debug("num2str", 1U, 1U, 14,
    c1_e_y), 14, sf_mex_call_debug("num2str", 1U, 1U, 14, c1_f_y), 14,
                    sf_mex_call_debug("num2str", 1U, 1U, 14, c1_g_y), 14,
                    sf_mex_call_debug("num2str", 1U, 1U, 14, c1_h_y),
                    &c1_c_result, &c1_b_status);
  sf_mex_assign(&c1_result, sf_mex_dup(c1_c_result), FALSE);
  _SFD_SYMBOL_SWITCH(2U, 2U);
  sf_mex_assign(&c1_status, sf_mex_dup(c1_b_status), FALSE);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
  sf_mex_printf("%s =\\n", "result");
  sf_mex_call_debug("disp", 0U, 1U, 14, sf_mex_dup(c1_result));
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
  for (c1_i23 = 0; c1_i23 < 60; c1_i23++) {
    c1_b_result[c1_i23] = c1_cv1[c1_i23];
  }

  _SFD_SYMBOL_SWITCH(2U, 5U);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 63);
  for (c1_i24 = 0; c1_i24 < 60; c1_i24++) {
    c1_i_u[c1_i24] = c1_b_result[c1_i24];
  }

  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_i_u, 10, 0U, 1U, 0U, 2, 1, 60),
                FALSE);
  sf_mex_assign(&c1_delay, sf_mex_call_debug("delay_summary", 1U, 1U, 14, c1_i_y),
                FALSE);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 66);
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_call_debug("transpose", 1U, 1U, 14,
    sf_mex_dup(c1_delay)), "transpose", c1_dv6);
  for (c1_i25 = 0; c1_i25 < 8; c1_i25++) {
    c1_ydelay[c1_i25] = c1_dv6[c1_i25];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 68);
  for (c1_i26 = 0; c1_i26 < 5; c1_i26++) {
    chartInstance->c1_last_emergency_instance[c1_i26] = c1_ymea[c1_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 69);
  for (c1_i27 = 0; c1_i27 < 8; c1_i27++) {
    chartInstance->c1_delay1[c1_i27] = c1_ydelay[c1_i27];
  }

  chartInstance->c1_delay1_not_empty = TRUE;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 70);
  chartInstance->c1_i++;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 72);
  for (c1_i28 = 0; c1_i28 < 5; c1_i28++) {
    c1_ymea1[c1_i28] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 73);
  for (c1_i29 = 0; c1_i29 < 5; c1_i29++) {
    c1_ymea1[c1_i29] = c1_ymea[c1_i29];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -73);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c1_result);
  sf_mex_destroy(&c1_status);
  sf_mex_destroy(&c1_delay);
  sf_mex_destroy(&c1_c_result);
  sf_mex_destroy(&c1_b_status);
  for (c1_i30 = 0; c1_i30 < 5; c1_i30++) {
    (*c1_b_ymea1)[c1_i30] = c1_ymea1[c1_i30];
  }

  for (c1_i31 = 0; c1_i31 < 8; c1_i31++) {
    (*c1_b_ydelay)[c1_i31] = c1_ydelay[c1_i31];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_CoupledTanks_WCPS_Event
  (SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i32;
  real_T c1_b_inData[5];
  int32_T c1_i33;
  real_T c1_u[5];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i32 = 0; c1_i32 < 5; c1_i32++) {
    c1_b_inData[c1_i32] = (*(real_T (*)[5])c1_inData)[c1_i32];
  }

  for (c1_i33 = 0; c1_i33 < 5; c1_i33++) {
    c1_u[c1_i33] = c1_b_inData[c1_i33];
  }

  c1_y = NULL;
  if (!chartInstance->c1_RetransCounter_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_b_RetransCounter, const char_T
  *c1_identifier, real_T c1_y[5])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_RetransCounter),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_RetransCounter);
}

static void c1_b_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5])
{
  real_T c1_dv7[5];
  int32_T c1_i34;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_RetransCounter_not_empty = FALSE;
  } else {
    chartInstance->c1_RetransCounter_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv7, 1, 0, 0U, 1, 0U, 2, 1,
                  5);
    for (c1_i34 = 0; c1_i34 < 5; c1_i34++) {
      c1_y[c1_i34] = c1_dv7[c1_i34];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_RetransCounter;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[5];
  int32_T c1_i35;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_b_RetransCounter = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_RetransCounter),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_RetransCounter);
  for (c1_i35 = 0; c1_i35 < 5; c1_i35++) {
    (*(real_T (*)[5])c1_outData)[c1_i35] = c1_y[c1_i35];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i36;
  real_T c1_b_inData[5];
  int32_T c1_i37;
  real_T c1_u[5];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i36 = 0; c1_i36 < 5; c1_i36++) {
    c1_b_inData[c1_i36] = (*(real_T (*)[5])c1_inData)[c1_i36];
  }

  for (c1_i37 = 0; c1_i37 < 5; c1_i37++) {
    c1_u[c1_i37] = c1_b_inData[c1_i37];
  }

  c1_y = NULL;
  if (!chartInstance->c1_last_emergency_instance_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_b_last_emergency_instance, const char_T
  *c1_identifier, real_T c1_y[5])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_last_emergency_instance),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_last_emergency_instance);
}

static void c1_d_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5])
{
  real_T c1_dv8[5];
  int32_T c1_i38;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_last_emergency_instance_not_empty = FALSE;
  } else {
    chartInstance->c1_last_emergency_instance_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv8, 1, 0, 0U, 1, 0U, 2, 1,
                  5);
    for (c1_i38 = 0; c1_i38 < 5; c1_i38++) {
      c1_y[c1_i38] = c1_dv8[c1_i38];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_last_emergency_instance;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[5];
  int32_T c1_i39;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_b_last_emergency_instance = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_last_emergency_instance),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_last_emergency_instance);
  for (c1_i39 = 0; c1_i39 < 5; c1_i39++) {
    (*(real_T (*)[5])c1_outData)[c1_i39] = c1_y[c1_i39];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_i_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_b_i, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_i), &c1_thisId);
  sf_mex_destroy(&c1_b_i);
  return c1_y;
}

static real_T c1_f_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_i_not_empty = FALSE;
  } else {
    chartInstance->c1_i_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d0;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_i;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_b_i = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_i), &c1_thisId);
  sf_mex_destroy(&c1_b_i);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i40;
  real_T c1_b_inData[8];
  int32_T c1_i41;
  real_T c1_u[8];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i40 = 0; c1_i40 < 8; c1_i40++) {
    c1_b_inData[c1_i40] = (*(real_T (*)[8])c1_inData)[c1_i40];
  }

  for (c1_i41 = 0; c1_i41 < 8; c1_i41++) {
    c1_u[c1_i41] = c1_b_inData[c1_i41];
  }

  c1_y = NULL;
  if (!chartInstance->c1_delay1_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 8), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_b_delay1, const char_T *c1_identifier,
  real_T c1_y[8])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_delay1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_delay1);
}

static void c1_h_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8])
{
  real_T c1_dv9[8];
  int32_T c1_i42;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_delay1_not_empty = FALSE;
  } else {
    chartInstance->c1_delay1_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv9, 1, 0, 0U, 1, 0U, 1, 8);
    for (c1_i42 = 0; c1_i42 < 8; c1_i42++) {
      c1_y[c1_i42] = c1_dv9[c1_i42];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_delay1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[8];
  int32_T c1_i43;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_b_delay1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_delay1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_delay1);
  for (c1_i43 = 0; c1_i43 < 8; c1_i43++) {
    (*(real_T (*)[8])c1_outData)[c1_i43] = c1_y[c1_i43];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i44;
  real_T c1_b_inData[8];
  int32_T c1_i45;
  real_T c1_u[8];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i44 = 0; c1_i44 < 8; c1_i44++) {
    c1_b_inData[c1_i44] = (*(real_T (*)[8])c1_inData)[c1_i44];
  }

  for (c1_i45 = 0; c1_i45 < 8; c1_i45++) {
    c1_u[c1_i45] = c1_b_inData[c1_i45];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 8), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_transpose;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[8];
  int32_T c1_i46;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_transpose = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_transpose), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_transpose);
  for (c1_i46 = 0; c1_i46 < 8; c1_i46++) {
    (*(real_T (*)[8])c1_outData)[c1_i46] = c1_y[c1_i46];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i47;
  real_T c1_b_inData[5];
  int32_T c1_i48;
  real_T c1_u[5];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i47 = 0; c1_i47 < 5; c1_i47++) {
    c1_b_inData[c1_i47] = (*(real_T (*)[5])c1_inData)[c1_i47];
  }

  for (c1_i48 = 0; c1_i48 < 5; c1_i48++) {
    c1_u[c1_i48] = c1_b_inData[c1_i48];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_i_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_ymea1, const char_T *c1_identifier, real_T
  c1_y[5])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ymea1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_ymea1);
}

static void c1_j_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5])
{
  real_T c1_dv10[5];
  int32_T c1_i49;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv10, 1, 0, 0U, 1, 0U, 1, 5);
  for (c1_i49 = 0; c1_i49 < 5; c1_i49++) {
    c1_y[c1_i49] = c1_dv10[c1_i49];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_ymea1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[5];
  int32_T c1_i50;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_ymea1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ymea1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_ymea1);
  for (c1_i50 = 0; c1_i50 < 5; c1_i50++) {
    (*(real_T (*)[5])c1_outData)[c1_i50] = c1_y[c1_i50];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_k_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i51;
  char_T c1_b_inData[60];
  int32_T c1_i52;
  char_T c1_u[60];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i51 = 0; c1_i51 < 60; c1_i51++) {
    c1_b_inData[c1_i51] = (*(char_T (*)[60])c1_inData)[c1_i51];
  }

  for (c1_i52 = 0; c1_i52 < 60; c1_i52++) {
    c1_u[c1_i52] = c1_b_inData[c1_i52];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 60), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_l_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[60])
{
  char_T c1_cv2[60];
  int32_T c1_i53;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_cv2, 1, 10, 0U, 1, 0U, 2, 1,
                60);
  for (c1_i53 = 0; c1_i53 < 60; c1_i53++) {
    c1_y[c1_i53] = c1_cv2[c1_i53];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_result;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  char_T c1_y[60];
  int32_T c1_i54;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_result = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_result), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_result);
  for (c1_i54 = 0; c1_i54 < 60; c1_i54++) {
    (*(char_T (*)[60])c1_outData)[c1_i54] = c1_y[c1_i54];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  const mxArray *c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = sf_mex_dup(*(const mxArray **)c1_inData);
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i55;
  real_T c1_b_inData[5];
  int32_T c1_i56;
  real_T c1_u[5];
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i55 = 0; c1_i55 < 5; c1_i55++) {
    c1_b_inData[c1_i55] = (*(real_T (*)[5])c1_inData)[c1_i55];
  }

  for (c1_i56 = 0; c1_i56 < 5; c1_i56++) {
    c1_u[c1_i56] = c1_b_inData[c1_i56];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_m_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5])
{
  real_T c1_dv11[5];
  int32_T c1_i57;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv11, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c1_i57 = 0; c1_i57 < 5; c1_i57++) {
    c1_y[c1_i57] = c1_dv11[c1_i57];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_emergency_instance;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[5];
  int32_T c1_i58;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_emergency_instance = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_emergency_instance),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_emergency_instance);
  for (c1_i58 = 0; c1_i58 < 5; c1_i58++) {
    (*(real_T (*)[5])c1_outData)[c1_i58] = c1_y[c1_i58];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_CoupledTanks_WCPS_Event_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static void c1_n_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_transpose, const char_T *c1_identifier,
  real_T c1_y[8])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_transpose), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_transpose);
}

static void c1_o_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8])
{
  real_T c1_dv12[8];
  int32_T c1_i59;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv12, 1, 0, 0U, 1, 0U, 1, 8);
  for (c1_i59 = 0; c1_i59 < 8; c1_i59++) {
    c1_y[c1_i59] = c1_dv12[c1_i59];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_p_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i60;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i60, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i60;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
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

static uint8_T c1_q_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_CoupledTanks_WCPS_Event, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_CoupledTanks_WCPS_Event), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_CoupledTanks_WCPS_Event);
  return c1_y;
}

static uint8_T c1_r_emlrt_marshallIn(SFc1_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance)
{
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

void sf_c1_CoupledTanks_WCPS_Event_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3198460684U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(876469112U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1378118982U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3004749818U);
}

mxArray *sf_c1_CoupledTanks_WCPS_Event_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("9fIVeUJtvtmEAulaZoTsE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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
      pr[0] = (double)(8);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_CoupledTanks_WCPS_Event_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_CoupledTanks_WCPS_Event(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"ydelay\",},{M[1],M[7],T\"ymea1\",},{M[4],M[0],T\"RetransCounter\",S'l','i','p'{{M1x2[243 257],M[0],}}},{M[4],M[0],T\"delay1\",S'l','i','p'{{M1x2[165 171],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[197 198],M[0],}}},{M[4],M[0],T\"last_emergency_instance\",S'l','i','p'{{M1x2[219 242],M[0],}}},{M[8],M[0],T\"is_active_c1_CoupledTanks_WCPS_Event\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_CoupledTanks_WCPS_Event_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
    chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CoupledTanks_WCPS_EventMachineNumber_,
           1,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_CoupledTanks_WCPS_EventMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CoupledTanks_WCPS_EventMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CoupledTanks_WCPS_EventMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"ymea1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ymea");
          _SFD_SET_DATA_PROPS(2,2,0,1,"ydelay");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,2,0,5,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2568);
        _SFD_CV_INIT_EML_IF(0,1,0,432,445,-1,460);
        _SFD_CV_INIT_EML_IF(0,1,1,461,496,-1,540);
        _SFD_CV_INIT_EML_IF(0,1,2,542,568,-1,603);
        _SFD_CV_INIT_EML_IF(0,1,3,868,1046,-1,1106);
        _SFD_CV_INIT_EML_IF(0,1,4,1158,1185,1283,1333);
        _SFD_CV_INIT_EML_FOR(0,1,0,851,864,1111);
        _SFD_CV_INIT_EML_FOR(0,1,1,1141,1154,1337);

        {
          static int condStart[] = { 873, 911, 946, 984, 1020 };

          static int condEnd[] = { 907, 940, 980, 1013, 1045 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, -2, 4, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,871,1046,5,0,&(condStart[0]),&(condEnd[0]),
                                9,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)
            c1_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        {
          real_T (*c1_ymea1)[5];
          real_T (*c1_ymea)[5];
          real_T (*c1_ydelay)[8];
          c1_ydelay = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_ymea = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
          c1_ymea1 = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_ymea1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_ymea);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_ydelay);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CoupledTanks_WCPS_EventMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "OMfVCHBVtGPut3xDoFTclG";
}

static void sf_opaque_initialize_c1_CoupledTanks_WCPS_Event(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_CoupledTanks_WCPS_Event
    ((SFc1_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
  initialize_c1_CoupledTanks_WCPS_Event
    ((SFc1_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_CoupledTanks_WCPS_Event(void *chartInstanceVar)
{
  enable_c1_CoupledTanks_WCPS_Event((SFc1_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_CoupledTanks_WCPS_Event(void *chartInstanceVar)
{
  disable_c1_CoupledTanks_WCPS_Event((SFc1_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_CoupledTanks_WCPS_Event(void *chartInstanceVar)
{
  sf_c1_CoupledTanks_WCPS_Event((SFc1_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_CoupledTanks_WCPS_Event
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_CoupledTanks_WCPS_Event
    ((SFc1_CoupledTanks_WCPS_EventInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_CoupledTanks_WCPS_Event();/* state var info */
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

extern void sf_internal_set_sim_state_c1_CoupledTanks_WCPS_Event(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_CoupledTanks_WCPS_Event();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_CoupledTanks_WCPS_Event
    ((SFc1_CoupledTanks_WCPS_EventInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_CoupledTanks_WCPS_Event
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_CoupledTanks_WCPS_Event(S);
}

static void sf_opaque_set_sim_state_c1_CoupledTanks_WCPS_Event(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_CoupledTanks_WCPS_Event(S, st);
}

static void sf_opaque_terminate_c1_CoupledTanks_WCPS_Event(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_CoupledTanks_WCPS_EventInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CoupledTanks_WCPS_Event_optimization_info();
    }

    finalize_c1_CoupledTanks_WCPS_Event
      ((SFc1_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_CoupledTanks_WCPS_Event
    ((SFc1_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_CoupledTanks_WCPS_Event(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_CoupledTanks_WCPS_Event
      ((SFc1_CoupledTanks_WCPS_EventInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_CoupledTanks_WCPS_Event(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CoupledTanks_WCPS_Event_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
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
  ssSetChecksum0(S,(4283159823U));
  ssSetChecksum1(S,(1144664848U));
  ssSetChecksum2(S,(1872944576U));
  ssSetChecksum3(S,(578330397U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_CoupledTanks_WCPS_Event(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_CoupledTanks_WCPS_Event(SimStruct *S)
{
  SFc1_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc1_CoupledTanks_WCPS_EventInstanceStruct *)utMalloc(sizeof
    (SFc1_CoupledTanks_WCPS_EventInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_CoupledTanks_WCPS_EventInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_CoupledTanks_WCPS_Event_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_CoupledTanks_WCPS_Event(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_CoupledTanks_WCPS_Event(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_CoupledTanks_WCPS_Event(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_CoupledTanks_WCPS_Event_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
