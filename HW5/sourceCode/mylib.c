#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mylib.h"
#include <time.h>

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

// function ( x^2 - 3 )/10
double fnct8(double x) {

	double fx = 0.0;
	fx = ( (x * x) - 3) / 10.0;
	return fx;
}

// function sin(Pi * x)/10
double fnct9(double x) {

	double fx = 0.0;
	fx = ( sin(Pi * x) ) / 10.0;
	return fx;
}

int bisMaxItr(double a, double b, double tol) {

	int x = ((log(tol / fabs(b - a)) / log(2)) / (log(0.5) / log(2)));
	if (x < 1) x = 1;
	return x;
}


double fixed1(double(*f)(double), double xn, double tol, int maxItr, double exproot) {

	int i = 0;
	double fxn1 = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;

	printf("fixed point approximation for f(x) = sin(Pi*x), where g(x) = x + ( f(x)/10 )\n");
	printf("tolerance =  %.3e\n", tol);
	printf("Initial value = %.1lf\n", xn);
	printf("expected root = %.8lf\n\n", exproot);
	printf("i\t| Xn\t\t\t| Xn+1\t\t\t|  e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	eabsolute = 10.0 * tol;

	while ((eabsolute > tol) && (maxItr > 0)) {

		maxItr--;
		i++;

		fxn1 = xn + f(xn);
		eabsolute = eabs(fxn1, exproot);
		erelative = erel(fxn1, exproot);

		printf("%d\t| %.8e\t| %.8e\t| %.3e\t| %.3e\n", i, xn, fxn1, eabsolute, erelative);

		xn = fxn1;
	}

	printf("\n\n\n");

	return fxn1;
}


double fixed2(double(*f)(double), double xn, double tol, int maxItr, double exproot) {

	int i = 0;
	double fxn1 = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;

	printf("fixed point approximation for f(x) = ( x^2 - 3 ), where g(x) = x - ( f(x)/10 )\n");
	printf("tolerance =  %.3e\n", tol);
	printf("Initial value = %lf\n", xn);
	printf("expected root = %.8lf\n\n", exproot);
	printf("i\t| Xn\t\t\t| Xn+1\t\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	eabsolute = 10.0 * tol;

	while ((eabsolute > tol) && (maxItr > 0)) {

		maxItr--;
		i++;

		fxn1 = xn - f(xn);

		eabsolute = eabs(fxn1, exproot);
		erelative = erel(fxn1, exproot);

		printf("%d\t| %.8e\t| %.8e\t| %.3e\t| %.3e\n", i, xn, fxn1, eabsolute, erelative);

		xn = fxn1;
	}

	printf("\n\n\n");

	return fxn1;
}


double expderivative(double(*f)(double), double x, double h, double tol, int maxItr, double expder) {

	int i = 0;
	double fp = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;

	printf("tolerance =  %.3e\n", tol);
	printf("x = %lf\n", x);
	printf("expected derivative = %.12lf\n\n", expder);

	printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	eabsolute = 10.0 * tol;

	while ((eabsolute > tol) && maxItr > 0) {

		maxItr--;
		i++;

		fp = (f(x + h) - f(x)) / (h);

		eabsolute = eabs(fp, expder);
		erelative = erel(fp, expder);

		printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fp, h, eabsolute, erelative);
		h = h / 2.0;

	}
	printf("\n\n\n");

	return fp;
}


double expbisection(double(*f)(double), double a, double b, double tol, int maxItr, double exproot) {
	int i = 0;
	double c = 0.0;
	double Fxc = 1.0;
	double Fxa = f(a);
	double Fxb = f(b);
	double root = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;

	printf("max itterations = %d, for tollerence = %.3e\n", maxItr, tol);
	printf("Lower initial value = %.1lf, Upper initial value = %.1lf\n", a, b);
	printf("expected root = %.12lf\n\n", exproot);
	printf("i\t| root bisection\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

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
				eabsolute = eabs(c, exproot);
				erelative = erel(c, exproot);
				printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, c, eabsolute, erelative);
				break;
			}
			eabsolute = eabs(c, exproot);
			erelative = erel(c, exproot);
			printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, c, eabsolute, erelative);
		}

		root = c;

	}
	else if ((Fxa * Fxb) == 0.0) {

		if (Fxa == 0) {
			root = a;
			eabsolute = eabs(a, exproot);
			erelative = erel(a, exproot);
			printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, a, eabsolute, erelative);
		}
		if (Fxb == 0) {
			root = b;
			eabsolute = eabs(b, exproot);
			erelative = erel(b, exproot);
			printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, b, eabsolute, erelative);
		}

	}
	else {

		printf("\n\nThere is no root or an even number of roots between the upper and lower initial values.");
		root = 0.0;
	}

	printf("\n\n\n");

	return root;
}


