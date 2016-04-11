/* Include files */

#include "blascompat32.h"
#include "SIMUL_step_delay_Embed_integrated_v2_sfun.h"
#include "c2_SIMUL_step_delay_Embed_integrated_v2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMUL_step_delay_Embed_integrated_v2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[16] = { "kk", "j", "nargin", "nargout",
  "yout", "ydelay", "structure", "yout_delay", "yin", "count1", "i", "yin_d",
  "yin_all", "delay1", "delay", "num" };

/* Function Declarations */
static void initialize_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void initialize_params_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void enable_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void disable_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_SIMUL_step_delay_Embed_integrated_v
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void set_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void sf_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void c2_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static real_T c2_rem(SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct
                     *chartInstance, real_T c2_x, real_T c2_y);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_e_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_f_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_g_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_h_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_i_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_j_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_k_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_l_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[20]);
static const mxArray *c2_m_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_n_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_yout_delay, const char_T *c2_name, real_T c2_y[4]);
static real_T c2_b_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_count1, const char_T *c2_name);
static void c2_c_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_delay, const char_T *c2_name, real_T c2_y[5]);
static void c2_d_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_delay1, const char_T *c2_name, real_T c2_y[155]);
static real_T c2_e_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_i, const char_T *c2_name);
static real_T c2_f_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_num, const char_T *c2_name);
static void c2_g_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_yin, const char_T *c2_name, real_T c2_y[4]);
static void c2_h_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_yin_all, const char_T *c2_name, real_T c2_y[40004]);
static void c2_i_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_yin_d, const char_T *c2_name, real_T c2_y[4]);
static uint8_T c2_j_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_SIMUL_step_delay_Embed_integrated_v2, const char_T
   *c2_name);
static void init_dsm_address_info
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *
   chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_yin_not_empty = FALSE;
  chartInstance->c2_count1_not_empty = FALSE;
  chartInstance->c2_i_not_empty = FALSE;
  chartInstance->c2_yin_d_not_empty = FALSE;
  chartInstance->c2_yin_all_not_empty = FALSE;
  chartInstance->c2_delay1_not_empty = FALSE;
  chartInstance->c2_delay_not_empty = FALSE;
  chartInstance->c2_num_not_empty = FALSE;
  chartInstance->c2_is_active_c2_SIMUL_step_delay_Embed_integrated_v2 = 0U;
}

static void initialize_params_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *
   chartInstance)
{
  const mxArray *c2_m0 = NULL;
  const mxArray *c2_mxField;
  c2_struct_v0tR0vTRrhhWAY2OuGMwxB c2_r0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'structure' in the parent workspace.\n");
  c2_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c2_mxField = sf_mex_getfield(c2_m0, "i", "structure", 0);
  sf_mex_import("structure", sf_mex_dup(c2_mxField), &c2_r0.i, 1, 0, 0U, 0, 0U,
                0);
  c2_mxField = sf_mex_getfield(c2_m0, "count", "structure", 0);
  sf_mex_import("structure", sf_mex_dup(c2_mxField), &c2_r0.count, 1, 0, 0U, 0,
                0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "yin", "structure", 0);
  sf_mex_import("structure", sf_mex_dup(c2_mxField), &c2_r0.yin, 1, 0, 0U, 1, 0U,
                2, 1, 4);
  c2_mxField = sf_mex_getfield(c2_m0, "yin_d", "structure", 0);
  sf_mex_import("structure", sf_mex_dup(c2_mxField), &c2_r0.yin_d, 1, 0, 0U, 1,
                0U, 2, 4, 1);
  c2_mxField = sf_mex_getfield(c2_m0, "delay1", "structure", 0);
  sf_mex_import("structure", sf_mex_dup(c2_mxField), &c2_r0.delay1, 1, 0, 0U, 1,
                0U, 2, 31, 5);
  c2_mxField = sf_mex_getfield(c2_m0, "ranD", "structure", 0);
  sf_mex_import("structure", sf_mex_dup(c2_mxField), &c2_r0.ranD, 1, 0, 0U, 1,
                0U, 2, 1, 4);
  sf_mex_destroy(&c2_m0);
  chartInstance->c2_structure = c2_r0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_SIMUL_step_delay_Embed_integrated_v
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct
   *chartInstance)
{
}

