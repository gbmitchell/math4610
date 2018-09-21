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
