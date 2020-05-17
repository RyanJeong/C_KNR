/*
 *  Write a program to determine the ranges of char, short, int, and long variables, 
 *  both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
 *  Harder if you compute them: determine the ranges of the various floating-point types.
 */
#include <stdio.h>

int main(void)
{
    printf("Minimum Signed Char\t: %d\n",
        (((unsigned char) ~0 >> 1) * (-1)) - 1);
    printf("Maximum Signed Char\t: %d\n",
        ((unsigned char) ~0 >> 1));
    printf("Maximum Unsigned Char\t: %d\n",
        (unsigned char) ~0);
    printf("Minimum Signed Short\t: %d\n",
        (((unsigned short) ~0 >> 1) * (-1)) - 1);
    printf("Maximum Signed Short\t: %d\n",
        ((unsigned short) ~0 >> 1));
    printf("Maximum Unsigned Short\t: %d\n",
        (unsigned short) ~0);
    printf("Minimum Signed Int\t: %d\n",
        (((unsigned int) ~0 >> 1) * (-1)) - 1);
    printf("Maximum Signed Int\t: %d\n",
        ((unsigned int) ~0 >> 1));
    printf("Maximum Unsigned Int\t: %u\n",
        (unsigned int) ~0);
    printf("Minimum Signed Long\t: %ld\n",
        (((unsigned long) ~0 >> 1) * (-1)) - 1);
    printf("Maximum signed Long\t: %ld\n",
        ((unsigned long) ~0 >> 1));
    printf("Maximum Unsigned Long\t: %lu\n",
        (unsigned long) ~0);

    return 0;
}
