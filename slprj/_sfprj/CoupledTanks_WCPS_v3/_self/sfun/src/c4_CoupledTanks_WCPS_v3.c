/* Include files */

#include "blascompat32.h"
#include "CoupledTanks_WCPS_v3_sfun.h"
#include "c4_CoupledTanks_WCPS_v3.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CoupledTanks_WCPS_v3_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[11] = { "ymea", "emergency_instance",
  "result", "status", "delay", "ymea1", "nargin", "nargout", "ydelay", "delay1",
  "i" };

/* Function Declarations */
static void initialize_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance);
static void initialize_params_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance);
static void enable_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance);
static void disable_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance);
static void set_sim_state_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance, const mxArray *c4_st);
static void finalize_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance);
static void sf_c4_CoupledTanks_WCPS_v3(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance);
static void initSimStructsc4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_b_i, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_b_delay1, const char_T *c4_identifier,
  real_T c4_y[8]);
static void c4_d_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[8]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_e_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_f_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[5]);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_g_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[5]);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_h_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_delay, const char_T *c4_identifier, real_T
  c4_y[8]);
static void c4_i_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[8]);
static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_j_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_k_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_CoupledTanks_WCPS_v3, const
  char_T *c4_identifier);
static uint8_T c4_l_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_delay1_not_empty = FALSE;
  chartInstance->c4_i_not_empty = FALSE;
  chartInstance->c4_is_active_c4_CoupledTanks_WCPS_v3 = 0U;
}

static void initialize_params_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance)
{
}

static void enable_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[8];
  const mxArray *c4_b_y = NULL;
  int32_T c4_i1;
  real_T c4_b_u[8];
  const mxArray *c4_c_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T (*c4_ydelay)[8];
  c4_ydelay = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(4));
  for (c4_i0 = 0; c4_i0 < 8; c4_i0++) {
    c4_u[c4_i0] = (*c4_ydelay)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 8));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i1 = 0; c4_i1 < 8; c4_i1++) {
    c4_b_u[c4_i1] = chartInstance->c4_delay1[c4_i1];
  }

  c4_c_y = NULL;
  if (!chartInstance->c4_delay1_not_empty) {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 8));
  }

  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_hoistedGlobal = chartInstance->c4_i;
  c4_c_u = c4_hoistedGlobal;
  c4_d_y = NULL;
  if (!chartInstance->c4_i_not_empty) {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_b_hoistedGlobal = chartInstance->c4_is_active_c4_CoupledTanks_WCPS_v3;
  c4_d_u = c4_b_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 3, c4_e_y);
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[8];
  int32_T c4_i2;
  real_T c4_dv1[8];
  int32_T c4_i3;
  real_T (*c4_ydelay)[8];
  c4_ydelay = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                        "ydelay", c4_dv0);
  for (c4_i2 = 0; c4_i2 < 8; c4_i2++) {
    (*c4_ydelay)[c4_i2] = c4_dv0[c4_i2];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
                        "delay1", c4_dv1);
  for (c4_i3 = 0; c4_i3 < 8; c4_i3++) {
    chartInstance->c4_delay1[c4_i3] = c4_dv1[c4_i3];
  }

  chartInstance->c4_i = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "i");
  chartInstance->c4_is_active_c4_CoupledTanks_WCPS_v3 = c4_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
     "is_active_c4_CoupledTanks_WCPS_v3");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_CoupledTanks_WCPS_v3(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance)
{
}

