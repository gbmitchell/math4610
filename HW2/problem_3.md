# Math 4610 Fundamentals of Computational Mathematics
Homework 2, problem 3a.

**Routine Name:**           expderivative

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** This function will compute an approximation for the derivative of a defined
function f(x) at a given value of x.

**Input:** There are six inputs needed in this case. A defined function f(x). A value for x. A value for
h, a distance from x. A tolerance eps for convergance to the expected derivative. A value for the maximum
number of itterations incase the result does not converge. A value for expder, the expected derivate used
to calculate the error between the approximate and expected derivative.

**Output:** The function returns a double precision value that represents an approximation of the derivative
for a defined function f(x) at a value of x.

**Usage/Example:**

The function returns an approximation for the derivative of a defined function f(x) at a given value of x.
As the value h moves toward zero, the approximation will increase in accuracy. The code below computes the
derivative with h starting at 1.0 and then halfing the value of h until a specified accuracy is reached or
a specified itteration count is reached. The function does have limitations as shown in the data output.
Some funcions will converge as expected toward the derivative and other functions start converging toward
the derivative and then diverge giving unexpected results. It is possible to mitigate error in some cases,
for example the sqrt(x) appears to converge and then diverges. Using the approximation for the derivative of
the sqrt(x) and multiplying by its conjugate will produce an alternative form that will converge to the 
correct value. Below is code written to demonstrate this.

    #include <stdio.h>
    #include <math.h>
    #include <mylib.h>


    int main() {

        int i = 0;
        int ipow = 0;
        int  maxIteration = 0;

        double eps = 0.0;
        double eabsolute = 0.0;
        double erelative = 0.0;

        double x = 0.0;
        double h = 0.0;
        double expder = 0.0;
        double fxx = 0.0;

        //***************************************************************************************
        //*******************  approximation for d/dx( sqrt(x) ) at x = 2.0  ********************
        //***************************************************************************************
        x = 2.0;
        h = 1.0;
        maxIteration = 50;
        expder = 0.353553390593;
        dmaceps(&eps, &ipow);

        printf("approximation for d/dx( sqrt(x) )\n");

        fxx = expderivative(sqrt, x, h, eps, maxIteration, expder);


        //***************************************************************************************
        //************* alternative approximation for d/dx( sqrt(x) ) at x = 2.0  ***************
        //***************************************************************************************
        x = 2.0;
        h = 1.0;
        maxIteration = 55;
        expder = 0.353553390593;
        dmaceps(&eps, &ipow);

        i = 0;
        eabsolute = 0.0;
        erelative = 0.0;

        printf("alternate approximation for d/dx( sqrt(x) )\n");
        printf("dmaceps =  %.8e\n", eps);
        printf("x = %lf\n", x);
        printf("expected derivative = %.12lf\n\n", expder);

        printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
        printf("--------------------------------------------------------------------------------------------\n");

        eabsolute = 10.0 * eps;

        while ((eabsolute > eps) && maxIteration > 0) {

            maxIteration--;
            i++;

            fxx = ((x + h) - x) / (h*(sqrt(x + h) + sqrt(x)));

            eabsolute = eabs(fxx, expder);
            erelative = erel(fxx, expder);

            printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fxx, h, eabsolute, erelative);
            h = h / 2.0;

        }
        printf("\n\n\n");


        //***************************************************************************************
        //************* direct use of d/dx( sqrt(x) ) =  1 / (2 * sqrt(x)), at x = 2.0  *********
        //***************************************************************************************

        expder = 0.353553390593;
        x = 2.0;
        dmaceps(&eps, &ipow);

        printf("direct use of d/dx( sqrt(x) ) = 1 / (2 * sqrt(x))\n");
        printf("dmaceps =  %.8e\n", eps);
        printf("x = %lf\n", x);
        printf("expected derivative = %.12lf\n\n", expder);

        printf("direct derivative\t\t| e absolute\t| e relative\n");
        printf("--------------------------------------------------------------------------------------------\n");

        fxx = 1 / (2 * sqrt(x));

        eabsolute = eabs(fxx, expder);
        erelative = erel(fxx, expder);

        printf("%.8e\t\t\t| %.3e\t| %.3e\n", fxx, eabsolute, erelative);

        printf("\n\n\n");
    }
    
