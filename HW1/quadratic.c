#include <stdio.h>
#include <math.h>
#include <stdbool.h>


void quadratic(double a, double b, double c, double *root1, double *root2, bool *imaginary) {

	// check if roots are imaginary
	if ( ( ( b * b ) - ( 4 * a * c ) ) < 0.0 ) {

		*imaginary = true;

		return;
	}
	// calculate roots if not imaginary
	else {

		*imaginary = false;

		*root1 = ( -b + sqrt( ( b * b ) - (4.0 * a * c ) ) ) / ( 2.0 * a );

		*root2 = ( -b - sqrt( ( b * b ) - (4.0 * a * c ) ) ) / ( 2.0 * a );

		return;
	}


}


int main() {
	
	double a = 0.0, b = 0.0, c = 0.0, root1 = 0.0, root2 = 0.0;

	bool imaginary = false;

	// print out the quadratic formula
	printf(" Given    Y = a(x^2) + b(x) + c,   and a can not = 0,\n\n");

	// input values a, b, c for the quatratic fucntion
	printf("Input a value for a\n> ");
	scanf_s("%lf",&a);

	printf("\nInput a value for b\n> ");
	scanf_s("%lf", &b);

	printf("\nInput a value for c\n> ");
	scanf_s("%lf", &c);

	// call quadratic function with inputs,
	// return roots and bool imaginary true or false.
	quadratic(a, b, c, &root1, &root2, &imaginary);

	if (imaginary == true) {

		printf("\nYou entered:\na = %lf\nb = %lf\nc = %lf\n\n", a, b, c);

		printf("\nRoots are imaginary.\n\n");
	}
	else {

		printf("\nYou entered:\na = %lf\nb = %lf\nc = %lf\n\n", a, b, c);

		printf("\nThe roots are:\nroot 1 = %lf\nroot 2 = %lf\n\n", root1, root2);

	}

	return 0;
}