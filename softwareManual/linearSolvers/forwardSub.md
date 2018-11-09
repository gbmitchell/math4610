# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           forwardSub

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will carry out forward substitution to solve for the unkown values of vector x in the problem Ax=b. A is a lower triangular matrix, x is a vector of unknowns, and b is a vector of known values. The problem Ax=b represents a linear system of n equations and n unknowns. Forward substitution solves for the values of in order of x1, x2, x3, ....., xn.

**Input:** There are four inputs needed in this case to forward solve the problem Ax=b. A lower triangular matrix, a vector of unkown values, a vector of given values, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it changes the values for the vector of unknowns. The solved values for the vector of unknowns can then be used as needed.

**Usage/Example:**

There are four inputs needed in this case to forward solve the problem Ax=b. A lower triangular matrix (A), a vector of unkown values (xa), a vector of given values (ba), and a value to indicate the size of the matrix and vectors (n). The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it changes the values for the vector of unknowns. The solved values for the vector of unknowns can then be used as needed.

    #include "mylib.h"
    #include <stdio.h>

    int main() {
        int i, j = 0;
        int n = 0;
        int m = 0;

        // 3x3
        double A[50][50] = { {1.0, 0.0, 0.0}, {3.0, 1.0, 0.0}, { -1.0, 1.0, -3.0} };
        double ba[50] = { -2.0, 0.0, 5.0 }; 
        double xa[50] = { 0 };

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

        return 0;
    }

Output from the lines above:

    Lower triagular augmented matrix A =
    1.000e+00       0.000e+00       0.000e+00       |-2.000e+00
    3.000e+00       1.000e+00       0.000e+00       |0.000e+00
    -1.000e+00      1.000e+00       -3.000e+00      |5.000e+00



    Solution using forward substitution on augmented matrix A
    x1 = -2.000e+00
    x2 = 6.000e+00
    x3 = 1.000e+00

The output from the example code prints the values for the lower triangular matrix A augmented with the known values of the vector b. The routine then forward solves for the values in the vector of unknowns and stores those values in the vector x. The stored values are then printed as the solution to the problem Ax=b.

**Implementation/Code:** The following is the code for forwardSub()

    void forwardSub(double A[50][50], double x[50], double b[50], int n) {
        int i, j = 0;
        double sum = 0.0;

        x[0] = b[0] / A[0][0];
        for (i = 1; i < n; i++) {
            sum = 0.0;
            for (j = 0; j < i; j++) {
                sum = sum + (A[i][j] * x[j]);
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
    }

**Last Modified:** November/2018
