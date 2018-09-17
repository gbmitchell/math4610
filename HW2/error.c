#include <mylib.h>


int main() {

	double  approximate = 0.0;
	double exact = 0.0;
	double e = 0.0;

	approximate = 3.001;
	exact = 3.0;
	

	printf("x = %.8e, y = %.8e\n\n", approximate, exact);

    e = eabs(approximate, exact);
	printf("absolute error = %.8e\n", e);

	e = erel(approximate, exact);
	printf("relative error = %.8e\n\n\n", e);

	return 0;
}