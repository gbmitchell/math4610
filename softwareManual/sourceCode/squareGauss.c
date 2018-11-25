#include "mylib.h"
#include <stdio.h>

int main() {
	int i, j = 0;
	int n = 0;
	int m = 0;

	// 3x3
	double A[50][50] = { {1.0, 0.0, 0.0}, {3.0, 1.0, 0.0}, { -1.0, 1.0, -3.0} };
	double B[50][50] = { {1.0, -2.0, -6.0}, {2.0, 4.0, 12.0}, {1.0, -3.0, -12.0} };
	double D[50][50] = { {1.0, -2.0, -6.0}, {2.0, 4.0, 12.0}, {1.0, -3.0, -12.0} };
	double E[50][50] = { {1.0, -1.0, 2.0}, {-1.0, 5.0, -4.0}, {2.0, -4.0, 6.0} };
	double F[50][50] = { {1.0, -1.0, 2.0}, {-1.0, 5.0, -4.0}, {2.0, -4.0, 6.0} };
	double G[50][50] = { {1.0, 2.0, 1.0, 3.0, 1.0}, {2.0, 29.0, 17.0, 11.0, 12.0}, {1.0, 17.0, 46.0, 18.0, 13.0}, {3.0, 11.0, 18.0, 78.0, 15.0}, {1.0, 12.0, 13.0, 15.0, 88.0} };
	double H[50][50] = { {0.0011, 0.0, 0.0, -0.0001, 0.0, 0.0, 0.0}, {0.0, 0.008860992908, -0.000066666667, 0.0, 0.002127659574, 0.0, 0.0}, {0.0, -0.000066666667, 0.003612765957, -0.000212765957, 0.0, -0.0030303030303, 0.0}, {-0.0001, 0.0, -0.000212765957, 0.001783354193, 0.0, 0.0, -0.001470588235}, {0.0, -0.002127659574, 0.0, 0.0, 0.00677311412, -0.0001, -0.004545454545}, {0.0, 0.0, -0.00303030303, 0.0, -0.0001, 0.00413030303, -0.001}, {0.0, 0.0, 0.0, -0.001470588235, -0.004545454545, -0.001, 0.007016042781} };
	double P[50][50] = { {18450.0, -3300.0, -15000.0, 0.0, 0.0}, {-3300.0, 19000.0, 0.0, -4700.0, 0.0}, {-15000.0, 0.0, 25800.0, -330.0, -10000.0}, {0.0, -4700.0, -330.0, 6710.0, -1000.0}, {0.0, 0.0, -10000.0, -1000.0, 11220.0} };
	double HU[50][50] = { 0 };
	double PU[50][50] = { 0 };
	double EU[50][50] = { 0 };
	double FU[50][50] = { 0 };
	double GU[50][50] = { 0 };
	double GUmult[50][50] = { 0 };
	double L[50][50] = { 0 };
	
	// 4x5
	double C[50][50] = { {1.0, -1.0, 3.0, 1.0, 1.0}, {3.0, 1.0, 7.0, 1.0, 5.0}, {-4.0, 4.0, 1.0, -2.0, 2.0}, {2.0, 1.0, 2.0, 1.0, 3.0} };

	double ba[50] = { -2.0, 0.0, 5.0 };
	double bb[50] = { 5.0, 0.0, -2.0 };
	double bc[50] = { 4.0, 5.0, 6.0, 7.0 };
	double bd[50] = { 5.0, 0.0, -2.0 };
	double be[50] = { 2.0, 1.0, 3.0 };
	double bg[50] = { 2.0, 1.0, 3.0, 1.0, 5.0 };
	double bh[50] = { 0.0, 0.08, 0.0, 0.0, 0.0, 0.0, 0.0 };
	double bp[50] = { 12.0, 0.0, 0.0, 0.0, 0.0 };

	double xa[50] = { 0 };
	double xb[50] = { 0 };
	double xc[50] = { 0 };
	double xd[50] = { 0 };
	double xe[50] = { 0 };
	double xg[50] = { 0 };
	double xh[50] = { 0 };
	double xp[50] = { 0 };

	m = 3;
	n = 3;

	printf("Lower triagular augmented matrix A =\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", A[i][j]);
		}
		printf("|%.3e\n", ba[i]);
	}

	forwardSub(A, xa, ba, n);

	printf("\n\n\n");

	printf("Solution using forward substitution on augmented matrix A\n");

	for (i = 0; i < n; i++) {
		printf("x%d = %.3e\n", i+1, xa[i]);
	}

	printf("\n\n\n");

	printf("Augmented matrix B =\n");

	for (i = 0; i < m; i++ ) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", B[i][j]);
		}
		printf("|%.3e\n", bb[i]);
	}

	GEsolve(B, xb, bb, n);

	printf("\n\n\n");

	printf("Solution using Gauss Elimination method\n");

	for (i = 0; i < n; i++) {
		printf("x%d = %.3e\n", i + 1, xb[i]);
	}

	printf("\n\n\n");

	printf("Augmented matrix C =\n");
	m = 4;
	n = 5;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", C[i][j]);
		}
		printf("|%.3e\n", bc[i]);
	}

	generalGauss(C, bc, m, n);

	printf("\n\n\n");

	printf("Gaussian elimination on augmented matrix C =\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", C[i][j]);
		}
		printf("|%.3e\n", bc[i]);
	}

	printf("\n\n\n");

	printf("Augmented matrix D =\n");

	m = 3;
	n = 3;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", D[i][j]);
		}
		printf("|%.3e\n", bd[i]);
	}

	LUsolve(D, L, xd, bd, n);

	printf("\n\n\n");

	printf("Solution Dx=b, using LU decomposition on matrix D\n");

	for (i = 0; i < n; i++) {
		printf("x%d = %.3e\n", i + 1, xd[i]);
	}

	printf("\n\n\n");

	m = 5;
	n = 5;

	printf("Matrix G =\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", G[i][j]);
		}
		printf("\n");
	}

	choleskyLU(G, GU, n);

	printf("\n\n\n");

	printf("Cholesky Decomposition on matrix G\nL = \n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", G[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n");

	printf("U = \n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", GU[i][j]);
		}
		printf("\n");
	}

	m = 7;
	n = 7;

	printf("\n\n\n");

	printf("Augmented matrix H =\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", H[i][j]);
		}
		printf("|%.3e\n", bh[i]);
	}

	Choleskysolve(H, HU, xh, bh, n);

	printf("\n\n\n");

	printf("Solution Hx=b, using Cholesky decomposition on matrix H\n");

	for (i = 0; i < n; i++) {
		printf("x%d = %.3e\n", i + 1, xh[i]);
	}

	printf("\n\n\n");

	m = 5;
	n = 5;

	printf("\n\n\n");

	printf("Augmented matrix P =\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", P[i][j]);
		}
		printf("|%.3e\n", bp[i]);
	}

	Choleskysolve(P, PU, xp, bp, n);

	printf("\n\n\n");

	printf("Solution Px=b, using Cholesky decomposition on matrix P\n");

	for (i = 0; i < n; i++) {
		printf("x%d = %.3e\n", i + 1, xp[i]);
	}

	printf("\n\n\n");

	/*
	printf("Augmented matrix G =\n");

	m = 5;
	n = 5;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3e\t", G[i][j]);
		}
		printf("|%.3e\n", bg[i]);
	}

	Choleskysolve(G, GU, xg, bg, n);

	printf("\n\n\n");

	printf("Solution Gx=b, using Cholesky decomposition on matrix G\n");

	for (i = 0; i < n; i++) {
		printf("x%d = %.3e\n", i + 1, xg[i]);
	}

	printf("\n\n\n");

	*/

	return 0;
}