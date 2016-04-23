/* Include files */

#include <stddef.h>
#include "blas.h"
#include "HeatExchanger_sfun.h"
#include "c5_HeatExchanger.h"
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
static const char * c5_debug_family_names[23] = { "sensor_reading",
  "sensor_delay", "kk", "j", "avg_delay", "fileID", "nargin", "nargout",
  "control_yactual_value", "control_ysensor_value", "control_ynetwork_delay",
  "structure", "control_signal_vector", "control_delay_vector", "i", "yin_d",
  "delay_v", "yin", "sensor_value", "num", "ynd_tmp", "last_senReading",
  "last_senDelay" };

/* Function Declarations */
static void initialize_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance);
static void initialize_params_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct *
  chartInstance);
static void enable_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance);
static void disable_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_HeatExchanger
  (SFc5_HeatExchangerInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_HeatExchanger
  (SFc5_HeatExchangerInstanceStruct *chartInstance);
static void set_sim_state_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance);
static void sf_gateway_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance);
static void c5_chartstep_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance);
static void initSimStructsc5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_last_senDelay, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_last_senReading, const char_T
  *c5_identifier);
static real_T c5_d_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_e_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_ynd_tmp, const char_T *c5_identifier,
  real_T c5_y[3]);
static void c5_f_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_g_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_num, const char_T *c5_identifier);
static real_T c5_h_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_i_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_sensor_value, const char_T *c5_identifier);
static real_T c5_j_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_k_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_yin, const char_T *c5_identifier, real_T
  c5_y[3]);
static void c5_l_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_m_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_delay_v, const char_T *c5_identifier,
  real_T c5_y[3]);
static void c5_n_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_o_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_yin_d, const char_T *c5_identifier, real_T
  c5_y[3]);
static void c5_p_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_q_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_i, const char_T *c5_identifier);
static real_T c5_r_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_s_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  c5_struct_GS2RmkGZ5GnB7UItqpfzDB *c5_y);
static void c5_t_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_u_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_v_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[5]);
static void c5_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u);
static real_T c5_fopen(SFc5_HeatExchangerInstanceStruct *chartInstance);
static real_T c5_fileManager(SFc5_HeatExchangerInstanceStruct *chartInstance);
static void c5_isequal(SFc5_HeatExchangerInstanceStruct *chartInstance);
static void c5_fprintf(SFc5_HeatExchangerInstanceStruct *chartInstance, real_T
  c5_fileID, real_T c5_varargin_1);
static void c5_fclose(SFc5_HeatExchangerInstanceStruct *chartInstance, real_T
                      c5_fileID);
static int32_T c5_b_fileManager(SFc5_HeatExchangerInstanceStruct *chartInstance,
  real_T c5_varargin_1);
static real_T c5_w_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_feval, const char_T *c5_identifier);
static real_T c5_x_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static boolean_T c5_y_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_failp, const char_T *c5_identifier);
static boolean_T c5_ab_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static const mxArray *c5_m_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_bb_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_cb_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_HeatExchanger, const char_T
  *c5_identifier);
static uint8_T c5_db_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_HeatExchangerInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_i_not_empty = false;
  chartInstance->c5_yin_d_not_empty = false;
  chartInstance->c5_delay_v_not_empty = false;
  chartInstance->c5_yin_not_empty = false;
  chartInstance->c5_sensor_value_not_empty = false;
  chartInstance->c5_num_not_empty = false;
  chartInstance->c5_ynd_tmp_not_empty = false;
  chartInstance->c5_last_senReading_not_empty = false;
  chartInstance->c5_last_senDelay_not_empty = false;
  chartInstance->c5_is_active_c5_HeatExchanger = 0U;
}

static void initialize_params_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct *
  chartInstance)
{
  const mxArray *c5_m0 = NULL;
  const mxArray *c5_mxField;
  c5_struct_GS2RmkGZ5GnB7UItqpfzDB c5_r0;
  c5_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c5_mxField = sf_mex_getfield(c5_m0, "i", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c5_mxField), &c5_r0.i, 1, 0, 0U, 0,
                      0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "count", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c5_mxField), &c5_r0.count, 1, 0,
                      0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "sen_num", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c5_mxField), &c5_r0.sen_num, 1, 0,
                      0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "yin", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c5_mxField), c5_r0.yin, 1, 0, 0U,
                      1, 0U, 2, 1, 3);
  c5_mxField = sf_mex_getfield(c5_m0, "yin_d", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c5_mxField), c5_r0.yin_d, 1, 0, 0U,
                      1, 0U, 2, 3, 1);
  c5_mxField = sf_mex_getfield(c5_m0, "delay_v", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c5_mxField), c5_r0.delay_v, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c5_mxField = sf_mex_getfield(c5_m0, "ynd_tmp", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c5_mxField), c5_r0.ynd_tmp, 1, 0,
                      0U, 1, 0U, 2, 1, 3);
  c5_mxField = sf_mex_getfield(c5_m0, "ranD", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c5_mxField), c5_r0.ranD, 1, 0, 0U,
                      1, 0U, 2, 1, 5);
  sf_mex_destroy(&c5_m0);
  chartInstance->c5_structure = c5_r0;
}

