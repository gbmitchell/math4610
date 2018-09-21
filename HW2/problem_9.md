# Math 4610 Fundamentals of Computational Mathematics
Homework 2, problem 9.

**Routine Name:**           expSecantHybrid

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** This function will compute an approximation for a root of a defined
function f(x) given f'(x) and two initial values for an interval on which a root exists. The
hybrid newton root finding method starts with one iteration of the newton method. If the value
from the first iteration of the newton method does not fall within the interval specified then
bisection is implimented to narrowthe interval by an error of about 10^(-1). Another iteration
of newtons method is done and if the result falls within the narrowed interval then newtons
method is used to finish the approximation to an error of 10^(-10). The idea is to bring the
interval close enough with bisection and then finish with newtons method to find the root faster
than just using bisection.

**Input:** There are seven inputs needed in this cases. A defined function f(x), a defined function
f'(x), two initial values for an interval on which a root exisits (initialGuess, initialGuess1), a
tolerance (prec10), a maximum amount of times to itterate (maxIteration), and the expected value of
the root (exproot) to calculate the error for analizing the hybrid newton method.

**Output:** The function returns a double precision value that represents an approximation for the
root of a defined function f(x) given f'(x) and two initial values for an interval on which a root
exisits.

**Usage/Example:**

The code below uses two defined functions, f(x) = x^2 - 3 and f(x) = sin(Pi * x) as functions to find
the roots of. The derivatives of the defined functions are d/dx( x^2 - 3 ) = ( 2 * x ) and
d/dx( sin(Pi * x) ) = ( Pi * cos(Pi * x) ). We know that x^2 - 3 has a root at sqrt(3) and sin(Pi * x)
has a root at 3.0. In the following code, initial values were given for an interval on which the known
root exists for each function. The approximate roots and error was calculated based on the known roots
to analize the behavior of the hybrid newton method.

    int main() {

        int  maxIteration = 0;
        double root = 0.0;
        double exproot = 0.0;
        double initialGuess = 0.0;
        double initialGuess1 = 0.0;
        double prec10 = 0.0000000001;

**Last Modified:** September/2018
