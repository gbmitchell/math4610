# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 3a.

**Routine Name:**           vectorAdd

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorMath.c

will produce an executable **vectorMath.exe** that can be executed.

**Description/Purpose:** This function will add two vectors of the same size and the computation is done in double precision. 

**Input:** There are four inputs needed in this case. Vectors u, v, and a are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. The real purpose is to produce values in the vector a that represent the result of u + v.

**Output:** This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of adding the vectors u and v. The resulting vector a can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Vectors u, v, and a are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the result of adding the vectors u and v. The resulting vector a can then be used in the main program as needed.

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
    
        printf("\n\nu + v =\n");
    
        vectorAdd(u, v, a, len);
    
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
    
    u + v =
    9.000
    -5.000
    9.000

The output shows the value for the vectors u and v as well as the result of adding the two vectors.

**Implementation/Code:** The following is the code for vectorAdd()

    void vectorAdd(double up[3], double vp[3], double ap[3], int len) {
        int i = 0;
        for (i = 0; i < len; i++) {
            ap[i] = up[i] + vp[i];
        }
    }
    
# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 3b.

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

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 3c.

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

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 3d.

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

# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 3e.

**Routine Name:**           vectorCross

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorMath.c

will produce an executable **vectorMath.exe** that can be executed.

**Description/Purpose:** This function will compute the cross product of two vectors of the same size and the computation is done in double precision. 

**Input:** There are four inputs needed in this case. Vectors u, v, and a are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. The real purpose is to produce values in the vector a that represent the cross product of the vectors u and v.

**Output:** This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the cross product the vectors u and v. The resulting vector a can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Vectors u, v, and a are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the cross product the vectors u and v. The resulting vector a can then be used in the main program as needed.

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

        printf("\n\n\nCross product of u and v =\n");

        vectorCross(u, v, a, len);

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
    
    Cross product of u and v =
    33.000
    18.000
    -23.000

The output shows the value for the vectors u and v as well as the resulting cross product of the two vectors.

**Implementation/Code:** The following is the code for vectorCross()

    void vectorCross(double up[3], double vp[3], double ap[3], int len) {
        ap[0] = (up[1] * vp[2]) - (up[2] * vp[1]);
        ap[1] = (up[2] * vp[0]) - (up[0] * vp[2]);
        ap[2] = (up[0] * vp[1]) - (up[1] * vp[0]);
    }

**Last Modified:** September/2018
