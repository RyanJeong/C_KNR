/*
 *  Verify the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

int main(void)
{
    int c;
    
    while ((c = getchar()) != EOF) {
        printf("%s%d\n", "c != EOF, value: ", c != EOF);
    }
    printf("%s%d\n", "c == EOF, value: ", c != EOF);
    
    return 0;
}