static void sf_c4_CoupledTanks_WCPS_v3(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance)
{
  int32_T c4_i4;
  uint32_T c4_debug_family_var_map[11];
  real_T c4_ymea[5];
  real_T c4_emergency_instance[5];
  const mxArray *c4_result = NULL;
  const mxArray *c4_status = NULL;
  const mxArray *c4_delay = NULL;
  real_T c4_ymea1[5];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  real_T c4_ydelay[8];
  int32_T c4_i5;
  int32_T c4_i6;
  static real_T c4_dv2[8] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c4_i7;
  int32_T c4_i8;
  static char_T c4_cv0[18] = { 't', 'o', 's', 's', 'i', 'm', '-', 'c', 'a', 'l',
    'l', '-', 'p', 's', 's', '.', 'p', 'y' };

  char_T c4_u[18];
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_d_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_e_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_f_u;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_m0 = NULL;
  const mxArray *c4_m1 = NULL;
  const mxArray *c4_b_result = NULL;
  const mxArray *c4_b_status = NULL;
  real_T c4_dv3[8];
  int32_T c4_i9;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  real_T (*c4_b_ydelay)[8];
  c4_b_ydelay = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i4 = 0; c4_i4 < 8; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_ydelay)[c4_i4], 0U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c4_ymea, 0U, c4_e_sf_marshallOut,
    c4_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_emergency_instance, 1U,
    c4_g_sf_marshallOut, c4_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_result, 2U, c4_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_status, 3U, c4_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_delay, 4U, c4_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c4_ymea1, 5U, c4_e_sf_marshallOut,
    c4_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 6U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 7U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_ydelay, 8U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c4_delay1, 9U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c4_i, 10U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  if (CV_EML_IF(0, 0, !chartInstance->c4_i_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
    chartInstance->c4_i = 0.0;
    chartInstance->c4_i_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  for (c4_i5 = 0; c4_i5 < 5; c4_i5++) {
    c4_ymea[c4_i5] = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  for (c4_i6 = 0; c4_i6 < 8; c4_i6++) {
    c4_ydelay[c4_i6] = c4_dv2[c4_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 27);
  for (c4_i7 = 0; c4_i7 < 5; c4_i7++) {
    c4_emergency_instance[c4_i7] = c4_ymea[c4_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
  for (c4_i8 = 0; c4_i8 < 18; c4_i8++) {
    c4_u[c4_i8] = c4_cv0[c4_i8];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 18));
  c4_b_u = -74.0;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  c4_c_u = c4_emergency_instance[0];
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0));
  c4_d_u = c4_emergency_instance[1];
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0));
  c4_e_u = c4_emergency_instance[2];
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0));
  c4_f_u = c4_emergency_instance[3];
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("python", 2U, 6U, 14, c4_y, 14, sf_mex_call_debug("num2str",
    1U, 1U, 14, c4_b_y), 14, sf_mex_call_debug("num2str", 1U, 1U, 14, c4_c_y),
                    14, sf_mex_call_debug("num2str", 1U, 1U, 14, c4_d_y), 14,
                    sf_mex_call_debug("num2str", 1U, 1U, 14, c4_e_y), 14,
                    sf_mex_call_debug("num2str", 1U, 1U, 14, c4_f_y), &c4_m1,
                    &c4_m0);
  sf_mex_assign(&c4_b_result, sf_mex_dup(c4_m1));
  sf_mex_assign(&c4_b_status, sf_mex_dup(c4_m0));
  sf_mex_assign(&c4_result, sf_mex_dup(c4_b_result));
  sf_mex_assign(&c4_status, sf_mex_dup(c4_b_status));
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 42);
  sf_mex_assign(&c4_delay, sf_mex_call_debug("delay_summary", 1U, 1U, 14,
    sf_mex_dup(c4_result)));
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 47);
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_delay), "delay", c4_dv3);
  for (c4_i9 = 0; c4_i9 < 8; c4_i9++) {
    c4_ydelay[c4_i9] = c4_dv3[c4_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 49);
  for (c4_i10 = 0; c4_i10 < 8; c4_i10++) {
    chartInstance->c4_delay1[c4_i10] = c4_ydelay[c4_i10];
  }

  chartInstance->c4_delay1_not_empty = TRUE;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 51);
  chartInstance->c4_i++;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 54);
  for (c4_i11 = 0; c4_i11 < 5; c4_i11++) {
    c4_ymea1[c4_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 55);
  for (c4_i12 = 0; c4_i12 < 5; c4_i12++) {
    c4_ymea1[c4_i12] = c4_ymea[c4_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -55);
  sf_debug_symbol_scope_pop();
  sf_mex_destroy(&c4_result);
  sf_mex_destroy(&c4_status);
  sf_mex_destroy(&c4_delay);
  sf_mex_destroy(&c4_b_result);
  sf_mex_destroy(&c4_b_status);
  sf_mex_destroy(&c4_m0);
  sf_mex_destroy(&c4_m1);
  for (c4_i13 = 0; c4_i13 < 8; c4_i13++) {
    (*c4_b_ydelay)[c4_i13] = c4_ydelay[c4_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  sf_debug_check_for_state_inconsistency(_CoupledTanks_WCPS_v3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_CoupledTanks_WCPS_v3
  (SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_i_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_b_i, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_i), &c4_thisId);
  sf_mex_destroy(&c4_b_i);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_i_not_empty = FALSE;
  } else {
    chartInstance->c4_i_not_empty = TRUE;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d0;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_i;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_b_i = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_i), &c4_thisId);
  sf_mex_destroy(&c4_b_i);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i14;
  real_T c4_b_inData[8];
  int32_T c4_i15;
  real_T c4_u[8];
  const mxArray *c4_y = NULL;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i14 = 0; c4_i14 < 8; c4_i14++) {
    c4_b_inData[c4_i14] = (*(real_T (*)[8])c4_inData)[c4_i14];
  }

  for (c4_i15 = 0; c4_i15 < 8; c4_i15++) {
    c4_u[c4_i15] = c4_b_inData[c4_i15];
  }

  c4_y = NULL;
  if (!chartInstance->c4_delay1_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 8));
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_b_delay1, const char_T *c4_identifier,
  real_T c4_y[8])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_delay1), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_delay1);
}

