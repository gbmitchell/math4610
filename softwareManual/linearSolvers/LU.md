# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           squareLU

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareLU.c

will produce an executable **squareLU.exe** that can be executed.

**Description/Purpose:** This routine will carry out LU decomposition of a square matrix. LU decomposition is the process of separating a matrix A into upper (U) and lower (L) triangular matrices such that A=LU.

**Input:** There are three inputs needed in the case of the LU decomposition routine. A square matrix A, a square matrix L, and a value to indicate the size of the matrices. The matrices are passed to the routine by reference and the values for matrix A are separated into a lower and upper triangular matrix. The upper triangular matrix values are computed and stored in matrix A by over writing the original values. The lower triangular matrix values are computed and stored in the matrix L. 

**Output:** This routine does not return anything, instead it changes the values for the matrix A to be the upper triangular matrix and changes the values in the matrix L to be the lower triangular matrix.

**Usage/Example:**

There are three inputs needed in this case of the LU decomposition routine. A square matrix (A), a square matrix (L), and a value to indicate the size of the matrices (n). The matrices are passed to the routine by reference and the values for matrix A are separated into a lower and upper triangular matrix. The upper triangular matrix values are computed and stored in matrix A by over writing the original values. The lower triangular matrix values are computed and stored in the matrix L.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j = 0;
        int m = 3;
        int n = 3;

        // alloc memory for a matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a matrix
        double **L;
        L = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            L[i] = calloc(n, sizeof(double));
        }

        A[0][0] = 1.0;  A[0][1] = -2.0; A[0][2] = -6.0;
        A[1][0] = 2.0;  A[1][1] = 4.0; A[1][2] = 12.0;
        A[2][0] = 1.0; A[2][1] = -3.0; A[2][2] = -12.0;

        printf("Matrix A =\n");

        printMatrix(A, m, n);

        squareLU(A, L, n);

        printf("LU decomposition on matrix A =\n");
        printf("\nMatrix U =\n");

        printMatrix(A, m, n);

        printf("Matrix L =\n");

        printMatrix(L, m, n);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);

        for (i = 0; i < m; i++)
        {
            free(L[i]);
        }

        free(L);

        return 0;
    }

Output from the lines above:

    Matrix A =
    1.000e+00       -2.000e+00      -6.000e+00
    2.000e+00       4.000e+00       1.200e+01
    1.000e+00       -3.000e+00      -1.200e+01

    LU decomposition on matrix A =

    Matrix U =
    1.000e+00       -2.000e+00      -6.000e+00
    0.000e+00       8.000e+00       2.400e+01
    0.000e+00       0.000e+00       -3.000e+00

    Matrix L =
    1.000e+00       0.000e+00       0.000e+00
    2.000e+00       1.000e+00       0.000e+00
    1.000e+00       -1.250e-01      1.000e+00


The output from the example code prints the values for the square matrix A to be sent through the LU decomposition process. After LU decompostion is executed, the values for the resulting upper and lower triangular matrices are printed.

**Implementation/Code:** The following is the code for squareLU()

    void squareLU(double **A, double **B, int n) {
        int i, j, k = 0;
        double factor = 0.0;
        for (k = 0; k < (n - 1); k++) {
            for (i = (k + 1); i < n; i++) {
                factor = A[i][k] / A[k][k];
                A[i][k] = 0.0;
                for (j = (k + 1); j < n; j++) {
                    A[i][j] = A[i][j] - (factor * A[k][j]);
                    B[i][j] = 0.0;
                }
                B[i][k] = factor;
            }
        }

        for (k = 0; k < n; k++) {
            B[k][k] = 1.0;
        }
    }

**Last Modified:** November/2018
