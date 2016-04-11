/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CoupledTanks_WCPS_Event_sfun.h"
#include "c3_CoupledTanks_WCPS_Event.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CoupledTanks_WCPS_Event_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[14] = { "actnum", "step_count", "kk",
  "j", "nargin", "nargout", "uout", "udelay", "uout_delay", "uin_d", "uin",
  "delay", "uin_all", "numAct" };

/* Function Declarations */
static void initialize_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void initialize_params_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void enable_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void disable_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void set_sim_state_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void finalize_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void sf_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void initSimStructsc3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void registerMessagesc3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_numAct, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_uin_all, const char_T *c3_identifier,
  real_T c3_y[20002]);
static void c3_d_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[20002]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_delay, const char_T *c3_identifier, real_T
  c3_y[8]);
static void c3_f_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[8]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_uin, const char_T *c3_identifier, real_T
  c3_y[2]);
static void c3_h_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_i_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_uin_d, const char_T *c3_identifier, real_T
  c3_y[2]);
static void c3_j_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_k_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_uout_delay, const char_T *c3_identifier,
  real_T c3_y[2]);
static void c3_l_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2]);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_m_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_n_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_o_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c3_b_is_active_c3_CoupledTanks_WCPS_Event, const
  char_T *c3_identifier);
static uint8_T c3_p_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_i_not_empty = FALSE;
  chartInstance->c3_uin_d_not_empty = FALSE;
  chartInstance->c3_uin_not_empty = FALSE;
  chartInstance->c3_delay_not_empty = FALSE;
  chartInstance->c3_uin_all_not_empty = FALSE;
  chartInstance->c3_numAct_not_empty = FALSE;
  chartInstance->c3_is_active_c3_CoupledTanks_WCPS_Event = 0U;
}

