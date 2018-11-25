#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	clock_t start, end;
	double time1 = 0.0;
	double time2 = 0.0;

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

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	jacobi(A, b, x, tol, maxiter, n);

	end = clock();
	time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\ntime 1 = %.3e\n", time1);

	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);


	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	jacobiParallel(A, b, x, tol, maxiter, n);

	end = clock();
	time2 = ((double)(end - start)) / CLOCKS_PER_SEC;


	printf("\ntime 2 = %.3e\n", time2);

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