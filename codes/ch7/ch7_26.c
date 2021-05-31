#include <stdio.h>

/* fputs: put string s on file iop */
int fputs(char *s, FILE *iop)
{
    int c;
    
    while (c = *s++) {
        putc(c, iop);
    }

    /* returns EOF if an error occurs, and non-negative otherwise */
    return ferror(iop) ? EOF : 0;
}
