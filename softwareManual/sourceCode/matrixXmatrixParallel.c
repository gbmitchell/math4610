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

	matrixXmatrix(A, B, C, m, n);

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\n\nTime to complete serial operation = %.3e\n", cpu_time_used);

	start = clock();

	parallelMatrixXmatrix(A, B, C, m, n);

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\n\nTime to complete parallel operation = %.3e\n", cpu_time_used);

	printf("\n\n\n");


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