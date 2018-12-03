# Math 4610 Fundamentals of Computational Mathematics
Homework 6 problem 2.

**Routine Name:**           inversePowerMethod

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    inversePowerMethod.c

will produce an executable **inversePowerMethod.exe** that can be executed.

**Description/Purpose:** This routine will compute the largest eigenvalue of a matrix.

**Input:** There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference.

**Output:** This routine returns a double precision value that represents the largest eigenvalue of the matrix A.

**Usage/Example:**

There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference. This routine returns a double precision value that represents the largest eigenvalue of the matrix A.



Output from the lines above:



The output shows the matrix A, the largest eigenvalue of matrix A, and the number of iterations it took to compute the eigenvalue.

**Implementation/Code:** The following is the code for inversePowerMethod()



**Last Modified:** November/2018
