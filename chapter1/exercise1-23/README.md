```c
/*
 * Write a program to remove all comments from a C program. Don’t forget to handle quoted strings and character constants properly.
 * C comments don’t nest.
 */
#include <stdio.h>
#define FALSE	0
#define TRUE	1

void singleComment(void);
void multiComment(void);

/*
 *	c	: used for getchar();
 */
void main()
{
	int c, isQuote, isSlash;

	isQuote		= FALSE;
	isSlash		= FALSE;
	while ((c = getchar()) != EOF) {
		if (!isQuote) {
			if (c == '"') {
				isQuote = TRUE;
				putchar('"');
			} else {
				if (!isSlash && (c == '/')) {
					isSlash = TRUE;
				} else if (isSlash && (c == '/')) {
					isSlash = FALSE;
					singleComment();
				} else if (isSlash && (c == '*')) {
					isSlash = FALSE;
					multiComment();
				} else {
					if (isSlash) {
						putchar('/');
					}
					isSlash = FALSE;
					putchar(c);
				}
			}
		} else {
			if (c == '"') {
				isQuote = FALSE;
			}
			putchar(c);
		}
	}

	return;
}

void singleComment(void)
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			putchar('\n');
			break;
		}
	}	

	return;
}

void multiComment(void)
{
	int c, isAsterisk;

	isAsterisk	= FALSE;
	while ((c = getchar()) != EOF) {
		if (!isAsterisk && (c == '*')) {
			isAsterisk = TRUE;
		} else if (isAsterisk && (c == '/')) {
			break;
		} else {
			isAsterisk = FALSE;
		}
	}	

	return;
}

```
