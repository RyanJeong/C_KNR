#ifndef __LINE_H__
#define __LINE_H__

enum {
    MAXLINES    = 5000, /* max #lines to be sorted */
    MAXLEN      = 1000  /* max length of any input line */
};

int     readlines(char *[], int);
int     getline(char *, int);
void    writelines(char *[], int);

#endif
