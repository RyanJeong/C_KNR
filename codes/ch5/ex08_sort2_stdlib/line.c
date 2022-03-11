#include <stdio.h>
#include <string.h>

#define MAXLEN 1000 /* max length of any input line */

int  getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int  len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
    
            return -1;
        } else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

/* writelines can be written instead as */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}