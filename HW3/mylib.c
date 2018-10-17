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

void vectorAdd(double up[3], double vp[3], double ap[3], int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		ap[i] = up[i] + vp[i];
	}
}

void vectorSub(double up[3], double vp[3], double ap[3], int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		ap[i] = up[i] - vp[i];
	}
}

void vectorScale(double up[3], double ap[3], double scale, int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		ap[i] = scale * up[i];
	}
}

double vectorInner(double up[3], double vp[3], int len) {
	int i = 0;
	double ia = 0.0;
	for (i = 0; i < len; i++) {
		ia = ia + (up[i] * vp[i]);
	}
	return ia;
}

void vectorCross(double up[3], double vp[3], double ap[3], int len) {
	ap[0] = (up[1] * vp[2]) - (up[2] * vp[1]);
	ap[1] = (up[2] * vp[0]) - (up[0] * vp[2]);
	ap[2] = (up[0] * vp[1]) - (up[1] * vp[0]);
}

double vectorNormL1(double up[3], int len) {
	int i = 0;
	double ia = 0.0;
	for (i = 0; i < len; i++) {
		ia = ia + fabs(up[i]);
	}
	return ia;
}

double vectorNormL2(double up[3], int len) {
	int i = 0;
	double ia = 0.0;
	for (i = 0; i < len; i++) {
		ia = ia + (up[i] * up[i]);
	}
	ia = sqrt(ia);
	return ia;
}

double vectorNormInfinity(double up[3], int len) {
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

double vectorErrorAbsoluteL1(double xp[3], double yp[3], int len) {

	double eabs = 0.0;
	double e[3] = { 0 };

	vectorSub(xp, yp, e, len);

	eabs = vectorNormL1(e, len);

	return eabs;
}

double vectorErrorRelativeL1(double xp[3], double yp[3], int len) {

	double erel = 0.0;
	double a = 0.0;

	a = vectorNormL1(xp, len);

	erel = (vectorErrorAbsoluteL1(xp, yp, len)) / a;

	return erel;
}

double vectorErrorAbsoluteL2(double xp[3], double yp[3], int len) {

	double eabs = 0.0;
	double e[3] = { 0 };

	vectorSub(xp, yp, e, len);

	eabs = vectorNormL2(e, len);

	return eabs;
}

double vectorErrorRelativeL2(double xp[3], double yp[3], int len) {

	double erel = 0.0;
	double a = 0.0;

	a = vectorNormL2(xp, len);

	erel = (vectorErrorAbsoluteL2(xp, yp, len)) / a;

	return erel;
}

double vectorErrorAbsoluteInfinity(double xp[3], double yp[3], int len) {

	double eabs = 0.0;
	double e[3] = { 0 };

	vectorSub(xp, yp, e, len);

	eabs = vectorNormInfinity(e, len);

	return eabs;
}

double vectorErrorRelativeInfinity(double xp[3], double yp[3], int len) {

	double erel = 0.0;
	double a = 0.0;

	a = vectorNormInfinity(xp, len);

	erel = (vectorErrorAbsoluteInfinity(xp, yp, len)) / a;

	return erel;
}

//***************************************************************************************************************************************

void matrixAdd(double A[3][3], double B[3][3], double C[3][3], int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void matrixSub(double A[3][3], double B[3][3], double C[3][3], int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

void vectorXmatrix(double A[3][3], double v[3], double u[3], int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		u[i] = 0;
		for (j = 0; j < n; j++) {
			u[i] = u[i] + (A[i][j] * v[j]);
		}
	}
}

void parallelVectorXmatrix(double A[3][3], double v[3], double u[3], int m, int n) {

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
				printf("A[0][%d] * v[%d], thread %d\n", i, i, id);
			}
		}

		if (id == 2) {
			u[1] = 0;
			for (i = 0; i < m; i++) {
				u[1] = u[1] + (A[1][i] * v[i]);
				printf("A[1][%d] * v[%d], thread %d\n", i, i, id);
			}
		}

		if (id == 3) {
			u[2] = 0;
			for (i = 0; i < m; i++) {
				u[2] = u[2] + (A[2][i] * v[i]);
				printf("A[2][%d] * v[%d], thread %d\n", i, i, id);
			}
		}
	}
}


void matrixXmatrix(double A[3][3], double B[3][3], double C[3][3], int m, int n) {
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


void parallelMatrixXmatrix(double A[3][3], double B[3][3], double C[3][3], int m, int n) {

	int i, j, k = 0;
	int id = 0;

	// begin parallel threads
#pragma omp parallel private(id, i, j, k)
	{
		id = omp_get_thread_num();

		if (id == 1) {
			for (i = 0; i < m; i++) {
				C[0][i] = 0;
				for (j = 0; j < n; j++) {
					C[0][i] = C[0][i] + (A[0][j] * B[j][i]);
					printf("A[0][%d] * B[%d][%d], thread %d\n", j, j, i, id);
				}
			}
		}

		if (id == 2) {
			for (i = 0; i < m; i++) {
				C[1][i] = 0;
				for (j = 0; j < n; j++) {
					C[1][i] = C[1][i] + (A[1][j] * B[j][i]);
					printf("A[1][%d] * B[%d][%d], thread %d\n", j, j, i, id);
				}
			}
		}

		if (id == 3) {
			for (i = 0; i < m; i++) {
				C[2][i] = 0;
				for (j = 0; j < n; j++) {
					C[2][i] = C[2][i] + (A[2][j] * B[j][i]);
					printf("A[2][%d] * B[%d][%d], thread %d\n", j, j, i, id);
				}
			}
		}
	}
}


double traceMatrix(double A[3][3], int m) {
	double trace = 0.0;
	int i = 0;
	for (i = 0; i < m; i++) {
		trace = trace + A[i][i];
	}
	return trace;
}

void scaleMatrix(double A[3][3], double C[3][3], double s, int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = s * A[i][j];
		}
	}
}

void transposeMatrix(double A[3][3], double C[3][3], int m, int n) {
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = A[j][i];
		}
	}
}

double determinantMatrix(double A[3][3], int m) {
	double determinant = (A[0][0] * ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1]))) - (A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0]))) + (A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0])));
	return determinant;
}

void KroneckerMatrix(double A[3][3], double B[3][3], double K[9][9], int m, int n) {

	int i, j, k = 0;
	double R[3][3] = { 0 };
	double S[3][3] = { 0 };
	double T[3][3] = { 0 };
	double U[3][3] = { 0 };
	double V[3][3] = { 0 };
	double W[3][3] = { 0 };
	double X[3][3] = { 0 };
	double Y[3][3] = { 0 };
	double Z[3][3] = { 0 };
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

}

double matrixNormL1(double a[3][3], int len) {
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

double matrixNormFrobenious(double a[3][3], int len) {
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

double matrixNormInfinity(double a[3][3], int len) {
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

void outerProductMatrix(double x[3], double y[3], double C[3][3], int m, int n) {
	int i, j = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = x[i] * y[j];
		}
	}
}

void unitOrthog(double v1[3], double v2[3], double u1[3], double u2[3], int len) {

	int i = 0;
	double ia = 0;
	double a[3] = { 0 };

	vectorCross(v1, v2, a, len);

	ia = vectorNormL2(a, len);

	ia = 1 / ia;

	vectorScale(a, u1, ia, len);

	vectorScale(u1, u2, -1.0, len);
}