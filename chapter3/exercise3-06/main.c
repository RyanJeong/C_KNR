/*
 *  Write a version of itoa that accepts three arguments instead of two.
 *  The third argument is a minimum field width;
 *  the converted number must be padded with blanks on the left if necessary to make it wide enough.
 */

#include <stdio.h>
#include <limits.h>

#define ABS(n)  (((n > 0) - (n < 0)) * n)
#define SIZE    (1 << 5)

void itoa(int, char *, size_t);
void reverse(char *);

int main(void)
{
    int     a, b, c, d, e;
    char    buf[SIZE];

    a   = 102;
    b   = -2345;
    c   = 502831;
    d   = -9987734;
    e   = 1702523523;
    itoa(a, buf, SIZE);
    printf("a: %s\n", buf);
    itoa(b, buf, SIZE);
    printf("b: %s\n", buf);
    itoa(c, buf, SIZE);
    printf("c: %s\n", buf);
    itoa(d, buf, SIZE);
    printf("d: %s\n", buf);
    itoa(e, buf, SIZE);
    printf("e: %s\n", buf);

    return 0;
}

void itoa(int n, char *buf, size_t width)
{
    char    *p;
    int     sign;
    size_t  count;
    
    count   = 0;
    p       = buf;
    sign    = n;
    while (n) {
        *buf++  = ABS((n % 10)) + '0';
        n       /= 10;
        ++count;
    }
    if (sign < 0) {
        *buf++ = '-';
        ++count;
    }
    while (count < SIZE) {
        *buf++ = ' ';
        ++count;
    }
    *buf = '\0';
    reverse(p);
}

void reverse(char *buf) 
{
    char c, *p;
    
    p = buf;
    while (*p != '\0') {
        ++p;
    }
    --p;    /* one step before('\0')    */
    while (buf < p) {
        c       = *buf;
        *buf++  = *p;
        *p--    = c;    
    }
}
