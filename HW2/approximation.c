#include <stdio.h>
#include <math.h>
#include <mylib.h>


int main() {
	double Pi = 3.1415926535897932384626433832795028841971693993751058209749445923;
	int i = 0, j = 0, maxIteration = 0, maxIteration1 = 0;
	int ipow = 0;
	int count = 0;
	double x = 0.0;
	double h = 0.0;
	double fxh = 0.0;
	double fx = 0.0;
	double fxx = 0.0;
	double expder = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;
	double eps = 0.0;

	double X1 = 0.0;
	double Xn = 0.0;
	double Xn1 = 0.0;
	double X1n = 0.0;
	double iteration = 0.0;
	double root = 0.0;
	double root1 = 0.0;

	double Fxl = 0.0;
	double Fxu = 0.0;
	double Fxm = 0.0;
	double xl = 0.0;
	double xu = 0.0;
	double xm = 0.0;

	double FXn = 0.0;
	double FXXn = 0.0;
	double FX1n = 0.0;


	

	//***************************************************************************************
	//*******************  approximation d/dx(x^2 + 3) at x = 2.0  **************************
	//***************************************************************************************
	x = 2.0;
	h = 1.0;
	maxIteration = 55;
	expder = 4.0;
	dmaceps(&eps, &ipow);
	eabsolute = 1.0;

	printf("dmaceps =  %.8e\n", eps);
	printf("x = %lf\n", x);
	printf("d/dx(x^2 + 3) = %.12lf\n\n", expder);

	printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && maxIteration > 0 ) {

		maxIteration--;
		i++;
		
		fxx = derivative(fnct1, x, h);

		eabsolute = eabs(fxx, expder);
		erelative = erel(fxx, expder);
		
		printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fxx, h, eabsolute, erelative);
		h = h / 2.0;

	}
	printf("\n\n\n");


	//***************************************************************************************
	//*******************  approximation for d/dx(e^x) at x = 2.0  **************************
	//***************************************************************************************

	expder = 7.38905609893;
	eabsolute = 1.0;
	x = 2.0;
	h = 1.0;
	i = 0;
	maxIteration = 55;

	dmaceps(&eps, &ipow);

	printf("dmaceps =  %.8e\n", eps);
	printf("x = %lf\n", x);
	printf("d/dx(e^x) = %.12lf\n\n", expder);

	printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	

	while ( (eabsolute > eps) && maxIteration > 0 ) {

		maxIteration--;
		i++;

		fxx = derivative(exp, x, h);

		eabsolute = eabs(fxx, expder);
		erelative = erel(fxx, expder);

		printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fxx, h, eabsolute, erelative);
		h = h / 2.0;

	}
	printf("\n\n\n");

	//***************************************************************************************
	//*******************  approximation for d/dx( sqrt(x) ) at x = 2.0  ********************
	//***************************************************************************************

	expder = 0.353553390593;
	eabsolute = 1.0;
	erelative = 1.0;
	x = 2.0;
	h = 1.0;
	i = 0;
	maxIteration = 50;

	dmaceps(&eps, &ipow);

	printf("dmaceps =  %.8e\n", eps);
	printf("x = %lf\n", x);
	printf("d/dx( sqrt(x) ) = %.12lf\n\n", expder);

	printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && maxIteration > 0 ) {

		maxIteration--;
		i++;

		fxx = derivative(sqrt, x, h);

		eabsolute = eabs(fxx, expder);
		erelative = erel(fxx, expder);

		printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fxx, h, eabsolute, erelative);
		h = h / 2.0;

	}
	printf("\n\n\n");

	//***************************************************************************************
	//************* alternative approximation for d/dx( sqrt(x) ) at x = 2.0  ***************
	//***************************************************************************************

	expder = 0.353553390593;
	eabsolute = 1.0;
	x = 2.0;
	h = 1.0;
	i = 0;
	maxIteration = 55;

	dmaceps(&eps, &ipow);

	printf("dmaceps =  %.8e\n", eps);
	printf("x = %lf\n", x);
	printf("d/dx( sqrt(x) ) = %.12lf\n\n", expder);

	printf("i\t| alt appoximate derivative\t| h\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && maxIteration > 0 ) {

		maxIteration--;
		i++;

		fxx = ( (x+h) - x )/( h*( sqrt(x+h) + sqrt(x) ) );

		eabsolute = eabs(fxx, expder);
		erelative = erel(fxx, expder);

		printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fxx, h, eabsolute, erelative);
		h = h / 2.0;

	}
	printf("\n\n\n");


	//***************************************************************************************
	//************* direct use of d/dx( sqrt(x) ) =  1 / (2 * sqrt(x)), at x = 2.0  *********
	//***************************************************************************************

	expder = 0.353553390593;
	x = 2.0;
	dmaceps(&eps, &ipow);

	printf("dmaceps =  %.8e\n", eps);
	printf("x = %lf\n", x);
	printf("d/dx( sqrt(x) ) = %.12lf\n\n", expder);

	printf("direct derivative\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	fxx = 1 / (2 * sqrt(x));

	eabsolute = eabs(fxx, expder);
	erelative = erel(fxx, expder);

	printf("%.8e\t\t\t| %.3e\t| %.3e\n", fxx, eabsolute, erelative);

	printf("\n\n\n");


	//***************************************************************************************
	//************* approximation for d/dx( sin(x) ) at x = 0.0  ***************
	//***************************************************************************************

	x = 0.0;
	expder = 1.0;
	eabsolute = 1.0;
	erelative = 1.0;
	h = 1.0;
	i = 0;
	maxIteration = 50;

	dmaceps(&eps, &ipow);

	printf("dmaceps =  %.8e\n", eps);
	printf("x = %lf\n", x);
	printf("d/dx( sin(x) ) = %.12lf\n\n", expder);

	printf("i\t| appoximate derivative\t\t| h\t\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && maxIteration > 0 ) {

		maxIteration--;
		i++;

		fxx = derivative(sin, x, h);

		eabsolute = eabs(fxx, expder);
		erelative = erel(fxx, expder);

		printf("%d\t| %.8e\t\t| %.3e\t\t| %.3e\t| %.3e\n", i, fxx, h, eabsolute, erelative);
		h = h / 2.0;

	}
	printf("\n\n\n");


	//***************************************************************************************
	//************* taylor series approximation for d/dx( sin(x) ) at x = 0.0  **************
	//************************** f(x) = x - (x^3/6) *****************************************
	//***************************************************************************************

	x = 0.0;
	expder = 1.0;
	eabsolute = 1.0;
	erelative = 1.0;
	h = 1.0;
	i = 0;
	maxIteration = 50;

	dmaceps(&eps, &ipow);

	printf("dmaceps =  %.8e\n", eps);
	printf("x = %lf\n", x);
	printf("d/dx( sin(x) ) = %.12lf\n\n", expder);

	printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ((eabsolute > eps) && maxIteration > 0) {

		maxIteration--;
		i++;

		fxx = derivative(fnct2, x, h);

		eabsolute = eabs(fxx, expder);
		erelative = erel(fxx, expder);

		printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fxx, h, eabsolute, erelative);
		h = h / 2.0;

	}
	printf("\n\n\n");



	//***************************************************************************************
	//************ root finding fixed point iteration method 1 for x^2 - 3 ******************
	//***************************************************************************************

	Xn = 2;
	i = 0;
	count = 0;
	maxIteration = 10;
	root1 = 1.73205080757;
	dmaceps(&eps, &ipow);
	eabsolute = 1.0;

	printf("dmaceps =  %.8e\n", eps);
	printf("Initial value = %lf\n", Xn);
	printf("roots of x^2 - 3 are, +%.11lf and -%.11lf\n\n", root1, root1);
	printf("i\t| Xn\t\t\t| Xn+1\t\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && (maxIteration > 0) && (count < 5) ) {

		maxIteration--;
		i++;

		Xn1 = fixed1(fnct4, Xn);

		eabsolute = eabs(Xn1, root1);
		erelative = erel(Xn1, root1);

		printf("%d\t| %.8e\t| %.8e\t| %.3e\t| %.3e\n", i, Xn, Xn1, eabsolute, erelative);
		
		if ( fabs(Xn1) > fabs(Xn) ) count++;

		Xn = Xn1;
	}
	printf("\n\n\n");


	//***************************************************************************************
	//************ root finding fixed point iteration method 2 for x^2 - 3 ******************
	//***************************************************************************************

	Xn = 2;
	i = 0;
	count = 0;
	maxIteration = 10;
	root1 = 1.73205080757;
	dmaceps(&eps, &ipow);
	eabsolute = 1.0;

	printf("dmaceps =  %.8e\n", eps);
	printf("Initial value = %lf\n", Xn);
	printf("roots of x^2 - 3 are, +%.11lf and -%.11lf\n\n", root1, root1);
	printf("i\t| Xn\t\t\t| Xn+1\t\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ((eabsolute > eps) && (maxIteration > 0) && (count < 5)) {

		maxIteration--;
		i++;

		Xn1 = fixed2(fnct4, Xn);

		eabsolute = eabs(Xn1, root1);
		erelative = erel(Xn1, root1);

		printf("%d\t| %.8e\t| %.8e\t| %.3e\t| %.3e\n", i, Xn, Xn1, eabsolute, erelative);

		if ( fabs(Xn1) > fabs(Xn) ) count++;

		Xn = Xn1;
	}
	printf("\n\n\n");


	//*****************************************************************************************
	//* root finding fixed point iteration method 1 for sin(Pi*x), roots at n = 0, 1, 2, ...  *
	//*****************************************************************************************

	dmaceps(&eps, &ipow);
	Xn = 10.5;
	i = 0;
	count = 0;
	maxIteration = 10;
	root1 = 10.0;
	eabsolute = 1.0;

	printf("dmaceps =  %.8e\n", eps);
	printf("Initial value = %.1lf\n", Xn);
	printf("roots of sin(Pi * x), n, for n = 0, 1, 2, ... \n\n");
	printf("i\t| Xn\t\t\t| Xn+1\t\t\t|  e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && (maxIteration > 0) && (count < 5)) {
		
		maxIteration--;
		i++;

		Xn1 = fixed1(sin, (Xn*Pi));

		eabsolute = eabs(Xn1, root1);
		erelative = erel(Xn1, root1);

		printf("%d\t| %.8e\t| %.8e\t| %.3e\t| %.3e\n", i, Xn, Xn1, eabsolute, erelative);

		if ( fabs(Xn1) > fabs(Xn) ) count++;

		Xn = Xn1;

	}

	printf("\n\n\n");


	//*****************************************************************************************
	//* root finding fixed point iteration method 2 for sin(Pi*x), roots at n = 0, 1, 2, ...  *
	//*****************************************************************************************

	dmaceps(&eps, &ipow);
	Xn = 10.5;
	i = 0;
	count = 0;
	maxIteration = 10;
	root1 = 10.0;
	eabsolute = 1.0;

	printf("dmaceps =  %.8e\n", eps);
	printf("Initial value = %.1lf\n", Xn);
	printf("roots of sin(Pi * x), n, for n = 0, 1, 2, ... \n\n");
	printf("i\t| Xn\t\t\t| Xn+1\t\t\t|  e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ((eabsolute > eps) && (maxIteration > 0) && (count < 5)) {

		maxIteration--;
		i++;

		Xn1 = fixed2(sin, (Xn*Pi));

		eabsolute = eabs(Xn1, root1);
		erelative = erel(Xn1, root1);

		printf("%d\t| %.8e\t| %.8e\t| %.3e\t| %.3e\n", i, Xn, Xn1, eabsolute, erelative);

		if (fabs(Xn1) > fabs(Xn)) count++;

		Xn = Xn1;

	}

	printf("\n\n\n");


	//***************************************************************************************
	//********************* root finding bisection method for x^2 - 3 ***********************
	//***************************************************************************************

	dmaceps(&eps, &ipow);
	i = 0;
	xl = 0.0;
	xu = 100.0;
	maxIteration = bisMaxItr(xl, xu, eps);
	
	root1 = sqrt(3);

	printf("\n\nmax itterations = %d, for tollerence = %.8e\n", maxIteration, eps);
	printf("Lower initial value = %.1lf, Upper initial value = %.1lf\n", xl, xu);
	printf("i\t| root\n");
	printf("--------------------------------------------------------------------------------------------\n");

	root = bisection(fnct4, xl, xu, eps, maxIteration);

	printf("\n\n\n");


	//***************************************************************************************
	//********************* root finding bisection method for sin(Pi * x) *******************
	//***************************************************************************************

	dmaceps(&eps, &ipow);
	i = 0;
	xl = 1.75;
	xu = 2.25;
	maxIteration = bisMaxItr(xl, xu, eps);

	root1 = 2.0;

	printf("\n\nmax itterations = %d, for tollerence = %.8e\n", maxIteration, eps);
	printf("Lower initial value = %.1lf, Upper initial value = %.1lf\n", xl, xu);
	printf("i\t| root\n");
	printf("--------------------------------------------------------------------------------------------\n");

	root = bisection(fnct6, xl, xu, eps, maxIteration);

	printf("\n\n\n");


	//***************************************************************************************
	//*******************  root finding newtons method for x^2 - 3   ************************
	//***************************************************************************************
	
	dmaceps(&eps, &ipow);
	i = 0;
	Xn = 2.0;
	root1 = sqrt(3);
	maxIteration = 10;
	eabsolute = 1.0;

	printf("dmaceps =  %.8e\n", eps);
	printf("Initial value = %lf\n", Xn);
	printf("a root of x^2 - 3 = %.12lf\n\n", root1);
	printf("i\t| root\t\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && maxIteration > 0 ) {

		maxIteration--;
		i++;
		
		Xn1 = newton(fnct4, fnct5, Xn);

		eabsolute = eabs(Xn1, root1);
		erelative = erel(Xn1, root1);

		printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, Xn1, eabsolute, erelative);

		Xn = Xn1;
	}

	printf("\n\n\n");


	//***************************************************************************************
	//*******************  root finding newtons method for sin(Pi * x) **********************
	//***************************************************************************************

	dmaceps(&eps, &ipow);
	i = 0;
	Xn = 6.2;
	root1 = 6.0;
	maxIteration = 10;
	eabsolute = 1.0;

	printf("dmaceps =  %.8e\n", eps);
	printf("Initial value = %lf\n", Xn);
	printf("a root of sin(Pi * x) = %.12lf\n\n", root1);
	printf("i\t| root\t\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && maxIteration > 0 ) {

		maxIteration--;
		i++;

		Xn1 = newton(fnct6, fnct7, Xn);

		eabsolute = eabs(Xn1, root1);
		erelative = erel(Xn1, root1);

		printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, Xn1, eabsolute, erelative);

		Xn = Xn1;
	}

	printf("\n\n\n");


	//***************************************************************************************
	//*******************  root finding secant method for x^2 - 3   *************************
	//***************************************************************************************

	dmaceps(&eps, &ipow);
	i = 0;
	X1n = 3.0;
	Xn = 6.0;
	root1 = sqrt(3);
	maxIteration = 10;
	eabsolute = 1.0;

	printf("dmaceps =  %.8e\n", eps);
	printf("Initial values = %lf and %lf\n", X1n, Xn);
	printf("a root of x^2 - 3 = %.12lf\n\n", root1);

	printf("i\t| root\t\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && maxIteration > 0 ) {

		maxIteration--;
		i++;

		Xn1 = secant(fnct4, Xn, X1n);

		eabsolute = eabs(Xn1, root1);
		erelative = erel(Xn1, root1);

		printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, Xn1, eabsolute, erelative);

		X1n = Xn;
		Xn = Xn1;

	}

	printf("\n\n\n");


	//***************************************************************************************
	//*******************  root finding secant method for sin(Pi * x) ***********************
	//***************************************************************************************

	dmaceps(&eps, &ipow);
	i = 0;
	X1n = 3.2;
	Xn = 3.3;
	root1 = 3.0;
	maxIteration = 10;
	eabsolute = 1.0;

	printf("dmaceps =  %.8e\n", eps);
	printf("Initial values = %lf and %lf\n", X1n, Xn);
	printf("a root of sin(Pi * x) = %.12lf\n\n", root1);

	printf("i\t| root\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	while ( (eabsolute > eps) && maxIteration > 0 ) {

		maxIteration--;
		i++;
		
		Xn1 = secant(fnct6, Xn, X1n);

		eabsolute = eabs(Xn1, root1);
		erelative = erel(Xn1, root1);

		printf("%d\t| %.10lf\t| %.3e\t| %.3e\n", i, Xn1, eabsolute, erelative);

		X1n = Xn;
		Xn = Xn1;

	}

	printf("\n\n\n");

	return 0;
}