static void enable_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_HeatExchanger
  (SFc5_HeatExchangerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_HeatExchanger
  (SFc5_HeatExchangerInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_i0;
  real_T c5_c_u[3];
  const mxArray *c5_d_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_d_hoistedGlobal;
  real_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  real_T c5_e_hoistedGlobal;
  real_T c5_f_u;
  const mxArray *c5_g_y = NULL;
  real_T c5_f_hoistedGlobal;
  real_T c5_g_u;
  const mxArray *c5_h_y = NULL;
  real_T c5_g_hoistedGlobal;
  real_T c5_h_u;
  const mxArray *c5_i_y = NULL;
  int32_T c5_i1;
  real_T c5_i_u[3];
  const mxArray *c5_j_y = NULL;
  int32_T c5_i2;
  real_T c5_j_u[3];
  const mxArray *c5_k_y = NULL;
  int32_T c5_i3;
  real_T c5_k_u[3];
  const mxArray *c5_l_y = NULL;
  uint8_T c5_h_hoistedGlobal;
  uint8_T c5_l_u;
  const mxArray *c5_m_y = NULL;
  real_T *c5_control_delay_vector;
  real_T *c5_control_signal_vector;
  c5_control_delay_vector = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_control_signal_vector = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(12, 1), false);
  c5_hoistedGlobal = *c5_control_delay_vector;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_control_signal_vector;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  for (c5_i0 = 0; c5_i0 < 3; c5_i0++) {
    c5_c_u[c5_i0] = chartInstance->c5_delay_v[c5_i0];
  }

  c5_d_y = NULL;
  if (!chartInstance->c5_delay_v_not_empty) {
    sf_mex_assign(&c5_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 3),
                  false);
  }

  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_c_hoistedGlobal = chartInstance->c5_i;
  c5_d_u = c5_c_hoistedGlobal;
  c5_e_y = NULL;
  if (!chartInstance->c5_i_not_empty) {
    sf_mex_assign(&c5_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_d_hoistedGlobal = chartInstance->c5_last_senDelay;
  c5_e_u = c5_d_hoistedGlobal;
  c5_f_y = NULL;
  if (!chartInstance->c5_last_senDelay_not_empty) {
    sf_mex_assign(&c5_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_y, 4, c5_f_y);
  c5_e_hoistedGlobal = chartInstance->c5_last_senReading;
  c5_f_u = c5_e_hoistedGlobal;
  c5_g_y = NULL;
  if (!chartInstance->c5_last_senReading_not_empty) {
    sf_mex_assign(&c5_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_y, 5, c5_g_y);
  c5_f_hoistedGlobal = chartInstance->c5_num;
  c5_g_u = c5_f_hoistedGlobal;
  c5_h_y = NULL;
  if (!chartInstance->c5_num_not_empty) {
    sf_mex_assign(&c5_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_y, 6, c5_h_y);
  c5_g_hoistedGlobal = chartInstance->c5_sensor_value;
  c5_h_u = c5_g_hoistedGlobal;
  c5_i_y = NULL;
  if (!chartInstance->c5_sensor_value_not_empty) {
    sf_mex_assign(&c5_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_y, 7, c5_i_y);
  for (c5_i1 = 0; c5_i1 < 3; c5_i1++) {
    c5_i_u[c5_i1] = chartInstance->c5_yin[c5_i1];
  }

  c5_j_y = NULL;
  if (!chartInstance->c5_yin_not_empty) {
    sf_mex_assign(&c5_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_i_u, 0, 0U, 1U, 0U, 2, 1, 3),
                  false);
  }

  sf_mex_setcell(c5_y, 8, c5_j_y);
  for (c5_i2 = 0; c5_i2 < 3; c5_i2++) {
    c5_j_u[c5_i2] = chartInstance->c5_yin_d[c5_i2];
  }

  c5_k_y = NULL;
  if (!chartInstance->c5_yin_d_not_empty) {
    sf_mex_assign(&c5_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_j_u, 0, 0U, 1U, 0U, 1, 3),
                  false);
  }

  sf_mex_setcell(c5_y, 9, c5_k_y);
  for (c5_i3 = 0; c5_i3 < 3; c5_i3++) {
    c5_k_u[c5_i3] = chartInstance->c5_ynd_tmp[c5_i3];
  }

  c5_l_y = NULL;
  if (!chartInstance->c5_ynd_tmp_not_empty) {
    sf_mex_assign(&c5_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_k_u, 0, 0U, 1U, 0U, 2, 1, 3),
                  false);
  }

  sf_mex_setcell(c5_y, 10, c5_l_y);
  c5_h_hoistedGlobal = chartInstance->c5_is_active_c5_HeatExchanger;
  c5_l_u = c5_h_hoistedGlobal;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 11, c5_m_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[3];
  int32_T c5_i4;
  real_T c5_dv1[3];
  int32_T c5_i5;
  real_T c5_dv2[3];
  int32_T c5_i6;
  real_T c5_dv3[3];
  int32_T c5_i7;
  real_T *c5_control_delay_vector;
  real_T *c5_control_signal_vector;
  c5_control_delay_vector = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_control_signal_vector = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *c5_control_delay_vector = c5_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 0)), "control_delay_vector");
  *c5_control_signal_vector = c5_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 1)), "control_signal_vector");
  c5_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
                        "delay_v", c5_dv0);
  for (c5_i4 = 0; c5_i4 < 3; c5_i4++) {
    chartInstance->c5_delay_v[c5_i4] = c5_dv0[c5_i4];
  }

  chartInstance->c5_i = c5_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 3)), "i");
  chartInstance->c5_last_senDelay = c5_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 4)), "last_senDelay");
  chartInstance->c5_last_senReading = c5_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 5)), "last_senReading");
  chartInstance->c5_num = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 6)), "num");
  chartInstance->c5_sensor_value = c5_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 7)), "sensor_value");
  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 8)),
                        "yin", c5_dv1);
  for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
    chartInstance->c5_yin[c5_i5] = c5_dv1[c5_i5];
  }

  c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 9)),
                        "yin_d", c5_dv2);
  for (c5_i6 = 0; c5_i6 < 3; c5_i6++) {
    chartInstance->c5_yin_d[c5_i6] = c5_dv2[c5_i6];
  }

  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 10)),
                        "ynd_tmp", c5_dv3);
  for (c5_i7 = 0; c5_i7 < 3; c5_i7++) {
    chartInstance->c5_ynd_tmp[c5_i7] = c5_dv3[c5_i7];
  }

  chartInstance->c5_is_active_c5_HeatExchanger = c5_cb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 11)),
     "is_active_c5_HeatExchanger");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_HeatExchanger(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance)
{
  real_T *c5_control_yactual_value;
  real_T *c5_control_ysensor_value;
  real_T *c5_control_ynetwork_delay;
  real_T *c5_control_signal_vector;
  real_T *c5_control_delay_vector;
  c5_control_delay_vector = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_control_signal_vector = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_control_ynetwork_delay = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_control_ysensor_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_control_yactual_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_control_yactual_value, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_control_ysensor_value, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_control_ynetwork_delay, 2U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_HeatExchanger(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_HeatExchangerMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c5_control_signal_vector, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_control_delay_vector, 5U);
}

