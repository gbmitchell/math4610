# Math 4610 Fundamentals of Computational Mathematics
Homework 2 problem 2.

**Routine Name:**           derivative

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** This function will compute an approximation for the derivative of a defined
function f(x) at a given value of x.

**Input:** There are three inputs needed in this case. A defined function f(x), an initial guess x,
and h (a distance from x) are arguments passed to the function as inputs.

**Output:** The function returns a double precision value that represents an approximation for a defined
function f(x) given an initial guess for x and a value h (distance from x).

**Usage/Example:**

The function returns an approximation for the derivative of a defined function f(x) at a given value of x.
As the value h moves toward zero, the approximation will increase in accuracy. The code below computes the
derivative with h starting at 1.0 and then halfing the value of h until a specified accuracy is reached or
a specified itteration count is reached. The function does have limitations as shown in the data output.
Some funcions will converge as expected toward the derivative and other functions start converging toward
the derivative and then diverge giving unexpected results.

    #include <stdio.h>
    #include <math.h>
    #include <mylib.h>
    
    int main() {
        double Pi = 3.1415926535897932384626433832795028841971693993751058209749445923;
        int i = 0, j = 0, maxIteration = 0;
        int ipow = 0;
        double eps = 0.0;
        double x = 0.0;
        double h = 0.0;
        double fxx = 0.0;
        double expder = 0.0;
        double eabsolute = 0.0;
        double erelative = 0.0;
    
        //***************************************************************************************
        //*******************  approximation d/dx(x^2 + 3) at x = 2.0  **************************
        //***************************************************************************************
        x = 2.0;
        h = 1.0;
        maxIteration = 55;
        expder = 4.0;
        dmaceps(&eps, &ipow);
        eabsolute = 1.0;
    
        printf("dmaceps =  %.8e\n", eps);
        printf("x = %lf\n", x);
        printf("d/dx(x^2 + 3) = %.12lf\n\n", expder);
    
        printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
        printf("--------------------------------------------------------------------------------------------\n");
    
        while ( (eabsolute > eps) && maxIteration > 0 ) {
    
            maxIteration--;
            i++;
    
            fxx = derivative(fnct1, x, h);
    
            eabsolute = eabs(fxx, expder);
            erelative = erel(fxx, expder);
    
            printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fxx, h, eabsolute, erelative);
            h = h / 2.0;
    
        }
        printf("\n\n\n");
    
        //***************************************************************************************
        //*******************  approximation for d/dx(e^x) at x = 2.0  **************************
        //***************************************************************************************
    
        expder = 7.38905609893;
        eabsolute = 1.0;
        x = 2.0;
        h = 1.0;
        i = 0;
        maxIteration = 55;
    
        dmaceps(&eps, &ipow);
    
        printf("dmaceps =  %.8e\n", eps);
        printf("x = %lf\n", x);
        printf("d/dx(e^x) = %.12lf\n\n", expder);
    
        printf("i\t| appoximate derivative\t\t| h\t\t| e absolute\t| e relative\n");
        printf("--------------------------------------------------------------------------------------------\n");
    
        while ( (eabsolute > eps) && maxIteration > 0 ) {
    
            maxIteration--;
            i++;
    
            fxx = derivative(exp, x, h);
    
            eabsolute = eabs(fxx, expder);
            erelative = erel(fxx, expder);
    
            printf("%d\t| %.8e\t\t| %.3e\t| %.3e\t| %.3e\n", i, fxx, h, eabsolute, erelative);
            h = h / 2.0;
    
        }
    
