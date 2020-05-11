/*  Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order.
    Be sure that -r works with -n.  */
#include <ctype.h>
#include <stdio.h>
#include "qsort.h"

enum {
    MAXLINES    = 5000,   /* max #lines to be sorted */
    MAXLEN      = 1000,   /* max length of any input line */
    ALLOCSIZE   = 10000   /* size of available space */
};

int     readlines(char *[], int);
int     getline(char *, int);
char    *alloc(int);
void    writelines(char *[], int);
void    strcpy(char *, char *);

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */
char        *lineptr[MAXLINES];     /* pointers to text lines */

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;         /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *)) (numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);

        return 0;
    } else {
        printf("input too big to sort\n");

        return 1;
    }
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

    return;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
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

/*getline: read a line into s, return length*/
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

/* return pointer to n characters */
char *alloc(int n)
{
    /* it fits */
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;

        /* old p */
        return allocp - n;
    } else {

        /* not enough room */
        return 0;
    }
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }

    return;
}

/*  strcpy: copy t to s;    */
void strcpy(char *s, char *t)
{
    while (*s++ = *t++) {
        ;
    }

    return;
}
