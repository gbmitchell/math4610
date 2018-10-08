# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           scaleMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will scale a square matrix by a double precision scale value, in this case a 3x3 matrix is scaled by a value of 5.0. 

**Input:** There are five inputs needed in this case. Matrix A and C are arguments passed by reference. Arguments also passed to the function are scaler, a scale value, as well as m and n to indicate the size of the matrix. The real purpose is to produce values in the matrix C that represent the result of scaling the matrix A.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of scaling the matrix A. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A and C are arguments passed by reference. Arguments also passed to the function are scaler, a scale value, as well as m and n to indicate the size of the matrix. The real purpose is to produce values in the matrix C that represent the result of scaling the matrix A. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of scaling the matrix A. The resulting matrix C can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double scaler = 5.0;
        double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
        double C[3][3] = { 0 };
    
        printf("\n\nMatrix A =\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", A[i][j]);
            }
            printf("\n");
        }
    
        scaleMatrix(A, C, scaler, m, n);

        printf("\n\nMatrix C = scaler * A\n");

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
    
    Matrix C = scaler * A
    10.000  20.000  30.000
    40.000  50.000  60.000
    70.000  80.000  90.000

The output shows the matrix C as a result of scaling matrix A by a scale of 5.

**Implementation/Code:** The following is the code for scaleMatrix()

    void scaleMatrix(double A[3][3], double C[3][3], double s, int m, int n) {
        int i, j = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = s * A[i][j];
            }
        }
    }

**Last Modified:** October/2018
