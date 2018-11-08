# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 10.

**Routine Name:**           Choleskysolve

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Cholesky decomposition, forward substitution, and back substitution. Cholesky decomposition will separate the matrix A into upper U and lower L triangular matrices such that A=LU=L(Ltranspose). The Upper triangular matrix U is the transpose of the lower triangular matrix L. The problem can then be writen as LUx=b. Using Ux=y, the problem can be writen as Ly=b and then forward substitution is used to solve for the unknown values of the vector y. After solving for the values of the vector y, back substitution is used to solve for the unkown values of vector x in the problem Ux=y, thus solving the unknown values for the vector x in the original problem of Ax=b.

**Input:** There are five inputs needed in this case to solve the problem Ax=b. A square matrix A, a square matrix L, a vector of unkown values x, a vector of given values b, and a value to indicate the size of the matrices and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses LU decomposition to store the values for the upper triangulare matrix in the original matrix A and stores the lower triangular matrix values in the matrix L. After forward and back solving, the solution for the values of the vector x are updated and can be used as needed.

**Usage/Example:**

There are five inputs needed in this case to solve the problem Ax=b. A square matrix H, a square matrix HU, a vector of unkown values xh, a vector of given values bh, and a value to indicate the size of the matrices and vectors (n). The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Cholesky decomposition to store the values for the lower triangulare matrix in the original matrix H and stores the upper triangular matrix values in the matrix HU. After forward and back solving, the solution for the values of the vector xh are updated and can be used as needed. The process is repeated for the 5x5 matrix P as well.

    #include "mylib.h"
    #include <stdio.h>

    int main() {
        int i, j = 0;
        int n = 0;
        int m = 0;

        // 7x7
        double H[50][50] = { {0.0011, 0.0, 0.0, -0.0001, 0.0, 0.0, 0.0}, {0.0, 0.008860992908, -0.000066666667, 0.0, 0.002127659574, 0.0, 0.0}, {0.0, -0.000066666667, 0.003612765957, -0.000212765957, 0.0, -0.0030303030303, 0.0}, {-0.0001, 0.0, -0.000212765957, 0.001783354193, 0.0, 0.0, -0.001470588235}, {0.0, -0.002127659574, 0.0, 0.0, 0.00677311412, -0.0001, -0.004545454545}, {0.0, 0.0, -0.00303030303, 0.0, -0.0001, 0.00413030303, -0.001}, {0.0, 0.0, 0.0, -0.001470588235, -0.004545454545, -0.001, 0.007016042781} };
        
        // 5x5
        double P[50][50] = { {18450.0, -3300.0, -15000.0, 0.0, 0.0}, {-3300.0, 19000.0, 0.0, -4700.0, 0.0}, {-15000.0, 0.0, 25800.0, -330.0, -10000.0}, {0.0, -4700.0, -330.0, 6710.0, -1000.0}, {0.0, 0.0, -10000.0, -1000.0, 11220.0} };

        double HU[50][50] = { 0 };
        double PU[50][50] = { 0 };

        double bh[50] = { 0.0, 0.08, 0.0, 0.0, 0.0, 0.0, 0.0 };
        double bp[50] = { 12.0, 0.0, 0.0, 0.0, 0.0 };

        double xh[50] = { 0 };
        double xp[50] = { 0 };

        m = 7;
        n = 7;

        printf("\n\n\n");

        printf("Augmented matrix H =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", H[i][j]);
            }
            printf("|%.3e\n", bh[i]);
        }

        Choleskysolve(H, HU, xh, bh, n);

        printf("\n\n\n");

        printf("Solution Hx=b, using Cholesky decomposition on matrix H\n");

        for (i = 0; i < n; i++) {
            printf("x%d = %.3e\n", i + 1, xh[i]);
        }

        printf("\n\n\n");

        m = 5;
        n = 5;

        printf("\n\n\n");

        printf("Augmented matrix P =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", P[i][j]);
            }
            printf("|%.3e\n", bp[i]);
        }

        Choleskysolve(P, PU, xp, bp, n);

        printf("\n\n\n");

        printf("Solution Px=b, using Cholesky decomposition on matrix P\n");

        for (i = 0; i < n; i++) {
            printf("x%d = %.3e\n", i + 1, xp[i]);
        }
        
        return 0;
    }

Output from the lines above:

    Augmented matrix H =
    1.100e-03       0.000e+00       0.000e+00       -1.000e-04      0.000e+00       0.000e+00       0.000e+00       |0.000e+00
    0.000e+00       8.861e-03       -6.667e-05      0.000e+00       2.128e-03       0.000e+00       0.000e+00       |8.000e-02
    0.000e+00       -6.667e-05      3.613e-03       -2.128e-04      0.000e+00       -3.030e-03      0.000e+00       |0.000e+00
    -1.000e-04      0.000e+00       -2.128e-04      1.783e-03       0.000e+00       0.000e+00       -1.471e-03      |0.000e+00
    0.000e+00       -2.128e-03      0.000e+00       0.000e+00       6.773e-03       -1.000e-04      -4.545e-03      |0.000e+00
    0.000e+00       0.000e+00       -3.030e-03      0.000e+00       -1.000e-04      4.130e-03       -1.000e-03      |0.000e+00
    0.000e+00       0.000e+00       0.000e+00       -1.471e-03      -4.545e-03      -1.000e-03      7.016e-03       |0.000e+00


    Solution Hx=b, using Cholesky decomposition on matrix H
    x1 = 8.080e-01
    x2 = 1.154e+01
    x3 = 7.539e+00
    x4 = 8.888e+00
    x5 = 1.021e+01
    x6 = 8.111e+00
    x7 = 9.632e+00


    Augmented matrix P =
    1.845e+04       -3.300e+03      -1.500e+04      0.000e+00       0.000e+00       |1.200e+01
    -3.300e+03      1.900e+04       0.000e+00       -4.700e+03      0.000e+00       |0.000e+00
    -1.500e+04      0.000e+00       2.580e+04       -3.300e+02      -1.000e+04      |0.000e+00
    0.000e+00       -4.700e+03      -3.300e+02      6.710e+03       -1.000e+03      |0.000e+00
    0.000e+00       0.000e+00       -1.000e+04      -1.000e+03      1.122e+04       |0.000e+00


    Solution Px=b, using Cholesky decomposition on matrix P
    x1 = 3.093e-03
    x2 = 8.080e-04
    x3 = 2.826e-03
    x4 = 1.095e-03
    x5 = 2.616e-03

The output from the example code prints the values for the 7x7 square matrix H augmented with the known values of the vector bh. The routine then executes Cholesky decomposition followed by forward and back substitution to solve for the values in the vector of unknowns and stores those values in the vector xh. The stored values are then printed as the solution to the problem Hx=b. The process is then repeated using a 5x5 matrix P.

**Implementation/Code:** The following is the code for Choleskysolve()

    void Choleskysolve(double A[50][50], double U[50][50], double x[50], double b[50], int n) {
        double yd[50] = { 0 };
        choleskyLU(A, U, n);
        forwardSub(A, yd, b, n);
        backSub(U, x, yd, n);
    }

**Last Modified:** November/2018
