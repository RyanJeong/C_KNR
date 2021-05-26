#include <stdio.h>

int main(void)
{
    char str1[10], str2[10], str3[10];

    /* input: suppression */
    scanf("%2s %*2s %4s %s", str1, str2, str3);
    /* output: */
    printf("%s %s %s\n", str1, str2, str3);

    return 0;
}