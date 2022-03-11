/*
 *  Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions.
 */
#include <stdio.h>

unsigned    rightrot(unsigned, int);
void        printDecToBin(unsigned);
void        _printDecToBin(unsigned);

int main()
{
    int         n, c;
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
        puts("Input n");
        scanf("%d", &n);
        getchar();
    } else if (c == '2') {
        puts("Input x in decimal");
        scanf("%u", &x);
        getchar();
        puts("Input n");
        scanf("%d", &n);
        getchar();
    } else {
        puts("Error!");

        return 1;
    }
    result = rightrot(x, n);
    printf("Result in binary: ");
    printDecToBin(result);
    printf("\nResult in decimal :%u\n", result);

    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    unsigned    temp;
    int         count, c;

    if (x) {
        temp = x;
        for (count = 0; (temp >>= 1); ++count) {
            ;
        }
        printf("Length : %d\n", count);
        while (n--) {
            c = (x & 01);
            printDecToBin(c << count);
            puts("");
            x >>= 1;
            x |= (c << count);
        }
    }
        
    return x;
}

void printDecToBin(unsigned u)
{
    (u) ? _printDecToBin(u) : putchar('0');
}

void _printDecToBin(unsigned u)
{
    if (u) {
        _printDecToBin((u >> 1));   
        putchar((u & 01) + '0');
    }
}
