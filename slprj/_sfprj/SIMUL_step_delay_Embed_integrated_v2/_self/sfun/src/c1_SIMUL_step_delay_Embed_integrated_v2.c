/* Include files */

#include "blascompat32.h"
#include "SIMUL_step_delay_Embed_integrated_v2_sfun.h"
#include "c1_SIMUL_step_delay_Embed_integrated_v2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMUL_step_delay_Embed_integrated_v2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[10] = { "result", "status", "delay",
  "nargin", "nargout", "ymea", "ymea1", "ydelay", "i", "delay1" };

/* Function Declarations */
static void initialize_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void initialize_params_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void enable_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void disable_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_SIMUL_step_delay_Embed_integrated_v
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void set_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_st);
static void finalize_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void sf_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_delay, const char_T *c1_name, real_T c1_y[5]);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[19]);
static const mxArray *c1_g_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_b_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_ydelay, const char_T *c1_name, real_T c1_y[5]);
static void c1_c_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_ymea1, const char_T *c1_name, real_T c1_y[4]);
static void c1_d_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_b_delay1, const char_T *c1_name, real_T c1_y[5]);
static real_T c1_e_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_b_i, const char_T *c1_name);
static uint8_T c1_f_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_SIMUL_step_delay_Embed_integrated_v2, const char_T
   *c1_name);
static void init_dsm_address_info
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *
   chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_i_not_empty = FALSE;
  chartInstance->c1_delay1_not_empty = FALSE;
  chartInstance->c1_is_active_c1_SIMUL_step_delay_Embed_integrated_v2 = 0U;
}

static void initialize_params_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *
   chartInstance)
{
}

static void enable_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_SIMUL_step_delay_Embed_integrated_v
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct
   *chartInstance)
{
}

static const mxArray *get_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct
   *chartInstance)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_hoistedGlobal[5];
  int32_T c1_i1;
  real_T c1_u[5];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i2;
  real_T c1_b_hoistedGlobal[4];
  int32_T c1_i3;
  real_T c1_b_u[4];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i4;
  real_T c1_c_hoistedGlobal[5];
  int32_T c1_i5;
  real_T c1_c_u[5];
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T (*c1_ymea1)[4];
  real_T (*c1_ydelay)[5];
  c1_ydelay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(5));
  for (c1_i0 = 0; c1_i0 < 5; c1_i0 = c1_i0 + 1) {
    c1_hoistedGlobal[c1_i0] = (*c1_ydelay)[c1_i0];
  }

  for (c1_i1 = 0; c1_i1 < 5; c1_i1 = c1_i1 + 1) {
    c1_u[c1_i1] = c1_hoistedGlobal[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 1U, 0U, 1, 5));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2 = c1_i2 + 1) {
    c1_b_hoistedGlobal[c1_i2] = (*c1_ymea1)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 4; c1_i3 = c1_i3 + 1) {
    c1_b_u[c1_i3] = c1_b_hoistedGlobal[c1_i3];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i4 = 0; c1_i4 < 5; c1_i4 = c1_i4 + 1) {
    c1_c_hoistedGlobal[c1_i4] = chartInstance->c1_delay1[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 5; c1_i5 = c1_i5 + 1) {
    c1_c_u[c1_i5] = c1_c_hoistedGlobal[c1_i5];
  }

  c1_d_y = NULL;
  if (!chartInstance->c1_delay1_not_empty) {
    sf_mex_assign(&c1_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 1U, 0U, 1, 5));
  }

  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_i;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  if (!chartInstance->c1_i_not_empty) {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal =
    chartInstance->c1_is_active_c1_SIMUL_step_delay_Embed_integrated_v2;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 4, c1_f_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *
   chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[5];
  int32_T c1_i6;
  real_T c1_dv1[4];
  int32_T c1_i7;
  real_T c1_dv2[5];
  int32_T c1_i8;
  real_T (*c1_ydelay)[5];
  real_T (*c1_ymea1)[4];
  c1_ydelay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "ydelay", c1_dv0);
  for (c1_i6 = 0; c1_i6 < 5; c1_i6 = c1_i6 + 1) {
    (*c1_ydelay)[c1_i6] = c1_dv0[c1_i6];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "ymea1", c1_dv1);
  for (c1_i7 = 0; c1_i7 < 4; c1_i7 = c1_i7 + 1) {
    (*c1_ymea1)[c1_i7] = c1_dv1[c1_i7];
  }

  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "delay1", c1_dv2);
  for (c1_i8 = 0; c1_i8 < 5; c1_i8 = c1_i8 + 1) {
    chartInstance->c1_delay1[c1_i8] = c1_dv2[c1_i8];
  }

  chartInstance->c1_i = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "i");
  chartInstance->c1_is_active_c1_SIMUL_step_delay_Embed_integrated_v2 =
    c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
                           (c1_u, 4)),
    "is_active_c1_SIMUL_step_delay_Embed_integrated_v2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_SIMUL_step_delay_Embed_integrated_v(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
}

