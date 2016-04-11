/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CoupledTanks_sfun.h"
#include "c3_CoupledTanks.h"
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
static const char * c3_debug_family_names[16] = { "sennum", "step_count", "kk",
  "j", "nargin", "nargout", "yout", "ydelay", "structure", "yout_delay", "i",
  "yin_d", "yin", "delay", "yin_all", "num" };

/* Function Declarations */
static void initialize_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance);
static void initialize_params_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance);
static void enable_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance);
static void disable_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_CoupledTanks
  (SFc3_CoupledTanksInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_CoupledTanks
  (SFc3_CoupledTanksInstanceStruct *chartInstance);
static void set_sim_state_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance);
static void sf_gateway_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance);
static void initSimStructsc3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_b_num, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_b_yin_all, const char_T *c3_identifier, real_T c3_y[2400003]);
static void c3_d_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y
  [2400003]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T c3_inData_sizes[2]);
static void c3_e_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_delay, const char_T *c3_identifier, real_T c3_y_data[],
  int32_T c3_y_sizes[2]);
static void c3_f_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y_data[],
  int32_T c3_y_sizes[2]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  c3_outData_sizes[2]);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_b_yin, const char_T *c3_identifier, real_T c3_y[3]);
static void c3_h_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_i_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_b_yin_d, const char_T *c3_identifier, real_T c3_y[3]);
static void c3_j_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_k_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_b_i, const char_T *c3_identifier);
static real_T c3_l_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_m_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_yout_delay, const char_T *c3_identifier, real_T c3_y[3]);
static void c3_n_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_o_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  c3_struct_jgcRFG32RbuET2w4s7dLLB *c3_y);
static real_T c3_p_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_q_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_r_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_s_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[804]);
static void c3_t_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[5]);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_u_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_v_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_CoupledTanks, const char_T
  *c3_identifier);
static uint8_T c3_w_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_CoupledTanksInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_i_not_empty = false;
  chartInstance->c3_yin_d_not_empty = false;
  chartInstance->c3_yin_not_empty = false;
  chartInstance->c3_delay_not_empty = false;
  chartInstance->c3_yin_all_not_empty = false;
  chartInstance->c3_num_not_empty = false;
  chartInstance->c3_is_active_c3_CoupledTanks = 0U;
}

static void initialize_params_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance)
{
  const mxArray *c3_m0 = NULL;
  const mxArray *c3_mxField;
  c3_struct_jgcRFG32RbuET2w4s7dLLB c3_r0;
  c3_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c3_mxField = sf_mex_getfield(c3_m0, "i", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c3_mxField), &c3_r0.i, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "count", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c3_mxField), &c3_r0.count, 1, 0,
                      0U, 0, 0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "yin", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c3_mxField), c3_r0.yin, 1, 0, 0U,
                      1, 0U, 2, 1, 3);
  c3_mxField = sf_mex_getfield(c3_m0, "yin_d", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c3_mxField), c3_r0.yin_d, 1, 0, 0U,
                      1, 0U, 2, 3, 1);
  c3_mxField = sf_mex_getfield(c3_m0, "delay1", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c3_mxField), c3_r0.delay1, 1, 0,
                      0U, 1, 0U, 2, 201, 4);
  c3_mxField = sf_mex_getfield(c3_m0, "ranD", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c3_mxField), c3_r0.ranD, 1, 0, 0U,
                      1, 0U, 2, 1, 5);
  sf_mex_destroy(&c3_m0);
  chartInstance->c3_structure = c3_r0;
}

