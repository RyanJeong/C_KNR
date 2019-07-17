```c
/*
 * Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces.
 * Don’t forget about quotes, both single and double, escape sequences, and comments.
 * (This program is hard if you do it in full generality.)
 * add check routine at () {} [] '' based on exerciese 1-23
 */

#include <stdio.h>
#define FALSE	0
#define TRUE	1

void	singleComment(void);
void	multiComment(void);
int	checkParen(void);
int	checkCurly(void);
int	checkSquare(void);
int	checkSingleQuote(void);

/*
 *	c		: used for getchar();
 *	isQuote		: check c is '"'
 *	isSlash		: check c is '/'
 */
void main()
{
	int c, isQuote, isSlash;

	isQuote = isSlash = FALSE;
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
					switch (c) {
						case '(':
							if (checkParen()) {
						
								return;
							}
							break;
						case '{':
							if (checkCurly()) {
						
								return;
							}
							break;
						case '[':
							if (checkSquare()) {
						
								return;
							}
							break;
						case '\'':
							if (checkSingleQuote()) {
						
								return;
							}
							break;
						case ')':
						case '}':
						case ']':
							puts("");
							puts("Syntax Error!");

							return;
						default:
							break;
					}
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

/*
 *	singleComment(void)	: get character until c = '\n'
 *
 *	c			: used for getchar();
 */
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

/*
 *	multiComment(void)	: get character until c_n = '*' && c_(n + 1) = '/'
 *
 *	c			: used for getchar();
 *	isAsterisk		: check c is '*'
 */
void multiComment(void)
{
	int c, isAsterisk;

	isAsterisk = FALSE;
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

/*
 *	checkParen(void)	: check syntax error on parenthesis
 *
 *	c			: used for getchar();
 */
int checkParen(void)
{
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
		if ((c == '(') || (c == ')') || (c == '\n')) {
			if (c != ')') {
				puts("");
				puts("Syntax Error!");
				
				return 1;
			}
			break;
		}
	}

	return 0;
}

/*
 *	checkCurly(void)	: check syntax error on curly brackets
 *
 *	c			: used for getchar();
 */
int checkCurly(void)
{
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
		if ((c == '{') || (c == '}') || (c == '\n')) {
			if (c != '}') {
				puts("");
				puts("Syntax Error!");
				
				return 1;
			}
			break;
		}
	}

	return 0;
}

/*
 *	checkSquare(void)	: check syntax error on square brackets
 *
 *	c			: used for getchar();
 */
int checkSquare(void)
{
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
		if ((c == '[') || (c == ']') || (c == '\n')) {
			if (c != ']') {
				puts("");
				puts("Syntax Error!");

				return 1;
			}
			break;
		}
	}

	return 0;
}

/*
 *	checkSingleQuote(void)	: check syntax error on single quote
 *
 *	c			: used for getchar();
 */
int checkSingleQuote(void)
{
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
		if ((c == '\'') || (c == '\n')) {
			if (c != '\'') {
				puts("");
				puts("Syntax Error!");
	
				return 1;
			}
			break;
		}
	}

	return 0;
}
```
