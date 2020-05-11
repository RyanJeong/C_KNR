#ifndef __QSORT_H__
#define __QSORT_H__

void    qsort(void *[], int, int, int (*)(void *, void *));
int     numcmp(const char *, const char *);
double  atof(const char []);
void    swap(void *[], int, int);

#endif
