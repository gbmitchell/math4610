# Math 4610 Fundamentals of Computational Mathematics
Homework 6 problem 7.

**Routine Name:**           conditionNumberParallel

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    2conditionNumberParallel.c

will produce an executable **2conditionNumberParallel.exe** that can be executed.

**Description/Purpose:** This routine will compute the largest eigenvalue of a matrix A and the largest eigenvalue of the matrix inverse A^(-1). The L2-Norm is used in computing the eigenvalues and by multiplying the two resulting eigenvalues together, the product is a 2 condition number or factor of the 2 condition number. This routine combines the parallel routies of the power method and inverse power method to create a parallel version of the 2 condition number routine. The majoraty of time gained from the parallel version of the condition number routine is contributed by the parallel power method routine. Not much time is gained from the parallel inverse power method routine. As a result the overall time gained is relativly small.

**Input:** There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference.

**Output:** This routine returns a double precision value that represents the 2 condition number of the matrix A.

**Usage/Example:**

There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference. This routine returns a double precision value that represents the 2 condition number of the matrix A.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>


    int main() {
        clock_t start, end;
        double time1 = 0.0;
        int i, j = 0;
        int n = 2000;
        int m = 2000;
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

        // allocate mxn matrix
        double **T;
        T = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            T[i] = calloc(n, sizeof(double));
        }

        // allocate vector for solution
        double *v;
        v = calloc(n, sizeof(double));

        // allocate vector for solution
        double *tempv;
        tempv = calloc(n, sizeof(double));

        // create uniformly distributed and diagnally dominant matrix
        // and create RHS vector
        uniformMatrix(A, v, n);

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                T[i][j] = A[i][j];
            }
        }

        for (i = 0; i < n; i++) {
            tempv[i] = v[i];
        }

        start = clock();

        condNum = conditionNumber(A, v, tol, maxiter, n);

        end = clock();
        time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nTime serial = %.3e\n", time1);

        printf("2 condition number = %.3e", condNum);

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = T[i][j];
            }
        }

        for (i = 0; i < n; i++) {
            v[i] = tempv[i];
        }

        start = clock();

        condNum = conditionNumberParallel(A, v, tol, maxiter, n);

        end = clock();
        time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nTime parallel = %.3e\n", time1);

        printf("2 condition number = %.3e", condNum);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(T[i]);
        }

        free(T);

        free(v);

        free(tempv);

        return 0;
    }

Output from the lines above:

    Finished after 7 iterations
    Finished after 3 iterations
    Time serial = 1.173e+01
    2 condition number = 1.004e+00

    Finished after 7 iterations
    Finished after 3 iterations
    Time parallel = 1.098e+01
    2 condition number = 1.004e+00

The output shows the number of iterations for the power method, the number of iterations for the inverse power method, and 2 condition number for the matrix A computed with both serial and parallel programming. The parallel program takes a little less time for a 2000x2000 matrix.

**Implementation/Code:** The following is the code for conditionNumberParallel()

    double conditionNumberParallel(double **A, double *v0, double tol, int maxiter, int n) {
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

        power = powerMethodParallel(A, v0, tol, maxiter, n);

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = T[i][j];
            }
        }

        for (i = 0; i < n; i++) {
            v0[i] = tempv[i];
        }

        inversePower = inversePowerMethodParallel(A, v0, tol, maxiter, n);

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
