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
