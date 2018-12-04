# Math 4610 Fundamentals of Computational Mathematics
Homework 6 problem 5.

**Routine Name:**           inversePowerMethodParallel

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    inversePowerMethodParallel.c

will produce an executable **inversePowerMethodParallel.exe** that can be executed.

**Description/Purpose:** This routine will compute the largest eigenvalue of a matrix inverse, for example A^(-1). The routine uses openMP to parallelize the program which results in less time to compute the eigenvalue for large sized matrices. Because the inverse power method uses LU factorization, I was able to find very little of the routine that was able to take advantage of parallel processing. As a result, the parallel version of inverse power method takes a little less time.

**Input:** There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference.

**Output:** This routine returns a double precision value that represents the largest eigenvalue of the matrix A^(-1).

**Usage/Example:**

There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference. This routine returns a double precision value that represents the largest eigenvalue of the matrix A^(-1).

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

        printf("Matrix A =\n");

        //printMatrix(A, m, n);

        start = clock();

        eigenvalue = inversePowerMethod(A, v, tol, maxiter, n);

        end = clock();
        time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nTime serial = %.3e\n", time1);

        printf("Largest eigenvalue of A^(-1) = %.3e", eigenvalue);

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = T[i][j];
            }
        }

        for (i = 0; i < n; i++) {
            v[i] = tempv[i];
        }

        start = clock();

        eigenvalue = inversePowerMethodParallel(A, v, tol, maxiter, n);

        end = clock();
        time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nTime parallel = %.3e\n", time1);

        printf("Largest eigenvalue of A^(-1) = %.3e", eigenvalue);

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

    Finished after 3 iterations
    Time serial = 1.491e+00
    Largest eigenvalue of A^(-1) = 1.014e-03

    Finished after 3 iterations
    Time parallel = 1.386e+00
    Largest eigenvalue of A^(-1) = 1.014e-03

The output shows the largest eigenvalue of matrix A^(-1), the number of iterations it took to compute the eigenvalue, and the time it took to compute the eigenvalue for both serial and parallel programming. The parallel program took a little less time to compute compared to the serial program with a matrix size of 1000x1000. 

**Implementation/Code:** The following is the code for inversePowerMethodParallel()

    double inversePowerMethodParallel(double **A, double *v0, double tol, int maxiter, int n) {
        int i, j = 0;
        int iter = 0;
        double temp = 0.0;
        double eigen0 = 0.0;
        double eigen1 = 0.0;
        double err = 10 * tol;

        // alloc memory for a matrix
        double **L;
        L = calloc(n, sizeof(double*));

        for (i = 0; i < n; i++)
        {
            L[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a vector
        double *y;
        y = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *yd;
        yd = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *v1;
        v1 = calloc(n, sizeof(double));

        LUsolve(A, L, y, v0, n);

        while ((err > tol) && (iter < maxiter)) {
            iter++;

            temp = vectorNormL2(y, n);

    #pragma omp parallel private(i)
            {
    #pragma omp for
                for (i = 0; i < n; i++) {
                    v1[i] = y[i] / temp;
                }
            }

            eigen1 = vectorInner(v1, y, n);

            forwardSub(L, yd, v1, n);
            backSub(A, y, yd, n);

            err = eabs(eigen1, eigen0);

            eigen0 = eigen1;

        }
        printf("Finished after %d iterations\n\n", iter);


        // free memory
        for (i = 0; i < n; i++)
        {
            free(L[i]);
        }

        free(L);

        free(y);
        free(v1);
        free(yd);

        return eigen0;
    }

**Last Modified:** November/2018
