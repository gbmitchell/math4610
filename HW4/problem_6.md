# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 6.

**Routine Name:**           backSub

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will carry out back substitution to solve for the unkown values of vector x in the problem Ax=b. A is an upper triangular matrix, x is a vector of unknowns, and b is a vector of known values. The problem Ax=b represents a linear system of n equations and n unknowns. Back substitution solves for the values of in order of xn, ....., x3, x2, x1.

**Input:** There are four inputs needed in this case to back solve the problem Ax=b. An upper triangular matrix, a vector of unkown values, a vector of given values, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it changes the values for the vector of unknowns. The solved values for the vector of unknowns can then be used as needed.

**Usage/Example:**

There are four inputs needed in this case to back solve the problem Ax=b. An upper triangular matrix (B), a vector of unkown values (xb), a vector of given values (bb), and a value to indicate the size of the matrix and vectors (n). The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it changes the values for the vector of unknowns. The solved values for the vector of unknowns can then be used as needed.

    #include "mylib.h"
    #include <stdio.h>

    int main() {
        int i, j = 0;
        int n = 0;
        int m = 0;

        // 3x3
        double A[50][50] = { {1.0, 0.0, 0.0}, {3.0, 1.0, 0.0}, { -1.0, 1.0, -3.0} };
        double B[50][50] = { {1.0, -2.0, -6.0}, {2.0, 4.0, 12.0}, {1.0, -3.0, -12.0} };
        double D[50][50] = { {1.0, -2.0, -6.0}, {2.0, 4.0, 12.0}, {1.0, -3.0, -12.0} };
        double L[50][50] = { 0 };

        // 4x5
        double C[50][50] = { {1.0, -1.0, 3.0, 1.0, 1.0}, {3.0, 1.0, 7.0, 1.0, 5.0}, {-4.0, 4.0, 1.0, -2.0, 2.0}, {2.0, 1.0, 2.0, 1.0, 3.0} };

        double ba[50] = { -2.0, 0.0, 5.0 };
        double bb[50] = { 5.0, 0.0, -2.0 };
        double bc[50] = { 4.0, 5.0, 6.0, 7.0 };
        double bd[50] = { 5.0, 0.0, -2.0 };

        double xa[50] = { 0 };
        double xb[50] = { 0 };
        double xc[50] = { 0 };
        double xd[50] = { 0 };
        double yd[50] = { 0 };


        m = 3;
        n = 3;

        printf("Lower triagular augmented matrix A =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", A[i][j]);
            }
            printf("|%.3e\n", ba[i]);
        }

        forwardSub(A, xa, ba, n);

        printf("\n\n\n");

        printf("Solution using forward substitution on augmented matrix A\n");

        for (i = 0; i < n; i++) {
            printf("x%d = %.3e\n", i+1, xa[i]);
        }

        printf("\n\n\n");

        printf("Augmented matrix B =\n");

        for (i = 0; i < m; i++ ) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", B[i][j]);
            }
            printf("|%.3e\n", bb[i]);
        }

        GEsolve(B, xb, bb, n);

        printf("\n\n\n");

        printf("Solution using Gauss Elimination method\n");

        for (i = 0; i < n; i++) {
            printf("x%d = %.3e\n", i + 1, xb[i]);
        }

        printf("\n\n\n");

        printf("Augmented matrix C =\n");
        m = 4;
        n = 5;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", C[i][j]);
            }
            printf("|%.3e\n", bc[i]);
        }

        generalGauss(C, bc, m, n);

        printf("\n\n\n");

        printf("Gaussian elimination on augmented matrix C =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", C[i][j]);
            }
            printf("|%.3e\n", bc[i]);
        }

        printf("\n\n\n");

        printf("Matrix D =\n");

        m = 3;
        n = 3;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", D[i][j]);
            }
            printf("\n");
        }

        squareLU(D, L, bb, n);

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

        printf("\n\n\n");

        printf("b =\n");

        for (i = 0; i < n; i++) {
            printf("x%d = %.3e\n", i + 1, bd[i]);
        }

        printf("\n\n\n");

        forwardSub(L, yd, bd, n);
        backSub(D, xd, yd, n);

        printf("Solution Dx=b, using LU decomposition on matrix D\n");

        for (i = 0; i < n; i++) {
            printf("x%d = %.3e\n", i + 1, xd[i]);
        }

        printf("\n\n\n");

        return 0;
    }

Output from the lines above:



The output from the example code prints the values for the upper triangular matrix B augmented with the known values of the vector bb. The routine then back solves for the values in the vector of unknowns and stores those values in the vector xb. The stored values are then printed as the solution to the problem Ax=b.

**Implementation/Code:** The following is the code for squareLU()

    void squareLU(double A[50][50], double B[50][50], double b[50], int n) {
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
