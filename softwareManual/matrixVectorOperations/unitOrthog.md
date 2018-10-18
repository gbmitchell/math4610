# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           unitOrthog

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorMath.c

will produce an executable **vectorMath.exe** that can be executed.

**Description/Purpose:** This function will compute a pair of unit vectors u1 and u2 which are orthoginal to the original vectors v1 and v2. This is accomplished by taking the cross product of v1 and v2 to get an orthoginal vector. Then the L2-norm or the cross product is computed. Next, (v1 cross v2)/(L2-norm of v1 cross v2) gives a unit vector u1 orthoginal to v1 and v2. Last, negating u1 will give another unit vector u2 orthoginal to v1 and v2.

**Input:** There are five inputs needed in this case. The arguments v1, v2, u1, and u2 are passed by reference and the function will change the values in u1 and u2 to be used in the main program as needed. The variable len is also passed to the function to indicate the length of the vectors.

**Output:** This function does not return any values, rather it changes the values in u1 and u2 which were passed in by reference. After changing the values in u1 and u2, they can be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. The arguments v1, v2, u1, and u2 are passed by reference and the function will change the values in u1 and u2 to be used in the main program as needed. The variable len is also passed to the function to indicate the length of the vectors. This function does not return any values, rather it changes the values in u1 and u2 which were passed in by reference. After changing the values in u1 and u2, they can be used in the main program as needed.

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

The output shows what the original vectors v1 and v2 are. After the unitOrthog routine is called the resulting unit orthoginal vectors u1 and u2 are displayed.

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

**Last Modified:** October/2018