static void initialize_params_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void enable_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[2];
  const mxArray *c3_b_y = NULL;
  int32_T c3_i1;
  real_T c3_b_u[8];
  const mxArray *c3_c_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  int32_T c3_i2;
  real_T c3_d_u[2];
  const mxArray *c3_e_y = NULL;
  int32_T c3_i3;
  real_T c3_e_u[20002];
  const mxArray *c3_f_y = NULL;
  int32_T c3_i4;
  real_T c3_f_u[2];
  const mxArray *c3_g_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  real_T (*c3_uout_delay)[2];
  c3_uout_delay = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(7), FALSE);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    c3_u[c3_i0] = (*c3_uout_delay)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i1 = 0; c3_i1 < 8; c3_i1++) {
    c3_b_u[c3_i1] = chartInstance->c3_delay[c3_i1];
  }

  c3_c_y = NULL;
  if (!chartInstance->c3_delay_not_empty) {
    sf_mex_assign(&c3_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 2, 1, 8),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_hoistedGlobal = chartInstance->c3_numAct;
  c3_c_u = c3_hoistedGlobal;
  c3_d_y = NULL;
  if (!chartInstance->c3_numAct_not_empty) {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 2, c3_d_y);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    c3_d_u[c3_i2] = chartInstance->c3_uin[c3_i2];
  }

  c3_e_y = NULL;
  if (!chartInstance->c3_uin_not_empty) {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_d_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 3, c3_e_y);
  for (c3_i3 = 0; c3_i3 < 20002; c3_i3++) {
    c3_e_u[c3_i3] = chartInstance->c3_uin_all[c3_i3];
  }

  c3_f_y = NULL;
  if (!chartInstance->c3_uin_all_not_empty) {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_e_u, 0, 0U, 1U, 0U, 2, 10001, 2),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 4, c3_f_y);
  for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
    c3_f_u[c3_i4] = chartInstance->c3_uin_d[c3_i4];
  }

  c3_g_y = NULL;
  if (!chartInstance->c3_uin_d_not_empty) {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_CoupledTanks_WCPS_Event;
  c3_g_u = c3_b_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[2];
  int32_T c3_i5;
  real_T c3_dv1[8];
  int32_T c3_i6;
  real_T c3_dv2[2];
  int32_T c3_i7;
  static real_T c3_dv3[20002];
  int32_T c3_i8;
  real_T c3_dv4[2];
  int32_T c3_i9;
  real_T (*c3_uout_delay)[2];
  c3_uout_delay = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                        "uout_delay", c3_dv0);
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    (*c3_uout_delay)[c3_i5] = c3_dv0[c3_i5];
  }

  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                        "delay", c3_dv1);
  for (c3_i6 = 0; c3_i6 < 8; c3_i6++) {
    chartInstance->c3_delay[c3_i6] = c3_dv1[c3_i6];
  }

  chartInstance->c3_numAct = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "numAct");
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
                        "uin", c3_dv2);
  for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
    chartInstance->c3_uin[c3_i7] = c3_dv2[c3_i7];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
                        "uin_all", c3_dv3);
  for (c3_i8 = 0; c3_i8 < 20002; c3_i8++) {
    chartInstance->c3_uin_all[c3_i8] = c3_dv3[c3_i8];
  }

  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
                        "uin_d", c3_dv4);
  for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
    chartInstance->c3_uin_d[c3_i9] = c3_dv4[c3_i9];
  }

  chartInstance->c3_is_active_c3_CoupledTanks_WCPS_Event = c3_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
     "is_active_c3_CoupledTanks_WCPS_Event");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_CoupledTanks_WCPS_Event(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void sf_c3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  real_T c3_uout[2];
  int32_T c3_i14;
  real_T c3_udelay[8];
  uint32_T c3_debug_family_var_map[14];
  real_T c3_actnum;
  real_T c3_step_count;
  real_T c3_kk;
  real_T c3_j;
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  real_T c3_uout_delay[2];
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_b_kk;
  int32_T c3_b_j;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  real_T (*c3_b_uout_delay)[2];
  real_T (*c3_b_udelay)[8];
  real_T (*c3_b_uout)[2];
  c3_b_udelay = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_uout_delay = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_uout = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i10 = 0; c3_i10 < 2; c3_i10++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_uout)[c3_i10], 0U);
  }

  for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_uout_delay)[c3_i11], 1U);
  }

  for (c3_i12 = 0; c3_i12 < 8; c3_i12++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_udelay)[c3_i12], 2U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
    c3_uout[c3_i13] = (*c3_b_uout)[c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 8; c3_i14++) {
    c3_udelay[c3_i14] = (*c3_b_udelay)[c3_i14];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_actnum, 0U, c3_h_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_step_count, 1U, c3_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_kk, 2U, c3_h_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j, 3U, c3_h_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 4U, c3_h_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 5U, c3_h_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_uout, 6U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_udelay, 7U, c3_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_uout_delay, 8U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c3_uin_d, 9U,
    c3_e_sf_marshallOut, c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c3_uin, 10U,
    c3_d_sf_marshallOut, c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c3_delay, 11U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c3_uin_all, 12U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_numAct, 13U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_actnum = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  c3_step_count = 10000.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c3_uin_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
    for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
      chartInstance->c3_uin[c3_i15] = 0.0;
    }

    chartInstance->c3_uin_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
    for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
      chartInstance->c3_uin_d[c3_i16] = 0.0;
    }

    chartInstance->c3_uin_d_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
    for (c3_i17 = 0; c3_i17 < 20002; c3_i17++) {
      chartInstance->c3_uin_all[c3_i17] = 0.0;
    }

    chartInstance->c3_uin_all_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
    for (c3_i18 = 0; c3_i18 < 8; c3_i18++) {
      chartInstance->c3_delay[c3_i18] = 0.0;
    }

    chartInstance->c3_delay_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
    for (c3_i19 = 0; c3_i19 < 8; c3_i19++) {
      chartInstance->c3_delay[c3_i19] = c3_udelay[c3_i19];
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
    chartInstance->c3_numAct = 0.0;
    chartInstance->c3_numAct_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  chartInstance->c3_numAct++;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
  for (c3_i20 = 0; c3_i20 < 8; c3_i20++) {
    chartInstance->c3_delay[c3_i20] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
  for (c3_i21 = 0; c3_i21 < 8; c3_i21++) {
    chartInstance->c3_delay[c3_i21] = c3_udelay[c3_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
  c3_kk = 1.0;
  c3_b_kk = 0;
  while (c3_b_kk < 2) {
    c3_kk = 1.0 + (real_T)c3_b_kk;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 45);
    chartInstance->c3_uin_all[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "uin_all", (int32_T)_SFD_INTEGER_CHECK("numAct", chartInstance->c3_numAct),
      1, 10001, 1, 0) + 10001 * ((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "uin_all", (int32_T)_SFD_INTEGER_CHECK("kk", c3_kk), 1, 2, 2, 0) - 1)) - 1]
      = c3_uout[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("uout", (int32_T)
      _SFD_INTEGER_CHECK("kk", c3_kk), 1, 2, 1, 0) - 1];
    c3_b_kk++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 49);
  c3_j = 1.0;
  c3_b_j = 0;
  while (c3_b_j < 2) {
    c3_j = 1.0 + (real_T)c3_b_j;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
    if (CV_EML_IF(0, 1, 1, chartInstance->c3_delay[(int32_T)(real_T)
                  _SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
          _SFD_INTEGER_CHECK("j+6", c3_j + 6.0), 1, 8, 2, 0) - 1] != 88.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
      chartInstance->c3_uin[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("uin",
        (int32_T)_SFD_INTEGER_CHECK("j", c3_j), 1, 2, 1, 0) - 1] =
        chartInstance->c3_uin_all[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "uin_all", (int32_T)_SFD_INTEGER_CHECK("numAct",
        chartInstance->c3_numAct), 1, 10001, 1, 0) + 10001 * ((int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("uin_all", (int32_T)_SFD_INTEGER_CHECK("j",
        c3_j), 1, 2, 2, 0) - 1)) - 1];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
      if (CV_EML_IF(0, 1, 2, chartInstance->c3_numAct > 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
        chartInstance->c3_uin[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("uin",
          (int32_T)_SFD_INTEGER_CHECK("j", c3_j), 1, 2, 1, 0) - 1] =
          chartInstance->c3_uin_all[((int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("uin_all", (int32_T)_SFD_INTEGER_CHECK(
          "numAct-1", chartInstance->c3_numAct - 1.0), 1, 10001, 1, 0) + 10001 *
                                     ((int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("uin_all", (int32_T)_SFD_INTEGER_CHECK("j",
          c3_j), 1, 2, 2, 0) - 1)) - 1];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 56);
        chartInstance->c3_uin_all[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "uin_all", (int32_T)_SFD_INTEGER_CHECK("numAct",
          chartInstance->c3_numAct), 1, 10001, 1, 0) + 10001 * ((int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("uin_all", (int32_T)_SFD_INTEGER_CHECK("j",
          c3_j), 1, 2, 2, 0) - 1)) - 1] = chartInstance->c3_uin_all[((int32_T)
          (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("uin_all", (int32_T)
          _SFD_INTEGER_CHECK("numAct-1", chartInstance->c3_numAct - 1.0), 1,
          10001, 1, 0) + 10001 * ((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "uin_all", (int32_T)_SFD_INTEGER_CHECK("j", c3_j), 1, 2, 2, 0) - 1)) -
          1];
      }
    }

    c3_b_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 62);
  for (c3_i22 = 0; c3_i22 < 2; c3_i22++) {
    chartInstance->c3_uin_d[c3_i22] = chartInstance->c3_uin[c3_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 64);
  for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
    c3_uout_delay[c3_i23] = chartInstance->c3_uin_d[c3_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -64);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i24 = 0; c3_i24 < 2; c3_i24++) {
    (*c3_b_uout_delay)[c3_i24] = c3_uout_delay[c3_i24];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CoupledTanks_WCPS_EventMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void registerMessagesc3_CoupledTanks_WCPS_Event
  (SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_numAct_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_numAct, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_numAct),
    &c3_thisId);
  sf_mex_destroy(&c3_b_numAct);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_numAct_not_empty = FALSE;
  } else {
    chartInstance->c3_numAct_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d0;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_numAct;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_b_numAct = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_numAct),
    &c3_thisId);
  sf_mex_destroy(&c3_b_numAct);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  static real_T c3_b_inData[20002];
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  real_T c3_u[20002];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i25 = 0;
  for (c3_i26 = 0; c3_i26 < 2; c3_i26++) {
    for (c3_i27 = 0; c3_i27 < 10001; c3_i27++) {
      c3_b_inData[c3_i27 + c3_i25] = (*(real_T (*)[20002])c3_inData)[c3_i27 +
        c3_i25];
    }

    c3_i25 += 10001;
  }

  c3_i28 = 0;
  for (c3_i29 = 0; c3_i29 < 2; c3_i29++) {
    for (c3_i30 = 0; c3_i30 < 10001; c3_i30++) {
      c3_u[c3_i30 + c3_i28] = c3_b_inData[c3_i30 + c3_i28];
    }

    c3_i28 += 10001;
  }

  c3_y = NULL;
  if (!chartInstance->c3_uin_all_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 10001, 2),
                  FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_uin_all, const char_T *c3_identifier,
  real_T c3_y[20002])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_uin_all), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_uin_all);
}

