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
int bisMaxItr(double a, double b, double tol);
double derivative(double(*f)(double), double x, double h);
double secant(double(*f)(double), double xa, double xb);
double newton(double(*f)(double), double(*fp)(double), double x);
double bisection(double(*f)(double), double a, double b, int tol, int maxItr);
double fixed1(double(*f)(double), double xn);
double fixed2(double(*f)(double), double xn);