```c
/*
 *	Write a function reverse(s) that reverses the character string s. 
 *	Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>
#define MAXLINE 1000		/*	maximum input line size	*/

char 	line[MAXLINE];		/*	current input line	*/

int 	_getline(void);

void main()
{
	int 		len;
	char		c;
	extern char 	line[];
	
	while ((len = _getline()) > 0) {
		while (line[len] == '\0') {
			--len;
		}
		while (line[len] == '\n') {
			--len;
		}
		while (len >= 0) {
			putchar(line[len--]);
		}	
		putchar('\n');
	}

	return;
}

/*	_getline: read a line into s, return length	*/

int _getline()
{
	int 		c, i;
	extern char 	line[];
	
	for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	
	return i;
}
```