static const mxArray *get_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct
   *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_hoistedGlobal[4];
  int32_T c2_i1;
  real_T c2_u[4];
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i2;
  real_T c2_c_hoistedGlobal[5];
  int32_T c2_i3;
  real_T c2_c_u[5];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i4;
  real_T c2_d_hoistedGlobal[155];
  int32_T c2_i5;
  real_T c2_d_u[155];
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  int32_T c2_i6;
  real_T c2_g_hoistedGlobal[4];
  int32_T c2_i7;
  real_T c2_g_u[4];
  const mxArray *c2_h_y = NULL;
  int32_T c2_i8;
  static real_T c2_h_hoistedGlobal[40004];
  int32_T c2_i9;
  static real_T c2_h_u[40004];
  const mxArray *c2_i_y = NULL;
  int32_T c2_i10;
  real_T c2_i_hoistedGlobal[4];
  int32_T c2_i11;
  real_T c2_i_u[4];
  const mxArray *c2_j_y = NULL;
  uint8_T c2_j_hoistedGlobal;
  uint8_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  real_T (*c2_yout_delay)[4];
  c2_yout_delay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(10));
  for (c2_i0 = 0; c2_i0 < 4; c2_i0 = c2_i0 + 1) {
    c2_hoistedGlobal[c2_i0] = (*c2_yout_delay)[c2_i0];
  }

  for (c2_i1 = 0; c2_i1 < 4; c2_i1 = c2_i1 + 1) {
    c2_u[c2_i1] = c2_hoistedGlobal[c2_i1];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_count1;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  if (!chartInstance->c2_count1_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i2 = 0; c2_i2 < 5; c2_i2 = c2_i2 + 1) {
    c2_c_hoistedGlobal[c2_i2] = chartInstance->c2_delay[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 5; c2_i3 = c2_i3 + 1) {
    c2_c_u[c2_i3] = c2_c_hoistedGlobal[c2_i3];
  }

  c2_d_y = NULL;
  if (!chartInstance->c2_delay_not_empty) {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 1U, 0U, 2, 1, 5));
  }

  sf_mex_setcell(c2_y, 2, c2_d_y);
  for (c2_i4 = 0; c2_i4 < 155; c2_i4 = c2_i4 + 1) {
    c2_d_hoistedGlobal[c2_i4] = chartInstance->c2_delay1[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 155; c2_i5 = c2_i5 + 1) {
    c2_d_u[c2_i5] = c2_d_hoistedGlobal[c2_i5];
  }

  c2_e_y = NULL;
  if (!chartInstance->c2_delay1_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 1U, 0U, 2, 31, 5));
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_i;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  if (!chartInstance->c2_i_not_empty) {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = chartInstance->c2_num;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  if (!chartInstance->c2_num_not_empty) {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 5, c2_g_y);
  for (c2_i6 = 0; c2_i6 < 4; c2_i6 = c2_i6 + 1) {
    c2_g_hoistedGlobal[c2_i6] = chartInstance->c2_yin[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 4; c2_i7 = c2_i7 + 1) {
    c2_g_u[c2_i7] = c2_g_hoistedGlobal[c2_i7];
  }

  c2_h_y = NULL;
  if (!chartInstance->c2_yin_not_empty) {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 1U, 0U, 2, 1, 4));
  }

  sf_mex_setcell(c2_y, 6, c2_h_y);
  for (c2_i8 = 0; c2_i8 < 40004; c2_i8 = c2_i8 + 1) {
    c2_h_hoistedGlobal[c2_i8] = chartInstance->c2_yin_all[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 40004; c2_i9 = c2_i9 + 1) {
    c2_h_u[c2_i9] = c2_h_hoistedGlobal[c2_i9];
  }

  c2_i_y = NULL;
  if (!chartInstance->c2_yin_all_not_empty) {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 1U, 0U, 2, 10001,
      4));
  }

  sf_mex_setcell(c2_y, 7, c2_i_y);
  for (c2_i10 = 0; c2_i10 < 4; c2_i10 = c2_i10 + 1) {
    c2_i_hoistedGlobal[c2_i10] = chartInstance->c2_yin_d[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 4; c2_i11 = c2_i11 + 1) {
    c2_i_u[c2_i11] = c2_i_hoistedGlobal[c2_i11];
  }

  c2_j_y = NULL;
  if (!chartInstance->c2_yin_d_not_empty) {
    sf_mex_assign(&c2_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 0, 0U, 1U, 0U, 1, 4));
  }

  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal =
    chartInstance->c2_is_active_c2_SIMUL_step_delay_Embed_integrated_v2;
  c2_j_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 9, c2_k_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *
   chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[4];
  int32_T c2_i12;
  real_T c2_dv1[5];
  int32_T c2_i13;
  real_T c2_dv2[155];
  int32_T c2_i14;
  real_T c2_dv3[4];
  int32_T c2_i15;
  static real_T c2_dv4[40004];
  int32_T c2_i16;
  real_T c2_dv5[4];
  int32_T c2_i17;
  real_T (*c2_yout_delay)[4];
  c2_yout_delay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "yout_delay", c2_dv0);
  for (c2_i12 = 0; c2_i12 < 4; c2_i12 = c2_i12 + 1) {
    (*c2_yout_delay)[c2_i12] = c2_dv0[c2_i12];
  }

  chartInstance->c2_count1 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "count1");
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
                        "delay", c2_dv1);
  for (c2_i13 = 0; c2_i13 < 5; c2_i13 = c2_i13 + 1) {
    chartInstance->c2_delay[c2_i13] = c2_dv1[c2_i13];
  }

  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
                        "delay1", c2_dv2);
  for (c2_i14 = 0; c2_i14 < 155; c2_i14 = c2_i14 + 1) {
    chartInstance->c2_delay1[c2_i14] = c2_dv2[c2_i14];
  }

  chartInstance->c2_i = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 4)), "i");
  chartInstance->c2_num = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 5)), "num");
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 6)),
                        "yin", c2_dv3);
  for (c2_i15 = 0; c2_i15 < 4; c2_i15 = c2_i15 + 1) {
    chartInstance->c2_yin[c2_i15] = c2_dv3[c2_i15];
  }

  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 7)),
                        "yin_all", c2_dv4);
  for (c2_i16 = 0; c2_i16 < 40004; c2_i16 = c2_i16 + 1) {
    chartInstance->c2_yin_all[c2_i16] = c2_dv4[c2_i16];
  }

  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 8)),
                        "yin_d", c2_dv5);
  for (c2_i17 = 0; c2_i17 < 4; c2_i17 = c2_i17 + 1) {
    chartInstance->c2_yin_d[c2_i17] = c2_dv5[c2_i17];
  }

  chartInstance->c2_is_active_c2_SIMUL_step_delay_Embed_integrated_v2 =
    c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
                           (c2_u, 9)),
    "is_active_c2_SIMUL_step_delay_Embed_integrated_v2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_SIMUL_step_delay_Embed_integrated_v(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
}