static void c5_chartstep_c5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_control_yactual_value;
  real_T c5_control_ysensor_value;
  real_T c5_control_ynetwork_delay;
  c5_struct_GS2RmkGZ5GnB7UItqpfzDB c5_b_structure;
  uint32_T c5_debug_family_var_map[23];
  real_T c5_sensor_reading[3];
  real_T c5_sensor_delay[3];
  real_T c5_kk;
  real_T c5_j;
  real_T c5_avg_delay;
  real_T c5_fileID;
  real_T c5_nargin = 4.0;
  real_T c5_nargout = 2.0;
  real_T c5_control_signal_vector;
  real_T c5_control_delay_vector;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  real_T c5_A;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  int32_T c5_i14;
  static char_T c5_cv0[12] = { 'a', 'c', 't', 'u', 'a', 'l', ' ', 'v', 'a', 'l',
    'u', 'e' };

  char_T c5_u[12];
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  int32_T c5_i15;
  static char_T c5_cv1[22] = { 'c', 'o', 'n', 'v', 'e', 'r', 't', 'e', 'd', ' ',
    's', 'e', 'n', 's', 'o', 'r', '_', 'v', 'a', 'l', 'u', 'e' };

  char_T c5_c_u[22];
  const mxArray *c5_c_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  int32_T c5_i16;
  static char_T c5_cv2[23] = { 'c', 'o', 'n', 'v', 'e', 'r', 't', 'e', 'd', ' ',
    'n', 'e', 't', 'w', 'o', 'r', 'k', ' ', 'd', 'e', 'l', 'a', 'y' };

  char_T c5_e_u[23];
  const mxArray *c5_e_y = NULL;
  real_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  int32_T c5_i17;
  static char_T c5_cv3[31] = { '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
    '-', '-', '-', '-', '-', 'n', 'u', 'm', '-', '-', '-', '-', '-', '-', '-',
    '-', '-', '-', '-', '-', '-' };

  char_T c5_g_u[31];
  const mxArray *c5_g_y = NULL;
  real_T c5_d_hoistedGlobal;
  real_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  real_T *c5_b_control_delay_vector;
  real_T *c5_b_control_signal_vector;
  real_T *c5_b_control_ynetwork_delay;
  real_T *c5_b_control_ysensor_value;
  real_T *c5_b_control_yactual_value;
  c5_b_control_delay_vector = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    2);
  c5_b_control_signal_vector = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    1);
  c5_b_control_ynetwork_delay = (real_T *)ssGetInputPortSignal(chartInstance->S,
    2);
  c5_b_control_ysensor_value = (real_T *)ssGetInputPortSignal(chartInstance->S,
    1);
  c5_b_control_yactual_value = (real_T *)ssGetInputPortSignal(chartInstance->S,
    0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_control_yactual_value;
  c5_b_hoistedGlobal = *c5_b_control_ysensor_value;
  c5_c_hoistedGlobal = *c5_b_control_ynetwork_delay;
  c5_control_yactual_value = c5_hoistedGlobal;
  c5_control_ysensor_value = c5_b_hoistedGlobal;
  c5_control_ynetwork_delay = c5_c_hoistedGlobal;
  c5_b_structure = chartInstance->c5_structure;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 23U, 23U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_sensor_reading, 0U,
    c5_l_sf_marshallOut, c5_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_sensor_delay, 1U, c5_l_sf_marshallOut,
    c5_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_kk, 2U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_j, 3U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_avg_delay, 4U, c5_j_sf_marshallOut,
    c5_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_fileID, 5U, c5_j_sf_marshallOut,
    c5_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_j_sf_marshallOut,
    c5_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_j_sf_marshallOut,
    c5_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_control_yactual_value, 8U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_control_ysensor_value, 9U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_control_ynetwork_delay, 10U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_structure, 11U, c5_k_sf_marshallOut,
    c5_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_control_signal_vector, 12U,
    c5_j_sf_marshallOut, c5_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_control_delay_vector, 13U,
    c5_j_sf_marshallOut, c5_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c5_i, 14U,
    c5_i_sf_marshallOut, c5_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c5_yin_d, 15U,
    c5_h_sf_marshallOut, c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c5_delay_v, 16U,
    c5_g_sf_marshallOut, c5_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c5_yin, 17U,
    c5_f_sf_marshallOut, c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c5_sensor_value, 18U,
    c5_e_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c5_num, 19U,
    c5_d_sf_marshallOut, c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c5_ynd_tmp, 20U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c5_last_senReading, 21U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c5_last_senDelay, 22U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c5_yin_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
    chartInstance->c5_i = c5_b_structure.i;
    chartInstance->c5_i_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 28);
    for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
      chartInstance->c5_yin[c5_i8] = c5_b_structure.yin[c5_i8];
    }

    chartInstance->c5_yin_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 29);
    for (c5_i9 = 0; c5_i9 < 3; c5_i9++) {
      chartInstance->c5_ynd_tmp[c5_i9] = c5_b_structure.ynd_tmp[c5_i9];
    }

    chartInstance->c5_ynd_tmp_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 31);
    for (c5_i10 = 0; c5_i10 < 3; c5_i10++) {
      chartInstance->c5_yin_d[c5_i10] = c5_b_structure.yin_d[c5_i10];
    }

    chartInstance->c5_yin_d_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 32);
    for (c5_i11 = 0; c5_i11 < 3; c5_i11++) {
      chartInstance->c5_delay_v[c5_i11] = c5_b_structure.delay_v[c5_i11];
    }

    chartInstance->c5_delay_v_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 34);
    chartInstance->c5_last_senReading = 0.0;
    chartInstance->c5_last_senReading_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 35);
    chartInstance->c5_last_senDelay = 0.0;
    chartInstance->c5_last_senDelay_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 43);
    chartInstance->c5_sensor_value = 0.0;
    chartInstance->c5_sensor_value_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 44);
    chartInstance->c5_sensor_value = c5_control_ysensor_value;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 45);
    chartInstance->c5_num = 0.0;
    chartInstance->c5_num_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 51);
  for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
    c5_sensor_reading[c5_i12] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 52);
  for (c5_i13 = 0; c5_i13 < 3; c5_i13++) {
    c5_sensor_delay[c5_i13] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 53);
  chartInstance->c5_num++;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 57);
  chartInstance->c5_sensor_value = c5_control_ysensor_value;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 61);
  if (CV_EML_IF(0, 1, 1, chartInstance->c5_num == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 62);
    c5_kk = 1.0;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 63);
    chartInstance->c5_last_senReading = c5_control_yactual_value;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 64);
    chartInstance->c5_last_senDelay = c5_control_ynetwork_delay;
    CV_EML_FOR(0, 1, 0, 0);
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 68);
  c5_j = 1.0;
  CV_EML_FOR(0, 1, 1, 1);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 69);
  if (CV_EML_IF(0, 1, 2, chartInstance->c5_sensor_value != 88.0)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 70);
    chartInstance->c5_last_senReading = c5_control_yactual_value;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 71);
    chartInstance->c5_last_senDelay = c5_control_ynetwork_delay;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 76);
    if (CV_EML_IF(0, 1, 3, chartInstance->c5_num > 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 78);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 80);
      chartInstance->c5_last_senDelay += 0.1;
    }
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 85);
  c5_avg_delay = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 87);
  c5_kk = 1.0;
  CV_EML_FOR(0, 1, 2, 1);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 90);
  c5_avg_delay += chartInstance->c5_last_senDelay;
  CV_EML_FOR(0, 1, 2, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 94);
  c5_A = c5_avg_delay;
  c5_x = c5_A;
  c5_b_x = c5_x;
  c5_c_x = c5_b_x;
  c5_avg_delay = c5_c_x;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 95);
  c5_fileID = c5_fopen(chartInstance);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 96);
  c5_fprintf(chartInstance, c5_fileID, c5_avg_delay);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 97);
  c5_fclose(chartInstance, c5_fileID);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 109);
  c5_control_signal_vector = chartInstance->c5_last_senReading;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 111);
  c5_control_delay_vector = chartInstance->c5_last_senDelay;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 113);
  for (c5_i14 = 0; c5_i14 < 12; c5_i14++) {
    c5_u[c5_i14] = c5_cv0[c5_i14];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 12), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 114);
  c5_b_u = c5_control_yactual_value;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_b_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 116);
  for (c5_i15 = 0; c5_i15 < 22; c5_i15++) {
    c5_c_u[c5_i15] = c5_cv1[c5_i15];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_c_u, 10, 0U, 1U, 0U, 2, 1, 22),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_c_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 117);
  c5_d_u = c5_control_signal_vector;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_d_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 118);
  for (c5_i16 = 0; c5_i16 < 23; c5_i16++) {
    c5_e_u[c5_i16] = c5_cv2[c5_i16];
  }

  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_e_u, 10, 0U, 1U, 0U, 2, 1, 23),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_e_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 119);
  c5_f_u = c5_control_delay_vector;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_f_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 120);
  for (c5_i17 = 0; c5_i17 < 31; c5_i17++) {
    c5_g_u[c5_i17] = c5_cv3[c5_i17];
  }

  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_g_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_g_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 121);
  c5_d_hoistedGlobal = chartInstance->c5_num;
  c5_h_u = c5_d_hoistedGlobal;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_h_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 126);
  chartInstance->c5_i++;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -126);
  _SFD_SYMBOL_SCOPE_POP();
  *c5_b_control_signal_vector = c5_control_signal_vector;
  *c5_b_control_delay_vector = c5_control_delay_vector;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_HeatExchanger(SFc5_HeatExchangerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  if (!chartInstance->c5_last_senDelay_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_last_senDelay, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_last_senDelay),
    &c5_thisId);
  sf_mex_destroy(&c5_b_last_senDelay);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_last_senDelay_not_empty = false;
  } else {
    chartInstance->c5_last_senDelay_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
    c5_y = c5_d0;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_last_senDelay;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_last_senDelay = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_last_senDelay),
    &c5_thisId);
  sf_mex_destroy(&c5_b_last_senDelay);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  if (!chartInstance->c5_last_senReading_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_last_senReading, const char_T
  *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_last_senReading),
    &c5_thisId);
  sf_mex_destroy(&c5_b_last_senReading);
  return c5_y;
}

