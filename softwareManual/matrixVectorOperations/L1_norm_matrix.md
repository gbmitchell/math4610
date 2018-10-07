# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           matrixNormL1

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the L1-norm given a matrix. The function was developed to compute the L1-norm of a 3x3 matrix. The L1-norm is used to give some sense of a magnitude for the given matrix. The L1-norm for a matrix is computed by summing each column in the matrix and then indentifying which sum is maximum.

**Input:** There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function.

**Output:** The function returns a double precision value max which represents the L1-norm of the input matrix.

**Usage/Example:**

There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function. The function returns a double precision value max which represents the L1-norm of the input matrix A. 

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
    
        norm = matrixNormL1(A, n);
        printf("\n\nL1 norm of A = \n");
        printf("%.3lf\n", norm);
    }

Output from the lines above:

    Matrix A =
    2.000   4.000   6.000
    8.000   10.000  12.000
    14.000  16.000  18.000
    
    L1 norm of A =
    36.000

The sum of column 1 is 2 + 8 + 14 = 24, the sum of column 2 is 4 + 10 + 16 = 30, and the sum of column 3 is 6 + 12 + 18 = 36.
The max of these sums is 36, therefore the L1-norm is 36.

**Implementation/Code:** The following is the code for matrixNormL1()

    double matrixNormL1(double a[3][3], int len) {
        int i, j = 0;
        double ia = 0.0;
        double max = 0.0;
        for (j = 0; j < len; j++) {
            ia = 0.0;
            for (i = 0; i < len; i++) {
                ia = ia + fabs(a[i][j]);
            }
            if (max < ia) {
                max = ia;
            }
        }

        return max;
    }

**Last Modified:** October/2018
