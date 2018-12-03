# Math 4610 Fundamentals of Computational Mathematics
Homework 6 problem 6.

**Routine Name:**           conditionNumberParallel

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    2conditionNumberParallel.c

will produce an executable **2conditionNumberParallel.exe** that can be executed.

**Description/Purpose:** This routine will compute the largest eigenvalue of a matrix A and the largest eigenvalue of the matrix inverse A^(-1). The L2-Norm is used in computing the eigenvalues and by multiplying the two eigenvalues together, the product is a 2 condition number or factor of the 2 condition number.

**Input:** There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference.

**Output:** This routine returns a double precision value that represents the 2 condition number of the matrix A.

**Usage/Example:**

There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference. This routine returns a double precision value that represents the 2 condition number of the matrix A.



Output from the lines above:



The output shows the matrix A and the 2 condition number of matrix A.

**Implementation/Code:** The following is the code for conditionNumber()



**Last Modified:** November/2018
