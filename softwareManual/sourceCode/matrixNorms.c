#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k = 0;
	double normL1 = 0.0;
	double normFrobenious = 0.0;
	double normInfinity = 0.0;

	int m = 3; // rows
	int n = 3; // col

	// alloc memory for a matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// assign even values to matrix A
	k = 1;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = k * 2;
			k++;
		}
	}

	printf("\n\n\n");

	printf("\n\nMatrix A =\n");

	printMatrix(A, m, n);

	normL1 = matrixNormL1(A, n);
	normFrobenious = matrixNormFrobenious(A, n);
	normInfinity = matrixNormInfinity(A, n);

	printf("\n\n\n");

	printf("\n\nL1 norm of A = %.3e\n", normL1);
	printf("\n\nFrobenious norm of A = %.3e\n", normFrobenious);
	printf("\n\nInfinity norm of A = %.3e\n", normInfinity);

	printf("\n\n\n");


	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	return 0;
}