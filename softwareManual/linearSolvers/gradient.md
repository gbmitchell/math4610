# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           gradient

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    gradient.c

will produce an executable **gradient.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Gradient (steepest descent) iteration. Gradient iteration provides an alternative way to solve a linear system. Iterative methods are an alternative to direct methods such as Gauss Elimination and LU Decomposition.

**Input:** There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Gradient iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

**Usage/Example:**

There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Gradient iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j = 0;
        int n = 7;
        int m = 7;
        int maxiter = n * 6000;
        double tol = 0.0000000001;

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
        gradient(A, b, x, tol, maxiter, n);

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
    3.519e+00       5.100e-01       8.630e-01       6.030e-01       6.660e-01       6.650e-01       2.020e-01       |7.028e+00
    5.100e-01       3.531e+00       8.340e-01       7.040e-01       5.560e-01       9.300e-02       8.240e-01       |7.052e+00
    8.630e-01       8.340e-01       3.706e+00       5.800e-01       6.160e-01       1.260e-01       6.770e-01       |7.402e+00
    6.030e-01       7.040e-01       5.800e-01       3.215e+00       3.060e-01       2.800e-02       9.840e-01       |6.420e+00
    6.660e-01       5.560e-01       6.160e-01       3.060e-01       2.780e+00       2.750e-01       3.510e-01       |5.550e+00
    6.650e-01       9.300e-02       1.260e-01       2.800e-02       2.750e-01       1.350e+00       1.530e-01       |2.690e+00
    2.020e-01       8.240e-01       6.770e-01       9.840e-01       3.510e-01       1.530e-01       3.201e+00       |6.392e+00

    Finished after 60 iterations

    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00

The output shows the matrix A augmented with vector b. Gradient iteration completed after 60 iterations and produced the expected solution vector x containing all ones.

**Implementation/Code:** The following is the code for gradient()

    // steepest descent method
    void gradient(double **A, double *b, double *x0, double tol, int maxiter, int n) {
        int i, j = 0;
        int iter = 0;
        double err = 10 * tol;
        double rnorm = 0.0;
        double ynorm = 0.0;
        double alpha = 0.0;
        double diff = 0.0;

        // alloc memory for a vector
        double *x1;
        x1 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *r0;
        r0 = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *y;
        y = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *u;
        u = calloc(n, sizeof(double));

        while ((err > tol) && (iter < maxiter)) {
            iter++;

            // r0 = b - Ax0
            // Ax0 = u;
            vectorXmatrix(A, x0, u, n, n);

            // r0 = b - u
            for (i = 0; i < n; i++) {
                r0[i] = b[i] - u[i];
            }

            rnorm = 0.0;
            for (i = 0; i < n; i++) {
                rnorm = rnorm + (r0[i] * r0[i]);
            }

            vectorXmatrix(A, r0, y, n, n);

            ynorm = 0.0;
            for (i = 0; i < n; i++) {
                ynorm = ynorm + (r0[i] * y[i]);
            }

            alpha = rnorm / ynorm;

            for (i = 0; i < n; i++) {
                x1[i] = x0[i] + (alpha * r0[i]);
            }

            // compute error
            err = 0.0;
            for (i = 0; i < n; i++) {
                diff = x1[i] - x0[i];
                err = err + (diff * diff);
            }
            err = sqrt(err);

            // x0 = x1
            for (i = 0; i < n; i++) {
                x0[i] = x1[i];
            }
        }

        printf("Finished after %d iterations\n\n", iter);

        // free memory
        free(x1);
        free(r0);
        free(y);
        free(u);
    }

**Last Modified:** November/2018
