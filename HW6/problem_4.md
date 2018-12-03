# Math 4610 Fundamentals of Computational Mathematics
Homework 6 problem 4.

**Routine Name:**           powerMethodParallel

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    powerMethodParallel.c

will produce an executable **powerMethodParallel.exe** that can be executed.

**Description/Purpose:** This routine will compute the largest eigenvalue of a matrix using openMP to parallelize the routine. Matrix multiplication with a vector can take a lot of time to compute. Parallelizing this matrix vector operation used in the power method routine can greatly reduce the time required to compute the largest eigenvalue for the matrix A.

**Input:** There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference.

**Output:** This routine returns a double precision value that represents the largest eigenvalue of the matrix A.

**Usage/Example:**

There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A (1000x1000), a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference. This routine returns a double precision value that represents the largest eigenvalue of the matrix A.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>


    int main() {
        clock_t start, end;
        double time1 = 0.0;
        int i, j = 0;
        int n = 1000;
        int m = 1000;
        int maxiter = n * 6000;
        double tol = 0.0001;
        double eigenvalue = 0.0;

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

        // create uniformly distributed and diagnally dominant matrix
        // and create RHS vector
        uniformMatrix(A, v, n);

        printf("Matrix A =\n");

        //printMatrix(A, m, n);

        start = clock();

        eigenvalue = powerMethod(A, v, tol, maxiter, n);

        end = clock();
        time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nTime serial = %.3e\n", time1);

        printf("Largest eigenvalue of matrix A = %.3e", eigenvalue);

        start = clock();

        eigenvalue = powerMethodParallel(A, v, tol, maxiter, n);

        end = clock();
        time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nTime parallel = %.3e\n", time1);

        printf("Largest eigenvalue of matrix A = %.3e", eigenvalue);

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

    Finished after 7 iterations
    Time serial = 2.800e-02
    Largest eigenvalue of matrix A = 9.941e+02

    Finished after 7 iterations
    Time parallel = 7.000e-03
    Largest eigenvalue of matrix A = 9.941e+02

The output shows the largest eigenvalue of matrix A, the number of iterations it took to compute the eigenvalue, and the time it took to compute the eigenvalue for both serial and parallel programming. The parallel program took considerably less time to compute the eigenvalue.

**Implementation/Code:** The following is the code for powerMethodParallel()

    double powerMethodParallel(double **A, double *v0, double tol, int maxiter, int n) {
        int i, j = 0;
        int iter = 0;
        double temp = 0.0;
        double eigen0 = 0.0;
        double eigen1 = 0.0;
        double err = 10 * tol;

        // alloc memory for a vector
        double *y;
        y = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *v1;
        v1 = calloc(n, sizeof(double));

        matrixXvectorParallel(A, v0, y, n, n);

        while ((err > tol) && (iter < maxiter)) {
            iter++;

            temp = vectorNormL2(y, n);

            for (i = 0; i < n; i++) {
                v1[i] = y[i] / temp;
            }

            eigen1 = vectorInner(v1, y, n);

            matrixXvectorParallel(A, v1, y, n, n);

            err = eabs(eigen1, eigen0);

            eigen0 = eigen1;

        }
        printf("Finished after %d iterations\n\n", iter);

        // free memory
        free(y);
        free(v1);

        return eigen0;
    }

**Last Modified:** November/2018
