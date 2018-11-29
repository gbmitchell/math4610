#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	int i, j, k = 0;
	int ma = 3; // row matrix A
	int na = 3; // col matrix A
	int mb = 3; // row matrix b
	int nb = 3; // col matrix b
	int mc = ma * mb; // row matrix c
	int nc = na * nb; // col matrix c

	// alloc memory for a matrix
	double **A;
	A = calloc(ma, sizeof(double*));

	for (i = 0; i < ma; i++)
	{
		A[i] = calloc(na, sizeof(double));
	}

	// alloc memory for a matrix
	double **B;
	B = calloc(mb, sizeof(double*));

	for (i = 0; i < mb; i++)
	{
		B[i] = calloc(nb, sizeof(double));
	}

	// alloc memory for a matrix
	double **C;
	C = calloc(mc, sizeof(double*));

	for (i = 0; i < mc; i++)
	{
		C[i] = calloc(nc, sizeof(double));
	}

	// assign even values to matrix A
	k = 1;
	for (i = 0; i < ma; i++) {
		for (j = 0; j < na; j++) {
			A[i][j] = k * 2;
			k++;
		}
	}

	// assign odd values to matrix B
	k = 1;
	for (i = 0; i < mb; i++) {
		for (j = 0; j < nb; j++) {
			B[i][j] = (k * 2) - 1;
			k++;
		}
	}

	printf("\n\n\n");

	printf("\n\nMatrix A =\n");

	printMatrix(A, ma, na);

	printf("\n\n\n");

	printf("\n\nMatrix B =\n");

	printMatrix(B, mb, nb);

	KroneckerMatrix(A, B, C, ma, na, mb, nb);

	printf("\n\n\n");

	printf("\n\nMatrix C = A * B\n");

	printMatrix(C, mc, nc);

	printf("\n\n\n");


	// free memory
	for (i = 0; i < ma; i++)
	{
		free(A[i]);
	}

	free(A);

	// free memory
	for (i = 0; i < mb; i++)
	{
		free(B[i]);
	}

	free(B);

	// free memory
	for (i = 0; i < mc; i++)
	{
		free(C[i]);
	}

	free(C);

	return 0;
}