Output from the lines above:

    approximation for d/dx( sqrt(x) )
    dmaceps =  1.11022302e-16
    x = 2.000000
    expected derivative = 0.353553390593

    i       | appoximate derivative         | h             | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.17837245e-01                | 1.000e+00     | 3.572e-02     | 1.010e-01
    2       | 3.33850535e-01                | 5.000e-01     | 1.970e-02     | 5.573e-02
    3       | 3.43145751e-01                | 2.500e-01     | 1.041e-02     | 2.944e-02
    4       | 3.48195291e-01                | 1.250e-01     | 5.358e-03     | 1.515e-02
    5       | 3.50833588e-01                | 6.250e-02     | 2.720e-03     | 7.693e-03
    6       | 3.52183008e-01                | 3.125e-02     | 1.370e-03     | 3.876e-03
    7       | 3.52865541e-01                | 1.563e-02     | 6.878e-04     | 1.946e-03
    8       | 3.53208796e-01                | 7.813e-03     | 3.446e-04     | 9.747e-04
    9       | 3.53380925e-01                | 3.906e-03     | 1.725e-04     | 4.878e-04
    10      | 3.53467116e-01                | 1.953e-03     | 8.627e-05     | 2.440e-04
    11      | 3.53510243e-01                | 9.766e-04     | 4.315e-05     | 1.220e-04
    12      | 3.53531814e-01                | 4.883e-04     | 2.158e-05     | 6.103e-05
    13      | 3.53542602e-01                | 2.441e-04     | 1.079e-05     | 3.052e-05
    14      | 3.53547996e-01                | 1.221e-04     | 5.395e-06     | 1.526e-05
    15      | 3.53550693e-01                | 6.104e-05     | 2.697e-06     | 7.629e-06
    16      | 3.53552042e-01                | 3.052e-05     | 1.349e-06     | 3.815e-06
    17      | 3.53552716e-01                | 1.526e-05     | 6.743e-07     | 1.907e-06
    18      | 3.53553053e-01                | 7.629e-06     | 3.372e-07     | 9.537e-07
    19      | 3.53553222e-01                | 3.815e-06     | 1.686e-07     | 4.769e-07
    20      | 3.53553306e-01                | 1.907e-06     | 8.440e-08     | 2.387e-07
    21      | 3.53553348e-01                | 9.537e-07     | 4.214e-08     | 1.192e-07
    22      | 3.53553369e-01                | 4.768e-07     | 2.142e-08     | 6.058e-08
    23      | 3.53553380e-01                | 2.384e-07     | 1.071e-08     | 3.028e-08
    24      | 3.53553385e-01                | 1.192e-07     | 6.051e-09     | 1.711e-08
    25      | 3.53553385e-01                | 5.960e-08     | 6.051e-09     | 1.711e-08
    26      | 3.53553385e-01                | 2.980e-08     | 6.051e-09     | 1.711e-08
    27      | 3.53553385e-01                | 1.490e-08     | 6.051e-09     | 1.711e-08
    28      | 3.53553385e-01                | 7.451e-09     | 6.051e-09     | 1.711e-08
    29      | 3.53553355e-01                | 3.725e-09     | 3.585e-08     | 1.014e-07
    30      | 3.53553295e-01                | 1.863e-09     | 9.546e-08     | 2.700e-07
    31      | 3.53553295e-01                | 9.313e-10     | 9.546e-08     | 2.700e-07
    32      | 3.53553295e-01                | 4.657e-10     | 9.546e-08     | 2.700e-07
    33      | 3.53552818e-01                | 2.328e-10     | 5.723e-07     | 1.619e-06
    34      | 3.53551865e-01                | 1.164e-10     | 1.526e-06     | 4.316e-06
    35      | 3.53549957e-01                | 5.821e-11     | 3.433e-06     | 9.711e-06
    36      | 3.53553772e-01                | 2.910e-11     | 3.814e-07     | 1.079e-06
    37      | 3.53546143e-01                | 1.455e-11     | 7.248e-06     | 2.050e-05
    38      | 3.53546143e-01                | 7.276e-12     | 7.248e-06     | 2.050e-05
    39      | 3.53515625e-01                | 3.638e-12     | 3.777e-05     | 1.068e-04
    40      | 3.53515625e-01                | 1.819e-12     | 3.777e-05     | 1.068e-04
    41      | 3.53515625e-01                | 9.095e-13     | 3.777e-05     | 1.068e-04
    42      | 3.53515625e-01                | 4.547e-13     | 3.777e-05     | 1.068e-04
    43      | 3.53515625e-01                | 2.274e-13     | 3.777e-05     | 1.068e-04
    44      | 3.53515625e-01                | 1.137e-13     | 3.777e-05     | 1.068e-04
    45      | 3.51562500e-01                | 5.684e-14     | 1.991e-03     | 5.631e-03
    46      | 3.51562500e-01                | 2.842e-14     | 1.991e-03     | 5.631e-03
    47      | 3.43750000e-01                | 1.421e-14     | 9.803e-03     | 2.773e-02
    48      | 3.43750000e-01                | 7.105e-15     | 9.803e-03     | 2.773e-02
    49      | 3.12500000e-01                | 3.553e-15     | 4.105e-02     | 1.161e-01
    50      | 2.50000000e-01                | 1.776e-15     | 1.036e-01     | 2.929e-01



    alternate approximation for d/dx( sqrt(x) )
    dmaceps =  1.11022302e-16
    x = 2.000000
    expected derivative = 0.353553390593

    i       | appoximate derivative         | h             | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.17837245e-01                | 1.000e+00     | 3.572e-02     | 1.010e-01
    2       | 3.33850535e-01                | 5.000e-01     | 1.970e-02     | 5.573e-02
    3       | 3.43145751e-01                | 2.500e-01     | 1.041e-02     | 2.944e-02
    4       | 3.48195291e-01                | 1.250e-01     | 5.358e-03     | 1.515e-02
    5       | 3.50833588e-01                | 6.250e-02     | 2.720e-03     | 7.693e-03
    6       | 3.52183008e-01                | 3.125e-02     | 1.370e-03     | 3.876e-03
    7       | 3.52865541e-01                | 1.563e-02     | 6.878e-04     | 1.946e-03
    8       | 3.53208796e-01                | 7.813e-03     | 3.446e-04     | 9.747e-04
    9       | 3.53380925e-01                | 3.906e-03     | 1.725e-04     | 4.878e-04
    10      | 3.53467116e-01                | 1.953e-03     | 8.627e-05     | 2.440e-04
    11      | 3.53510243e-01                | 9.766e-04     | 4.315e-05     | 1.220e-04
    12      | 3.53531814e-01                | 4.883e-04     | 2.158e-05     | 6.103e-05
    13      | 3.53542602e-01                | 2.441e-04     | 1.079e-05     | 3.052e-05
    14      | 3.53547996e-01                | 1.221e-04     | 5.395e-06     | 1.526e-05
    15      | 3.53550693e-01                | 6.104e-05     | 2.697e-06     | 7.629e-06
    16      | 3.53552042e-01                | 3.052e-05     | 1.349e-06     | 3.815e-06
    17      | 3.53552716e-01                | 1.526e-05     | 6.743e-07     | 1.907e-06
    18      | 3.53553053e-01                | 7.629e-06     | 3.372e-07     | 9.537e-07
    19      | 3.53553222e-01                | 3.815e-06     | 1.686e-07     | 4.768e-07
    20      | 3.53553306e-01                | 1.907e-06     | 8.429e-08     | 2.384e-07
    21      | 3.53553348e-01                | 9.537e-07     | 4.215e-08     | 1.192e-07
    22      | 3.53553370e-01                | 4.768e-07     | 2.107e-08     | 5.960e-08
    23      | 3.53553380e-01                | 2.384e-07     | 1.054e-08     | 2.980e-08
    24      | 3.53553385e-01                | 1.192e-07     | 5.268e-09     | 1.490e-08
    25      | 3.53553388e-01                | 5.960e-08     | 2.634e-09     | 7.450e-09
    26      | 3.53553389e-01                | 2.980e-08     | 1.317e-09     | 3.725e-09
    27      | 3.53553390e-01                | 1.490e-08     | 6.583e-10     | 1.862e-09
    28      | 3.53553390e-01                | 7.451e-09     | 3.290e-10     | 9.305e-10
    29      | 3.53553390e-01                | 3.725e-09     | 1.644e-10     | 4.649e-10
    30      | 3.53553391e-01                | 1.863e-09     | 8.204e-11     | 2.321e-10
    31      | 3.53553391e-01                | 9.313e-10     | 4.089e-11     | 1.156e-10
    32      | 3.53553391e-01                | 4.657e-10     | 2.031e-11     | 5.743e-11
    33      | 3.53553391e-01                | 2.328e-10     | 1.002e-11     | 2.833e-11
    34      | 3.53553391e-01                | 1.164e-10     | 4.871e-12     | 1.378e-11
    35      | 3.53553391e-01                | 5.821e-11     | 2.299e-12     | 6.502e-12
    36      | 3.53553391e-01                | 2.910e-11     | 1.013e-12     | 2.864e-12
    37      | 3.53553391e-01                | 1.455e-11     | 3.694e-13     | 1.045e-12
    38      | 3.53553391e-01                | 7.276e-12     | 4.785e-14     | 1.353e-13
    39      | 3.53553391e-01                | 3.638e-12     | 1.130e-13     | 3.195e-13
    40      | 3.53553391e-01                | 1.819e-12     | 1.933e-13     | 5.469e-13
    41      | 3.53553391e-01                | 9.095e-13     | 2.335e-13     | 6.605e-13
    42      | 3.53553391e-01                | 4.547e-13     | 2.536e-13     | 7.174e-13
    43      | 3.53553391e-01                | 2.274e-13     | 2.637e-13     | 7.458e-13
    44      | 3.53553391e-01                | 1.137e-13     | 2.687e-13     | 7.599e-13
    45      | 3.53553391e-01                | 5.684e-14     | 2.712e-13     | 7.671e-13
    46      | 3.53553391e-01                | 2.842e-14     | 2.724e-13     | 7.706e-13
    47      | 3.53553391e-01                | 1.421e-14     | 2.731e-13     | 7.725e-13
    48      | 3.53553391e-01                | 7.105e-15     | 2.734e-13     | 7.734e-13
    49      | 3.53553391e-01                | 3.553e-15     | 2.736e-13     | 7.737e-13
    50      | 3.53553391e-01                | 1.776e-15     | 2.737e-13     | 7.741e-13
    51      | 3.53553391e-01                | 8.882e-16     | 2.737e-13     | 7.741e-13
    52      | 3.53553391e-01                | 4.441e-16     | 2.737e-13     | 7.742e-13
    53      | 0.00000000e+00                | 2.220e-16     | 3.536e-01     | 1.000e+00
    54      | 0.00000000e+00                | 1.110e-16     | 3.536e-01     | 1.000e+00
    55      | 0.00000000e+00                | 5.551e-17     | 3.536e-01     | 1.000e+00



    direct use of d/dx( sqrt(x) ) = 1 / (2 * sqrt(x))
    dmaceps =  1.11022302e-16
    x = 2.000000
    expected derivative = 0.353553390593

    direct derivative               | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    3.53553391e-01                  | 2.737e-13     | 7.742e-13

