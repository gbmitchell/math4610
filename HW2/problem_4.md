# Math 4610 Fundamentals of Computational Mathematics
Homework 2 problem 4.

**Routine Name:**           fixed1, fixed2

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** These functions will compute an approximation for a root of a defined
function f(x) given an initial guess for the value of x. The function fixed1 takes the form of
g(x) = x + f(x) and the function fixed2 takes the form g(x) = x - f(x). These can then be used
for itteratoin g(Xn+1) = Xn + f(Xn) or g(Xn+1) = Xn - f(Xn) to approximate the root of a defined
function f(x). 

**Input:** There are two inputs needed in these cases. A defined function f(x) and an initial guess
for the value of x are arguments passed to the functions as inputs.

**Output:** The functions return a double precision value that represents an approximation for the
root of a defined function f(x) given an initial guess for x.

**Usage/Example:**

The functions return an approximation for the root of a defined function f(x) at a guess for the value of x.
The goal is to find a function g(x) = x and recursivly itterate the function until an approximate root is
found within an acceptable tolerance. The code below uses two defined functions, f(x) = x^2 - 3 and f(x) =
sin(Pi * x) as functions to find the roots of. To find the funcion g(x) = x, the function f(x) is set equal
to zero and either add or subtract x to both sides of the equation. The result is an equation in the form of
X(n+1) = X(n) + C that can be itterated until X(n+1) is approximatly equal to X(n).


    
Output from the lines above:

    

First the deriv

**Implementation/Code:** The following is the code for fixed1()

    double fixed1(double(*f)(double), double xn) {

        double fxn1 = 0.0;
        fxn1 = xn + f(xn);
        return fxn1;
    }


**Implementation/Code:** The following is the code for fixed2()
    double fixed2(double(*f)(double), double xn) {
    
        double fxn1 = 0.0;
	fxn1 = xn - f(xn);
	return fxn1;
    }
   
**Last Modified:** September/2018