static void sf_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_previousEvent;
  real_T (*c2_yout_delay)[4];
  real_T (*c2_ydelay)[5];
  real_T (*c2_yout)[4];
  c2_yout_delay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_ydelay = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 1);
  c2_yout = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  for (c2_i18 = 0; c2_i18 < 4; c2_i18 = c2_i18 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_yout)[c2_i18], 0U);
  }

  for (c2_i19 = 0; c2_i19 < 5; c2_i19 = c2_i19 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_ydelay)[c2_i19], 1U);
  }

  for (c2_i20 = 0; c2_i20 < 4; c2_i20 = c2_i20 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_yout_delay)[c2_i20], 2U);
  }

  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_SIMUL_step_delay_Embed_integrated_v2(chartInstance);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_SIMUL_step_delay_Embed_integrated_v2MachineNumber_,
     chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c2_c2_SIMUL_step_delay_Embed_integrated_v2
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
  int32_T c2_i21;
  real_T c2_hoistedGlobal[4];
  int32_T c2_i22;
  real_T c2_b_hoistedGlobal[5];
  c2_struct_v0tR0vTRrhhWAY2OuGMwxB c2_c_hoistedGlobal;
  int32_T c2_i23;
  real_T c2_yout[4];
  int32_T c2_i24;
  real_T c2_ydelay[5];
  c2_struct_v0tR0vTRrhhWAY2OuGMwxB c2_b_structure;
  uint32_T c2_debug_family_var_map[16];
  static const char *c2_sv0[16] = { "kk", "j", "nargin", "nargout", "yout",
    "ydelay", "structure", "yout_delay", "yin", "count1", "i"
    , "yin_d", "yin_all", "delay1", "delay", "num" };

  real_T c2_kk;
  real_T c2_j;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 1.0;
  real_T c2_yout_delay[4];
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  real_T c2_b_kk;
  int32_T c2_i33;
  static char_T c2_cv0[3] = { 'y', 'i', 'n' };

  char_T c2_u[3];
  const mxArray *c2_y = NULL;
  int32_T c2_i34;
  real_T c2_d_hoistedGlobal[4];
  int32_T c2_i35;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i36;
  int32_T c2_i37;
  static char_T c2_cv1[5] = { 'y', 'i', 'n', '_', 'd' };

  char_T c2_c_u[5];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i38;
  real_T c2_e_hoistedGlobal[4];
  int32_T c2_i39;
  real_T c2_d_u[4];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i40;
  char_T c2_e_u[3];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i41;
  real_T c2_f_hoistedGlobal[4];
  int32_T c2_i42;
  real_T c2_f_u[4];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i43;
  int32_T c2_i44;
  char_T c2_g_u[5];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i45;
  real_T c2_g_hoistedGlobal[4];
  int32_T c2_i46;
  real_T c2_h_u[4];
  const mxArray *c2_h_y = NULL;
  int32_T c2_i47;
  char_T c2_i_u[3];
  const mxArray *c2_i_y = NULL;
  int32_T c2_i48;
  real_T c2_h_hoistedGlobal[4];
  int32_T c2_i49;
  real_T c2_j_u[4];
  const mxArray *c2_j_y = NULL;
  int32_T c2_i50;
  int32_T c2_i51;
  char_T c2_k_u[5];
  const mxArray *c2_k_y = NULL;
  int32_T c2_i52;
  real_T c2_i_hoistedGlobal[4];
  int32_T c2_i53;
  real_T c2_l_u[4];
  const mxArray *c2_l_y = NULL;
  int32_T c2_i54;
  char_T c2_m_u[3];
  const mxArray *c2_m_y = NULL;
  int32_T c2_i55;
  real_T c2_j_hoistedGlobal[4];
  int32_T c2_i56;
  real_T c2_n_u[4];
  const mxArray *c2_n_y = NULL;
  int32_T c2_i57;
  int32_T c2_i58;
  char_T c2_o_u[5];
  const mxArray *c2_o_y = NULL;
  int32_T c2_i59;
  real_T c2_k_hoistedGlobal[4];
  int32_T c2_i60;
  real_T c2_p_u[4];
  const mxArray *c2_p_y = NULL;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  static char_T c2_cv2[5] = { 'd', 'e', 'l', 'a', 'y' };

  char_T c2_q_u[5];
  const mxArray *c2_q_y = NULL;
  int32_T c2_i64;
  real_T c2_l_hoistedGlobal[5];
  int32_T c2_i65;
  real_T c2_r_u[5];
  const mxArray *c2_r_y = NULL;
  int32_T c2_i66;
  int32_T c2_i67;
  static char_T c2_cv3[10] = { 'y', 'o', 'u', 't', '_', 'd', 'e', 'l', 'a', 'y'
  };

  char_T c2_s_u[10];
  const mxArray *c2_s_y = NULL;
  int32_T c2_i68;
  real_T c2_t_u[4];
  const mxArray *c2_t_y = NULL;
  char_T c2_u_u;
  const mxArray *c2_u_y = NULL;
  real_T c2_m_hoistedGlobal;
  real_T c2_v_u;
  const mxArray *c2_v_y = NULL;
  int32_T c2_i69;
  real_T (*c2_b_yout_delay)[4];
  real_T (*c2_b_ydelay)[5];
  real_T (*c2_b_yout)[4];
  c2_b_yout_delay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_ydelay = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_yout = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for (c2_i21 = 0; c2_i21 < 4; c2_i21 = c2_i21 + 1) {
    c2_hoistedGlobal[c2_i21] = (*c2_b_yout)[c2_i21];
  }

  for (c2_i22 = 0; c2_i22 < 5; c2_i22 = c2_i22 + 1) {
    c2_b_hoistedGlobal[c2_i22] = (*c2_b_ydelay)[c2_i22];
  }

  c2_c_hoistedGlobal = chartInstance->c2_structure;
  for (c2_i23 = 0; c2_i23 < 4; c2_i23 = c2_i23 + 1) {
    c2_yout[c2_i23] = c2_hoistedGlobal[c2_i23];
  }

  for (c2_i24 = 0; c2_i24 < 5; c2_i24 = c2_i24 + 1) {
    c2_ydelay[c2_i24] = c2_b_hoistedGlobal[c2_i24];
  }

  c2_b_structure = c2_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 16U, 16U, c2_sv0, c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_kk, c2_l_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_j, c2_l_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_l_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_l_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_yout, c2_i_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_ydelay, c2_k_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c2_b_structure, c2_j_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c2_yout_delay, c2_i_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_yin, c2_h_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_count1, c2_g_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_i, c2_f_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_yin_d, c2_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_yin_all, c2_d_sf_marshall,
    12U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_delay1, c2_c_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_delay, c2_b_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_num, c2_sf_marshall, 15U);
  CV_EML_FCN(0, 0);

  /*  Inputs:  */
  /*  yout: measurements output */
  /*  ydelay: delay traces */
  /*  structure: other necessary information  */
  /*  Inputs:  */
  /*  yout: measurements output */
  /*  ydelay: delay traces */
  /*  Outputs: */
  /*  yout_delay: delayed measurements output for controller */
  _SFD_EML_CALL(0,17);

  /*  initialize parameters */
  _SFD_EML_CALL(0,20);
  if (CV_EML_IF(0, 0, !chartInstance->c2_yin_not_empty)) {
    _SFD_EML_CALL(0,21);
    chartInstance->c2_count1 = c2_b_structure.count;
    chartInstance->c2_count1_not_empty = TRUE;
    _SFD_EML_CALL(0,22);
    chartInstance->c2_i = c2_b_structure.i;
    chartInstance->c2_i_not_empty = TRUE;
    _SFD_EML_CALL(0,23);
    for (c2_i25 = 0; c2_i25 < 4; c2_i25 = c2_i25 + 1) {
      chartInstance->c2_yin[c2_i25] = c2_b_structure.yin[c2_i25];
    }

    chartInstance->c2_yin_not_empty = TRUE;
    _SFD_EML_CALL(0,24);
    for (c2_i26 = 0; c2_i26 < 4; c2_i26 = c2_i26 + 1) {
      chartInstance->c2_yin_d[c2_i26] = c2_b_structure.yin_d[c2_i26];
    }

    chartInstance->c2_yin_d_not_empty = TRUE;
    _SFD_EML_CALL(0,25);
    for (c2_i27 = 0; c2_i27 < 40004; c2_i27 = c2_i27 + 1) {
      chartInstance->c2_yin_all[c2_i27] = 0.0;
    }

    chartInstance->c2_yin_all_not_empty = TRUE;

    /* zeros (step count, sensor number) */
    _SFD_EML_CALL(0,27);
    for (c2_i28 = 0; c2_i28 < 155; c2_i28 = c2_i28 + 1) {
      chartInstance->c2_delay1[c2_i28] = c2_b_structure.delay1[c2_i28];
    }

    chartInstance->c2_delay1_not_empty = TRUE;
    _SFD_EML_CALL(0,29);
    for (c2_i29 = 0; c2_i29 < 5; c2_i29 = c2_i29 + 1) {
      chartInstance->c2_delay[c2_i29] = 0.0;
    }

    chartInstance->c2_delay_not_empty = TRUE;
    _SFD_EML_CALL(0,30);
    for (c2_i30 = 0; c2_i30 < 5; c2_i30 = c2_i30 + 1) {
      chartInstance->c2_delay[c2_i30] = c2_ydelay[c2_i30];
    }

    _SFD_EML_CALL(0,32);
    chartInstance->c2_num = 0.0;
    chartInstance->c2_num_not_empty = TRUE;
  }

  /*  4-th order (Runge-kutta) method has intermidiate points, so update the delay traces and yin when rem(i,4)==0 */
  _SFD_EML_CALL(0,36);
  if (CV_EML_IF(0, 1, c2_rem(chartInstance, chartInstance->c2_i, 4.0) == 0.0)) {
    _SFD_EML_CALL(0,37);
    chartInstance->c2_num = chartInstance->c2_num + 1.0;
    _SFD_EML_CALL(0,38);
    c2_i31 = _SFD_EML_ARRAY_BOUNDS_CHECK("delay1", (int32_T)_SFD_INTEGER_CHECK(
      "num", chartInstance->c2_num), 1, 31, 1, 0) - 1;
    for (c2_i32 = 0; c2_i32 < 5; c2_i32 = c2_i32 + 1) {
      chartInstance->c2_delay1[c2_i31 + 31 * c2_i32] = c2_ydelay[c2_i32];
    }

    c2_kk = 1.0;
    c2_b_kk = 1.0;
    while (c2_b_kk <= 4.0) {
      c2_kk = c2_b_kk;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0,40);
      chartInstance->c2_yin_all[(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
        _SFD_INTEGER_CHECK("num", chartInstance->c2_num), 1,
        10001, 1, 0) - 1) + 10001 * (_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all",
        (int32_T)_SFD_INTEGER_CHECK("kk", c2_kk), 1, 4, 2, 0) - 1)] =
        c2_yout[_SFD_EML_ARRAY_BOUNDS_CHECK("yout", (int32_T)_SFD_INTEGER_CHECK(
        "kk", c2_kk), 1, 4, 1, 0) - 1];
      c2_b_kk = c2_b_kk + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 0, 0);
  }

  /*  disp('count1') */
  /*  disp(count1) */
  /*  delay = delay1(count,:); */
  /*  disp('delay1') */
  /*  disp(delay1) */
  _SFD_EML_CALL(0,50);
  if (CV_EML_IF(0, 2, c2_rem(chartInstance, chartInstance->c2_i, 40.0) == 16.0))
  {
    /*  check remains after dividing */
    _SFD_EML_CALL(0,51);
    c2_j = 1.0;
    _SFD_EML_CALL(0,52);
    if (CV_EML_IF(0, 3, chartInstance->c2_delay[1] != 88.0)) {
      _SFD_EML_CALL(0,53);
      chartInstance->c2_yin[0] = chartInstance->
        c2_yin_all[_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
        _SFD_INTEGER_CHECK("",
                           chartInstance->c2_num - 4.0), 1, 10001, 1, 0) - 1];
      _SFD_EML_CALL(0,54);
      for (c2_i33 = 0; c2_i33 < 3; c2_i33 = c2_i33 + 1) {
        c2_u[c2_i33] = c2_cv0[c2_i33];
      }

      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 3));
      sf_mex_call_debug("disp", 0U, 1U, 14, c2_y);
      _SFD_EML_CALL(0,55);
      for (c2_i34 = 0; c2_i34 < 4; c2_i34 = c2_i34 + 1) {
        c2_d_hoistedGlobal[c2_i34] = chartInstance->c2_yin[c2_i34];
      }

      for (c2_i35 = 0; c2_i35 < 4; c2_i35 = c2_i35 + 1) {
        c2_b_u[c2_i35] = c2_d_hoistedGlobal[c2_i35];
      }

      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 1, 4));
      sf_mex_call_debug("disp", 0U, 1U, 14, c2_b_y);
    }

    _SFD_EML_CALL(0,57);
    for (c2_i36 = 0; c2_i36 < 4; c2_i36 = c2_i36 + 1) {
      chartInstance->c2_yin_d[c2_i36] = chartInstance->c2_yin[c2_i36];
    }

    _SFD_EML_CALL(0,58);
    for (c2_i37 = 0; c2_i37 < 5; c2_i37 = c2_i37 + 1) {
      c2_c_u[c2_i37] = c2_cv1[c2_i37];
    }

    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 10, 0U, 1U, 0U, 2, 1, 5));
    sf_mex_call_debug("disp", 0U, 1U, 14, c2_c_y);
    _SFD_EML_CALL(0,59);
    for (c2_i38 = 0; c2_i38 < 4; c2_i38 = c2_i38 + 1) {
      c2_e_hoistedGlobal[c2_i38] = chartInstance->c2_yin_d[c2_i38];
    }

    for (c2_i39 = 0; c2_i39 < 4; c2_i39 = c2_i39 + 1) {
      c2_d_u[c2_i39] = c2_e_hoistedGlobal[c2_i39];
    }

    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 1U, 0U, 1, 4));
    sf_mex_call_debug("disp", 0U, 1U, 14, c2_d_y);
  }

  _SFD_EML_CALL(0,62);
  if (CV_EML_IF(0, 4, c2_rem(chartInstance, chartInstance->c2_i, 40.0) == 24.0))
  {
    /*  check remains after dividing */
    _SFD_EML_CALL(0,63);
    c2_j = 2.0;
    _SFD_EML_CALL(0,64);
    if (CV_EML_IF(0, 5, chartInstance->c2_delay[2] != 88.0)) {
      _SFD_EML_CALL(0,65);
      chartInstance->c2_yin[1] = chartInstance->
        c2_yin_all[_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
        _SFD_INTEGER_CHECK("",
                           chartInstance->c2_num - 2.0), 1, 10001, 1, 0) + 10000];
      _SFD_EML_CALL(0,66);
      for (c2_i40 = 0; c2_i40 < 3; c2_i40 = c2_i40 + 1) {
        c2_e_u[c2_i40] = c2_cv0[c2_i40];
      }

      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 10, 0U, 1U, 0U, 2, 1, 3));
      sf_mex_call_debug("disp", 0U, 1U, 14, c2_e_y);
      _SFD_EML_CALL(0,67);
      for (c2_i41 = 0; c2_i41 < 4; c2_i41 = c2_i41 + 1) {
        c2_f_hoistedGlobal[c2_i41] = chartInstance->c2_yin[c2_i41];
      }

      for (c2_i42 = 0; c2_i42 < 4; c2_i42 = c2_i42 + 1) {
        c2_f_u[c2_i42] = c2_f_hoistedGlobal[c2_i42];
      }

      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 1U, 0U, 2, 1, 4));
      sf_mex_call_debug("disp", 0U, 1U, 14, c2_f_y);
    }

    _SFD_EML_CALL(0,69);
    for (c2_i43 = 0; c2_i43 < 4; c2_i43 = c2_i43 + 1) {
      chartInstance->c2_yin_d[c2_i43] = chartInstance->c2_yin[c2_i43];
    }

    _SFD_EML_CALL(0,70);
    for (c2_i44 = 0; c2_i44 < 5; c2_i44 = c2_i44 + 1) {
      c2_g_u[c2_i44] = c2_cv1[c2_i44];
    }

    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 10, 0U, 1U, 0U, 2, 1, 5));
    sf_mex_call_debug("disp", 0U, 1U, 14, c2_g_y);
    _SFD_EML_CALL(0,71);
    for (c2_i45 = 0; c2_i45 < 4; c2_i45 = c2_i45 + 1) {
      c2_g_hoistedGlobal[c2_i45] = chartInstance->c2_yin_d[c2_i45];
    }

    for (c2_i46 = 0; c2_i46 < 4; c2_i46 = c2_i46 + 1) {
      c2_h_u[c2_i46] = c2_g_hoistedGlobal[c2_i46];
    }

    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 1U, 0U, 1, 4));
    sf_mex_call_debug("disp", 0U, 1U, 14, c2_h_y);
  }

  _SFD_EML_CALL(0,74);
  if (CV_EML_IF(0, 6, c2_rem(chartInstance, chartInstance->c2_i, 40.0) == 32.0))
  {
    /*  check remains after dividing */
    _SFD_EML_CALL(0,75);
    c2_j = 3.0;
    _SFD_EML_CALL(0,76);
    if (CV_EML_IF(0, 7, chartInstance->c2_delay[3] != 88.0)) {
      _SFD_EML_CALL(0,77);
      chartInstance->c2_yin[2] = chartInstance->
        c2_yin_all[_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
        _SFD_INTEGER_CHECK("",
                           chartInstance->c2_num - 2.0), 1, 10001, 1, 0) + 20001];
      _SFD_EML_CALL(0,78);
      for (c2_i47 = 0; c2_i47 < 3; c2_i47 = c2_i47 + 1) {
        c2_i_u[c2_i47] = c2_cv0[c2_i47];
      }

      c2_i_y = NULL;
      sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 10, 0U, 1U, 0U, 2, 1, 3));
      sf_mex_call_debug("disp", 0U, 1U, 14, c2_i_y);
      _SFD_EML_CALL(0,79);
      for (c2_i48 = 0; c2_i48 < 4; c2_i48 = c2_i48 + 1) {
        c2_h_hoistedGlobal[c2_i48] = chartInstance->c2_yin[c2_i48];
      }

      for (c2_i49 = 0; c2_i49 < 4; c2_i49 = c2_i49 + 1) {
        c2_j_u[c2_i49] = c2_h_hoistedGlobal[c2_i49];
      }

      c2_j_y = NULL;
      sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 0, 0U, 1U, 0U, 2, 1, 4));
      sf_mex_call_debug("disp", 0U, 1U, 14, c2_j_y);
    }

    _SFD_EML_CALL(0,81);
    for (c2_i50 = 0; c2_i50 < 4; c2_i50 = c2_i50 + 1) {
      chartInstance->c2_yin_d[c2_i50] = chartInstance->c2_yin[c2_i50];
    }

    _SFD_EML_CALL(0,82);
    for (c2_i51 = 0; c2_i51 < 5; c2_i51 = c2_i51 + 1) {
      c2_k_u[c2_i51] = c2_cv1[c2_i51];
    }

    c2_k_y = NULL;
    sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_k_u, 10, 0U, 1U, 0U, 2, 1, 5));
    sf_mex_call_debug("disp", 0U, 1U, 14, c2_k_y);
    _SFD_EML_CALL(0,83);
    for (c2_i52 = 0; c2_i52 < 4; c2_i52 = c2_i52 + 1) {
      c2_i_hoistedGlobal[c2_i52] = chartInstance->c2_yin_d[c2_i52];
    }

    for (c2_i53 = 0; c2_i53 < 4; c2_i53 = c2_i53 + 1) {
      c2_l_u[c2_i53] = c2_i_hoistedGlobal[c2_i53];
    }

    c2_l_y = NULL;
    sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_l_u, 0, 0U, 1U, 0U, 1, 4));
    sf_mex_call_debug("disp", 0U, 1U, 14, c2_l_y);
  }

  _SFD_EML_CALL(0,86);
  if (CV_EML_COND(0, 0, c2_rem(chartInstance, chartInstance->c2_i, 40.0) == 0.0))
  {
    if (CV_EML_COND(0, 1, chartInstance->c2_i != 0.0)) {
      CV_EML_MCDC(0, 0, TRUE);
      CV_EML_IF(0, 8, TRUE);

      /*  check remains after dividing */
      _SFD_EML_CALL(0,87);
      c2_j = 4.0;
      _SFD_EML_CALL(0,88);
      if (CV_EML_IF(0, 9, chartInstance->c2_delay[4] != 88.0)) {
        _SFD_EML_CALL(0,89);
        chartInstance->c2_yin[3] = chartInstance->
          c2_yin_all[_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
          _SFD_INTEGER_CHECK("",
                             chartInstance->c2_num - 2.0), 1, 10001, 1, 0) +
          30002];
        _SFD_EML_CALL(0,90);
        for (c2_i54 = 0; c2_i54 < 3; c2_i54 = c2_i54 + 1) {
          c2_m_u[c2_i54] = c2_cv0[c2_i54];
        }

        c2_m_y = NULL;
        sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_m_u, 10, 0U, 1U, 0U, 2, 1,
          3));
        sf_mex_call_debug("disp", 0U, 1U, 14, c2_m_y);
        _SFD_EML_CALL(0,91);
        for (c2_i55 = 0; c2_i55 < 4; c2_i55 = c2_i55 + 1) {
          c2_j_hoistedGlobal[c2_i55] = chartInstance->c2_yin[c2_i55];
        }

        for (c2_i56 = 0; c2_i56 < 4; c2_i56 = c2_i56 + 1) {
          c2_n_u[c2_i56] = c2_j_hoistedGlobal[c2_i56];
        }

        c2_n_y = NULL;
        sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_n_u, 0, 0U, 1U, 0U, 2, 1,
          4));
        sf_mex_call_debug("disp", 0U, 1U, 14, c2_n_y);
      }

      _SFD_EML_CALL(0,93);
      for (c2_i57 = 0; c2_i57 < 4; c2_i57 = c2_i57 + 1) {
        chartInstance->c2_yin_d[c2_i57] = chartInstance->c2_yin[c2_i57];
      }

      _SFD_EML_CALL(0,94);
      for (c2_i58 = 0; c2_i58 < 5; c2_i58 = c2_i58 + 1) {
        c2_o_u[c2_i58] = c2_cv1[c2_i58];
      }

      c2_o_y = NULL;
      sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_o_u, 10, 0U, 1U, 0U, 2, 1, 5));
      sf_mex_call_debug("disp", 0U, 1U, 14, c2_o_y);
      _SFD_EML_CALL(0,95);
      for (c2_i59 = 0; c2_i59 < 4; c2_i59 = c2_i59 + 1) {
        c2_k_hoistedGlobal[c2_i59] = chartInstance->c2_yin_d[c2_i59];
      }

      for (c2_i60 = 0; c2_i60 < 4; c2_i60 = c2_i60 + 1) {
        c2_p_u[c2_i60] = c2_k_hoistedGlobal[c2_i60];
      }

      c2_p_y = NULL;
      sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_p_u, 0, 0U, 1U, 0U, 1, 4));
      sf_mex_call_debug("disp", 0U, 1U, 14, c2_p_y);
      _SFD_EML_CALL(0,96);
      chartInstance->c2_count1 = chartInstance->c2_count1 + 1.0;
      goto label_1;
    }
  }

  CV_EML_MCDC(0, 0, FALSE);
  CV_EML_IF(0, 8, FALSE);
 label_1:
  ;
  _SFD_EML_CALL(0,99);
  if (CV_EML_IF(0, 10, c2_rem(chartInstance, chartInstance->c2_num, 10.0) == 1.0))
  {
    _SFD_EML_CALL(0,100);
    c2_i61 = _SFD_EML_ARRAY_BOUNDS_CHECK("delay1", (int32_T)_SFD_INTEGER_CHECK(
      "num", chartInstance->c2_num), 1, 31, 1, 0) - 1;
    for (c2_i62 = 0; c2_i62 < 5; c2_i62 = c2_i62 + 1) {
      chartInstance->c2_delay[c2_i62] = chartInstance->c2_delay1[c2_i61 + 31 *
        c2_i62];
    }
  }

  _SFD_EML_CALL(0,103);
  for (c2_i63 = 0; c2_i63 < 5; c2_i63 = c2_i63 + 1) {
    c2_q_u[c2_i63] = c2_cv2[c2_i63];
  }

  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_q_u, 10, 0U, 1U, 0U, 2, 1, 5));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_q_y);
  _SFD_EML_CALL(0,104);
  for (c2_i64 = 0; c2_i64 < 5; c2_i64 = c2_i64 + 1) {
    c2_l_hoistedGlobal[c2_i64] = chartInstance->c2_delay[c2_i64];
  }

  for (c2_i65 = 0; c2_i65 < 5; c2_i65 = c2_i65 + 1) {
    c2_r_u[c2_i65] = c2_l_hoistedGlobal[c2_i65];
  }

  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_r_u, 0, 0U, 1U, 0U, 2, 1, 5));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_r_y);
  _SFD_EML_CALL(0,106);
  for (c2_i66 = 0; c2_i66 < 4; c2_i66 = c2_i66 + 1) {
    c2_yout_delay[c2_i66] = chartInstance->c2_yin_d[c2_i66];
  }

  _SFD_EML_CALL(0,107);
  for (c2_i67 = 0; c2_i67 < 10; c2_i67 = c2_i67 + 1) {
    c2_s_u[c2_i67] = c2_cv3[c2_i67];
  }

  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_s_u, 10, 0U, 1U, 0U, 2, 1, 10));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_s_y);
  _SFD_EML_CALL(0,108);
  for (c2_i68 = 0; c2_i68 < 4; c2_i68 = c2_i68 + 1) {
    c2_t_u[c2_i68] = c2_yout_delay[c2_i68];
  }

  c2_t_y = NULL;
  sf_mex_assign(&c2_t_y, sf_mex_create("y", &c2_t_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_t_y);
  _SFD_EML_CALL(0,110);
  chartInstance->c2_i = chartInstance->c2_i + 1.0;
  _SFD_EML_CALL(0,111);
  c2_u_u = 'i';
  c2_u_y = NULL;
  sf_mex_assign(&c2_u_y, sf_mex_create("y", &c2_u_u, 10, 0U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_u_y);
  _SFD_EML_CALL(0,112);
  c2_m_hoistedGlobal = chartInstance->c2_i;
  c2_v_u = c2_m_hoistedGlobal;
  c2_v_y = NULL;
  sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_v_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_v_y);

  /*  disp('Yout') */
  /*  disp( yout) */
  _SFD_EML_CALL(0,-112);
  sf_debug_symbol_scope_pop();
  for (c2_i69 = 0; c2_i69 < 4; c2_i69 = c2_i69 + 1) {
    (*c2_b_yout_delay)[c2_i69] = c2_yout_delay[c2_i69];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static real_T c2_rem(SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct
                     *chartInstance, real_T c2_x, real_T c2_y)
{
  real_T c2_xk;
  real_T c2_yk;
  real_T c2_b_x;
  real_T c2_b_y;
  c2_xk = c2_x;
  c2_yk = c2_y;
  c2_b_x = c2_xk;
  c2_b_y = c2_yk;
  return muDoubleScalarRem(c2_b_x, c2_b_y);
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  if (!chartInstance->c2_num_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i70;
  real_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i70 = 0; c2_i70 < 5; c2_i70 = c2_i70 + 1) {
    c2_b_u[c2_i70] = (*((real_T (*)[5])c2_u))[c2_i70];
  }

  c2_b_y = NULL;
  if (!chartInstance->c2_delay_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 1, 5));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  real_T c2_b_u[155];
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_i71 = 0;
  for (c2_i72 = 0; c2_i72 < 5; c2_i72 = c2_i72 + 1) {
    for (c2_i73 = 0; c2_i73 < 31; c2_i73 = c2_i73 + 1) {
      c2_b_u[c2_i73 + c2_i71] = (*((real_T (*)[155])c2_u))[c2_i73 + c2_i71];
    }

    c2_i71 = c2_i71 + 31;
  }

  c2_b_y = NULL;
  if (!chartInstance->c2_delay1_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 31, 5));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  static real_T c2_b_u[40004];
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_i74 = 0;
  for (c2_i75 = 0; c2_i75 < 4; c2_i75 = c2_i75 + 1) {
    for (c2_i76 = 0; c2_i76 < 10001; c2_i76 = c2_i76 + 1) {
      c2_b_u[c2_i76 + c2_i74] = (*((real_T (*)[40004])c2_u))[c2_i76 + c2_i74];
    }

    c2_i74 = c2_i74 + 10001;
  }

  c2_b_y = NULL;
  if (!chartInstance->c2_yin_all_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 10001,
      4));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_e_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i77;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i77 = 0; c2_i77 < 4; c2_i77 = c2_i77 + 1) {
    c2_b_u[c2_i77] = (*((real_T (*)[4])c2_u))[c2_i77];
  }

  c2_b_y = NULL;
  if (!chartInstance->c2_yin_d_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 4));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_f_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  if (!chartInstance->c2_i_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_g_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  if (!chartInstance->c2_count1_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_h_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i78;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i78 = 0; c2_i78 < 4; c2_i78 = c2_i78 + 1) {
    c2_b_u[c2_i78] = (*((real_T (*)[4])c2_u))[c2_i78];
  }

  c2_b_y = NULL;
  if (!chartInstance->c2_yin_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 1, 4));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_i_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i79;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i79 = 0; c2_i79 < 4; c2_i79 = c2_i79 + 1) {
    c2_b_u[c2_i79] = (*((real_T (*)[4])c2_u))[c2_i79];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_j_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  c2_struct_v0tR0vTRrhhWAY2OuGMwxB c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i80;
  real_T c2_e_u[4];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i81;
  real_T c2_f_u[4];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i82;
  real_T c2_g_u[155];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i83;
  real_T c2_h_u[4];
  const mxArray *c2_h_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((c2_struct_v0tR0vTRrhhWAY2OuGMwxB *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1));
  c2_c_u = c2_b_u.i;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_b_y, c2_c_y, "i", "i", 0);
  c2_d_u = c2_b_u.count;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_b_y, c2_d_y, "count", "count", 0);
  for (c2_i80 = 0; c2_i80 < 4; c2_i80 = c2_i80 + 1) {
    c2_e_u[c2_i80] = c2_b_u.yin[c2_i80];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_addfield(c2_b_y, c2_e_y, "yin", "yin", 0);
  for (c2_i81 = 0; c2_i81 < 4; c2_i81 = c2_i81 + 1) {
    c2_f_u[c2_i81] = c2_b_u.yin_d[c2_i81];
  }

  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 1U, 0U, 2, 4, 1));
  sf_mex_addfield(c2_b_y, c2_f_y, "yin_d", "yin_d", 0);
  for (c2_i82 = 0; c2_i82 < 155; c2_i82 = c2_i82 + 1) {
    c2_g_u[c2_i82] = c2_b_u.delay1[c2_i82];
  }

  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 1U, 0U, 2, 31, 5));
  sf_mex_addfield(c2_b_y, c2_g_y, "delay1", "delay1", 0);
  for (c2_i83 = 0; c2_i83 < 4; c2_i83 = c2_i83 + 1) {
    c2_h_u[c2_i83] = c2_b_u.ranD[c2_i83];
  }

  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_addfield(c2_b_y, c2_h_y, "ranD", "ranD", 0);
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_k_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i84;
  real_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i84 = 0; c2_i84 < 5; c2_i84 = c2_i84 + 1) {
    c2_b_u[c2_i84] = (*((real_T (*)[5])c2_u))[c2_i84];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 5));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_l_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray
  *sf_c2_SIMUL_step_delay_Embed_integrated_v2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[20];
  const mxArray *c2_m1 = NULL;
  int32_T c2_i85;
  c2_ResolvedFunctionInfo *c2_r1;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m1, sf_mex_createstruct("nameCaptureInfo", 1, 20));
  for (c2_i85 = 0; c2_i85 < 20; c2_i85 = c2_i85 + 1) {
    c2_r1 = &c2_info[c2_i85];
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", c2_r1->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r1->context)), "context",
                    "nameCaptureInfo", c2_i85);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", c2_r1->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r1->name)), "name",
                    "nameCaptureInfo", c2_i85);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", c2_r1->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r1->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i85);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", c2_r1->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r1->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i85);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", &c2_r1->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i85);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", &c2_r1->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i85
                    );
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", &c2_r1->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i85
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m1);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[20])
{
  c2_info[0].context = "";
  c2_info[0].name = "zeros";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]zeros";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "ctranspose";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[B]ctranspose";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "rem";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[2].fileLength = 961U;
  c2_info[2].fileTime1 = 1244760750U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[3].name = "nargin";
  c2_info[3].dominantType = "";
  c2_info[3].resolved = "[B]nargin";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[4].name = "gt";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]gt";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[5].name = "isreal";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]isreal";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[6].name = "isa";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]isa";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[7].name = "class";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]class";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[8].name = "eml_scalar_eg";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[8].fileLength = 3068U;
  c2_info[8].fileTime1 = 1240287210U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c2_info[9].name = "false";
  c2_info[9].dominantType = "";
  c2_info[9].resolved = "[B]false";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[10].name = "isstruct";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]isstruct";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[11].name = "eq";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]eq";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[12].name = "cast";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[B]cast";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[13].name = "plus";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]plus";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[14].name = "eml_scalexp_alloc";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[14].fileLength = 808U;
  c2_info[14].fileTime1 = 1230519898U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[15].name = "minus";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]minus";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[16].name = "isscalar";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]isscalar";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[17].name = "not";
  c2_info[17].dominantType = "logical";
  c2_info[17].resolved = "[B]not";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[18].name = "eml_scalar_rem";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  c2_info[18].fileLength = 1167U;
  c2_info[18].fileTime1 = 1236282454U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "";
  c2_info[19].name = "ne";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved = "[B]ne";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
}

