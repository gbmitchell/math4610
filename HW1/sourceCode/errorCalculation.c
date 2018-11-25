#include <ctype.h>
#include <stdio.h>


int main() {

	// create and initialize arguments
	float seps1 = 1.0;
	int ipow = 0;

	// call dmaceps function passing arguments by reference
	smaceps(&seps1, &ipow);

	// print the resulting values to the console
	printf("\n%d\t%.8e", ipow, seps1);

	// create and initialize arguments
	double seps2 = 1.0;
	ipow = 0;

	// call dmaceps function passing arguments by reference
	dmaceps(&seps2, &ipow);

	// print the resulting values to the console
	printf("\n%d\t%.8e\n\n", ipow, seps2);

	return 0;
}
