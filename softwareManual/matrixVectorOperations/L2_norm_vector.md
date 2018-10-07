# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorNormL2

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
        int len = 0;
        double ia = 0.0;
        double u[3] = { 1.0, 2.0, 3.0 };
    
        len = sizeof(u) / 8;
    
        printf("\n\nVector u =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u[i]);
        }
    
        ia = vectorNormL2(u, len);
        printf("\n\nL2 norm of u = %.3lf", ia);
    }

Output from the lines above:

    Vector u =
    1.000
    2.000
    3.000
    
    L2 norm of u = 3.742

The sum of the squared values in the vector u are (1 * 1) + (2 * 2) + (3 * 3) = 14, then the L2-norm = sqrt(14) = 3.742.

**Implementation/Code:** The following is the code for vectorNormL2()

    double vectorNormL2(double up[3], int len) {
        int i = 0;
        double ia = 0.0;
        for (i = 0; i < len; i++) {
            ia = ia + (up[i] * up[i]);
        }
        ia = sqrt(ia);
        return ia;
    }

**Last Modified:** October/2018
