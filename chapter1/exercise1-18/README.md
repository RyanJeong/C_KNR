```Text
$cc main.c -o run -ansi
```
```c
/*
 *  Write a program to remove trailing blanks and tabs from each line of input, 
 *  and to delete entirely blank lines.
 */

#include <stdio.h>

enum {
    MAXLINE = 1000  /*  maximum input line size */
};

int     getline(void);

char    line[MAXLINE];      /*  current input line  */

int main(void)
{
    extern char line[];
    char        c;
    int         len;
    
    while ((len = getline()) > 0) {
        for (--len; len; --len) {   /*  init-expression: to skip null character */
            c = line[len];
            if ((c != ' ') && (c != '\t') && (c != '\n')) {
                break;
            }
        }
        if (len) {
            line[len + 1]   = '\n'; /*  recovery of excess parts    */
            line[len + 2]   = '\0';
            puts(line);
        }
    }

    return 0;
}

/*  getline: read a line into s, return length  */
int getline()
{
    extern char line[];
    int         c, i;
    
    for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    
    return i;
}
```