static void enable_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_CoupledTanks
  (SFc3_CoupledTanksInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_CoupledTanks
  (SFc3_CoupledTanksInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[3];
  const mxArray *c3_b_y = NULL;
  int32_T c3_u_sizes[2];
  int32_T c3_b_u;
  int32_T c3_c_u;
  int32_T c3_loop_ub;
  int32_T c3_i1;
  real_T c3_u_data[11];
  const mxArray *c3_c_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_e_y = NULL;
  int32_T c3_i2;
  real_T c3_f_u[3];
  const mxArray *c3_f_y = NULL;
  int32_T c3_i3;
  static real_T c3_g_u[2400003];
  const mxArray *c3_g_y = NULL;
  int32_T c3_i4;
  real_T c3_h_u[3];
  const mxArray *c3_h_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_i_u;
  const mxArray *c3_i_y = NULL;
  real_T (*c3_yout_delay)[3];
  c3_yout_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(8, 1), false);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0++) {
    c3_u[c3_i0] = (*c3_yout_delay)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_u_sizes[0] = 1;
  c3_u_sizes[1] = chartInstance->c3_delay_sizes[1];
  c3_b_u = c3_u_sizes[0];
  c3_c_u = c3_u_sizes[1];
  c3_loop_ub = chartInstance->c3_delay_sizes[0] * chartInstance->c3_delay_sizes
    [1] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    c3_u_data[c3_i1] = chartInstance->c3_delay_data[c3_i1];
  }

  c3_c_y = NULL;
  if (!chartInstance->c3_delay_not_empty) {
    sf_mex_assign(&c3_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 2,
      c3_u_sizes[0], c3_u_sizes[1]), false);
  }

  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_hoistedGlobal = chartInstance->c3_i;
  c3_d_u = c3_hoistedGlobal;
  c3_d_y = NULL;
  if (!chartInstance->c3_i_not_empty) {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_b_hoistedGlobal = chartInstance->c3_num;
  c3_e_u = c3_b_hoistedGlobal;
  c3_e_y = NULL;
  if (!chartInstance->c3_num_not_empty) {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 3, c3_e_y);
  for (c3_i2 = 0; c3_i2 < 3; c3_i2++) {
    c3_f_u[c3_i2] = chartInstance->c3_yin[c3_i2];
  }

  c3_f_y = NULL;
  if (!chartInstance->c3_yin_not_empty) {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 2, 1, 3),
                  false);
  }

  sf_mex_setcell(c3_y, 4, c3_f_y);
  for (c3_i3 = 0; c3_i3 < 2400003; c3_i3++) {
    c3_g_u[c3_i3] = chartInstance->c3_yin_all[c3_i3];
  }

  c3_g_y = NULL;
  if (!chartInstance->c3_yin_all_not_empty) {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_g_u, 0, 0U, 1U, 0U, 2, 800001,
      3), false);
  }

  sf_mex_setcell(c3_y, 5, c3_g_y);
  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    c3_h_u[c3_i4] = chartInstance->c3_yin_d[c3_i4];
  }

  c3_h_y = NULL;
  if (!chartInstance->c3_yin_d_not_empty) {
    sf_mex_assign(&c3_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_h_u, 0, 0U, 1U, 0U, 1, 3),
                  false);
  }

  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_c_hoistedGlobal = chartInstance->c3_is_active_c3_CoupledTanks;
  c3_i_u = c3_c_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[3];
  int32_T c3_i5;
  int32_T c3_tmp_sizes[2];
  real_T c3_tmp_data[11];
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_loop_ub;
  int32_T c3_i8;
  real_T c3_dv1[3];
  int32_T c3_i9;
  static real_T c3_dv2[2400003];
  int32_T c3_i10;
  real_T c3_dv3[3];
  int32_T c3_i11;
  real_T (*c3_yout_delay)[3];
  c3_yout_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                        "yout_delay", c3_dv0);
  for (c3_i5 = 0; c3_i5 < 3; c3_i5++) {
    (*c3_yout_delay)[c3_i5] = c3_dv0[c3_i5];
  }

  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                        "delay", c3_tmp_data, c3_tmp_sizes);
  chartInstance->c3_delay_sizes[0] = 1;
  chartInstance->c3_delay_sizes[1] = c3_tmp_sizes[1];
  c3_i6 = chartInstance->c3_delay_sizes[0];
  c3_i7 = chartInstance->c3_delay_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i8 = 0; c3_i8 <= c3_loop_ub; c3_i8++) {
    chartInstance->c3_delay_data[c3_i8] = c3_tmp_data[c3_i8];
  }

  chartInstance->c3_i = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "i");
  chartInstance->c3_num = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "num");
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
                        "yin", c3_dv1);
  for (c3_i9 = 0; c3_i9 < 3; c3_i9++) {
    chartInstance->c3_yin[c3_i9] = c3_dv1[c3_i9];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
                        "yin_all", c3_dv2);
  for (c3_i10 = 0; c3_i10 < 2400003; c3_i10++) {
    chartInstance->c3_yin_all[c3_i10] = c3_dv2[c3_i10];
  }

  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
                        "yin_d", c3_dv3);
  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    chartInstance->c3_yin_d[c3_i11] = c3_dv3[c3_i11];
  }

  chartInstance->c3_is_active_c3_CoupledTanks = c3_v_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 7)),
     "is_active_c3_CoupledTanks");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_CoupledTanks(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance)
{
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  real_T c3_yout[3];
  int32_T c3_i15;
  real_T c3_ydelay[4];
  c3_struct_jgcRFG32RbuET2w4s7dLLB c3_b_structure;
  uint32_T c3_debug_family_var_map[16];
  real_T c3_sennum;
  real_T c3_step_count;
  real_T c3_kk;
  real_T c3_j;
  real_T c3_nargin = 3.0;
  real_T c3_nargout = 1.0;
  real_T c3_yout_delay[3];
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  real_T c3_b_ydelay[4];
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  real_T c3_dv4[11];
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_b_kk;
  int32_T c3_b_j;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  real_T (*c3_b_yout_delay)[3];
  real_T (*c3_c_ydelay)[4];
  real_T (*c3_b_yout)[3];
  c3_b_yout_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_c_ydelay = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_yout = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_yout)[c3_i12], 0U);
  }

  for (c3_i13 = 0; c3_i13 < 4; c3_i13++) {
    _SFD_DATA_RANGE_CHECK((*c3_c_ydelay)[c3_i13], 1U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
    c3_yout[c3_i14] = (*c3_b_yout)[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
    c3_ydelay[c3_i15] = (*c3_c_ydelay)[c3_i15];
  }

  c3_b_structure = chartInstance->c3_structure;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_sennum, 0U, c3_j_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_step_count, 1U, c3_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_kk, 2U, c3_j_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j, 3U, c3_j_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 4U, c3_j_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 5U, c3_j_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_yout, 6U, c3_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_ydelay, 7U, c3_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_structure, 8U, c3_h_sf_marshallOut,
    c3_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_yout_delay, 9U, c3_g_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_i, 10U,
    c3_f_sf_marshallOut, c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c3_yin_d, 11U,
    c3_e_sf_marshallOut, c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c3_yin, 12U,
    c3_d_sf_marshallOut, c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(chartInstance->c3_delay_data, (const
    int32_T *)&chartInstance->c3_delay_sizes, NULL, 1, 13, (void *)
    c3_c_sf_marshallOut, (void *)c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c3_yin_all, 14U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_num, 15U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_sennum = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_step_count = 800000.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c3_yin_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
    chartInstance->c3_i = c3_b_structure.i;
    chartInstance->c3_i_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
    for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
      chartInstance->c3_yin[c3_i16] = c3_b_structure.yin[c3_i16];
    }

    chartInstance->c3_yin_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
    for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
      chartInstance->c3_yin_d[c3_i17] = c3_b_structure.yin_d[c3_i17];
    }

    chartInstance->c3_yin_d_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
    for (c3_i18 = 0; c3_i18 < 2400003; c3_i18++) {
      chartInstance->c3_yin_all[c3_i18] = 0.0;
    }

    chartInstance->c3_yin_all_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
    for (c3_i19 = 0; c3_i19 < 4; c3_i19++) {
      c3_b_ydelay[c3_i19] = 0.0;
    }

    chartInstance->c3_delay_sizes[0] = 1;
    chartInstance->c3_delay_sizes[1] = 4;
    c3_i20 = chartInstance->c3_delay_sizes[0];
    c3_i21 = chartInstance->c3_delay_sizes[1];
    for (c3_i22 = 0; c3_i22 < 4; c3_i22++) {
      chartInstance->c3_delay_data[c3_i22] = c3_b_ydelay[c3_i22];
    }

    chartInstance->c3_delay_not_empty = true;
    chartInstance->c3_delay_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
    for (c3_i23 = 0; c3_i23 < 4; c3_i23++) {
      c3_b_ydelay[c3_i23] = c3_ydelay[c3_i23];
    }

    chartInstance->c3_delay_sizes[0] = 1;
    chartInstance->c3_delay_sizes[1] = 4;
    c3_i24 = chartInstance->c3_delay_sizes[0];
    c3_i25 = chartInstance->c3_delay_sizes[1];
    for (c3_i26 = 0; c3_i26 < 4; c3_i26++) {
      chartInstance->c3_delay_data[c3_i26] = c3_b_ydelay[c3_i26];
    }

    chartInstance->c3_delay_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
    chartInstance->c3_num = 0.0;
    chartInstance->c3_num_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
  chartInstance->c3_num++;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  for (c3_i27 = 0; c3_i27 < 11; c3_i27++) {
    c3_dv4[c3_i27] = 0.0;
  }

  chartInstance->c3_delay_sizes[0] = 1;
  chartInstance->c3_delay_sizes[1] = 11;
  c3_i28 = chartInstance->c3_delay_sizes[0];
  c3_i29 = chartInstance->c3_delay_sizes[1];
  for (c3_i30 = 0; c3_i30 < 11; c3_i30++) {
    chartInstance->c3_delay_data[c3_i30] = c3_dv4[c3_i30];
  }

  chartInstance->c3_delay_not_empty = true;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
  for (c3_i31 = 0; c3_i31 < 4; c3_i31++) {
    c3_b_ydelay[c3_i31] = c3_ydelay[c3_i31];
  }

  chartInstance->c3_delay_sizes[0] = 1;
  chartInstance->c3_delay_sizes[1] = 4;
  c3_i32 = chartInstance->c3_delay_sizes[0];
  c3_i33 = chartInstance->c3_delay_sizes[1];
  for (c3_i34 = 0; c3_i34 < 4; c3_i34++) {
    chartInstance->c3_delay_data[c3_i34] = c3_b_ydelay[c3_i34];
  }

  chartInstance->c3_delay_not_empty = true;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
  c3_kk = 1.0;
  c3_b_kk = 0;
  while (c3_b_kk < 3) {
    c3_kk = 1.0 + (real_T)c3_b_kk;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
    chartInstance->c3_yin_all[(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
      chartInstance->c3_num, 1, 800001, 1, 0) + 800001 * ((int32_T)c3_kk - 1)) -
      1] = c3_yout[(int32_T)c3_kk - 1];
    c3_b_kk++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 46);
  c3_j = 1.0;
  c3_b_j = 0;
  while (c3_b_j < 3) {
    c3_j = 1.0 + (real_T)c3_b_j;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 47);
    if (CV_EML_IF(0, 1, 1, chartInstance->c3_delay_data
                  [chartInstance->c3_delay_sizes[0] * ((int32_T)(c3_j + 1.0) - 1)]
                  != 88.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 48);
      chartInstance->c3_yin[(int32_T)c3_j - 1] = chartInstance->c3_yin_all
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)chartInstance->c3_num,
           1, 800001, 1, 0) + 800001 * ((int32_T)c3_j - 1)) - 1];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
      if (CV_EML_IF(0, 1, 2, chartInstance->c3_num > 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 52);
        chartInstance->c3_yin[(int32_T)c3_j - 1] = chartInstance->c3_yin_all
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
             (chartInstance->c3_num - 1.0), 1, 800001, 1, 0) + 800001 *
            ((int32_T)c3_j - 1)) - 1];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
        chartInstance->c3_yin_all[(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all",
          (int32_T)chartInstance->c3_num, 1, 800001, 1, 0) + 800001 * ((int32_T)
          c3_j - 1)) - 1] = chartInstance->c3_yin_all
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
             (chartInstance->c3_num - 1.0), 1, 800001, 1, 0) + 800001 *
            ((int32_T)c3_j - 1)) - 1];
      }
    }

    c3_b_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
  for (c3_i35 = 0; c3_i35 < 3; c3_i35++) {
    chartInstance->c3_yin_d[c3_i35] = chartInstance->c3_yin[c3_i35];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 61);
  for (c3_i36 = 0; c3_i36 < 3; c3_i36++) {
    c3_yout_delay[c3_i36] = chartInstance->c3_yin_d[c3_i36];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 67);
  chartInstance->c3_i++;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -67);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i37 = 0; c3_i37 < 3; c3_i37++) {
    (*c3_b_yout_delay)[c3_i37] = c3_yout_delay[c3_i37];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CoupledTanksMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c3_i38 = 0; c3_i38 < 3; c3_i38++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_yout_delay)[c3_i38], 2U);
  }
}