First the derivative function was used to approximate the derivative of sqrt(x) at x = 2.0 and the
approximation converged to an approximate value of 3.53553385e-01 with absolute error of 6.051e-09.
The approximation then began to move away from the correct value and the error increased. Next the 
dirivative function was rewriten by multiplying by the conjugate and the approximation converged
to a value of 3.53553391e-01 and absolute error of 2.737e-13. Finaly the direct derivative of sqrt(x)
was used and produced a value of 3.53553391e-01 and absolute error of 2.737e-13. Rewriting the
derivative provided a better function for approximation as can be seen by comparing the result with the
dirrect use of the derivative.

**Implementation/Code:** The following is the code for expderivative()

    double expderivative(double(*f)(double), double x, double h, double tol, int maxItr, double expder) {
        int i = 0;
        double fp = 0.0;
        double eabsolute = 0.0;
        double erelative = 0.0;

        printf("dmaceps =  %.8e\n", tol);
        printf("x = %lf\n", x);
        printf("expected derivative = %.12lf\n\n", expder);

        printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
        printf("--------------------------------------------------------------------------------------------\n");

        eabsolute = 10.0 * tol;

        while ((eabsolute > tol) && maxItr > 0) {

            maxItr--;
            i++;

            fp = (f(x + h) - f(x)) / (h);

            eabsolute = eabs(fp, expder);
            erelative = erel(fp, expder);

            printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fp, h, eabsolute, erelative);
            h = h / 2.0;

        }
        printf("\n\n\n");

        return fp;
    }

