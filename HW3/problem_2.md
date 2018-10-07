# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 2a.

**Routine Name:**           vectorErrorAbsoluteL1

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for absolute error between an exact vector x and a vector y which is the approximation to the vector x. Computing the absolute error between an exact and approximate vector involves taking the difference between the two and computing the L1-norm of the difference. The result is a single value to give some idea of the absolute error in an approximation to the exact vector.

**Input:** There are two inputs needed in this case. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function.

**Output:** This function returns a double precision value eabs which represents the absolute error between the two input vectors x and y.

**Usage/Example:**

The function has three input arguments needed to produce the absolute error. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function. The function returns a double precision value eabs which represents the absolute error between the two input vectors x and y.

    #include "mylib.h"

    int main() {
        int i = 0;
        int len = 0;
        double eabs = 0.0;
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
    
        eabs = vectorErrorAbsoluteL1(x, y, len);
        printf("\n\ne = x - y");
        printf("\nL1 norm of e = L1 eabs = %.3lf", eabs);
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
    
    e = x - y
    L1 norm of e = L1 eabs = 0.438

The output displays the values of the exact vector x and its approximation vector y. The error vector e = x-y and the L1-norm of the vector e represents the absolute error, in this case L1-eabs = 0.438.

**Implementation/Code:** The following is the code for vectorErrorAbsoluteL1()

    double vectorErrorAbsoluteL1(double xp[3], double yp[3], int len) {
    
        double eabs = 0.0;
        double e[3] = { 0 };
    
        vectorSub(xp, yp, e, len);
    
        eabs = vectorNormL1(e, len);
    
        return eabs;
    }
    
# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 2b.

**Routine Name:**           vectorErrorRelativeL1

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for relative error between an exact vector x and a vector y which is the approximation to the vector x. Computing the relative error between an exact and approximate vector involves taking the difference between the two and computing the L1-norm of the difference. The L1-norm of the difference divided by the L1-norm of x results in a single value to give some idea of the relative error in an approximation to the exact vector.

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
    
        erel = vectorErrorRelativeL1(x, y, len);
        printf("\n\neabs/L1 norm of x = L1 erel = %.3lf", erel);
    
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
    
    eabs/L1 norm of x = L1 erel = 0.068

The output displays the values of the exact vector x and its approximation vector y. The error vector e = x-y and the L1-norm of the vector e represents the absolute error, the absolute error divided by the L1-norm of x is the relative error and in this case L1-erel = 0.068.

**Implementation/Code:** The following is the code for vectorErrorRelativeL1()
    
    double vectorErrorRelativeL1(double xp[3], double yp[3], int len) {
    
        double erel = 0.0;
        double a = 0.0;
    
        a = vectorNormL1(xp, len);
    
        erel = ( vectorErrorAbsoluteL1(xp, yp, len) ) / a;
    
        return erel;
    }
    
# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 2c.

**Routine Name:**           vectorErrorAbsoluteL2

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for absolute error between an exact vector x and a vector y which is the approximation to the vector x. Computing the absolute error between an exact and approximate vector involves taking the difference between the two and computing the L2-norm of the difference. The result is a single value to give some idea of the absolute error in an approximation to the exact vector.

**Input:** There are two inputs needed in this case. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function.

**Output:** This function returns a double precision value eabs which represents the absolute error between the two input vectors x and y.

**Usage/Example:**

The function has three input arguments needed to produce the absolute error. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function. The function returns a double precision value eabs which represents the absolute error between the two input vectors x and y.

    #include "mylib.h"

    int main() {
        int i = 0;
        int len = 0;
        double eabs = 0.0;
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
    
        eabs = vectorErrorAbsoluteL2(x, y, len);
        printf("\n\ne = x - y");
        printf("\nL2 norm of e = L2 eabs = %.3lf", eabs);
    
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
    
    e = x - y
    L2 norm of e = L2 eabs = 0.286

The output displays the values of the exact vector x and its approximation vector y. The error vector e = x-y and the L2-norm of the vector e represents the absolute error, in this case L2-eabs = 0.286.

**Implementation/Code:** The following is the code for vectorErrorAbsoluteL2()
    
    double vectorErrorAbsoluteL2(double xp[3], double yp[3], int len) {
    
        double eabs = 0.0;
        double e[3] = { 0 };
    
        vectorSub(xp, yp, e, len);
    
        eabs = vectorNormL2(e, len);
    
        return eabs;
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 2d.

**Routine Name:**           vectorErrorRelativeL2

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for relative error between an exact vector x and a vector y which is the approximation to the vector x. Computing the relative error between an exact and approximate vector involves taking the difference between the two and computing the L2-norm of the difference. The L2-norm of the difference divided by the L2-norm of x results in a single value to give some idea of the relative error in an approximation to the exact vector.

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
    
        erel = vectorErrorRelativeL2(x, y, len);
        printf("\n\neabs/L2 norm of x = L2 erel = %.3lf", erel);
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
    
    eabs/L2 norm of x = L2 erel = 0.073

The output displays the values of the exact vector x and its approximation vector y. The error vector e = x-y and the L2-norm of the vector e represents the absolute error, the absolute error divided by the L2-norm of x is the relative error and in this case L2-erel = 0.073.

**Implementation/Code:** The following is the code for vectorErrorRelativeL2()
    
    double vectorErrorRelativeL2(double xp[3], double yp[3], int len) {
    
        double erel = 0.0;
        double a = 0.0;
    
        a = vectorNormL2(xp, len);
    
        erel = (vectorErrorAbsoluteL2(xp, yp, len)) / a;
    
        return erel;
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 2e.

**Routine Name:**           vectorErrorAbsoluteInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    norms.c

will produce an executable **norms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for absolute error between an exact vector x and a vector y which is the approximation to the vector x. Computing the absolute error between an exact and approximate vector involves taking the difference between the two and computing the Infinity-norm of the difference. The result is a single value to give some idea of the absolute error in an approximation to the exact vector.

**Input:** There are two inputs needed in this case. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function.

**Output:** This function returns a double precision value eabs which represents the absolute error between the two input vectors x and y.

**Usage/Example:**

The function has three input arguments needed to produce the absolute error. An exact vector x and a vector y which represents an approximation to the vector x are passed by reference and a parameter len which represents the length of the vectors is passed to the function. The function returns a double precision value eabs which represents the absolute error between the two input vectors x and y.

    #include "mylib.h"

    int main() {
        int i = 0;
        int len = 0;
        double eabs = 0.0;
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
    
        eabs = vectorErrorAbsoluteInfinity(x, y, len);
        printf("\n\ne = x - y");
        printf("\nInfinity norm of e = Infinity eabs = %.3lf", eabs);
    
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
    
    e = x - y
    Infinity norm of e = Infinity eabs = 0.250

The output displays the values of the exact vector x and its approximation vector y. The error vector e = x-y and the Infinity-norm of the vector e represents the absolute error, in this case Infinity-eabs = 0.250.

**Implementation/Code:** The following is the code for vectorErrorAbsoluteInfinity()
    
    double vectorErrorAbsoluteInfinity(double xp[3], double yp[3], int len) {
    
        double eabs = 0.0;
        double e[3] = { 0 };
    
        vectorSub(xp, yp, e, len);
    
        eabs = vectorNormInfinity(e, len);
    
        return eabs;
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 2f.

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
