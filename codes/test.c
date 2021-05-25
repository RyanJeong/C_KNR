#include <stdio.h>

int main(void)
{
    char s[100];
    int  len, a, b;
    
    a = 3;
    b = 5;
    len = sprintf(s, "%d + %d = %d", a, b, a + b);
    printf("%s, len: %d\n", s, len); /* 3 + 5 = 8, len: 9 */

    return 0;
}