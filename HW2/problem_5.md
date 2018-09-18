# Math 4610 Fundamentals of Computational Mathematics
Homework 2, problem 5.

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
		double initialGuess1 = 0.0;

		//***************************************************************************************
		//********************* root finding bisection method for x^2 - 3 ***********************
		//***************************************************************************************
		initialGuess = 0.0;
		initialGuess1 = 100.0;
		exproot = sqrt(3);
		dmaceps(&eps, &ipow);
		maxIteration = bisMaxItr(initialGuess, initialGuess1, eps);

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

		printf("bisection method approximation for f(x) = sin(Pi * x)\n");

		root = expbisection(fnct6, initialGuess, initialGuess1, eps, maxIteration, exproot);
	}

Output from the lines above:

	bisection method approximation for f(x) = ( x^2 - 3 )
	max itterations = 60, for tollerence = 9.60171520e-306
	Lower initial value = 0.0, Upper initial value = 100.0
	
	expected root = 1.732050807569
	
	i       | root                  | e absolute    | e relative
	--------------------------------------------------------------------------------------------
	1       | 5.00000000e+01        | 4.827e+01     | 2.787e+01
	2       | 2.50000000e+01        | 2.327e+01     | 1.343e+01
	3       | 1.25000000e+01        | 1.077e+01     | 6.217e+00
	4       | 6.25000000e+00        | 4.518e+00     | 2.608e+00
	5       | 3.12500000e+00        | 1.393e+00     | 8.042e-01
	6       | 1.56250000e+00        | 1.696e-01     | 9.789e-02
	7       | 2.34375000e+00        | 6.117e-01     | 3.532e-01
	8       | 1.95312500e+00        | 2.211e-01     | 1.276e-01
	9       | 1.75781250e+00        | 2.576e-02     | 1.487e-02
	10      | 1.66015625e+00        | 7.189e-02     | 4.151e-02
	11      | 1.70898438e+00        | 2.307e-02     | 1.332e-02
	12      | 1.73339844e+00        | 1.348e-03     | 7.781e-04
	13      | 1.72119141e+00        | 1.086e-02     | 6.270e-03
	14      | 1.72729492e+00        | 4.756e-03     | 2.746e-03
	15      | 1.73034668e+00        | 1.704e-03     | 9.839e-04
	16      | 1.73187256e+00        | 1.782e-04     | 1.029e-04
	17      | 1.73263550e+00        | 5.847e-04     | 3.376e-04
	18      | 1.73225403e+00        | 2.032e-04     | 1.173e-04
	19      | 1.73206329e+00        | 1.249e-05     | 7.209e-06
	20      | 1.73196793e+00        | 8.288e-05     | 4.785e-05
	21      | 1.73201561e+00        | 3.520e-05     | 2.032e-05
	22      | 1.73203945e+00        | 1.136e-05     | 6.556e-06
	23      | 1.73205137e+00        | 5.650e-07     | 3.262e-07
	24      | 1.73204541e+00        | 5.396e-06     | 3.115e-06
	25      | 1.73204839e+00        | 2.415e-06     | 1.394e-06
	26      | 1.73204988e+00        | 9.252e-07     | 5.341e-07
	27      | 1.73205063e+00        | 1.801e-07     | 1.040e-07
	28      | 1.73205100e+00        | 1.924e-07     | 1.111e-07
	29      | 1.73205081e+00        | 6.166e-09     | 3.560e-09
	30      | 1.73205072e+00        | 8.697e-08     | 5.021e-08
	31      | 1.73205077e+00        | 4.040e-08     | 2.333e-08
	32      | 1.73205079e+00        | 1.712e-08     | 9.883e-09
	33      | 1.73205080e+00        | 5.476e-09     | 3.161e-09
	34      | 1.73205081e+00        | 3.449e-10     | 1.991e-10
	35      | 1.73205081e+00        | 2.565e-09     | 1.481e-09
	36      | 1.73205081e+00        | 1.110e-09     | 6.410e-10
	37      | 1.73205081e+00        | 3.827e-10     | 2.210e-10
	38      | 1.73205081e+00        | 1.891e-11     | 1.092e-11
	39      | 1.73205081e+00        | 1.630e-10     | 9.410e-11
	40      | 1.73205081e+00        | 7.204e-11     | 4.159e-11
	41      | 1.73205081e+00        | 2.656e-11     | 1.534e-11
	42      | 1.73205081e+00        | 3.828e-12     | 2.210e-12
	43      | 1.73205081e+00        | 7.541e-12     | 4.354e-12
	44      | 1.73205081e+00        | 1.857e-12     | 1.072e-12
	45      | 1.73205081e+00        | 9.854e-13     | 5.689e-13
	46      | 1.73205081e+00        | 4.357e-13     | 2.515e-13
	47      | 1.73205081e+00        | 2.749e-13     | 1.587e-13
	48      | 1.73205081e+00        | 8.038e-14     | 4.641e-14
	49      | 1.73205081e+00        | 9.726e-14     | 5.615e-14
	50      | 1.73205081e+00        | 8.438e-15     | 4.872e-15
	51      | 1.73205081e+00        | 3.597e-14     | 2.077e-14
	52      | 1.73205081e+00        | 1.377e-14     | 7.948e-15
	53      | 1.73205081e+00        | 2.665e-15     | 1.538e-15
	54      | 1.73205081e+00        | 2.887e-15     | 1.667e-15
	55      | 1.73205081e+00        | 0.000e+00     | 0.000e+00
	56      | 1.73205081e+00        | 1.332e-15     | 7.692e-16
	57      | 1.73205081e+00        | 6.661e-16     | 3.846e-16
	58      | 1.73205081e+00        | 4.441e-16     | 2.564e-16
	59      | 1.73205081e+00        | 2.220e-16     | 1.282e-16
	60      | 1.73205081e+00        | 0.000e+00     | 0.000e+00
	
	
	
	bisection method approximation for f(x) = sin(Pi * x)
	max itterations = 53, for tollerence = 9.60171520e-306
	Lower initial value = 1.8, Upper initial value = 2.3
	
	expected root = 2.000000000000
	
	i       | root                  | e absolute    | e relative
	--------------------------------------------------------------------------------------------
	1       | 2.00000000e+00        | 0.000e+00     | 0.000e+00
	2       | 2.12500000e+00        | 1.250e-01     | 6.250e-02
	3       | 2.06250000e+00        | 6.250e-02     | 3.125e-02
	4       | 2.03125000e+00        | 3.125e-02     | 1.563e-02
	5       | 2.01562500e+00        | 1.563e-02     | 7.813e-03
	6       | 2.00781250e+00        | 7.813e-03     | 3.906e-03
	7       | 2.00390625e+00        | 3.906e-03     | 1.953e-03
	8       | 2.00195313e+00        | 1.953e-03     | 9.766e-04
	9       | 2.00097656e+00        | 9.766e-04     | 4.883e-04
	10      | 2.00048828e+00        | 4.883e-04     | 2.441e-04
	11      | 2.00024414e+00        | 2.441e-04     | 1.221e-04
	12      | 2.00012207e+00        | 1.221e-04     | 6.104e-05
	13      | 2.00006104e+00        | 6.104e-05     | 3.052e-05
	14      | 2.00003052e+00        | 3.052e-05     | 1.526e-05
	15      | 2.00001526e+00        | 1.526e-05     | 7.629e-06
	16      | 2.00000763e+00        | 7.629e-06     | 3.815e-06
	17      | 2.00000381e+00        | 3.815e-06     | 1.907e-06
	18      | 2.00000191e+00        | 1.907e-06     | 9.537e-07
	19      | 2.00000095e+00        | 9.537e-07     | 4.768e-07
	20      | 2.00000048e+00        | 4.768e-07     | 2.384e-07
	21      | 2.00000024e+00        | 2.384e-07     | 1.192e-07
	22      | 2.00000012e+00        | 1.192e-07     | 5.960e-08
	23      | 2.00000006e+00        | 5.960e-08     | 2.980e-08
	24      | 2.00000003e+00        | 2.980e-08     | 1.490e-08
	25      | 2.00000001e+00        | 1.490e-08     | 7.451e-09
	26      | 2.00000001e+00        | 7.451e-09     | 3.725e-09
	27      | 2.00000000e+00        | 3.725e-09     | 1.863e-09
	28      | 2.00000000e+00        | 1.863e-09     | 9.313e-10
	29      | 2.00000000e+00        | 9.313e-10     | 4.657e-10
	30      | 2.00000000e+00        | 4.657e-10     | 2.328e-10
	31      | 2.00000000e+00        | 2.328e-10     | 1.164e-10
	32      | 2.00000000e+00        | 1.164e-10     | 5.821e-11
	33      | 2.00000000e+00        | 5.821e-11     | 2.910e-11
	34      | 2.00000000e+00        | 2.910e-11     | 1.455e-11
	35      | 2.00000000e+00        | 1.455e-11     | 7.276e-12
	36      | 2.00000000e+00        | 7.276e-12     | 3.638e-12
	37      | 2.00000000e+00        | 3.638e-12     | 1.819e-12
	38      | 2.00000000e+00        | 1.819e-12     | 9.095e-13
	39      | 2.00000000e+00        | 9.095e-13     | 4.547e-13
	40      | 2.00000000e+00        | 4.547e-13     | 2.274e-13
	41      | 2.00000000e+00        | 2.274e-13     | 1.137e-13
	42      | 2.00000000e+00        | 1.137e-13     | 5.684e-14
	43      | 2.00000000e+00        | 5.684e-14     | 2.842e-14
	44      | 2.00000000e+00        | 2.842e-14     | 1.421e-14
	45      | 2.00000000e+00        | 1.421e-14     | 7.105e-15
	46      | 2.00000000e+00        | 7.105e-15     | 3.553e-15
	47      | 2.00000000e+00        | 3.553e-15     | 1.776e-15
	48      | 2.00000000e+00        | 1.776e-15     | 8.882e-16
	49      | 2.00000000e+00        | 8.882e-16     | 4.441e-16
	50      | 2.00000000e+00        | 4.441e-16     | 2.220e-16
	51      | 2.00000000e+00        | 0.000e+00     | 0.000e+00
	52      | 2.00000000e+00        | 0.000e+00     | 0.000e+00
	53      | 2.00000000e+00        | 0.000e+00     | 0.000e+00

The result in both cases is convergence to an approximation of a root for the defined functions f(x).

**Implementation/Code:** The following is the code for expbisection()

	double expbisection(double(*f)(double), double a, double b, int tol, int maxItr, double exproot) {
		int i = 0;
		double c = 0.0;
		double Fxc = 1.0;
		double Fxa = f(a);
		double Fxb = f(b);
		double root = 0.0;
		double eabsolute = 0.0;
		double erelative = 0.0;

		printf("max itterations = %d, for tollerence = %.8e\n", maxItr, tol);
		printf("Lower initial value = %.1lf, Upper initial value = %.1lf\n\n", a, b);
		printf("expected root = %.12lf\n\n", exproot);
		printf("i\t| root\t\t\t| e absolute\t| e relative\n");
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

**Last Modified:** September/2018
