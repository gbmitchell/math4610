# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorScale

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorScale.c

will produce an executable **vectorScale.exe** that can be executed.

**Description/Purpose:** This function will scale a vector by a value defined by the variable scaler. Given a vector v1, the function will multiply each element of the vector by a scale value which results in a new vector with scaled values. 

**Input:** There are four inputs needed in this case. Vectors v1 and a are arguments passed by reference. Scaler and n are arguments passed to the function to indicate the scale value and the length of the vectors. The real purpose is to produce values in the vector a that represent the result of scaler * v1.

**Output:** This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of scaling the vector v1 by the scaler value. The resulting vector a can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Vectors v1 and a are arguments passed by reference. Scaler and n are arguments passed to the function to indicate the scale value and the length of the vectors. The real purpose is to produce values in the vector a that represent the result of scaler * v1. This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of scaling the vector v1 by the scaler value. The resulting vector a can then be used in the main program as needed

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i, k = 0;
        double scaler = 5.0;

        int n = 3;

        // alloc memory for a vector
        double *v1;
        v1 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *a;
        a = calloc(n, sizeof(double));


        // assign values to vector v1
        k = 4;
        for (i = 0; i < n; i++) {
            v1[i] = k;
            k++;
        }

        printf("\n\nVector v1 =\n");

        printVector(v1, n);

        vectorScale(v1, a, scaler, n);

        printf("\n\nVector a = 5 * v1\n");

        printVector(a, n);

        // free memory
        free(v1);
        free(a);

        return 0;
    }

Output from the lines above:

    Vector v1 =
    4.000e+00
    5.000e+00
    6.000e+00

    Vector a = 5 * v1
    2.000e+01
    2.500e+01
    3.000e+01

The output shows the value for the vector u and the result of scaling the vector u by a value of 5.0.

**Implementation/Code:** The following is the code for vectorScale()

    void vectorScale(double *up, double *ap, double scale, int len) {
        int i = 0;
        for (i = 0; i < len; i++) {
            ap[i] = scale * up[i];
        }
    }

**Last Modified:** November/2018
