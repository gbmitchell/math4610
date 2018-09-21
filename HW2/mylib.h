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