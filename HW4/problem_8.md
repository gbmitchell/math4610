# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 8.

**Routine Name:**           squareLU

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will carry out LU decomposition of a square matrix. LU decomposition is the process of separating a matrix A into upper (U) and lower (L) triangular matrices such that A=LU.

**Input:** There are three inputs needed in the case of the LU decomposition routine. A square matrix A, a square matrix L, and a value to indicate the size of the matrices. The matrices are passed to the routine by reference and the values for matrix A are separated into a lower and upper triangular matrix. The upper triangular matrix values are computed and stored in matrix A by over writing the original values. The lower triangular matrix values are computed and stored in the matrix L. 

**Output:** This routine does not return anything, instead it changes the values for the matrix A to be the upper triangular matrix and changes the values in the matrix L to be the lower triangular matrix.

**Usage/Example:**

There are three inputs needed in this case of the LU decomposition routine. A square matrix (D), a square matrix (L), and a value to indicate the size of the matrices (n). The matrices are passed to the routine by reference and the values for matrix D are separated into a lower and upper triangular matrix. The upper triangular matrix values are computed and stored in matrix D by over writing the original values. The lower triangular matrix values are computed and stored in the matrix L.



Output from the lines above:



The output from the example code prints the values for the square matrix D to be sent through the LU decomposition process. After LU decompostion is executed, the values for the resulting upper and lower triangular matrices are printed.

**Implementation/Code:** The following is the code for squareLU()



**Last Modified:** November/2018