static real_T c5_d_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d1;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_last_senReading_not_empty = false;
  } else {
    chartInstance->c5_last_senReading_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d1, 1, 0, 0U, 0, 0U, 0);
    c5_y = c5_d1;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_last_senReading;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_last_senReading = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_last_senReading),
    &c5_thisId);
  sf_mex_destroy(&c5_b_last_senReading);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i18;
  real_T c5_b_inData[3];
  int32_T c5_i19;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i18 = 0; c5_i18 < 3; c5_i18++) {
    c5_b_inData[c5_i18] = (*(real_T (*)[3])c5_inData)[c5_i18];
  }

  for (c5_i19 = 0; c5_i19 < 3; c5_i19++) {
    c5_u[c5_i19] = c5_b_inData[c5_i19];
  }

  c5_y = NULL;
  if (!chartInstance->c5_ynd_tmp_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_e_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_ynd_tmp, const char_T *c5_identifier,
  real_T c5_y[3])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_ynd_tmp), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_b_ynd_tmp);
}

static void c5_f_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv4[3];
  int32_T c5_i20;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_ynd_tmp_not_empty = false;
  } else {
    chartInstance->c5_ynd_tmp_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv4, 1, 0, 0U, 1, 0U, 2, 1,
                  3);
    for (c5_i20 = 0; c5_i20 < 3; c5_i20++) {
      c5_y[c5_i20] = c5_dv4[c5_i20];
    }
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_ynd_tmp;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i21;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_ynd_tmp = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_ynd_tmp), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_b_ynd_tmp);
  for (c5_i21 = 0; c5_i21 < 3; c5_i21++) {
    (*(real_T (*)[3])c5_outData)[c5_i21] = c5_y[c5_i21];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  if (!chartInstance->c5_num_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_g_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_num, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_num), &c5_thisId);
  sf_mex_destroy(&c5_b_num);
  return c5_y;
}

static real_T c5_h_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d2;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_num_not_empty = false;
  } else {
    chartInstance->c5_num_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d2, 1, 0, 0U, 0, 0U, 0);
    c5_y = c5_d2;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_num;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_num = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_num), &c5_thisId);
  sf_mex_destroy(&c5_b_num);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  if (!chartInstance->c5_sensor_value_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_i_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_sensor_value, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sensor_value),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sensor_value);
  return c5_y;
}

static real_T c5_j_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d3;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_sensor_value_not_empty = false;
  } else {
    chartInstance->c5_sensor_value_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d3, 1, 0, 0U, 0, 0U, 0);
    c5_y = c5_d3;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sensor_value;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_sensor_value = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sensor_value),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sensor_value);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i22;
  real_T c5_b_inData[3];
  int32_T c5_i23;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i22 = 0; c5_i22 < 3; c5_i22++) {
    c5_b_inData[c5_i22] = (*(real_T (*)[3])c5_inData)[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 3; c5_i23++) {
    c5_u[c5_i23] = c5_b_inData[c5_i23];
  }

  c5_y = NULL;
  if (!chartInstance->c5_yin_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_k_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_yin, const char_T *c5_identifier, real_T
  c5_y[3])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_yin), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_b_yin);
}

static void c5_l_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv5[3];
  int32_T c5_i24;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_yin_not_empty = false;
  } else {
    chartInstance->c5_yin_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv5, 1, 0, 0U, 1, 0U, 2, 1,
                  3);
    for (c5_i24 = 0; c5_i24 < 3; c5_i24++) {
      c5_y[c5_i24] = c5_dv5[c5_i24];
    }
  }

  sf_mex_destroy(&c5_u);
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_yin;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i25;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_yin = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_yin), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_b_yin);
  for (c5_i25 = 0; c5_i25 < 3; c5_i25++) {
    (*(real_T (*)[3])c5_outData)[c5_i25] = c5_y[c5_i25];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i26;
  real_T c5_b_inData[3];
  int32_T c5_i27;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
    c5_b_inData[c5_i26] = (*(real_T (*)[3])c5_inData)[c5_i26];
  }

  for (c5_i27 = 0; c5_i27 < 3; c5_i27++) {
    c5_u[c5_i27] = c5_b_inData[c5_i27];
  }

  c5_y = NULL;
  if (!chartInstance->c5_delay_v_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_m_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_delay_v, const char_T *c5_identifier,
  real_T c5_y[3])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_delay_v), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_b_delay_v);
}

static void c5_n_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv6[3];
  int32_T c5_i28;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_delay_v_not_empty = false;
  } else {
    chartInstance->c5_delay_v_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv6, 1, 0, 0U, 1, 0U, 1, 3);
    for (c5_i28 = 0; c5_i28 < 3; c5_i28++) {
      c5_y[c5_i28] = c5_dv6[c5_i28];
    }
  }

  sf_mex_destroy(&c5_u);
}

static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_delay_v;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i29;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_delay_v = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_delay_v), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_b_delay_v);
  for (c5_i29 = 0; c5_i29 < 3; c5_i29++) {
    (*(real_T (*)[3])c5_outData)[c5_i29] = c5_y[c5_i29];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i30;
  real_T c5_b_inData[3];
  int32_T c5_i31;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i30 = 0; c5_i30 < 3; c5_i30++) {
    c5_b_inData[c5_i30] = (*(real_T (*)[3])c5_inData)[c5_i30];
  }

  for (c5_i31 = 0; c5_i31 < 3; c5_i31++) {
    c5_u[c5_i31] = c5_b_inData[c5_i31];
  }

  c5_y = NULL;
  if (!chartInstance->c5_yin_d_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_o_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_yin_d, const char_T *c5_identifier, real_T
  c5_y[3])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_yin_d), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_b_yin_d);
}

static void c5_p_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv7[3];
  int32_T c5_i32;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_yin_d_not_empty = false;
  } else {
    chartInstance->c5_yin_d_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv7, 1, 0, 0U, 1, 0U, 1, 3);
    for (c5_i32 = 0; c5_i32 < 3; c5_i32++) {
      c5_y[c5_i32] = c5_dv7[c5_i32];
    }
  }

  sf_mex_destroy(&c5_u);
}

static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_yin_d;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i33;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_yin_d = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_yin_d), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_b_yin_d);
  for (c5_i33 = 0; c5_i33 < 3; c5_i33++) {
    (*(real_T (*)[3])c5_outData)[c5_i33] = c5_y[c5_i33];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  if (!chartInstance->c5_i_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_q_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_i, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_i), &c5_thisId);
  sf_mex_destroy(&c5_b_i);
  return c5_y;
}

