# Math 4610 Fundamentals of Computational Mathematics
Homework 5 problem 2.

**Routine Name:**           matrixInducedNormInfinity

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixInducedNorms.c

will produce an executable **matrixInducedNorms.exe** that can be executed.

**Description/Purpose:** This function will compute a double precision value for the induced Infinity-norm given a matrix A and a vector v. The induced Infinity-norm of a matrix is used to give some sense of a magnitude for the given matrix. The induced Infinity-norm for a matrix A is computed by multiplying the matrix A by the vector v and computing the Infinity-norm of the resulting vector. The resulting Infinity-norm is then divided by the Infinity-norm of the vector v. Writen another way, the induced Infinity-norm for a matrix A is ||Av||/||v||.

**Input:** There are three inputs needed in this case. The matrix A and vector v are passed to the function by reference. An argument n is also passed to the function, n represents the size of the matrix and vector.

**Output:** The function returns a double precision value inducedNorm which represents the induced Infinity-norm of the input matrix A.

**Usage/Example:**

There are three inputs needed in this case. The matrix A and vector v are passed to the function by reference. An argument n is also passed to the function, n represents the size of the matrix and vector. The function returns a double precision value inducedNorm which represents the induced Infinity-norm of the input matrix A.



Output from the lines above:

  Uniform diagnaly dominent matrix A augmented with vector b =
  1.854e+00       1.080e-01       1.340e-01       6.430e-01       1.340e-01       7.380e-01       8.700e-02       |3.698e+00
  1.080e-01       1.940e+00       9.070e-01       1.610e-01       3.290e-01       2.160e-01       2.090e-01       |3.870e+00
  1.340e-01       9.070e-01       4.125e+00       7.090e-01       8.380e-01       9.040e-01       6.230e-01       |8.240e+00
  6.430e-01       1.610e-01       7.090e-01       3.378e+00       4.970e-01       8.300e-01       5.280e-01       |6.746e+00
  1.340e-01       3.290e-01       8.380e-01       4.970e-01       3.443e+00       9.700e-01       6.650e-01       |6.876e+00
  7.380e-01       2.160e-01       9.040e-01       8.300e-01       9.700e-01       3.892e+00       2.240e-01       |7.774e+00
  8.700e-02       2.090e-01       6.230e-01       5.280e-01       6.650e-01       2.240e-01       2.346e+00       |4.682e+00

The output show the computed induced Infinity-norm of matrix A is 33.33.

**Implementation/Code:** The following is the code for matrixInducedNormInfinity()



**Last Modified:** November/2018
