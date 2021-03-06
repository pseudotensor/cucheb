#include <cucheb.h>
/*
  cuchebmatrix_destroy

  This routine frees memory associated with an instance of a cuchebmatrix
  object. The following inputs are required:

    ccm - a reference to an instance of a cuchebmatrix

*/

/* routine to free memory in cuchebmatrix object */
int cuchebmatrix_destroy(cuchebmatrix* ccm){

  // free rowinds
  delete[] ccm->rowinds;

  // free colinds
  delete[] ccm->colinds;

  // free vals
  delete[] ccm->vals;

  // destroy cublas handle
  cublasDestroy(ccm->cublashandle);
 
  // destroy cusparse handle
  cusparseDestroy(ccm->cusparsehandle);
 
  // destroy cusparse matdescr
  cusparseDestroyMatDescr(ccm->matdescr);
 
  // free drowinds
  cudaFree(ccm->drowinds);

  // free dcolinds
  cudaFree(ccm->dcolinds);

  // free dvals
  cudaFree(ccm->dvals);

  // free dtemp
  cudaFree(ccm->dtemp);

  // return  
  return 0;

}