double expnewton(double(*f)(double), double(*fp)(double), double x, double tol, int maxItr, double exproot) {

	int i = 0;
	double fxn1 = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;

	printf("tolerance =  %.3e\n", tol);
	printf("Initial value = %lf\n", x);
	printf("expected root = %.12lf\n\n", exproot);
	printf("i\t| root newton\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	eabsolute = 10.0 * tol;

	while ((eabsolute > tol) && maxItr > 0) {

		maxItr--;
		i++;

		fxn1 = x - (f(x)) / (fp(x));

		eabsolute = eabs(fxn1, exproot);
		erelative = erel(fxn1, exproot);

		printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, fxn1, eabsolute, erelative);

		x = fxn1;
	}

	printf("\n\n\n");


	return fxn1;
}


double expsecant(double(*f)(double), double xa, double xb, double tol, int maxItr, double exproot) {

	int i = 0;
	double fxn1 = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;

	printf("tolerance =  %.3e\n", tol);
	printf("Initial values = %lf and %lf\n", xa, xb);
	printf("expected root = %.12lf\n\n", exproot);

	printf("i\t| root secant\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	eabsolute = 10.0 * tol;

	while ((eabsolute > tol) && maxItr > 0) {

		maxItr--;
		i++;


		fxn1 = xb - ((f(xb) * (xb - xa)) / (f(xb) - f(xa)));

		eabsolute = eabs(fxn1, exproot);
		erelative = erel(fxn1, exproot);

		printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, fxn1, eabsolute, erelative);

		xa = xb;
		xb = fxn1;

	}

	printf("\n\n\n");

	return fxn1;
}



double expNewtonHybrid(double(*f)(double), double(*fp)(double), double a, double b, double tol, int maxItr, double exproot) {
	int i = 0, j = 0;
	double c = 0.0;
	double Fxc = 1.0;
	double Fxa = f(a);
	double Fxb = f(b);
	double root = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;
	double initialGuess = 0.0;
	double prec1 = 0.1;
	int maxIteration = 0;

	eabsolute = 10.0 * tol;

	while ((eabsolute > tol) && maxItr > 0) {

		maxItr--;
		j++;

		initialGuess = (a + b) / 2;
		maxIteration = 1;

		root = expnewton(f, fp, initialGuess, tol, maxIteration, exproot);
		
		if (root >= a && root <= b) {
			maxIteration = 10;
			initialGuess = root;
			root = expnewton(f, fp, initialGuess, tol, maxIteration, exproot);

			printf("expected root = %.12lf\n\n", exproot);
			printf("j\t| root hybrid newton\t| e absolute\t| e relative\n");
			printf("--------------------------------------------------------------------------------------------\n");
			eabsolute = eabs(root, exproot);
			erelative = erel(root, exproot);
			printf("%d\t| %.8e\t| %.3e\t| %.3e\n", j, root, eabsolute, erelative);
			printf("\n\n\n\n");
			break;
		}
		else {
			maxIteration = bisMaxItr(a, b, prec1);

			printf("max itterations = %d, for tollerence = %.3e\n", maxIteration, prec1);
			printf("Lower initial value = %.3lf, Upper initial value = %.3lf\n", a, b);
			printf("expected root = %.12lf\n\n", exproot);
			printf("i\t| root bisection\t| e absolute\t| e relative\n");
			printf("--------------------------------------------------------------------------------------------\n");

			if ((Fxa * Fxb) < 0.0) {
				i = 0;
				while (maxIteration > 0) {

					maxIteration--;
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
						eabsolute = eabs(c, exproot);
						erelative = erel(c, exproot);
						printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, c, eabsolute, erelative);
						break;
					}
					eabsolute = eabs(c, exproot);
					erelative = erel(c, exproot);
					printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, c, eabsolute, erelative);
				}

				root = c;

			}
			else if ((Fxa * Fxb) == 0.0) {

				if (Fxa == 0) {
					root = a;
					eabsolute = eabs(a, exproot);
					erelative = erel(a, exproot);
					printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, a, eabsolute, erelative);
				}
				if (Fxb == 0) {
					root = b;
					eabsolute = eabs(b, exproot);
					erelative = erel(b, exproot);
					printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, b, eabsolute, erelative);
				}

			}
			else {

				printf("\n\nThere is no root or an even number of roots between the upper and lower initial values.");
				root = 0.0;
			}

			printf("\n\n\n");

		}


		printf("expected root = %.12lf\n\n", exproot);
		printf("j\t| root hybrid newton\t| e absolute\t| e relative\n");
		printf("--------------------------------------------------------------------------------------------\n");
		eabsolute = eabs(root, exproot);
		erelative = erel(root, exproot);
		printf("%d\t| %.8e\t| %.3e\t| %.3e\n", j, root, eabsolute, erelative);
		printf("\n\n\n\n");
	}


	return root;
}