static void c3_d_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[20002])
{
  real_T c3_dv5[20002];
  int32_T c3_i31;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_uin_all_not_empty = FALSE;
  } else {
    chartInstance->c3_uin_all_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv5, 1, 0, 0U, 1, 0U, 2,
                  10001, 2);
    for (c3_i31 = 0; c3_i31 < 20002; c3_i31++) {
      c3_y[c3_i31] = c3_dv5[c3_i31];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_uin_all;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  static real_T c3_y[20002];
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_b_uin_all = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_uin_all), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_uin_all);
  c3_i32 = 0;
  for (c3_i33 = 0; c3_i33 < 2; c3_i33++) {
    for (c3_i34 = 0; c3_i34 < 10001; c3_i34++) {
      (*(real_T (*)[20002])c3_outData)[c3_i34 + c3_i32] = c3_y[c3_i34 + c3_i32];
    }

    c3_i32 += 10001;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i35;
  real_T c3_b_inData[8];
  int32_T c3_i36;
  real_T c3_u[8];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i35 = 0; c3_i35 < 8; c3_i35++) {
    c3_b_inData[c3_i35] = (*(real_T (*)[8])c3_inData)[c3_i35];
  }

  for (c3_i36 = 0; c3_i36 < 8; c3_i36++) {
    c3_u[c3_i36] = c3_b_inData[c3_i36];
  }

  c3_y = NULL;
  if (!chartInstance->c3_delay_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 8), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_delay, const char_T *c3_identifier, real_T
  c3_y[8])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_delay), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_delay);
}

