# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           traceMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will compute the trace of a square matrix, in this case 3x3.

**Input:** There are two inputs needed in this case. Matrix A is an argument passed by reference. Another arguments also passed to the function is m indicate the size of the square matrix.

**Output:** This function returns a double precision value trace which represents the computed value for the trace of the matrix.

**Usage/Example:**

There are two inputs needed in this case. Matrix A is an argument passed by reference. Another arguments also passed to the function is m indicate the size of the square matrix. This function returns a double precision value trace which represents the computed value for the trace of the matrix.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double tr = 0.0;
        double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
    
        printf("\n\nMatrix A =\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", A[i][j]);
            }
            printf("\n");
        }
    
        tr = traceMatrix(A, m);
        printf("\n\nTrace of A = \n");
        printf("%.3lf\n", tr);
    }    

Output from the lines above:

    Matrix A =
    2.000   4.000   6.000
    8.000   10.000  12.000
    14.000  16.000  18.000
    
    Trace of A =
    30.000

The output shows the matrix C has a trace of 30.

**Implementation/Code:** The following is the code for traceMatrix()

    double traceMatrix(double A[3][3],  int m) {
        double trace = 0.0;
        int i = 0;
        for (i = 0; i < m; i++) {
            trace = trace + A[i][i];
        }
        return trace;
    }

**Last Modified:** October/2018
