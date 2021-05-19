#include <stdlib.h>
#include <string.h>
#include "tree.h"

/* talloc: make a tnode */
struct tnode *talloc(void)
{

    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s)
{
    char *p;

    /* make a duplicate of s */
    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p) { /* p != NULL */
        strcpy(p, s);
    }

    return p;
}