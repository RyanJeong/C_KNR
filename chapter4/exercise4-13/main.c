/*
 *  Write a recursive version of the function reverse(s), which reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

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
        printf("%d\n", len);
        if (line[len-2] == '\n') {
            line[len-2] = '\0';
        }
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

/*  reverse: reverses the character string s, recursive version, return nothing   */
void reverse(char s[])
{
    char *p, temp;

    p       = s + strlen(s) - 1;    /*  TODO: Fix it    */
    printf("%p %p\n", s, p);
    temp    = *s;
    *s++    = *p;
    *p--    = temp;
    if (s < p) {
        reverse(s);
    }

    return;
}
