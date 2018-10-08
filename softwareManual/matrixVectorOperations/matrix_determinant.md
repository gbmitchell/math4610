# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           determinantMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will compute the determinant of  a 3x3 matrix in double precision.

**Input:** There are two inputs needed in this case. Matrix A is an argument passed by reference. Another argument m is also passed to the function to indicate the size of the matrix.

**Output:** This function returns a double precision value determinant which represents the determinant of the matrix A.

**Usage/Example:**

There are two inputs needed in this case. Matrix A is an argument passed by reference. Another argument m is also passed to the function to indicate the size of the matrix. This function returns a double precision value determinant which represents the determinant of the matrix A.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double det = 0.0;
        double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
    
        printf("\n\nMatrix A =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", A[i][j]);
            }
            printf("\n");
        }
        
        det = determinantMatrix(A, m);
        printf("\n\nDeterminant of A = \n");
        printf("%.3lf\n", det);
    }    

Output from the lines above:

    Matrix A =
    2.000   4.000   6.000
    8.000   10.000  12.000
    14.000  16.000  18.000

    Determinant of A =
    0.000

The output shows the values for matrix A and the computed determinant for the matrix which is 0.

**Implementation/Code:** The following is the code for determinantMatrix()

    double determinantMatrix(double A[3][3], int m) {
        double determinant = (A[0][0]*((A[1][1]*A[2][2])-(A[1][2] * A[2][1])))-(A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0])))+(A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0])));
        return determinant;
    }

**Last Modified:** October/2018
