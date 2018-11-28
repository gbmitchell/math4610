# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorNormInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorNorms.c

will produce an executable **vectorNorms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the Infinity-norm given a vector. The function was developed to compute the Infinity-norm of a vector with three elements or vector length of three. The Infinity-norm is used to give some sence of a magnitude for the given vector. The Infinity-norm for a vector is computed by identifying which element of the vector is the  maximum.

**Input:** There are two inputs needed in this case. The vector (v1) of length three is passed to the function by reference. An argument for the length (n) of the vector is also passed to the function.

**Output:** This function returns a double precision value (ia) which represents the Infinity-norm of the input vector.

**Usage/Example:**

The function has two arguments needed to compute and return the value for Infinity-norm of the vector. The vector v1 of length three contains the double precision values 1.0, 2.0, and 3.0. A parameter len represents the lenght of the input vector. The function is then called with these input parameters and returns a double precision value which represents the Infinity-norm for the vector v1. 

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i, k = 0;
        double normInfinity = 0.0;

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

        normInfinity = vectorNormInfinity(v1, n);

        printf("\n\nInfinity norm of v1 = %.3e\n", normInfinity);

        // free memory
        free(v1);

        return 0;
    }

Output from the lines above:

    Vector v1 =
    1.000e+00
    2.000e+00
    3.000e+00

    Infinity norm of v1 = 3.000e+00

The maximum value out of the vector elements 1.0, 2.0, and 3.0 is 3.0, therefore the Infinity-norm of the vector v1 is 3.0.

**Implementation/Code:** The following is the code for vectorNormInfinity()

    double vectorNormInfinity(double *up, int len) {
        int i = 0;
        double ia = 0.0;
        ia = fabs(up[0]);
        for (i = 0; i < len; i++) {
            if (fabs(up[i]) > ia) {
                ia = fabs(up[i]);
            }
        }
        return ia;
    }

**Last Modified:** November/2018
