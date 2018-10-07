# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 4a.

**Routine Name:**           matrixNormFrobenious

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the L1-norm given a vector. The function was developed to compute the L1-norm of a vector with three elements or vector length of three. The L1-norm is used to give some sence of a magnitude for the given vector. The L1-norm for a vector is computed by summing the absolute value of each element of the vector.

**Input:** There are two inputs needed in this case. The vector (u) of length three is passed to the function by reference. An argument for the length (len) of the vector is also passed to the function.

**Output:** This function returns a double precision value (ia) which represents the L1-norm of the input vector.

**Usage/Example:**

The function has two arguments needed to compute and return the value for L1-norm of the vector. The vector u of length three contains the double precision values 1.0, 2.0, and 3.0. A parameter len represents the lenght of the input vector. The function is then called with these input parameters and returns a double precision value which represents the L1-norm for the vector u. 

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

The sum of the absolute values in the vector u are 1 + 2 + 3 = 6.

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

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 4b.

**Routine Name:**           matrixNormL1

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the L2-norm given a vector. The function was developed to compute the L2-norm of a vector with three elements or vector length of three. The L2-norm is used to give some sence of a magnitude for the given vector. The L2-norm for a vector is computed by summing the squre of each element of the vector and then take the square root of the sum.

**Input:** There are two inputs needed in this case. The vector (u) of length three is passed to the function by reference. An argument for the length (len) of the vector is also passed to the function.

**Output:** This function returns a double precision value (ia) which represents the L2-norm of the input vector.

**Usage/Example:**

The function has two arguments needed to compute and return the value for L2-norm of the vector. The vector u of length three contains the double precision values 1.0, 2.0, and 3.0. A parameter len represents the lenght of the input vector. The function is then called with these input parameters and returns a double precision value which represents the L2-norm for the vector u. 

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

The sum of the squared values in the vector u are (1 * 1) + (2 * 2) + (3 * 3) = 14, then the L2-norm = sqrt(14) = 3.742.

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

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 4c.

**Routine Name:**           matrixNormInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the Infinity-norm given a vector. The function was developed to compute the Infinity-norm of a vector with three elements or vector length of three. The Infinity-norm is used to give some sence of a magnitude for the given vector. The Infinity-norm for a vector is computed by identifying which element of the vector is the  maximum.

**Input:** There are two inputs needed in this case. The vector (u) of length three is passed to the function by reference. An argument for the length (len) of the vector is also passed to the function.

**Output:** This function returns a double precision value (ia) which represents the Infinity-norm of the input vector.

**Usage/Example:**

The function has two arguments needed to compute and return the value for Infinity-norm of the vector. The vector u of length three contains the double precision values 1.0, 2.0, and 3.0. A parameter len represents the lenght of the input vector. The function is then called with these input parameters and returns a double precision value which represents the Infinity-norm for the vector u. 

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

The maximum value out of the vector elements 1.0, 2.0, and 3.0 is 3.0, therefore the Infinity-norm of the vector u is 3.0.

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
