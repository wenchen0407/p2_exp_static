/* Include files */

#include "CoupledTanks_WCPS_v2_sfun.h"
#include "CoupledTanks_WCPS_v2_sfun_debug_macros.h"
#include "c1_CoupledTanks_WCPS_v2.h"
#include "c2_CoupledTanks_WCPS_v2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _CoupledTanks_WCPS_v2MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void CoupledTanks_WCPS_v2_initializer(void)
{
}

void CoupledTanks_WCPS_v2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_CoupledTanks_WCPS_v2_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_CoupledTanks_WCPS_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_CoupledTanks_WCPS_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_CoupledTanks_WCPS_v2_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2797835799U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2991837863U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3346786847U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(921297544U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1298607680U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3806914221U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3976791122U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3093983316U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_CoupledTanks_WCPS_v2_get_check_sum(mxArray *plhs[]);
          sf_c1_CoupledTanks_WCPS_v2_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_CoupledTanks_WCPS_v2_get_check_sum(mxArray *plhs[]);
          sf_c2_CoupledTanks_WCPS_v2_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1764838350U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3410240878U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(118138738U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(243351119U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3529822148U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2074918933U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4216200282U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1134132851U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CoupledTanks_WCPS_v2_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "WCnnMNzBEC5Sx5tYN3eybC") == 0) {
          extern mxArray *sf_c1_CoupledTanks_WCPS_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_CoupledTanks_WCPS_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "WVMfOLdl8qX0N7Erg8fCZH") == 0) {
          extern mxArray *sf_c2_CoupledTanks_WCPS_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_CoupledTanks_WCPS_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CoupledTanks_WCPS_v2_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_CoupledTanks_WCPS_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_CoupledTanks_WCPS_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_CoupledTanks_WCPS_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_CoupledTanks_WCPS_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CoupledTanks_WCPS_v2_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "yEKnO8P0TcChCJkm773AxD") == 0) {
          extern mxArray *sf_c1_CoupledTanks_WCPS_v2_third_party_uses_info(void);
          plhs[0] = sf_c1_CoupledTanks_WCPS_v2_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "UVhIJusNvkEkUHoW033G3E") == 0) {
          extern mxArray *sf_c2_CoupledTanks_WCPS_v2_third_party_uses_info(void);
          plhs[0] = sf_c2_CoupledTanks_WCPS_v2_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void CoupledTanks_WCPS_v2_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _CoupledTanks_WCPS_v2MachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"CoupledTanks_WCPS_v2","sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _CoupledTanks_WCPS_v2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _CoupledTanks_WCPS_v2MachineNumber_,0);
}

void CoupledTanks_WCPS_v2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_CoupledTanks_WCPS_v2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "CoupledTanks_WCPS_v2", "CoupledTanks_WCPS_v2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_CoupledTanks_WCPS_v2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
