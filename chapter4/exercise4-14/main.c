/*
 *  Define a macro swap(t, x, y) that interchanges two arguments of type t. (Block structure will help.)
 */

#include <stdio.h>

#define swap(t, x, y) do {  \
    t z;                    \
                            \
    z = x;                  \
    x = y;                  \
    y = z;                  \
} while (0);

int main(void)
{
    int a, b;

    a = 3;
    b = 4;
    printf("a: %d, b: %d\n", a, b);
	swap(int, a, b);
    printf("a: %d, b: %d\n", a, b);

	return 0;
}
