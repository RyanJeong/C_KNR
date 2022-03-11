/*
 *  In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
 *  Explain why. Use this observation to write a faster version of bitcount .
 */
#include <stdio.h>

void bitcount(unsigned);

int main(void)
{
    int         c;
    unsigned    x, result;
    
    puts("Select mode, 1: input binary, 2: input decimal");
    c = getchar();
    if (getchar() != '\n') {
        puts("Error!");
        
        return 1;
    } else if (c == '1') {
        puts("Input x in binary");
        x = 0;
        while ((c = getchar()) != '\n') {
            x = (x << 1) + (c - '0');
        }
    } else if (c == '2') {
        puts("Input x in decimal");
        scanf("%u", &x);
        getchar();
    } else {
        puts("Error!");

        return 1;
    }
    bitcount(x);

    return 0;
}

void bitcount(unsigned x)
{
    int count;

    for (count = 0; x; ++count) {
        x &= (x - 1);
    }
    printf("count: %d\n", count);
}
