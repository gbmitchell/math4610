# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           transposeMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will transpose a square matrix, in this case 3x3. 

**Input:** There are four inputs needed in this case. Matrix A and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of transposing matrix A.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of transposing matrix A. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Matrix A and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of transposing matrix A. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of transposing matrix A. The resulting matrix C can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
        double C[3][3] = { 0 };
    
        printf("\n\nMatrix A =\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", A[i][j]);
            }
            printf("\n");
        }
    
        transposeMatrix(A, C, m, n);
    
        printf("\n\nMatrix C = Transpose of A\n");
    
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
    
    Matrix C = Transpose of A
    2.000   8.000   14.000
    4.000   10.000  16.000
    6.000   12.000  18.000

The output shows the matrix C as a result of transposing matrix A.

**Implementation/Code:** The following is the code for transposeMatrix()

    void transposeMatrix(double A[3][3], double C[3][3], int m, int n) {
        int i, j = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = A[j][i];
            }
        }
    }

**Last Modified:** October/2018