double expSecantHybrid(double(*f)(double), double a, double b, double tol, int maxItr, double exproot) {
	int i = 0, j = 0;
	double c = 0.0;
	double Fxc = 1.0;
	double Fxa = f(a);
	double Fxb = f(b);
	double root = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;
	double initialGuess = 0.0;
	double prec1 = 0.1;
	int maxIteration = 0;
	//double temp = 0.0;

	eabsolute = 10.0 * tol;

	while ((eabsolute > tol) && maxItr > 0) {

		maxItr--;
		j++;

		maxIteration = 2;

		root = expsecant(f, a, b, tol, maxIteration, exproot);

		if (root >= a && root <= b) {
			maxIteration = 10;

			root = expsecant(f, a, b, tol, maxIteration, exproot);

			printf("expected root = %.12lf\n\n", exproot);
			printf("j\t| root hybrid secant\t| e absolute\t| e relative\n");
			printf("--------------------------------------------------------------------------------------------\n");
			eabsolute = eabs(root, exproot);
			erelative = erel(root, exproot);
			printf("%d\t| %.8e\t| %.3e\t| %.3e\n", j, root, eabsolute, erelative);
			printf("\n\n\n\n");
			break;
		}
		else {

			maxIteration = bisMaxItr(a, b, prec1);

			printf("max itterations = %d, for tollerence = %.3e\n", maxIteration, prec1);
			printf("Lower initial value = %.3lf, Upper initial value = %.3lf\n", a, b);
			printf("expected root = %.12lf\n\n", exproot);
			printf("i\t| root bisection\t| e absolute\t| e relative\n");
			printf("--------------------------------------------------------------------------------------------\n");

			if ((Fxa * Fxb) < 0.0) {
				i = 0;
				while (maxIteration > 0) {

					maxIteration--;
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
						eabsolute = eabs(c, exproot);
						erelative = erel(c, exproot);
						printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, c, eabsolute, erelative);
						break;
					}
					eabsolute = eabs(c, exproot);
					erelative = erel(c, exproot);
					printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, c, eabsolute, erelative);
				}

				root = c;

			}
			else if ((Fxa * Fxb) == 0.0) {

				if (Fxa == 0) {
					root = a;
					eabsolute = eabs(a, exproot);
					erelative = erel(a, exproot);
					printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, a, eabsolute, erelative);
				}
				if (Fxb == 0) {
					root = b;
					eabsolute = eabs(b, exproot);
					erelative = erel(b, exproot);
					printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, b, eabsolute, erelative);
				}

			}
			else {

				printf("\n\nThere is no root or an even number of roots between the upper and lower initial values.");
				root = 0.0;
			}

			printf("\n\n\n");

		}


		printf("expected root = %.12lf\n\n", exproot);
		printf("j\t| root hybrid secant\t| e absolute\t| e relative\n");
		printf("--------------------------------------------------------------------------------------------\n");
		eabsolute = eabs(root, exproot);
		erelative = erel(root, exproot);
		printf("%d\t| %.8e\t| %.3e\t| %.3e\n", j, root, eabsolute, erelative);
		printf("\n\n\n\n");
	}


	return root;
}



double derivative(double(*f)(double), double x, double h, double tol, int maxItr) {

	int i = 0;
	double fp = 0.0;

	printf("x = %lf\n", x);

	printf("i\t| appoximate derivative\t\t| h\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while (maxItr > 0) {

		maxItr--;
		i++;

		fp = (f(x + h) - f(x)) / (h);

		printf("%d\t| %.8e\t\t| %.3e\n", i, fp, h);
		h = h / 2.0;

	}

	printf("\n\n\n");

	return fp;
}


double bisection(double(*f)(double), double a, double b, double tol, int maxItr) {
	int i = 0;
	double c = 0.0;
	double Fxc = 1.0;
	double Fxa = f(a);
	double Fxb = f(b);
	double root = 0.0;

	printf("max itterations = %d, for tollerence = %.3e\n", maxItr, tol);
	printf("Lower initial value = %.1lf, Upper initial value = %.1lf\n\n", a, b);
	printf("i\t| root\n");
	printf("--------------------------------------------------------------------------------------------\n");

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

	printf("\n\n\n");

	return root;
}


double newton(double(*f)(double), double(*fp)(double), double x, double tol, int maxItr) {

	int i = 0;
	double fxn1 = 0.0;

	printf("tolerance =  %.3e\n", tol);
	printf("Initial value = %lf\n", x);
	printf("i\t| root\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while (maxItr > 0) {

		maxItr--;
		i++;

		fxn1 = x - (f(x)) / (fp(x));

		printf("%d\t| %.8e\n", i, fxn1);

		x = fxn1;
	}

	printf("\n\n\n");

	return fxn1;
}


double secant(double(*f)(double), double xa, double xb, double tol, int maxItr) {

	int i = 0;
	double fxn1 = 0.0;

	printf("tolerance =  %.3e\n", tol);
	printf("Initial values = %lf and %lf\n", xa, xb);

	printf("i\t| root\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while (maxItr > 0) {

		maxItr--;
		i++;

		fxn1 = xb - ((f(xb) * (xb - xa)) / (f(xb) - f(xa)));

		printf("%d\t| %.8e\n", i, fxn1);

		xa = xb;
		xb = fxn1;

	}

	printf("\n\n\n");

	return fxn1;
}

//*******************************************************************************************************************************

void printAugMatrix(double **A, double *b, int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", A[i][j]);
		}
		printf("|%.3e\n", b[i]);
	}
}

void printMatrix(double **A, int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", A[i][j]);
		}
		printf("\n");
	}
}

