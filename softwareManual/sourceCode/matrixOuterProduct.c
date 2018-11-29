#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, k = 0;
	int m = 3; // rows
	int n = 3; // col

	// alloc memory for a matrix
	double **C;
	C = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		C[i] = calloc(n, sizeof(double));
	}

	// alloc memory for a vector
	double *x;
	x = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *y;
	y = calloc(n, sizeof(double));


	// assign even values to vector v
	k = 4;
	for (i = 0; i < n; i++) {
		x[i] = k;
		k++;
	}

	// assign even values to vector v
	k = 7;
	for (i = 0; i < n; i++) {
		y[i] = k;
		k++;
	}

	printf("\n\n\n");

	printf("\n\nVector x =\n");

	printVector(x, n);

	printf("\n\n\n");

	printf("\n\nVector y =\n");

	printVector(y, n);

	outerProductMatrix(x, y, C, m, n);

	printf("\n\n\n");

	printf("\n\nMatrix C = outer product of x and y\n");

	printMatrix(C, m, n);

	printf("\n\n\n");


	// free memory
	for (i = 0; i < m; i++)
	{
		free(C[i]);
	}

	free(C);

	free(x);

	free(y);

	return 0;
}