# Math 4610 Fundamentals of Computational Mathematics
Homework 2, problem 3b.

**Routine Name:**           expderivative

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** This function will compute an approximation for the derivative of a defined
function f(x) at a given value of x.

**Input:** There are six inputs needed in this case. A defined function f(x). A value for x. A value for
h, a distance from x. A tolerance eps for convergance to the expected derivative. A value for the maximum
number of itterations incase the result does not converge. A value for expder, the expected derivate used
to calculate the error between the approximate and expected derivative.

**Output:** The function returns a double precision value that represents an approximation of the derivative
for a defined function f(x) at a value of x.

**Usage/Example:**

In this example we will use the derivative approximation to examin the funcion sin(x) at x = 0. Alternativly
we will use a taylor series expansion of sin(x) and approximate its derivative.

    #include <stdio.h>
    #include <math.h>
    #include <mylib.h>
    
    
    int main() {
    
        int i = 0;
        int ipow = 0;
        int  maxIteration = 0;
    
        double eps = 0.0;
        double eabsolute = 0.0;
        double erelative = 0.0;
    
        double x = 0.0;
        double h = 0.0;
        double expder = 0.0;
        double fxx = 0.0;
     
        //***************************************************************************************
        //************* approximation for d/dx( sin(x) ) at x = 0.0  ***************
        //***************************************************************************************
        x = 0.0;
        h = 1.0;
        maxIteration = 50;
        expder = 1.0;
        dmaceps(&eps, &ipow);
    
        printf("approximation for d/dx( sin(x) )\n");
    
        fxx = expderivative(sin, x, h, eps, maxIteration, expder);
    
    
        //***************************************************************************************
        //************* taylor series approximation for d/dx( sin(x) ) at x = 0.0  **************
        //************************** f(x) = x - (x^3/6) *****************************************
        //***************************************************************************************
        x = 0.0;
        h = 1.0;
        maxIteration = 50;
        expder = 1.0;
        dmaceps(&eps, &ipow);
    
        printf("taylor series approximation for d/dx( sin(x) ) = d/dx( x - ( x^3/6 ) )\n");
    
        fxx = expderivative(fnct2, x, h, eps, maxIteration, expder);
    
    }

