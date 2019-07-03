```c
/*
 *  Verify the expression getchar() != EOF is 0 or 1.
 */
#include <stdio.h>

/* copy input to output; 2nd version */

main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		printf("%s%d\n", "c != EOF, ", c != EOF);
	}
	printf("%s%d\n", "c == EOF, ", c != EOF);
}
```
