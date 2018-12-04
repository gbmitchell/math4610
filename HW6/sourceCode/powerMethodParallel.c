#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	clock_t start, end;
	double time1 = 0.0;
	int i, j = 0;
	int n = 1000;
	int m = 1000;
	int maxiter = n * 6000;
	double tol = 0.0001;
	double eigenvalue = 0.0;

	// allocate mxn matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// allocate vector for solution
	double *v;
	v = calloc(n, sizeof(double));

	printf("\n\n\n");

	/*
	A[0][0] = 0.0; A[0][1] = 6.0; A[0][2] = -2.0; A[0][3] = -1.0; A[0][4] = 5.0;
	A[1][0] = 0.0; A[1][1] = 0.0; A[1][2] = 0.0; A[1][3] = -9.0; A[1][4] = -7.0;
	A[2][0] = 0.0; A[2][1] = 15.0; A[2][2] = 35.0; A[2][3] = 0.0; A[2][4] = 0.0;
	A[3][0] = 0.0; A[3][1] = -1.0; A[3][2] = -11.0; A[3][3] = -2.0; A[3][4] = 1.0;
	A[4][0] = -2.0; A[4][1] = -2.0; A[4][2] = 3.0; A[4][3] = .0; A[4][4] = .0;

	v[0] = 1.0; v[1] = 1.0; v[2] = 1.0; v[3] = 1.0; v[4] = 1.0;
	*/

	// create uniformly distributed and diagnally dominant matrix
	// and create RHS vector
	uniformMatrix(A, v, n);

	printf("Matrix A =\n");

	//printMatrix(A, m, n);

	printf("\n\n\n");

	start = clock();

	eigenvalue = powerMethod(A, v, tol, maxiter, n);

	end = clock();
	time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\nTime serial = %.3e\n", time1);

	printf("Largest eigenvalue of matrix A = %.3e", eigenvalue);


	printf("\n\n\n");

	start = clock();

	eigenvalue = powerMethodParallel(A, v, tol, maxiter, n);

	end = clock();
	time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\nTime parallel = %.3e\n", time1);

	printf("Largest eigenvalue of matrix A = %.3e", eigenvalue);

	printf("\n\n\n");

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);
	free(v);

	return 0;
}