void printVector(double *v, int n) {
	int i, j = 0;
	for (i = 0; i < n; i++) {
		printf("%.3e\n", v[i]);
	}
}

void vectorAdd(double *up, double *vp, double *ap, int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		ap[i] = up[i] + vp[i];
	}
}

void vectorSub(double *up, double *vp, double *ap, int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		ap[i] = up[i] - vp[i];
	}
}

void vectorScale(double *up, double *ap, double scale, int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		ap[i] = scale * up[i];
	}
}

double vectorInner(double *up, double *vp, int len) {
	int i = 0;
	double ia = 0.0;
	for (i = 0; i < len; i++) {
		ia = ia + (up[i] * vp[i]);
	}
	return ia;
}

void vectorCross(double *up, double *vp, double *ap, int len) {
	ap[0] = (up[1] * vp[2]) - (up[2] * vp[1]);
	ap[1] = (up[2] * vp[0]) - (up[0] * vp[2]);
	ap[2] = (up[0] * vp[1]) - (up[1] * vp[0]);
}

double vectorNormL1(double *up, int len) {
	int i = 0;
	double ia = 0.0;
	for (i = 0; i < len; i++) {
		ia = ia + fabs(up[i]);
	}
	return ia;
}

double vectorNormL2(double *up, int len) {
	int i = 0;
	double ia = 0.0;
	for (i = 0; i < len; i++) {
		ia = ia + (up[i] * up[i]);
	}
	ia = sqrt(ia);
	return ia;
}

double vectorNormInfinity(double *up, int len) {
	int i = 0;
	double ia = 0.0;
	ia = fabs(up[0]);
	for (i = 0; i < len; i++) {
		if (fabs(up[i]) > ia) {
			ia = fabs(up[i]);
		}
	}
	return ia;
}

//**********************************************************************************************************************************

double vectorErrorAbsoluteL1(double *xp, double *yp, int len) {
	
	double eabs = 0.0;
	int i = 0;

	// alloc memory for a vector
	double *e;
	e = calloc(len, sizeof(double));

	vectorSub(xp, yp, e, len);

	eabs = vectorNormL1(e, len);

	// free memory
	free(e);

	return eabs;
}

double vectorErrorRelativeL1(double *xp, double *yp, int len) {

	double erel = 0.0;
	double a = 0.0;

	a = vectorNormL1(xp, len);

	erel = (vectorErrorAbsoluteL1(xp, yp, len)) / a;

	return erel;
}

double vectorErrorAbsoluteL2(double *xp, double *yp, int len) {

	double eabs = 0.0;
	int i = 0;

	// alloc memory for a vector
	double *e;
	e = calloc(len, sizeof(double));

	vectorSub(xp, yp, e, len);

	eabs = vectorNormL2(e, len);

	// free memory
	free(e);

	return eabs;
}

double vectorErrorRelativeL2(double *xp, double *yp, int len) {

	double erel = 0.0;
	double a = 0.0;

	a = vectorNormL2(xp, len);

	erel = (vectorErrorAbsoluteL2(xp, yp, len)) / a;

	return erel;
}

double vectorErrorAbsoluteInfinity(double *xp, double *yp, int len) {

	double eabs = 0.0;
	int i = 0;

	// alloc memory for a vector
	double *e;
	e = calloc(len, sizeof(double));

	vectorSub(xp, yp, e, len);

	eabs = vectorNormInfinity(e, len);

	// free memory
	free(e);

	return eabs;
}

double vectorErrorRelativeInfinity(double *xp, double *yp, int len) {

	double erel = 0.0;
	double a = 0.0;

	a = vectorNormInfinity(xp, len);

	erel = (vectorErrorAbsoluteInfinity(xp, yp, len)) / a;

	return erel;
}

//***************************************************************************************************************************************

void matrixAdd(double **A, double **B, double **C, int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void matrixSub(double **A, double **B, double **C, int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

void vectorXmatrix(double **A, double *v, double *u, int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		u[i] = 0;
		for (j = 0; j < n; j++) {
			u[i] = u[i] + (A[i][j] * v[j]);
		}
	}
}

void matrixXvectorParallel(double **A, double *v, double *u, int m, int n) {
	int i, j = 0;

	// begin parallel threads
#pragma omp parallel private(i, j)
	{
#pragma omp for
		for (i = 0; i < m; i++) {
			u[i] = 0;
			for (j = 0; j < n; j++) {
				u[i] = u[i] + (A[i][j] * v[j]);
			}
		}
	}

}

void parallelVectorXmatrix(double **A, double *v, double *u, int m, int n) {

	int i = 0;
	int id = 0;

	// begin parallel threads
#pragma omp parallel private(id, i)
	{
		id = omp_get_thread_num();

		if (id == 1) {
			u[0] = 0;
			for (i = 0; i < m; i++) {
				u[0] = u[0] + (A[0][i] * v[i]);
				//printf("A[0][%d] * v[%d], thread %d\n", i, i, id);
			}
		}

		if (id == 2) {
			u[1] = 0;
			for (i = 0; i < m; i++) {
				u[1] = u[1] + (A[1][i] * v[i]);
				//printf("A[1][%d] * v[%d], thread %d\n", i, i, id);
			}
		}

		if (id == 3) {
			u[2] = 0;
			for (i = 0; i < m; i++) {
				u[2] = u[2] + (A[2][i] * v[i]);
				//printf("A[2][%d] * v[%d], thread %d\n", i, i, id);
			}
		}
	}
}


void matrixXmatrix(double **A, double **B, double **C, int m, int n) {
	int i, j, k = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = 0;
			for (k = 0; k < m; k++) {
				C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
			}
		}
	}
}


