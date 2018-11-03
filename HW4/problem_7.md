# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 7.

**Routine Name:**           LUsolve

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of LU decomposition, forward substitution, and back substitution. LU decomposition will separate the matrix A into upper (U) and lower (L) triangular matrices such that A=LU. The problem can then be writen as LUx=b. Using Ux=y, the problem can be writen as Ly=b and then forward substitution is used to solve for the unknown values of the vector y. After solving for the values of the vector y, back substitution is used to solve for the unkown values of vector x in the problem Ux=y, thus solving the unknown values for the vector x in the original problem of Ax=b.

**Input:** There are five inputs needed in this case to solve the problem Ax=b. A square matrix A, a square matrix L, a vector of unkown values x, a vector of given values b, and a value to indicate the size of the matrices and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses LU decomposition to store the values for the upper triangulare matrix in the original matrix A and stores the lower triangular matrix values in the matrix L. After forward and back solving, the solution for the values of the vector x are updated and can be used as needed.

**Usage/Example:**

There are five inputs needed in this case to solve the problem Ax=b. A square matrix D, a square matrix L, a vector of unkown values xd, a vector of given values bd, and a value to indicate the size of the matrices and vectors (n). The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses LU decomposition to store the values for the upper triangulare matrix in the original matrix D and stores the lower triangular matrix values in the matrix L. After forward and back solving, the solution for the values of the vector x are updated and can be used as needed.

    #include "mylib.h"
    #include <stdio.h>

    int main() {
        int i, j = 0;
        int n = 0;
        int m = 0;

        // 3x3
        double D[50][50] = { {1.0, -2.0, -6.0}, {2.0, 4.0, 12.0}, {1.0, -3.0, -12.0} };
        double L[50][50] = { 0 };
        double bd[50] = { 5.0, 0.0, -2.0 };
        double xd[50] = { 0 };

        m = 3;
        n = 3;

        printf("Augmented matrix D =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", D[i][j]);
            }
            printf("|%.3e\n", bd[i]);
        }

        LUsolve(D, L, xd, bd, n);

        printf("\n\n\n");

        printf("Solution Dx=b, using LU decomposition on matrix D\n");

        for (i = 0; i < n; i++) {
            printf("x%d = %.3e\n", i + 1, xd[i]);
        }

        return 0;
    }

Output from the lines above:

    Augmented matrix D =
    1.000e+00       -2.000e+00      -6.000e+00      |5.000e+00
    2.000e+00       4.000e+00       1.200e+01       |0.000e+00
    1.000e+00       -3.000e+00      -1.200e+01      |-2.000e+00



    Solution Dx=b, using LU decomposition on matrix D
    x1 = 2.500e+00
    x2 = -9.500e+00
    x3 = 2.750e+00

The output from the example code prints the values for the square matrix D augmented with the known values of the vector bd. The routine then executes LU decomposition followed by forward and back substitution to solve for the values in the vector of unknowns and stores those values in the vector xd. The stored values are then printed as the solution to the problem Dx=b.

**Implementation/Code:** The following is the code for LUsolve()

    void LUsolve(double A[50][50], double L[50][50], double x[50], double b[50], int n) {
        double yd[50] = { 0 };
        squareLU(A, L, n);
        forwardSub(L, yd, b, n);
        backSub(A, x, yd, n);
    }

**Last Modified:** November/2018
