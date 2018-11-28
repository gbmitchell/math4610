# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           KroneckerMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixKronecker.c

will produce an executable **matrixKronecker.exe** that can be executed.

**Description/Purpose:** This function will take two matrices and produce the Kronecker product of thoes matrices.

**Input:** There are seven inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are ma, na, mb, and nb to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represents the Kronecker product of matrix A and B.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the Kronecker product of matrix A and B. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are seven inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are ma, na, mb and nb to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represents the Kronecker product of matrix A and B. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the Kronecker product of matrix A and B. The resulting matrix C can then be used in the main program as needed.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j, k = 0;
        int ma = 3; // row matrix A
        int na = 3; // col matrix A
        int mb = 3; // row matrix b
        int nb = 3; // col matrix b
        int mc = ma * mb; // row matrix c
        int nc = na * nb; // col matrix c

        // alloc memory for a matrix
        double **A;
        A = calloc(ma, sizeof(double*));

        for (i = 0; i < ma; i++)
        {
            A[i] = calloc(na, sizeof(double));
        }

        // alloc memory for a matrix
        double **B;
        B = calloc(mb, sizeof(double*));

        for (i = 0; i < mb; i++)
        {
            B[i] = calloc(nb, sizeof(double));
        }

        // alloc memory for a matrix
        double **C;
        C = calloc(mc, sizeof(double*));

        for (i = 0; i < mc; i++)
        {
            C[i] = calloc(nc, sizeof(double));
        }

        // assign even values to matrix A
        k = 1;
        for (i = 0; i < ma; i++) {
            for (j = 0; j < na; j++) {
                A[i][j] = k * 2;
                k++;
            }
        }

        // assign odd values to matrix B
        k = 1;
        for (i = 0; i < mb; i++) {
            for (j = 0; j < nb; j++) {
                B[i][j] = (k * 2) - 1;
                k++;
            }
        }

        printf("\n\nMatrix A =\n");

        printMatrix(A, ma, na);

        printf("\n\nMatrix B =\n");

        printMatrix(B, mb, nb);

        KroneckerMatrix(A, B, C, ma, na, mb, nb);

        printf("\n\nMatrix C = A * B\n");

        printMatrix(C, mc, nc);

        // free memory
        for (i = 0; i < ma; i++)
        {
            free(A[i]);
        }

        free(A);

        // free memory
        for (i = 0; i < mb; i++)
        {
            free(B[i]);
        }

        free(B);

        // free memory
        for (i = 0; i < mc; i++)
        {
            free(C[i]);
        }

        free(C);

        return 0;
    }    

Output from the lines above:

    Matrix A =
    2.000e+00       4.000e+00       6.000e+00
    8.000e+00       1.000e+01       1.200e+01
    1.400e+01       1.600e+01       1.800e+01

    Matrix B =
    1.000e+00       3.000e+00       5.000e+00
    7.000e+00       9.000e+00       1.100e+01
    1.300e+01       1.500e+01       1.700e+01

    Matrix C = A * B
    2.000e+00       6.000e+00       1.000e+01       4.000e+00       1.200e+01       2.000e+01       6.000e+00       1.800e+01       3.000e+01
    1.400e+01       1.800e+01       2.200e+01       2.800e+01       3.600e+01       4.400e+01       4.200e+01       5.400e+01       6.600e+01
    2.600e+01       3.000e+01       3.400e+01       5.200e+01       6.000e+01       6.800e+01       7.800e+01       9.000e+01       1.020e+02
    8.000e+00       2.400e+01       4.000e+01       1.000e+01       3.000e+01       5.000e+01       1.200e+01       3.600e+01       6.000e+01
    5.600e+01       7.200e+01       8.800e+01       7.000e+01       9.000e+01       1.100e+02       8.400e+01       1.080e+02       1.320e+02
    1.040e+02       1.200e+02       1.360e+02       1.300e+02       1.500e+02       1.700e+02       1.560e+02       1.800e+02       2.040e+02
    1.400e+01       4.200e+01       7.000e+01       1.600e+01       4.800e+01       8.000e+01       1.800e+01       5.400e+01       9.000e+01
    9.800e+01       1.260e+02       1.540e+02       1.120e+02       1.440e+02       1.760e+02       1.260e+02       1.620e+02       1.980e+02
    1.820e+02       2.100e+02       2.380e+02       2.080e+02       2.400e+02       2.720e+02       2.340e+02       2.700e+02       3.060e+02

The output shows the values for matrix A and B. Additionally, the output shows the matrix C which is the Kronecker product of matrix A and matrix B.

**Implementation/Code:** The following is the code for KroneckerMatrix()

    void KroneckerMatrix(double **A, double **B, double **C, int ma, int na, int mb, int nb) {
        int i, j, k, l = 0;
        int Row = 0;
        int Col = 0;

        for (i = 0; i < ma; i++) {
            for (j = 0; j < na; j++) {
                Row = i * mb;
                Col = j * nb;
                for (k = 0; k < na; k++) {
                    for (l = 0; l < nb; l++) {
                        C[Row + k][Col + l] = A[i][j] * B[k][l];
                    }
                }
            }
        }
    }

**Last Modified:** November/2018
