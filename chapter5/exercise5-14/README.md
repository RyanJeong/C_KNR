```Text
$cc alloc.c main.c line.c qsort.c -o sort -ansi
```
```C
/*  main.c  */
/*  Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order.
    Be sure that -r works with -n.  */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "line.h"
#include "qsort.h"

int order;  /*  1 if reserse order  */
/* sort input lines */
int main(int argc, char *argv[])
{
    char    *lineptr[MAXLINES]; /* pointers to text lines */
    int     nlines;             /* number of input lines read */
    int     numeric;            /* 1 if numeric sort */            
    int     c;                  /* temp */

    numeric = 0;    
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                order = 1;
                break;
            default:
                printf("sort: illegal option %c\n"
                       "Usage: sort [OPTION]\n"
                       "-n: numeric sort\n"
                       "-r: sorting in reverse order\n", c);
                
                return (-1);
            }
        }
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
```
```C
/*  alloc.h */
#ifndef __ALLOC_H__
#define __ALLOC_H__

enum {
    ALLOCSIZE   = 10000   /* size of available space */
};

char *alloc(int);
void afree(char *);
#endif
```
```C
/*  alloc.c */
#include "alloc.h"

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

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

/* free storage pointed to by p */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }

    return;
}
```
```C
/*  line.h  */
#ifndef __LINE_H__
#define __LINE_H__

enum {
    MAXLINES    = 5000, /* max #lines to be sorted */
    MAXLEN      = 1000  /* max length of any input line */
};

int     readlines(char *[], int);
int     getline(char *, int);
void    writelines(char *[], int);

#endif
```
```C
/*  line.c  */
#include <stdio.h>
#include <string.h>
#include "alloc.h"
#include "line.h"

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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }

    return;
}
```
```C
/*  qsort.h */
#ifndef __QSORT_H__
#define __QSORT_H__

void    qsort(void *[], int, int, int (*)(void *, void *));
int     numcmp(const char *, const char *);
double  atof(const char []);
void    swap(void *[], int, int);

#endif
```
```C
/*  qsort.c */
#include <ctype.h>
#include <string.h>
#include "qsort.h"

extern int order;  /*  1 if reserse order  */
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    void    swap(void *v[], int, int);
    int     i, last;

    if (left >= right) {    /* do nothing if array contains */

        return; /* fewer than two elements */
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if ((*comp)((order ? v[left] : v[i]), (order ? v[i] : v[left])) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);

    return;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {

        return -1;
    } else if (v1 > v2) {

        return 1;
    } else {

        return 0;
    }
}

/* atof: convert string s to double */
double atof(const char s[])
{
    double  val, power;
    int     i, sign;

    for (i = 0; isspace(s[i]); ++i) {   /* skip white space */
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = (10.0 * val + (s[i] - '0'));
    }
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = (10.0 * val + (s[i] - '0'));
        power *= 10;
    }

    return sign * val / power;
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
```