static void sf_c1_SIMUL_step_delay_Embed_integrated_v2
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_previousEvent;
  int32_T c1_i12;
  real_T c1_hoistedGlobal[4];
  int32_T c1_i13;
  real_T c1_ymea[4];
  uint32_T c1_debug_family_var_map[10];
  static const char *c1_sv0[10] = { "result", "status", "delay", "nargin",
    "nargout", "ymea", "ymea1", "ydelay", "i", "delay1" };

  const mxArray *c1_result = NULL;
  const mxArray *c1_status = NULL;
  const mxArray *c1_delay = NULL;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 2.0;
  real_T c1_ymea1[4];
  real_T c1_ydelay[5];
  int32_T c1_i14;
  int32_T c1_i15;
  static char_T c1_cv0[14] = { 't', 'o', 's', 's', 'i', 'm', '-', 'c', 'a', 'l',
    'l', '.', 'p', 'y' };

  char_T c1_u[14];
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_m0 = NULL;
  const mxArray *c1_m1 = NULL;
  const mxArray *c1_b_result = NULL;
  const mxArray *c1_b_status = NULL;
  real_T c1_dv3[5];
  int32_T c1_i16;
  int32_T c1_i17;
  real_T c1_b_hoistedGlobal;
  real_T c1_x;
  real_T c1_xk;
  real_T c1_b_x;
  real_T c1_r;
  int32_T c1_i18;
  char_T c1_e_u[14];
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_m2 = NULL;
  const mxArray *c1_m3 = NULL;
  const mxArray *c1_c_result = NULL;
  const mxArray *c1_c_status = NULL;
  real_T c1_dv4[5];
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  static char_T c1_cv1[6] = { 'y', 'd', 'e', 'l', 'a', 'y' };

  char_T c1_i_u[6];
  const mxArray *c1_i_y = NULL;
  int32_T c1_i25;
  real_T c1_j_u[5];
  const mxArray *c1_j_y = NULL;
  int32_T c1_i26;
  int32_T c1_i27;
  real_T (*c1_b_ymea1)[4];
  real_T (*c1_b_ydelay)[5];
  real_T (*c1_b_ymea)[4];
  c1_b_ydelay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_ymea = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_ymea1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c1_i9 = 0; c1_i9 < 4; c1_i9 = c1_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_ymea1)[c1_i9], 0U);
  }

  for (c1_i10 = 0; c1_i10 < 4; c1_i10 = c1_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_ymea)[c1_i10], 1U);
  }

  for (c1_i11 = 0; c1_i11 < 5; c1_i11 = c1_i11 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_ydelay)[c1_i11], 2U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c1_i12 = 0; c1_i12 < 4; c1_i12 = c1_i12 + 1) {
    c1_hoistedGlobal[c1_i12] = (*c1_b_ymea)[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 4; c1_i13 = c1_i13 + 1) {
    c1_ymea[c1_i13] = c1_hoistedGlobal[c1_i13];
  }

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c1_sv0, c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_result, c1_f_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_status, c1_f_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_delay, c1_f_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_ymea, c1_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c1_ymea1, c1_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c1_ydelay, c1_c_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c1_i, c1_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c1_delay1, c1_sf_marshall, 9U);
  CV_EML_FCN(0, 0);

  /*  Inputs: */
  /*  ymea: measurement from structure */
  /*  Outputs: */
  /*  ymea1: measurement output */
  /*  ydelay: delay traces */
  /*  delay trace */
  /*  count */
  /*  allow these matlab functions to be used in Embedded Matlab block */
  _SFD_EML_CALL(0,14);
  _SFD_EML_CALL(0,15);
  _SFD_EML_CALL(0,16);
  _SFD_EML_CALL(0,17);
  _SFD_EML_CALL(0,19);
  for (c1_i14 = 0; c1_i14 < 5; c1_i14 = c1_i14 + 1) {
    c1_ydelay[c1_i14] = 0.0;
  }

  _SFD_EML_CALL(0,21);
  if (CV_EML_IF(0, 0, !chartInstance->c1_i_not_empty)) {
    _SFD_EML_CALL(0,23);
    chartInstance->c1_i = 0.0;
    chartInstance->c1_i_not_empty = TRUE;

    /*  call python to communicate with TOSSIM */
    /*
       [result status node_id_final delay_final fb_data_out]=python('tossim_config-tdma-bridge.py', num2str(0), num2str(0), num2str(0),num2str(0),num2str(0)); */
    _SFD_EML_CALL(0,26);
    for (c1_i15 = 0; c1_i15 < 14; c1_i15 = c1_i15 + 1) {
      c1_u[c1_i15] = c1_cv0[c1_i15];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 14));
    c1_b_u = 0.0;
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
    c1_c_u = 0.0;
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0));
    c1_d_u = 0.0;
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0));
    sf_mex_call_debug("python", 2U, 4U, 14, c1_y, 14, sf_mex_call_debug(
      "num2str", 1U, 1U, 14, c1_b_y), 14, sf_mex_call_debug("num2str"
      , 1U, 1U, 14, c1_c_y), 14, sf_mex_call_debug("num2str", 1U, 1U, 14, c1_d_y),
                      &c1_m1, &c1_m0);
    sf_mex_assign(&c1_b_result, sf_mex_dup(c1_m1));
    sf_mex_assign(&c1_b_status, sf_mex_dup(c1_m0));
    sf_mex_assign(&c1_result, sf_mex_dup(c1_b_result));
    sf_mex_assign(&c1_status, sf_mex_dup(c1_b_status));
    _SFD_EML_CALL(0,27);
    sf_mex_assign(&c1_delay, sf_mex_call_debug("delay_summary", 1U, 1U, 14,
      sf_mex_dup(c1_result)));

    /*  assign delay */
    _SFD_EML_CALL(0,29);
    c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_delay), "delay", c1_dv3);
    for (c1_i16 = 0; c1_i16 < 5; c1_i16 = c1_i16 + 1) {
      c1_ydelay[c1_i16] = c1_dv3[c1_i16];
    }

    _SFD_EML_CALL(0,30);
    for (c1_i17 = 0; c1_i17 < 5; c1_i17 = c1_i17 + 1) {
      chartInstance->c1_delay1[c1_i17] = c1_ydelay[c1_i17];
    }

    chartInstance->c1_delay1_not_empty = TRUE;
  } else {
    _SFD_EML_CALL(0,32);
    c1_b_hoistedGlobal = chartInstance->c1_i;
    c1_x = c1_b_hoistedGlobal;
    c1_xk = c1_x;
    c1_b_x = c1_xk;
    c1_r = muDoubleScalarRem(c1_b_x, 40.0);
    if (CV_EML_COND(0, 0, c1_r == 0.0)) {
      if (CV_EML_COND(0, 1, chartInstance->c1_i != 0.0)) {
        CV_EML_MCDC(0, 0, TRUE);
        CV_EML_IF(0, 1, TRUE);

        /*  call python to communicate with TOSSIM */
        /*
           [result status node_id_final delay_final fb_data_out]=python('tossim_config-tdma-bridge.py', num2str(0), num2str(0), num2str(0),num2str(0),num2str(0)); */
        _SFD_EML_CALL(0,36);
        for (c1_i18 = 0; c1_i18 < 14; c1_i18 = c1_i18 + 1) {
          c1_e_u[c1_i18] = c1_cv0[c1_i18];
        }

        c1_e_y = NULL;
        sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 10, 0U, 1U, 0U, 2, 1,
          14));
        c1_f_u = 0.0;
        c1_f_y = NULL;
        sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0));
        c1_g_u = 0.0;
        c1_g_y = NULL;
        sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0));
        c1_h_u = 0.0;
        c1_h_y = NULL;
        sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0));
        sf_mex_call_debug("python", 2U, 4U, 14, c1_e_y, 14, sf_mex_call_debug(
          "num2str", 1U, 1U, 14, c1_f_y), 14, sf_mex_call_debug(
          "num2str", 1U, 1U, 14, c1_g_y), 14, sf_mex_call_debug("num2str", 1U,
          1U, 14, c1_h_y), &c1_m3, &c1_m2);
        sf_mex_assign(&c1_c_result, sf_mex_dup(c1_m3));
        sf_mex_assign(&c1_c_status, sf_mex_dup(c1_m2));
        sf_mex_assign(&c1_result, sf_mex_dup(c1_c_result));
        sf_mex_assign(&c1_status, sf_mex_dup(c1_c_status));
        _SFD_EML_CALL(0,37);
        sf_mex_assign(&c1_delay, sf_mex_call_debug("delay_summary", 1U, 1U, 14,
          sf_mex_dup(c1_result)));

        /*  assign delay */
        _SFD_EML_CALL(0,39);
        c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_delay), "delay", c1_dv4);
        for (c1_i19 = 0; c1_i19 < 5; c1_i19 = c1_i19 + 1) {
          c1_ydelay[c1_i19] = c1_dv4[c1_i19];
        }

        _SFD_EML_CALL(0,40);
        for (c1_i20 = 0; c1_i20 < 5; c1_i20 = c1_i20 + 1) {
          chartInstance->c1_delay1[c1_i20] = c1_ydelay[c1_i20];
        }

        goto label_1;
      }
    }

    CV_EML_MCDC(0, 0, FALSE);
    CV_EML_IF(0, 1, FALSE);
    _SFD_EML_CALL(0,43);
    for (c1_i21 = 0; c1_i21 < 5; c1_i21 = c1_i21 + 1) {
      c1_ydelay[c1_i21] = chartInstance->c1_delay1[c1_i21];
    }

   label_1:
    ;
  }

  _SFD_EML_CALL(0,46);
  chartInstance->c1_i = chartInstance->c1_i + 1.0;
  _SFD_EML_CALL(0,48);
  for (c1_i22 = 0; c1_i22 < 4; c1_i22 = c1_i22 + 1) {
    c1_ymea1[c1_i22] = 0.0;
  }

  _SFD_EML_CALL(0,49);
  for (c1_i23 = 0; c1_i23 < 4; c1_i23 = c1_i23 + 1) {
    c1_ymea1[c1_i23] = c1_ymea[c1_i23];
  }

  _SFD_EML_CALL(0,50);
  for (c1_i24 = 0; c1_i24 < 6; c1_i24 = c1_i24 + 1) {
    c1_i_u[c1_i24] = c1_cv1[c1_i24];
  }

  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 10, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_call_debug("disp", 0U, 1U, 14, c1_i_y);
  _SFD_EML_CALL(0,51);
  for (c1_i25 = 0; c1_i25 < 5; c1_i25 = c1_i25 + 1) {
    c1_j_u[c1_i25] = c1_ydelay[c1_i25];
  }

  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_j_u, 0, 0U, 1U, 0U, 2, 1, 5));
  sf_mex_call_debug("disp", 0U, 1U, 14, c1_j_y);
  _SFD_EML_CALL(0,-51);
  sf_debug_symbol_scope_pop();
  sf_mex_destroy(&c1_result);
  sf_mex_destroy(&c1_status);
  sf_mex_destroy(&c1_delay);
  sf_mex_destroy(&c1_c_result);
  sf_mex_destroy(&c1_c_status);
  sf_mex_destroy(&c1_b_result);
  sf_mex_destroy(&c1_b_status);
  sf_mex_destroy(&c1_m0);
  sf_mex_destroy(&c1_m1);
  sf_mex_destroy(&c1_m2);
  sf_mex_destroy(&c1_m3);
  for (c1_i26 = 0; c1_i26 < 4; c1_i26 = c1_i26 + 1) {
    (*c1_b_ymea1)[c1_i26] = c1_ymea1[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 5; c1_i27 = c1_i27 + 1) {
    (*c1_b_ydelay)[c1_i27] = c1_ydelay[c1_i27];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_SIMUL_step_delay_Embed_integrated_v2MachineNumber_,
     chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static void c1_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_delay,
   const char_T *c1_name, real_T c1_y[5])
{
  real_T c1_dv5[5];
  int32_T c1_i28;
  sf_mex_import(c1_name, sf_mex_dup(c1_delay), &c1_dv5, 1, 0, 0U, 1, 0U, 1, 5);
  for (c1_i28 = 0; c1_i28 < 5; c1_i28 = c1_i28 + 1) {
    c1_y[c1_i28] = c1_dv5[c1_i28];
  }

  sf_mex_destroy(&c1_delay);
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i29;
  real_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  for (c1_i29 = 0; c1_i29 < 5; c1_i29 = c1_i29 + 1) {
    c1_b_u[c1_i29] = (*((real_T (*)[5])c1_u))[c1_i29];
  }

  c1_b_y = NULL;
  if (!chartInstance->c1_delay1_not_empty) {
    sf_mex_assign(&c1_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 5));
  }

  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  if (!chartInstance->c1_i_not_empty) {
    sf_mex_assign(&c1_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i30;
  real_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  for (c1_i30 = 0; c1_i30 < 5; c1_i30 = c1_i30 + 1) {
    c1_b_u[c1_i30] = (*((real_T (*)[5])c1_u))[c1_i30];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 5));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i31;
  real_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  for (c1_i31 = 0; c1_i31 < 4; c1_i31 = c1_i31 + 1) {
    c1_b_u[c1_i31] = (*((real_T (*)[4])c1_u))[c1_i31];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = sf_mex_dup(*((const mxArray **)c1_u));
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_duplicatearraysafe(&c1_b_u));
  sf_mex_destroy(&c1_b_u);
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray
  *sf_c1_SIMUL_step_delay_Embed_integrated_v2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[19];
  const mxArray *c1_m4 = NULL;
  int32_T c1_i32;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m4, sf_mex_createstruct("nameCaptureInfo", 1, 19));
  for (c1_i32 = 0; c1_i32 < 19; c1_i32 = c1_i32 + 1) {
    c1_r0 = &c1_info[c1_i32];
    sf_mex_addfield(c1_m4, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i32);
    sf_mex_addfield(c1_m4, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i32);
    sf_mex_addfield(c1_m4, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i32);
    sf_mex_addfield(c1_m4, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i32);
    sf_mex_addfield(c1_m4, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i32);
    sf_mex_addfield(c1_m4, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i32
                    );
    sf_mex_addfield(c1_m4, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i32
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m4);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[19])
{
  c1_info[0].context = "";
  c1_info[0].name = "ctranspose";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[B]ctranspose";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "rem";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[1].fileLength = 961U;
  c1_info[1].fileTime1 = 1244760750U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[2].name = "nargin";
  c1_info[2].dominantType = "";
  c1_info[2].resolved = "[B]nargin";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[3].name = "gt";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[B]gt";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[4].name = "isreal";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]isreal";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[5].name = "isa";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]isa";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[6].name = "class";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]class";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[7].name = "eml_scalar_eg";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[7].fileLength = 3068U;
  c1_info[7].fileTime1 = 1240287210U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c1_info[8].name = "false";
  c1_info[8].dominantType = "";
  c1_info[8].resolved = "[B]false";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[9].name = "isstruct";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]isstruct";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c1_info[10].name = "eq";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]eq";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c1_info[11].name = "cast";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[B]cast";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c1_info[12].name = "plus";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]plus";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[13].name = "eml_scalexp_alloc";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[13].fileLength = 808U;
  c1_info[13].fileTime1 = 1230519898U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[14].name = "minus";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[B]minus";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[15].name = "isscalar";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[B]isscalar";
  c1_info[15].fileLength = 0U;
  c1_info[15].fileTime1 = 0U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[16].name = "not";
  c1_info[16].dominantType = "logical";
  c1_info[16].resolved = "[B]not";
  c1_info[16].fileLength = 0U;
  c1_info[16].fileTime1 = 0U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[17].name = "eml_scalar_rem";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  c1_info[17].fileLength = 1167U;
  c1_info[17].fileTime1 = 1236282454U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context = "";
  c1_info[18].name = "ne";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[B]ne";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
}

