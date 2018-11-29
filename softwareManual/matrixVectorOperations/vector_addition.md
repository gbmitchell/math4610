# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorAdd

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorAdd.c

will produce an executable **vectorAdd.exe** that can be executed.

**Description/Purpose:** This function will add two vectors of the same size and the computation is done in double precision. 

**Input:** There are four inputs needed in this case. Vectors v1, v2, and a are arguments passed by reference and n is an argument passed to the function to indicate the length of the vectors. The real purpose is to produce values in the vector a that represent the result of v1 + v2.

**Output:** This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of adding the vectors v1 and v2. The resulting vector a can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Vectors v1, v2, and a are arguments passed by reference and n is an argument passed to the function to indicate the length of the vectors. This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of adding the vectors v1 and v2. The resulting vector a can then be used in the main program as needed.

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

        vectorAdd(v1, v2, a, n);

        printf("\n\nVector a = v1 + v2\n");

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

    Vector a = v1 + v2
    1.100e+01
    1.300e+01
    1.500e+01

The output shows the value for the vectors v1 and v2 as well as the result of adding the two vectors.

**Implementation/Code:** The following is the code for vectorAdd()

    void vectorAdd(double *up, double *vp, double *ap, int len) {
        int i = 0;
        for (i = 0; i < len; i++) {
            ap[i] = up[i] + vp[i];
        }
    }

**Last Modified:** November/2018
