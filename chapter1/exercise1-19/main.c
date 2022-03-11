/*
 *  Write a function reverse(s) that reverses the character string s. 
 *  Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

enum {
    MAXLINE = 1000  /*  maximum input line size */
};

int     getline(char []);
void    reverse(char []);

int main(void)
{
    char    line[MAXLINE];
    int     len;
    
    while ((len = getline(line)) > 0) {
        reverse(line);
        puts(line);
    }

    return 0;
}

/*  getline: read a line into s, return length  */
int getline(char s[])
{
    int c, i;
    
    for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

/*  reverse: reverses the character string s, return nothing   */
void reverse(char s[])
{
    char *p, temp;

    p = s;
    while (*p++) {
        ;
    }
    p--;
    if (*--p == '\n') {
        *p-- = '\0';
    }
    while (s < p) {
        temp    = *s;
        *s++    = *p;
        *p--    = temp;
    }
}
