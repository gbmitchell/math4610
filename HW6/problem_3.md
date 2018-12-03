# Math 4610 Fundamentals of Computational Mathematics
Homework 6 problem 3.

**Routine Name:**           conditionNumber

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    2conditionNumber.c

will produce an executable **2conditionNumber.exe** that can be executed.

**Description/Purpose:** This routine will compute the largest eigenvalue of a matrix A and the largest eigenvalue of the matrix inverse A^(-1). The L2-Norm is used in computing the eigenvalues and by multiplying the two eigenvalues together, the product is a 2 condition number or factor of the 2 condition number.

**Input:** There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference.

**Output:** This routine returns a double precision value that represents the 2 condition number of the matrix A.

**Usage/Example:**

There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference. This routine returns a double precision value that represents the 2 condition number of the matrix A.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j = 0;
        int n = 3;
        int m = 3;
        int maxiter = n * 6000;
        double tol = 0.0001;
        double condNum = 0.0;

        // allocate mxn matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // allocate vector for solution
        double *v;
        v = calloc(n, sizeof(double));

        A[0][0] = 4.0; A[0][1] = 1.0; A[0][2] = 2.0;
        A[1][0] = 1.0; A[1][1] = 5.0; A[1][2] = 3.0;
        A[2][0] = 2.0; A[2][1] = 3.0; A[2][2] = 6.0;

        v[0] = 1.0; v[1] = 1.0; v[2] = 1.0;

        printf("Matrix A =\n");

        printMatrix(A, m, n);

        condNum = conditionNumber(A, v, tol, maxiter, n);

        printf("2 condition number of matrix A = %.3e", condNum);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);
        free(v);

        return 0;
    }

Output from the lines above:

    Matrix A =
    4.000e+00       1.000e+00       2.000e+00
    1.000e+00       5.000e+00       3.000e+00
    2.000e+00       3.000e+00       6.000e+00

    2 condition number of matrix A = 4.292e+00

The output shows the matrix A and the 2 condition number of matrix A.

**Implementation/Code:** The following is the code for conditionNumber()

    double conditionNumber(double **A, double *v0, double tol, int maxiter, int n) {
        int i, j = 0;
        double power = 0.0;
        double inversePower = 0.0;
        double condNum = 0.0;

        // allocate mxn matrix
        double **T;
        T = calloc(n, sizeof(double*));

        for (i = 0; i < n; i++)
        {
            T[i] = calloc(n, sizeof(double));
        }

        // allocate vector for solution
        double *tempv;
        tempv = calloc(n, sizeof(double));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                T[i][j] = A[i][j];
            }
        }

        for (i = 0; i < n; i++) {
            tempv[i] = v0[i];
        }

        power = powerMethod(A, v0, tol, maxiter, n);

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = T[i][j];
            }
        }

        for (i = 0; i < n; i++) {
            v0[i] = tempv[i];
        }

        inversePower = inversePowerMethod(A, v0, tol, maxiter, n);

        condNum = power * inversePower;

        // free memory
        for (i = 0; i < n; i++)
        {
            free(T[i]);
        }

        free(T);

        free(tempv);

        return condNum;
    }

**Last Modified:** November/2018
