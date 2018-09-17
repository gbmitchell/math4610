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

**Input:** There are no inputs needed in this case. Arguments are passed by reference and the function will change their values.
The real purpose is to produce values in those variables to be used as needed.

**Output:** This function returns a single precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:**

The function has two arguments needed to produce the values of the precision in terms of the smallest number that can be
represented. Since the code is written in terms of a C function, the value of the machine epsilon (seps) is a single
precision value (float) and the power of two that gives the machine epsilon (ipow) is an integer. 

    #include <stdio.h>
    #include <math.h>
    
    int main() {
    
        // create and initialize arguments
        float seps = 1.0;
        int ipow = 0;
        
        // call smaceps function passing arguments by reference
        smaceps(&seps, &ipow);
        
        // print the resulting values to the console
        printf("\n%d\t%.8e", ipow, seps);
        
        // keeps the console open until a key is pressed
        getch();

        return 0;
    }

Output from the lines above:

      24    5.96046448e-08

The first value (24) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly eight (e-08 on the
end of the second value).

**Implementation/Code:** The following is the code for smaceps()

    double derivative(double(*f)(double), double x, double h) {
        double fxx = 0.0;
        fxx = (f(x + h) - f(x)) / (h);
        return fxx;
    }

**Last Modified:** September/2018