static real_T c5_r_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d4;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_i_not_empty = false;
  } else {
    chartInstance->c5_i_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d4, 1, 0, 0U, 0, 0U, 0);
    c5_y = c5_d4;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_i;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_i = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_i), &c5_thisId);
  sf_mex_destroy(&c5_b_i);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_feval;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_feval = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_feval), &c5_thisId);
  sf_mex_destroy(&c5_feval);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  c5_struct_GS2RmkGZ5GnB7UItqpfzDB c5_u;
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  int32_T c5_i34;
  real_T c5_e_u[3];
  const mxArray *c5_e_y = NULL;
  int32_T c5_i35;
  real_T c5_f_u[3];
  const mxArray *c5_f_y = NULL;
  int32_T c5_i36;
  real_T c5_g_u[3];
  const mxArray *c5_g_y = NULL;
  int32_T c5_i37;
  real_T c5_h_u[3];
  const mxArray *c5_h_y = NULL;
  int32_T c5_i38;
  real_T c5_i_u[5];
  const mxArray *c5_i_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(c5_struct_GS2RmkGZ5GnB7UItqpfzDB *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_b_u = c5_u.i;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_b_y, "i", "i", 0);
  c5_c_u = c5_u.count;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_c_y, "count", "count", 0);
  c5_d_u = c5_u.sen_num;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_d_y, "sen_num", "sen_num", 0);
  for (c5_i34 = 0; c5_i34 < 3; c5_i34++) {
    c5_e_u[c5_i34] = c5_u.yin[c5_i34];
  }

  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_e_u, 0, 0U, 1U, 0U, 2, 1, 3),
                false);
  sf_mex_addfield(c5_y, c5_e_y, "yin", "yin", 0);
  for (c5_i35 = 0; c5_i35 < 3; c5_i35++) {
    c5_f_u[c5_i35] = c5_u.yin_d[c5_i35];
  }

  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_f_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_y, c5_f_y, "yin_d", "yin_d", 0);
  for (c5_i36 = 0; c5_i36 < 3; c5_i36++) {
    c5_g_u[c5_i36] = c5_u.delay_v[c5_i36];
  }

  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_g_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_y, c5_g_y, "delay_v", "delay_v", 0);
  for (c5_i37 = 0; c5_i37 < 3; c5_i37++) {
    c5_h_u[c5_i37] = c5_u.ynd_tmp[c5_i37];
  }

  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_h_u, 0, 0U, 1U, 0U, 2, 1, 3),
                false);
  sf_mex_addfield(c5_y, c5_h_y, "ynd_tmp", "ynd_tmp", 0);
  for (c5_i38 = 0; c5_i38 < 5; c5_i38++) {
    c5_i_u[c5_i38] = c5_u.ranD[c5_i38];
  }

  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_i_u, 0, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_addfield(c5_y, c5_i_y, "ranD", "ranD", 0);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_s_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  c5_struct_GS2RmkGZ5GnB7UItqpfzDB *c5_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[8] = { "i", "count", "sen_num", "yin",
    "yin_d", "delay_v", "ynd_tmp", "ranD" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 8, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "i";
  c5_y->i = c5_x_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "i", "i", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "count";
  c5_y->count = c5_x_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "count", "count", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "sen_num";
  c5_y->sen_num = c5_x_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "sen_num", "sen_num", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "yin";
  c5_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "yin",
    "yin", 0)), &c5_thisId, c5_y->yin);
  c5_thisId.fIdentifier = "yin_d";
  c5_u_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "yin_d",
    "yin_d", 0)), &c5_thisId, c5_y->yin_d);
  c5_thisId.fIdentifier = "delay_v";
  c5_u_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "delay_v", "delay_v", 0)), &c5_thisId, c5_y->delay_v);
  c5_thisId.fIdentifier = "ynd_tmp";
  c5_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "ynd_tmp", "ynd_tmp", 0)), &c5_thisId, c5_y->ynd_tmp);
  c5_thisId.fIdentifier = "ranD";
  c5_v_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "ranD",
    "ranD", 0)), &c5_thisId, c5_y->ranD);
  sf_mex_destroy(&c5_u);
}

