# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorErrorRelativeL2

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorError.c

will produce an executable **vectorError.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for relative error between an exact vector x and a vector y which is the approximation to the vector x. Computing the relative error between an exact and approximate vector involves taking the difference between the two and computing the L2-norm of the difference. The L2-norm of the difference divided by the L2-norm of x results in a single value to give some idea of the relative error in an approximation to the exact vector.

**Input:** There are two inputs needed in this case. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function.

**Output:** This function returns a double precision value erel which represents the relative error between the two input vectors x and y.

**Usage/Example:**

The function has three input arguments needed to produce the relative error. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function. The function returns a double precision value erel which represents the relative error between the two input vectors x and y.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i = 0;
        double k = 0.0;
        double erelL2 = 0.0;

        int n = 3;

        // alloc memory for a vector
        double *x;
        x = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *y;
        y = calloc(n, sizeof(double));

        // assign values to vector x
        k = -1.125;
        for (i = 0; i < n; i++) {
            x[i] = k;
            k = k + 1.25;
        }

        // assign values to vector y
        k = -1.0;
        for (i = 0; i < n; i++) {
            y[i] = k;
            k = k + 1.25;
        }

        printf("\n\nExact vector x =\n");

        printVector(x, n);

        printf("\n\nApproximate vector y =\n");

        printVector(y, n);

        erelL2 = vectorErrorRelativeL2(x, y, n);

        printf("\n\nRelative error using L2 norm = %.3e\n", erelL2);

        // free memory
        free(x);
        free(y);

        return 0;
    }

Output from the lines above:

    Exact vector x =
    -1.125e+00
    1.250e-01
    1.375e+00

    Approximate vector y =
    -1.000e+00
    2.500e-01
    1.500e+00

    Relative error using L2 norm = 1.216e-01

The output displays the values of the exact vector x and its approximation vector y. The error vector e = x-y and the L2-norm of the vector e represents the absolute error, the absolute error divided by the L2-norm of x is the relative error and in this case L2-erel = 0.1216.

**Implementation/Code:** The following is the code for vectorErrorRelativeL2()
    
    double vectorErrorRelativeL2(double *xp, double *yp, int len) {

        double erel = 0.0;
        double a = 0.0;

        a = vectorNormL2(xp, len);

        erel = (vectorErrorAbsoluteL2(xp, yp, len)) / a;

        return erel;
    }

**Last Modified:** November/2018
