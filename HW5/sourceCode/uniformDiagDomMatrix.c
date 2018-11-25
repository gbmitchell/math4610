#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j = 0;
	int n = 7;
	int m = 7;

	// allocate mxn matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// allocate vector for RHS
	double *b;
	b = calloc(n, sizeof(double));

	printf("\n\n\n");

	// create uniformly distributed and diagnally dominant matrix
	// and create RHS vector by multiplying matrix by vector of ones
	uniformMatrix(A, b, n);

	printf("Uniform diagnaly dominent matrix A augmented with vector b =\n");

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