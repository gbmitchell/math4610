# Math 4610 Fundamentals of Computational Mathematics
Homework 2 problem 8.

**Routine Name:**           fixed1

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** These functions will compute an approximation for a root of a defined
function f(x) given an initial guess for the value of x. The function fixed1 takes the form of
g(x) = x + f(x) and the function fixed2 takes the form g(x) = x - f(x). These can then be used
for itteratoin g(Xn+1) = Xn + f(Xn) or g(Xn+1) = Xn - f(Xn) to approximate the root of a defined
function f(x). Where xr is the root, g'(xr) must be less than 1 in order for the itteration to
converge. 

**Input:** There are five inputs needed in these cases. A defined function f(x), an initial guess
for the root (initialGuess), a tolerance (eps), a maximum amount of times to itterate (maxIteration),
and the expected value of the root (exproot) to calculate the error for analizing the fixed itteration
functions.

**Output:** The functions return a double precision value that represents an approximation for the
root of a defined function f(x) given an initial guess for the root.

**Usage/Example:**

The functions return an approximation for the root of a defined function f(x) given an initial guess for
the root. The goal is to find a function g(x) = x and recursivly itterate the function until an approximate
root is found within an acceptable tolerance. The code below uses two defined functions, f(x) = x^2 - 3 and
f(x) = sin(Pi * x) as functions to find the roots of. To find the funcion g(x) = x, the function f(x) is set
equal to zero and either add or subtract x to both sides of the equation. The result is an equation in the
form of g(Xn+1) = Xn + f(Xn) that can be itterated until g(Xn+1) is approximatly equal to the expected root.
To meet the requirement of g'(xr) less than 1, the initial functions for f(x) were divided by 10.

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
