#include "mylib.h"

int main() {
	int i = 0;
	int len = 0;
	double ia = 0;
	double scaler = 5.0;
	double u[3] = { 1, 2, 3 };
	double v[3] = { 8, -7, 6 };
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


	printf("\n\nu + v =\n");

	vectorAdd(u, v, a, len);

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", a[i]);
	}

	printf("\n\n\nv - u =\n");

	vectorSub(v, u, a, len);

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", a[i]);
	}


	printf("\n\n\nScaler * u =\n");

	vectorScale(u, a, scaler, len);

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", a[i]);
	}

	printf("\n\n\nInner product of u and v = ");

	ia = vectorInner(u, v, len);

	printf("%.3lf", ia);

	printf("\n\n\nCross product of u and v =\n");

	vectorCross(u, v, a, len);

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", a[i]);
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


	printf("\n\n\n");

	return 0;
}