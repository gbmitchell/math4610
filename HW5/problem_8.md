# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 8.

**Routine Name:**           gaussSeidelParallel

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    gauss_seidel_Parallel.c

will produce an executable **gauss_seidel_Parallel.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Gauss-Seidel iteration. This version of Gauss-Seidel iteration uses openMP to execute matrix vector operations in parallel in an effort to decrease the amount of time it takes to compute a solution.

**Input:** There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Gauss-Seidel iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.

**Usage/Example:**

There are six inputs needed in this case to solve the problem Ax=b. A square matrix A, a vector of unkown values x, a vector of given values b, a tol for error, a maxiter value to stop infinite loops, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Gauss-Seidel iteration to store the solution values in the vector x. The solution for the values of the vector x can then be used in the main program as needed.



Output from the lines above:



The output shows the matrix A augmented with vector b. Gauss-Seidel completed after 7 iterations and produced the expected solution vector x containing all ones.

**Implementation/Code:** The following is the code for gaussSeidelParallel()



**Last Modified:** November/2018
