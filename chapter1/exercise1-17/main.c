/*
 *  Write a program to print all input lines that are longer than 80 characters.
 */
 
#include <stdio.h>
#define MAXLINE 1000	/*	maximum input line size	*/
#define MIN     80

int 	_getline(void);

char 	line[MAXLINE];	/*	current input line	*/

/*	print longest input line	*/
void main()
{
	int 		len;
	extern char 	longest[];
	
	while ((len = _getline()) > 0) {
		if (len > MIN) {
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
