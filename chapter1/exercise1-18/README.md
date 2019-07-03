```c
/*
 *  Write a program to remove trailing blanks and tabs from each line of input, 
 *  and to delete entirely blank lines.
 */

/*
 *  Write a program to remove trailing blanks and tabs from each line of input, 
 *  and to delete entirely blank lines.
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
		for (--len; len; --len) {	//	init-expression: to skip null character
			c = line[len];
			if ((c != ' ') && (c != '\t') && (c != '\n')) {
				break;
			}
		}
		if (len) {
			line[len + 1]	= '\n';	//	recovery of excess parts
			line[len + 2]	= '\0';
			puts(line);
		}
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
