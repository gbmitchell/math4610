# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           squareGauss

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will compute the necassary factors and carry out row operations for Gauss Elimination of a square matrix up to size. No pivoting methods are used in this routine.

**Input:** There are three inputs needed in this case. A square matrix of size nxn and a vector of size n are arguments passed by reference and the routine will change their values according to the process for Gauss Elimination. The variable n is also passed to the routine to indicate the size of the matrix and vector. The vector and matrix are treated as though they are combined to form an augmented matrix even though they remain separate.

**Output:** This routine does not return anything, instead it changes the original matrix and vector values as though they were an augmented matrix going through the Gauss Elimination process.

**Usage/Example:**

There are three inputs needed in this case. A square matrix (A) of size nxn (3x3) and a vector (b) of size n (3) are arguments passed by reference and the routine will change their values according to the process for Gauss Elimination. The variable n (3) is also passed to the routine to indicate the size of the matrix and vector. The vector and matrix are treated as though they are combined to form an augmented matrix even though they remain separate. This routine does not return anything, instead it changes the original matrix and vector values as though they were an augmented matrix going through the Gauss Elimination process. 

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j = 0;
        int m = 3;
        int n = 3;

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

        A[0][0] = 1.0;  A[0][1] = -2.0; A[0][2] = -6.0;
        A[1][0] = 2.0;  A[1][1] = 4.0; A[1][2] = 12.0;
        A[2][0] = 1.0; A[2][1] = -3.0; A[2][2] = -12.0;

        b[0] = 5.0; b[1] = 0.0; b[2] = -2.0;

        printf("Upper triagular augmented matrix A =\n");

        printAugMatrix(A, b, m, n);

        squareGauss(A, b, n);

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
    1.000e+00       -2.000e+00      -6.000e+00      |5.000e+00
    2.000e+00       4.000e+00       1.200e+01       |0.000e+00
    1.000e+00       -3.000e+00      -1.200e+01      |-2.000e+00

    Gauss Elimination on augmented matrix A=
    1.000e+00       -2.000e+00      -6.000e+00      |5.000e+00
    0.000e+00       8.000e+00       2.400e+01       |-1.000e+01
    0.000e+00       0.000e+00       -3.000e+00      |-8.250e+00

The output from the example code prints the matrix A and vector b as though they are augmented even though they remain separate. The output shows the original values of A and b. The Gauss Elimination process is then executed and the output prints the modified values of A and b. Gauss Elimination results in an upper triangular matrix that can be used to solve for a solution to x in the problem of Ax=b.

**Implementation/Code:** The following is the code for squareGauss()

    void squareGauss(double **A, double *b, int n) {
        int i, j, k = 0;
        double factor = 0.0;
        for (k = 0; k < (n - 1); k++) {
            for (i = (k + 1); i < n; i++) {
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
