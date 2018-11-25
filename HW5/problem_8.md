# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 8.

**Routine Name:**           gaussSeidelParallel

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    gauss_seidel_Parallel.c

will produce an executable **gauss_seidel_Parallel.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Gauss-Seidel iteration. This version of Gauss-Seidel iteration uses openMP to execute matrix vector operations in parallel in an effort to decrease the amount of time it takes to compute a solution.

**Input:** There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Gauss-Seidel iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

**Usage/Example:**

There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Gauss-Seidel iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

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

        //printAugMatrix(A, b, m, n);

        for (i = 0; i < n; i++) {
            x[i] = 2.0;
        }

        start = clock();

        // solve linear system with jacobi iteration
        //gaussSeidel(A, b, x, tol, maxiter, n);
        gaussSeidel(A, b, x, tol, maxiter, n);
        end = clock();
        time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\ntime 1 = %.3e\n", time1);

        printf("Solution vector x =\n");

        //printVector(x, n);

        for (i = 0; i < n; i++) {
            x[i] = 2.0;
        }

        start = clock();

        // solve linear system with jacobi iteration
        gaussSeidelParallel(A, b, x, tol, maxiter, n);

        end = clock();
        time2 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\ntime 2 = %.3e\n", time2);

        printf("Solution vector x =\n");

        //printVector(x, n);

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
    4.314e+00       2.980e-01       9.580e-01       7.830e-01       7.320e-01       9.570e-01       5.760e-01       |8.618e+00
    2.980e-01       2.608e+00       4.540e-01       6.200e-02       7.000e-02       7.880e-01       9.260e-01       |5.206e+00
    9.580e-01       4.540e-01       4.521e+00       9.930e-01       3.490e-01       9.420e-01       8.150e-01       |9.032e+00
    7.830e-01       6.200e-02       9.930e-01       2.702e+00       4.010e-01       2.880e-01       1.650e-01       |5.394e+00
    7.320e-01       7.000e-02       3.490e-01       4.010e-01       2.714e+00       4.190e-01       7.330e-01       |5.418e+00
    9.570e-01       7.880e-01       9.420e-01       2.880e-01       4.190e-01       3.923e+00       5.190e-01       |7.836e+00
    5.760e-01       9.260e-01       8.150e-01       1.650e-01       7.330e-01       5.190e-01       3.744e+00       |7.478e+00

    Finished after 8 iterations
    time 1 = 0.000e+00

    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00

    Finished after 8 iterations
    time 2 = 6.000e-03
    
    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    
    
    Uniform diagnaly dominent matrix A augmented with vector b =

    Finished after 8 iterations
    time 1 = 1.200e-02
    Solution vector x =

    Finished after 8 iterations
    time 2 = 6.800e-02
    Solution vector x =

The output shows the matrix A augmented with vector b. Gauss-Seidel completed after 8 iterations and produced the expected solution vector x containing all ones. The first solution vector x was computed with serial programing and took 0.000 seconds. The second solution vector x was computed with parallel programing and took 0.006 seconds. The parallel version takes longer in the case of a 7x7 matrix because it takes some overhead to set up the parallel threads. Running the code again with a matrix size of 640x640 resulted in 8 iterations. The serial program took 0.012 seconds while the parallel program took 0.068 seconds. Again the parallel version took longer. Due to the nature of Gauss-Seidel, I was only able to parallelize short portions of each iteration and the result is more overhead and time to set up the threads. The overhead and time to creat the parallel threads makes it more efficient to use the serial version of Gauss-Seidel.

**Implementation/Code:** The following is the code for gaussSeidelParallel()

    void gaussSeidelParallel(double **A, double *b, double *x0, double tol, int maxiter, int n) {
        int i, j = 0;
        int iter = 0;
        double err = 10 * tol;

        // alloc memory for a vector
        double *x1;
        x1 = calloc(n, sizeof(double));
        // alloc memory for a vector
        double *s1;
        s1 = calloc(n, sizeof(double));
        // alloc memory for a vector
        double *s2;
        s2 = calloc(n, sizeof(double));

        while ((err > tol) && (iter < maxiter)) {
            iter++;

            for (i = 0; i < n; i++) {
                x1[i] = 0;

                // begin parallel threads
    #pragma omp parallel
                {
    #pragma omp for
                    for (j = 0; j < n; j++) {
                        s1[j] = 0.0;
                        s2[j] = 0.0;
                    }
    #pragma omp barrier
    #pragma omp for	
                    for (j = 0; j < i; j++) {
                        s1[j] = (A[i][j] * x1[j]);
                    }
    #pragma omp barrier
    #pragma omp for			
                    for (j = (i + 1); j < n; j++) {
                        s2[j] = (A[i][j] * x1[j]);
                    }
                }

                for (j = 0; j < n; j++) {
                    x1[i] = x1[i] + s1[j] + s2[j];
                }

                x1[i] = (b[i] - x1[i]) / A[i][i];
            }

            err = vectorErrorRelativeL2(x1, x0, n);


            for (i = 0; i < n; i++) {
                x0[i] = x1[i];
            }
        }
        printf("Finished after %d iterations\n\n", iter);

        // free memory
        free(x1);
        free(s1);
        free(s2);
    }

**Last Modified:** November/2018
