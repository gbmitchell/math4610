#include "mylib.h"

int main() {
	int i = 0;
	int len = 0;
	double eabs = 0.0;
	double erel = 0.0;
	double ia = 0.0;
	double scaler = 5.0;
	double u[3] = { 1, 2, 3 };
	double v[3] = { 8, -7, 6 };
	double x[3] = { -1.25, 2.125, 3.0625 };
	double y[3] = { -1, 2, 3 };
	double a[3] = { 0 };


	len = sizeof(u) / 8;

	printf("\n\nVector u =\n");

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", u[i]);
	}

	printf("\n\nVector v =\n");

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", v[i]);
	}

	ia = vectorNormL1(u, len);
	printf("\n\nL1 norm of u = %.3lf", ia);

	ia = vectorNormL1(v, len);
	printf("\n\nL1 norm of v = %.3lf", ia);

	ia = vectorNormL2(u, len);
	printf("\n\nL2 norm of u = %.3lf", ia);

	ia = vectorNormL2(v, len);
	printf("\n\nL2 norm of v = %.3lf", ia);

	ia = vectorNormInfinity(u, len);
	printf("\n\nInfinity norm of u = %.3lf", ia);

	ia = vectorNormInfinity(v, len);
	printf("\n\nInfinity norm of v = %.3lf", ia);


	printf("\n\nExact Vector x =\n");

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", x[i]);
	}

	printf("\n\nApproximate Vector y =\n");

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", y[i]);
	}

	eabs = vectorErrorAbsoluteL1(x, y, len);
	printf("\n\ne = x - y");
	printf("\nL1 norm of e = L1 eabs = %.3lf", eabs);

	erel = vectorErrorRelativeL1(x, y, len);
	printf("\n\neabs/L1 norm of x = L1 erel = %.3lf", erel);

	eabs = vectorErrorAbsoluteL2(x, y, len);
	printf("\n\ne = x - y");
	printf("\nL2 norm of e = L2 eabs = %.3lf", eabs);

	erel = vectorErrorRelativeL2(x, y, len);
	printf("\n\neabs/L2 norm of x = L2 erel = %.3lf", erel);

	eabs = vectorErrorAbsoluteInfinity(x, y, len);
	printf("\n\ne = x - y");
	printf("\nInfinity norm of e = Infinity eabs = %.3lf", eabs);

	erel = vectorErrorRelativeInfinity(x, y, len);
	printf("\n\neabs/Infinity norm of x = Infinity erel = %.3lf", erel);

	printf("\n\n\n");
}