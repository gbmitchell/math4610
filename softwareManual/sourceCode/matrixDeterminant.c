#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	int i, j, k = 0;
	double determinant = 0.0;

	int m = 1; // rows
	int n = 1; // col

	// alloc memory for a matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	A[0][0] = 5.0;

	printf("\n\n\n");

	printf("\n\nMatrix A =\n");

	printMatrix(A, m, n);

	determinant = determinantMatrixNxN(A, n);

	printf("\n\n\n");

	printf("\n\nDeterminant of A = %.3e\n", determinant);

	printf("\n\n\n");


	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	m = 2; // rows
	n = 2; // col

	// alloc memory for a matrix
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	A[0][0] = 3.0; A[0][1] = 8.0; 
	A[1][0] = 4.0; A[1][1] = 6.0; 

	printf("\n\n\n");

	printf("\n\nMatrix A =\n");

	printMatrix(A, m, n);

	determinant = determinantMatrixNxN(A, n);

	printf("\n\n\n");

	printf("\n\nDeterminant of A = %.3e\n", determinant);

	printf("\n\n\n");


	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	m = 5; // rows
	n = 5; // col

	// alloc memory for a matrix
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	A[0][0] = 0.0; A[0][1] = 6.0; A[0][2] = -2.0; A[0][3] = -1.0; A[0][4] = 5.0;
	A[1][0] = 0.0; A[1][1] = 0.0; A[1][2] = 0.0; A[1][3] = -9.0; A[1][4] = -7.0;
	A[2][0] = 0.0; A[2][1] = 15.0; A[2][2] = 35.0; A[2][3] = 0.0; A[2][4] = 0.0;
	A[3][0] = 0.0; A[3][1] = -1.0; A[3][2] = -11.0; A[3][3] = -2.0; A[3][4] = 1.0;
	A[4][0] = -2.0; A[4][1] = -2.0; A[4][2] = 3.0; A[4][3] = .0; A[4][4] = .0;

	printf("\n\n\n");

	printf("\n\nMatrix A =\n");

	printMatrix(A, m, n);

	determinant = determinantMatrixNxN(A, n);

	printf("\n\n\n");

	printf("\n\nDeterminant of A = %.3e\n", determinant);

	printf("\n\n\n");


	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	return 0;
}