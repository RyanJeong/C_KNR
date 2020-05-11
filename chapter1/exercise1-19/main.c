/*
 *  Write a function reverse(s) that reverses the character string s. 
 *  Use it to write a program that reverses its input a line at a time.
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
        while (line[len] == '\0') {
            --len;
        }
        while (line[len] == '\n') {
            --len;
        }
        while (len >= 0) {
            putchar(line[len--]);
        }   
        putchar('\n');
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