Output from the lines above:

    approximation for d/dx( sin(x) )
    dmaceps =  1.11022302e-16
    x = 0.000000
    expected derivative = 1.000000000000
    
    i       | appoximate derivative         | h             | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 8.41470985e-01                | 1.000e+00     | 1.585e-01     | 1.585e-01
    2       | 9.58851077e-01                | 5.000e-01     | 4.115e-02     | 4.115e-02
    3       | 9.89615837e-01                | 2.500e-01     | 1.038e-02     | 1.038e-02
    4       | 9.97397867e-01                | 1.250e-01     | 2.602e-03     | 2.602e-03
    5       | 9.99349085e-01                | 6.250e-02     | 6.509e-04     | 6.509e-04
    6       | 9.99837248e-01                | 3.125e-02     | 1.628e-04     | 1.628e-04
    7       | 9.99959310e-01                | 1.563e-02     | 4.069e-05     | 4.069e-05
    8       | 9.99989828e-01                | 7.813e-03     | 1.017e-05     | 1.017e-05
    9       | 9.99997457e-01                | 3.906e-03     | 2.543e-06     | 2.543e-06
    10      | 9.99999364e-01                | 1.953e-03     | 6.358e-07     | 6.358e-07
    11      | 9.99999841e-01                | 9.766e-04     | 1.589e-07     | 1.589e-07
    12      | 9.99999960e-01                | 4.883e-04     | 3.974e-08     | 3.974e-08
    13      | 9.99999990e-01                | 2.441e-04     | 9.934e-09     | 9.934e-09
    14      | 9.99999998e-01                | 1.221e-04     | 2.484e-09     | 2.484e-09
    15      | 9.99999999e-01                | 6.104e-05     | 6.209e-10     | 6.209e-10
    16      | 1.00000000e+00                | 3.052e-05     | 1.552e-10     | 1.552e-10
    17      | 1.00000000e+00                | 1.526e-05     | 3.881e-11     | 3.881e-11
    18      | 1.00000000e+00                | 7.629e-06     | 9.701e-12     | 9.701e-12
    19      | 1.00000000e+00                | 3.815e-06     | 2.425e-12     | 2.425e-12
    20      | 1.00000000e+00                | 1.907e-06     | 6.063e-13     | 6.063e-13
    21      | 1.00000000e+00                | 9.537e-07     | 1.515e-13     | 1.515e-13
    22      | 1.00000000e+00                | 4.768e-07     | 3.786e-14     | 3.786e-14
    23      | 1.00000000e+00                | 2.384e-07     | 9.437e-15     | 9.437e-15
    24      | 1.00000000e+00                | 1.192e-07     | 2.331e-15     | 2.331e-15
    25      | 1.00000000e+00                | 5.960e-08     | 5.551e-16     | 5.551e-16
    26      | 1.00000000e+00                | 2.980e-08     | 1.110e-16     | 1.110e-16
    
    
    
    taylor series approximation for d/dx( sin(x) ) = d/dx( x - ( x^3/6 ) )
    dmaceps =  1.11022302e-16
    x = 0.000000
    expected derivative = 1.000000000000
    
    i       | appoximate derivative         | h             | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 8.33333333e-01                | 1.000e+00     | 1.667e-01     | 1.667e-01
    2       | 9.58333333e-01                | 5.000e-01     | 4.167e-02     | 4.167e-02
    3       | 9.89583333e-01                | 2.500e-01     | 1.042e-02     | 1.042e-02
    4       | 9.97395833e-01                | 1.250e-01     | 2.604e-03     | 2.604e-03
    5       | 9.99348958e-01                | 6.250e-02     | 6.510e-04     | 6.510e-04
    6       | 9.99837240e-01                | 3.125e-02     | 1.628e-04     | 1.628e-04
    7       | 9.99959310e-01                | 1.563e-02     | 4.069e-05     | 4.069e-05
    8       | 9.99989827e-01                | 7.813e-03     | 1.017e-05     | 1.017e-05
    9       | 9.99997457e-01                | 3.906e-03     | 2.543e-06     | 2.543e-06
    10      | 9.99999364e-01                | 1.953e-03     | 6.358e-07     | 6.358e-07
    11      | 9.99999841e-01                | 9.766e-04     | 1.589e-07     | 1.589e-07
    12      | 9.99999960e-01                | 4.883e-04     | 3.974e-08     | 3.974e-08
    13      | 9.99999990e-01                | 2.441e-04     | 9.934e-09     | 9.934e-09
    14      | 9.99999998e-01                | 1.221e-04     | 2.484e-09     | 2.484e-09
    15      | 9.99999999e-01                | 6.104e-05     | 6.209e-10     | 6.209e-10
    16      | 1.00000000e+00                | 3.052e-05     | 1.552e-10     | 1.552e-10
    17      | 1.00000000e+00                | 1.526e-05     | 3.881e-11     | 3.881e-11
    18      | 1.00000000e+00                | 7.629e-06     | 9.701e-12     | 9.701e-12
    19      | 1.00000000e+00                | 3.815e-06     | 2.425e-12     | 2.425e-12
    20      | 1.00000000e+00                | 1.907e-06     | 6.063e-13     | 6.063e-13
    21      | 1.00000000e+00                | 9.537e-07     | 1.515e-13     | 1.515e-13
    22      | 1.00000000e+00                | 4.768e-07     | 3.786e-14     | 3.786e-14
    23      | 1.00000000e+00                | 2.384e-07     | 9.437e-15     | 9.437e-15
    24      | 1.00000000e+00                | 1.192e-07     | 2.331e-15     | 2.331e-15
    25      | 1.00000000e+00                | 5.960e-08     | 5.551e-16     | 5.551e-16
    26      | 1.00000000e+00                | 2.980e-08     | 1.110e-16     | 1.110e-16

