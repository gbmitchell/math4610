# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           parallelMatrixXmatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will take a matrix and multiply it by another matrix in double precision. In this case, the matrices are 3x3. This function also uses parallel execution of the multiplication process to perform the operation in less time making use of the computers multiple core resources. The process is split up between three threads, each row of the resulting matrix C is computed by a different thread.

**Input:** There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix A by matrix B.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix A by matrix B. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix A by matrix B. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix A by matrix B. The resulting matrix C can then be used in the main program as needed.

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
		
		parallelMatrixXmatrix(A, B, C, m, n);

		printf("\n\nMatrix C = A * B\n");

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				printf("%.3lf\t", C[i][j]);
			}
			printf("\n");
		}
	}    

Output from the lines above:

    Matrix A =
    2.000   4.000   6.000
    8.000   10.000  12.000
    14.000  16.000  18.000
    
    Matrix B =
    1.000   3.000   5.000
    7.000   9.000   11.000
    13.000  15.000  17.000
    
    A[0][0] * B[0][0], thread 1
    A[1][0] * B[0][0], thread 2
    A[1][1] * B[1][0], thread 2
    A[2][0] * B[0][0], thread 3
    A[1][2] * B[2][0], thread 2
    A[2][1] * B[1][0], thread 3
    A[1][0] * B[0][1], thread 2
    A[0][1] * B[1][0], thread 1
    A[1][1] * B[1][1], thread 2
    A[2][2] * B[2][0], thread 3
    A[1][2] * B[2][1], thread 2
    A[0][2] * B[2][0], thread 1
    A[1][0] * B[0][2], thread 2
    A[2][0] * B[0][1], thread 3
    A[1][1] * B[1][2], thread 2
    A[2][1] * B[1][1], thread 3
    A[1][2] * B[2][2], thread 2
    A[0][0] * B[0][1], thread 1
    A[0][1] * B[1][1], thread 1
    A[2][2] * B[2][1], thread 3
    A[0][2] * B[2][1], thread 1
    A[2][0] * B[0][2], thread 3
    A[0][0] * B[0][2], thread 1
    A[2][1] * B[1][2], thread 3
    A[0][1] * B[1][2], thread 1
    A[2][2] * B[2][2], thread 3
    A[0][2] * B[2][2], thread 1

    Matrix C = A * B
    108.000 132.000 156.000
    234.000 294.000 354.000
    360.000 456.000 552.000

The output shows the values for matrix C which is the result of A * B. Just above the result are lines showing each of the matrix multiplication operations and which thread did the multiplication of that particular element of the matrix.

**Implementation/Code:** The following is the code for parallelMatrixXmatrix()

	void parallelMatrixXmatrix(double A[3][3], double B[3][3], double C[3][3], int m, int n) {

		int i, j, k = 0;
		int id = 0;

		// begin parallel threads
		#pragma omp parallel private(id, i, j, k)
		{
			id = omp_get_thread_num();

			if (id == 1) {
				for (i = 0; i < m; i++) {
					C[0][i] = 0;
					for (j = 0; j < n; j++) {
						C[0][i] = C[0][i] + (A[0][j] * B[j][i]);
						printf("A[0][%d] * B[%d][%d], thread %d\n", j, j, i, id);
					}
				}
			}

			if (id == 2) {
				for (i = 0; i < m; i++) {
					C[1][i] = 0;
					for (j = 0; j < n; j++) {
						C[1][i] = C[1][i] + (A[1][j] * B[j][i]);
						printf("A[1][%d] * B[%d][%d], thread %d\n", j, j, i, id);
					}
				}
			}

			if (id == 3) {
				for (i = 0; i < m; i++) {
					C[2][i] = 0;
					for (j = 0; j < n; j++) {
						C[2][i] = C[2][i] + (A[2][j] * B[j][i]);
						printf("A[2][%d] * B[%d][%d], thread %d\n", j, j, i, id);
					}
				}
			}
		}
	}

**Last Modified:** October/2018
