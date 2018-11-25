# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 7.

**Routine Name:**           jacobiParallel

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    jacobiParallel.c

will produce an executable **jacobiParallel.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Jacobi iteration. This version of Jacobi iteration uses opemMP to execute matrix vector operations in parallel in an effort to decrease the amount of time it takes to compute a solution.

**Input:** There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Jacobi iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

**Usage/Example:**

There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Jacobi iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>


    int main() {
        clock_t start, end;
        double time1 = 0.0;
        double time2 = 0.0;

        int i, j = 0;
        int n = 7;
        int m = 7;
        int maxiter = n * 6000;
        double tol = 0.0001;

        // allocate mxn matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // allocate vector for RHS
        double *b;
        b = calloc(n, sizeof(double));

        // allocate vector for solution
        double *x;
        x = calloc(n, sizeof(double));

        // create uniformly distributed and diagnally dominant matrix
        // and create RHS vector
        uniformMatrix(A, b, n);

        printf("Uniform diagnaly dominent matrix A augmented with vector b =\n");

        printAugMatrix(A, b, m, n);

        for (i = 0; i < n; i++) {
            x[i] = 0.0;
        }

        start = clock();

        // solve linear system with jacobi iteration
        jacobi(A, b, x, tol, maxiter, n);

        end = clock();
        time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\ntime 1 = %.3e\n", time1);

        printf("Solution vector x =\n");

        printVector(x, n);

        for (i = 0; i < n; i++) {
            x[i] = 0.0;
        }

        start = clock();

        // solve linear system with jacobi iteration
        jacobiParallel(A, b, x, tol, maxiter, n);

        end = clock();
        time2 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\ntime 2 = %.3e\n", time2);

        printf("Solution vector x =\n");

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

    Uniform diagnaly dominent matrix A augmented with vector b =
    3.912e+00       9.510e-01       1.710e-01       6.040e-01       8.640e-01       6.130e-01       6.990e-01       |7.814e+00
    9.510e-01       2.770e+00       7.470e-01       3.150e-01       3.550e-01       1.420e-01       2.500e-01       |5.530e+00
    1.710e-01       7.470e-01       2.245e+00       4.000e-03       1.980e-01       1.170e-01       9.980e-01       |4.480e+00
    6.040e-01       3.150e-01       4.000e-03       2.973e+00       5.370e-01       6.160e-01       8.870e-01       |5.936e+00
    8.640e-01       3.550e-01       1.980e-01       5.370e-01       3.111e+00       7.800e-01       3.670e-01       |6.212e+00
    6.130e-01       1.420e-01       1.170e-01       6.160e-01       7.800e-01       2.318e+00       4.000e-02       |4.626e+00
    6.990e-01       2.500e-01       9.980e-01       8.870e-01       3.670e-01       4.000e-02       3.251e+00       |6.492e+00

    Finished after 2908 iterations
    time 1 = 3.000e-03

    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00

    Finished after 2908 iterations
    time 2 = 2.500e-02

    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00

The output shows the matrix A augmented with vector b. Jacobi iteration completed after 2908 iterations and produced the expected solution vector x containing all ones. The first solution vector x was computed with serial programing and took 0.0030 seconds. The second solution vector x was computed with parallel programing and took 0.0025 seconds.

**Implementation/Code:** The following is the code for jacobiParallel()

    void jacobiParallel(double **A, double *b, double *x0, double tol, int maxiter, int n) {
        int i, j = 0;
        int iter = 0;
        double err = 10 * tol;

        // alloc memory for a vector
        double *x1;
        x1 = calloc(n, sizeof(double));

        while ((err > tol) && (iter < maxiter)) {
            iter++;

            // begin parallel threads
    #pragma omp parallel private(i, j)
            {
    #pragma omp for
                for (i = 0; i < n; i++) {
                    x1[i] = 0;
                    for (j = 0; j < n; j++) {
                        if (i != j) {
                            x1[i] = x1[i] + (A[i][j] * x0[j]);
                        }
                    }
                    x1[i] = (b[i] - x1[i]) / A[i][i];
                }
            }

            err = vectorErrorRelativeL2(x1, x0, n);

            for (i = 0; i < n; i++) {
                x0[i] = x1[i];
            }
        }
        printf("Finished after %d iterations\n\n", iter);

        // free memory
        free(x1);
    }

**Last Modified:** November/2018