static void initSimStructsc3_CoupledTanks(SFc3_CoupledTanksInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_num_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_b_num, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_num), &c3_thisId);
  sf_mex_destroy(&c3_b_num);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_num_not_empty = false;
  } else {
    chartInstance->c3_num_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d0;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_num;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_b_num = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_num), &c3_thisId);
  sf_mex_destroy(&c3_b_num);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i39;
  int32_T c3_i40;
  int32_T c3_i41;
  static real_T c3_b_inData[2400003];
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  static real_T c3_u[2400003];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i39 = 0;
  for (c3_i40 = 0; c3_i40 < 3; c3_i40++) {
    for (c3_i41 = 0; c3_i41 < 800001; c3_i41++) {
      c3_b_inData[c3_i41 + c3_i39] = (*(real_T (*)[2400003])c3_inData)[c3_i41 +
        c3_i39];
    }

    c3_i39 += 800001;
  }

  c3_i42 = 0;
  for (c3_i43 = 0; c3_i43 < 3; c3_i43++) {
    for (c3_i44 = 0; c3_i44 < 800001; c3_i44++) {
      c3_u[c3_i44 + c3_i42] = c3_b_inData[c3_i44 + c3_i42];
    }

    c3_i42 += 800001;
  }

  c3_y = NULL;
  if (!chartInstance->c3_yin_all_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 800001, 3),
                  false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_b_yin_all, const char_T *c3_identifier, real_T c3_y[2400003])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_yin_all), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_yin_all);
}

