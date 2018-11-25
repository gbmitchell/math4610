# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 4.

**Routine Name:**           gaussSeidel

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    gauss_seidel.c

will produce an executable **gauss_seidel.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Gauss-Seidel iteration. Gauss-Seidel iteration provides an alternative way to solve a linear system. Iterative methods are an alternative to direct methods such as Gauss Elimination and LU Decomposition.

**Input:** There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Gauss-Seidel iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

**Usage/Example:**

There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Gauss-Seidel iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
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

        // solve linear system with gauss-seidel iteration
        gaussSeidel(A, b, x, tol, maxiter, n);

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
    3.039e+00       3.350e-01       8.510e-01       4.320e-01       3.740e-01       2.690e-01       7.680e-01       |6.068e+00
    3.350e-01       2.972e+00       1.450e-01       9.660e-01       1.000e-03       5.190e-01       9.960e-01       |5.934e+00
    8.510e-01       1.450e-01       2.601e+00       6.900e-02       2.280e-01       9.250e-01       3.730e-01       |5.192e+00
    4.320e-01       9.660e-01       6.900e-02       3.180e+00       8.610e-01       7.060e-01       1.360e-01       |6.350e+00
    3.740e-01       1.000e-03       2.280e-01       8.610e-01       2.058e+00       5.270e-01       5.700e-02       |4.106e+00
    2.690e-01       5.190e-01       9.250e-01       7.060e-01       5.270e-01       3.390e+00       4.340e-01       |6.770e+00
    7.680e-01       9.960e-01       3.730e-01       1.360e-01       5.700e-02       4.340e-01       2.774e+00       |5.538e+00

    Finished after 7 iterations

    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00

The output shows the matrix A augmented with vector b. Jacobi iteration completed after 7 iterations and produced the expected solution vector x containing all ones.

**Implementation/Code:** The following is the code for gaussSeidel()

    void gaussSeidel(double **A, double *b, double *x0, double tol, int maxiter, int n) {
        int i, j = 0;
        int iter = 0;
        double err = 10 * tol;

        // alloc memory for a vector
        double *x1;
        x1 = calloc(n, sizeof(double));

        while ((err > tol) && (iter < maxiter)) {
            iter++;

            for (i = 0; i < n; i++) {
                x1[i] = 0;
                for (j = 0; j < n; j++) {
                    if (i != j) {
                        x1[i] = x1[i] + (A[i][j] * x1[j]);
                    }
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
    }

**Last Modified:** November/2018
