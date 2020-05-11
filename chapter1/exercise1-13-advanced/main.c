/*
 *  Write a program to print a histogram 
 *  of the lengths of words in its input. 
 *  Draw the histogram with the bars vertical.
 */

#include <stdio.h>

enum {
    MAX = 1000
};

/*
 *  c           = get character
 *  nc          = length of word
 *  i, j        = for statement variable
 *  count       = count of words
 *  max         = max length of word
 *  lenOfWord   = lists of length of words
 */
int main(void)
{
    int c, nc, i, j, count, max;
    int lenOfWord[MAX];

    count = nc = max = 0;
    while ((c = getchar()) != EOF) {
        if ((c == ' ') || (c == '\t') || (c == '\n')) {
            lenOfWord[count++] = nc;
            max = (nc > max) ? nc : max;
            nc  = 0;
        } else {
            ++nc;
        }
    }
    for (i = 0; i < max; ++i) {
        for (j = 0; j < count; ++j) {
            if (lenOfWord[j]) {
                putchar('*');
                --lenOfWord[j];
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}
