/*
 * Write a program to fold long input lines into two or more shorter lines after the last non-blank character 
 * that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines,
 * and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>
#include <stdlib.h>
#define ON	1	//	start word
#define OFF	0	//	end word

/*
 *	count		= number of characters
 *	copy_count	= number of characters copied
 *	state		= check character is blank
 *	pBuffer		= pointer of buffer
 *	pLine		= pointer of line
 */

void main()
{
	int column;
	int c, count, state, copy_count;
	char *buffer, *line, *pBuffer, *pLine;

	state	= OFF;
	count	= 0;
	printf("Input max column: ");
	scanf("%d", &column);
	getchar();
	buffer	= (char *) malloc(column + 1);
	line	= (char *) malloc(column + 1);
	pBuffer	= buffer;
	pLine	= line;
	while ((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\n') || (c == '\t')) {
			state = ON;
			if (c == '\n') {
				*pBuffer = '\0';
				if (count > column) {
					if (pLine != line) {	// if line is empty(first word) 
						*pLine	= '\0';
						puts(line);	
						pLine	= line;
					}
					puts(buffer);
				} else {
					pBuffer = buffer;	//	set to start address of buffer
					while ((*pLine++ = *pBuffer++)) {
						;
					}
					puts(line);
					pLine = line;
				}
				pBuffer	= buffer;
				count	= 0;
			}
			if (count) {
				++count;
				*pBuffer++ = c;
			}
		} else {
			if (state) {
				*pBuffer	= '\0';
				copy_count	= 0;
				state		= OFF;
				if (count > column) {
					if (pLine != line) {
						*pLine	= '\0';
						puts(line);	// if line is empty(first word) 
						pLine	= line;
						count = 0;
					}
				}
				pBuffer = buffer;	// set to start address of buffer
				while ((*pLine++ = *pBuffer++)) {
					++copy_count;	//	count characters copied
				}
				if (!count) {
					count += copy_count;	//	pass a value if new line
				}
				pBuffer = buffer;	// set to start address of buffer
				--pLine;	//	null escape purpose
			}
			++count;
			*pBuffer++ = c;
		}
		// printf("state: %d, count: %d\n", state, count);
		// printf("%s%s\n%s%s\n", "Buffer: ", buffer, "Line: ", line);
	}
	free(line);
	free(buffer);

	return;
}
//c == '\n || count ? colummn??
