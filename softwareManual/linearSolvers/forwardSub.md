# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           forwardSub

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    forwardSub.c

will produce an executable **forwardSub.exe** that can be executed.

**Description/Purpose:** This routine will carry out forward substitution to solve for the unkown values of vector x in the problem Ax=b. A is a lower triangular matrix, x is a vector of unknowns, and b is a vector of known values. The problem Ax=b represents a linear system of n equations and n unknowns. Forward substitution solves for the values of in order of x1, x2, x3, ....., xn.

**Input:** There are four inputs needed in this case to forward solve the problem Ax=b. A lower triangular matrix, a vector of unkown values, a vector of given values, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it changes the values for the vector of unknowns. The solved values for the vector of unknowns can then be used as needed.

**Usage/Example:**

There are four inputs needed in this case to forward solve the problem Ax=b. A lower triangular matrix (A), a vector of unkown values (x), a vector of given values (b), and a value to indicate the size of the matrix and vectors (n). The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it changes the values for the vector of unknowns. The solved values for the vector of unknowns can then be used as needed.

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

        // alloc memory for a vector
        double *b;
        b = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *x;
        x = calloc(n, sizeof(double));

        A[0][0] = 1.0;  A[0][1] = 0.0; A[0][2] = 0.0;
        A[1][0] = 3.0;  A[1][1] = 1.0; A[1][2] = 0.0;
        A[2][0] = -1.0; A[2][1] = 1.0; A[2][2] = -3.0;

        b[0] = -2.0; b[1] = 0.0; b[2] = 5.0;

        printf("Lower triagular augmented matrix A =\n");

        printAugMatrix(A, b, m, n);

        forwardSub(A, x, b, n);

        printf("Solution using forward substitution on augmented matrix A\n");
        printf("Vector x =\n");

        printVector(x, n);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);

        free(b);
        free(x);

        return 0;
    }

Output from the lines above:

    Lower triagular augmented matrix A =
    1.000e+00       0.000e+00       0.000e+00       |-2.000e+00
    3.000e+00       1.000e+00       0.000e+00       |0.000e+00
    -1.000e+00      1.000e+00       -3.000e+00      |5.000e+00

    Solution using forward substitution on augmented matrix A
    Vector x =
    -2.000e+00
    6.000e+00
    1.000e+00

The output from the example code prints the values for the lower triangular matrix A augmented with the known values of the vector b. The routine then forward solves for the values in the vector of unknowns and stores those values in the vector x. The stored values are then printed as the solution to the problem Ax=b.

**Implementation/Code:** The following is the code for forwardSub()

    void forwardSub(double **A, double *x, double *b, int n) {
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
