# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorSub

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorMath.c

will produce an executable **vectorMath.exe** that can be executed.

**Description/Purpose:** This function will subtract two vectors of the same size and the computation is done in double precision. 

**Input:** There are four inputs needed in this case. Vectors u, v, and a are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. The real purpose is to produce values in the vector a that represent the result of v - u.

**Output:** This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of subtracting the vectors u and v. The resulting vector a can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Vectors u, v, and a are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of subtracting the vectors u and v. The resulting vector a can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int len = 0;
        double u[3] = { 1, 2, 3 };
        double v[3] = { 8, -7, 6 };
        double a[3] = { 0 };
    
        len = sizeof(u) / 8;
    
        printf("\n\nVector u =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u[i]);
        }
    
        printf("\n\nVector v =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", v[i]);
        }
    
        printf("\n\n\nv - u =\n");
    
        vectorSub(v, u, a, len);
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", a[i]);
        }
    }

Output from the lines above:

    Vector u =
    1.000
    2.000
    3.000
    
    Vector v =
    8.000
    -7.000
    6.000
    
    v - u =
    7.000
    -9.000
    3.000

The output shows the value for the vectors u and v as well as the result of subtracting the two vectors.

**Implementation/Code:** The following is the code for vectorSub()

    void vectorSub(double up[3], double vp[3], double ap[3], int len) {
        int i = 0;
        for (i = 0; i < len; i++) {
            ap[i] = up[i] - vp[i];
        }
    }

**Last Modified:** October/2018
