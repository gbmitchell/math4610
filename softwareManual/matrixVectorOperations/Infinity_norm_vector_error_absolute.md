# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorErrorAbsoluteInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorError.c

will produce an executable **vectorError.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for absolute error between an exact vector x and a vector y which is the approximation to the vector x. Computing the absolute error between an exact and approximate vector involves taking the difference between the two and computing the Infinity-norm of the difference. The result is a single value to give some idea of the absolute error in an approximation to the exact vector.

**Input:** There are two inputs needed in this case. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function.

**Output:** This function returns a double precision value eabs which represents the absolute error between the two input vectors x and y.

**Usage/Example:**

The function has three input arguments needed to produce the absolute error. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function. The function returns a double precision value eabs which represents the absolute error between the two input vectors x and y.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i = 0;
        double k = 0.0;
        double eabsInfinity = 0.0;

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

        eabsInfinity = vectorErrorAbsoluteInfinity(x, y, n);

        printf("\n\nAbsolut error using Infinity norm = %.3e\n", eabsInfinity);

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

    Absolut error using Infinity norm = 1.250e-01

The output displays the values of the exact vector x and its approximation vector y. The error vector e = x-y and the Infinity-norm of the vector e represents the absolute error, in this case Infinity-eabs = 0.250.

**Implementation/Code:** The following is the code for vectorErrorAbsoluteInfinity()
    
    double vectorErrorAbsoluteInfinity(double *xp, double *yp, int len) {

        double eabs = 0.0;
        int i = 0;

        // alloc memory for a vector
        double *e;
        e = calloc(len, sizeof(double));

        vectorSub(xp, yp, e, len);

        eabs = vectorNormInfinity(e, len);

        // free memory
        free(e);

        return eabs;
    }

**Last Modified:** November/2018
