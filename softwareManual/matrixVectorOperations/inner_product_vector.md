# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorInner

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorMath.c

will produce an executable **vectorMath.exe** that can be executed.

**Description/Purpose:** This function will compute the inner product of two vectors of the same size and the computation is done in double precision. 

**Input:** There are three inputs needed in this case. Vectors u and v are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors.

**Output:** This function returns a double precision value which represents the inner product of the vectors u and v.

**Usage/Example:**

There are three inputs needed in this case. Vectors u and v are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. This function returns a double precision value ia, which represents the inner product of the vectors u and v.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int len = 0;
        double ia = 0;
        double u[3] = { 1, 2, 3 };
        double v[3] = { 8, -7, 6 };
    
        len = sizeof(u) / 8;
    
        printf("\n\nVector u =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u[i]);
        }
    
        printf("\n\nVector v =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", v[i]);
        }
    
        printf("\n\n\nInner product of u and v = ");
    
        ia = vectorInner(u, v, len);
    
        printf("%.3lf", ia);
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
    
    Inner product of u and v = 12.000

The output shows the value for the vectors u and v as well as the resulting inner product of the vectors.

**Implementation/Code:** The following is the code for vectorInner()

    double vectorInner(double up[3], double vp[3], int len) {
        int i = 0;
        double ia = 0.0;
        for (i = 0; i < len; i++) {
            ia = ia + ( up[i] * vp[i]);
        }
        return ia;
    }

**Last Modified:** October/2018
