# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 1a.

**Routine Name:**           matrixNormL1

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the L1-norm given a matrix. The function was developed to compute the L1-norm of a 3x3 matrix. The L1-norm is used to give some sense of a magnitude for the given matrix. The L1-norm for a matrix is computed by summing each column in the matrix and then indentifying which sum is maximum.

**Input:** There are two inputs needed in this case. The matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function.

**Output:** The function returns a double precision value max which represents the L1-norm of the input matrix.

**Usage/Example:**

There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function. The function returns a double precision value max which represents the L1-norm of the input matrix A. 



Output from the lines above:



The sum of column 1 is 2 + 8 + 14 = 24, the sum of column 2 is 4 + 10 + 16 = 30, and the sum of column 3 is 6 + 12 + 18 = 36.
The max of these sums is 36, therefore the L1-norm is 36.

**Implementation/Code:** The following is the code for matrixNormL1()



# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 1b.

**Routine Name:**           matrixNormInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the Infinity-norm given a matrix. The function was developed to compute the Infinity-norm of a 3x3 matrix. The Infinity-norm is used to give some sense of a magnitude for the given matrix. The Infinity-norm for a matrix is computed by summing each row in the matrix and then indentifying which sum is maximum.

**Input:** There are two inputs needed in this case. The matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function.

**Output:** The function returns a double precision value max which represents the Infinity-norm of the input matrix.

**Usage/Example:**

There are two inputs needed in this case. The Matrix A is passed to the function by reference. An argument for the size of the matirx n is also passed to the function. The function returns a double precision value max which represents the Infinity-norm of the input matrix A.



Output from the lines above:



The sum of row 1 is 2 + 4 + 6 = 12, the sum of row 2 is 8 + 10 + 12 = 30, and the sum of row 3 is 14 + 16 + 18 = 48.
The max of these sums is 48, therefore the Infinity-norm is 48.

**Implementation/Code:** The following is the code for matrixNormInfinity()



**Last Modified:** November/2018
