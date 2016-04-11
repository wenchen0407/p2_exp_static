/* Include files */

#include "blascompat32.h"
#include "SIMUL_step_delay_Embed_integrated_sfun.h"
#include "c1_SIMUL_step_delay_Embed_integrated.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMUL_step_delay_Embed_integrated_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[8] = { "result", "status", "delay",
  "nargin", "nargout", "ymea", "ymea1", "ydelay" };

/* Function Declarations */
static void initialize_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance);
static void initialize_params_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance);
static void enable_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance);
static void disable_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance);
static void set_sim_state_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void finalize_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance);
static void sf_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance, const
   mxArray *c1_delay, const char_T *c1_name, real_T c1_y[5]);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_b_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance, const
   mxArray *c1_ydelay, const char_T *c1_name, real_T c1_y[5]);
static void c1_c_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance, const
   mxArray *c1_ymea1, const char_T *c1_name, real_T c1_y[4]);
static uint8_T c1_d_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_SIMUL_step_delay_Embed_integrated, const char_T
   *c1_name);
static void init_dsm_address_info
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_SIMUL_step_delay_Embed_integrated = 0U;
}

static void initialize_params_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *
   chartInstance)
{
}

static void enable_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *
   chartInstance)
{
}

static const mxArray *get_sim_state_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *
   chartInstance)
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
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T (*c1_ymea1)[4];
  real_T (*c1_ydelay)[5];
  c1_ydelay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3));
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
  c1_c_hoistedGlobal =
    chartInstance->c1_is_active_c1_SIMUL_step_delay_Embed_integrated;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance,
   const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[5];
  int32_T c1_i4;
  real_T c1_dv1[4];
  int32_T c1_i5;
  real_T (*c1_ydelay)[5];
  real_T (*c1_ymea1)[4];
  c1_ydelay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ymea1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "ydelay", c1_dv0);
  for (c1_i4 = 0; c1_i4 < 5; c1_i4 = c1_i4 + 1) {
    (*c1_ydelay)[c1_i4] = c1_dv0[c1_i4];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "ymea1", c1_dv1);
  for (c1_i5 = 0; c1_i5 < 4; c1_i5 = c1_i5 + 1) {
    (*c1_ymea1)[c1_i5] = c1_dv1[c1_i5];
  }

  chartInstance->c1_is_active_c1_SIMUL_step_delay_Embed_integrated =
    c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    c1_u, 2)), "is_active_c1_SIMUL_step_delay_Embed_integrated");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_SIMUL_step_delay_Embed_integrated(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance)
{
}