static const mxArray *c1_g_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static void c1_b_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_ydelay,
   const char_T *c1_name, real_T c1_y[5])
{
  real_T c1_dv6[5];
  int32_T c1_i33;
  sf_mex_import(c1_name, sf_mex_dup(c1_ydelay), &c1_dv6, 1, 0, 0U, 1, 0U, 1, 5);
  for (c1_i33 = 0; c1_i33 < 5; c1_i33 = c1_i33 + 1) {
    c1_y[c1_i33] = c1_dv6[c1_i33];
  }

  sf_mex_destroy(&c1_ydelay);
}

static void c1_c_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_ymea1,
   const char_T *c1_name, real_T c1_y[4])
{
  real_T c1_dv7[4];
  int32_T c1_i34;
  sf_mex_import(c1_name, sf_mex_dup(c1_ymea1), &c1_dv7, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i34 = 0; c1_i34 < 4; c1_i34 = c1_i34 + 1) {
    c1_y[c1_i34] = c1_dv7[c1_i34];
  }

  sf_mex_destroy(&c1_ymea1);
}

static void c1_d_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_b_delay1
   , const char_T *c1_name, real_T c1_y[5])
{
  real_T c1_dv8[5];
  int32_T c1_i35;
  if (mxIsEmpty(c1_b_delay1)) {
    chartInstance->c1_delay1_not_empty = FALSE;
  } else {
    chartInstance->c1_delay1_not_empty = TRUE;
    sf_mex_import(c1_name, sf_mex_dup(c1_b_delay1), &c1_dv8, 1, 0, 0U, 1, 0U, 1,
                  5);
    for (c1_i35 = 0; c1_i35 < 5; c1_i35 = c1_i35 + 1) {
      c1_y[c1_i35] = c1_dv8[c1_i35];
    }
  }

  sf_mex_destroy(&c1_b_delay1);
}

