# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorNormInfinity

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
        int len = 0;
        double ia = 0.0;
        double u[3] = { 1.0, 2.0, 3.0 };
    
        len = sizeof(u) / 8;
    
        printf("\n\nVector u =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u[i]);
        }
    
        ia = vectorNormInfinity(u, len);
        printf("\n\nInfinity norm of u = %.3lf", ia);
    }

Output from the lines above:

    Vector u =
    1.000
    2.000
    3.000
    
    Infinity norm of u = 3.000

The maximum value out of the vector elements 1.0, 2.0, and 3.0 is 3.0, therefore the Infinity-norm of the vector u is 3.0.

**Implementation/Code:** The following is the code for vectorNormInfinity()

    double vectorNormInfinity(double up[3], int len) {
        int i = 0;
        double ia = 0.0;
        ia = fabs(up[0]);
        for (i = 0; i < len; i++) {
            if (fabs(up[i]) > ia) {
                ia = fabs(up[i]);
            }
        }
        return ia;
    }

**Last Modified:** October/2018