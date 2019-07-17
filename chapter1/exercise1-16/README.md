```c
/*
 *  Revise the main routine of the longest-line program 
 *  so it will correctly print the length of arbitrary long input lines, 
 *  and as much as possible of the text.
 */

#include <stdio.h>
#define MAXLINE 1000		/*	maximum input line size	*/

int 	max;			/*	maximum length seen so far	*/
char 	line[MAXLINE];		/*	current input line	*/
char 	longest[MAXLINE];	/*	longest line saved here	*/

int 	_getline(void);
void 	_copy(void);

/*	print longest input line	*/
void main()
{
	int 		len;
	extern int 	max;
	extern char 	longest[];
	
	max = 0;
	while ((len = _getline()) > 0) {
		if (len > max) {
			max = len;
			_copy();
		}
	}
	if (max > 0) {
		/*	there was a line	*/
		printf("%s\n", longest);
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

/*	_copy: copy 'from' into 'to'; assume to is big enough	*/
void _copy()
{
	int 		i;
	extern char 	line[], longest[];
	
	i = 0;
	while ((longest[i] = line[i]) != '\0') {
		++i;
	}

	return;
}
```
