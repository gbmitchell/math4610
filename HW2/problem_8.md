# Math 4610 Fundamentals of Computational Mathematics
Homework 2, problem 8.

**Routine Name:**           expnewton

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** This function will compute an approximation for a root of a defined
function f(x) given f'(x) and an initial guess for the root. The newton root finding method
uses the derivative of f(x) at the initial guess for x to obtain a tangent line. Where the
tangent line crosses the x axis is the approximation for the root. Recusivly applying the new
approximation as a guess will converge to a root.

**Input:** There are six inputs needed in this cases. A defined function f(x), a defined function
f'(x), an initial guess for the root (initialGuess), a tolerance (eps), a maximum amount of times
to itterate (maxIteration), and the expected value of the root (exproot) to calculate the error for
analizing the newton method.

**Output:** The function returns a double precision value that represents an approximation for the
root of a defined function f(x) given f'(x) and an initial guess for the root.

**Usage/Example:**

The code below uses two defined functions, f(x) = x^2 - 3 and f(x) = sin(Pi * x) as functions to find
the roots of. The derivatives of the defined functions are d/dx( x^2 - 3 ) = ( 2 * x ) and
d/dx( sin(Pi * x) ) = ( Pi * cos(Pi * x) ). We know that x^2 - 3 has a root at sqrt(3) and sin(Pi * x)
has a root at 6.0. In the following code, initial guesses were given relativly close to these known
roots and error was calculated based on the known roots to analize the behavior of the newton method.

**Last Modified:** September/2018
