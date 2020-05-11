#ifndef __ALLOC_H__
#define __ALLOC_H__

enum {
    ALLOCSIZE   = 10000   /* size of available space */
};

char *alloc(int);
void afree(char *);
#endif
