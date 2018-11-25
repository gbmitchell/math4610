#include <stdio.h>
#include <math.h>
#include "mylib.h"

int main() {

	// create and initialize arguments
	double seps = 1.0;
	int ipow = 0;

	// call dmaceps function passing arguments by reference
	dmaceps(&seps, &ipow);

	// print the resulting values to the console
	printf("\n%d\t%.8e", ipow, seps);

	// keeps the console open until a key is pressed
	getch();

	return 0;
}
