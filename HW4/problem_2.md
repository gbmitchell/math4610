# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 2.

**Routine Name:**           generalGauss

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will compute the necassary factors and carry out row operations for Gauss Elimination of a general matrix mxn up to size 50x50. No pivoting methods are used in this routine.

**Input:** There are four inputs needed in this case. A general matrix of size mxn and a vector of size n are arguments passed by reference and the routine will change their values according to the process for Gauss Elimination. The variables m and n are also passed to the routine to indicate the size of the matrix and vector. The vector and matrix are treated as though they are combined to form an augmented matrix even though they remain separate.

**Output:** This routine does not return anything, instead it changes the original matrix and vector values as though they were an augmented matrix going through the Gauss Elimination process.

**Usage/Example:**

There are four inputs needed in this case. A general matrix (C) of size mxn (4x5) and a vector (bc) of size m (4) are arguments passed by reference and the routine will change their values according to the process for Gauss Elimination. The variables m (4) and n (5) are also passed to the routine to indicate the size of the matrix and vector. The vector and matrix are treated as though they are combined to form an augmented matrix even though they remain separate. This routine does not return anything, instead it changes the original matrix and vector values as though they were an augmented matrix going through the Gauss Elimination process. 

    #include "mylib.h"
    #include <stdio.h>

    int main() {
        int i, j = 0;
        int n = 0;
        int m = 0;

        // 4x5
        double C[50][50] = { {1.0, -1.0, 3.0, 1.0, 1.0}, {3.0, 1.0, 7.0, 1.0, 5.0}, {-4.0, 4.0, 1.0, -2.0, 2.0}, {2.0, 1.0, 2.0, 1.0, 3.0} };

        double bc[50] = { 4.0, 5.0, 6.0, 7.0 };

        printf("Augmented matrix C =\n");
        m = 4;
        n = 5;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", C[i][j]);
            }
            printf("|%.3e\n", bc[i]);
        }

        generalGauss(C, bc, m, n);

        printf("\n\n\n");

        printf("Gaussian elimination on augmented matrix C =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", C[i][j]);
            }
            printf("|%.3e\n", bc[i]);
        }
        
        return 0;
    }

Output from the lines above:

    Augmented matrix C =
    1.000e+00       -1.000e+00      3.000e+00       1.000e+00       1.000e+00       |4.000e+00
    3.000e+00       1.000e+00       7.000e+00       1.000e+00       5.000e+00       |5.000e+00
    -4.000e+00      4.000e+00       1.000e+00       -2.000e+00      2.000e+00       |6.000e+00
    2.000e+00       1.000e+00       2.000e+00       1.000e+00       3.000e+00       |7.000e+00



    Gaussian elimination on augmented matrix C =
    1.000e+00       -1.000e+00      3.000e+00       1.000e+00       1.000e+00       |4.000e+00
    0.000e+00       4.000e+00       -2.000e+00      -2.000e+00      2.000e+00       |-7.000e+00
    0.000e+00       0.000e+00       1.300e+01       2.000e+00       6.000e+00       |2.200e+01
    0.000e+00       0.000e+00       0.000e+00       8.846e-01       6.538e-01       |8.481e+00

The output from the example code prints the matrix C and vector bc as though they are augmented even though they remain separate. The output shows the original values of C and bc. The Gauss Elimination process is then executed and the output prints the modified values of C and bC.

**Implementation/Code:** The following is the code for generalGauss()

    void generalGauss(double A[50][50], double b[50], int m, int n) {
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
