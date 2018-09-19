# Math 4610 Fundamentals of Computational Mathematics
Homework 2, problem 7.

**Routine Name:**           expsecant

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** This function will compute an approximation for a root of a defined
function f(x) given two initial guesses for the root (guesses do not have to brakcet the root).
The secant root finding method uses the secant line of f(x) at the initial guesses. Where the
secannt line crosses the x axis is the approximation for the root. Recusivly applying the new
approximation as one of the guesses will converge to a root.

**Input:** There are six inputs needed in this cases. A defined function f(x), two initial guesses
for the root (initialGuess and initialGuess1), a tolerance (eps), a maximum amount of times to
itterate (maxIteration), and the expected value of the root (exproot) to calculate the error for
analizing the secant method.

**Output:** The function returns a double precision value that represents an approximation for the
root of a defined function f(x) given two initial guesses for the root.

**Usage/Example:**

The code below uses two defined functions, f(x) = x^2 - 3 and f(x) = sin(Pi * x) as functions to find
the roots of. We know that x^2 - 3 has a root at sqrt(3) and sin(Pi * x) has a root at 3.0. In the
following code, two initial guesses were given relativly close to these known roots and error was
calculated based on the known roots to analize the behavior of the secant method.


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
		double initialGuess1 = 0.0;
	
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
	}

Output from the lines above:

	secant method approximation for f(x) = ( x^2 - 3 )
	dmaceps =  1.11022302e-16
	Initial values = 3.000000 and 6.000000
	expected root = 1.732050807569
	
	i       | root                  | e absolute    | e relative
	--------------------------------------------------------------------------------------------
	1       | 2.33333333e+00        | 6.013e-01     | 3.472e-01
	2       | 2.04000000e+00        | 3.079e-01     | 1.778e-01
	3       | 1.77439024e+00        | 4.234e-02     | 2.444e-02
	4       | 1.73546902e+00        | 3.418e-03     | 1.974e-03
	5       | 1.73209204e+00        | 4.123e-05     | 2.381e-05
	6       | 1.73205085e+00        | 4.065e-08     | 2.347e-08
	7       | 1.73205081e+00        | 4.838e-13     | 2.793e-13
	8       | 1.73205081e+00        | 2.220e-16     | 1.282e-16
	9       | 1.73205081e+00        | 0.000e+00     | 0.000e+00
	
	
	
	secant method approximation for f(x) = sin(Pi * x)
	dmaceps =  1.11022302e-16
	Initial values = 3.200000 and 3.300000
	expected root = 3.000000000000
	
	i       | root                  | e absolute    | e relative
	--------------------------------------------------------------------------------------------
	1       | 2.93431242e+00        | 6.569e-02     | 2.190e-02
	2       | 3.00821391e+00        | 8.214e-03     | 2.738e-03
	3       | 2.99994878e+00        | 5.122e-05     | 1.707e-05
	4       | 3.00000001e+00        | 5.650e-09     | 1.883e-09
	5       | 3.00000000e+00        | 0.000e+00     | 0.000e+00

The result in both cases is convergence to an approximation of a root for the defined functions f(x).

**Implementation/Code:** The following is the code for expsecant()

	double expsecant(double(*f)(double), double xa, double xb, double tol, int maxItr, double exproot) {
	
		int i = 0;
		double fxn1 = 0.0;
		double eabsolute = 0.0;
		double erelative = 0.0;
	
		printf("dmaceps =  %.8e\n", tol);
		printf("Initial values = %lf and %lf\n", xa, xb);
		printf("expected root = %.12lf\n\n", exproot);
	
		printf("i\t| root\t\t\t| e absolute\t| e relative\n");
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

**Last Modified:** September/2018
