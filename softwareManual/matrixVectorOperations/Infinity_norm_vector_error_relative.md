# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorErrorRelativeInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for relative error between an exact vector x and a vector y which is the approximation to the vector x. Computing the relative error between an exact and approximate vector involves taking the difference between the two and computing the Infinity-norm of the difference. The Infinity-norm of the difference divided by the Infinity-norm of x results in a single value to give some idea of the relative error in an approximation to the exact vector.

**Input:** There are two inputs needed in this case. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function.

**Output:** This function returns a double precision value erel which represents the relative error between the two input vectors x and y.

**Usage/Example:**

The function has three input arguments needed to produce the relative error. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function. The function returns a double precision value erel which represents the relative error between the two input vectors x and y.

    #include "mylib.h"

    int main() {
        int i = 0;
        int len = 0;
        double erel = 0.0;
        double x[3] = { -1.25, 2.125, 3.0625 };
        double y[3] = { -1.0, 2.0, 3.0 };
    
        len = sizeof(x) / 8;
    
        printf("\n\nExact Vector x =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", x[i]);
        }
    
        printf("\n\nApproximate Vector y =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", y[i]);
        }
    
        erel = vectorErrorRelativeInfinity(x, y, len);
        printf("\n\neabs/Infinity norm of x = Infinity erel = %.3lf", erel);
    }

Output from the lines above:

    Exact Vector x =
    -1.250
    2.125
    3.063
    
    Approximate Vector y =
    -1.000
    2.000
    3.000
    
    eabs/Infinity norm of x = Infinity erel = 0.082

The output displays the values of the exact vector x and its approximation vector y. The error vector e = x-y and the Infinity-norm of the vector e represents the absolute error, the absolute error divided by the Infinity-norm of x is the relative error and in this case Infinity-erel = 0.082.

**Implementation/Code:** The following is the code for vectorErrorRelativeInfinity()
    
    double vectorErrorRelativeInfinity(double xp[3], double yp[3], int len) {
    
        double erel = 0.0;
        double a = 0.0;
    
        a = vectorNormInfinity(xp, len);
    
        erel = (vectorErrorAbsoluteInfinity(xp, yp, len)) / a;
    
        return erel;
    }

**Last Modified:** October/2018