void parallelMatrixXmatrix(double **A, double **B, double **C, int m, int n) {

	int i, j = 0;
	int id = 0;

	// begin parallel threads
#pragma omp parallel private(id, i, j)
	{
		id = omp_get_thread_num();

		if (id == 1) {
			for (i = 0; i < m; i++) {
				C[0][i] = 0;
				for (j = 0; j < n; j++) {
					C[0][i] = C[0][i] + (A[0][j] * B[j][i]);
					//printf("A[0][%d] * B[%d][%d], thread %d\n", j, j, i, id);
				}
			}
		}

		if (id == 2) {
			for (i = 0; i < m; i++) {
				C[1][i] = 0;
				for (j = 0; j < n; j++) {
					C[1][i] = C[1][i] + (A[1][j] * B[j][i]);
					//printf("A[1][%d] * B[%d][%d], thread %d\n", j, j, i, id);
				}
			}
		}

		if (id == 3) {
			for (i = 0; i < m; i++) {
				C[2][i] = 0;
				for (j = 0; j < n; j++) {
					C[2][i] = C[2][i] + (A[2][j] * B[j][i]);
					//printf("A[2][%d] * B[%d][%d], thread %d\n", j, j, i, id);
				}
			}
		}
	}
}


double traceMatrix(double **A, int m) {
	double trace = 0.0;
	int i = 0;
	for (i = 0; i < m; i++) {
		trace = trace + A[i][i];
	}
	return trace;
}

void scaleMatrix(double **A, double **C, double s, int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = s * A[i][j];
		}
	}
}

void transposeMatrix(double **A, double **C, int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = A[j][i];
		}
	}
}

double determinantMatrix(double **A, int m) {
	double determinant = (A[0][0] * ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1]))) - (A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0]))) + (A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0])));
	return determinant;
}

void KroneckerMatrix(double **A, double **B, double **K, int m, int n) {
	/*
	int i, j, k = 0;

	//************************************************
	// alloc memory for a matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = 0.0;
		}
	}
	//************************************************

	
	double R[50][50] = { 0 };
	double S[50][50] = { 0 };
	double T[50][50] = { 0 };
	double U[50][50] = { 0 };
	double V[50][50] = { 0 };
	double W[50][50] = { 0 };
	double X[50][50] = { 0 };
	double Y[50][50] = { 0 };
	double Z[50][50] = { 0 };
	double s = 0;

	s = A[0][0];
	scaleMatrix(B, R, s, m, n);

	s = A[0][1];
	scaleMatrix(B, S, s, m, n);

	s = A[0][2];
	scaleMatrix(B, T, s, m, n);

	s = A[1][0];
	scaleMatrix(B, U, s, m, n);

	s = A[1][1];
	scaleMatrix(B, V, s, m, n);

	s = A[1][2];
	scaleMatrix(B, W, s, m, n);

	s = A[2][0];
	scaleMatrix(B, X, s, m, n);

	s = A[2][1];
	scaleMatrix(B, Y, s, m, n);

	s = A[2][2];
	scaleMatrix(B, Z, s, m, n);


	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			K[i][j] = R[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			K[i][j + 3] = S[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			K[i][j + 6] = T[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			K[i + 3][j] = U[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			K[i + 3][j + 3] = V[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			K[i + 3][j + 6] = W[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			K[i + 6][j] = X[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			K[i + 6][j + 3] = Y[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			K[i + 6][j + 6] = Z[i][j];
		}
	}


	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	*/
}

double matrixNormL1(double **a, int len) {
	int i, j = 0;
	double ia = 0.0;
	double max = 0.0;
	for (j = 0; j < len; j++) {
		ia = 0.0;
		for (i = 0; i < len; i++) {
			ia = ia + fabs(a[i][j]);
		}
		if (max < ia) {
			max = ia;
		}
	}

	return max;
}

double matrixNormFrobenious(double **a, int len) {
	int i, j = 0;
	double ia = 0.0;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			ia = ia + (a[i][j] * a[i][j]);
		}
	}
	ia = sqrt(ia);
	return ia;
}

double matrixNormInfinity(double **a, int len) {
	int i, j = 0;
	double ia = 0.0;
	double max = 0.0;
	for (i = 0; i < len; i++) {
		ia = 0.0;
		for (j = 0; j < len; j++) {
			ia = ia + fabs(a[i][j]);
		}
		if (max < ia) {
			max = ia;
		}
	}

	return max;
}

