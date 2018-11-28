# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           parallelMatrixXmatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixXmatrixParallel.c

will produce an executable **matrixXmatrixParallel.exe** that can be executed.

**Description/Purpose:** This function will take a matrix and multiply it by another matrix in double precision. The matrices must be the same size, in this case, the matrices are 500x500. This function also uses parallel execution of the multiplication process to perform the operation in less time making use of the computers multiple core resources. The process is split up between three threads, each row of the resulting matrix C is computed by a different thread.

**Input:** There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix A by matrix B.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix A by matrix B. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, B, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix A by matrix B. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix A by matrix B. The resulting matrix C can then be used in the main program as needed.

	#include "mylib.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>


	int main() {
		clock_t start, end;
		double cpu_time_used;

		int i, j, k = 0;
		int m = 500; // rows
		int n = 500; // col


		// alloc memory for a matrix
		double **A;
		A = calloc(m, sizeof(double*));

		for (i = 0; i < m; i++)
		{
			A[i] = calloc(n, sizeof(double));
		}

		// alloc memory for a matrix
		double **B;
		B = calloc(m, sizeof(double*));

		for (i = 0; i < m; i++)
		{
			B[i] = calloc(n, sizeof(double));
		}

		// alloc memory for a matrix
		double **C;
		C = calloc(m, sizeof(double*));

		for (i = 0; i < m; i++)
		{
			C[i] = calloc(n, sizeof(double));
		}

		// assign even values to matrix A
		k = 1;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				A[i][j] = k * 2;
				k++;
			}
		}

		// assign odd values to matrix B
		k = 1;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				B[i][j] = (k * 2) - 1;
				k++;
			}
		}

		start = clock();

		matrixXmatrix(A, B, C, m, n); // serial multiply

		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

		printf("\n\nTime to complete serial operation = %.3e\n", cpu_time_used);

		start = clock();

		parallelMatrixXmatrix(A, B, C, m, n); // parallel multiply

		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

		printf("\n\nTime to complete parallel operation = %.3e\n", cpu_time_used);

		// free memory
		for (i = 0; i < m; i++)
		{
			free(A[i]);
		}

		free(A);

		// free memory
		for (i = 0; i < m; i++)
		{
			free(B[i]);
		}

		free(B);

		// free memory
		for (i = 0; i < m; i++)
		{
			free(C[i]);
		}

		free(C);

		return 0;
	}    

Output from the lines above:

	Time to complete serial operation = 8.040e-01

	Time to complete parallel operation = 3.000e-03

The output shows the time difference it took to compute a 500x500 matrix A multiplyed by a 500x500 matrix B in series vs parallel. It took significantly less time using a parallel version of matrix multiplication. 

**Implementation/Code:** The following is the code for parallelMatrixXmatrix()

	void parallelMatrixXmatrix(double **A, double **B, double **C, int m, int n) {

		int i, j = 0;
		int id = 0;

		// begin parallel threads
	#pragma omp parallel private(id, i, j)
		{
			id = omp_get_thread_num();

			if (id == 1) {
				for (i = 0; i < m; i++) {
					C[0][i] = 0;
					for (j = 0; j < n; j++) {
						C[0][i] = C[0][i] + (A[0][j] * B[j][i]);
						//printf("A[0][%d] * B[%d][%d], thread %d\n", j, j, i, id);
					}
				}
			}

			if (id == 2) {
				for (i = 0; i < m; i++) {
					C[1][i] = 0;
					for (j = 0; j < n; j++) {
						C[1][i] = C[1][i] + (A[1][j] * B[j][i]);
						//printf("A[1][%d] * B[%d][%d], thread %d\n", j, j, i, id);
					}
				}
			}

			if (id == 3) {
				for (i = 0; i < m; i++) {
					C[2][i] = 0;
					for (j = 0; j < n; j++) {
						C[2][i] = C[2][i] + (A[2][j] * B[j][i]);
						//printf("A[2][%d] * B[%d][%d], thread %d\n", j, j, i, id);
					}
				}
			}
		}
	}

**Last Modified:** November/2018
