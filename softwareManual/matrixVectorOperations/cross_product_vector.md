# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorCross

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorCrossProduct.c

will produce an executable **vectorCrossProduct.exe** that can be executed.

**Description/Purpose:** This function will compute the cross product of two vectors of the same size and the computation is done in double precision. 

**Input:** There are four inputs needed in this case. Vectors v1, v2, and a are arguments passed by reference and n is an argument passed to the function to indicate the length of the vectors. The real purpose is to produce values in the vector a that represents the cross product of the vectors v1 and v2.

**Output:** This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the cross product the vectors v1 and v2. The resulting vector a can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Vectors v1, v2, and a are arguments passed by reference and n is an argument passed to the function to indicate the length of the vectors. This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the cross product the vectors v1 and v2. The resulting vector a can then be used in the main program as needed.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i, k = 0;

        int n = 3;

        // alloc memory for a vector
        double *v1;
        v1 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *v2;
        v2 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *a;
        a = calloc(n, sizeof(double));

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

        vectorCross(v1, v2, a, n);

        printf("\n\nVector a = Cross Product of  v1 and v2\n");

        printVector(a, n);

        // free memory
        free(v1);
        free(v2);
        free(a);

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

    Vector a = Cross Product of  v1 and v2
    -3.000e+00
    6.000e+00
    -3.000e+00

The output shows the value for the vectors v1 and v2 as well as the resulting cross product of the two vectors.

**Implementation/Code:** The following is the code for vectorCross()

    void vectorCross(double *up, double *vp, double *ap, int len) {
        ap[0] = (up[1] * vp[2]) - (up[2] * vp[1]);
        ap[1] = (up[2] * vp[0]) - (up[0] * vp[2]);
        ap[2] = (up[0] * vp[1]) - (up[1] * vp[0]);
    }

**Last Modified:** November/2018