static real_T c1_e_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c1_b_i,
   const char_T *c1_name)
{
  real_T c1_y;
  real_T c1_d0;
  if (mxIsEmpty(c1_b_i)) {
    chartInstance->c1_i_not_empty = FALSE;
  } else {
    chartInstance->c1_i_not_empty = TRUE;
    sf_mex_import(c1_name, sf_mex_dup(c1_b_i), &c1_d0, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d0;
  }

  sf_mex_destroy(&c1_b_i);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *
   c1_b_is_active_c1_SIMUL_step_delay_Embed_integrated_v2, const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup
                (c1_b_is_active_c1_SIMUL_step_delay_Embed_integrated_v2), &c1_u0,
                1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_SIMUL_step_delay_Embed_integrated_v2);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_SIMUL_step_delay_Embed_integrated_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1357135634U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2119922260U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1682656522U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2249503281U);
}

mxArray *sf_c1_SIMUL_step_delay_Embed_integrated_v2_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4120975397U);
    pr[1] = (double)(3815607255U);
    pr[2] = (double)(2248754673U);
    pr[3] = (double)(412029176U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(5);
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

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_SIMUL_step_delay_Embed_integrated_v2
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"ydelay\",},{M[1],M[7],T\"ymea1\",},{M[4],M[0],T\"delay1\",S'l','i','p'{{M1x2[168 174],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[200 201],M[0],}}},{M[8],M[0],T\"is_active_c1_SIMUL_step_delay_Embed_integrated_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_SIMUL_step_delay_Embed_integrated_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
    chartInstance = (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SIMUL_step_delay_Embed_integrated_v2MachineNumber_,
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
          init_script_number_translation
            (_SIMUL_step_delay_Embed_integrated_v2MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_SIMUL_step_delay_Embed_integrated_v2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_SIMUL_step_delay_Embed_integrated_v2MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ymea1",0,(MexFcnForType)c1_d_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ymea",0,(MexFcnForType)c1_d_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 5;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ydelay",0,(MexFcnForType)c1_c_sf_marshall);
          }

          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1351);
        _SFD_CV_INIT_EML_IF(0,0,409,422,826,1276);
        _SFD_CV_INIT_EML_IF(0,1,826,855,1247,1276);

        {
          static int condStart[] = { 834, 850 };

          static int condEnd[] = { 846, 854 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,834,854,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
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
          real_T (*c1_ymea1)[4];
          real_T (*c1_ymea)[4];
          real_T (*c1_ydelay)[5];
          c1_ydelay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_ymea = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          c1_ymea1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_ymea1);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_ymea);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_ydelay);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SIMUL_step_delay_Embed_integrated_v2MachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c1_SIMUL_step_delay_Embed_integrated_v2
    ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
  initialize_c1_SIMUL_step_delay_Embed_integrated_v2
    ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  enable_c1_SIMUL_step_delay_Embed_integrated_v2
    ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  disable_c1_SIMUL_step_delay_Embed_integrated_v2
    ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  sf_c1_SIMUL_step_delay_Embed_integrated_v2
    ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
}