Output from the lines above:

    dmaceps =  1.11022302e-16
    x = 2.000000
    d/dx(x^2 + 3) = 4.000000000000

    i       | appoximate derivative         | h             | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 5.00000000e+00                | 1.000e+00     | 1.000e+00     | 2.500e-01
    2       | 4.50000000e+00                | 5.000e-01     | 5.000e-01     | 1.250e-01
    3       | 4.25000000e+00                | 2.500e-01     | 2.500e-01     | 6.250e-02
    4       | 4.12500000e+00                | 1.250e-01     | 1.250e-01     | 3.125e-02
    5       | 4.06250000e+00                | 6.250e-02     | 6.250e-02     | 1.563e-02
    6       | 4.03125000e+00                | 3.125e-02     | 3.125e-02     | 7.813e-03
    7       | 4.01562500e+00                | 1.563e-02     | 1.563e-02     | 3.906e-03
    8       | 4.00781250e+00                | 7.813e-03     | 7.813e-03     | 1.953e-03
    9       | 4.00390625e+00                | 3.906e-03     | 3.906e-03     | 9.766e-04
    10      | 4.00195313e+00                | 1.953e-03     | 1.953e-03     | 4.883e-04
    11      | 4.00097656e+00                | 9.766e-04     | 9.766e-04     | 2.441e-04
    12      | 4.00048828e+00                | 4.883e-04     | 4.883e-04     | 1.221e-04
    13      | 4.00024414e+00                | 2.441e-04     | 2.441e-04     | 6.104e-05
    14      | 4.00012207e+00                | 1.221e-04     | 1.221e-04     | 3.052e-05
    15      | 4.00006104e+00                | 6.104e-05     | 6.104e-05     | 1.526e-05
    16      | 4.00003052e+00                | 3.052e-05     | 3.052e-05     | 7.629e-06
    17      | 4.00001526e+00                | 1.526e-05     | 1.526e-05     | 3.815e-06
    18      | 4.00000763e+00                | 7.629e-06     | 7.629e-06     | 1.907e-06
    19      | 4.00000381e+00                | 3.815e-06     | 3.815e-06     | 9.537e-07
    20      | 4.00000191e+00                | 1.907e-06     | 1.907e-06     | 4.768e-07
    21      | 4.00000095e+00                | 9.537e-07     | 9.537e-07     | 2.384e-07
    22      | 4.00000048e+00                | 4.768e-07     | 4.768e-07     | 1.192e-07
    23      | 4.00000024e+00                | 2.384e-07     | 2.384e-07     | 5.960e-08
    24      | 4.00000012e+00                | 1.192e-07     | 1.192e-07     | 2.980e-08
    25      | 4.00000006e+00                | 5.960e-08     | 5.960e-08     | 1.490e-08
    26      | 4.00000003e+00                | 2.980e-08     | 2.980e-08     | 7.451e-09
    27      | 4.00000000e+00                | 1.490e-08     | 0.000e+00     | 0.000e+00



    dmaceps =  1.11022302e-16
    x = 2.000000
    d/dx(e^x) = 7.389056098930

    i       | appoximate derivative         | h             | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 1.26964808e+01                | 1.000e+00     | 5.307e+00     | 7.183e-01
    2       | 9.58687572e+00                | 5.000e-01     | 2.198e+00     | 2.974e-01
    3       | 8.39471895e+00                | 2.500e-01     | 1.006e+00     | 1.361e-01
    4       | 7.87073111e+00                | 1.250e-01     | 4.817e-01     | 6.519e-02
    5       | 7.62485080e+00                | 6.250e-02     | 2.358e-01     | 3.191e-02
    6       | 7.50572220e+00                | 3.125e-02     | 1.167e-01     | 1.579e-02
    7       | 7.44708494e+00                | 1.563e-02     | 5.803e-02     | 7.853e-03
    8       | 7.41799491e+00                | 7.813e-03     | 2.894e-02     | 3.916e-03
    9       | 7.40350666e+00                | 3.906e-03     | 1.445e-02     | 1.956e-03
    10      | 7.39627667e+00                | 1.953e-03     | 7.221e-03     | 9.772e-04
    11      | 7.39266521e+00                | 9.766e-04     | 3.609e-03     | 4.884e-04
    12      | 7.39086036e+00                | 4.883e-04     | 1.804e-03     | 2.442e-04
    13      | 7.38995816e+00                | 2.441e-04     | 9.021e-04     | 1.221e-04
    14      | 7.38950711e+00                | 1.221e-04     | 4.510e-04     | 6.104e-05
    15      | 7.38928160e+00                | 6.104e-05     | 2.255e-04     | 3.052e-05
    16      | 7.38916885e+00                | 3.052e-05     | 1.127e-04     | 1.526e-05
    17      | 7.38911247e+00                | 1.526e-05     | 5.637e-05     | 7.629e-06
    18      | 7.38908429e+00                | 7.629e-06     | 2.819e-05     | 3.815e-06
    19      | 7.38907019e+00                | 3.815e-06     | 1.409e-05     | 1.907e-06
    20      | 7.38906315e+00                | 1.907e-06     | 7.047e-06     | 9.536e-07
    21      | 7.38905962e+00                | 9.537e-07     | 3.523e-06     | 4.768e-07
    22      | 7.38905786e+00                | 4.768e-07     | 1.761e-06     | 2.383e-07
    23      | 7.38905698e+00                | 2.384e-07     | 8.817e-07     | 1.193e-07
    24      | 7.38905654e+00                | 1.192e-07     | 4.421e-07     | 5.983e-08
    25      | 7.38905631e+00                | 5.960e-08     | 2.111e-07     | 2.857e-08
    26      | 7.38905621e+00                | 2.980e-08     | 1.068e-07     | 1.446e-08
    27      | 7.38905615e+00                | 1.490e-08     | 4.721e-08     | 6.390e-09
    28      | 7.38905609e+00                | 7.451e-09     | 1.239e-08     | 1.677e-09
    29      | 7.38905597e+00                | 3.725e-09     | 1.316e-07     | 1.781e-08
    30      | 7.38905621e+00                | 1.863e-09     | 1.068e-07     | 1.446e-08
    31      | 7.38905621e+00                | 9.313e-10     | 1.068e-07     | 1.446e-08
    32      | 7.38905525e+00                | 4.657e-10     | 8.469e-07     | 1.146e-07
    33      | 7.38905716e+00                | 2.328e-10     | 1.060e-06     | 1.435e-07
    34      | 7.38905334e+00                | 1.164e-10     | 2.754e-06     | 3.727e-07
    35      | 7.38905334e+00                | 5.821e-11     | 2.754e-06     | 3.727e-07
    36      | 7.38903809e+00                | 2.910e-11     | 1.801e-05     | 2.438e-06
    37      | 7.38903809e+00                | 1.455e-11     | 1.801e-05     | 2.438e-06
    38      | 7.38903809e+00                | 7.276e-12     | 1.801e-05     | 2.438e-06
    39      | 7.38891602e+00                | 3.638e-12     | 1.401e-04     | 1.896e-05
    40      | 7.38916016e+00                | 1.819e-12     | 1.041e-04     | 1.408e-05
    41      | 7.38867188e+00                | 9.095e-13     | 3.842e-04     | 5.200e-05
    42      | 7.38867188e+00                | 4.547e-13     | 3.842e-04     | 5.200e-05
    43      | 7.38671875e+00                | 2.274e-13     | 2.337e-03     | 3.163e-04
    44      | 7.39062500e+00                | 1.137e-13     | 1.569e-03     | 2.123e-04
    45      | 7.39062500e+00                | 5.684e-14     | 1.569e-03     | 2.123e-04
    46      | 7.37500000e+00                | 2.842e-14     | 1.406e-02     | 1.902e-03
    47      | 7.37500000e+00                | 1.421e-14     | 1.406e-02     | 1.902e-03
    48      | 7.37500000e+00                | 7.105e-15     | 1.406e-02     | 1.902e-03
    49      | 7.25000000e+00                | 3.553e-15     | 1.391e-01     | 1.882e-02
    50      | 7.50000000e+00                | 1.776e-15     | 1.109e-01     | 1.501e-02
    51      | 7.00000000e+00                | 8.882e-16     | 3.891e-01     | 5.265e-02
    52      | 6.00000000e+00                | 4.441e-16     | 1.389e+00     | 1.880e-01
    53      | 0.00000000e+00                | 2.220e-16     | 7.389e+00     | 1.000e+00
    54      | 0.00000000e+00                | 1.110e-16     | 7.389e+00     | 1.000e+00
    55      | 0.00000000e+00                | 5.551e-17     | 7.389e+00     | 1.000e+00

First the derivative function was used to approximate the derivative of x^2 + 3 at x = 2.0 and the
approximation converged to an approximate value of 4.0 which is correct. Next the dirivative function
was used to approximate the derivative of e^x at x = 2.0 and the approximation converged to an expected
approximate value of 7.38905609893 with an absolute error of 1.239e-08. After this the approximation
produced unexpected results with an increase in the absolute error.

**Implementation/Code:** The following is the code for smaceps()

    double derivative(double(*f)(double), double x, double h) {
        double fxx = 0.0;
        fxx = (f(x + h) - f(x)) / (h);
        return fxx;
    }

**Last Modified:** September/2018
