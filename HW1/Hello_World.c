#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;

	printf("How many times?\n\n> ");

	scanf_s("%d", &j);

	printf("\n");

	for (i = 0; i < j; i++ ) {
		printf("Hello World\n\n");
	}

	scanf_s("%d", &j);

	return 0;
}