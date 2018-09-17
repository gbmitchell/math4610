#include <stdio.h>
#include <math.h>
#include "mylib.h"

double Pi = 3.1415926535897932384626433832795028841971693993751058209749445923;

void smaceps(float *seps, int *ipow) {

	// create an initialize function variables
	// initialized to find machine value near 1.0
	float one = 0.0, appone = 0.0;
	int i = 0;
	one = 1.0;
	*seps = 1.0;
	appone = one + *seps;
	*ipow = 0;

	// loop, dividing by 2 each time to determine when the difference
	//  between one and the approximation is zero in single precision
	for (i = 0; i < 1000; i++) {
		*ipow = *ipow + 1;
		*seps = *seps / 2.0;
		appone = one + *seps;
		if (fabs(appone - one) == 0.0) return;
	}

	// print error message to console if loops more than 1000 times
	// code should never reach this point unless there is an error
	printf("The loop limit has been exceeded");

	return;
}

void dmaceps(double *seps, int *ipow) {

	// create an initialize function variables
	// initialized to find machine value near 1.0
	double one = 0.0, appone = 0.0;
	int i = 0;
	one = 1.0;
	*seps = 1.0;
	appone = one + *seps;
	*ipow = 0;

	// loop, dividing by 2 each time to determine when the difference
	//  between one and the approximation is zero in double precision
	for (i = 0; i < 1000; i++) {
		*ipow = *ipow + 1;
		*seps = *seps / 2.0;
		appone = one + *seps;
		if (fabs(appone - one) == 0.0) return;
	}

	// print error message to console if loops more than 1000 times
	// code should never reach this point unless there is an error
	printf("The loop limit has been exceeded");

	return;
}

double eabs(double v, double u) {
	double e = fabs(u - v);
	return e;
}

double erel(double v, double u) {
	double e = (fabs(u- v)) / (fabs(u));
	return e;
}

// funciton x^2 + 3
double fnct1(double x) {

	double fx = 0.0;
	fx = (x * x) + 3;
	return fx;
}


// function taylor series sin(x)
double fnct2(double x) {

	double fx = 0.0;
	fx = x - ((x * x * x) / 6);
	return fx;
}

// function taylor series d/dx( sin(x) )
double fnct3(double x) {

	double fx = 0.0;
	fx = 1 - ((x * x) / 2);
	return fx;
}

// function x^2 - 3
double fnct4(double x) {

	double fx = 0.0;
	fx = (x * x) - 3;
	return fx;
}

// function d/dx( x^2 - 3 )
double fnct5(double x) {

	double fx = 0.0;
	fx = 2 * x;
	return fx;
}

// function ( sin(Pi * x) )
double fnct6(double x) {

	double fx = 0.0;
	fx = sin(Pi * x);
	return fx;
}

// function d/dx( sin(Pi * x) )
double fnct7(double x) {

	double fx = 0.0;
	fx = Pi * cos(Pi * x);
	return fx;
}


int bisMaxItr(double a, double b, double tol) {

	int x = ((log(tol / fabs(b - a)) / log(2)) / (log(0.5) / log(2))) + 1;
	return x;
}

double derivative(double(*f)(double), double x, double h) {

	double fxx = 0.0;
	fxx = (f(x + h) - f(x)) / (h);
	return fxx;
}

double secant(double(*f)(double), double xa, double xb) {

	double fxn1 = 0.0;
	fxn1 = xb - ((f(xb) * (xb - xa)) / (f(xb) - f(xa)));
	return fxn1;
}

double newton(double(*f)(double), double(*fp)(double), double x) {

	double fxn1 = 0.0;
	fxn1 = x - (f(x)) / (fp(x));
	return fxn1;
}


double bisection(double(*f)(double), double a, double b, int tol, int maxItr) {
	int i = 0;
	double c = 0.0;
	double Fxc = 1.0;
	double Fxa = f(a);
	double Fxb = f(b);
	double root = 0.0;

	if ((Fxa * Fxb) < 0.0) {

		while (maxItr > 0) {

			maxItr--;
			i++;

			c = (a + b) / 2.0;

			Fxc = f(c);

			if ((Fxa * Fxc) < 0.0) {
				b = c;
				Fxb = f(b);
			}
			else if ((Fxa * Fxc) > 0.0) {
				a = c;
				Fxa = f(a);
			}
			else {
				printf("%d\t| %.8e\n", i, c);
				break;
			}
			printf("%d\t| %.8e\n", i, c);
		}

		root = c;

	}
	else if ((Fxa * Fxb) == 0.0) {

		if (Fxa == 0) {
			root = a;
			printf("%d\t| %.8e\n", i, a);
		}
		if (Fxb == 0) {
			root = b;
			printf("%d\t| %.8e\n", i, b);
		}

	}
	else {

		printf("\n\nThere is no root or an even number of roots between the upper and lower initial values.");
		root = 0.0;
	}

	return root;
}


double fixed1(double(*f)(double), double xn) {

	double fxn1 = 0.0;
	fxn1 = xn + f(xn);
	return fxn1;
}

double fixed2(double(*f)(double), double xn) {

	double fxn1 = 0.0;
	fxn1 = xn - f(xn);
	return fxn1;
}