void outerProductMatrix(double *x, double *y, double **C, int m, int n) {
	int i, j = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = x[i] * y[j];
		}
	}
}

void unitOrthog(double *v1, double *v2, double *u1, double *u2, int len) {

	int i = 0;
	double ia = 0;

	// alloc memory for a vector
	double *a;
	a = calloc(len, sizeof(double));

	vectorCross(v1, v2, a, len);

	ia = vectorNormL2(a, len);

	ia = 1 / ia;

	vectorScale(a, u1, ia, len);

	vectorScale(u1, u2, -1.0, len);

	// free memory
	free(a);
}

//******************************
void forwardSub(double **A, double *x, double *b, int n) {
	int i, j = 0;
	double sum = 0.0;

	x[0] = b[0] / A[0][0];
	for (i = 1; i < n; i++) {
		sum = 0.0;
		for (j = 0; j < i; j++) {
			sum = sum + (A[i][j] * x[j]);
		}
		x[i] = (b[i] - sum) / A[i][i];
	}
}

void backSub(double **A, double *x, double *b, int n) {
	int i, j = 0;
	double sum = 0.0;

	x[n] = b[n] / A[n][n];
	for (i = n - 1; i > -1; i--) {
		sum = 0.0;
		for (j = (i + 1); j < n; j++) {
			sum = sum + (A[i][j] * x[j]);
		}
		x[i] = (b[i] - sum) / A[i][i];
	}
}

void squareGauss(double **A, double *b, int n) {
	int i, j, k = 0;
	double factor = 0.0;
	for (k = 0; k < (n - 1); k++) {
		for (i = (k + 1); i < n; i++) {
			factor = A[i][k] / A[k][k];
			A[i][k] = 0.0;
			for (j = (k + 1); j < n; j++) {
				A[i][j] = A[i][j] - (factor * A[k][j]);
			}
			b[i] = b[i] - (factor * b[k]);
		}
	}
}

void squareLU(double **A, double **B, int n) {
	int i, j, k = 0;
	double factor = 0.0;
	for (k = 0; k < (n - 1); k++) {
		for (i = (k + 1); i < n; i++) {
			factor = A[i][k] / A[k][k];
			A[i][k] = 0.0;
			for (j = (k + 1); j < n; j++) {
				A[i][j] = A[i][j] - (factor * A[k][j]);
				B[i][j] = 0.0;
			}
			B[i][k] = factor;
		}
	}

	for (k = 0; k < n; k++) {
		B[k][k] = 1.0;
	}
}

void generalGauss(double **A, double *b, int m, int n) {
	int i, j, k = 0;
	double factor = 0.0;
	for (k = 0; k < (n - 1); k++) {
		for (i = (k + 1); i < m; i++) {
			factor = A[i][k] / A[k][k];
			A[i][k] = 0.0;
			for (j = (k + 1); j < n; j++) {
				A[i][j] = A[i][j] - (factor * A[k][j]);
			}
			b[i] = b[i] - (factor * b[k]);
		}
	}
}

void GEsolve(double **A, double *x, double *b, int n) {
	squareGauss(A, b, n);
	backSub(A, x, b, n);
}

void LUsolve(double **A, double **L, double *x, double *b, int n) {
	int i = 0;

	// alloc memory for a vector
	double *yd;
	yd = calloc(n, sizeof(double));
	
	squareLU(A, L, n);
	forwardSub(L, yd, b, n);
	backSub(A, x, yd, n);

	// free memory
	free(yd);
}

void choleskyLU(double **A, double **B, int n) {
	int i, j, k = 0;
	for (k = 0; k < (n - 1); k++) {
		A[k][k] = sqrt(A[k][k]);
		for (i = (k + 1); i < n; i++) {
			A[i][k] = A[i][k] / A[k][k];
		}
		for (j = (k + 1); j < n; j++) {
			for (i = j; i < n; i++) {
				A[i][j] = A[i][j] - (A[i][k] * A[j][k]);
			}
		}
	}
	A[n - 1][n - 1] = sqrt(A[n - 1][n - 1]);
	for (k = 0; k < n; k++) {
		for (i = (k + 1); i < n; i++) {
			A[k][i] = 0.0;
		}
	}

	transposeMatrix(A, B, n, n);
}

void Choleskysolve(double **A, double **U, double *x, double *b, int n) {
	int i = 0;

	// alloc memory for a vector
	double *yd;
	yd = calloc(n, sizeof(double));

	choleskyLU(A, U, n);
	forwardSub(A, yd, b, n);
	backSub(U, x, yd, n);

	// free memory
	free(yd);
}

double matrixInducedNormL1(double **A, double *v, int n) {
	double AvNorm = 0.0;
	double vNorm = 0.0;
	double inducedNorm = 0.0;

	// alloc memory for a vector
	double *u;
	u = calloc(n, sizeof(double));

	vectorXmatrix(A, v, u, n, n);
	AvNorm = vectorNormL1(u, n);
	vNorm = vectorNormL1(v, n);
	inducedNorm = AvNorm / vNorm;

	// free memory
	free(u);

	return inducedNorm;
}

