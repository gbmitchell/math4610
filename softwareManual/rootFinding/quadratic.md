# Math 4610 Fundamentals of Computational Mathematics
Software Manual.

**Routine Name:**           quadratic

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    quadratic.c

will produce an executable **quadratic.exe** that can be executed.

**Description/Purpose:** This function will compute the quatdratic formula with double precision values.

**Input:** There are 6 arguments used for input to the function. 3 passed by reference are used as place
holders for return values from the function. A bool to indicate if the roots are imaginary and 2 doubles,
root1 and root2. Additionally, 3 nputs a, b, c are type double values input by the user and passed as
arguments to the routine. These values come from a polynomial in the form of,

    Y = a(x^2) + b(x) + c

**Output:** This function returns 2 double precision values for the calculated roots if they are not imaginary.
The function will also return a bool set true if the roots are imaginary and false if the roots are not imaginary.
If the roots are imaginary, the returned root values are not valid results and should be ignored.

**Usage/Example:**

The function has 6 arguments needed to produce the roots calculated using the quadratic equation.
Three arguments a, b, c are user input in double precision from a polynomial. Two arguments root1
and root2 are to return the root values in double precision. One bool argument is used to indicate
if the roots are imaginary or not.

    void quadratic(double a, double b, double c, double *root1, double *root2, bool *imaginary) {

        // check if roots are imaginary
        if ( ( ( b * b ) - ( 4 * a * c ) ) < 0.0 ) {

            *imaginary = true;

            return;
        }

        // calculate roots if not imaginary
        else {

            *imaginary = false;

            *root1 = ( -b + sqrt( ( b * b ) - (4.0 * a * c ) ) ) / ( 2.0 * a );

            *root2 = ( -b - sqrt( ( b * b ) - (4.0 * a * c ) ) ) / ( 2.0 * a );

            return;
        }
    }

Output from the lines above:

    Given    Y = a(x^2) + b(x) + c,   and a can not = 0,

    Input a value for a
    > 3

    Input a value for b
    > 20

    Input a value for c
    > 16

    You entered:
    a = 3.000000
    b = 20.000000
    c = 16.000000

    The roots are:
    root 1 = -0.929632
    root 2 = -5.737034

The output prints the user inputs along with the values calculated using the quadratic function.

**Implementation/Code:** The following is the code for quadratic()

    #include <stdio.h>
    #include <math.h>
    #include <stdbool.h>
    
    int main() {

        double a = 0.0, b = 0.0, c = 0.0, root1 = 0.0, root2 = 0.0;

        bool imaginary = false;

        // print out the quadratic formula
        printf(" Given    Y = a(x^2) + b(x) + c,   and a can not = 0,\n\n");

        // input values a, b, c for the quatratic fucntion
        printf("Input a value for a\n> ");
        scanf_s("%lf",&a);
        
        printf("\nInput a value for b\n> ");
        scanf_s("%lf", &b);

        printf("\nInput a value for c\n> ");
        scanf_s("%lf", &c);

        // call quadratic function with inputs,
        // return roots and bool imaginary true or false.
        quadratic(a, b, c, &root1, &root2, &imaginary);

        if (imaginary == true) {

            printf("\nYou entered:\na = %lf\nb = %lf\nc = %lf\n\n", a, b, c);

            printf("\nRoots are imaginary.\n\n");
        }
        else {

            printf("\nYou entered:\na = %lf\nb = %lf\nc = %lf\n\n", a, b, c);

            printf("\nThe roots are:\nroot 1 = %lf\nroot 2 = %lf\n\n", root1, root2);

        }

        return 0;
    }

**Last Modified:** September/2018