static void c3_d_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y
  [2400003])
{
  static real_T c3_dv5[2400003];
  int32_T c3_i45;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_yin_all_not_empty = false;
  } else {
    chartInstance->c3_yin_all_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv5, 1, 0, 0U, 1, 0U, 2,
                  800001, 3);
    for (c3_i45 = 0; c3_i45 < 2400003; c3_i45++) {
      c3_y[c3_i45] = c3_dv5[c3_i45];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_yin_all;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  static real_T c3_y[2400003];
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_b_yin_all = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_yin_all), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_yin_all);
  c3_i46 = 0;
  for (c3_i47 = 0; c3_i47 < 3; c3_i47++) {
    for (c3_i48 = 0; c3_i48 < 800001; c3_i48++) {
      (*(real_T (*)[2400003])c3_outData)[c3_i48 + c3_i46] = c3_y[c3_i48 + c3_i46];
    }

    c3_i46 += 800001;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T c3_inData_sizes[2])
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes[2];
  int32_T c3_loop_ub;
  int32_T c3_i49;
  real_T c3_b_inData_data[11];
  int32_T c3_u_sizes[2];
  int32_T c3_b_loop_ub;
  int32_T c3_i50;
  real_T c3_u_data[11];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes[0] = 1;
  c3_b_inData_sizes[1] = c3_inData_sizes[1];
  c3_loop_ub = c3_inData_sizes[1] - 1;
  for (c3_i49 = 0; c3_i49 <= c3_loop_ub; c3_i49++) {
    c3_b_inData_data[c3_b_inData_sizes[0] * c3_i49] =
      c3_inData_data[c3_inData_sizes[0] * c3_i49];
  }

  c3_u_sizes[0] = 1;
  c3_u_sizes[1] = c3_b_inData_sizes[1];
  c3_b_loop_ub = c3_b_inData_sizes[1] - 1;
  for (c3_i50 = 0; c3_i50 <= c3_b_loop_ub; c3_i50++) {
    c3_u_data[c3_u_sizes[0] * c3_i50] = c3_b_inData_data[c3_b_inData_sizes[0] *
      c3_i50];
  }

  c3_y = NULL;
  if (!chartInstance->c3_delay_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 2,
      c3_u_sizes[0], c3_u_sizes[1]), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_delay, const char_T *c3_identifier, real_T c3_y_data[],
  int32_T c3_y_sizes[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_delay), &c3_thisId,
                        c3_y_data, c3_y_sizes);
  sf_mex_destroy(&c3_delay);
}

