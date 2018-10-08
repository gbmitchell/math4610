# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           parallelVectorXmatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will take a matrix and multiply it by a vector in double precision. In this case, the matrix is a 3x3 and the vector is a 3x1 and the result is a 3x1 vector. This function also uses parallel execution of the multiplication process to perform the operation in less time making use of the computers multiple core resources. The process is split up between three threads, each element of the resulting vector u is computed by a different thread.

**Input:** There are five inputs needed in this case. Matrix A, vector u, and vector v are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrix and vectors. The real purpose is to produce values in the vector u that represent the result of multiplying the matrix A by the vector v.

**Output:** This function doesnt return a value. Because the vector u was passed by reference, the function can modify the vector u to produce the result of multiplying the matrix A by the vector v. The resulting vector u can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, vector u, and vector v are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrix and vectors. The real purpose is to produce values in the vector u that represent the result of multiplying the matrix A by the vector v. This function doesnt return a value. Because the vector u was passed by reference, the function can modify the vector u to produce the result of multiplying the matrix A by the vector v. The resulting vector u can then be used in the main program as needed.

	#include "mylib.h"
	
	int main() {
		int i = 0;
		int j = 0;
		int m = 3; // rows
		int n = 3; // col
		double v[3] = { 1, 2, 3 };
		double u[3] = { 0 };
		double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
		
		printf("\n\nMatrix A =\n");
		
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				printf("%.3lf\t", A[i][j]);
			}
			printf("\n");
		} 
		
		printf("\n\nVector v =\n");
		
		for (i = 0; i < m; i++) {
			printf("%.3lf\n", v[i]);
		}
		
		parallelVectorXmatrix(A, v, u, m, n);
		
		printf("\n\nVector u = A * v\n");
		
		for (i = 0; i < m; i++) {
			printf("%.3lf\n", u[i]);
		}
	}    

Output from the lines above:

    Matrix A =
    2.000   4.000   6.000
    8.000   10.000  12.000
    14.000  16.000  18.000
    
    Vector v =
    1.000
    2.000
    3.000
    
    A[2][0] * v[0], thread 3
    A[1][0] * v[0], thread 2
    A[2][1] * v[1], thread 3
    A[0][0] * v[0], thread 1
    A[0][1] * v[1], thread 1
    A[0][2] * v[2], thread 1
    A[1][1] * v[1], thread 2
    A[1][2] * v[2], thread 2
    A[2][2] * v[2], thread 3

    Vector u = A * v
    28.000
    64.000
    100.000

The output shows the values for vector u which is the result of A * v. Just above the result are lines showing each of the matrix multiplied by vector elements and which thread did the multiplication of that particular element.

**Implementation/Code:** The following is the code for parallelVectorXmatrix()

	void parallelVectorXmatrix(double A[3][3], double v[3], double u[3], int m, int n) {

		int i = 0;
		int id = 0;

		// begin parallel threads
	#pragma omp parallel private(id, i)
		{
			id = omp_get_thread_num();

			if (id == 1) {
				u[0] = 0;
				for (i = 0; i < m; i++) {
					u[0] = u[0] + (A[0][i] * v[i]);
					printf("A[0][%d] * v[%d], thread %d\n", i, i, id);
				}
			}

			if (id == 2) {
				u[1] = 0;
				for (i = 0; i < m; i++) {
					u[1] = u[1] + (A[1][i] * v[i]);
					printf("A[1][%d] * v[%d], thread %d\n", i, i, id);
				}
			}

			if (id == 3) {
				u[2] = 0;
				for (i = 0; i < m; i++) {
					u[2] = u[2] + (A[2][i] * v[i]);
					printf("A[2][%d] * v[%d], thread %d\n", i, i, id);
				}
			}
		}
	}

**Last Modified:** October/2018