static mxArray*
  sf_internal_get_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2
    ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_SIMUL_step_delay_Embed_integrated_v2();/* state var info */
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

static void sf_internal_set_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c1_SIMUL_step_delay_Embed_integrated_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2
    ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2(S);
}

static void sf_opaque_set_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2(S, st);
}

static void sf_opaque_terminate_c1_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_SIMUL_step_delay_Embed_integrated_v2
      ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_SIMUL_step_delay_Embed_integrated_v2
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_SIMUL_step_delay_Embed_integrated_v2
      ((SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_SIMUL_step_delay_Embed_integrated_v2(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("SIMUL_step_delay_Embed_integrated_v2",
      "SIMUL_step_delay_Embed_integrated_v2",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("SIMUL_step_delay_Embed_integrated_v2",
                "SIMUL_step_delay_Embed_integrated_v2",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "SIMUL_step_delay_Embed_integrated_v2",
      "SIMUL_step_delay_Embed_integrated_v2",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "SIMUL_step_delay_Embed_integrated_v2",
        "SIMUL_step_delay_Embed_integrated_v2",1,1);
      sf_mark_chart_reusable_outputs(S,"SIMUL_step_delay_Embed_integrated_v2",
        "SIMUL_step_delay_Embed_integrated_v2",1,2);
    }

    sf_set_rtw_dwork_info(S,"SIMUL_step_delay_Embed_integrated_v2",
                          "SIMUL_step_delay_Embed_integrated_v2",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3153806299U));
  ssSetChecksum1(S,(3284858986U));
  ssSetChecksum2(S,(259385100U));
  ssSetChecksum3(S,(3446196664U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_SIMUL_step_delay_Embed_integrated_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SIMUL_step_delay_Embed_integrated_v2",
      "SIMUL_step_delay_Embed_integrated_v2",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_SIMUL_step_delay_Embed_integrated_v2(SimStruct *S)
{
  SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    malloc(sizeof(SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_SIMUL_step_delay_Embed_integrated_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info(chartInstance);
  }

  chart_debug_initialization(S,1);
}

void c1_SIMUL_step_delay_Embed_integrated_v2_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_SIMUL_step_delay_Embed_integrated_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_SIMUL_step_delay_Embed_integrated_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_SIMUL_step_delay_Embed_integrated_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_SIMUL_step_delay_Embed_integrated_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
