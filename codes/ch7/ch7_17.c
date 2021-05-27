#include <stdio.h>

int main(void)
{
    char str1[2], str2[10], str3[10];

    /* input: suppression */
    scanf("%2c %*2s %4s %6s", str1, str2, str3);
    /* output: */
    printf("%c%c %s %s\n", str1[0], str1[1], str2, str3);

    return 0;
}