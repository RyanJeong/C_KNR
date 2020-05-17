/*
 *  for (i = 0; (i < (lim - 1)) && ((c = getchar()) != '\n') && (c != EOF); ++i) {
 *      s[i] = c;
 *  }
 *
 *  Write a loop equivalent to the for loop above without using && or ||.
 */

#include <stdio.h>

enum {
    MAX = 100
};

int main(void)
{
    char    s[MAX];
    int     c, i, lim;

    lim = (MAX - 1);
    for (i = 0; ((c = getchar()) != EOF); ++i) {
        if (i == lim) {
            break;
        }
        if (c == '\n') {
            break;
        }
        s[i] = c;
    }
    s[i] = '\0';
    puts(s);

    return 0;
}
