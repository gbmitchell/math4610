# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorNormL2

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorNorms.c

will produce an executable **vectorNorms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the L2-norm given a vector. The function was developed to compute the L2-norm of a vector with three elements or vector length of three. The L2-norm is used to give some sence of a magnitude for the given vector. The L2-norm for a vector is computed by summing the squre of each element of the vector and then take the square root of the sum.

**Input:** There are two inputs needed in this case. The vector (v1) of length three is passed to the function by reference. An argument for the length (n) of the vector is also passed to the function.

**Output:** This function returns a double precision value (ia) which represents the L2-norm of the input vector.

**Usage/Example:**

The function has two arguments needed to compute and return the value for L2-norm of the vector. The vector v1 of length three contains the double precision values 1.0, 2.0, and 3.0. A parameter len represents the lenght of the input vector. The function is then called with these input parameters and returns a double precision value which represents the L2-norm for the vector v1. 

#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, k = 0;
	double normL2 = 0.0;

	int n = 3;

	// alloc memory for a vector
	double *v1;
	v1 = calloc(n, sizeof(double));

	// assign values to vector v1
	k = 1;
	for (i = 0; i < n; i++) {
		v1[i] = k;
		k++;
	}

	printf("\n\nVector v1 =\n");

	printVector(v1, n);

	normL2 = vectorNormL2(v1, n);

	printf("\n\nL2 norm of v1 = %.3e\n", normL2);

	// free memory
	free(v1);

	return 0;
}

Output from the lines above:

    Vector v1 =
    1.000e+00
    2.000e+00
    3.000e+00

    L2 norm of v1 = 3.742e+00

The sum of the squared values in the vector v1 are (1 * 1) + (2 * 2) + (3 * 3) = 14, then the L2-norm = sqrt(14) = 3.742.

**Implementation/Code:** The following is the code for vectorNormL2()

    double vectorNormL2(double *up, int len) {
        int i = 0;
        double ia = 0.0;
        for (i = 0; i < len; i++) {
            ia = ia + (up[i] * up[i]);
        }
        ia = sqrt(ia);
        return ia;
    }

**Last Modified:** November/2018
