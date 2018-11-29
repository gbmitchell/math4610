#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i = 0;
	double k = 0.0;
	double eabsL1 = 0.0;
	double erelL1 = 0.0;
	double eabsL2 = 0.0;
	double erelL2 = 0.0;
	double eabsInfinity = 0.0;
	double erelInfinity = 0.0;

	int n = 3;

	// alloc memory for a vector
	double *x;
	x = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *y;
	y = calloc(n, sizeof(double));

	// assign values to vector x
	k = -1.125;
	for (i = 0; i < n; i++) {
		x[i] = k;
		k = k + 1.25;
	}

	// assign values to vector y
	k = -1.0;
	for (i = 0; i < n; i++) {
		y[i] = k;
		k = k + 1.25;
	}

	printf("\n\n\n");

	printf("\n\nExact vector x =\n");

	printVector(x, n);

	printf("\n\n\n");

	printf("\n\nApproximate vector y =\n");

	printVector(y, n);

	eabsL1 = vectorErrorAbsoluteL1(x, y, n);

	erelL1 = vectorErrorRelativeL1(x, y, n);

	eabsL2 = vectorErrorAbsoluteL2(x, y, n);

	erelL2 = vectorErrorRelativeL2(x, y, n);

	eabsInfinity = vectorErrorAbsoluteInfinity(x, y, n);

	erelInfinity = vectorErrorRelativeInfinity(x, y, n);

	printf("\n\n\n");

	printf("\n\nAbsolut error using L1 norm = %.3e\n", eabsL1);
	printf("\n\nRelative error using L1 norm = %.3e\n", erelL1);
	printf("\n\nAbsolut error using L2 norm = %.3e\n", eabsL2);
	printf("\n\nRelative error using L2 norm = %.3e\n", erelL2);
	printf("\n\nAbsolut error using Infinity norm = %.3e\n", eabsInfinity);
	printf("\n\nRelative error using Infinity norm = %.3e\n", erelInfinity);
	
	printf("\n\n\n");

	// free memory
	free(x);
	free(y);

	return 0;
}