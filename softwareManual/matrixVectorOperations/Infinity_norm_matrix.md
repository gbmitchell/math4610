# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           matrixNormInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the Infinity-norm given a matrix. The function was developed to compute the Infinity-norm of a 3x3 matrix. The Infinity-norm is used to give some sense of a magnitude for the given matrix. The Infinity-norm for a matrix is computed by summing each row in the matrix and then indentifying which sum is maximum.

**Input:** There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function.

**Output:** The function returns a double precision value max which represents the Infinity-norm of the input matrix.

**Usage/Example:**

There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function. The function returns a double precision value max which represents the Infinity-norm of the input matrix A.

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
    
        norm = matrixNormInfinity(A, n);
        printf("\n\nInfinity norm of A = \n");
        printf("%.3lf\n", norm);
    }

Output from the lines above:

    Matrix A =
    2.000   4.000   6.000
    8.000   10.000  12.000
    14.000  16.000  18.000
    
    Infinity norm of A =
    48.000

The sum of row 1 is 2 + 4 + 6 = 12, the sum of row 2 is 8 + 10 + 12 = 30, and the sum of row 3 is 14 + 16 + 18 = 48.
The max of these sums is 48, therefore the Infinity-norm is 48.

**Implementation/Code:** The following is the code for matrixNormInfinity()

    double matrixNormInfinity(double a[3][3], int len) {
        int i, j = 0;
        double ia = 0.0;
        double max = 0.0;
        for (i = 0; i < len; i++) {
            ia = 0.0;
            for (j = 0; j < len; j++) {
                ia = ia + fabs(a[i][j]);
            }
            if (max < ia) {
                max = ia;
            }
        }

        return max;
    }

**Last Modified:** October/2018