static void c3_f_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[8])
{
  real_T c3_dv6[8];
  int32_T c3_i37;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_delay_not_empty = FALSE;
  } else {
    chartInstance->c3_delay_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv6, 1, 0, 0U, 1, 0U, 2, 1,
                  8);
    for (c3_i37 = 0; c3_i37 < 8; c3_i37++) {
      c3_y[c3_i37] = c3_dv6[c3_i37];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_delay;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[8];
  int32_T c3_i38;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_b_delay = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_delay), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_delay);
  for (c3_i38 = 0; c3_i38 < 8; c3_i38++) {
    (*(real_T (*)[8])c3_outData)[c3_i38] = c3_y[c3_i38];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i39;
  real_T c3_b_inData[2];
  int32_T c3_i40;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i39 = 0; c3_i39 < 2; c3_i39++) {
    c3_b_inData[c3_i39] = (*(real_T (*)[2])c3_inData)[c3_i39];
  }

  for (c3_i40 = 0; c3_i40 < 2; c3_i40++) {
    c3_u[c3_i40] = c3_b_inData[c3_i40];
  }

  c3_y = NULL;
  if (!chartInstance->c3_uin_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_uin, const char_T *c3_identifier, real_T
  c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_uin), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_uin);
}

static void c3_h_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2])
{
  real_T c3_dv7[2];
  int32_T c3_i41;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_uin_not_empty = FALSE;
  } else {
    chartInstance->c3_uin_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv7, 1, 0, 0U, 1, 0U, 2, 1,
                  2);
    for (c3_i41 = 0; c3_i41 < 2; c3_i41++) {
      c3_y[c3_i41] = c3_dv7[c3_i41];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_uin;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i42;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_b_uin = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_uin), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_uin);
  for (c3_i42 = 0; c3_i42 < 2; c3_i42++) {
    (*(real_T (*)[2])c3_outData)[c3_i42] = c3_y[c3_i42];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i43;
  real_T c3_b_inData[2];
  int32_T c3_i44;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i43 = 0; c3_i43 < 2; c3_i43++) {
    c3_b_inData[c3_i43] = (*(real_T (*)[2])c3_inData)[c3_i43];
  }

  for (c3_i44 = 0; c3_i44 < 2; c3_i44++) {
    c3_u[c3_i44] = c3_b_inData[c3_i44];
  }

  c3_y = NULL;
  if (!chartInstance->c3_uin_d_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_i_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_b_uin_d, const char_T *c3_identifier, real_T
  c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_uin_d), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_uin_d);
}

