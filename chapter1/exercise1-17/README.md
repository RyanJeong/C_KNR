```Text
$cc main.c -o run -ansi
```
```c
/*
 *  Write a program to print all input lines that are longer than 80 characters.
 */
 
#include <stdio.h>

enum {
    MAXLINE = 1000, /*  maximum input line size */
    MINLINE = 80    /*  minimum input line size */
};

int     getline(void);

char    line[MAXLINE];  /*  current input line  */

/*  print longest input line    */
int main(void)
{
    extern char longest[];
    int         len;

    while ((len = getline()) > 0) {
        if (len > MINLINE) {
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
