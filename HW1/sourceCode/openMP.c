#include <stdio.h>

int main() {

	// create and initialize variables
	int i = 0, id = 0, nthrds = 0;

	// begin parallel threads
	#pragma omp parallel private(id)
	{
		id = omp_get_thread_num();
		printf("hellow world from thread %d\n", id);

	// each thread executes and waits at the barrier, when all
	// threads arrive at the barrier then each one continues.
	// if statement allows only thread 0 to print nthrds.
	#pragma omp barrier
		if (id == 0) {
			nthrds = omp_get_num_threads();
			printf("There are %d threads!", nthrds);
		}
	}

	printf("\n\n\n");

	return 0;
}