# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           uniformMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    uniformDiagDomMatrix.c

will produce an executable **uniformDiagDomMatrix.exe** that can be executed.

**Description/Purpose:** This function will creat a symetric, uniform, and diagonally dominant matrix of size mxn. First, the matrix is filled with values in the upper triangular part. Next, the upper triangular part is transposed to the lower triangular part of the matrix to make it symetric. Finally, the main diaginal values are computed and assigned to make the matrix diagonally dominant. Additionally, the right hand side vector b is computed by multiplying the matrix A by a vector of ones. The purpose of this routine is to generate random matrices with a right hand side to be used as test problems for linear solving routines. When solved corectly, the solution vector x should be a vector of ones.

**Input:** There are three inputs needed in this case. The matrix A and vector b are passed to the function by reference. An argument n is also passed to the function, n represents the size of the matrix and vector.

**Output:** The function does not return anything, instead it changes the values in the matrix A and the vector b. The matrix A is a symetric, uniform, diagonally dominant matrix. The vector b is the right hand side for the linear system Ax=b.

**Usage/Example:**

There are three inputs needed in this case. The matrix A and vector b are passed to the function by reference. An argument n is also passed to the function, n represents the size of the matrix and vector. The function does not return anything, instead it changes the values in the matrix A and the vector b. The matrix A is a symetric, uniform, and a diagonally dominant matrix. The vector b is the right hand side for the linear system Ax=b.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i, j = 0;
        int n = 7;
        int m = 7;

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

        printf("\n\n\n");

        // create uniformly distributed and diagnally dominant matrix
        // and create RHS vector by multiplying matrix by vector of ones
        uniformMatrix(A, b, n);

        printf("Uniform diagnaly dominent matrix A augmented with vector b =\n");

        printAugMatrix(A, b, m, n);

        printf("\n\n\n");

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);
        free(b);

        return 0;
    }

Output from the lines above:

    Uniform diagnaly dominent matrix A augmented with vector b =
    1.854e+00       1.080e-01       1.340e-01       6.430e-01       1.340e-01       7.380e-01       8.700e-02       |3.698e+00
    1.080e-01       1.940e+00       9.070e-01       1.610e-01       3.290e-01       2.160e-01       2.090e-01       |3.870e+00
    1.340e-01       9.070e-01       4.125e+00       7.090e-01       8.380e-01       9.040e-01       6.230e-01       |8.240e+00
    6.430e-01       1.610e-01       7.090e-01       3.378e+00       4.970e-01       8.300e-01       5.280e-01       |6.746e+00
    1.340e-01       3.290e-01       8.380e-01       4.970e-01       3.443e+00       9.700e-01       6.650e-01       |6.876e+00
    7.380e-01       2.160e-01       9.040e-01       8.300e-01       9.700e-01       3.892e+00       2.240e-01       |7.774e+00
    8.700e-02       2.090e-01       6.230e-01       5.280e-01       6.650e-01       2.240e-01       2.346e+00       |4.682e+00

The output shows a computed 7x7 matrix A augmented with the computed right hand side vector b.

**Implementation/Code:** The following is the code for uniformMatrix()

    void uniformMatrix(double **A, double *b, int n) {
        int i, j, k = 0;
        double sum = 0.0;

        double *ones;
        ones = calloc(n, sizeof(double));

        for (i = 0; i < n; i++) {
            ones[i] = 1.0;
        }

        srand(time(0));

        // upper triangular
        for (i = 0; i < n; i++) {
            for (j = (i + 1); j < n; j++) {
                A[i][j] = ((rand() % 1000) + 1) / 1000.0;
            }
        }

        // lower triangular
        for (i = 0; i < n; i++) {
            for (j = (i + 1); j < n; j++) {
                A[j][i] = A[i][j];
            }
        }

        // diaginal dominant
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum = sum + A[i][j];
                }
            }
            A[i][i] = sum + 0.01;
            sum = 0.0;
        }

        // compute RHS values for vector b
        vectorXmatrix(A, ones, b, n, n);

        free(ones);
    }

**Last Modified:** November/2018
