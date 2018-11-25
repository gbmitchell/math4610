#include "mylib.h"

int main() {
	int i = 0;
	int len = 0;
	double ia = 0;
	double scaler = 5.0;
	double v1[3] = { 4, -1, 2 };
	double v2[3] = { 0, 5, 1 };
	double u1[3] = { 0 };
	double u2[3] = { 0 };
	double a[3] = { 0 };

	len = sizeof(v1) / 8;

	printf("\n\nVector v1 =\n");

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", v1[i]);
	}

	printf("\n\nVector v2 =\n");

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", v2[i]);
	}


	printf("\n\nv1 + v2 =\n");

	vectorAdd(v1, v2, a, len);

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", a[i]);
	}

	printf("\n\n\nv2 - v1 =\n");

	vectorSub(v2, v1, a, len);

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", a[i]);
	}


	printf("\n\n\nScaler * v1 =\n");

	vectorScale(v1, a, scaler, len);

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", a[i]);
	}

	printf("\n\n\nInner product of v1 and v2 = ");

	ia = vectorInner(v1, v2, len);

	printf("%.3lf", ia);

	printf("\n\n\nCross product of v1 and v2 =\n");

	vectorCross(v1, v2, a, len);

	for (i = 0; i < len; i++) {
		printf("%.3lf\n", a[i]);
	}

	ia = vectorNormL1(v1, len);
	printf("\n\nL1 norm of u = %.3lf", ia);

	ia = vectorNormL1(v2, len);
	printf("\n\nL1 norm of v = %.3lf", ia);

	ia = vectorNormL2(v1, len);
	printf("\n\nL2 norm of u = %.3lf", ia);

	ia = vectorNormL2(v2, len);
	printf("\n\nL2 norm of v = %.3lf", ia);

	ia = vectorNormInfinity(v1, len);
	printf("\n\nInfinity norm of u = %.3lf", ia);

	ia = vectorNormInfinity(v2, len);
	printf("\n\nInfinity norm of v = %.3lf", ia);

	unitOrthog(v1, v2, u1, u2, len);

	printf("\n\n\nUnit orthoginal vector u1 =\n");
	for (i = 0; i < len; i++) {
		printf("%.3lf\n", u1[i]);
	}

	printf("\n\n\nUnit orthoginal vector u2 =\n");
	for (i = 0; i < len; i++) {
		printf("%.3lf\n", u2[i]);
	}

	printf("\n\n\n");

	return 0;
}