# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 1.

**Routine Name:**           L1-norm

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the L1-norm given a vector. The function was developed to compute the L1-norm of a vector with three elements or vector length of three.

**Input:** There are no inputs needed in this case. Arguments are passed by reference and the function will change their values.
The real purpose is to produce values in those variables to be used as needed.

**Output:** This function returns a single precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:**

The function has two arguments needed to produce the values of the precision in terms of the smallest number that can be
represented. Since the code is written in terms of a C function, the value of the machine epsilon (seps) is a single
precision value (float) and the power of two that gives the machine epsilon (ipow) is an integer. 

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int len = 0;
        double ia = 0.0;
        double u[3] = { 1, 2, 3 };
    
        len = sizeof(u) / 8;
    
        printf("\n\nVector u =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u[i]);
        }
    
        ia = vectorNormL1(u, len);
        printf("\n\nL1 norm of u = %.3lf", ia);
    }

Output from the lines above:

      24    5.96046448e-08

The first value (24) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly eight (e-08 on the
end of the second value).

**Implementation/Code:** The following is the code for vectorNormL1()

    double vectorNormL1(double up[3], int len) {
        int i = 0;
        double ia = 0.0;
        for (i = 0; i < len; i++) {
            ia = ia + fabs(up[i]);
        }
        return ia;
    }

**Last Modified:** September/2018
