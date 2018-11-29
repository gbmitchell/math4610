#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	int i, j = 0;
	int m = 5;
	int n = 5;

	// alloc memory for a matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// alloc memory for a matrix
	double **U;
	U = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		U[i] = calloc(n, sizeof(double));
	}

	A[0][0] = 1.0; A[0][1] = 2.0;  A[0][2] = 1.0;  A[0][3] = 3.0;  A[0][4] = 1.0;
	A[1][0] = 2.0; A[1][1] = 29.0; A[1][2] = 17.0; A[1][3] = 11.0; A[1][4] = 12.0;
	A[2][0] = 1.0; A[2][1] = 17.0; A[2][2] = 46.0; A[2][3] = 18.0; A[2][4] = 13.0;
	A[3][0] = 3.0; A[3][1] = 11.0; A[3][2] = 18.0; A[3][3] = 78.0; A[3][4] = 15.0;
	A[4][0] = 1.0; A[4][1] = 12.0; A[4][2] = 13.0; A[4][3] = 15.0; A[4][4] = 88.0;

	printf("Matrix A =\n");

	printMatrix(A, m, n);

	printf("\n\n\n");

	choleskyLU(A, U, n);

	printf("\n\n\n");

	printf("Cholesky decomposition on matrix A =\n");
	printf("Matrix L =\n");

	printMatrix(A, m, n);

	printf("\nMatrix U =\n");

	printMatrix(U, m, n);

	printf("\n\n\n");

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	for (i = 0; i < m; i++)
	{
		free(U[i]);
	}

	free(U);

	return 0;
}