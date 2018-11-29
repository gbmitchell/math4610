#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	int i, j = 0;
	int m = 7;
	int n = 7;

	// alloc memory for a matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// alloc memory for a matrix
	double **U;
	U = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		U[i] = calloc(n, sizeof(double));
	}

	// alloc memory for a vector
	double *b;
	b = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *x;
	x = calloc(n, sizeof(double));

	m = 5;
	n = 5;

	// alloc memory for a matrix
	double **B;
	B = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		B[i] = calloc(n, sizeof(double));
	}

	// alloc memory for a matrix
	double **V;
	V = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		V[i] = calloc(n, sizeof(double));
	}

	// alloc memory for a vector
	double *c;
	c = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *y;
	y = calloc(n, sizeof(double));

	// 7x7 node voltage
	A[0][0] = 0.0011;  A[0][1] = 0.0;             A[0][2] = 0.0;             A[0][3] = -0.0001;         A[0][4] = 0.0;             A[0][5] = 0.0;              A[0][6] = 0.0;
	A[1][0] = 0.0;     A[1][1] = 0.008860992908;  A[1][2] = -0.000066666667; A[1][3] = 0.0;             A[1][4] = 0.002127659574;  A[1][5] = 0.0;              A[1][6] = 0.0;
	A[2][0] = 0.0;     A[2][1] = -0.000066666667; A[2][2] = 0.003612765957;  A[2][3] = -0.000212765957; A[2][4] = 0.0;             A[2][5] = -0.0030303030303; A[2][6] = 0.0;
	A[3][0] = -0.0001; A[3][1] = 0.0;             A[3][2] = -0.000212765957; A[3][3] = 0.001783354193;  A[3][4] = 0.0;             A[3][5] = 0.0;              A[3][6] = -0.001470588235;
	A[4][0] = 0.0;     A[4][1] = -0.002127659574; A[4][2] = 0.0;             A[4][3] = 0.0;             A[4][4] = 0.00677311412;   A[4][5] = -0.0001;          A[4][6] = -0.004545454545;
	A[5][0] = 0.0;     A[5][1] = 0.0;             A[5][2] = -0.00303030303;  A[5][3] = 0.0;             A[5][4] = -0.0001;         A[5][5] = 0.00413030303;    A[5][6] = -0.001;
	A[6][0] = 0.0;     A[6][1] = 0.0;             A[6][2] = 0.0;             A[6][3] = -0.001470588235; A[6][4] = -0.004545454545; A[6][5] = -0.001;           A[6][6] = 0.007016042781;

	// RHS node voltage
	b[0] = 0.0; b[1] = 0.08; b[2] = 0.0; b[3] = 0.0; b[4] = 0.0; b[5] = 0.0; b[6] = 0.0;


	// 5x5 mesh current
	B[0][0] = 18450.0;  B[0][1] = -3300.0;  B[0][2] = -15000.0;  B[0][3] = 0.0;      B[0][4] = 0.0;
	B[1][0] = -3300.0;  B[1][1] = 19000.0;  B[1][2] = 0.0;       B[1][3] = -4700.0;  B[1][4] = 0.0;
	B[2][0] = -15000.0; B[2][1] = 0.0;      B[2][2] = 25800.0;   B[2][3] = -330.0;   B[2][4] = -10000.0;
	B[3][0] = 0.0;      B[3][1] = -4700.0;  B[3][2] = -330.0;    B[3][3] = 6710.0;   B[3][4] = -1000.0;
	B[4][0] = 0.0;      B[4][1] = 0.0;      B[4][2] = -10000.0;  B[4][3] = -1000.0;  B[4][4] = 11220.0;

	// RHS mesh current
	c[0] = 12.0; c[1] = 0.0; c[2] = 0.0; c[3] = 0.0; c[4] = 0.0;


	m = 7;
	n = 7;

	printf("Augmented matrix A =\n");

	printAugMatrix(A, b, m, n);

	printf("\n\n\n");

	Choleskysolve(A, U, x, b, n);

	printf("\n\n\n");

	printf("Solution Ax=b, using Cholesky decomposition on matrix A\n");
	printf("x =\n");

	printVector(x, n);

	printf("\n\n\n");

	m = 5;
	n = 5;

	printf("Augmented matrix B =\n");

	printAugMatrix(B, c, m, n);

	printf("\n\n\n");

	Choleskysolve(B, V, y, c, n);

	printf("\n\n\n");

	printf("Solution By=c, using Cholesky decomposition on matrix B\n");
	printf("y =\n");

	printVector(y, n);

	printf("\n\n\n");

	m = 7;
	n = 7;

	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	for (i = 0; i < m; i++)
	{
		free(U[i]);
	}

	free(U);

	for (i = 0; i < m; i++)
	{
		free(B[i]);
	}

	free(b);
	free(x);

	m = 5;
	n = 5;

	free(B);

	for (i = 0; i < m; i++)
	{
		free(V[i]);
	}

	free(V);
	
	free(c);
	free(y);

	return 0;
}