static void c4_d_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[8])
{
  real_T c4_dv4[8];
  int32_T c4_i16;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_delay1_not_empty = FALSE;
  } else {
    chartInstance->c4_delay1_not_empty = TRUE;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv4, 1, 0, 0U, 1, 0U, 1, 8);
    for (c4_i16 = 0; c4_i16 < 8; c4_i16++) {
      c4_y[c4_i16] = c4_dv4[c4_i16];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_delay1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[8];
  int32_T c4_i17;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_b_delay1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_delay1), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_delay1);
  for (c4_i17 = 0; c4_i17 < 8; c4_i17++) {
    (*(real_T (*)[8])c4_outData)[c4_i17] = c4_y[c4_i17];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i18;
  real_T c4_b_inData[8];
  int32_T c4_i19;
  real_T c4_u[8];
  const mxArray *c4_y = NULL;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i18 = 0; c4_i18 < 8; c4_i18++) {
    c4_b_inData[c4_i18] = (*(real_T (*)[8])c4_inData)[c4_i18];
  }

  for (c4_i19 = 0; c4_i19 < 8; c4_i19++) {
    c4_u[c4_i19] = c4_b_inData[c4_i19];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 8));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_delay;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[8];
  int32_T c4_i20;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_delay = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_delay), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_delay);
  for (c4_i20 = 0; c4_i20 < 8; c4_i20++) {
    (*(real_T (*)[8])c4_outData)[c4_i20] = c4_y[c4_i20];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static real_T c4_e_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i21;
  real_T c4_b_inData[5];
  int32_T c4_i22;
  real_T c4_u[5];
  const mxArray *c4_y = NULL;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i21 = 0; c4_i21 < 5; c4_i21++) {
    c4_b_inData[c4_i21] = (*(real_T (*)[5])c4_inData)[c4_i21];
  }

  for (c4_i22 = 0; c4_i22 < 5; c4_i22++) {
    c4_u[c4_i22] = c4_b_inData[c4_i22];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 5));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static void c4_f_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[5])
{
  real_T c4_dv5[5];
  int32_T c4_i23;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv5, 1, 0, 0U, 1, 0U, 1, 5);
  for (c4_i23 = 0; c4_i23 < 5; c4_i23++) {
    c4_y[c4_i23] = c4_dv5[c4_i23];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_ymea1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[5];
  int32_T c4_i24;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_ymea1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ymea1), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_ymea1);
  for (c4_i24 = 0; c4_i24 < 5; c4_i24++) {
    (*(real_T (*)[5])c4_outData)[c4_i24] = c4_y[c4_i24];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  const mxArray *c4_u;
  const mxArray *c4_y = NULL;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = sf_mex_dup(*(const mxArray **)c4_inData);
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u));
  sf_mex_destroy(&c4_u);
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i25;
  real_T c4_b_inData[5];
  int32_T c4_i26;
  real_T c4_u[5];
  const mxArray *c4_y = NULL;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i25 = 0; c4_i25 < 5; c4_i25++) {
    c4_b_inData[c4_i25] = (*(real_T (*)[5])c4_inData)[c4_i25];
  }

  for (c4_i26 = 0; c4_i26 < 5; c4_i26++) {
    c4_u[c4_i26] = c4_b_inData[c4_i26];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 5));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static void c4_g_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[5])
{
  real_T c4_dv6[5];
  int32_T c4_i27;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv6, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c4_i27 = 0; c4_i27 < 5; c4_i27++) {
    c4_y[c4_i27] = c4_dv6[c4_i27];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_emergency_instance;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[5];
  int32_T c4_i28;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_emergency_instance = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_emergency_instance),
                        &c4_thisId, c4_y);
  sf_mex_destroy(&c4_emergency_instance);
  for (c4_i28 = 0; c4_i28 < 5; c4_i28++) {
    (*(real_T (*)[5])c4_outData)[c4_i28] = c4_y[c4_i28];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_CoupledTanks_WCPS_v3_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c4_nameCaptureInfo;
}

static void c4_h_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_delay, const char_T *c4_identifier, real_T
  c4_y[8])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_delay), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_delay);
}

static void c4_i_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[8])
{
  real_T c4_dv7[8];
  int32_T c4_i29;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv7, 1, 0, 0U, 1, 0U, 1, 8);
  for (c4_i29 = 0; c4_i29 < 8; c4_i29++) {
    c4_y[c4_i29] = c4_dv7[c4_i29];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static int32_T c4_j_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i30;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i30, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i30;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_k_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_CoupledTanks_WCPS_v3, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_CoupledTanks_WCPS_v3), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_CoupledTanks_WCPS_v3);
  return c4_y;
}