static void c3_f_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y_data[],
  int32_T c3_y_sizes[2])
{
  int32_T c3_i51;
  uint32_T c3_uv0[2];
  int32_T c3_i52;
  static boolean_T c3_bv0[2] = { false, true };

  boolean_T c3_bv1[2];
  int32_T c3_tmp_sizes[2];
  real_T c3_tmp_data[11];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i53;
  for (c3_i51 = 0; c3_i51 < 2; c3_i51++) {
    c3_uv0[c3_i51] = 1U + 10U * (uint32_T)c3_i51;
  }

  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_delay_not_empty = false;
    c3_y_sizes[0] = 1;
    c3_y_sizes[1] = 0;
  } else {
    chartInstance->c3_delay_not_empty = true;
    for (c3_i52 = 0; c3_i52 < 2; c3_i52++) {
      c3_bv1[c3_i52] = c3_bv0[c3_i52];
    }

    sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 0, 0U, 1, 0U,
                     2, c3_bv1, c3_uv0, c3_tmp_sizes);
    c3_y_sizes[0] = 1;
    c3_y_sizes[1] = c3_tmp_sizes[1];
    c3_y = c3_y_sizes[0];
    c3_b_y = c3_y_sizes[1];
    c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
    for (c3_i53 = 0; c3_i53 <= c3_loop_ub; c3_i53++) {
      c3_y_data[c3_i53] = c3_tmp_data[c3_i53];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  c3_outData_sizes[2])
{
  const mxArray *c3_delay;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes[2];
  real_T c3_y_data[11];
  int32_T c3_loop_ub;
  int32_T c3_i54;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_delay = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_delay), &c3_thisId,
                        c3_y_data, c3_y_sizes);
  sf_mex_destroy(&c3_delay);
  c3_outData_sizes[0] = 1;
  c3_outData_sizes[1] = c3_y_sizes[1];
  c3_loop_ub = c3_y_sizes[1] - 1;
  for (c3_i54 = 0; c3_i54 <= c3_loop_ub; c3_i54++) {
    c3_outData_data[c3_outData_sizes[0] * c3_i54] = c3_y_data[c3_y_sizes[0] *
      c3_i54];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i55;
  real_T c3_b_inData[3];
  int32_T c3_i56;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i55 = 0; c3_i55 < 3; c3_i55++) {
    c3_b_inData[c3_i55] = (*(real_T (*)[3])c3_inData)[c3_i55];
  }

  for (c3_i56 = 0; c3_i56 < 3; c3_i56++) {
    c3_u[c3_i56] = c3_b_inData[c3_i56];
  }

  c3_y = NULL;
  if (!chartInstance->c3_yin_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_b_yin, const char_T *c3_identifier, real_T c3_y[3])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_yin), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_yin);
}

