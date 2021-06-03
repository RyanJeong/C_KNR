#include <stdlib.h>
#include <string.h>

char *strDup(char *s)
{
    char *p;

    /* make a duplicate of s */
    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p) { /* p != NULL */
        strcpy(p, s);
    }

    return p;
}