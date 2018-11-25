# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 3.

**Routine Name:**           Choleskysolve

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will solve a linear system Ax=b by use of Cholesky decomposition, forward substitution, and back substitution. Cholesky decomposition will separate the matrix A into upper U and lower L triangular matrices such that A=LU=L(Ltranspose). The Upper triangular matrix U is the transpose of the lower triangular matrix L. The problem can then be writen as LUx=b. Using Ux=y, the problem can be writen as Ly=b and then forward substitution is used to solve for the unknown values of the vector y. After solving for the values of the vector y, back substitution is used to solve for the unkown values of vector x in the problem Ux=y, thus solving the unknown values for the vector x in the original problem of Ax=b.

**Input:** There are five inputs needed in this case to solve the problem Ax=b. A square matrix A, a square matrix U, a vector of unkown values x, a vector of given values b, and a value to indicate the size of the matrices and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it uses Cholesky decomposition to store the values for the lower triangular matrix in the original matrix A and stores the upper triangular matrix values in the matrix U. After forward and back solving, the solution for the values of the vector x are updated and can be used as needed.

**Usage/Example:**

There are five inputs needed in this case to solve the problem Ax=b. A square matrix H, a square matrix HU, a vector of unkown values xh, a vector of given values bh, and a value to indicate the size of the matrices and vectors (n). The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it uses Cholesky decomposition to store the values for the lower triangulare matrix in the original matrix H and stores the upper triangular matrix values in the matrix HU. After forward and back solving, the solution for the values of the vector xh are updated and can be used as needed. The process is repeated for the 5x5 matrix P as well.



Output from the lines above:



The output from the example code prints the values for the 7x7 square matrix H augmented with the known values of the vector bh. The routine then executes Cholesky decomposition followed by forward and back substitution to solve for the values in the vector of unknowns and stores those values in the vector xh. The stored values are then printed as the solution to the problem Hx=b. The process is then repeated using a 5x5 matrix P.

**Implementation/Code:** The following is the code for Choleskysolve()



**Last Modified:** November/2018
