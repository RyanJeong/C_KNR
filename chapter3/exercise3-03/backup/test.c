#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	size_t *a, *b;
	size_t i;

	a = (size_t *) malloc(sizeof(size_t) * 20);
	b = a;
	for (i = 0; i < 5; ++i) {
		*(a++ + i) = i;
	}
	for (i = 0; i < 20; ++i) {
		printf("%lu ", *(b + i));
	}
	free(b);

	return 0;
}
