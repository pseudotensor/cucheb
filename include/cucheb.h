#include <cuchebdependencies.h>

#include <cuchebstats.h>
#include <cuchebpoly.h>
#include <cuchebmatrix.h>
#include <cucheblanczos.h>

/* header file for cucheb data type */
#ifndef __cucheb_h__ 
#define __cucheb_h__



/* cuchebutils subroutines */
/* rotation generator */
int cuchebutils_rotation(const double a, const double b, double* c, double* s,
                         double* nrm);

/* function to perform banded symmetric bulge chase */
int cuchebutils_chasebulge(int n, int bwidth, double* bands, int ldbands,
                           double* bulge, double* vecs, int ldvecs);

/* eigenvalues and eigenvectors of 2x2 symmetric matrix */
int cuchebutils_2x2symeig(double a1, double a2, double b, double* e1, double* e2,
                         double* c, double* s);

/* reduce banded symmetric matrix to tridiagonal */
int cuchebutils_bandsymred(int n, int bwidth, double* bands, int ldbands,
                           double* vecs, int ldvecs);

/* eigenvalues and eigenvectors of banded symmetric matrix via QR */
int cuchebutils_bandsymqr(int n, int bwidth, double* bands, int ldbands,
                           double* evals, double* vecs, int ldvecs);



/* cuchebstats subroutines */
/* standard print cuchebstats object */
int cuchebstats_print(cuchebstats* ccs);

/* print cuchebstats objects to file */
int cuchebstats_fileprint(const string& fname, int nummats, string* matnames,
                          cuchebstats* ccstats);



/* cuchebpoly subroutines */
/* instantiate cuchebpoly object */
int cuchebpoly_init(cuchebpoly* ccp);

/* destroy cuchebpoly object */
int cuchebpoly_destroy(cuchebpoly* ccp);

/* standard print cuchebpoly object */
int cuchebpoly_print(cuchebpoly* ccp);

/* long print cuchebpoly object */
int cuchebpoly_printlong(cuchebpoly* ccp);

/* second kind Chebyshev points */
int cuchebpoly_points(double a, double b, cuchebpoly* ccp);

/* convert values to coefficients */
int cuchebpoly_coeffs(cuchebpoly* ccp);

/* threshold coefficients */
int cuchebpoly_chop(cuchebpoly* ccp);

/* routine for creating point filter */
int cuchebpoly_pointfilter(double a, double b, double rho, int order, cuchebpoly* ccp);

/* routine for creating step filter */
int cuchebpoly_stepfilter(double a, double b, double c, double d, int order, cuchebpoly* ccp);

/* routine for creating gaussian filter */
int cuchebpoly_gaussianfilter(double a, double b, double rho, double tau, cuchebpoly* ccp);



/* cuchebmatrix subroutines */
/* instantiate cuchebmatrix object */
int cuchebmatrix_init(const string& mtxfile, cuchebmatrix* ccm);

/* destroy cuchebmatrix object */
int cuchebmatrix_destroy(cuchebmatrix* ccm);

/* print cuchebmatrix object */
int cuchebmatrix_print(cuchebmatrix* ccm);

/* longprint cuchebmatrix object */
int cuchebmatrix_printlong(cuchebmatrix* ccm);

/* gpuprint cuchebmatrix object */
int cuchebmatrix_gpuprint(cuchebmatrix* ccm);

/* routine for sorting entries */
int cuchebmatrix_sort(cuchebmatrix* ccm);

/* routine for converting to csr format */
int cuchebmatrix_csr(cuchebmatrix* ccm);

/* routine for mv multiply on GPU */
int cuchebmatrix_mv(cuchebmatrix* ccm, double* alpha, double* x, double* beta,
                    double* y);

/* routine for poly mv multiply on GPU */
int cuchebmatrix_polymv(cuchebmatrix* ccm, cuchebpoly* ccp, double* x, double* y);

/* routine for estimating spectral interval */
int cuchebmatrix_specint(cuchebmatrix* ccm);

/* filtered lanczos routine for isolated point*/
int cuchebmatrix_filteredlanczos(int neigs, double shift, int bsize, 
                                      cuchebmatrix* ccm, cucheblanczos* ccl);

/* filtered lanczos routine for isolated point with statistics*/
int cuchebmatrix_filteredlanczos(int neigs, double shift, int bsize, 
                                 cuchebmatrix* ccm, cucheblanczos* ccl,
                                 cuchebstats* ccs);

/* filtered lanczos routine for interval */
int cuchebmatrix_filteredlanczos(double lbnd, double ubnd, int bsize, cuchebmatrix* ccm, 
                                 cucheblanczos* ccl);

/* same routine as above but with statistics variable */
int cuchebmatrix_filteredlanczos(double lbnd, double ubnd, int bsize, 
                                 cuchebmatrix* ccm, cucheblanczos* ccl, 
                                 cuchebstats* ccs);



/* cucheblanczos subroutines */
/* instantiate cucheblanczos object */
int cucheblanczos_init(int bsize, int nblocks, cuchebmatrix* ccm, cucheblanczos* ccl);

/* destroy cucheblanczos object */
int cucheblanczos_destroy(cucheblanczos* ccl);

/* print cucheblanczos object */
int cucheblanczos_print(cucheblanczos* ccl);

/* set cucheblanczos starting vectors */
int cucheblanczos_startvecs(cucheblanczos* ccl);

/* arnoldi run using cuchebmatrix */
int cucheblanczos_arnoldi(int nsteps, cuchebmatrix* ccm, cucheblanczos* ccl);

/* filtered arnoldi run using cuchebmatrix */
int cucheblanczos_filteredarnoldi(int nsteps, cuchebmatrix* ccm, cuchebpoly* ccp,
                                  cucheblanczos* ccl, cuchebstats* ccstats);

/* compute rayleigh quotients */
int cucheblanczos_rayleigh(cuchebmatrix* ccm, cucheblanczos* ccl);

/* reset Arnoldi vectors */
int cucheblanczos_reset(cuchebmatrix* ccm, cucheblanczos* ccl);

/* check convergence and sort using interval bounds */
int cucheblanczos_checkconvergence(int* numconv, double lb, double ub,
                                   cuchebmatrix* ccm, cucheblanczos* ccl);



#endif /* __cucheb_h__ */
