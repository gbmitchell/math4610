#pragma once
void smaceps(float *seps, int *ipow);
void dmaceps(double *seps, int *ipow);
double eabs(double v, double u);
double erel(double v, double u);
double fnct1(double x);
double fnct2(double x);
double fnct3(double x);
double fnct4(double x);
double fnct5(double x);
double fnct6(double x);
double fnct7(double x);
double fnct8(double x);
double fnct9(double x);
int bisMaxItr(double a, double b, double tol);
double derivative(double(*f)(double), double x, double h, double tol, int maxItr);
double expderivative(double(*f)(double), double x, double h, double tol, int maxItr, double expder);
double secant(double(*f)(double), double xa, double xb, double tol, int maxItr);
double expsecant(double(*f)(double), double xa, double xb, double tol, int maxItr, double exproot);
double newton(double(*f)(double), double(*fp)(double), double x, double tol, int maxItr);
double expnewton(double(*f)(double), double(*fp)(double), double x, double tol, int maxItr, double exproot);
double bisection(double(*f)(double), double a, double b, double tol, int maxItr);
double expbisection(double(*f)(double), double a, double b, double tol, int maxItr, double exproot);
double fixed1(double(*f)(double), double xn, double tol, int maxItr, double exproot);
double fixed2(double(*f)(double), double xn, double tol, int maxItr, double exproot);
double expNewtonHybrid(double(*f)(double), double(*fp)(double), double a, double b, double tol, int maxItr, double exproot);
double expSecantHybrid(double(*f)(double), double a, double b, double tol, int maxItr, double exproot);

// vector and matrix operations
//***********************************************************************************************************************************
void vectorAdd(double *up, double *vp, double *ap, int len);
void vectorSub(double *up, double *vp, double *ap, int len);
void vectorScale(double *up, double *ap, double scale, int len);
double vectorInner(double *up, double *vp, int len);
void vectorCross(double *up, double *vp, double *ap, int len);
double vectorNormL1(double *up, int len);
double vectorNormL2(double *up, int len);
double vectorNormInfinity(double *up, int len);
double vectorErrorAbsoluteL1(double *xp, double *yp, int len);
double vectorErrorRelativeL1(double *xp, double *yp, int len);
double vectorErrorAbsoluteL2(double *xp, double *yp, int len);
double vectorErrorRelativeL2(double *xp, double *yp, int len);
double vectorErrorAbsoluteInfinity(double *xp, double *yp, int len);
double vectorErrorRelativeInfinity(double *xp, double *yp, int len);
void matrixAdd(double **A, double **B, double **C, int m, int n);
void matrixSub(double **A, double **B, double **C, int m, int n);
void vectorXmatrix(double **A, double *v, double *u, int m, int n);
void matrixXvectorParallel(double **A, double *v, double *u, int m, int n);
void parallelVectorXmatrix(double **A, double *v, double *u, int m, int n);
void matrixXmatrix(double **A, double **B, double **C, int m, int n);
void parallelMatrixXmatrix(double **A, double **B, double **C, int m, int n);
double traceMatrix(double **A, int m);
void scaleMatrix(double **A, double **C, double s, int m, int n);
void transposeMatrix(double **A, double **C, int m, int n);
double determinantMatrix(double **A, int m);
double determinantMatrixNxN(double **A, int n);
void KroneckerMatrix(double **A, double **B, double **C, int ma, int na, int mb, int nb);
double matrixNormL1(double **a, int len);
double matrixNormFrobenious(double **a, int len);
double matrixNormInfinity(double **a, int len);
void outerProductMatrix(double *x, double *y, double **C, int m, int n);
void unitOrthog(double *v1, double *v2, double *u1, double *u2, int len);
void forwardSub(double **A, double *x, double *b, int n);
void backSub(double **A, double *x, double *b, int n);
void squareGauss(double **A, double *b, int n);
void squareLU(double **A, double **B, int n);
void generalGauss(double **A, double *b, int m, int n);
void GEsolve(double **A, double *x, double *b, int n);
void LUsolve(double **A, double **L, double *x, double *b, int n);
void choleskyLU(double **A, double **B, int n);
void Choleskysolve(double **A, double **U, double *x, double *b, int n);
void printAugMatrix(double **A, double *b, int m, int n);
void printMatrix(double **A, int m, int n);
void printVector(double *v, int n);
double matrixInducedNormL1(double **A, double *v, int n);
double matrixInducedNormInfinity(double **A, double *v, int n);
void uniformMatrix(double **A, double *b, int n);
void jacobi(double **A, double *b, double *x0, double tol, int maxiter, int n);
void jacobiParallel(double **A, double *b, double *x0, double tol, int maxiter, int n);
void gaussSeidel(double **A, double *b, double *x0, double tol, int maxiter, int n);
void gaussSeidelParallel(double **A, double *b, double *x0, double tol, int maxiter, int n);
void gradient(double **A, double *b, double *x0, double tol, int maxiter, int n);
void conjugateGradient(double **A, double *b, double *x0, double tol, int maxiter, int n);
void conjugateGradientParallel(double **A, double *b, double *x0, double tol, int maxiter, int n);