static const mxArray *c2_m_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_n_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i86;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i86 = 0; c2_i86 < 4; c2_i86 = c2_i86 + 1) {
    c2_b_u[c2_i86] = (*((real_T (*)[4])c2_u))[c2_i86];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static void c2_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_yout_delay
   , const char_T *c2_name, real_T c2_y[4])
{
  real_T c2_dv6[4];
  int32_T c2_i87;
  sf_mex_import(c2_name, sf_mex_dup(c2_yout_delay), &c2_dv6, 1, 0, 0U, 1, 0U, 1,
                4);
  for (c2_i87 = 0; c2_i87 < 4; c2_i87 = c2_i87 + 1) {
    c2_y[c2_i87] = c2_dv6[c2_i87];
  }

  sf_mex_destroy(&c2_yout_delay);
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *
   c2_b_count1, const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d0;
  if (mxIsEmpty(c2_b_count1)) {
    chartInstance->c2_count1_not_empty = FALSE;
  } else {
    chartInstance->c2_count1_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_count1), &c2_d0, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d0;
  }

  sf_mex_destroy(&c2_b_count1);
  return c2_y;
}

static void c2_c_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_delay
   , const char_T *c2_name, real_T c2_y[5])
{
  real_T c2_dv7[5];
  int32_T c2_i88;
  if (mxIsEmpty(c2_b_delay)) {
    chartInstance->c2_delay_not_empty = FALSE;
  } else {
    chartInstance->c2_delay_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_delay), &c2_dv7, 1, 0, 0U, 1, 0U, 2,
                  1, 5);
    for (c2_i88 = 0; c2_i88 < 5; c2_i88 = c2_i88 + 1) {
      c2_y[c2_i88] = c2_dv7[c2_i88];
    }
  }

  sf_mex_destroy(&c2_b_delay);
}

