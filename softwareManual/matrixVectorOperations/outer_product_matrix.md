# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           outerProductMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will take a 3x1 matrix and multiply it by a 1x3 matrix in double precision. The result is a 3x3 matrix and this is known as the outer product.

**Input:** There are five inputs needed in this case. Matrix x, y, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix x by matrix y transpose.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix x by matrix y transpose. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix x, y, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix x by matrix y transpose. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix x by matrix y transpose. The resulting matrix C can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double C[3][3] = { 0 };
        double x[3] = { 4, 5, 6 };
        double y[3] = { 7, 8, 9 };
        
        printf("\n\nVector x =\n");
    
        for (i = 0; i < m; i++) {
            printf("%.3lf\n", x[i]);
        }
    
        printf("\n\nVector y =\n");
    
        for (i = 0; i < m; i++) {
            printf("%.3lf\n", y[i]);
        }
    
        outerProductMatrix(x, y, C, m, n);
    
        printf("\n\nMatrix C = outer product of x and y\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", C[i][j]);
            }
            printf("\n");
        }    
    }    

Output from the lines above:

    Vector x =
    4.000
    5.000
    6.000
    
    Vector y =
    7.000
    8.000
    9.000
    
    Matrix C = outer product of x and y
    28.000  32.000  36.000
    35.000  40.000  45.000
    42.000  48.000  54.000

The output shows the values for matrix x and y. Additionally, the output shows the matrix C which is the result of multiplying matrix x by matrix y transpose. The result is called the outer product.

**Implementation/Code:** The following is the code for outerProductMatrix()

    void outerProductMatrix(double x[3], double y[3], double C[3][3], int m, int n) {
        int i, j = 0;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = x[i] * y[j];
            }
        }
    }

**Last Modified:** October/2018
