#include <stdio.h>

void swap1(int a, int b) /* call by value */
{
    int temp;

    temp = a;
    a    = b;
    b    = temp;
}

void swap2(int *a, int *b) /* call by address */
{
    int temp;

    temp = *a;
    *a   = *b;
    *b   = temp;
}

int main(void)
{
    int a, b;

    a = 3;
    b = 4;
    printf("Before calling function swap1, a: %d, b : %d\n", a, b);
    swap1(a, b);
    printf("After calling function swap1, a: %d, b : %d\n", a, b);
    printf("Before calling function swap2, a: %d, b : %d\n", a, b);
    swap2(&a, &b);
    printf("After calling function swap2, a: %d, b : %d\n", a, b);

    return 0;
}