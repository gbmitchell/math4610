# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorScale

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorMath.c

will produce an executable **vectorMath.exe** that can be executed.

**Description/Purpose:** This function will scale a vector by a value defined by the variable scaler. Given a vector u, the function will multiply each element of the vector by a scale value which results in a new vector with scaled values. 

**Input:** There are four inputs needed in this case. Vectors u and a are arguments passed by reference. Scaler and len are arguments passed to the function to indicate the scale value and the length of the vectors. The real purpose is to produce values in the vector a that represent the result of scaler * u.

**Output:** This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of scaling the vector u by the scaler value. The resulting vector a can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Vectors u and a are arguments passed by reference. Scaler and len are arguments passed to the function to indicate the scale value and the length of the vectors. This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of scaling the vector u by the scaler value. The resulting vector a can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int len = 0;
        double scaler = 5.0;
        double u[3] = { 1, 2, 3 };
        double a[3] = { 0 };
    
        len = sizeof(u) / 8;
    
        printf("\n\nVector u =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u[i]);
        }
    
        printf("\n\n\nScaler * u =\n");
    
        vectorScale(u, a, scaler, len);
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", a[i]);
        }
    }

Output from the lines above:

    Vector u =
    1.000
    2.000
    3.000
    
    Scaler * u =
    5.000
    10.000
    15.000

The output shows the value for the vector u and the result of scaling the vector u by a value of 5.0.

**Implementation/Code:** The following is the code for vectorScale()

    void vectorScale(double up[3], double ap[3], double scale, int len) {
        int i = 0;
        for (i = 0; i < len; i++) {
            ap[i] = scale * up[i];
        }
    }

**Last Modified:** October/2018
