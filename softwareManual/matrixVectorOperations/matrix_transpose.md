# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           transposeMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixTranspose.c

will produce an executable **matrixTranspose.exe** that can be executed.

**Description/Purpose:** This function will transpose a square matrix, in this case 3x3. 

**Input:** There are four inputs needed in this case. Matrix A and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of transposing matrix A.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of transposing matrix A. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Matrix A and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of transposing matrix A. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of transposing matrix A. The resulting matrix C can then be used in the main program as needed.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int i, j, k = 0;

        int m = 3; // rows
        int n = 3; // col

        // alloc memory for a matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // alloc memory for a matrix
        double **C;
        C = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            C[i] = calloc(n, sizeof(double));
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

        transposeMatrix(A, C, m, n);

        printf("\n\nMatrix C = A transpose\n");

        printMatrix(C, m, n);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);

        // free memory
        for (i = 0; i < m; i++)
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

    Matrix C = A transpose
    2.000e+00       8.000e+00       1.400e+01
    4.000e+00       1.000e+01       1.600e+01
    6.000e+00       1.200e+01       1.800e+01

The output shows the matrix C as a result of transposing matrix A.

**Implementation/Code:** The following is the code for transposeMatrix()

    void transposeMatrix(double **A, double **C, int m, int n) {
        int i, j = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = A[j][i];
            }
        }
    }

**Last Modified:** November/2018
