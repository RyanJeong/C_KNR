/*
 *  Write the function itob(n, s, b)
 *  that converts the integer n into a base b character representation in the string s.
 *  In particular, itob(n, s, 16) formats n as a hexadecimal integer in s.
 */

#include <stdio.h>

#define ABS(n)  (((n > 0) - (n < 0)) * n)

void itoa(int, char *, int);
void reverse(char *);

int main()
{
    char    buf[1 << 5];
    int     pos, neg;
    size_t  i;

    pos = 254;
    neg = -127;
    for (i = 2; i <= 16; i <<= 1) {
        itoa(pos, buf, i);
        printf("%d converts into a base %lu: %s\n", pos, i, buf);
        itoa(neg, buf, i);
        printf("%d converts into a base %lu: %s\n", neg, i, buf);
    }
     
    return 0;
}

void itoa(int n, char *s, int b)
{
    char    *p;
    int     sign;
    size_t  temp;
    
    p       = s;
    sign    = n;
    do {
        temp = ABS(n % b);
        *s++ = (temp > 10) ? (temp - 10 + 'a') : (temp + '0'); 
    } while (n /= b);
    if (sign < 0) {
        *s++ = '-';
    }
    *s = '\0';
    reverse(p);
}

void reverse(char *s) 
{
    char c, *p;
    
    p = s;
    while (*p != '\0') {
        ++p;
    }
    --p;    /*  one step before('\0')   */
    while (s < p) {
        c       = *s;
        *s++  = *p;
        *p--    = c;    
    }
}
