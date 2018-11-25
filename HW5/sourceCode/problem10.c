#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	clock_t start, end;
	double time1 = 0.0;
	double time2 = 0.0;
	double time3 = 0.0;
	double time4 = 0.0;
	double time5 = 0.0;
	double time6 = 0.0;
	double time7 = 0.0;
	double time8 = 0.0;
	double time9 = 0.0;
	double time10 = 0.0;

	int i, j = 0;
	int maxiter = 500000;
	double tol = 0.0001;


	// 40x40  ***************************************************************************************
	int n = 40;
	int m = 40;

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

	//printAugMatrix(A, b, m, n);

	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidel(A, b, x, tol, maxiter, n);

	end = clock();
	time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);


	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidelParallel(A, b, x, tol, maxiter, n);

	end = clock();
	time2 = ((double)(end - start)) / CLOCKS_PER_SEC;



	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);

	printf("\n\n\n");

	printf("\ntime 1 = %.3e\n", time1);
	printf("\ntime 2 = %.3e\n", time2);

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);
	free(b);
	free(x);

	// 80x80  ***************************************************************************************
	n = 80;
	m = 80;

	// allocate mxn matrix
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// allocate vector for RHS
	b = calloc(n, sizeof(double));

	// allocate vector for solution
	x = calloc(n, sizeof(double));

	printf("\n\n\n");

	// create uniformly distributed and diagnally dominant matrix
	// and create RHS vector
	uniformMatrix(A, b, n);

	printf("Uniform diagnaly dominent matrix A augmented with vector b =\n");

	//printAugMatrix(A, b, m, n);

	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidel(A, b, x, tol, maxiter, n);

	end = clock();
	time3 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);


	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidelParallel(A, b, x, tol, maxiter, n);

	end = clock();
	time4 = ((double)(end - start)) / CLOCKS_PER_SEC;



	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);

	printf("\n\n\n");

	printf("\ntime 1 = %.3e\n", time1);
	printf("\ntime 2 = %.3e\n", time2);

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);
	free(b);
	free(x);

	// 160x160  ***************************************************************************************
	n = 160;
	m = 160;

	// allocate mxn matrix
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// allocate vector for RHS
	b = calloc(n, sizeof(double));

	// allocate vector for solution
	x = calloc(n, sizeof(double));

	printf("\n\n\n");

	// create uniformly distributed and diagnally dominant matrix
	// and create RHS vector
	uniformMatrix(A, b, n);

	printf("Uniform diagnaly dominent matrix A augmented with vector b =\n");

	//printAugMatrix(A, b, m, n);

	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidel(A, b, x, tol, maxiter, n);

	end = clock();
	time5 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);


	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidelParallel(A, b, x, tol, maxiter, n);

	end = clock();
	time6 = ((double)(end - start)) / CLOCKS_PER_SEC;



	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);

	printf("\n\n\n");

	printf("\ntime 1 = %.3e\n", time1);
	printf("\ntime 2 = %.3e\n", time2);

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);
	free(b);
	free(x);

	// 320x320  ***************************************************************************************
	n = 320;
	m = 320;

	// allocate mxn matrix
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// allocate vector for RHS
	b = calloc(n, sizeof(double));

	// allocate vector for solution
	x = calloc(n, sizeof(double));

	printf("\n\n\n");

	// create uniformly distributed and diagnally dominant matrix
	// and create RHS vector
	uniformMatrix(A, b, n);

	printf("Uniform diagnaly dominent matrix A augmented with vector b =\n");

	//printAugMatrix(A, b, m, n);

	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidel(A, b, x, tol, maxiter, n);

	end = clock();
	time7 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);


	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidelParallel(A, b, x, tol, maxiter, n);

	end = clock();
	time8 = ((double)(end - start)) / CLOCKS_PER_SEC;



	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);

	printf("\n\n\n");

	printf("\ntime 1 = %.3e\n", time1);
	printf("\ntime 2 = %.3e\n", time2);

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);
	free(b);
	free(x);

	// 640x640  ***************************************************************************************
	n = 640;
	m = 640;

	// allocate mxn matrix
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// allocate vector for RHS
	b = calloc(n, sizeof(double));

	// allocate vector for solution
	x = calloc(n, sizeof(double));

	printf("\n\n\n");

	// create uniformly distributed and diagnally dominant matrix
	// and create RHS vector
	uniformMatrix(A, b, n);

	printf("Uniform diagnaly dominent matrix A augmented with vector b =\n");

	//printAugMatrix(A, b, m, n);

	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidel(A, b, x, tol, maxiter, n);

	end = clock();
	time9 = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);


	printf("\n\n\n");

	for (i = 0; i < n; i++) {
		x[i] = 0.0;
	}

	start = clock();

	// solve linear system with jacobi iteration
	gaussSeidelParallel(A, b, x, tol, maxiter, n);

	end = clock();
	time10 = ((double)(end - start)) / CLOCKS_PER_SEC;



	printf("\n\n\n");

	printf("Solution vector x =\n");

	printVector(x, n);

	printf("\n\n\n");

	printf("\ntime 1 = %.3e\n", time1);
	printf("\ntime 2 = %.3e\n", time2);

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);
	free(b);
	free(x);

	printf("\ntime 40x40 serial = %.3e\n", time1);
	printf("\ntime 40x40 parallel = %.3e\n", time2);
	printf("\ntime 80x80 serial = %.3e\n", time3);
	printf("\ntime 80x80 parallel = %.3e\n", time4);
	printf("\ntime 160x160 serial = %.3e\n", time5);
	printf("\ntime 160x160 parallel = %.3e\n", time6);
	printf("\ntime 320x320 serial = %.3e\n", time7);
	printf("\ntime 320x320 parallel = %.3e\n", time8);
	printf("\ntime 640x640 serial = %.3e\n", time9);
	printf("\ntime 640x640 parallel = %.3e\n", time10);

	return 0;
}