static void c2_d_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_delay1
   , const char_T *c2_name, real_T c2_y[155])
{
  real_T c2_dv8[155];
  int32_T c2_i89;
  if (mxIsEmpty(c2_b_delay1)) {
    chartInstance->c2_delay1_not_empty = FALSE;
  } else {
    chartInstance->c2_delay1_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_delay1), &c2_dv8, 1, 0, 0U, 1, 0U, 2,
                  31, 5);
    for (c2_i89 = 0; c2_i89 < 155; c2_i89 = c2_i89 + 1) {
      c2_y[c2_i89] = c2_dv8[c2_i89];
    }
  }

  sf_mex_destroy(&c2_b_delay1);
}

static real_T c2_e_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_i,
   const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d1;
  if (mxIsEmpty(c2_b_i)) {
    chartInstance->c2_i_not_empty = FALSE;
  } else {
    chartInstance->c2_i_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_i), &c2_d1, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d1;
  }

  sf_mex_destroy(&c2_b_i);
  return c2_y;
}

static real_T c2_f_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_num
   , const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d2;
  if (mxIsEmpty(c2_b_num)) {
    chartInstance->c2_num_not_empty = FALSE;
  } else {
    chartInstance->c2_num_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_num), &c2_d2, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d2;
  }

  sf_mex_destroy(&c2_b_num);
  return c2_y;
}

