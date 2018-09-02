#include <stdio.h>
#include <math.h>


void smaceps(float *seps, int *ipow) {

	// create an initialize function variables
	// initialized to find machine value near 1.0
	float one = 0.0, appone = 0.0;
	int i = 0;
	one = 1.0;
	*seps = 1.0;
	appone = one + *seps;
	*ipow = 0;

	// loop, dividing by 2 each time to determine when the difference
	//  between one and the approximation is zero in single precision
	for (i = 0; i < 1000; i++) {
		*ipow = *ipow + 1;
		*seps = *seps / 2.0;
		appone = one + *seps;
		if (fabs(appone - one) == 0.0) return;
	}

	// print error message to console if loops more than 1000 times
	// code should never reach this point unless there is an error
	printf("The loop limit has been exceeded");

	return;
}

int main() {

	// create and initialize arguments
	float seps = 1.0;
	int ipow = 0;

	// call smaceps function passing arguments by reference
	smaceps(&seps, &ipow);

	// print the resulting values to the console
	printf("\n%d\t%.8e", ipow, seps);

	// keeps the console open until a key is pressed
	getch();

	return 0;
}
