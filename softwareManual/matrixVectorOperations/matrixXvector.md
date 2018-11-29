# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           vectorXmatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixXvector.c

will produce an executable **matrixXvector.exe** that can be executed.

**Description/Purpose:** This function will take a matrix and multiply it by a vector in double precision. In this case, the matrix is a 3x3 and the vector is a 3x1 and the result is a 3x1 vector.

**Input:** There are five inputs needed in this case. Matrix A, vector u, and vector v are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrix and vectors. The real purpose is to produce values in the vector u that represent the result of multiplying the matrix A by the vector v.

**Output:** This function doesnt return a value. Because the vector u was passed by reference, the function can modify the vector u to produce the result of multiplying the matrix A by the vector v. The resulting vector u can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, vector u, and vector v are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrix and vectors. The real purpose is to produce values in the vector u that represent the result of multiplying the matrix A by the vector v. This function doesnt return a value. Because the vector u was passed by reference, the function can modify the vector u to produce the result of multiplying the matrix A by the vector v. The resulting vector u can then be used in the main program as needed.

	#include "mylib.h"
	#include <stdio.h>
	#include <stdlib.h>

	int main() {
		int i, j, k = 0;
		int m = 3; // rows
		int n = 3; // col

		// alloc memory for a matrix
		double **A;
		A = calloc(m, sizeof(double*));

		for (i = 0; i < m; i++)
		{
			A[i] = calloc(n, sizeof(double));
		}

		// alloc memory for a vector
		double *v;
		v = calloc(n, sizeof(double));

		// alloc memory for a vector
		double *u;
		u = calloc(n, sizeof(double));

		// assign even values to matrix A
		k = 1;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				A[i][j] = k * 2;
				k++;
			}
		}

		// assign even values to vector v
		k = 1;
		for (i = 0; i < n; i++) {
				v[i] = k;
				k++;
		}

		printf("\n\nMatrix A =\n");

		printMatrix(A, m, n);

		printf("\n\nVector v =\n");

		printVector(v, n);

		vectorXmatrix(A, v, u, m, n);

		printf("\n\nVector u = A * v\n");

		printVector(u, n);

		// free memory
		for (i = 0; i < m; i++)
		{
			free(A[i]);
		}

		free(A);

		free(v);

		free(u);

		return 0;
	}    

Output from the lines above:

	Matrix A =
	2.000e+00       4.000e+00       6.000e+00
	8.000e+00       1.000e+01       1.200e+01
	1.400e+01       1.600e+01       1.800e+01

	Vector v =
	1.000e+00
	2.000e+00
	3.000e+00

	Vector u = A * v
	2.800e+01
	6.400e+01
	1.000e+02

The output shows the values for matrix A, the values for vector v, and the values for vector u as a result of multiplying A * v.

**Implementation/Code:** The following is the code for vectorXmatrix()

	void vectorXmatrix(double **A, double *v, double *u, int m, int n) {
		int i, j = 0;
		for (i = 0; i < m; i++) {
			u[i] = 0;
			for (j = 0; j < n; j++) {
				u[i] = u[i] + (A[i][j] * v[j]);
			}
		}
	}

**Last Modified:** November/2018
