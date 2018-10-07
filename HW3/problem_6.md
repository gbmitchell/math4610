# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 6a.

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

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 6b.

**Routine Name:**           KroneckerMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will take two 3x3 matrices and produce the Kronecker product of thoes matrices.

**Input:** There are five inputs needed in this case. Matrix A, B, and K are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix K that represent the Kronecker product of matrix A and B.

**Output:** This function doesnt return a value. Because the matrix K was passed by reference, the function can modify the matrix K to produce the Kronecker product of matrix A and B. The resulting matrix K can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, B, and K are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix K that represent the Kronecker product of matrix A and B. This function doesnt return a value. Because the matrix K was passed by reference, the function can modify the matrix K to produce the Kronecker product of matrix A and B. The resulting matrix K can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
        double B[3][3] = { { 1, 3, 5 },{ 7, 9, 11 },{ 13, 15, 17 } };
        double K[9][9] = { 0 };
        
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
        
        KroneckerMatrix(A, B, K, m, n);
    
        printf("\n\nKronecker A * B =\n");
    
        for (i = 0; i < (m * m); i++) {
            for (j = 0; j < (n * n); j++) {
                printf("%.3lf\t", K[i][j]);
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
    
    Kronecker A * B =
    2.000   6.000   10.000  4.000   12.000  20.000  6.000   18.000  30.000
    14.000  18.000  22.000  28.000  36.000  44.000  42.000  54.000  66.000
    26.000  30.000  34.000  52.000  60.000  68.000  78.000  90.000  102.000
    8.000   24.000  40.000  10.000  30.000  50.000  12.000  36.000  60.000
    56.000  72.000  88.000  70.000  90.000  110.000 84.000  108.000 132.000
    104.000 120.000 136.000 130.000 150.000 170.000 156.000 180.000 204.000
    14.000  42.000  70.000  16.000  48.000  80.000  18.000  54.000  90.000
    98.000  126.000 154.000 112.000 144.000 176.000 126.000 162.000 198.000
    182.000 210.000 238.000 208.000 240.000 272.000 234.000 270.000 306.000

The output shows the values for matrix A and B. Additionally, the output shows the matrix K which is the Kronecker product of matrix A and matrix B.

**Implementation/Code:** The following is the code for KroneckerMatrix()

    void KroneckerMatrix(double A[3][3], double B[3][3], double K[9][9], int m, int n) {

        int i, j, k = 0;
        double R[3][3] = { 0 };
        double S[3][3] = { 0 };
        double T[3][3] = { 0 };
        double U[3][3] = { 0 };
        double V[3][3] = { 0 };
        double W[3][3] = { 0 };
        double X[3][3] = { 0 };
        double Y[3][3] = { 0 };
        double Z[3][3] = { 0 };
        double s = 0;

        s = A[0][0];
        scaleMatrix(B, R, s, m, n);

        s = A[0][1];
        scaleMatrix(B, S, s, m, n);

        s = A[0][2];
        scaleMatrix(B, T, s, m, n);

        s = A[1][0];
        scaleMatrix(B, U, s, m, n);

        s = A[1][1];
        scaleMatrix(B, V, s, m, n);

        s = A[1][2];
        scaleMatrix(B, W, s, m, n);

        s = A[2][0];
        scaleMatrix(B, X, s, m, n);

        s = A[2][1];
        scaleMatrix(B, Y, s, m, n);

        s = A[2][2];
        scaleMatrix(B, Z, s, m, n);


        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                K[i][j] = R[i][j];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                K[i][j+3] = S[i][j];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                K[i][j + 6] = T[i][j];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                K[i+3][j] = U[i][j];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                K[i+3][j + 3] = V[i][j];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                K[i+3][j + 6] = W[i][j];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                K[i+6][j] = X[i][j];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                K[i+6][j + 3] = Y[i][j];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                K[i+6][j + 6] = Z[i][j];
            }
        }

    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 6c.

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