static void c5_t_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv8[3];
  int32_T c5_i39;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv8, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c5_i39 = 0; c5_i39 < 3; c5_i39++) {
    c5_y[c5_i39] = c5_dv8[c5_i39];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_u_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv9[3];
  int32_T c5_i40;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv9, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c5_i40 = 0; c5_i40 < 3; c5_i40++) {
    c5_y[c5_i40] = c5_dv9[c5_i40];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_v_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[5])
{
  real_T c5_dv10[5];
  int32_T c5_i41;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv10, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c5_i41 = 0; c5_i41 < 5; c5_i41++) {
    c5_y[c5_i41] = c5_dv10[c5_i41];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_structure;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_struct_GS2RmkGZ5GnB7UItqpfzDB c5_y;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_structure = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_structure), &c5_thisId,
                        &c5_y);
  sf_mex_destroy(&c5_b_structure);
  *(c5_struct_GS2RmkGZ5GnB7UItqpfzDB *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i42;
  real_T c5_b_inData[3];
  int32_T c5_i43;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i42 = 0; c5_i42 < 3; c5_i42++) {
    c5_b_inData[c5_i42] = (*(real_T (*)[3])c5_inData)[c5_i42];
  }

  for (c5_i43 = 0; c5_i43 < 3; c5_i43++) {
    c5_u[c5_i43] = c5_b_inData[c5_i43];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_sensor_delay;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i44;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_sensor_delay = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_sensor_delay), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_sensor_delay);
  for (c5_i44 = 0; c5_i44 < 3; c5_i44++) {
    (*(real_T (*)[3])c5_outData)[c5_i44] = c5_y[c5_i44];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_HeatExchanger_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 61, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  const mxArray *c5_rhs3 = NULL;
  const mxArray *c5_lhs3 = NULL;
  const mxArray *c5_rhs4 = NULL;
  const mxArray *c5_lhs4 = NULL;
  const mxArray *c5_rhs5 = NULL;
  const mxArray *c5_lhs5 = NULL;
  const mxArray *c5_rhs6 = NULL;
  const mxArray *c5_lhs6 = NULL;
  const mxArray *c5_rhs7 = NULL;
  const mxArray *c5_lhs7 = NULL;
  const mxArray *c5_rhs8 = NULL;
  const mxArray *c5_lhs8 = NULL;
  const mxArray *c5_rhs9 = NULL;
  const mxArray *c5_lhs9 = NULL;
  const mxArray *c5_rhs10 = NULL;
  const mxArray *c5_lhs10 = NULL;
  const mxArray *c5_rhs11 = NULL;
  const mxArray *c5_lhs11 = NULL;
  const mxArray *c5_rhs12 = NULL;
  const mxArray *c5_lhs12 = NULL;
  const mxArray *c5_rhs13 = NULL;
  const mxArray *c5_lhs13 = NULL;
  const mxArray *c5_rhs14 = NULL;
  const mxArray *c5_lhs14 = NULL;
  const mxArray *c5_rhs15 = NULL;
  const mxArray *c5_lhs15 = NULL;
  const mxArray *c5_rhs16 = NULL;
  const mxArray *c5_lhs16 = NULL;
  const mxArray *c5_rhs17 = NULL;
  const mxArray *c5_lhs17 = NULL;
  const mxArray *c5_rhs18 = NULL;
  const mxArray *c5_lhs18 = NULL;
  const mxArray *c5_rhs19 = NULL;
  const mxArray *c5_lhs19 = NULL;
  const mxArray *c5_rhs20 = NULL;
  const mxArray *c5_lhs20 = NULL;
  const mxArray *c5_rhs21 = NULL;
  const mxArray *c5_lhs21 = NULL;
  const mxArray *c5_rhs22 = NULL;
  const mxArray *c5_lhs22 = NULL;
  const mxArray *c5_rhs23 = NULL;
  const mxArray *c5_lhs23 = NULL;
  const mxArray *c5_rhs24 = NULL;
  const mxArray *c5_lhs24 = NULL;
  const mxArray *c5_rhs25 = NULL;
  const mxArray *c5_lhs25 = NULL;
  const mxArray *c5_rhs26 = NULL;
  const mxArray *c5_lhs26 = NULL;
  const mxArray *c5_rhs27 = NULL;
  const mxArray *c5_lhs27 = NULL;
  const mxArray *c5_rhs28 = NULL;
  const mxArray *c5_lhs28 = NULL;
  const mxArray *c5_rhs29 = NULL;
  const mxArray *c5_lhs29 = NULL;
  const mxArray *c5_rhs30 = NULL;
  const mxArray *c5_lhs30 = NULL;
  const mxArray *c5_rhs31 = NULL;
  const mxArray *c5_lhs31 = NULL;
  const mxArray *c5_rhs32 = NULL;
  const mxArray *c5_lhs32 = NULL;
  const mxArray *c5_rhs33 = NULL;
  const mxArray *c5_lhs33 = NULL;
  const mxArray *c5_rhs34 = NULL;
  const mxArray *c5_lhs34 = NULL;
  const mxArray *c5_rhs35 = NULL;
  const mxArray *c5_lhs35 = NULL;
  const mxArray *c5_rhs36 = NULL;
  const mxArray *c5_lhs36 = NULL;
  const mxArray *c5_rhs37 = NULL;
  const mxArray *c5_lhs37 = NULL;
  const mxArray *c5_rhs38 = NULL;
  const mxArray *c5_lhs38 = NULL;
  const mxArray *c5_rhs39 = NULL;
  const mxArray *c5_lhs39 = NULL;
  const mxArray *c5_rhs40 = NULL;
  const mxArray *c5_lhs40 = NULL;
  const mxArray *c5_rhs41 = NULL;
  const mxArray *c5_lhs41 = NULL;
  const mxArray *c5_rhs42 = NULL;
  const mxArray *c5_lhs42 = NULL;
  const mxArray *c5_rhs43 = NULL;
  const mxArray *c5_lhs43 = NULL;
  const mxArray *c5_rhs44 = NULL;
  const mxArray *c5_lhs44 = NULL;
  const mxArray *c5_rhs45 = NULL;
  const mxArray *c5_lhs45 = NULL;
  const mxArray *c5_rhs46 = NULL;
  const mxArray *c5_lhs46 = NULL;
  const mxArray *c5_rhs47 = NULL;
  const mxArray *c5_lhs47 = NULL;
  const mxArray *c5_rhs48 = NULL;
  const mxArray *c5_lhs48 = NULL;
  const mxArray *c5_rhs49 = NULL;
  const mxArray *c5_lhs49 = NULL;
  const mxArray *c5_rhs50 = NULL;
  const mxArray *c5_lhs50 = NULL;
  const mxArray *c5_rhs51 = NULL;
  const mxArray *c5_lhs51 = NULL;
  const mxArray *c5_rhs52 = NULL;
  const mxArray *c5_lhs52 = NULL;
  const mxArray *c5_rhs53 = NULL;
  const mxArray *c5_lhs53 = NULL;
  const mxArray *c5_rhs54 = NULL;
  const mxArray *c5_lhs54 = NULL;
  const mxArray *c5_rhs55 = NULL;
  const mxArray *c5_lhs55 = NULL;
  const mxArray *c5_rhs56 = NULL;
  const mxArray *c5_lhs56 = NULL;
  const mxArray *c5_rhs57 = NULL;
  const mxArray *c5_lhs57 = NULL;
  const mxArray *c5_rhs58 = NULL;
  const mxArray *c5_lhs58 = NULL;
  const mxArray *c5_rhs59 = NULL;
  const mxArray *c5_lhs59 = NULL;
  const mxArray *c5_rhs60 = NULL;
  const mxArray *c5_lhs60 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1388481696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c5_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c5_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c5_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c5_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("fopen"), "name", "name", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fopen.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c5_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fopen.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("fileManager"), "name", "name",
                  8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871902U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c5_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.errorIf"),
                  "name", "name", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/errorIf.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1334093538U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c5_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c5_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m!STANDALONE"),
                  "context", "context", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isequal"), "name", "name", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c5_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c5_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnan"), "name", "name", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c5_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c5_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("fprintf"), "name", "name", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871902U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c5_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isequal"), "name", "name", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c5_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c5_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("upper"), "name", "name", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c5_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_string_transform"), "name",
                  "name", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c5_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c5_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_charmax"), "name", "name",
                  21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c5_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c5_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c5_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_charmax"), "name", "name",
                  24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c5_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("colon"), "name", "name", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c5_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("colon"), "name", "name", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c5_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c5_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c5_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("floor"), "name", "name", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c5_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c5_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c5_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmin"), "name", "name", 32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c5_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c5_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c5_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmin"), "name", "name", 35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c5_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c5_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c5_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c5_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c5_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.unsignedClass"),
                  "name", "name", 40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c5_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c5_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 42);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 42);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c5_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 43);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 43);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c5_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 44);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  44);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c5_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 45);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 45);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c5_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 46);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c5_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 47);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 47);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c5_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 48);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 48);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c5_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "name", "name", 49);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1319751568U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c5_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 50);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("fidCheck"), "name", "name", 50);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871902U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c5_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("upper"), "name", "name", 51);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c5_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 52);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 52);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c5_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 53);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 53);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c5_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 54);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 54);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c5_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 55);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 55);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c5_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 56);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 56);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c5_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 57);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 57);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c5_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 58);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("fclose"), "name", "name", 58);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c5_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("fidCheck"), "name", "name", 59);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871902U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c5_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "context",
                  "context", 60);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("fileManager"), "name", "name",
                  60);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381871902U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c5_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs60), "lhs", "lhs",
                  60);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
  sf_mex_destroy(&c5_rhs3);
  sf_mex_destroy(&c5_lhs3);
  sf_mex_destroy(&c5_rhs4);
  sf_mex_destroy(&c5_lhs4);
  sf_mex_destroy(&c5_rhs5);
  sf_mex_destroy(&c5_lhs5);
  sf_mex_destroy(&c5_rhs6);
  sf_mex_destroy(&c5_lhs6);
  sf_mex_destroy(&c5_rhs7);
  sf_mex_destroy(&c5_lhs7);
  sf_mex_destroy(&c5_rhs8);
  sf_mex_destroy(&c5_lhs8);
  sf_mex_destroy(&c5_rhs9);
  sf_mex_destroy(&c5_lhs9);
  sf_mex_destroy(&c5_rhs10);
  sf_mex_destroy(&c5_lhs10);
  sf_mex_destroy(&c5_rhs11);
  sf_mex_destroy(&c5_lhs11);
  sf_mex_destroy(&c5_rhs12);
  sf_mex_destroy(&c5_lhs12);
  sf_mex_destroy(&c5_rhs13);
  sf_mex_destroy(&c5_lhs13);
  sf_mex_destroy(&c5_rhs14);
  sf_mex_destroy(&c5_lhs14);
  sf_mex_destroy(&c5_rhs15);
  sf_mex_destroy(&c5_lhs15);
  sf_mex_destroy(&c5_rhs16);
  sf_mex_destroy(&c5_lhs16);
  sf_mex_destroy(&c5_rhs17);
  sf_mex_destroy(&c5_lhs17);
  sf_mex_destroy(&c5_rhs18);
  sf_mex_destroy(&c5_lhs18);
  sf_mex_destroy(&c5_rhs19);
  sf_mex_destroy(&c5_lhs19);
  sf_mex_destroy(&c5_rhs20);
  sf_mex_destroy(&c5_lhs20);
  sf_mex_destroy(&c5_rhs21);
  sf_mex_destroy(&c5_lhs21);
  sf_mex_destroy(&c5_rhs22);
  sf_mex_destroy(&c5_lhs22);
  sf_mex_destroy(&c5_rhs23);
  sf_mex_destroy(&c5_lhs23);
  sf_mex_destroy(&c5_rhs24);
  sf_mex_destroy(&c5_lhs24);
  sf_mex_destroy(&c5_rhs25);
  sf_mex_destroy(&c5_lhs25);
  sf_mex_destroy(&c5_rhs26);
  sf_mex_destroy(&c5_lhs26);
  sf_mex_destroy(&c5_rhs27);
  sf_mex_destroy(&c5_lhs27);
  sf_mex_destroy(&c5_rhs28);
  sf_mex_destroy(&c5_lhs28);
  sf_mex_destroy(&c5_rhs29);
  sf_mex_destroy(&c5_lhs29);
  sf_mex_destroy(&c5_rhs30);
  sf_mex_destroy(&c5_lhs30);
  sf_mex_destroy(&c5_rhs31);
  sf_mex_destroy(&c5_lhs31);
  sf_mex_destroy(&c5_rhs32);
  sf_mex_destroy(&c5_lhs32);
  sf_mex_destroy(&c5_rhs33);
  sf_mex_destroy(&c5_lhs33);
  sf_mex_destroy(&c5_rhs34);
  sf_mex_destroy(&c5_lhs34);
  sf_mex_destroy(&c5_rhs35);
  sf_mex_destroy(&c5_lhs35);
  sf_mex_destroy(&c5_rhs36);
  sf_mex_destroy(&c5_lhs36);
  sf_mex_destroy(&c5_rhs37);
  sf_mex_destroy(&c5_lhs37);
  sf_mex_destroy(&c5_rhs38);
  sf_mex_destroy(&c5_lhs38);
  sf_mex_destroy(&c5_rhs39);
  sf_mex_destroy(&c5_lhs39);
  sf_mex_destroy(&c5_rhs40);
  sf_mex_destroy(&c5_lhs40);
  sf_mex_destroy(&c5_rhs41);
  sf_mex_destroy(&c5_lhs41);
  sf_mex_destroy(&c5_rhs42);
  sf_mex_destroy(&c5_lhs42);
  sf_mex_destroy(&c5_rhs43);
  sf_mex_destroy(&c5_lhs43);
  sf_mex_destroy(&c5_rhs44);
  sf_mex_destroy(&c5_lhs44);
  sf_mex_destroy(&c5_rhs45);
  sf_mex_destroy(&c5_lhs45);
  sf_mex_destroy(&c5_rhs46);
  sf_mex_destroy(&c5_lhs46);
  sf_mex_destroy(&c5_rhs47);
  sf_mex_destroy(&c5_lhs47);
  sf_mex_destroy(&c5_rhs48);
  sf_mex_destroy(&c5_lhs48);
  sf_mex_destroy(&c5_rhs49);
  sf_mex_destroy(&c5_lhs49);
  sf_mex_destroy(&c5_rhs50);
  sf_mex_destroy(&c5_lhs50);
  sf_mex_destroy(&c5_rhs51);
  sf_mex_destroy(&c5_lhs51);
  sf_mex_destroy(&c5_rhs52);
  sf_mex_destroy(&c5_lhs52);
  sf_mex_destroy(&c5_rhs53);
  sf_mex_destroy(&c5_lhs53);
  sf_mex_destroy(&c5_rhs54);
  sf_mex_destroy(&c5_lhs54);
  sf_mex_destroy(&c5_rhs55);
  sf_mex_destroy(&c5_lhs55);
  sf_mex_destroy(&c5_rhs56);
  sf_mex_destroy(&c5_lhs56);
  sf_mex_destroy(&c5_rhs57);
  sf_mex_destroy(&c5_lhs57);
  sf_mex_destroy(&c5_rhs58);
  sf_mex_destroy(&c5_lhs58);
  sf_mex_destroy(&c5_rhs59);
  sf_mex_destroy(&c5_lhs59);
  sf_mex_destroy(&c5_rhs60);
  sf_mex_destroy(&c5_lhs60);
}