double matrixInducedNormInfinity(double **A, double *v, int n) {
	double AvNorm = 0.0;
	double vNorm = 0.0;
	double inducedNorm = 0.0;

	// alloc memory for a vector
	double *u;
	u = calloc(n, sizeof(double));

	vectorXmatrix(A, v, u, n, n);
	AvNorm = vectorNormInfinity(u, n);
	vNorm = vectorNormInfinity(v, n);
	inducedNorm = AvNorm / vNorm;

	// free memory
	free(u);

	return inducedNorm;
}

void uniformMatrix(double **A, double *b, int n) {
	int i, j, k = 0;
	double sum = 0.0;

	double *ones;
	ones = calloc(n, sizeof(double));

	for (i = 0; i < n; i++) {
		ones[i] = 1.0;
	}

	srand(time(0));

	// upper triangular
	for (i = 0; i < n; i++) {
		for (j = (i + 1); j < n; j++) {
			A[i][j] = ((rand() % 1000) + 1) / 1000.0;
		}
	}

	// lower triangular
	for (i = 0; i < n; i++) {
		for (j = (i + 1); j < n; j++) {
			A[j][i] = A[i][j];
		}
	}

	// diaginal dominant
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i != j) {
				sum = sum + A[i][j];
			}
		}
		A[i][i] = sum + 0.01;
		sum = 0.0;
	}

	// compute RHS values for vector b
	vectorXmatrix(A, ones, b, n, n);

	free(ones);
}

void jacobi(double **A, double *b, double *x0, double tol, int maxiter, int n) {
	int i, j = 0;
	int iter = 0;
	double err = 10 * tol;

	// alloc memory for a vector
	double *x1;
	x1 = calloc(n, sizeof(double));

	while ((err > tol) && (iter < maxiter)) {
		iter++;

		for (i = 0; i < n; i++) {
			x1[i] = 0;
			for (j = 0; j < n; j++) {
				if (i != j) {
					x1[i] = x1[i] + (A[i][j] * x0[j]);
				}
			}
			x1[i] = (b[i] - x1[i]) / A[i][i];
		}

		err = vectorErrorRelativeL2(x1, x0, n);

		for (i = 0; i < n; i++) {
			x0[i] = x1[i];
		}
	}
	printf("Finished after %d iterations\n\n", iter);

	// free memory
	free(x1);
}

void jacobiParallel(double **A, double *b, double *x0, double tol, int maxiter, int n) {
	int i, j = 0;
	int iter = 0;
	double err = 10 * tol;

	// alloc memory for a vector
	double *x1;
	x1 = calloc(n, sizeof(double));

	while ((err > tol) && (iter < maxiter)) {
		iter++;

		// begin parallel threads
#pragma omp parallel private(i, j)
		{
#pragma omp for
			for (i = 0; i < n; i++) {
				x1[i] = 0;
				for (j = 0; j < n; j++) {
					if (i != j) {
						x1[i] = x1[i] + (A[i][j] * x0[j]);
					}
				}
				x1[i] = (b[i] - x1[i]) / A[i][i];
			}
		}

		err = vectorErrorRelativeL2(x1, x0, n);

		for (i = 0; i < n; i++) {
			x0[i] = x1[i];
		}
	}
	printf("Finished after %d iterations\n\n", iter);

	// free memory
	free(x1);
}

void gaussSeidel(double **A, double *b, double *x0, double tol, int maxiter, int n) {
	int i, j = 0;
	int iter = 0;
	double err = 10 * tol;

	// alloc memory for a vector
	double *x1;
	x1 = calloc(n, sizeof(double));

	while ((err > tol) && (iter < maxiter)) {
		iter++;

		for (i = 0; i < n; i++) {
			x1[i] = 0;
			for (j = 0; j < n; j++) {
				if (i != j) {
					x1[i] = x1[i] + (A[i][j] * x1[j]);
				}
			}
			x1[i] = (b[i] - x1[i]) / A[i][i];
		}

		err = vectorErrorRelativeL2(x1, x0, n);

		for (i = 0; i < n; i++) {
			x0[i] = x1[i];
		}
	}
	printf("Finished after %d iterations\n\n", iter);

	// free memory
	free(x1);
}

void gaussSeidelParallel(double **A, double *b, double *x0, double tol, int maxiter, int n) {
	int i, j = 0;
	int iter = 0;
	double err = 10 * tol;

	// alloc memory for a vector
	double *x1;
	x1 = calloc(n, sizeof(double));
	// alloc memory for a vector
	double *s1;
	s1 = calloc(n, sizeof(double));
	// alloc memory for a vector
	double *s2;
	s2 = calloc(n, sizeof(double));

	while ((err > tol) && (iter < maxiter)) {
		iter++;

		for (i = 0; i < n; i++) {
			x1[i] = 0;

			// begin parallel threads
#pragma omp parallel
			{
#pragma omp for
				for (j = 0; j < n; j++) {
					s1[j] = 0.0;
					s2[j] = 0.0;
				}
#pragma omp barrier
#pragma omp for	
				for (j = 0; j < i; j++) {
					s1[j] = (A[i][j] * x1[j]);
				}
#pragma omp barrier
#pragma omp for			
				for (j = (i + 1); j < n; j++) {
					s2[j] = (A[i][j] * x1[j]);
				}
			}

			for (j = 0; j < n; j++) {
				x1[i] = x1[i] + s1[j] + s2[j];
			}

			x1[i] = (b[i] - x1[i]) / A[i][i];
		}

		err = vectorErrorRelativeL2(x1, x0, n);


		for (i = 0; i < n; i++) {
			x0[i] = x1[i];
		}
	}
	printf("Finished after %d iterations\n\n", iter);

	// free memory
	free(x1);
	free(s1);
	free(s2);
}

