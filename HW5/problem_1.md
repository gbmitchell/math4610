# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 1a.

**Routine Name:**           matrixInducedNormL1

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the L1-norm given a matrix. The function was developed to compute the L1-norm of a 3x3 matrix. The L1-norm is used to give some sense of a magnitude for the given matrix. The L1-norm for a matrix is computed by summing each column in the matrix and then indentifying which sum is maximum.

**Input:** There are two inputs needed in this case. The matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function.

**Output:** The function returns a double precision value max which represents the L1-norm of the input matrix.

**Usage/Example:**

There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function. The function returns a double precision value max which represents the L1-norm of the input matrix A. 

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

The sum of column 1 is 2 + 8 + 14 = 24, the sum of column 2 is 4 + 10 + 16 = 30, and the sum of column 3 is 6 + 12 + 18 = 36.
The max of these sums is 36, therefore the L1-norm is 36.

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

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the Infinity-norm given a matrix. The function was developed to compute the Infinity-norm of a 3x3 matrix. The Infinity-norm is used to give some sense of a magnitude for the given matrix. The Infinity-norm for a matrix is computed by summing each row in the matrix and then indentifying which sum is maximum.

**Input:** There are two inputs needed in this case. The matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function.

**Output:** The function returns a double precision value max which represents the Infinity-norm of the input matrix.

**Usage/Example:**

There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function. The function returns a double precision value max which represents the Infinity-norm of the input matrix A.

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

The sum of row 1 is 2 + 4 + 6 = 12, the sum of row 2 is 8 + 10 + 12 = 30, and the sum of row 3 is 14 + 16 + 18 = 48.
The max of these sums is 48, therefore the Infinity-norm is 48.

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
