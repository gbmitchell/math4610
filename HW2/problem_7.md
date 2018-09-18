# Math 4610 Fundamentals of Computational Mathematics
Homework 2, problem 7.

**Routine Name:**           expbisection

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
	}

Output from the lines above:



The result in both cases is convergence to an approximation of a root for the defined functions f(x).

**Implementation/Code:** The following is the code for ()



**Last Modified:** September/2018