static void sf_c1_SIMUL_step_delay_Embed_integrated
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance)
{
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_previousEvent;
  int32_T c1_i9;
  real_T c1_hoistedGlobal[4];
  int32_T c1_i10;
  real_T c1_ymea[4];
  uint32_T c1_debug_family_var_map[8];
  static const char *c1_sv0[8] = { "result", "status", "delay", "nargin",
    "nargout", "ymea", "ymea1", "ydelay" };

  const mxArray *c1_result = NULL;
  const mxArray *c1_status = NULL;
  const mxArray *c1_delay = NULL;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 2.0;
  real_T c1_ymea1[4];
  real_T c1_ydelay[5];
  int32_T c1_i11;
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
  int32_T c1_i12;
  real_T c1_dv2[5];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  static char_T c1_cv1[6] = { 'y', 'd', 'e', 'l', 'a', 'y' };

  char_T c1_e_u[6];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i17;
  real_T c1_f_u[5];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i18;
  int32_T c1_i19;
  real_T (*c1_b_ymea1)[4];
  real_T (*c1_b_ydelay)[5];
  real_T (*c1_b_ymea)[4];
  c1_b_ydelay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_ymea = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_ymea1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c1_i6 = 0; c1_i6 < 4; c1_i6 = c1_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_ymea1)[c1_i6], 0U);
  }

  for (c1_i7 = 0; c1_i7 < 4; c1_i7 = c1_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_ymea)[c1_i7], 1U);
  }

  for (c1_i8 = 0; c1_i8 < 5; c1_i8 = c1_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_ydelay)[c1_i8], 2U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c1_i9 = 0; c1_i9 < 4; c1_i9 = c1_i9 + 1) {
    c1_hoistedGlobal[c1_i9] = (*c1_b_ymea)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 4; c1_i10 = c1_i10 + 1) {
    c1_ymea[c1_i10] = c1_hoistedGlobal[c1_i10];
  }

  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c1_sv0, c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_result, c1_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_status, c1_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_delay, c1_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_c_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_ymea, c1_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c1_ymea1, c1_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c1_ydelay, c1_sf_marshall, 7U);
  CV_EML_FCN(0, 0);

  /*  Inputs: */
  /*  ymea: measurement from structure */
  /*  Outputs: */
  /*  ymea1: measurement output */
  /*  ydelay: delay traces */
  /*  allow these matlab functions to be used in Embedded Matlab block */
  _SFD_EML_CALL(0,11);
  _SFD_EML_CALL(0,12);
  _SFD_EML_CALL(0,13);
  _SFD_EML_CALL(0,14);

  /*  call python to communicate with TOSSIM */
  /*
     [result status node_id_final delay_final fb_data_out]=python('tossim_config-tdma-bridge.py', num2str(0), num2str(0), num2str(0),num2str(0),num2str(0)); */
  _SFD_EML_CALL(0,18);
  for (c1_i11 = 0; c1_i11 < 14; c1_i11 = c1_i11 + 1) {
    c1_u[c1_i11] = c1_cv0[c1_i11];
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
  sf_mex_call_debug("python", 2U, 4U, 14, c1_y, 14, sf_mex_call_debug("num2str",
    1U, 1U, 14, c1_b_y), 14, sf_mex_call_debug("num2str"
    , 1U, 1U, 14, c1_c_y), 14, sf_mex_call_debug("num2str", 1U, 1U, 14, c1_d_y),
                    &c1_m1, &c1_m0);
  sf_mex_assign(&c1_b_result, sf_mex_dup(c1_m1));
  sf_mex_assign(&c1_b_status, sf_mex_dup(c1_m0));
  sf_mex_assign(&c1_result, sf_mex_dup(c1_b_result));
  sf_mex_assign(&c1_status, sf_mex_dup(c1_b_status));
  _SFD_EML_CALL(0,19);
  sf_mex_assign(&c1_delay, sf_mex_call_debug("delay_summary", 1U, 1U, 14,
    sf_mex_dup(c1_result)));

  /*  disp('delay') */
  /*  disp(delay) */
  /*  assign delay  */
  _SFD_EML_CALL(0,25);
  for (c1_i12 = 0; c1_i12 < 5; c1_i12 = c1_i12 + 1) {
    c1_ydelay[c1_i12] = 0.0;
  }

  _SFD_EML_CALL(0,26);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_delay), "delay", c1_dv2);
  for (c1_i13 = 0; c1_i13 < 5; c1_i13 = c1_i13 + 1) {
    c1_ydelay[c1_i13] = c1_dv2[c1_i13];
  }

  _SFD_EML_CALL(0,28);
  for (c1_i14 = 0; c1_i14 < 4; c1_i14 = c1_i14 + 1) {
    c1_ymea1[c1_i14] = 0.0;
  }

  _SFD_EML_CALL(0,29);
  for (c1_i15 = 0; c1_i15 < 4; c1_i15 = c1_i15 + 1) {
    c1_ymea1[c1_i15] = c1_ymea[c1_i15];
  }

  _SFD_EML_CALL(0,30);
  for (c1_i16 = 0; c1_i16 < 6; c1_i16 = c1_i16 + 1) {
    c1_e_u[c1_i16] = c1_cv1[c1_i16];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 10, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_call_debug("disp", 0U, 1U, 14, c1_e_y);
  _SFD_EML_CALL(0,31);
  for (c1_i17 = 0; c1_i17 < 5; c1_i17 = c1_i17 + 1) {
    c1_f_u[c1_i17] = c1_ydelay[c1_i17];
  }

  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 1U, 0U, 2, 1, 5));
  sf_mex_call_debug("disp", 0U, 1U, 14, c1_f_y);
  _SFD_EML_CALL(0,-31);
  sf_debug_symbol_scope_pop();
  sf_mex_destroy(&c1_result);
  sf_mex_destroy(&c1_status);
  sf_mex_destroy(&c1_delay);
  sf_mex_destroy(&c1_b_result);
  sf_mex_destroy(&c1_b_status);
  sf_mex_destroy(&c1_m0);
  sf_mex_destroy(&c1_m1);
  for (c1_i18 = 0; c1_i18 < 4; c1_i18 = c1_i18 + 1) {
    (*c1_b_ymea1)[c1_i18] = c1_ymea1[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 5; c1_i19 = c1_i19 + 1) {
    (*c1_b_ydelay)[c1_i19] = c1_ydelay[c1_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_SIMUL_step_delay_Embed_integratedMachineNumber_,
     chartInstance->chartNumber, chartInstance->
     instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static void c1_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance, const
   mxArray *c1_delay, const
   char_T *c1_name, real_T c1_y[5])
{
  real_T c1_dv3[5];
  int32_T c1_i20;
  sf_mex_import(c1_name, sf_mex_dup(c1_delay), &c1_dv3, 1, 0, 0U, 1, 0U, 1, 5);
  for (c1_i20 = 0; c1_i20 < 5; c1_i20 = c1_i20 + 1) {
    c1_y[c1_i20] = c1_dv3[c1_i20];
  }

  sf_mex_destroy(&c1_delay);
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i21;
  real_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  for (c1_i21 = 0; c1_i21 < 5; c1_i21 = c1_i21 + 1) {
    c1_b_u[c1_i21] = (*((real_T (*)[5])c1_u))[c1_i21];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 5));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i22;
  real_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  for (c1_i22 = 0; c1_i22 < 4; c1_i22 = c1_i22 + 1) {
    c1_b_u[c1_i22] = (*((real_T (*)[4])c1_u))[c1_i22];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *)
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
  *sf_c1_SIMUL_step_delay_Embed_integrated_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[1];
  c1_ResolvedFunctionInfo (*c1_b_info)[1];
  const mxArray *c1_m2 = NULL;
  int32_T c1_i23;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[1])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "ctranspose";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved = "[B]ctranspose";
  (*c1_b_info)[0].fileLength = 0U;
  (*c1_b_info)[0].fileTime1 = 0U;
  (*c1_b_info)[0].fileTime2 = 0U;
  sf_mex_assign(&c1_m2, sf_mex_createstruct("nameCaptureInfo", 1, 1));
  for (c1_i23 = 0; c1_i23 < 1; c1_i23 = c1_i23 + 1) {
    c1_r0 = &c1_info[c1_i23];
    sf_mex_addfield(c1_m2, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i23);
    sf_mex_addfield(c1_m2, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i23);
    sf_mex_addfield(c1_m2, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i23);
    sf_mex_addfield(c1_m2, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i23);
    sf_mex_addfield(c1_m2, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i23);
    sf_mex_addfield(c1_m2, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i23
                    );
    sf_mex_addfield(c1_m2, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i23
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m2);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static void c1_b_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance, const
   mxArray *c1_ydelay,
   const char_T *c1_name, real_T c1_y[5])
{
  real_T c1_dv4[5];
  int32_T c1_i24;
  sf_mex_import(c1_name, sf_mex_dup(c1_ydelay), &c1_dv4, 1, 0, 0U, 1, 0U, 1, 5);
  for (c1_i24 = 0; c1_i24 < 5; c1_i24 = c1_i24 + 1) {
    c1_y[c1_i24] = c1_dv4[c1_i24];
  }

  sf_mex_destroy(&c1_ydelay);
}

static void c1_c_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance, const
   mxArray *c1_ymea1,
   const char_T *c1_name, real_T c1_y[4])
{
  real_T c1_dv5[4];
  int32_T c1_i25;
  sf_mex_import(c1_name, sf_mex_dup(c1_ymea1), &c1_dv5, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i25 = 0; c1_i25 < 4; c1_i25 = c1_i25 + 1) {
    c1_y[c1_i25] = c1_dv5[c1_i25];
  }

  sf_mex_destroy(&c1_ymea1);
}