void conjugateGradient(double **A, double *b, double *x0, double tol, int maxiter, int n) {
	int i, j = 0;
	int iter = 0;
	double err = 10 * tol;
	double delta0 = 0.0;
	double delta1 = 0.0;
	double alpha = 0.0;
	double temp = 0.0;



	// alloc memory for a vector
	double *x1;
	x1 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *r0;
	r0 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *r1;
	r1 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *p0;
	p0 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *p1;
	p1 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *s;
	s = calloc(n, sizeof(double));

	// r0 = b - Ax0
	for (i = 0; i < n; i++) {
		r0[i] = b[i];
		for (j = 0; j < n; j++) {
			if (i != j) {
				r0[i] = r0[i] - (A[i][j] * x0[j]);
			}
		}
	}

	delta0 = vectorInner(r0, r0, n);
	err = vectorInner(b, b, n);

	for (i = 0; i < n; i++) {
		p0[i] = r0[i];
	}


	while ((delta0 > (tol * tol * err)) && (iter < maxiter)) {
		iter++;

		vectorXmatrix(A, p0, s, n, n);
		temp = vectorInner(p0, s, n);
		alpha = delta0 / temp;

		for (i = 0; i < n; i++) {
			x1[i] = x0[i] + (alpha * p0[i]);
		}

		for (i = 0; i < n; i++) {
			r1[i] = r0[i] - (alpha * s[i]);
		}

		delta1 = vectorInner(r1, r1, n);

		for (i = 0; i < n; i++) {
			p1[i] = r1[i] + ((delta1 / delta0) * p0[i]);
		}

		for (i = 0; i < n; i++) {
			p0[i] = p1[i];
		}

		for (i = 0; i < n; i++) {
			r0[i] = r1[i];
		}

		delta0 = delta1;

		for (i = 0; i < n; i++) {
			x0[i] = x1[i];
		}
	}

	printf("Finished after %d iterations\n\n", iter);

	// free memory
	free(x1);
	free(r0);
	free(r1);
	free(p0);
	free(p1);
	free(s);
}

void conjugateGradientParallel(double **A, double *b, double *x0, double tol, int maxiter, int n) {
	int i, j = 0;
	int iter = 0;
	double err = 10 * tol;
	double delta0 = 0.0;
	double delta1 = 0.0;
	double alpha = 0.0;
	double temp = 0.0;



	// alloc memory for a vector
	double *x1;
	x1 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *r0;
	r0 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *r1;
	r1 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *p0;
	p0 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *p1;
	p1 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *s;
	s = calloc(n, sizeof(double));

	// begin parallel threads
#pragma omp parallel private(i, j)
	{
#pragma omp for
		// r0 = b - Ax0
		for (i = 0; i < n; i++) {
			r0[i] = b[i];
			for (j = 0; j < n; j++) {
				if (i != j) {
					r0[i] = r0[i] - (A[i][j] * x0[j]);
				}
			}
		}
	}

	delta0 = vectorInner(r0, r0, n);
	err = vectorInner(b, b, n);

	for (i = 0; i < n; i++) {
		p0[i] = r0[i];
	}


	while ((delta0 > (tol * tol * err)) && (iter < maxiter)) {
		iter++;

		vectorXmatrix(A, p0, s, n, n);
		temp = vectorInner(p0, s, n);
		alpha = delta0 / temp;

		for (i = 0; i < n; i++) {
			x1[i] = x0[i] + (alpha * p0[i]);
		}

		for (i = 0; i < n; i++) {
			r1[i] = r0[i] - (alpha * s[i]);
		}

		delta1 = vectorInner(r1, r1, n);

		for (i = 0; i < n; i++) {
			p1[i] = r1[i] + ((delta1 / delta0) * p0[i]);
		}

		for (i = 0; i < n; i++) {
			p0[i] = p1[i];
		}

		for (i = 0; i < n; i++) {
			r0[i] = r1[i];
		}

		delta0 = delta1;

		for (i = 0; i < n; i++) {
			x0[i] = x1[i];
		}
	}

	printf("Finished after %d iterations\n\n", iter);

	// free memory
	free(x1);
	free(r0);
	free(r1);
	free(p0);
	free(p1);
	free(s);
}





// code to allocate memory for matrix and vector
/*

	// alloc memory for a matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);




	// alloc memory for a vector
	double *b;
	b = calloc(n, sizeof(double));

	// free memory
	free(b);

*/