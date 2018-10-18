#include "mylib.h"

int main() {
	int i = 0;
	int j = 0;
	int m = 3; // rows
	int n = 3; // col
	double tr = 0.0;
	double scaler = 5.0;
	double det = 0.0;
	double norm = 0.0;
	double A[3][3] = { { 2, 4, 6 },{ 8, 10, 12 },{ 14, 16, 18 } };
	double B[3][3] = { { 1, 3, 5 },{ 7, 9, 11 },{ 13, 15, 17 } };
	double C[3][3] = { 0 };
	double K[9][9] = { 0 };
	double v[3] = { 1, 2, 3 };
	double u[3] = { 0 };
	double x[3] = { 4, 5, 6 };
	double y[3] = { 7, 8, 9 };



	printf("\n\nMatrix A =\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", A[i][j]);
		}
		printf("\n");
	}


	printf("\n\nMatrix B =\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", B[i][j]);
		}
		printf("\n");
	}


	printf("\n\nMatrix C =\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", C[i][j]);
		}
		printf("\n");
	}


	printf("\n\nMatrix K =\n");

	for (i = 0; i < (m * m); i++) {
		for (j = 0; j < (n * n); j++) {
			printf("%.3lf\t", K[i][j]);
		}
		printf("\n");
	}


	printf("\n\nVector v =\n");

	for (i = 0; i < m; i++) {
		printf("%.3lf\n", v[i]);
	}


	printf("\n\nVector u =\n");

	for (i = 0; i < m; i++) {
		printf("%.3lf\n", u[i]);
	}


	matrixAdd(A, B, C, m, n);

	printf("\n\nMatrix C = A + B\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", C[i][j]);
		}
		printf("\n");
	}


	matrixSub(A, B, C, m, n);

	printf("\n\nMatrix C = A - B\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", C[i][j]);
		}
		printf("\n");
	}


	vectorXmatrix(A, v, u, m, n);

	printf("\n\nVector u = A * v\n");

	for (i = 0; i < m; i++) {
		printf("%.3lf\n", u[i]);
	}


	matrixXmatrix(A, B, C, m, n);

	printf("\n\nMatrix C = A * B\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", C[i][j]);
		}
		printf("\n");
	}


	scaleMatrix(A, C, scaler, m, n);

	printf("\n\nMatrix C = scaler * A\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", C[i][j]);
		}
		printf("\n");
	}


	transposeMatrix(A, C, m, n);

	printf("\n\nMatrix C = Transpose of A\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", C[i][j]);
		}
		printf("\n");
	}


	tr = traceMatrix(A, m);
	printf("\n\nTrace of A = \n");
	printf("%.3lf\n", tr);


	tr = traceMatrix(B, m);
	printf("\n\nTrace of B = \n");
	printf("%.3lf\n", tr);


	det = determinantMatrix(A, m);
	printf("\n\nDeterminant of A = \n");
	printf("%.3lf\n", det);


	det = determinantMatrix(B, m);
	printf("\n\nDeterminant of B = \n");
	printf("%.3lf\n", det);


	KroneckerMatrix(A, B, K, m, n);

	printf("\n\nKronecker A * B =\n");

	for (i = 0; i < (m * m); i++) {
		for (j = 0; j < (n * n); j++) {
			printf("%.3lf\t", K[i][j]);
		}
		printf("\n");
	}


	printf("\n\n\n");

	parallelMatrixXmatrix(A, B, C, m, n);

	printf("\n\nMatrix C = A * B\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", C[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n");

	parallelVectorXmatrix(A, v, u, m, n);

	printf("\n\nVector u = A * v\n");

	for (i = 0; i < m; i++) {
		printf("%.3lf\n", u[i]);
	}

	norm = matrixNormL1(A, n);
	printf("\n\nL1 norm of A = \n");
	printf("%.3lf\n", norm);

	norm = matrixNormFrobenious(A, n);
	printf("\n\nFrobenious norm of A = \n");
	printf("%.3lf\n", norm);

	norm = matrixNormInfinity(A, n);
	printf("\n\nInfinity norm of A = \n");
	printf("%.3lf\n", norm);


	printf("\n\nVector x =\n");

	for (i = 0; i < m; i++) {
		printf("%.3lf\n", x[i]);
	}

	printf("\n\nVector y =\n");

	for (i = 0; i < m; i++) {
		printf("%.3lf\n", y[i]);
	}

	outerProductMatrix(x, y, C, m, n);

	printf("\n\nMatrix C = outer product of x and y\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.3lf\t", C[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n");

	return 0;
}