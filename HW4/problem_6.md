# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 6.

**Routine Name:**           squareLU

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will carry out LU decomposition of a square matrix. LU decomposition is the process of separating a matrix A into upper (U) and lower (L) triangular matrices such that A=LU.

**Input:** There are three inputs needed in the case of the LU decomposition routine. A square matrix A, a square matrix L, and a value to indicate the size of the matrices. The matrices are passed to the routine by reference and the values for matrix A are separated into a lower and upper triangular matrix. The upper triangular matrix values are computed and stored in matrix A by over writing the original values. The lower triangular matrix values are computed and stored in the matrix L. 

**Output:** This routine does not return anything, instead it changes the values for the matrix A to be the upper triangular matrix and changes the values in the matrix L to be the lower triangular matrix.

**Usage/Example:**

There are three inputs needed in this case of the LU decomposition routine. A square matrix (D), a square matrix (L), and a value to indicate the size of the matrices (n). The matrices are passed to the routine by reference and the values for matrix D are separated into a lower and upper triangular matrix. The upper triangular matrix values are computed and stored in matrix D by over writing the original values. The lower triangular matrix values are computed and stored in the matrix L.

    #include "mylib.h"
    #include <stdio.h>

    int main() {
        int i, j = 0;
        int n = 0;
        int m = 0;

        // 3x3
        double D[50][50] = { {1.0, -2.0, -6.0}, {2.0, 4.0, 12.0}, {1.0, -3.0, -12.0} };
        double L[50][50] = { 0 };

        m = 3;
        n = 3;

        printf("Matrix D =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", D[i][j]);
            }
            printf("\n");
        }

        squareLU(D, L, n);

        printf("\n\n\n");

        printf("LU decomposition on matrix D =\n");
        printf("\nMatrix U =\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", D[i][j]);
            }
            printf("\n");
        }

        printf("\n\n\n");

        printf("Matrix L =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", L[i][j]);
            }
            printf("\n");
        }

        return 0;
    }

Output from the lines above:

    Matrix D =
    1.000e+00       -2.000e+00      -6.000e+00
    2.000e+00       4.000e+00       1.200e+01
    1.000e+00       -3.000e+00      -1.200e+01


    LU decomposition on matrix D =
    Matrix U =
    1.000e+00       -2.000e+00      -6.000e+00
    0.000e+00       8.000e+00       2.400e+01
    0.000e+00       0.000e+00       -3.000e+00


    Matrix L =
    1.000e+00       0.000e+00       0.000e+00
    2.000e+00       1.000e+00       0.000e+00
    1.000e+00       -1.250e-01      1.000e+00

The output from the example code prints the values for the square matrix D to be sent through the LU decomposition process. After LU decompostion is executed, the values for the resulting upper and lower triangular matrices are printed.

**Implementation/Code:** The following is the code for squareLU()

    void squareLU(double A[50][50], double B[50][50], int n) {
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
