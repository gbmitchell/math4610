# Math 4610 Fundamentals of Computational Mathematics
Homework 2, problem 6.

**Routine Name:**           expnewton

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** This function will compute an approximation for a root of a defined
function f(x) given two initial guesses with a root between them. The bisection root finding
method is based off of the intermediade value therom. Bisection tests the endpoints of an interval
using the function f(x), checks to make sure there is a difference in the sine to make sure a root
exists, divides the interval in half and repeats the check for each half. Itterations are done to
reduce the interval within a specified tolerance.

**Input:** There are six inputs needed in this cases. A defined function f(x), two initial guesses
bracketing the root (initialGuess and initialGuess1), a tolerance (eps), a maximum amount of times
to itterate (maxIteration), and the expected value of the root (exproot) to calculate the error for
analizing the bisection method.

**Output:** The function returns a double precision value that represents an approximation for the
root of a defined function f(x) given two initial guesses bracketing the root.

**Usage/Example:**

The code below uses two defined functions, f(x) = x^2 - 3 and f(x) = sin(Pi * x) as functions to find
the roots of. We know that x^3 -3 has a root at sqrt(3) and sin(Pi * x) has a root at 2.0. In the
following code, initial guesses were given that bracketed the known roots and error was calculated based
on the known roots to analize the behavior of the bisection method.

	#include <stdio.h>
	#include <math.h>
	#include <mylib.h>

	int main() {

		int ipow = 0;
		int  maxIteration = 0;
		double eps = 0.0;
		double root = 0.0;
		double exproot = 0.0;
		double initialGuess = 0.0;
	
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
	}

Output from the lines above:

	newton method approximation for f(x) = ( x^2 - 3 )
	dmaceps =  1.11022302e-16
	Initial value = 2.000000
	expected root = 1.732050807569
		
	i       | root                  | e absolute    | e relative
	--------------------------------------------------------------------------------------------
	1       | 1.75000000e+00        | 1.795e-02     | 1.036e-02
	2       | 1.73214286e+00        | 9.205e-05     | 5.314e-05
	3       | 1.73205081e+00        | 2.446e-09     | 1.412e-09
	4       | 1.73205081e+00        | 0.000e+00     | 0.000e+00
	
	
	
	newton method approximation for f(x) = sin(Pi * x)
	dmaceps =  1.11022302e-16
	Initial value = 6.200000
	expected root = 6.000000000000
	
	i       | root                  | e absolute    | e relative
	--------------------------------------------------------------------------------------------
	1       | 5.96873433e+00        | 3.127e-02     | 5.211e-03
	2       | 6.00010094e+00        | 1.009e-04     | 1.682e-05
	3       | 6.00000000e+00        | 3.383e-12     | 5.638e-13
	4       | 6.00000000e+00        | 8.882e-16     | 1.480e-16
	5       | 6.00000000e+00        | 0.000e+00     | 0.000e+00

The result in both cases is convergence to an approximation of a root for the defined functions f(x).

**Implementation/Code:** The following is the code for expnewton()

	double expnewton(double(*f)(double), double(*fp)(double), double x, double tol, int maxItr, double exproot) {
	
		int i = 0;
		double fxn1 = 0.0;
		double eabsolute = 0.0;
		double erelative = 0.0;
	
		printf("dmaceps =  %.8e\n", tol);
		printf("Initial value = %lf\n", x);
		printf("expected root = %.12lf\n\n", exproot);
		printf("i\t| root\t\t\t| e absolute\t| e relative\n");
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

**Last Modified:** September/2018
