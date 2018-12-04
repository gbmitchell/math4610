#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	clock_t start, end;
	double time1 = 0.0;
	int i, j = 0;
	int n = 2000;
	int m = 2000;
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

	// allocate mxn matrix
	double **T;
	T = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		T[i] = calloc(n, sizeof(double));
	}

	// allocate vector for solution
	double *v;
	v = calloc(n, sizeof(double));

	// allocate vector for solution
	double *tempv;
	tempv = calloc(n, sizeof(double));

	printf("\n\n\n");

	/*
	A[0][0] = 4.0; A[0][1] = 1.0; A[0][2] = 2.0;
	A[1][0] = 1.0; A[1][1] = 5.0; A[1][2] = 3.0;
	A[2][0] = 2.0; A[2][1] = 3.0; A[2][2] = 6.0;

	v[0] = 1.0; v[1] = 1.0; v[2] = 1.0;
	*/
	
	
	// create uniformly distributed and diagnally dominant matrix
	// and create RHS vector
	uniformMatrix(A, v, n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			T[i][j] = A[i][j];
		}
	}

	for (i = 0; i < n; i++) {
			tempv[i] = v[i];
	}

	printf("Matrix A =\n");

	//printMatrix(A, m, n);

	printf("\n\n\n");

	start = clock();

	eigenvalue = inversePowerMethod(A, v, tol, maxiter, n);

	end = clock();
	time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\nTime serial = %.3e\n", time1);

	printf("Largest eigenvalue of A^(-1) = %.3e", eigenvalue);


	printf("\n\n\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = T[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		v[i] = tempv[i];
	}

	start = clock();

	eigenvalue = inversePowerMethodParallel(A, v, tol, maxiter, n);

	end = clock();
	time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\nTime parallel = %.3e\n", time1);

	printf("Largest eigenvalue of A^(-1) = %.3e", eigenvalue);

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
		free(T[i]);
	}

	free(T);

	free(v);

	free(tempv);

	return 0;
}