static const mxArray *c5_emlrt_marshallOut(const char * c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_u)), false);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static real_T c5_fopen(SFc5_HeatExchangerInstanceStruct *chartInstance)
{
  return c5_fileManager(chartInstance);
}

static real_T c5_fileManager(SFc5_HeatExchangerInstanceStruct *chartInstance)
{
  int32_T c5_i45;
  static char_T c5_cv4[5] = { 'f', 'o', 'p', 'e', 'n' };

  char_T c5_u[5];
  const mxArray *c5_y = NULL;
  int32_T c5_i46;
  static char_T c5_filename[23] = { 'c', 'o', 'n', 't', 'r', 'o', 'l', '_', 's',
    'e', 'n', 's', 'o', 'r', '_', 'd', 'a', 't', 'a', '.', 't', 'x', 't' };

  char_T c5_b_u[23];
  const mxArray *c5_b_y = NULL;
  char_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  c5_isequal(chartInstance);
  for (c5_i45 = 0; c5_i45 < 5; c5_i45++) {
    c5_u[c5_i45] = c5_cv4[c5_i45];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 5), false);
  for (c5_i46 = 0; c5_i46 < 23; c5_i46++) {
    c5_b_u[c5_i46] = c5_filename[c5_i46];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                false);
  c5_c_u = 'a';
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 10, 0U, 0U, 0U, 0), false);
  return c5_w_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 3U, 14, c5_y, 14, c5_b_y, 14,
     c5_c_y), "feval");
}

static void c5_isequal(SFc5_HeatExchangerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_fprintf(SFc5_HeatExchangerInstanceStruct *chartInstance, real_T
  c5_fileID, real_T c5_varargin_1)
{
  boolean_T c5_cond;
  int32_T c5_i47;
  static char_T c5_cv5[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 't',
    'i', 'm', 'p', 'l', 'e', 'm', 'e', 'n', 't', 'e', 'd', '_', 'm', 'x' };

  char_T c5_u[24];
  const mxArray *c5_y = NULL;
  boolean_T c5_b_cond;
  int32_T c5_i48;
  static char_T c5_cv6[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'F', 'i', 'l',
    'e', 'I', 'O', ':', 'I', 'n', 'v', 'a', 'l', 'i', 'd', 'F', 'i', 'd' };

  char_T c5_b_u[24];
  const mxArray *c5_b_y = NULL;
  int32_T c5_i49;
  static char_T c5_cv7[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c5_c_u[7];
  const mxArray *c5_c_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  int32_T c5_i50;
  static char_T c5_formatSpec[4] = { '%', 'f', '\\', 'n' };

  char_T c5_e_u[4];
  const mxArray *c5_e_y = NULL;
  real_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_cfmt = NULL;
  const mxArray *c5_convs = NULL;
  c5_isequal(chartInstance);
  c5_cond = (c5_fileID != 0.0);
  if (c5_cond) {
  } else {
    for (c5_i47 = 0; c5_i47 < 24; c5_i47++) {
      c5_u[c5_i47] = c5_cv5[c5_i47];
    }

    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c5_y));
  }

  c5_b_cond = (c5_fileID > -1.0);
  if (c5_b_cond) {
  } else {
    for (c5_i48 = 0; c5_i48 < 24; c5_i48++) {
      c5_b_u[c5_i48] = c5_cv6[c5_i48];
    }

    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c5_b_y));
  }

  for (c5_i49 = 0; c5_i49 < 7; c5_i49++) {
    c5_c_u[c5_i49] = c5_cv7[c5_i49];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c5_d_u = c5_fileID;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  for (c5_i50 = 0; c5_i50 < 4; c5_i50++) {
    c5_e_u[c5_i50] = c5_formatSpec[c5_i50];
  }

  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_e_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  c5_f_u = c5_varargin_1;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), false);
  c5_w_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14,
    c5_c_y, 14, c5_d_y, 14, c5_e_y, 14, c5_f_y), "feval");
  sf_mex_destroy(&c5_cfmt);
  sf_mex_destroy(&c5_convs);
}

static void c5_fclose(SFc5_HeatExchangerInstanceStruct *chartInstance, real_T
                      c5_fileID)
{
  c5_b_fileManager(chartInstance, c5_fileID);
}

