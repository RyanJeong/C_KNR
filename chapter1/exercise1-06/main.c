/*
 *  Verify the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

void main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		printf("%s%d\n", "c != EOF, value: ", c != EOF);
	}
	printf("%s%d\n", "c == EOF, value: ", c != EOF);
	
	return;
}
