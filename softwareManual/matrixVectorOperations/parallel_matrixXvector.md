# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           parallelVectorXmatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matricXvectorParallel.c

will produce an executable **matricXvectorParallel.exe** that can be executed.

**Description/Purpose:** This function will take a matrix and multiply it by a vector in double precision. In this case, the matrix is a 15000x15000 and the vector is a 15000x1 and the result is a 15000x1 vector. This function also uses parallel execution of the multiplication process to perform the operation in less time making use of the computers multiple core resources. The process is split up between three threads, each element of the resulting vector u is computed by available threads.

**Input:** There are five inputs needed in this case. Matrix A, vector u, and vector v are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrix and vectors. The real purpose is to produce values in the vector u that represent the result of multiplying the matrix A by the vector v.

**Output:** This function doesnt return a value. Because the vector u was passed by reference, the function can modify the vector u to produce the result of multiplying the matrix A by the vector v. The resulting vector u can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix A, vector u, and vector v are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrix and vectors. The real purpose is to produce values in the vector u that represent the result of multiplying the matrix A by the vector v. This function doesnt return a value. Because the vector u was passed by reference, the function can modify the vector u to produce the result of multiplying the matrix A by the vector v. The resulting vector u can then be used in the main program as needed.

	#include "mylib.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>


	int main() {
		clock_t start, end;
		double cpu_time_used;

		int i, j, k = 0;
		int m = 15000; // rows
		int n = 15000; // col

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

		start = clock();

		vectorXmatrix(A, v, u, m, n); // serial version

		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

		printf("\n\nTime to complete serial operation = %.3e\n", cpu_time_used);

		start = clock();

		parallelVectorXmatrix(A, v, u, m, n); // parallel version

		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

		printf("\n\nTime to complete parallel operation = %.3e\n", cpu_time_used);

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

	Time to complete serial operation = 7.740e-01

	Time to complete parallel operation = 1.000e-03

The output shows the results of how much time the multiplication took for the serial and parallel programs. The parallel version took considerable less time to compute.

**Implementation/Code:** The following is the code for parallelVectorXmatrix()

	void parallelVectorXmatrix(double **A, double *v, double *u, int m, int n) {

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
					//printf("A[0][%d] * v[%d], thread %d\n", i, i, id);
				}
			}

			if (id == 2) {
				u[1] = 0;
				for (i = 0; i < m; i++) {
					u[1] = u[1] + (A[1][i] * v[i]);
					//printf("A[1][%d] * v[%d], thread %d\n", i, i, id);
				}
			}

			if (id == 3) {
				u[2] = 0;
				for (i = 0; i < m; i++) {
					u[2] = u[2] + (A[2][i] * v[i]);
					//printf("A[2][%d] * v[%d], thread %d\n", i, i, id);
				}
			}
		}
	}

**Last Modified:** November/2018