static void c3_h_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv6[3];
  int32_T c3_i57;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_yin_not_empty = false;
  } else {
    chartInstance->c3_yin_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv6, 1, 0, 0U, 1, 0U, 2, 1,
                  3);
    for (c3_i57 = 0; c3_i57 < 3; c3_i57++) {
      c3_y[c3_i57] = c3_dv6[c3_i57];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_yin;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i58;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_b_yin = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_yin), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_yin);
  for (c3_i58 = 0; c3_i58 < 3; c3_i58++) {
    (*(real_T (*)[3])c3_outData)[c3_i58] = c3_y[c3_i58];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i59;
  real_T c3_b_inData[3];
  int32_T c3_i60;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i59 = 0; c3_i59 < 3; c3_i59++) {
    c3_b_inData[c3_i59] = (*(real_T (*)[3])c3_inData)[c3_i59];
  }

  for (c3_i60 = 0; c3_i60 < 3; c3_i60++) {
    c3_u[c3_i60] = c3_b_inData[c3_i60];
  }

  c3_y = NULL;
  if (!chartInstance->c3_yin_d_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_i_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_b_yin_d, const char_T *c3_identifier, real_T c3_y[3])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_yin_d), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_yin_d);
}

static void c3_j_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv7[3];
  int32_T c3_i61;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_yin_d_not_empty = false;
  } else {
    chartInstance->c3_yin_d_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv7, 1, 0, 0U, 1, 0U, 1, 3);
    for (c3_i61 = 0; c3_i61 < 3; c3_i61++) {
      c3_y[c3_i61] = c3_dv7[c3_i61];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_yin_d;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i62;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_b_yin_d = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_yin_d), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_yin_d);
  for (c3_i62 = 0; c3_i62 < 3; c3_i62++) {
    (*(real_T (*)[3])c3_outData)[c3_i62] = c3_y[c3_i62];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_i_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_k_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_b_i, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i), &c3_thisId);
  sf_mex_destroy(&c3_b_i);
  return c3_y;
}

static real_T c3_l_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d1;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_i_not_empty = false;
  } else {
    chartInstance->c3_i_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d1, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d1;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_i;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_b_i = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i), &c3_thisId);
  sf_mex_destroy(&c3_b_i);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i63;
  real_T c3_b_inData[3];
  int32_T c3_i64;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i63 = 0; c3_i63 < 3; c3_i63++) {
    c3_b_inData[c3_i63] = (*(real_T (*)[3])c3_inData)[c3_i63];
  }

  for (c3_i64 = 0; c3_i64 < 3; c3_i64++) {
    c3_u[c3_i64] = c3_b_inData[c3_i64];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_m_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_yout_delay, const char_T *c3_identifier, real_T c3_y[3])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_yout_delay), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_yout_delay);
}