static int32_T c5_b_fileManager(SFc5_HeatExchangerInstanceStruct *chartInstance,
  real_T c5_varargin_1)
{
  int32_T c5_f;
  real_T c5_fid;
  int32_T c5_i51;
  static char_T c5_cv8[6] = { 'f', 'c', 'l', 'o', 's', 'e' };

  char_T c5_u[6];
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_failp = NULL;
  c5_fid = c5_varargin_1;
  c5_isequal(chartInstance);
  for (c5_i51 = 0; c5_i51 < 6; c5_i51++) {
    c5_u[c5_i51] = c5_cv8[c5_i51];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 6), false);
  c5_b_u = c5_fid;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_failp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "logical", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "feval", 1U, 2U, 14, c5_y, 14, c5_b_y)), false);
  if (c5_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_failp), "failp")) {
    c5_f = -1;
  } else {
    c5_f = 0;
  }

  sf_mex_destroy(&c5_failp);
  return c5_f;
}

static real_T c5_w_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_feval, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_feval), &c5_thisId);
  sf_mex_destroy(&c5_feval);
  return c5_y;
}

static real_T c5_x_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d5;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d5, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d5;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static boolean_T c5_y_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_failp, const char_T *c5_identifier)
{
  boolean_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_failp), &c5_thisId);
  sf_mex_destroy(&c5_failp);
  return c5_y;
}

static boolean_T c5_ab_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  boolean_T c5_y;
  boolean_T c5_b0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_b0, 1, 11, 0U, 0, 0U, 0);
  c5_y = c5_b0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static const mxArray *c5_m_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_bb_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i52;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i52, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i52;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_cb_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_HeatExchanger, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_db_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_HeatExchanger), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_HeatExchanger);
  return c5_y;
}

static uint8_T c5_db_emlrt_marshallIn(SFc5_HeatExchangerInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_HeatExchangerInstanceStruct
  *chartInstance)
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

void sf_c5_HeatExchanger_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1242605821U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1563522967U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2929257515U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1387104000U);
}

mxArray *sf_c5_HeatExchanger_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("HSfer62eynyK0VyIKcPX5C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_HeatExchanger_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_HeatExchanger_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_HeatExchanger(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[14],T\"control_delay_vector\",},{M[1],M[5],T\"control_signal_vector\",},{M[4],M[0],T\"delay_v\",S'l','i','p'{{M1x2[404 411],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[396 397],M[0],}}},{M[4],M[0],T\"last_senDelay\",S'l','i','p'{{M1x2[479 492],M[0],}}},{M[4],M[0],T\"last_senReading\",S'l','i','p'{{M1x2[463 478],M[0],}}},{M[4],M[0],T\"num\",S'l','i','p'{{M1x2[440 443],M[0],}}},{M[4],M[0],T\"sensor_value\",S'l','i','p'{{M1x2[427 439],M[0],}}},{M[4],M[0],T\"yin\",S'l','i','p'{{M1x2[423 426],M[0],}}},{M[4],M[0],T\"yin_d\",S'l','i','p'{{M1x2[398 403],M[0],}}}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[4],M[0],T\"ynd_tmp\",S'l','i','p'{{M1x2[444 451],M[0],}}},{M[8],M[0],T\"is_active_c5_HeatExchanger\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 12, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_HeatExchanger_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_HeatExchangerInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_HeatExchangerInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _HeatExchangerMachineNumber_,
           5,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"control_yactual_value");
          _SFD_SET_DATA_PROPS(1,1,1,0,"control_ysensor_value");
          _SFD_SET_DATA_PROPS(2,1,1,0,"control_ynetwork_delay");
          _SFD_SET_DATA_PROPS(3,2,0,1,"control_signal_vector");
          _SFD_SET_DATA_PROPS(4,10,0,0,"structure");
          _SFD_SET_DATA_PROPS(5,2,0,1,"control_delay_vector");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,3,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3099);
        _SFD_CV_INIT_EML_IF(0,1,0,673,688,-1,1242);
        _SFD_CV_INIT_EML_IF(0,1,1,1538,1549,-1,1702);
        _SFD_CV_INIT_EML_IF(0,1,2,1763,1787,2003,2280);
        _SFD_CV_INIT_EML_IF(0,1,3,2016,2024,-1,2264);
        _SFD_CV_INIT_EML_FOR(0,1,0,1554,1567,1697);
        _SFD_CV_INIT_EML_FOR(0,1,1,1749,1759,2284);
        _SFD_CV_INIT_EML_FOR(0,1,2,2302,2315,2456);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_j_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_j_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_j_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_j_sf_marshallOut,(MexInFcnForType)c5_j_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_k_sf_marshallOut,(MexInFcnForType)c5_k_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_j_sf_marshallOut,(MexInFcnForType)c5_j_sf_marshallIn);

        {
          real_T *c5_control_yactual_value;
          real_T *c5_control_ysensor_value;
          real_T *c5_control_ynetwork_delay;
          real_T *c5_control_signal_vector;
          real_T *c5_control_delay_vector;
          c5_control_delay_vector = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 2);
          c5_control_signal_vector = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 1);
          c5_control_ynetwork_delay = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 2);
          c5_control_ysensor_value = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 1);
          c5_control_yactual_value = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_control_yactual_value);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_control_ysensor_value);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_control_ynetwork_delay);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_control_signal_vector);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c5_structure);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_control_delay_vector);
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
  return "6QSKLy51AxYr8qrg2qOmDD";
}

static void sf_opaque_initialize_c5_HeatExchanger(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_HeatExchangerInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_HeatExchanger((SFc5_HeatExchangerInstanceStruct*)
    chartInstanceVar);
  initialize_c5_HeatExchanger((SFc5_HeatExchangerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_HeatExchanger(void *chartInstanceVar)
{
  enable_c5_HeatExchanger((SFc5_HeatExchangerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_HeatExchanger(void *chartInstanceVar)
{
  disable_c5_HeatExchanger((SFc5_HeatExchangerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_HeatExchanger(void *chartInstanceVar)
{
  sf_gateway_c5_HeatExchanger((SFc5_HeatExchangerInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_HeatExchanger(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_HeatExchanger
    ((SFc5_HeatExchangerInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_HeatExchanger();/* state var info */
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

extern void sf_internal_set_sim_state_c5_HeatExchanger(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_HeatExchanger();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_HeatExchanger((SFc5_HeatExchangerInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_HeatExchanger(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_HeatExchanger(S);
}

static void sf_opaque_set_sim_state_c5_HeatExchanger(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c5_HeatExchanger(S, st);
}

static void sf_opaque_terminate_c5_HeatExchanger(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_HeatExchangerInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_HeatExchanger_optimization_info();
    }

    finalize_c5_HeatExchanger((SFc5_HeatExchangerInstanceStruct*)
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
  initSimStructsc5_HeatExchanger((SFc5_HeatExchangerInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_HeatExchanger(SimStruct *S)
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
    initialize_params_c5_HeatExchanger((SFc5_HeatExchangerInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_HeatExchanger(SimStruct *S)
{
  /* Actual parameters from chart:
     structure
   */
  const char_T *rtParamNames[] = { "structure" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_HeatExchanger_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(156390770U));
  ssSetChecksum1(S,(1277335941U));
  ssSetChecksum2(S,(3506464760U));
  ssSetChecksum3(S,(274763602U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_HeatExchanger(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_HeatExchanger(SimStruct *S)
{
  SFc5_HeatExchangerInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_HeatExchangerInstanceStruct *)utMalloc(sizeof
    (SFc5_HeatExchangerInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_HeatExchangerInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_HeatExchanger;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_HeatExchanger;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_HeatExchanger;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_HeatExchanger;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_HeatExchanger;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_HeatExchanger;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_HeatExchanger;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_HeatExchanger;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_HeatExchanger;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_HeatExchanger;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_HeatExchanger;
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

void c5_HeatExchanger_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_HeatExchanger(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_HeatExchanger(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_HeatExchanger(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_HeatExchanger_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
