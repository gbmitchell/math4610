# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           unitOrthog

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorUnitOrthoginal.c

will produce an executable **vectorUnitOrthoginal.exe** that can be executed.

**Description/Purpose:** This function will compute a pair of unit vectors u1 and u2 which are orthoginal to the original vectors v1 and v2. This is accomplished by taking the cross product of v1 and v2 to get an orthoginal vector. Then the L2-norm of the cross product is computed. Next, (v1 cross v2)/(L2-norm of v1 cross v2) gives a unit vector u1 orthoginal to v1 and v2. Last, negating u1 will give another unit vector u2 orthoginal to v1 and v2.

**Input:** There are five inputs needed in this case. The arguments v1, v2, u1, and u2 are passed by reference and the function will change the values in u1 and u2 to be used in the main program as needed. The variable len is also passed to the function to indicate the length of the vectors.

**Output:** This function does not return any values, rather it changes the values in u1 and u2 which were passed in by reference. After changing the values in u1 and u2, they can be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. The arguments v1, v2, u1, and u2 are passed by reference and the function will change the values in u1 and u2 to be used in the main program as needed. The variable len is also passed to the function to indicate the length of the vectors. This function does not return any values, rather it changes the values in u1 and u2 which were passed in by reference. After changing the values in u1 and u2, they can be used in the main program as needed.

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

        // alloc memory for a vector
        double *u1;
        u1 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *u2;
        u2 = calloc(n, sizeof(double));

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

        unitOrthog(v1, v2, u1, u2, n);

        printf("\n\n\nUnit orthoginal vector u1 =\n");

        printVector(u1, n);

        printf("\n\n\nUnit orthoginal vector u2 =\n");

        printVector(u2, n);

        // free memory
        free(v1);
        free(v2);
        free(u1);
        free(u2);

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

    Unit orthoginal vector u1 =
    -4.082e-01
    8.165e-01
    -4.082e-01

    Unit orthoginal vector u2 =
    4.082e-01
    -8.165e-01
    4.082e-01

The output shows what the original vectors v1 and v2 are. After the unitOrthog routine is called the resulting unit orthoginal vectors u1 and u2 are displayed.

**Implementation/Code:** The following is the code for unitOrthog()

    void unitOrthog(double *v1, double *v2, double *u1, double *u2, int len) {

        int i = 0;
        double ia = 0;

        // alloc memory for a vector
        double *a;
        a = calloc(len, sizeof(double));

        vectorCross(v1, v2, a, len);

        ia = vectorNormL2(a, len);

        ia = 1 / ia;

        vectorScale(a, u1, ia, len);

        vectorScale(u1, u2, -1.0, len);

        // free memory
        free(a);
    }

**Last Modified:** November/2018
