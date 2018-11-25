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



The output shows the matrix A augmented with vector b. Gauss-Seidel completed after 7 iterations and produced the expected solution vector x containing all ones. The first solution vector x was computed with serial programing and took 0.0030 seconds. The second solution vector x was computed with parallel programing and took 0.025 seconds. The parallel version takes longer in the case of a 7x7 matrix because it takes some overhead to set up the parallel threads. Running the code again with a matrix size of 640x640 resulted in 314699 iterations. The serial program took 438.4 seconds while the parallel program took 129.5 seconds. It can be concluded that parallel programing is benificial in larger systems.

**Implementation/Code:** The following is the code for gaussSeidelParallel()



**Last Modified:** November/2018