static uint8_T c1_d_emlrt_marshallIn
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance, const
   mxArray *
   c1_b_is_active_c1_SIMUL_step_delay_Embed_integrated, const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup
                (c1_b_is_active_c1_SIMUL_step_delay_Embed_integrated), &c1_u0, 1,
                3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_SIMUL_step_delay_Embed_integrated);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_SIMUL_step_delay_Embed_integrated_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2136274663U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2811898225U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4119377928U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1710701264U);
}

mxArray *sf_c1_SIMUL_step_delay_Embed_integrated_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4089365172U);
    pr[1] = (double)(1602059150U);
    pr[2] = (double)(2096303964U);
    pr[3] = (double)(127796586U);
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

static mxArray *sf_get_sim_state_info_c1_SIMUL_step_delay_Embed_integrated(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"ydelay\",},{M[1],M[7],T\"ymea1\",},{M[8],M[0],T\"is_active_c1_SIMUL_step_delay_Embed_integrated\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_SIMUL_step_delay_Embed_integrated_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance;
    chartInstance = (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SIMUL_step_delay_Embed_integratedMachineNumber_,
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
            (_SIMUL_step_delay_Embed_integratedMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_SIMUL_step_delay_Embed_integratedMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_SIMUL_step_delay_Embed_integratedMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ymea1",0,(MexFcnForType)c1_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ymea",0,(MexFcnForType)c1_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 5;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ydelay",0,(MexFcnForType)c1_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,788);
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
        (_SIMUL_step_delay_Embed_integratedMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_SIMUL_step_delay_Embed_integrated(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c1_SIMUL_step_delay_Embed_integrated
    ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*) chartInstanceVar);
  initialize_c1_SIMUL_step_delay_Embed_integrated
    ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_SIMUL_step_delay_Embed_integrated(void
  *chartInstanceVar)
{
  enable_c1_SIMUL_step_delay_Embed_integrated
    ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_SIMUL_step_delay_Embed_integrated(void
  *chartInstanceVar)
{
  disable_c1_SIMUL_step_delay_Embed_integrated
    ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_SIMUL_step_delay_Embed_integrated(void
  *chartInstanceVar)
{
  sf_c1_SIMUL_step_delay_Embed_integrated
    ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_SIMUL_step_delay_Embed_integrated
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_SIMUL_step_delay_Embed_integrated
    ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_SIMUL_step_delay_Embed_integrated();/* state var info */
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

static void sf_internal_set_sim_state_c1_SIMUL_step_delay_Embed_integrated
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
    sf_get_sim_state_info_c1_SIMUL_step_delay_Embed_integrated();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_SIMUL_step_delay_Embed_integrated
    ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_SIMUL_step_delay_Embed_integrated
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_SIMUL_step_delay_Embed_integrated(S);
}

static void sf_opaque_set_sim_state_c1_SIMUL_step_delay_Embed_integrated
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_SIMUL_step_delay_Embed_integrated(S, st);
}

static void sf_opaque_terminate_c1_SIMUL_step_delay_Embed_integrated(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_SIMUL_step_delay_Embed_integrated
      ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_SIMUL_step_delay_Embed_integrated(SimStruct *
  S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_SIMUL_step_delay_Embed_integrated
      ((SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct*)(((ChartInfoStruct
          *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_SIMUL_step_delay_Embed_integrated(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("SIMUL_step_delay_Embed_integrated",
      "SIMUL_step_delay_Embed_integrated",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("SIMUL_step_delay_Embed_integrated",
                "SIMUL_step_delay_Embed_integrated",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "SIMUL_step_delay_Embed_integrated","SIMUL_step_delay_Embed_integrated",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"SIMUL_step_delay_Embed_integrated",
        "SIMUL_step_delay_Embed_integrated",1,1);
      sf_mark_chart_reusable_outputs(S,"SIMUL_step_delay_Embed_integrated",
        "SIMUL_step_delay_Embed_integrated",1,2);
    }

    sf_set_rtw_dwork_info(S,"SIMUL_step_delay_Embed_integrated",
                          "SIMUL_step_delay_Embed_integrated",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2840364659U));
  ssSetChecksum1(S,(3825737644U));
  ssSetChecksum2(S,(762431929U));
  ssSetChecksum3(S,(3497115433U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_SIMUL_step_delay_Embed_integrated(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SIMUL_step_delay_Embed_integrated",
      "SIMUL_step_delay_Embed_integrated",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_SIMUL_step_delay_Embed_integrated(SimStruct *S)
{
  SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *chartInstance;
  chartInstance = (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct *)malloc
    (sizeof(SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_SIMUL_step_delay_Embed_integratedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c1_SIMUL_step_delay_Embed_integrated;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_SIMUL_step_delay_Embed_integrated;
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

void c1_SIMUL_step_delay_Embed_integrated_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_SIMUL_step_delay_Embed_integrated(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_SIMUL_step_delay_Embed_integrated(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_SIMUL_step_delay_Embed_integrated(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_SIMUL_step_delay_Embed_integrated_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
