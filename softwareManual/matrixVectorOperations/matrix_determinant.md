# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           determinantMatrixNxN

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixDeterminant.c

will produce an executable **matrixDeterminant.exe** that can be executed.

**Description/Purpose:** This function will compute the determinant of a square matrix in double precision. The routine involves three diferent cases. A 1x1 matrix, a 2x2 matrix, and any matrix greater than 2x2.

**Input:** There are two inputs needed in this case. Matrix A is an argument passed by reference. Another argument n is also passed to the function to indicate the size of the matrix.

**Output:** This function returns a double precision value determinant which represents the determinant of the matrix A.

**Usage/Example:**

There are two inputs needed in this case. Matrix A is an argument passed by reference. Another argument m is also passed to the function to indicate the size of the matrix. This function returns a double precision value determinant which represents the determinant of the matrix A. The matrix A starts as a 1x1 and the determinant is computed. Then matrix A is changed to a 2x2 and the determinant is computed. Finally, matrix A is changed to a 5x5 and the determinant is computed. This was done to test each case of the determinant routine.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j, k = 0;
        double determinant = 0.0;

        int m = 1; // rows
        int n = 1; // col

        // alloc memory for a matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        A[0][0] = 5.0;

        printf("\n\nMatrix A =\n");

        printMatrix(A, m, n);

        determinant = determinantMatrixNxN(A, n);

        printf("\n\nDeterminant of A = %.3e\n", determinant);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);

        m = 2; // rows
        n = 2; // col

        // alloc memory for a matrix
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        A[0][0] = 3.0; A[0][1] = 8.0; 
        A[1][0] = 4.0; A[1][1] = 6.0; 

        printf("\n\nMatrix A =\n");

        printMatrix(A, m, n);

        determinant = determinantMatrixNxN(A, n);

        printf("\n\nDeterminant of A = %.3e\n", determinant);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);

        m = 5; // rows
        n = 5; // col

        // alloc memory for a matrix
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        A[0][0] = 0.0; A[0][1] = 6.0; A[0][2] = -2.0; A[0][3] = -1.0; A[0][4] = 5.0;
        A[1][0] = 0.0; A[1][1] = 0.0; A[1][2] = 0.0; A[1][3] = -9.0; A[1][4] = -7.0;
        A[2][0] = 0.0; A[2][1] = 15.0; A[2][2] = 35.0; A[2][3] = 0.0; A[2][4] = 0.0;
        A[3][0] = 0.0; A[3][1] = -1.0; A[3][2] = -11.0; A[3][3] = -2.0; A[3][4] = 1.0;
        A[4][0] = -2.0; A[4][1] = -2.0; A[4][2] = 3.0; A[4][3] = .0; A[4][4] = .0;

        printf("\n\nMatrix A =\n");

        printMatrix(A, m, n);

        determinant = determinantMatrixNxN(A, n);

        printf("\n\nDeterminant of A = %.3e\n", determinant);

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
    5.000e+00

    Determinant of A = 5.000e+00


    Matrix A =
    3.000e+00       8.000e+00
    4.000e+00       6.000e+00

    Determinant of A = -1.400e+01


    Matrix A =
    0.000e+00       6.000e+00       -2.000e+00      -1.000e+00      5.000e+00
    0.000e+00       0.000e+00       0.000e+00       -9.000e+00      -7.000e+00
    0.000e+00       1.500e+01       3.500e+01       0.000e+00       0.000e+00
    0.000e+00       -1.000e+00      -1.100e+01      -2.000e+00      1.000e+00
    -2.000e+00      -2.000e+00      3.000e+00       0.000e+00       0.000e+00

    Determinant of A = 2.480e+03

The output shows the values for matrix A which changed from 1x1 to 2x2 to 5x5 and their respective determinants. The sizes were used to test the three different cases of the determinant routine.

**Implementation/Code:** The following is the code for determinantMatrixNxN()

    double determinantMatrixNxN(double **A, int n) {
        int h, i, j, k, l = 0;
        double det = 0;

        if (n == 1) {
            return A[0][0];
        }
        else if (n == 2) {
            det = (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
            return det;
        }
        else {
            for (l = 0; l < n; l++) {
                // alloc memory for a matrix
                double **T;
                T = calloc(n, sizeof(double*));

                for (i = 0; i < n; i++)
                {
                    T[i] = calloc(n, sizeof(double));
                }

                h = 0;
                k = 0;
                for (i = 1; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        if (j == l) {
                            continue;
                        }
                        T[h][k] = A[i][j];
                        k++;
                        if (k == (n - 1)) {
                            h++;
                            k = 0;
                        }
                    }
                }
                det = det + A[0][l] * pow(-1, l) * determinantMatrixNxN(T, (n - 1));

                // free memory
                for (i = 0; i < n; i++)
                {
                    free(T[i]);
                }

                free(T);
            }

            return det;
        }
    }

**Last Modified:** November/2018