static void c2_g_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_yin,
   const char_T *c2_name, real_T c2_y[4])
{
  real_T c2_dv9[4];
  int32_T c2_i90;
  if (mxIsEmpty(c2_b_yin)) {
    chartInstance->c2_yin_not_empty = FALSE;
  } else {
    chartInstance->c2_yin_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_yin), &c2_dv9, 1, 0, 0U, 1, 0U, 2, 1,
                  4);
    for (c2_i90 = 0; c2_i90 < 4; c2_i90 = c2_i90 + 1) {
      c2_y[c2_i90] = c2_dv9[c2_i90];
    }
  }

  sf_mex_destroy(&c2_b_yin);
}

static void c2_h_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *
   c2_b_yin_all, const char_T *c2_name, real_T c2_y[40004])
{
  static real_T c2_dv10[40004];
  int32_T c2_i91;
  if (mxIsEmpty(c2_b_yin_all)) {
    chartInstance->c2_yin_all_not_empty = FALSE;
  } else {
    chartInstance->c2_yin_all_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_yin_all), &c2_dv10, 1, 0, 0U, 1, 0U,
                  2, 10001, 4);
    for (c2_i91 = 0; c2_i91 < 40004; c2_i91 = c2_i91 + 1) {
      c2_y[c2_i91] = c2_dv10[c2_i91];
    }
  }

  sf_mex_destroy(&c2_b_yin_all);
}

