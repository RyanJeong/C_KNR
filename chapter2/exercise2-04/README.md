```c
/*
 *  Write an alternate version of squeeze(s1,s2) that deletes each character in the string s1 that matches any character in the string s2.  
 */
#include <stdio.h>

enum {
    MAX = 100
};

void squeeze(char *, char *);

int main(void)
{
    char    s1[MAX], s2[MAX];
    int     c, i, limit;

    limit = (MAX - 1);
    puts("Input s1");
    for (i = 0; ((c = getchar()) != EOF); ++i) {
        if (i == limit) {
            while (getchar() != '\n') {
                ;
            }
            break;
        }
        if (c == '\n') {
            break;
        }
        s1[i] = c;
    }
    s1[i] = '\0';
    puts("Input s2");
    for (i = 0; ((c = getchar()) != EOF); ++i) {
        if (i == limit) {
            while (getchar() != '\n') {
                ;
            }
            break;
        }
        if (c == '\n') {
            break;
        }
        s2[i] = c;
    }
    s2[i] = '\0';
    printf("s1: %s, s2: %s\n", s1, s2);
    squeeze(s1, s2);
    printf("result: %s\n", s1);

    return 0;
}

void squeeze(char *s1, char *s2)
{
    char    *p_s1;
    int     c, i;

    while ((c = *s2++)) {
        p_s1 = s1;
        for (i = 0; *(s1 + i); ++i) {
            if (*(s1 + i) != c) {
                *p_s1++ = *(s1 + i);
            }
        }
        *p_s1 = '\0';
    }

    return;
}
```
