# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           generalGauss

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    generalGauss.c

will produce an executable **generalGauss.exe** that can be executed.

**Description/Purpose:** This routine will compute the necassary factors and carry out row operations for Gauss Elimination of a general matrix mxn up to size. No pivoting methods are used in this routine.

**Input:** There are four inputs needed in this case. A general matrix of size mxn and a vector of size n are arguments passed by reference and the routine will change their values according to the process for Gauss Elimination. The variables m and n are also passed to the routine to indicate the size of the matrix and vector. The vector and matrix are treated as though they are combined to form an augmented matrix even though they remain separate.

**Output:** This routine does not return anything, instead it changes the original matrix and vector values as though they were an augmented matrix going through the Gauss Elimination process.

**Usage/Example:**

There are four inputs needed in this case. A general matrix (A) of size mxn (4x5) and a vector (b) of size m (4) are arguments passed by reference and the routine will change their values according to the process for Gauss Elimination. The variables m (4) and n (5) are also passed to the routine to indicate the size of the matrix and vector. The vector and matrix are treated as though they are combined to form an augmented matrix even though they remain separate. This routine does not return anything, instead it changes the original matrix and vector values as though they were an augmented matrix going through the Gauss Elimination process. 

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j = 0;
        int m = 4;
        int n = 5;

        // alloc memory for a matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a vector
        double *b;
        b = calloc(n, sizeof(double));

        double C[50][50] = { {1.0, -1.0, 3.0, 1.0, 1.0}, {3.0, 1.0, 7.0, 1.0, 5.0}, {-4.0, 4.0, 1.0, -2.0, 2.0}, {2.0, 1.0, 2.0, 1.0, 3.0} };

        double bc[50] = { 4.0, 5.0, 6.0, 7.0 };

        A[0][0] = 1.0;  A[0][1] = -1.0; A[0][2] = 3.0; A[0][3] = 1.0; A[0][4] = 1.0;
        A[1][0] = 3.0;  A[1][1] = 1.0; A[1][2] = 7.0; A[1][3] = 1.0; A[1][4] = 5.0;
        A[2][0] = -4.0; A[2][1] = 4.0; A[2][2] = 1.0; A[2][3] = -2.0; A[2][4] = 2.0;
        A[3][0] = 2.0; A[3][1] = 1.0; A[3][2] = 2.0; A[3][3] = 1.0; A[3][4] = 3.0;

        b[0] = 4.0; b[1] = 5.0; b[2] = 6.0; b[3] = 7.0;

        printf("Upper triagular augmented matrix A =\n");

        printAugMatrix(A, b, m, n);

        generalGauss(A, b, m, n);

        printf("Gauss Elimination on augmented matrix A=\n");

        printAugMatrix(A, b, m, n);

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

    Upper triagular augmented matrix A =
    1.000e+00       -1.000e+00      3.000e+00       1.000e+00       1.000e+00       |4.000e+00
    3.000e+00       1.000e+00       7.000e+00       1.000e+00       5.000e+00       |5.000e+00
    -4.000e+00      4.000e+00       1.000e+00       -2.000e+00      2.000e+00       |6.000e+00
    2.000e+00       1.000e+00       2.000e+00       1.000e+00       3.000e+00       |7.000e+00

    Gauss Elimination on augmented matrix A=
    1.000e+00       -1.000e+00      3.000e+00       1.000e+00       1.000e+00       |4.000e+00
    0.000e+00       4.000e+00       -2.000e+00      -2.000e+00      2.000e+00       |-7.000e+00
    0.000e+00       0.000e+00       1.300e+01       2.000e+00       6.000e+00       |2.200e+01
    0.000e+00       0.000e+00       0.000e+00       8.846e-01       6.538e-01       |8.481e+00

The output from the example code prints the matrix A and vector b as though they are augmented even though they remain separate. The output shows the original values of A and b. The Gauss Elimination process is then executed and the output prints the modified values of A and b.

**Implementation/Code:** The following is the code for generalGauss()

    void generalGauss(double **A, double *b, int m, int n) {
        int i, j, k = 0;
        double factor = 0.0;
        for (k = 0; k < (n - 1); k++) {
            for (i = (k + 1); i < m; i++) {
                factor = A[i][k] / A[k][k];
                A[i][k] = 0.0;
                for (j = (k + 1); j < n; j++) {
                    A[i][j] = A[i][j] - (factor * A[k][j]);
                }
                b[i] = b[i] - (factor * b[k]);
            }
        }
    }

**Last Modified:** November/2018
