#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	int i, j = 0;
	int m = 4;
	int n = 5;

	// alloc memory for a matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// alloc memory for a vector
	double *b;
	b = calloc(n, sizeof(double));

	double C[50][50] = { {1.0, -1.0, 3.0, 1.0, 1.0}, {3.0, 1.0, 7.0, 1.0, 5.0}, {-4.0, 4.0, 1.0, -2.0, 2.0}, {2.0, 1.0, 2.0, 1.0, 3.0} };

	double bc[50] = { 4.0, 5.0, 6.0, 7.0 };

	A[0][0] = 1.0;  A[0][1] = -1.0; A[0][2] = 3.0; A[0][3] = 1.0; A[0][4] = 1.0;
	A[1][0] = 3.0;  A[1][1] = 1.0; A[1][2] = 7.0; A[1][3] = 1.0; A[1][4] = 5.0;
	A[2][0] = -4.0; A[2][1] = 4.0; A[2][2] = 1.0; A[2][3] = -2.0; A[2][4] = 2.0;
	A[3][0] = 2.0; A[3][1] = 1.0; A[3][2] = 2.0; A[3][3] = 1.0; A[3][4] = 3.0;

	b[0] = 4.0; b[1] = 5.0; b[2] = 6.0; b[3] = 7.0;

	printf("Upper triagular augmented matrix A =\n");

	printAugMatrix(A, b, m, n);

	generalGauss(A, b, m, n);

	printf("\n\n\n");

	printf("Gauss Elimination on augmented matrix A=\n");

	printAugMatrix(A, b, m, n);

	printf("\n\n\n");


	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	free(b);

	return 0;
}