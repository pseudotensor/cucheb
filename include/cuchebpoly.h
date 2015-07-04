/* header file for cuchebpoly data type */
#ifndef __cuchebpoly_h__ 
#define __cuchebpoly_h__

#include <stdio.h>
#include <math.h>
#include <cuda.h>
#include <cufft.h>

/* double precision pi */
#ifdef DOUBLE_PI
#undef DOUBLE_PI
#define DOUBLE_PI 3.141592653589793238
#else
#define DOUBLE_PI 3.141592653589793238
#endif

/* maximum construction degree */
#ifdef DOUBLE_DEG
#undef DOUBLE_DEG
#define DOUBLE_DEG 128
#else
#define DOUBLE_DEG 128
#endif

/* construction tolerance */
#ifdef DOUBLE_EPS
#undef DOUBLE_EPS
#define DOUBLE_EPS (double) pow(2.0,-8)
#else
#define DOUBLE_EPS (double) pow(2.0,-8)
#endif

/* maximum filter degree */
#ifdef MAX_DOUBLE_DEG
#undef MAX_DOUBLE_DEG
#define MAX_DOUBLE_DEG 50
#else
#define MAX_DOUBLE_DEG 50
#endif

/* cuchebpoly data type */
typedef struct {

  int degree;
  double a;
  double b;
  double coeffs[DOUBLE_DEG+1];

} cuchebpoly;

/* instantiate cuchebpoly object */
int cuchebpoly_init(cuchebpoly* ccp);

/* standard print cuchebpoly object */
int cuchebpoly_print(cuchebpoly* ccp);

/* long print cuchebpoly object */
int cuchebpoly_printlong(cuchebpoly* ccp);

/* second kind Chebyshev points */
int cuchebpoints(double a, double b, double* points);

/* convert values to coefficients */
int cuchebcoeffs(double* coeffs);

/* threshold coefficients */
int cuchebchop(int *degree, double* coeffs);

#endif /* __cuchebpoly_h__ */
