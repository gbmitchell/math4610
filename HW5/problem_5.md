# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 5.

**Routine Name:**           gradient

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    gradient.c

will produce an executable **gradient.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Jacobi iteration. Jacobi iteration provides an alternative way to solve a linear system. Iterative methods are an alternative to direct methods such as Gauss Elimination and LU Decomposition.

**Input:** There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Jacobi iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

**Usage/Example:**

There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Jacobi iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.



Output from the lines above:



The output shows the matrix A augmented with vector b. Jacobi iteration completed after 3173 iterations and produced the expected solution vector x containing all ones.

**Implementation/Code:** The following is the code for jacobi()



**Last Modified:** November/2018
