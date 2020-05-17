/*
 *  In a two's complement number representation, our version of itoa does not handle the largest negative number,
 *  that is, the value of n equal to -(2 to the power (wordsize - 1)). Explain why not.
 *  Modify it to print that value correctly regardless of the machine on which it runs.
 */
#include <stdio.h>
#include <limits.h>

#define ABS(n)  (((n > 0) - (n < 0)) * n)

void itoa(int, char *);
void reverse(char *);

int main(void)
{
    char buf[1 << 5];

    printf("INT_MIN: %d\n", INT_MIN);
    itoa(INT_MIN, buf);
    printf("After itoa : %s\n", buf);

    return 0;
}

void itoa(int n, char *buf)
{
    char    *p;
    int     sign;
    
    p       = buf;
    sign    = n;
    while (n) {
        *buf++  = ABS((n % 10)) + '0';
        n       /= 10;
    }
    if (sign < 0) {
        *buf++ = '-';
    }
    *buf = '\0';
    reverse(p);

    return;
}

void reverse(char *buf) 
{
    char c, *p;
    
    p = buf;
    while (*p != '\0') {
        ++p;
    }
    --p;    /*  one step before('\0')   */
    while (buf < p) {
        c       = *buf;
        *buf++  = *p;
        *p--    = c;    
    }

    return;
}
