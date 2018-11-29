#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, k = 0;
	double normL1 = 0.0;
	double normL2 = 0.0;
	double normInfinity = 0.0;

	int n = 3;

	// alloc memory for a vector
	double *v1;
	v1 = calloc(n, sizeof(double));

	// assign values to vector v1
	k = 1;
	for (i = 0; i < n; i++) {
		v1[i] = k;
		k++;
	}

	printf("\n\n\n");

	printf("\n\nVector v1 =\n");

	printVector(v1, n);

	normL1 = vectorNormL1(v1, n);
	normL2 = vectorNormL2(v1, n);
	normInfinity = vectorNormInfinity(v1, n);

	printf("\n\n\n");

	printf("\n\nL1 norm of v1 = %.3e\n", normL1);
	printf("\n\nL2 norm of v1 = %.3e\n", normL2);
	printf("\n\nInfinity norm of v1 = %.3e\n", normInfinity);

	printf("\n\n\n");

	// free memory
	free(v1);

	return 0;
}