static void c2_i_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_yin_d
   , const char_T *c2_name, real_T c2_y[4])
{
  real_T c2_dv11[4];
  int32_T c2_i92;
  if (mxIsEmpty(c2_b_yin_d)) {
    chartInstance->c2_yin_d_not_empty = FALSE;
  } else {
    chartInstance->c2_yin_d_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_yin_d), &c2_dv11, 1, 0, 0U, 1, 0U, 1,
                  4);
    for (c2_i92 = 0; c2_i92 < 4; c2_i92 = c2_i92 + 1) {
      c2_y[c2_i92] = c2_dv11[c2_i92];
    }
  }

  sf_mex_destroy(&c2_b_yin_d);
}

static uint8_T c2_j_emlrt_marshallIn
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance, const
   mxArray *
   c2_b_is_active_c2_SIMUL_step_delay_Embed_integrated_v2, const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup
                (c2_b_is_active_c2_SIMUL_step_delay_Embed_integrated_v2), &c2_u0,
                1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_SIMUL_step_delay_Embed_integrated_v2);
  return c2_y;
}

static void init_dsm_address_info
  (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_SIMUL_step_delay_Embed_integrated_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(958539972U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1592693587U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1386692091U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3555646962U);
}

mxArray *sf_c2_SIMUL_step_delay_Embed_integrated_v2_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3669714337U);
    pr[1] = (double)(3351732391U);
    pr[2] = (double)(1343403239U);
    pr[3] = (double)(964307501U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_SIMUL_step_delay_Embed_integrated_v2
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[5],T\"yout_delay\",},{M[4],M[0],T\"count1\",S'l','i','p'{{M1x2[338 344],M[0],}}},{M[4],M[0],T\"delay\",S'l','i','p'{{M1x2[345 350],M[0],}}},{M[4],M[0],T\"delay1\",S'l','i','p'{{M1x2[308 314],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[315 316],M[0],}}},{M[4],M[0],T\"num\",S'l','i','p'{{M1x2[359 362],M[0],}}},{M[4],M[0],T\"yin\",S'l','i','p'{{M1x2[334 337],M[0],}}},{M[4],M[0],T\"yin_all\",S'l','i','p'{{M1x2[351 358],M[0],}}},{M[4],M[0],T\"yin_d\",S'l','i','p'{{M1x2[317 322],M[0],}}},{M[8],M[0],T\"is_active_c2_SIMUL_step_delay_Embed_integrated_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 10, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_SIMUL_step_delay_Embed_integrated_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
    chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SIMUL_step_delay_Embed_integrated_v2MachineNumber_,
           2,
           1,
           1,
           4,
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
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"yout",0,(MexFcnForType)c2_n_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 5;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ydelay",0,(MexFcnForType)c2_k_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"yout_delay",0,(MexFcnForType)
                                c2_i_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(3,10,0,0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,
                              "structure",0,(MexFcnForType)c2_j_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,11,0,0,1,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2141);
        _SFD_CV_INIT_EML_IF(0,0,412,427,-1,706);
        _SFD_CV_INIT_EML_IF(0,1,819,833,-1,944);
        _SFD_CV_INIT_EML_IF(0,2,1038,1054,-1,1255);
        _SFD_CV_INIT_EML_IF(0,3,1099,1118,-1,1199);
        _SFD_CV_INIT_EML_IF(0,4,1257,1273,-1,1474);
        _SFD_CV_INIT_EML_IF(0,5,1318,1337,-1,1418);
        _SFD_CV_INIT_EML_IF(0,6,1476,1492,-1,1693);
        _SFD_CV_INIT_EML_IF(0,7,1537,1556,-1,1637);
        _SFD_CV_INIT_EML_IF(0,8,1695,1720,-1,1944);
        _SFD_CV_INIT_EML_IF(0,9,1765,1784,-1,1865);
        _SFD_CV_INIT_EML_IF(0,10,1946,1963,-1,1994);
        _SFD_CV_INIT_EML_FOR(0,0,884,897,940);

        {
          static int condStart[] = { 1699, 1715 };

          static int condEnd[] = { 1711, 1719 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,1699,1719,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
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
          real_T (*c2_yout)[4];
          real_T (*c2_ydelay)[5];
          real_T (*c2_yout_delay)[4];
          c2_yout_delay = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S,
            1);
          c2_ydelay = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 1);
          c2_yout = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_yout);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_ydelay);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_yout_delay);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_structure);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SIMUL_step_delay_Embed_integrated_v2MachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c2_SIMUL_step_delay_Embed_integrated_v2
    ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
  initialize_c2_SIMUL_step_delay_Embed_integrated_v2
    ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  enable_c2_SIMUL_step_delay_Embed_integrated_v2
    ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  disable_c2_SIMUL_step_delay_Embed_integrated_v2
    ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  sf_c2_SIMUL_step_delay_Embed_integrated_v2
    ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*) chartInstanceVar);
}

