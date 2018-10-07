# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           matrixNormFrobenious

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the Frobenious-norm given a matrix. The function was developed to compute the Frobenious-norm of a 3x3 matrix. The Frobenious-norm is used to give some sense of a magnitude for the given matrix. The Frobenious-norm for a matrix is computed by summing the square of each value in the matrix and then taking the square root of the sum.

**Input:** There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function.

**Output:** The function returns a double precision value ia which represents the Frobenious-norm of the input matrix.

**Usage/Example:**

There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function. The function returns a double precision value ia which represents the Frobenious-norm of the input matrix A.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double norm = 0.0;
        double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
    
        printf("\n\nMatrix A =\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", A[i][j]);
            }
            printf("\n");
        }
    
        norm = matrixNormFrobenious(A, n);
        printf("\n\nFrobenious norm of A = \n");
        printf("%.3lf\n", norm);
    }

Output from the lines above:

    Matrix A =
    2.000   4.000   6.000
    8.000   10.000  12.000
    14.000  16.000  18.000
    
    Frobenious norm of A =
    33.764

The sum of the squared values in the matrix A are,
(2 * 2) + (4 * 4) + (6 * 6) + (8 * 8) + (10 * 10) + (12 * 12) + (14 * 14) + (16 * 16) + (18 * 18) = 1140.
Then the Frobenious-norm is the sqrt(1140) = 33.764.

**Implementation/Code:** The following is the code for matrixNormFrobenious()

    double matrixNormFrobenious(double a[3][3], int len) {
        int i, j = 0;
        double ia = 0.0;
        for (i = 0; i < len; i++) {
            for (j = 0; j < len; j++) {
                ia = ia + (a[i][j] * a[i][j]);
            }
        }
        ia = sqrt(ia);
        return ia;
    }

**Last Modified:** October/2018
