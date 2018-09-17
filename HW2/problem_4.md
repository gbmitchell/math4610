# Math 4610 Fundamentals of Computational Mathematics
Homework 2 problem 4.

**Routine Name:**           fixed1, fixed2

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** These functions will compute an approximation for a root of a defined
function f(x) given an initial guess for the value of x.

**Input:** There are two inputs needed in these cases. A defined function f(x) and an initial guess
for the value of x are arguments passed to the functions as inputs.

**Output:** The functions return a double precision value that represents an approximation for the
root of a defined function f(x) given an initial guess for x.

**Usage/Example:**

The functions return an approximation for the root of a defined function f(x) at a guess for the value of x.
The goal is to find a function g(x) = x and recursivly itterate the function until an approximate root is
found within an acceptable tolerance. The code below uses two defined functions, f(x) = x^2 - 3 and f(x) =
sin(Pi * x) as functions to find the roots of. To find the funcion g(x) = x, the function f(x) is set equal
to zero and either add or subtract x to both sides of the equation. The result is an equation in the form of
X(n+1) = X(n) + C that can be itterated until X(n+1) is approximatly equal to X(n).

    #include <stdio.h>
    #include <math.h>
    #include <mylib.h>
    
    int main() {
        double Pi = 3.1415926535897932384626433832795028841971693993751058209749445923;
        int i = 0, j = 0, maxIteration = 0;
        int ipow = 0;
        double eps = 0.0;
        double x = 0.0;
        double h = 0.0;
        double fxx = 0.0;
        double expder = 0.0;
        double eabsolute = 0.0;
        double erelative = 0.0;
    
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
    
Output from the lines above:

    

First the derivative function was used to approximate the derivative of sqrt(x) at x = 2.0 and the
approximation converged to an approximate value of 3.53553385e-01 with absolute error of 6.051e-09.
The approximation then began to move away from the correct value and the error increased. Next the 
dirivative function was rewriten by multiplying by the conjugate and the approximation converged
to a value of 3.53553391e-01 and absolute error of 2.737e-13. Finaly the direct derivative of sqrt(x)
was used and produced a value of 3.53553391e-01 and absolute error of 2.737e-13. Rewriting the
derivative provided a better function for approximation as can be seen by comparing the result with the
dirrect use of the derivative.

**Implementation/Code:** The following is the code for derivative()

    double derivative(double(*f)(double), double x, double h) {
        double fxx = 0.0;
        fxx = (f(x + h) - f(x)) / (h);
        return fxx;
    }

**Last Modified:** September/2018