First the derivative function was used to approximate the derivative of sin(x) at x = 0 and the
approximation converged to an approximate value of 1.00000000e+00 with absolute error of 1.110e-16.
Next the function sin(x) was rewriten as a talor series expansion and the derivative approximation
was used and converged to an approximation of 1.00000000e+00 with absolute error of 1.110e-16. Both
using the sin(x) function and taylor series expansion resulted in convergance.

**Implementation/Code:** The following is the code for derivative()

    double expderivative(double(*f)(double), double x, double h, double tol, int maxItr, double expder) {
        int i = 0;
        double fp = 0.0;
        double eabsolute = 0.0;
        double erelative = 0.0;

        printf("dmaceps =  %.8e\n", tol);
        printf("x = %lf\n", x);
        printf("expected derivative = %.12lf\n\n", expder);

        printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
        printf("--------------------------------------------------------------------------------------------\n");

        eabsolute = 10.0 * tol;

        while ((eabsolute > tol) && maxItr > 0) {

            maxItr--;
            i++;

            fp = (f(x + h) - f(x)) / (h);

            eabsolute = eabs(fp, expder);
            erelative = erel(fp, expder);

            printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fp, h, eabsolute, erelative);
            h = h / 2.0;

        }
        printf("\n\n\n");

        return fp;
    }

**Last Modified:** September/2018
