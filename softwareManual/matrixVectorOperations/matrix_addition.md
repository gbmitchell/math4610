# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           matrixAdd

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixAdd.c

will produce an executable **matrixAdd.exe** that can be executed.

**Description/Purpose:** This function will add two square matrices of the same size, in this case 3x3. The computation is done in double precision. 

**Input:** There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of adding the matrices A + B.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of adding the matrices A + B. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of adding the matrices A + B. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of adding the matrices A + B. The resulting matrix C can then be used in the main program as needed.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i, j, k = 0;
        int m = 3; // rows
        int n = 3; // col

        // alloc memory for a matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a matrix
        double **B;
        B = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            B[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a matrix
        double **C;
        C = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            C[i] = calloc(n, sizeof(double));
        }

        // assign even values to matrix A
        k = 1;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = k * 2;
                k++;
            }
        }

        // assign odd values to matrix B
        k = 1;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                B[i][j] = (k * 2) - 1;
                k++;
            }
        }

        printf("\n\nMatrix A =\n");

        printMatrix(A, m, n);

        printf("\n\nMatrix B =\n");

        printMatrix(B, m, n);

        matrixAdd(A, B, C, m, n);

        printf("\n\nMatrix C = A + B\n");

        printMatrix(C, m, n);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(B[i]);
        }

        free(B);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(C[i]);
        }

        free(C);

        return 0;
    }    

Output from the lines above:

    Matrix A =
    2.000e+00       4.000e+00       6.000e+00
    8.000e+00       1.000e+01       1.200e+01
    1.400e+01       1.600e+01       1.800e+01

    Matrix B =
    1.000e+00       3.000e+00       5.000e+00
    7.000e+00       9.000e+00       1.100e+01
    1.300e+01       1.500e+01       1.700e+01

    Matrix C = A + B
    3.000e+00       7.000e+00       1.100e+01
    1.500e+01       1.900e+01       2.300e+01
    2.700e+01       3.100e+01       3.500e+01

The output shows the matrix C as a result of adding matrix A and B.

**Implementation/Code:** The following is the code for matrixAdd()

    void matrixAdd(double **A, double **B, double **C, int m, int n) {
        int i, j = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }

**Last Modified:** November/2018