static void c3_j_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2])
{
  real_T c3_dv8[2];
  int32_T c3_i45;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_uin_d_not_empty = FALSE;
  } else {
    chartInstance->c3_uin_d_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv8, 1, 0, 0U, 1, 0U, 1, 2);
    for (c3_i45 = 0; c3_i45 < 2; c3_i45++) {
      c3_y[c3_i45] = c3_dv8[c3_i45];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_uin_d;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i46;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_b_uin_d = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_uin_d), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_uin_d);
  for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
    (*(real_T (*)[2])c3_outData)[c3_i46] = c3_y[c3_i46];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i47;
  real_T c3_b_inData[2];
  int32_T c3_i48;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i47 = 0; c3_i47 < 2; c3_i47++) {
    c3_b_inData[c3_i47] = (*(real_T (*)[2])c3_inData)[c3_i47];
  }

  for (c3_i48 = 0; c3_i48 < 2; c3_i48++) {
    c3_u[c3_i48] = c3_b_inData[c3_i48];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_k_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_uout_delay, const char_T *c3_identifier,
  real_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_uout_delay), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_uout_delay);
}

static void c3_l_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2])
{
  real_T c3_dv9[2];
  int32_T c3_i49;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv9, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i49 = 0; c3_i49 < 2; c3_i49++) {
    c3_y[c3_i49] = c3_dv9[c3_i49];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_uout_delay;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i50;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_uout_delay = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_uout_delay), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_uout_delay);
  for (c3_i50 = 0; c3_i50 < 2; c3_i50++) {
    (*(real_T (*)[2])c3_outData)[c3_i50] = c3_y[c3_i50];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i51;
  real_T c3_b_inData[8];
  int32_T c3_i52;
  real_T c3_u[8];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i51 = 0; c3_i51 < 8; c3_i51++) {
    c3_b_inData[c3_i51] = (*(real_T (*)[8])c3_inData)[c3_i51];
  }

  for (c3_i52 = 0; c3_i52 < 8; c3_i52++) {
    c3_u[c3_i52] = c3_b_inData[c3_i52];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 8), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_m_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d1;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d1, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_CoupledTanks_WCPS_Event_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_n_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i53;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i53, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i53;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_o_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c3_b_is_active_c3_CoupledTanks_WCPS_Event, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_CoupledTanks_WCPS_Event), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_CoupledTanks_WCPS_Event);
  return c3_y;
}

static uint8_T c3_p_emlrt_marshallIn(SFc3_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_CoupledTanks_WCPS_EventInstanceStruct
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

void sf_c3_CoupledTanks_WCPS_Event_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4052085587U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1113136213U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3621731431U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(224496171U);
}

