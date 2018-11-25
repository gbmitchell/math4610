# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 1a.

**Routine Name:**           matrixInducedNormL1

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixInducedNorms.c

will produce an executable **matrixInducedNorms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the induced L1-norm given a matrix A and a vector v. The induced L1-norm of a matrix is used to give some sense of a magnitude for the given matrix. The induced L1-norm for a matrix A is computed by multiplying the matrix A by the vector v and computing the L1-norm of the resulting vector. The resulting L1-norm is then divided by the L1-norm of the vector v. Writen another way, the induced L1-norm for a matrix A is.

    ||Av||/||v||

**Input:** There are three inputs needed in this case. The matrix A and vector v are passed to the function by reference. An argument n is also passed to the function, n represents the size of the matrix and vector.

**Output:** The function returns a double precision value inducedNorm which represents the induced L1-norm of the input matrix A.

**Usage/Example:**

There are three inputs needed in this case. The matrix A and vector v are passed to the function by reference. An argument n is also passed to the function, n represents the size of the matrix and vector. The function returns a double precision value inducedNorm which represents the induced L1-norm of the input matrix A.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j, k = 0;
        int m = 3; // rows
        int n = 3; // col
        double inducedNormL1 = 0.0;

        // alloc memory for a matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a vector
        double *v;
        v = calloc(n, sizeof(double));

        // assign even values to matrix A
        k = 1;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = k * 2;
                k++;
            }
        }

        // assign even values to vector v
        k = 1;
        for (i = 0; i < n; i++) {
            v[i] = k;
            k++;
        }

        printf("\n\nMatrix A =\n");

        printMatrix(A, m, n);

        printf("\n\nVector v =\n");

        printVector(v, n);

        inducedNormL1 = matrixInducedNormL1(A, v, n);

        printf("\n\nInduced L1 norm of A = ||Av||/||v|| = %.3e\n", inducedNormL1);

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

    Matrix A =
    2.000e+00       4.000e+00       6.000e+00
    8.000e+00       1.000e+01       1.200e+01
    1.400e+01       1.600e+01       1.800e+01

    Vector v =
    1.000e+00
    2.000e+00
    3.000e+00

    Induced L1 norm of A = ||Av||/||v|| = 3.200e+01

The output show the computed induced L1-norm of matrix A is 32.

**Implementation/Code:** The following is the code for matrixInducedNormL1()

    double matrixInducedNormL1(double **A, double *v, int n) {
        double AvNorm = 0.0;
        double vNorm = 0.0;
        double inducedNorm = 0.0;

        // alloc memory for a vector
        double *u;
        u = calloc(n, sizeof(double));

        vectorXmatrix(A, v, u, n, n);
        AvNorm = vectorNormL1(u, n);
        vNorm = vectorNormL1(v, n);
        inducedNorm = AvNorm / vNorm;

        // free memory
        free(u);

        return inducedNorm;
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 1b.

**Routine Name:**           matrixInducedNormInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixInducedNorms.c

will produce an executable **matrixInducedNorms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the induced Infinity-norm given a matrix A and a vector v. The induced Infinity-norm of a matrix is used to give some sense of a magnitude for the given matrix. The induced Infinity-norm for a matrix A is computed by multiplying the matrix A by the vector v and computing the Infinity-norm of the resulting vector. The resulting Infinity-norm is then divided by the Infinity-norm of the vector v. Writen another way, the induced Infinity-norm for a matrix A is.

    ||Av||/||v||

**Input:** There are three inputs needed in this case. The matrix A and vector v are passed to the function by reference. An argument n is also passed to the function, n represents the size of the matrix and vector.

**Output:** The function returns a double precision value inducedNorm which represents the induced Infinity-norm of the input matrix A.

**Usage/Example:**

There are three inputs needed in this case. The matrix A and vector v are passed to the function by reference. An argument n is also passed to the function, n represents the size of the matrix and vector. The function returns a double precision value inducedNorm which represents the induced Infinity-norm of the input matrix A.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j, k = 0;
        int m = 3; // rows
        int n = 3; // col
        double inducedNormInfinity = 0.0;

        // alloc memory for a matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a vector
        double *v;
        v = calloc(n, sizeof(double));

        // assign even values to matrix A
        k = 1;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = k * 2;
                k++;
            }
        }

        // assign even values to vector v
        k = 1;
        for (i = 0; i < n; i++) {
            v[i] = k;
            k++;
        }

        printf("\n\nMatrix A =\n");

        printMatrix(A, m, n);

        printf("\n\nVector v =\n");

        printVector(v, n);

        inducedNormInfinity = matrixInducedNormInfinity(A, v, n);

        printf("\n\nInduced Infinity norm of A = ||Av||/||v|| = %.3e\n", inducedNormInfinity);

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

    Matrix A =
    2.000e+00       4.000e+00       6.000e+00
    8.000e+00       1.000e+01       1.200e+01
    1.400e+01       1.600e+01       1.800e+01

    Vector v =
    1.000e+00
    2.000e+00
    3.000e+00

    Induced Infinity norm of A = ||Av||/||v|| = 3.333e+01

The output show the computed induced Infinity-norm of matrix A is 33.33.

**Implementation/Code:** The following is the code for matrixInducedNormInfinity()

    double matrixInducedNormInfinity(double **A, double *v, int n) {
        double AvNorm = 0.0;
        double vNorm = 0.0;
        double inducedNorm = 0.0;

        // alloc memory for a vector
        double *u;
        u = calloc(n, sizeof(double));

        vectorXmatrix(A, v, u, n, n);
        AvNorm = vectorNormInfinity(u, n);
        vNorm = vectorNormInfinity(v, n);
        inducedNorm = AvNorm / vNorm;

        // free memory
        free(u);

        return inducedNorm;
    }

**Last Modified:** November/2018
