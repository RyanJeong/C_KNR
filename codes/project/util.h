#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include "student.h"

#define DEFAULT_OFFSET 100

void    setOffset(int);
int     getOffset(void);
void    setSize(size_t);
size_t  getSize(void);
int     skipWhite(FILE *);
char    *strDup(char *);
Student *studentDup(Student *obj);

#endif