mxArray *sf_c3_CoupledTanks_WCPS_Event_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5VZ8l6YHTFJYeBFiCosK3F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_CoupledTanks_WCPS_Event_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_CoupledTanks_WCPS_Event(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"uout_delay\",},{M[4],M[0],T\"delay\",S'l','i','p'{{M1x2[323 328],M[0],}}},{M[4],M[0],T\"numAct\",S'l','i','p'{{M1x2[337 343],M[0],}}},{M[4],M[0],T\"uin\",S'l','i','p'{{M1x2[319 322],M[0],}}},{M[4],M[0],T\"uin_all\",S'l','i','p'{{M1x2[329 336],M[0],}}},{M[4],M[0],T\"uin_d\",S'l','i','p'{{M1x2[301 306],M[0],}}},{M[8],M[0],T\"is_active_c3_CoupledTanks_WCPS_Event\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_CoupledTanks_WCPS_Event_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
    chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CoupledTanks_WCPS_EventMachineNumber_,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"uout");
          _SFD_SET_DATA_PROPS(1,2,0,1,"uout_delay");
          _SFD_SET_DATA_PROPS(2,1,1,0,"udelay");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1435);
        _SFD_CV_INIT_EML_IF(0,1,0,459,474,-1,694);
        _SFD_CV_INIT_EML_IF(0,1,1,953,972,1030,1261);
        _SFD_CV_INIT_EML_IF(0,1,2,1043,1054,-1,1245);
        _SFD_CV_INIT_EML_FOR(0,1,0,832,845,883);
        _SFD_CV_INIT_EML_FOR(0,1,1,939,949,1265);
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
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c3_uout)[2];
          real_T (*c3_uout_delay)[2];
          real_T (*c3_udelay)[8];
          c3_udelay = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
          c3_uout_delay = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S,
            1);
          c3_uout = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_uout);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_uout_delay);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_udelay);
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
  return "U1RJdmY8zf7B72D6nxa2kH";
}

static void sf_opaque_initialize_c3_CoupledTanks_WCPS_Event(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_CoupledTanks_WCPS_Event
    ((SFc3_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
  initialize_c3_CoupledTanks_WCPS_Event
    ((SFc3_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_CoupledTanks_WCPS_Event(void *chartInstanceVar)
{
  enable_c3_CoupledTanks_WCPS_Event((SFc3_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_CoupledTanks_WCPS_Event(void *chartInstanceVar)
{
  disable_c3_CoupledTanks_WCPS_Event((SFc3_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_CoupledTanks_WCPS_Event(void *chartInstanceVar)
{
  sf_c3_CoupledTanks_WCPS_Event((SFc3_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_CoupledTanks_WCPS_Event
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_CoupledTanks_WCPS_Event
    ((SFc3_CoupledTanks_WCPS_EventInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_CoupledTanks_WCPS_Event();/* state var info */
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

extern void sf_internal_set_sim_state_c3_CoupledTanks_WCPS_Event(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_CoupledTanks_WCPS_Event();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_CoupledTanks_WCPS_Event
    ((SFc3_CoupledTanks_WCPS_EventInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_CoupledTanks_WCPS_Event
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c3_CoupledTanks_WCPS_Event(S);
}

static void sf_opaque_set_sim_state_c3_CoupledTanks_WCPS_Event(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c3_CoupledTanks_WCPS_Event(S, st);
}

static void sf_opaque_terminate_c3_CoupledTanks_WCPS_Event(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_CoupledTanks_WCPS_EventInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CoupledTanks_WCPS_Event_optimization_info();
    }

    finalize_c3_CoupledTanks_WCPS_Event
      ((SFc3_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_CoupledTanks_WCPS_Event
    ((SFc3_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_CoupledTanks_WCPS_Event(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_CoupledTanks_WCPS_Event
      ((SFc3_CoupledTanks_WCPS_EventInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_CoupledTanks_WCPS_Event(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CoupledTanks_WCPS_Event_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(657870974U));
  ssSetChecksum1(S,(2866977695U));
  ssSetChecksum2(S,(924426323U));
  ssSetChecksum3(S,(2703920991U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_CoupledTanks_WCPS_Event(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_CoupledTanks_WCPS_Event(SimStruct *S)
{
  SFc3_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanks_WCPS_EventInstanceStruct *)utMalloc(sizeof
    (SFc3_CoupledTanks_WCPS_EventInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_CoupledTanks_WCPS_EventInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_CoupledTanks_WCPS_Event;
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

void c3_CoupledTanks_WCPS_Event_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_CoupledTanks_WCPS_Event(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_CoupledTanks_WCPS_Event(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_CoupledTanks_WCPS_Event(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_CoupledTanks_WCPS_Event_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