static uint8_T c4_l_emlrt_marshallIn(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_CoupledTanks_WCPS_v3InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_CoupledTanks_WCPS_v3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(805888311U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4107723496U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1235147998U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2976675697U);
}

mxArray *sf_c4_CoupledTanks_WCPS_v3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(119264210U);
    pr[1] = (double)(1323923997U);
    pr[2] = (double)(2064236215U);
    pr[3] = (double)(202724014U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
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
      pr[0] = (double)(8);
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

static const mxArray *sf_get_sim_state_info_c4_CoupledTanks_WCPS_v3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"ydelay\",},{M[4],M[0],T\"delay1\",S'l','i','p'{{M1x2[151 157],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[183 184],M[0],}}},{M[8],M[0],T\"is_active_c4_CoupledTanks_WCPS_v3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_CoupledTanks_WCPS_v3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
    chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CoupledTanks_WCPS_v3MachineNumber_,
           4,
           1,
           1,
           1,
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
          init_script_number_translation(_CoupledTanks_WCPS_v3MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_CoupledTanks_WCPS_v3MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_CoupledTanks_WCPS_v3MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"ydelay");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1460);
        _SFD_CV_INIT_EML_IF(0,0,418,431,-1,446);
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
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)
            c4_c_sf_marshallIn);
        }

        {
          real_T (*c4_ydelay)[8];
          c4_ydelay = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_ydelay);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_CoupledTanks_WCPS_v3MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_CoupledTanks_WCPS_v3(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_CoupledTanks_WCPS_v3
    ((SFc4_CoupledTanks_WCPS_v3InstanceStruct*) chartInstanceVar);
  initialize_c4_CoupledTanks_WCPS_v3((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_CoupledTanks_WCPS_v3(void *chartInstanceVar)
{
  enable_c4_CoupledTanks_WCPS_v3((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_CoupledTanks_WCPS_v3(void *chartInstanceVar)
{
  disable_c4_CoupledTanks_WCPS_v3((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_CoupledTanks_WCPS_v3(void *chartInstanceVar)
{
  sf_c4_CoupledTanks_WCPS_v3((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_CoupledTanks_WCPS_v3
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_CoupledTanks_WCPS_v3
    ((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_CoupledTanks_WCPS_v3();/* state var info */
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

extern void sf_internal_set_sim_state_c4_CoupledTanks_WCPS_v3(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_CoupledTanks_WCPS_v3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_CoupledTanks_WCPS_v3((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_CoupledTanks_WCPS_v3(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c4_CoupledTanks_WCPS_v3(S);
}

static void sf_opaque_set_sim_state_c4_CoupledTanks_WCPS_v3(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_CoupledTanks_WCPS_v3(S, st);
}

static void sf_opaque_terminate_c4_CoupledTanks_WCPS_v3(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_CoupledTanks_WCPS_v3InstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_CoupledTanks_WCPS_v3((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_CoupledTanks_WCPS_v3((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_CoupledTanks_WCPS_v3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_CoupledTanks_WCPS_v3
      ((SFc4_CoupledTanks_WCPS_v3InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_CoupledTanks_WCPS_v3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"CoupledTanks_WCPS_v3",
      "CoupledTanks_WCPS_v3",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"CoupledTanks_WCPS_v3",
                "CoupledTanks_WCPS_v3",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"CoupledTanks_WCPS_v3",
      "CoupledTanks_WCPS_v3",4,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,"CoupledTanks_WCPS_v3",
        "CoupledTanks_WCPS_v3",4,1);
    }

    sf_set_rtw_dwork_info(S,"CoupledTanks_WCPS_v3","CoupledTanks_WCPS_v3",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2058765008U));
  ssSetChecksum1(S,(2547932398U));
  ssSetChecksum2(S,(1179123199U));
  ssSetChecksum3(S,(2305565521U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_CoupledTanks_WCPS_v3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "CoupledTanks_WCPS_v3", "CoupledTanks_WCPS_v3",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_CoupledTanks_WCPS_v3(SimStruct *S)
{
  SFc4_CoupledTanks_WCPS_v3InstanceStruct *chartInstance;
  chartInstance = (SFc4_CoupledTanks_WCPS_v3InstanceStruct *)malloc(sizeof
    (SFc4_CoupledTanks_WCPS_v3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_CoupledTanks_WCPS_v3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_CoupledTanks_WCPS_v3;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_CoupledTanks_WCPS_v3;
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

void c4_CoupledTanks_WCPS_v3_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_CoupledTanks_WCPS_v3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_CoupledTanks_WCPS_v3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_CoupledTanks_WCPS_v3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_CoupledTanks_WCPS_v3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
