/*
 *  Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences
 *  like \n and \t as it copies the string t to s. Use a switch. 
 *  Write a function for the other direction as well, converting escape sequences into the real characters.
 */

#include <stdio.h>

#define MAX (1 << 8)

int     getline(char [], int);
void    escape(char *, char *);

int main(void)
{
    char s[MAX], t[MAX];

    getline(t, MAX);
    escape(s, t);
    printf("%s: %s\n%s: %s\n", "Before: ", t, "After: ", s);

    return 0;
}

/*  getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

void escape(char *s, char *t)
{
    char c;

    while ((c = *t++)) {
        switch (c) {
        case '\t':
            *s++ = '\\';
            *s++ = 't';
            break;
        case '\n':
            *s++ = '\\';
            *s++ = 'n';
            break;
        default:
            *s++ = c;
            break;
        }
    }
    *s = c;
}
