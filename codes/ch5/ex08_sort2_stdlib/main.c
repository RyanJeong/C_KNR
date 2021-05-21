#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int  readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int  numcmp(const char *s1, const char *s2);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;      /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        /*
        void qsort (void *base, size_t num, size_t size,
                    int (*compar)(const void *,const void *));
        */
       /* TODO: Fix it, char ** */
        qsort(lineptr, nlines, sizeof(char *), 
              (int (*)(const void *,const void *)) (numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);

        return 0;
    } else {
        printf("input too big to sort\n");

        return 1;
    }
}