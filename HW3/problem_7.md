# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 5f.

**Routine Name:**           vectorXmatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will take a matrix and multiply it by a vector in double precision. In this case, the matrix is a 3x3 and the vector is a 3x1 and the result is a 3x1 vector.

**Input:** There are five inputs needed in this case. Matrix A, vector u, and vector v are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrix and vectors. The real purpose is to produce values in the vector u that represent the result of multiplying the matrix A by the vector v.

**Output:** This function doesnt return a value. Because the vector u was passed by reference, the function can modify the vector u to produce the result of multiplying the matrix A by the vector v. The resulting vector u can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, vector u, and vector v are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrix and vectors. The real purpose is to produce values in the vector u that represent the result of multiplying the matrix A by the vector v. This function doesnt return a value. Because the vector u was passed by reference, the function can modify the vector u to produce the result of multiplying the matrix A by the vector v. The resulting vector u can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double scaler = 5.0;
        double v[3] = { 1, 2, 3 };
	    double u[3] = { 0 };
        double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
    
        printf("\n\nMatrix A =\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", A[i][j]);
            }
            printf("\n");
        }
        
        printf("\n\nVector v =\n");

        for (i = 0; i < m; i++) {
            printf("%.3lf\n", v[i]);
        }
        
        vectorXmatrix(A, v, u, m, n);
    
        printf("\n\nVector u = A * v\n");
    
        for (i = 0; i < m; i++) {
            printf("%.3lf\n", u[i]);
        }    
    }    

Output from the lines above:

    Matrix A =
    2.000   4.000   6.000
    8.000   10.000  12.000
    14.000  16.000  18.000
    
    Vector v =
    1.000
    2.000
    3.000
    
    Vector u = A * v
    28.000
    64.000
    100.000

The output shows the values for matrix A, the values for vector v, and the values for vector u as a result of multiplying A * v.

**Implementation/Code:** The following is the code for vectorXmatrix()

    void vectorXmatrix(double A[3][3], double v[3], double u[3], int m, int n) {
        int i, j = 0;
        for (i = 0; i < m; i++) {
            u[i] = 0;
            for (j = 0; j < n; j++) {
                u[i] = u[i] + (A[i][j] * v[j]);
            }
        }
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 5g.

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
