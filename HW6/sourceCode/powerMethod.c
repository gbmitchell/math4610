#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>



int main() {
	int i, j = 0;
	int n = 3;
	int m = 3;
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

	
	A[0][0] = 4.0; A[0][1] = 1.0; A[0][2] = 2.0;
	A[1][0] = 1.0; A[1][1] = 5.0; A[1][2] = 3.0;
	A[2][0] = 2.0; A[2][1] = 3.0; A[2][2] = 6.0;

	v[0] = 1.0; v[1] = 1.0; v[2] = 1.0;
	

	// create uniformly distributed and diagnally dominant matrix
	// and create RHS vector
	//uniformMatrix(A, v, n);

	printf("Matrix A =\n");

	printMatrix(A, m, n);

	printf("\n\n\n");

	eigenvalue = powerMethod(A, v, tol, maxiter, n);

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