static void c3_n_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv8[3];
  int32_T c3_i65;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv8, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i65 = 0; c3_i65 < 3; c3_i65++) {
    c3_y[c3_i65] = c3_dv8[c3_i65];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_yout_delay;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i66;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_yout_delay = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_yout_delay), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_yout_delay);
  for (c3_i66 = 0; c3_i66 < 3; c3_i66++) {
    (*(real_T (*)[3])c3_outData)[c3_i66] = c3_y[c3_i66];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  c3_struct_jgcRFG32RbuET2w4s7dLLB c3_u;
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_i67;
  real_T c3_d_u[3];
  const mxArray *c3_d_y = NULL;
  int32_T c3_i68;
  real_T c3_e_u[3];
  const mxArray *c3_e_y = NULL;
  int32_T c3_i69;
  real_T c3_f_u[804];
  const mxArray *c3_f_y = NULL;
  int32_T c3_i70;
  real_T c3_g_u[5];
  const mxArray *c3_g_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(c3_struct_jgcRFG32RbuET2w4s7dLLB *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c3_b_u = c3_u.i;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_b_y, "i", "i", 0);
  c3_c_u = c3_u.count;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_c_y, "count", "count", 0);
  for (c3_i67 = 0; c3_i67 < 3; c3_i67++) {
    c3_d_u[c3_i67] = c3_u.yin[c3_i67];
  }

  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_d_u, 0, 0U, 1U, 0U, 2, 1, 3),
                false);
  sf_mex_addfield(c3_y, c3_d_y, "yin", "yin", 0);
  for (c3_i68 = 0; c3_i68 < 3; c3_i68++) {
    c3_e_u[c3_i68] = c3_u.yin_d[c3_i68];
  }

  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_e_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c3_y, c3_e_y, "yin_d", "yin_d", 0);
  for (c3_i69 = 0; c3_i69 < 804; c3_i69++) {
    c3_f_u[c3_i69] = c3_u.delay1[c3_i69];
  }

  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 2, 201, 4),
                false);
  sf_mex_addfield(c3_y, c3_f_y, "delay1", "delay1", 0);
  for (c3_i70 = 0; c3_i70 < 5; c3_i70++) {
    c3_g_u[c3_i70] = c3_u.ranD[c3_i70];
  }

  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_g_u, 0, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_addfield(c3_y, c3_g_y, "ranD", "ranD", 0);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_o_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  c3_struct_jgcRFG32RbuET2w4s7dLLB *c3_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[6] = { "i", "count", "yin", "yin_d",
    "delay1", "ranD" };

  c3_thisId.fParent = c3_parentId;
  sf_mex_check_struct(c3_parentId, c3_u, 6, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "i";
  c3_y->i = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "i", "i", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "count";
  c3_y->count = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "count", "count", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "yin";
  c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u, "yin",
    "yin", 0)), &c3_thisId, c3_y->yin);
  c3_thisId.fIdentifier = "yin_d";
  c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u, "yin_d",
    "yin_d", 0)), &c3_thisId, c3_y->yin_d);
  c3_thisId.fIdentifier = "delay1";
  c3_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u, "delay1",
    "delay1", 0)), &c3_thisId, c3_y->delay1);
  c3_thisId.fIdentifier = "ranD";
  c3_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u, "ranD",
    "ranD", 0)), &c3_thisId, c3_y->ranD);
  sf_mex_destroy(&c3_u);
}

static real_T c3_p_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d2, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_q_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv9[3];
  int32_T c3_i71;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv9, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c3_i71 = 0; c3_i71 < 3; c3_i71++) {
    c3_y[c3_i71] = c3_dv9[c3_i71];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_r_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv10[3];
  int32_T c3_i72;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv10, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c3_i72 = 0; c3_i72 < 3; c3_i72++) {
    c3_y[c3_i72] = c3_dv10[c3_i72];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_s_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[804])
{
  real_T c3_dv11[804];
  int32_T c3_i73;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv11, 1, 0, 0U, 1, 0U, 2, 201,
                4);
  for (c3_i73 = 0; c3_i73 < 804; c3_i73++) {
    c3_y[c3_i73] = c3_dv11[c3_i73];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_t_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[5])
{
  real_T c3_dv12[5];
  int32_T c3_i74;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv12, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c3_i74 = 0; c3_i74 < 5; c3_i74++) {
    c3_y[c3_i74] = c3_dv12[c3_i74];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_structure;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  c3_struct_jgcRFG32RbuET2w4s7dLLB c3_y;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_b_structure = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_structure), &c3_thisId,
                        &c3_y);
  sf_mex_destroy(&c3_b_structure);
  *(c3_struct_jgcRFG32RbuET2w4s7dLLB *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i75;
  real_T c3_b_inData[4];
  int32_T c3_i76;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i75 = 0; c3_i75 < 4; c3_i75++) {
    c3_b_inData[c3_i75] = (*(real_T (*)[4])c3_inData)[c3_i75];
  }

  for (c3_i76 = 0; c3_i76 < 4; c3_i76++) {
    c3_u[c3_i76] = c3_b_inData[c3_i76];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_CoupledTanks_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_u_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i77;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i77, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i77;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_v_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_CoupledTanks, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_CoupledTanks), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_CoupledTanks);
  return c3_y;
}

static uint8_T c3_w_emlrt_marshallIn(SFc3_CoupledTanksInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_CoupledTanksInstanceStruct *chartInstance)
{
  (void)chartInstance;
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

void sf_c3_CoupledTanks_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2526271312U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1986378934U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(662718645U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3385013595U);
}

