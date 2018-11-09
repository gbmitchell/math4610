# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           choleskyLU

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will carry out a form of LU decomposition called Cholesky decomposition on a square matrix. Cholesky decomposition is similar to LU decomposition in that the square matrix is separated into a lower and upper triangular matrix. In the case of Cholesky, the upper triangular matix is the transpose of the lower triangular matrix. A = LU = L(transpose(L)).

**Input:** There are three inputs needed in the case of the Cholesky decomposition routine. A square matrix A, a square matrix U, and a value to indicate the size of the matrices. The matrices are passed to the routine by reference and the values for matrix A are separated into a lower and upper triangular matrix. The lower triangular matrix values are computed and stored in matrix A by over writing the original values. The upper triangular matrix values are computed by taking the transpose of the lower triangular matrix and storing the values in the matrix U. 

**Output:** This routine does not return anything, instead it changes the values for the matrix A to be the lower triangular matrix and changes the values in the matrix U to be the upper triangular matrix.

**Usage/Example:**

There are three inputs needed in the case of the Cholesky decomposition routine. A square matrix G, a square matrix GU, and a value to indicate the size of the matrices (n). The matrices are passed to the routine by reference and the values for matrix G are separated into a lower and upper triangular matrix. The lower triangular matrix values are computed and stored in matrix G by over writing the original values. The upper triangular matrix values are computed by taking the transpose of the lower triangular matrix and storing the values in the matrix GU. This routine does not return anything, instead it changes the values for the matrix G to be the lower triangular matrix and changes the values in the matrix GU to be the upper triangular matrix.

    #include "mylib.h"
    #include <stdio.h>

    int main() {
        int i, j = 0;
        int n = 0;
        int m = 0;

        // 5x5
        double G[50][50] = { {1.0, 2.0, 1.0, 3.0, 1.0}, {2.0, 29.0, 17.0, 11.0, 12.0}, {1.0, 17.0, 46.0, 18.0, 13.0}, {3.0, 11.0, 18.0, 78.0, 15.0}, {1.0, 12.0, 13.0, 15.0, 88.0} };
        double GU[50][50] = { 0 };

        m = 5;
        n = 5;

        printf("Matrix G =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", G[i][j]);
            }
            printf("\n");
        }

        choleskyLU(G, GU, n);

        printf("\n\n\n");

        printf("Cholesky Decomposition on matrix G\nL = \n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", G[i][j]);
            }
            printf("\n");
        }

        printf("\n\n\n");

        printf("U = \n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", GU[i][j]);
            }
            printf("\n");
        }
        
        return 0;
    }

Output from the lines above:

    Matrix G =
    1.000e+00       2.000e+00       1.000e+00       3.000e+00       1.000e+00
    2.000e+00       2.900e+01       1.700e+01       1.100e+01       1.200e+01
    1.000e+00       1.700e+01       4.600e+01       1.800e+01       1.300e+01
    3.000e+00       1.100e+01       1.800e+01       7.800e+01       1.500e+01
    1.000e+00       1.200e+01       1.300e+01       1.500e+01       8.800e+01



    Cholesky Decomposition on matrix G
    L =
    1.000e+00       0.000e+00       0.000e+00       0.000e+00       0.000e+00
    2.000e+00       5.000e+00       0.000e+00       0.000e+00       0.000e+00
    1.000e+00       3.000e+00       6.000e+00       0.000e+00       0.000e+00
    3.000e+00       1.000e+00       2.000e+00       8.000e+00       0.000e+00
    1.000e+00       2.000e+00       1.000e+00       1.000e+00       9.000e+00



    U =
    1.000e+00       2.000e+00       1.000e+00       3.000e+00       1.000e+00
    0.000e+00       5.000e+00       3.000e+00       1.000e+00       2.000e+00
    0.000e+00       0.000e+00       6.000e+00       2.000e+00       1.000e+00
    0.000e+00       0.000e+00       0.000e+00       8.000e+00       1.000e+00
    0.000e+00       0.000e+00       0.000e+00       0.000e+00       9.000e+00

The output from the example code prints the values for the square matrix G to be sent through the Cholesky decomposition process. After Cholesky decompostion is executed, the values for the resulting lower and upper triangular matrices are printed.

**Implementation/Code:** The following is the code for choleskyLU()

    void choleskyLU(double A[50][50], double B[50][50], int n) {
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
