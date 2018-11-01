# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 1.

**Routine Name:**           squareGauss

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This function will compute the single precision value for the machine epsilon or the number of digits
in the representation of real numbers in single precision. This is a function for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** There are no inputs needed in this case. Arguments are passed by reference and the function will change their values.
The real purpose is to produce values in those variables to be used as needed.

**Output:** This function returns a single precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:**

The function has two arguments needed to produce the values of the precision in terms of the smallest number that can be
represented. Since the code is written in terms of a C function, the value of the machine epsilon (seps) is a single
precision value (float) and the power of two that gives the machine epsilon (ipow) is an integer. 

    #include "mylib.h"
    #include <stdio.h>

    int main() {
        int i, j, k = 0;
        int n = 0;
        int m = 0;

        // 3x3
        double A[50][50] = { {1.0, 0.0, 0.0}, {3.0, 1.0, 0.0}, { -1.0, 1.0, -3.0} };
        double B[50][50] = { {1.0, -2.0, -6.0}, {2.0, 4.0, 12.0}, {1.0, -3.0, -12.0} };
        double D[50][50] = { {1.0, -2.0, -6.0}, {2.0, 4.0, 12.0}, {1.0, -3.0, -12.0} };
        double L[50][50] = { 0 };

        // 4x6
        double C[50][50] = { {2.0, 2.0, 3.0, 4.0, 20.0, 30.0}, {5.0, 6.0, 7.0, 8.0, 40.0, 50.0}, {11.0, 10.0, 11.0, 15.0, 60.0, 70.0}, {13.0,14.0,15.0,16.0, 80.0, 90.0} };

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

        squareGauss(B, bb, n);

        printf("\n\n\n");

        printf("Gaussian elimination on augmented matrix B =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", B[i][j]);
            }
            printf("|%.3e\n", bb[i]);
        }

        backSub(B, xb, bb, n);

        printf("\n\n\n");

        printf("Solution using back substitution on augmented matrix B\n");

        for (i = 0; i < n; i++) {
            printf("x%d = %.3e\n", i + 1, xb[i]);
        }

        printf("\n\n\n");

        printf("Augmented matrix C =\n");
        m = 4;
        n = 6;
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

      24    5.96046448e-08

The first value (24) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly eight (e-08 on the
end of the second value).

**Implementation/Code:** The following is the code for squareGauss()

    void squareGauss(double A[50][50], double b[50], int n) {
        int i, j, k = 0;
        double factor = 0.0;
        for (k = 0; k < (n - 1); k++) {
            for (i = (k + 1); i < n; i++) {
                factor = A[i][k] / A[k][k];
                A[i][k] = 0.0;
                for (j = (k + 1); j < n; j++) {
                    A[i][j] = A[i][j] - (factor * A[k][j]);
                }
                b[i] = b[i] - (factor * b[k]);
            }
        }
    }

**Last Modified:** November/2018
