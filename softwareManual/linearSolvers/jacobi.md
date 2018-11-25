# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           jacobi

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    jacobi.c

will produce an executable **jacobi.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Jacobi iteration. Jacobi iteration provides an alternative way to solve a linear system. Iterative methods are an alternative to direct methods such as Gauss Elimination and LU Decomposition.

**Input:** There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Jacobi iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

**Usage/Example:**

There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Jacobi iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

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

        // solve linear system with jacobi iteration
        jacobi(A, b, x, tol, maxiter, n);

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
    4.255e+00       9.630e-01       6.550e-01       9.470e-01       5.410e-01       3.820e-01       7.570e-01       |8.500e+00
    9.630e-01       2.106e+00       1.090e-01       1.950e-01       3.810e-01       1.400e-02       4.340e-01       |4.202e+00
    6.550e-01       1.090e-01       3.153e+00       6.270e-01       5.460e-01       5.620e-01       6.440e-01       |6.296e+00
    9.470e-01       1.950e-01       6.270e-01       2.886e+00       9.010e-01       1.410e-01       6.500e-02       |5.762e+00
    5.410e-01       3.810e-01       5.460e-01       9.010e-01       3.745e+00       7.940e-01       5.720e-01       |7.480e+00
    3.820e-01       1.400e-02       5.620e-01       1.410e-01       7.940e-01       2.864e+00       9.610e-01       |5.718e+00
    7.570e-01       4.340e-01       6.440e-01       6.500e-02       5.720e-01       9.610e-01       3.443e+00       |6.876e+00

    Finished after 3173 iterations

    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00

The output shows the matrix A augmented with vector b. Jacobi iteration completed after 3173 iterations and produced the expected solution vector x containing all ones.

**Implementation/Code:** The following is the code for jacobi()

    void jacobi(double **A, double *b, double *x0, double tol, int maxiter, int n) {
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
                        x1[i] = x1[i] + (A[i][j] * x0[j]);
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
