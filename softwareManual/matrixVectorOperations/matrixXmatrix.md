# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           matrixXmatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will take a matrix and multiply it by another matrix in double precision. In this case, the matrices are 3x3.

**Input:** There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix A by matrix B.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix A by matrix B. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix A by matrix B. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix A by matrix B. The resulting matrix C can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
        double B[3][3] = { { 1, 3, 5 },{ 7, 9, 11 },{ 13, 15, 17 } };
        double C[3][3] = { 0 };
    
        printf("\n\nMatrix A =\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", A[i][j]);
            }
            printf("\n");
        }
    
        printf("\n\nMatrix B =\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", B[i][j]);
            }
            printf("\n");
        }
        
        matrixXmatrix(A, B, C, m, n);
    
        printf("\n\nMatrix C = A * B\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", C[i][j]);
            }
            printf("\n");
        }    
    }    

Output from the lines above:

    Matrix A =
    2.000   4.000   6.000
    8.000   10.000  12.000
    14.000  16.000  18.000
    
    Matrix B =
    1.000   3.000   5.000
    7.000   9.000   11.000
    13.000  15.000  17.000

    Matrix C = A * B
    108.000 132.000 156.000
    234.000 294.000 354.000
    360.000 456.000 552.000

The output shows the values for matrix A and B. Additionally, the output shows the matrix C which is the result of multiplying matrix A by matrix B.

**Implementation/Code:** The following is the code for matrixXmatrix()

    void matrixXmatrix(double A[3][3], double B[3][3], double C[3][3], int m, int n) {
        int i, j, k = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = 0;
                for (k = 0; k < m; k++) {
                    C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
                }
            }
        }
    }

**Last Modified:** October/2018
