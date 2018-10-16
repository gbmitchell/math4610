# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 9.

**Routine Name:**           unitOrthog

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorMath.c

will produce an executable **vectorMath.exe** that can be executed.

**Description/Purpose:** This function will compute the single precision value for the machine epsilon or the number of digits
in the representation of real numbers in single precision. This is a function for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

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
        double v1[3] = { 4, -1, 2 };
        double v2[3] = { 0, 5, 1 };
        double u1[3] = { 0 };
        double u2[3] = { 0 };

        printf("\n\nVector v1 =\n");

        for (i = 0; i < len; i++) {
            printf("%.3lf\n", v1[i]);
        }

        printf("\n\nVector v2 =\n");

        for (i = 0; i < len; i++) {
            printf("%.3lf\n", v2[i]);
        }

        unitOrthog(v1, v2, u1, u2, len);

        printf("\n\n\nUnit orthoginal vector u1 =\n");
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u1[i]);
        }

        printf("\n\n\nUnit orthoginal vector u2 =\n");
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u2[i]);
        }
    }

Output from the lines above:

    Vector v1 =
    4.000
    -1.000
    2.000
    
    Vector v2 =
    0.000
    5.000
    1.000
    
    Unit orthoginal vector u1 =
    -0.475
    -0.173
    0.863
    
    Unit orthoginal vector u2 =
    0.475
    0.173
    -0.863

The first value (24) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly eight (e-08 on the
end of the second value).

**Implementation/Code:** The following is the code for unitOrthog()

    void unitOrthog(double v1[3], double v2[3], double u1[3], double u2[3], int len) {

        int i = 0;
        double ia = 0;
        double a[3] = { 0 };

        vectorCross(v1, v2, a, len);

        ia = vectorNormL2(a, len);

        ia = 1 / ia;

        vectorScale(a, u1, ia, len);

        vectorScale(u1, u2, -1.0, len);
    }

**Last Modified:** September/2018
