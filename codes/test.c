#include <stdio.h>

struct {
    unsigned int a : 1;
    unsigned int b : 2;
    unsigned int c : 4;
    unsigned int   : 1; 
    unsigned int d : 8;
} flags;

int main(void)
{

    flags.a = 1;   /*         1 */
    flags.b = 2;   /*        10 */
    flags.c = 15;  /*      1111 */
    flags.d = 128; /* 1000 0000 */

    return 0;
}