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
