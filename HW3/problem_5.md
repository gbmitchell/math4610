# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 5a.

**Routine Name:**           matrixAdd

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will add two square matrices of the same size, in this case 3x3. The computation is done in double precision. 

**Input:** There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of adding the matrices A + B.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of adding the matrices A + B. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of adding the matrices A + B. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of adding the matrices A + B. The resulting matrix C can then be used in the main program as needed.

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
    
        matrixAdd(A, B, C, m, n);
    
        printf("\n\nMatrix C = A + B\n");
    
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
    
    Matrix C = A + B
    3.000   7.000   11.000
    15.000  19.000  23.000
    27.000  31.000  35.000

The output shows the matix C as a result of adding matrix A and B.

**Implementation/Code:** The following is the code for matrixAdd()

    void matrixAdd(double A[3][3], double B[3][3], double C[3][3], int m, int n) {
        int i, j = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 5b.

**Routine Name:**           matrixSub

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will subtract two square matrices of the same size, in this case 3x3. The computation is done in double precision. 

**Input:** There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of subtracting the matrices A - B.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of subtracting the matrices A - B. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of subtracting the matrices A - B. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matirx C to produce the result of subtracting the matrices A - B. The resulting matrix C can then be used in the main program as needed.

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
    
        matrixSub(A, B, C, m, n);

        printf("\n\nMatrix C = A - B\n");

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
    
    Matrix C = A - B
    1.000   1.000   1.000
    1.000   1.000   1.000
    1.000   1.000   1.000

The output shows the matix C as a result of subtracting matrix B from A.

**Implementation/Code:** The following is the code for matrixSub()

    void matrixSub(double A[3][3], double B[3][3], double C[3][3], int m, int n) {
        int i, j = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 5c.

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

The output shows the matix C as a result of transposing matrix A.

**Implementation/Code:** The following is the code for transposeMatrix()

    void transposeMatrix(double A[3][3], double C[3][3], int m, int n) {
        int i, j = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = A[j][i];
            }
        }
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 5d.

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

The output shows the matix C has a trace of 30.

**Implementation/Code:** The following is the code for traceMatrix()

    double traceMatrix(double A[3][3],  int m) {
        double trace = 0.0;
        int i = 0;
        for (i = 0; i < m; i++) {
            trace = trace + A[i][i];
        }
        return trace;
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 5e.

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

The output shows the matix C as a result of scaling matrix A by a scale of 5.

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
