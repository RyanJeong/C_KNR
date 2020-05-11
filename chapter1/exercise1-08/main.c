/*
 *  Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main(void)
{
    int c, nb, nt, nl;

    nb = nt = nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++nb;
        }
        if (c == '\t') {
            ++nt;
        }
        if (c == '\n') {
            ++nl;
        }
    }
    printf("Blanks: %d, Tabs: %d, Newlines: %d\n", nb, nt, nl);
  
    return 0;
}
