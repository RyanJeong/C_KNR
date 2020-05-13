/*
    #01: 1-4--97-2
    output: 123456789765432 
    #02: -a--z-c9-3f-a
    output: -abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedc9876543fedcba
    #03: 0-9a--z0---9
    output: 0123456789abcdefghijklmnopqrstuvwxyz0123456789
    #04: a-z-g-w-h
    output: abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihghijklmnopqrstuvwvutsrqponmlkjih
    #05: ----a--z--
    output: ----abcdefghijklmnopqrstuvwxyz--
    #06: f-w0-2a-f
    output: fghijklmnopqrstuvw012abcdef
    #07: 2-7
    output: 234567
    #08: a-9-g-3
    output: abcdefghijklmnopqrstuvwxyz0123456789abcdefghijklmnopqrstuvwxyz0123
    #09: a-c9-0
    output: abc9876543210
    #10: a-0-6b--pq-w9-0-3
    output: abcdefghijklmnopqrstuvwxyz0123456bcdefghijklmnopqrstuvw9876543210123
*/
/*
 *  Write a function expand(s1,s2) that expands shorthand notations
 *  like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
 *  Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 *  Arrange that a leading or trailing - is taken literally.
 */
#include <stdio.h>

#define SIZE 1000

void expand(char *, char *);

int main(void)
{
    char    *str[10], buf[SIZE];
    size_t  i;
    
    *(str + 0) = "1-4--97-2";
    *(str + 1) = "-a--z-c9-3f-a";
    *(str + 2) = "0-9a--z0---9";
    *(str + 3) = "a-z-g-w-h";
    *(str + 4) = "----a--z--";
    *(str + 5) = "f-w0-22-f";
    *(str + 6) = "2-7";
    *(str + 7) = "a-9-g-3";
    *(str + 8) = "a-c9-0";
    *(str + 9) = "a-0-6b--pq-w9-0-3";
    for (i = 0; i < 10; ++i) {
        expand(*(str + i), buf);
        printf("#%02lu: %s\noutput: %s\n", (i + 1), *(str + i), buf);
    }

    return 0;
}

void expand(char *s, char *t)
{
    size_t  src, dest;

    while (*s == '-') {
        ++s;
        *t++ = '-';
    }
    while (1) {
        if (*s == '\0') {
            break;
        } else if (*s != '-') { /*  -a0-    : next step will be in here */
            src = *s++;
            *t++ = src;
        } else {
            while (*s != '\0') {
                if (*s == '-') {
                    ++s;
                } else {
                    dest = *s++;    /*  a-a-a , a--a--a, ..., a------a : next step will be in here, */
                    if ((src >= '0') && (src <= '9')) {
                        if ((dest >= '0') && (dest <= '9')) {
                            while (src != dest) {
                                if (src > dest) {
                                    *t++ = --src;   
                                } else {
                                    *t++ = ++src;
                                }
                            }
                        } else if ((dest >= 'a') && (dest <= 'z')) {
                            while (src < '9') {
                                *t++ = ++src;
                            }
                            src = 'a';
                            while (src != dest) {
                                *t++ = src++;
                            }
                            *t++ = src;
                        }
                    } else if ((src >= 'a') && (src <= 'z')) {
                        if ((dest >= '0') && (dest <= '9')) {
                            while (src < 'z') {
                                *t++ = ++src;
                            }
                            src = '0';
                            while (src != dest) {
                                *t++ = src++;
                            }
                            *t++ = src;
                        } else if ((dest >= 'a') && (dest <= 'z')) {
                            while (src != dest) {
                                if (src > dest) {
                                    *t++ = --src;   
                                } else {
                                    *t++ = ++src;
                                }
                            }
                        }
                    }
                    break;
                }
            }
            if (*s == '\0') {
                break;
            }
        }
    }
    --s;
    while (*s-- == '-') {
        *t++ = '-';
    }
    *t = '\0';

    return;
}