static mxArray*
  sf_internal_get_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2
    ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_SIMUL_step_delay_Embed_integrated_v2();/* state var info */
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

static void sf_internal_set_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2
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
    sf_get_sim_state_info_c2_SIMUL_step_delay_Embed_integrated_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2
    ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2(S);
}

static void sf_opaque_set_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2(S, st);
}

static void sf_opaque_terminate_c2_SIMUL_step_delay_Embed_integrated_v2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_SIMUL_step_delay_Embed_integrated_v2
      ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_SIMUL_step_delay_Embed_integrated_v2
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_SIMUL_step_delay_Embed_integrated_v2
      ((SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_SIMUL_step_delay_Embed_integrated_v2(SimStruct
  *S)
{
  /* Actual parameters from chart:
     structure
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("SIMUL_step_delay_Embed_integrated_v2",
      "SIMUL_step_delay_Embed_integrated_v2",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("SIMUL_step_delay_Embed_integrated_v2",
                "SIMUL_step_delay_Embed_integrated_v2",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "SIMUL_step_delay_Embed_integrated_v2",
      "SIMUL_step_delay_Embed_integrated_v2",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "SIMUL_step_delay_Embed_integrated_v2",
        "SIMUL_step_delay_Embed_integrated_v2",2,2);
      sf_mark_chart_reusable_outputs(S,"SIMUL_step_delay_Embed_integrated_v2",
        "SIMUL_step_delay_Embed_integrated_v2",2,1);
    }

    sf_set_rtw_dwork_info(S,"SIMUL_step_delay_Embed_integrated_v2",
                          "SIMUL_step_delay_Embed_integrated_v2",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(23486032U));
  ssSetChecksum1(S,(431455373U));
  ssSetChecksum2(S,(1740465573U));
  ssSetChecksum3(S,(1183210370U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_SIMUL_step_delay_Embed_integrated_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SIMUL_step_delay_Embed_integrated_v2",
      "SIMUL_step_delay_Embed_integrated_v2",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_SIMUL_step_delay_Embed_integrated_v2(SimStruct *S)
{
  SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct *)
    malloc(sizeof(SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_SIMUL_step_delay_Embed_integrated_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c2_SIMUL_step_delay_Embed_integrated_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_SIMUL_step_delay_Embed_integrated_v2;
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

void c2_SIMUL_step_delay_Embed_integrated_v2_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_SIMUL_step_delay_Embed_integrated_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_SIMUL_step_delay_Embed_integrated_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_SIMUL_step_delay_Embed_integrated_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_SIMUL_step_delay_Embed_integrated_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
