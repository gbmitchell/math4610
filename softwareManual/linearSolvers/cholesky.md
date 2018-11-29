# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           choleskyLU

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    cholesky.c

will produce an executable **cholesky.exe** that can be executed.

**Description/Purpose:** This routine will carry out a form of LU decomposition called Cholesky decomposition on a square matrix. Cholesky decomposition is similar to LU decomposition in that the square matrix is separated into a lower and upper triangular matrix. In the case of Cholesky, the upper triangular matix is the transpose of the lower triangular matrix. A = LU = L(transpose(L)).

**Input:** There are three inputs needed in the case of the Cholesky decomposition routine. The square matrix A, a square matrix U, and a value to indicate the size of the matrices. The matrices are passed to the routine by reference and the values for matrix A are separated into a lower and upper triangular matrix. The lower triangular matrix values are computed and stored in matrix A by over writing the original values. The upper triangular matrix values are computed by taking the transpose of the lower triangular matrix and storing the values in the matrix U. 

**Output:** This routine does not return anything, instead it changes the values for the matrix A to be the lower triangular matrix and changes the values in the matrix U to be the upper triangular matrix.

**Usage/Example:**

There are three inputs needed in the case of the Cholesky decomposition routine. The square matrix A, a square matrix U, and a value to indicate the size of the matrices (n). The matrices are passed to the routine by reference and the values for matrix A are separated into a lower and upper triangular matrix. The lower triangular matrix values are computed and stored in matrix A by over writing the original values. The upper triangular matrix values are computed by taking the transpose of the lower triangular matrix and storing the values in the matrix U. This routine does not return anything, instead it changes the values for the matrix A to be the lower triangular matrix and changes the values in the matrix U to be the upper triangular matrix.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j = 0;
        int m = 5;
        int n = 5;

        // alloc memory for a matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a matrix
        double **U;
        U = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            U[i] = calloc(n, sizeof(double));
        }

        A[0][0] = 1.0; A[0][1] = 2.0;  A[0][2] = 1.0;  A[0][3] = 3.0;  A[0][4] = 1.0;
        A[1][0] = 2.0; A[1][1] = 29.0; A[1][2] = 17.0; A[1][3] = 11.0; A[1][4] = 12.0;
        A[2][0] = 1.0; A[2][1] = 17.0; A[2][2] = 46.0; A[2][3] = 18.0; A[2][4] = 13.0;
        A[3][0] = 3.0; A[3][1] = 11.0; A[3][2] = 18.0; A[3][3] = 78.0; A[3][4] = 15.0;
        A[4][0] = 1.0; A[4][1] = 12.0; A[4][2] = 13.0; A[4][3] = 15.0; A[4][4] = 88.0;

        printf("Matrix A =\n");

        printMatrix(A, m, n);

        choleskyLU(A, U, n);

        printf("Cholesky decomposition on matrix A =\n");
        printf("Matrix L =\n");

        printMatrix(A, m, n);

        printf("\nMatrix U =\n");

        printMatrix(U, m, n);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);

        for (i = 0; i < m; i++)
        {
            free(U[i]);
        }

        free(U);

        return 0;
    }

Output from the lines above:

    Matrix A =
    1.000e+00       2.000e+00       1.000e+00       3.000e+00       1.000e+00
    2.000e+00       2.900e+01       1.700e+01       1.100e+01       1.200e+01
    1.000e+00       1.700e+01       4.600e+01       1.800e+01       1.300e+01
    3.000e+00       1.100e+01       1.800e+01       7.800e+01       1.500e+01
    1.000e+00       1.200e+01       1.300e+01       1.500e+01       8.800e+01

    Cholesky decomposition on matrix A =
    Matrix L =
    1.000e+00       0.000e+00       0.000e+00       0.000e+00       0.000e+00
    2.000e+00       5.000e+00       0.000e+00       0.000e+00       0.000e+00
    1.000e+00       3.000e+00       6.000e+00       0.000e+00       0.000e+00
    3.000e+00       1.000e+00       2.000e+00       8.000e+00       0.000e+00
    1.000e+00       2.000e+00       1.000e+00       1.000e+00       9.000e+00

    Matrix U =
    1.000e+00       2.000e+00       1.000e+00       3.000e+00       1.000e+00
    0.000e+00       5.000e+00       3.000e+00       1.000e+00       2.000e+00
    0.000e+00       0.000e+00       6.000e+00       2.000e+00       1.000e+00
    0.000e+00       0.000e+00       0.000e+00       8.000e+00       1.000e+00
    0.000e+00       0.000e+00       0.000e+00       0.000e+00       9.000e+00

The output from the example code prints the values for the square matrix A to be sent through the Cholesky decomposition process. After Cholesky decompostion is executed, the values for the resulting lower and upper triangular matrices are printed.

**Implementation/Code:** The following is the code for choleskyLU()

    void choleskyLU(double **A, double **B, int n) {
        int i, j, k = 0;
        for (k = 0; k < (n - 1); k++) {
            A[k][k] = sqrt(A[k][k]);
            for (i = (k + 1); i < n; i++) {
                A[i][k] = A[i][k] / A[k][k];
            }
            for (j = (k + 1); j < n; j++) {
                for (i = j; i < n; i++) {
                    A[i][j] = A[i][j] - (A[i][k] * A[j][k]);
                }
            }
        }
        A[n - 1][n - 1] = sqrt(A[n - 1][n - 1]);
        for (k = 0; k < n; k++) {
            for (i = (k + 1); i < n; i++) {
                A[k][i] = 0.0;
            }
        }

        transposeMatrix(A, B, n, n);
    }

**Last Modified:** November/2018
