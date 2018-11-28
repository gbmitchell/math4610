# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           matrixNormInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixNorms.c

will produce an executable **matrixNorms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the Infinity-norm given a matrix. The function was developed to compute the Infinity-norm of a 3x3 matrix. The Infinity-norm is used to give some sense of a magnitude for the given matrix. The Infinity-norm for a matrix is computed by summing each row in the matrix and then indentifying which sum is maximum.

**Input:** There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function.

**Output:** The function returns a double precision value max which represents the Infinity-norm of the input matrix.

**Usage/Example:**

There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function. The function returns a double precision value max which represents the Infinity-norm of the input matrix A.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i, j, k = 0;
        double normInfinity = 0.0;

        int m = 3; // rows
        int n = 3; // col

        // alloc memory for a matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // assign even values to matrix A
        k = 1;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = k * 2;
                k++;
            }
        }

        printf("\n\nMatrix A =\n");

        printMatrix(A, m, n);

        normInfinity = matrixNormInfinity(A, n);

        printf("\n\nInfinity norm of A = %.3e\n", normInfinity);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);

        return 0;
    }

Output from the lines above:

    Matrix A =
    2.000e+00       4.000e+00       6.000e+00
    8.000e+00       1.000e+01       1.200e+01
    1.400e+01       1.600e+01       1.800e+01

    Infinity norm of A = 4.800e+01

The sum of row 1 is 2 + 4 + 6 = 12, the sum of row 2 is 8 + 10 + 12 = 30, and the sum of row 3 is 14 + 16 + 18 = 48.
The max of these sums is 48, therefore the Infinity-norm is 48.

**Implementation/Code:** The following is the code for matrixNormInfinity()

    double matrixNormInfinity(double **a, int len) {
        int i, j = 0;
        double ia = 0.0;
        double max = 0.0;
        for (i = 0; i < len; i++) {
            ia = 0.0;
            for (j = 0; j < len; j++) {
                ia = ia + fabs(a[i][j]);
            }
            if (max < ia) {
                max = ia;
            }
        }

        return max;
    }

**Last Modified:** November/2018
