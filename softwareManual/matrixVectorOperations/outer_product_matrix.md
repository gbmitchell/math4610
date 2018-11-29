# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           outerProductMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixOuterProduct.c

will produce an executable **matrixOuterProduct.exe** that can be executed.

**Description/Purpose:** This function will take a 3x1 matrix and multiply it by a 1x3 matrix in double precision. The result is a 3x3 matrix and this is known as the outer product (a specific case of the kronecker product).

**Input:** There are five inputs needed in this case. Matrix x, y, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix x by matrix y transpose.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix x by matrix y transpose. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix x, y, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix x by matrix y transpose. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix x by matrix y transpose. The resulting matrix C can then be used in the main program as needed.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i, k = 0;
        int m = 3; // rows
        int n = 3; // col

        // alloc memory for a matrix
        double **C;
        C = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            C[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a vector
        double *x;
        x = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *y;
        y = calloc(n, sizeof(double));


        // assign even values to vector v
        k = 4;
        for (i = 0; i < n; i++) {
            x[i] = k;
            k++;
        }

        // assign even values to vector v
        k = 7;
        for (i = 0; i < n; i++) {
            y[i] = k;
            k++;
        }

        printf("\n\nVector x =\n");

        printVector(x, n);

        printf("\n\nVector y =\n");

        printVector(y, n);

        outerProductMatrix(x, y, C, m, n);

        printf("\n\nMatrix C = outer product of x and y\n");

        printMatrix(C, m, n);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(C[i]);
        }

        free(C);

        free(x);

        free(y);

        return 0;
    }    

Output from the lines above:

    Vector x =
    4.000e+00
    5.000e+00
    6.000e+00

    Vector y =
    7.000e+00
    8.000e+00
    9.000e+00

    Matrix C = outer product of x and y
    2.800e+01       3.200e+01       3.600e+01
    3.500e+01       4.000e+01       4.500e+01
    4.200e+01       4.800e+01       5.400e+01

The output shows the values for matrix x and y. Additionally, the output shows the matrix C which is the result of multiplying matrix x by matrix y transpose. The result is called the outer product.

**Implementation/Code:** The following is the code for outerProductMatrix()

    void outerProductMatrix(double *x, double *y, double **C, int m, int n) {
        int i, j = 0;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = x[i] * y[j];
            }
        }
    }

**Last Modified:** November/2018
