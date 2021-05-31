#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>

#define DEFAULT_OFFSET 100
#define FUNC_LOAD "load()"
#define FUNC_SAVE "save()"

void setOffset(int);
int  getOffset(void);
int  skipWhite(FILE *);

#endif
