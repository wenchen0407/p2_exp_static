/* Include files */

#include "CoupledTanks_down_sfun.h"
#include "CoupledTanks_down_sfun_debug_macros.h"
#include "c1_CoupledTanks_down.h"
#include "c3_CoupledTanks_down.h"
#include "c5_CoupledTanks_down.h"
#include "c6_CoupledTanks_down.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _CoupledTanks_downMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void CoupledTanks_down_initializer(void)
{
}

void CoupledTanks_down_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_CoupledTanks_down_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_CoupledTanks_down_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_CoupledTanks_down_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_CoupledTanks_down_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_CoupledTanks_down_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_CoupledTanks_down_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3563124979U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(523206083U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1308214658U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2975221851U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2658907577U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2581259307U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(172819029U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(936841478U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_CoupledTanks_down_get_check_sum(mxArray *plhs[]);
          sf_c1_CoupledTanks_down_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_CoupledTanks_down_get_check_sum(mxArray *plhs[]);
          sf_c3_CoupledTanks_down_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_CoupledTanks_down_get_check_sum(mxArray *plhs[]);
          sf_c5_CoupledTanks_down_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_CoupledTanks_down_get_check_sum(mxArray *plhs[]);
          sf_c6_CoupledTanks_down_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4260895566U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2703130584U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3620031602U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1458276751U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CoupledTanks_down_autoinheritance_info( int nlhs, mxArray *
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
        if (strcmp(aiChksum, "dReM6YV1efZUpYcb1KG7PF") == 0) {
          extern mxArray *sf_c1_CoupledTanks_down_get_autoinheritance_info(void);
          plhs[0] = sf_c1_CoupledTanks_down_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "yn3O8TiRdYw2nsFrRiAn4E") == 0) {
          extern mxArray *sf_c3_CoupledTanks_down_get_autoinheritance_info(void);
          plhs[0] = sf_c3_CoupledTanks_down_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "X1YCTJgPJGNDpND3OYAbX") == 0) {
          extern mxArray *sf_c5_CoupledTanks_down_get_autoinheritance_info(void);
          plhs[0] = sf_c5_CoupledTanks_down_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "cQumQuYCdRHKEklAhmyblC") == 0) {
          extern mxArray *sf_c6_CoupledTanks_down_get_autoinheritance_info(void);
          plhs[0] = sf_c6_CoupledTanks_down_get_autoinheritance_info();
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

unsigned int sf_CoupledTanks_down_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_CoupledTanks_down_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_CoupledTanks_down_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_CoupledTanks_down_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_CoupledTanks_down_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_CoupledTanks_down_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_CoupledTanks_down_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_CoupledTanks_down_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_CoupledTanks_down_get_eml_resolved_functions_info();
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

unsigned int sf_CoupledTanks_down_third_party_uses_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "SHAN08ZcrBfPZzjprruiYG") == 0) {
          extern mxArray *sf_c1_CoupledTanks_down_third_party_uses_info(void);
          plhs[0] = sf_c1_CoupledTanks_down_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "AkaVypzSTAxN9BFdAsykfH") == 0) {
          extern mxArray *sf_c3_CoupledTanks_down_third_party_uses_info(void);
          plhs[0] = sf_c3_CoupledTanks_down_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "kfGqVbNn8Vjw6EOZKPBTJ") == 0) {
          extern mxArray *sf_c5_CoupledTanks_down_third_party_uses_info(void);
          plhs[0] = sf_c5_CoupledTanks_down_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "1fs4bQjN4b8oFaDjPhTyiC") == 0) {
          extern mxArray *sf_c6_CoupledTanks_down_third_party_uses_info(void);
          plhs[0] = sf_c6_CoupledTanks_down_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void CoupledTanks_down_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _CoupledTanks_downMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "CoupledTanks_down","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _CoupledTanks_downMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _CoupledTanks_downMachineNumber_,0);
}

void CoupledTanks_down_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_CoupledTanks_down_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "CoupledTanks_down", "CoupledTanks_down");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_CoupledTanks_down_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
