#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	int i, j = 0;
	int n = 7;
	int m = 7;
	int maxiter = n * 6000;
	double tol = 0.0001;

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

	// allocate vector for solution
	double *x;
	x = calloc(n, sizeof(double));

	printf("\n\n\n");

	// create uniformly distributed and diagnally dominant matrix
	// and create RHS vector
	uniformMatrix(A, b, n);

	printf("Uniform diagnaly dominent matrix A augmented with vector b =\n");

	printAugMatrix(A, b, m, n);

	printf("\n\n\n");

	// solve linear system with gauss-seidel iteration
	gaussSeidel(A, b, x, tol, maxiter, n);

	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);

	printf("\n\n\n");

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);
	free(b);
	free(x);

	return 0;
}