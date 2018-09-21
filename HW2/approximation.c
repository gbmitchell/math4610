#include <stdio.h>
#include <math.h>
#include <mylib.h>


int main() {
	
	int i = 0;
	int ipow = 0;
	int  maxIteration = 0;
	
	double eps = 0.0;
	double eabsolute = 0.0;
	double erelative = 0.0;

	double x = 0.0;
	double h = 0.0;
	double expder = 0.0;
	double fxx = 0.0;
	
	double root = 0.0;
	double exproot = 0.0;

	double initialGuess = 0.0;
	double initialGuess1 = 0.0;

	double prec1 = 0.1; // 1 * 10^(-1)
	double prec10 = 0.0000000001; // 1 * 10^(-10)

	

	//***************************************************************************************
	//*******************  approximation d/dx(x^2 + 3) at x = 2.0  **************************
	//***************************************************************************************
	x = 2.0;
	h = 1.0;
	maxIteration = 55;
	expder = 4.0;
	dmaceps(&eps, &ipow);
	
	printf("approximation for d/dx(x^2 + 3)\n");

	fxx = expderivative(fnct1, x, h, eps, maxIteration, expder);

		

	//***************************************************************************************
	//*******************  approximation for d/dx(e^x) at x = 2.0  **************************
	//***************************************************************************************
	x = 2.0;
	h = 1.0;
	maxIteration = 55;
	expder = 7.38905609893;
	dmaceps(&eps, &ipow);

	printf("approximation for d/dx(e^x)\n");
	
	fxx = expderivative(exp, x, h, eps, maxIteration, expder);


	//***************************************************************************************
	//*******************  approximation for d/dx( sqrt(x) ) at x = 2.0  ********************
	//***************************************************************************************
	x = 2.0;
	h = 1.0;
	maxIteration = 50;
	expder = 0.353553390593;
	dmaceps(&eps, &ipow);

	printf("approximation for d/dx( sqrt(x) )\n");

	fxx = expderivative(sqrt, x, h, eps, maxIteration, expder);


	//***************************************************************************************
	//************* alternative approximation for d/dx( sqrt(x) ) at x = 2.0  ***************
	//***************************************************************************************
	x = 2.0;
	h = 1.0;
	maxIteration = 55;
	expder = 0.353553390593;
	dmaceps(&eps, &ipow);

	i = 0;
	eabsolute = 0.0;
	erelative = 0.0;

	printf("alternate approximation for d/dx( sqrt(x) )\n");
	printf("dmaceps =  %.8e\n", eps);
	printf("x = %lf\n", x);
	printf("expected derivative = %.12lf\n\n", expder);

	printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
	printf("--------------------------------------------------------------------------------------------\n");

	eabsolute = 10.0 * eps;

	while ((eabsolute > eps) && maxIteration > 0) {

		maxIteration--;
		i++;

		fxx = ((x + h) - x) / (h*(sqrt(x + h) + sqrt(x)));

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

	printf("direct use of d/dx( sqrt(x) ) = 1 / (2 * sqrt(x))\n");
	printf("dmaceps =  %.8e\n", eps);
	printf("x = %lf\n", x);
	printf("expected derivative = %.12lf\n\n", expder);

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
	h = 1.0;
	maxIteration = 50;
	expder = 1.0;
	dmaceps(&eps, &ipow);

	printf("approximation for d/dx( sin(x) )\n");

	fxx = expderivative(sin, x, h, eps, maxIteration, expder);


	//***************************************************************************************
	//************* taylor series approximation for d/dx( sin(x) ) at x = 0.0  **************
	//************************** f(x) = x - (x^3/6) *****************************************
	//***************************************************************************************
	x = 0.0;
	h = 1.0;
	maxIteration = 50;
	expder = 1.0;
	dmaceps(&eps, &ipow);

	printf("taylor series approximation for d/dx( sin(x) ) = d/dx( x - ( x^3/6 ) )\n");

	fxx = expderivative(fnct2, x, h, eps, maxIteration, expder);


	//***************************************************************************************
	//************ root finding fixed point iteration for x^2 - 3 ***************************
	//***************************************************************************************
	initialGuess = 2;
	maxIteration = 85;
	exproot = 1.73205080757;
	dmaceps(&eps, &ipow);

	root = fixed2(fnct8, initialGuess, eps, maxIteration, exproot);


	//*****************************************************************************************
	//**************** root finding fixed point iteration for sin(Pi*x)  **********************
	//*****************************************************************************************
	dmaceps(&eps, &ipow);
	initialGuess = 0.5;
	maxIteration = 100;
	exproot = 1.0;

	root = fixed1(fnct9, initialGuess, eps, maxIteration, exproot);



	//***************************************************************************************
	//********************* root finding bisection method for x^2 - 3 ***********************
	//***************************************************************************************
	initialGuess = 0.0;
	initialGuess1 = 100.0;
	exproot = sqrt(3);
	dmaceps(&eps, &ipow);
	maxIteration = bisMaxItr(initialGuess, initialGuess1, eps);
	dmaceps(&eps, &ipow);

	printf("bisection method approximation for f(x) = ( x^2 - 3 )\n");

	root = expbisection(fnct4, initialGuess, initialGuess1, eps, maxIteration, exproot);

	

	//***************************************************************************************
	//********************* root finding bisection method for sin(Pi * x) *******************
	//***************************************************************************************
	initialGuess = 1.75;
	initialGuess1 = 2.25;
	exproot = 2.0;
	dmaceps(&eps, &ipow);
	maxIteration = bisMaxItr(initialGuess, initialGuess1, eps);
	dmaceps(&eps, &ipow);

	printf("bisection method approximation for f(x) = sin(Pi * x)\n");

	root = expbisection(fnct6, initialGuess, initialGuess1, eps, maxIteration, exproot);



	//***************************************************************************************
	//*******************  root finding newtons method for x^2 - 3   ************************
	//***************************************************************************************
	initialGuess = 2.0;
	exproot = sqrt(3);
	maxIteration = 10;
	dmaceps(&eps, &ipow);

	printf("newton method approximation for f(x) = ( x^2 - 3 )\n");

	root = expnewton(fnct4, fnct5, initialGuess, eps, maxIteration, exproot);




	//***************************************************************************************
	//*******************  root finding newtons method for sin(Pi * x) **********************
	//***************************************************************************************
	initialGuess = 6.2;
	exproot = 6.0;
	maxIteration = 10;
	dmaceps(&eps, &ipow);
	
	printf("newton method approximation for f(x) = sin(Pi * x)\n");

	root = expnewton(fnct6, fnct7, initialGuess, eps, maxIteration, exproot);


	//***************************************************************************************
	//*******************  root finding secant method for x^2 - 3   *************************
	//***************************************************************************************
	initialGuess = 3.0;
	initialGuess1 = 6.0;
	exproot = sqrt(3);
	maxIteration = 10;
	dmaceps(&eps, &ipow);

	printf("secant method approximation for f(x) = ( x^2 - 3 )\n");

	root = expsecant(fnct4, initialGuess, initialGuess1, eps, maxIteration, exproot);



	//***************************************************************************************
	//*******************  root finding secant method for sin(Pi * x) ***********************
	//***************************************************************************************
	initialGuess = 3.2;
	initialGuess1 = 3.3;
	exproot = 3.0;
	maxIteration = 10;
	dmaceps(&eps, &ipow);

	printf("secant method approximation for f(x) = sin(Pi * x)\n");

	root = expsecant(fnct6, initialGuess, initialGuess1, eps, maxIteration, exproot);



	//***************************************************************************************
	//***************  root finding hybrid newton method for x^2 - 3   **********************
	//***************************************************************************************
	initialGuess = -1.54;
	initialGuess1 = 1.74;
	exproot = sqrt(3);
	maxIteration = 10;
	dmaceps(&eps, &ipow);

	printf("hybrid newton method approximation for f(x) = ( x^2 - 3 )\n\n");

	root = expNewtonHybrid(fnct4, fnct5, initialGuess, initialGuess1, prec10, maxIteration, exproot);



	//***************************************************************************************
	//***************  root finding hybrid newton method for sin(Pi * x) ********************
	//***************************************************************************************
	initialGuess = 2.99;
	initialGuess1 = 3.99;
	exproot = 3.0;
	maxIteration = 50;
	dmaceps(&eps, &ipow);

	printf("hybrid newton method approximation for f(x) = sin(Pi * x)\n\n");

	root = expNewtonHybrid(fnct6, fnct7, initialGuess, initialGuess1, prec10, maxIteration, exproot);




	//***************************************************************************************
	//***************  root finding hybrid secant method for x^2 - 3   **********************
	//***************************************************************************************
	initialGuess = -1.54;
	initialGuess1 = 1.74;
	exproot = sqrt(3);
	maxIteration = 10;
	dmaceps(&eps, &ipow);

	printf("hybrid secant method approximation for f(x) = ( x^2 - 3 )\n\n");

	root = expSecantHybrid(fnct4, initialGuess, initialGuess1, prec10, maxIteration, exproot);



	//***************************************************************************************
	//***************  root finding hybrid secant method for sin(Pi * x) ********************
	//***************************************************************************************
	initialGuess = 2.99;
	initialGuess1 = 3.99;
	exproot = 3.0;
	maxIteration = 10;
	dmaceps(&eps, &ipow);

	printf("hybrid secant method approximation for f(x) = sin(Pi * x)\n\n");

	root = expSecantHybrid(fnct6, initialGuess, initialGuess1, prec10, maxIteration, exproot);

	return 0;
}