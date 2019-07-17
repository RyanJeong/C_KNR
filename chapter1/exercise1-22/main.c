/*
 * Write a program to fold long input lines into two or more shorter lines after the last non-blank character 
 * that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines,
 * and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>
#include <stdlib.h>
#define ON	1
#define OFF	0

void main(void)
{
	/*
	 *	i	: use at for statement
	 *	n	: tab size
	 *	c	: getchar()'s buffer
	 *	max	: column size
	 *	index	: position of line
	 *	count	: number of white space
	 *	state	: check if input is white space
	 *	len	: size of buffer
	 *	skip	: skip white space when new line(except first line)
	 *	buffer	: temporary word buffer
	 */
	int	i, n, c, max, index, count, state, len, skip;
	char	*buffer, *pBuffer;

	index	= 0;
	count	= 0;
	len	= 0;
	skip	= OFF;
	state	= OFF;
	printf("Tab size?\n");
	scanf("%d", &n);
	getchar();
	printf("Column size?\n");
	scanf("%d", &max);
	getchar();
	buffer	= (char *) malloc(max + 1);
	pBuffer	= buffer;
	printf("Set tab size: %d, Column size: %d\n", n, max);
	while ((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\n') || (c == '\t')) {
			if (!state && len) {	//	input white space and buffer is not empty
				state = ON;
				if ((index + len) > max) {
					putchar('\n');
					index	= 0;
				}
				for (i = 0; i < len; ++i) {
					putchar(*(buffer + i));
					++index;
				}
				len 	= 0;
				pBuffer = buffer;
			}
			if (!skip) {		//	start a new line without white space
				++count;
			}
			switch (c) {
				case ' ':
					if ((index + count) > max) {
						putchar('\n');
						skip	= ON;
						index	= 0;
						count	= 0;
					} else if (!((index + count) % n)) {
						while (count) {
							++index;
							--count;
							putchar(' ');
						}
					}
					break;
				case '\t':
					count = n - (index % n);
					if ((index + count) > max) {
						putchar('\n');
						skip	= ON;
						index	= 0;
						count	= 0;
					} else {
						while (count) {
							++index;
							--count;
							putchar(' ');
						}
					}
					break;
				case '\n':
					putchar('\n');
					skip	= ON;
					index	= 0;
					count	= 0;
					break;
				default:
					break;
			}
		} else {
			state	= OFF;
			skip	= OFF;
			while (count) {
				++index;
				--count;
				putchar(' ');
			}
			*pBuffer++ = c;
			++len;
		}
	}
	free(buffer);	// free allocated memory
	
	return;
}
