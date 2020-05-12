/*
 *  Write the function any(s1,s2), which returns the first location in the string s1 where any character from the string s2 occurs,
 *  or -1 if s1 contains no characters from s2.
 *  (The standard library function strpbrk does the same job but returns a pointer to the location.)
 */
#include <stdio.h>

enum {
    MAX = 100
};

void any(char *, char *);

int main(void)
{
    char    s1[MAX], s2[MAX];

    puts("Input s1");
    scanf("%s", s1);
    getchar();
    puts("Input s2");
    scanf("%s", s2);
    getchar();
    printf("s1: %s, s2: %s\n", s1, s2);
    any(s1, s2);

    return 0;
}

void any(char *s1, char *s2)
{
    char    *p_s1;

    while (*s2) {
        p_s1 = s1;
        for (p_s1 = s1; *p_s1; ++p_s1) {
            if (*p_s1 == *s2) {
                break;
            }
        }
        printf("%c\'s location: %d\n", *s2++, (!*p_s1) ? (-1) : (int) (p_s1 - s1));
    }

    return;
}
