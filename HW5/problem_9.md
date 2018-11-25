# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 9.

**Routine Name:**           conjugateGradientParallel

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    conjugateGradientParallel.c

will produce an executable **conjugateGradientParallel.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Conjugate Gradient iteration. This version of Conjugate Gradient iteration uses openMP to execute matrix vector operations in parallel in an effort to decrease the amount of time it takes to compute a solution.

**Input:** There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Conjugate Gradient iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

**Usage/Example:**

There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Conjugate Gradient iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

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
        double tol = 0.00000001;

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
        conjugateGradient(A, b, x, tol, maxiter, n);

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
        conjugateGradientParallel(A, b, x, tol, maxiter, n);

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
    2.249e+00       7.220e-01       5.600e-02       1.830e-01       3.620e-01       3.700e-02       8.790e-01       |4.488e+00
    7.220e-01       3.100e+00       7.530e-01       5.330e-01       7.310e-01       2.290e-01       1.220e-01       |6.190e+00
    5.600e-02       7.530e-01       2.838e+00       1.410e-01       8.050e-01       1.340e-01       9.390e-01       |5.666e+00
    1.830e-01       5.330e-01       1.410e-01       2.810e+00       8.580e-01       9.570e-01       1.280e-01       |5.610e+00
    3.620e-01       7.310e-01       8.050e-01       8.580e-01       3.839e+00       6.760e-01       3.970e-01       |7.668e+00
    3.700e-02       2.290e-01       1.340e-01       9.570e-01       6.760e-01       2.076e+00       3.300e-02       |4.142e+00
    8.790e-01       1.220e-01       9.390e-01       1.280e-01       3.970e-01       3.300e-02       2.508e+00       |5.006e+00

    Finished after 7 iterations
    time 1 = 0.000e+00

    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00

    Finished after 7 iterations
    time 2 = 0.000e+00

    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00

    Uniform diagnaly dominent matrix A augmented with vector b =

    Finished after 6 iterations
    time 1 = 1.100e-02
    Solution vector x =

    Finished after 6 iterations
    time 2 = 9.000e-03
    Solution vector x =

The output shows the matrix A augmented with vector b. Conjugate Gradient completed after 7 iterations and produced the expected solution vector x containing all ones. The first solution vector x was computed with serial programing and took 0.000 seconds. The second solution vector x was computed with parallel programing and took 0.000 seconds. The serial and parallel version were so quick in the case of a 7x7 matrix that no difference could be seen. Running the code again with a matrix size of 640x640 resulted in 6 iterations. The serial program took 0.011 seconds while the parallel program took 0.009 seconds. It can be concluded that parallel programing is benificial in larger systems.

**Implementation/Code:** The following is the code for conjugateGradientParallel()

    void conjugateGradientParallel(double **A, double *b, double *x0, double tol, int maxiter, int n) {
        int i, j = 0;
        int iter = 0;
        double err = 10 * tol;
        double delta0 = 0.0;
        double delta1 = 0.0;
        double alpha = 0.0;
        double temp = 0.0;



        // alloc memory for a vector
        double *x1;
        x1 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *r0;
        r0 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *r1;
        r1 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *p0;
        p0 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *p1;
        p1 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *s;
        s = calloc(n, sizeof(double));

        // begin parallel threads
    #pragma omp parallel private(i, j)
        {
    #pragma omp for
            // r0 = b - Ax0
            for (i = 0; i < n; i++) {
                r0[i] = b[i];
                for (j = 0; j < n; j++) {
                    if (i != j) {
                        r0[i] = r0[i] - (A[i][j] * x0[j]);
                    }
                }
            }
        }

        delta0 = vectorInner(r0, r0, n);
        err = vectorInner(b, b, n);

        for (i = 0; i < n; i++) {
            p0[i] = r0[i];
        }


        while ((delta0 > (tol * tol * err)) && (iter < maxiter)) {
            iter++;

            vectorXmatrix(A, p0, s, n, n);
            temp = vectorInner(p0, s, n);
            alpha = delta0 / temp;

            for (i = 0; i < n; i++) {
                x1[i] = x0[i] + (alpha * p0[i]);
            }

            for (i = 0; i < n; i++) {
                r1[i] = r0[i] - (alpha * s[i]);
            }

            delta1 = vectorInner(r1, r1, n);

            for (i = 0; i < n; i++) {
                p1[i] = r1[i] + ((delta1 / delta0) * p0[i]);
            }

            for (i = 0; i < n; i++) {
                p0[i] = p1[i];
            }

            for (i = 0; i < n; i++) {
                r0[i] = r1[i];
            }

            delta0 = delta1;

            for (i = 0; i < n; i++) {
                x0[i] = x1[i];
            }
        }

        printf("Finished after %d iterations\n\n", iter);

        // free memory
        free(x1);
        free(r0);
        free(r1);
        free(p0);
        free(p1);
        free(s);
    }

**Last Modified:** November/2018