mxArray *sf_c3_CoupledTanks_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("VbXo8xsSgn0PFqHQqZRHrC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_CoupledTanks_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_CoupledTanks_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_CoupledTanks(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[5],T\"yout_delay\",},{M[4],M[0],T\"delay\",S'l','i','p'{{M1x2[332 337],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[308 309],M[0],}}},{M[4],M[0],T\"num\",S'l','i','p'{{M1x2[346 349],M[0],}}},{M[4],M[0],T\"yin\",S'l','i','p'{{M1x2[328 331],M[0],}}},{M[4],M[0],T\"yin_all\",S'l','i','p'{{M1x2[338 345],M[0],}}},{M[4],M[0],T\"yin_d\",S'l','i','p'{{M1x2[310 315],M[0],}}},{M[8],M[0],T\"is_active_c3_CoupledTanks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_CoupledTanks_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_CoupledTanksInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_CoupledTanksInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CoupledTanksMachineNumber_,
           3,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"yout");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ydelay");
          _SFD_SET_DATA_PROPS(2,2,0,1,"yout_delay");
          _SFD_SET_DATA_PROPS(3,10,0,0,"structure");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1423);
        _SFD_CV_INIT_EML_IF(0,1,0,466,481,-1,724);
        _SFD_CV_INIT_EML_IF(0,1,1,964,983,1038,1257);
        _SFD_CV_INIT_EML_IF(0,1,2,1051,1059,-1,1241);
        _SFD_CV_INIT_EML_FOR(0,1,0,836,849,894);
        _SFD_CV_INIT_EML_FOR(0,1,1,950,960,1261);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_g_sf_marshallOut,(MexInFcnForType)
            c3_g_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_h_sf_marshallOut,(MexInFcnForType)c3_h_sf_marshallIn);

        {
          real_T (*c3_yout)[3];
          real_T (*c3_ydelay)[4];
          real_T (*c3_yout_delay)[3];
          c3_yout_delay = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            1);
          c3_ydelay = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c3_yout = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_yout);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_ydelay);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_yout_delay);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c3_structure);
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
  return "8enLIsuydEtYA3fFcQf2dE";
}

static void sf_opaque_initialize_c3_CoupledTanks(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_CoupledTanksInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_CoupledTanks((SFc3_CoupledTanksInstanceStruct*)
    chartInstanceVar);
  initialize_c3_CoupledTanks((SFc3_CoupledTanksInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_CoupledTanks(void *chartInstanceVar)
{
  enable_c3_CoupledTanks((SFc3_CoupledTanksInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_CoupledTanks(void *chartInstanceVar)
{
  disable_c3_CoupledTanks((SFc3_CoupledTanksInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_CoupledTanks(void *chartInstanceVar)
{
  sf_gateway_c3_CoupledTanks((SFc3_CoupledTanksInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_CoupledTanks(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_CoupledTanks
    ((SFc3_CoupledTanksInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_CoupledTanks();/* state var info */
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

extern void sf_internal_set_sim_state_c3_CoupledTanks(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_CoupledTanks();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_CoupledTanks((SFc3_CoupledTanksInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_CoupledTanks(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_CoupledTanks(S);
}

static void sf_opaque_set_sim_state_c3_CoupledTanks(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c3_CoupledTanks(S, st);
}

static void sf_opaque_terminate_c3_CoupledTanks(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_CoupledTanksInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CoupledTanks_optimization_info();
    }

    finalize_c3_CoupledTanks((SFc3_CoupledTanksInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_CoupledTanks((SFc3_CoupledTanksInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_CoupledTanks(SimStruct *S)
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
    initialize_params_c3_CoupledTanks((SFc3_CoupledTanksInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_CoupledTanks(SimStruct *S)
{
  /* Actual parameters from chart:
     structure
   */
  const char_T *rtParamNames[] = { "structure" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CoupledTanks_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
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
  ssSetChecksum0(S,(656819830U));
  ssSetChecksum1(S,(2792852803U));
  ssSetChecksum2(S,(3454941841U));
  ssSetChecksum3(S,(3655217990U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_CoupledTanks(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_CoupledTanks(SimStruct *S)
{
  SFc3_CoupledTanksInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_CoupledTanksInstanceStruct *)utMalloc(sizeof
    (SFc3_CoupledTanksInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_CoupledTanksInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_CoupledTanks;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_CoupledTanks;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_CoupledTanks;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_CoupledTanks;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_CoupledTanks;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_CoupledTanks;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_CoupledTanks;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_CoupledTanks;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_CoupledTanks;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_CoupledTanks;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_CoupledTanks;
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

void c3_CoupledTanks_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_CoupledTanks(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_CoupledTanks(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_CoupledTanks(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_CoupledTanks_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
