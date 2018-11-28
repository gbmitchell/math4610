# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorInner

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorInnerProduct.c

will produce an executable **vectorInnerProduct.exe** that can be executed.

**Description/Purpose:** This function will compute the inner product of two vectors of the same size and the computation is done in double precision. 

**Input:** There are three inputs needed in this case. Vectors v1 and v2 are arguments passed by reference and n is an argument passed to the function to indicate the length of the vectors.

**Output:** This function returns a double precision value which represents the inner product of the vectors v1 and v2.

**Usage/Example:**

There are three inputs needed in this case. Vectors v1 and v2 are arguments passed by reference and n is an argument passed to the function to indicate the length of the vectors. This function returns a double precision value ia, which represents the inner product of the vectors v1 and v2.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i, k = 0;
        double innerProduct = 0.0;

        int n = 3;

        // alloc memory for a vector
        double *v1;
        v1 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *v2;
        v2 = calloc(n, sizeof(double));

        // assign values to vector v1
        k = 4;
        for (i = 0; i < n; i++) {
            v1[i] = k;
            k++;
        }

        // assign values to vector v2
        k = 7;
        for (i = 0; i < n; i++) {
            v2[i] = k;
            k++;
        }

        printf("\n\nVector v1 =\n");

        printVector(v1, n);

        printf("\n\nVector v2 =\n");

        printVector(v2, n);

        innerProduct = vectorInner(v1, v2, n);

        printf("\n\nInner Product of  v1 and v2 = %.3e\n", innerProduct);

        // free memory
        free(v1);
        free(v2);

        return 0;
    }

Output from the lines above:

    Vector v1 =
    4.000e+00
    5.000e+00
    6.000e+00

    Vector v2 =
    7.000e+00
    8.000e+00
    9.000e+00

    Inner Product of  v1 and v2 = 1.220e+02

The output shows the value for the vectors v1 and v2 as well as the resulting inner product of the vectors.

**Implementation/Code:** The following is the code for vectorInner()

    double vectorInner(double *up, double *vp, int len) {
        int i = 0;
        double ia = 0.0;
        for (i = 0; i < len; i++) {
            ia = ia + (up[i] * vp[i]);
        }
        return ia;
    }

**Last Modified:** November/2018
