# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           conjugateGradient

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    conjugateGradient.c

will produce an executable **conjugateGradient.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Conjugate Gradient iteration. Conjugate Gradient iteration provides an alternative way to solve a linear system. Iterative methods are an alternative to direct methods such as Gauss Elimination and LU Decomposition.

**Input:** There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Conjugate Gradient iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

**Usage/Example:**

There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Conjugate Gradient iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>


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
        conjugateGradient(A, b, x, tol, maxiter, n);

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
    3.563e+00       2.970e-01       5.600e-01       8.440e-01       3.120e-01       9.400e-01       6.000e-01       |7.116e+00
    2.970e-01       2.036e+00       9.000e-02       1.350e-01       3.700e-02       5.500e-01       9.170e-01       |4.062e+00
    5.600e-01       9.000e-02       2.591e+00       4.840e-01       4.040e-01       6.980e-01       3.450e-01       |5.172e+00
    8.440e-01       1.350e-01       4.840e-01       2.478e+00       8.690e-01       2.000e-03       1.340e-01       |4.946e+00
    3.120e-01       3.700e-02       4.040e-01       8.690e-01       3.418e+00       8.210e-01       9.650e-01       |6.826e+00
    9.400e-01       5.500e-01       6.980e-01       2.000e-03       8.210e-01       3.631e+00       6.100e-01       |7.252e+00
    6.000e-01       9.170e-01       3.450e-01       1.340e-01       9.650e-01       6.100e-01       3.581e+00       |7.152e+00

    Finished after 7 iterations

    Solution vector x =
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00
    1.000e+00

The output shows the matrix A augmented with vector b. Conjugate Gradient completed after 7 iterations and produced the expected solution vector x containing all ones.

**Implementation/Code:** The following is the code for conjugateGradient()

    void conjugateGradient(double **A, double *b, double *x0, double tol, int maxiter, int n) {
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

        // r0 = b - Ax0
        for (i = 0; i < n; i++) {
            r0[i] = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    r0[i] = r0[i] - (A[i][j] * x0[j]);
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
