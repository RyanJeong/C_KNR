#include <stdio.h>

int main(void)
{
    /* a minus sign with minimum width */
    printf("%6d\n",  100);
    printf("%-6d\n", 100);
    printf("%6d\n",  1000000);
    printf("%-6d\n", 1000000);

    /* string with precision */
    printf("%6.3s\n",  "ABCDE");
    printf("%-6.3s\n", "ABCDE");
    printf("%6.6s\n",  "ABCDE");
    printf("%-6.6s\n", "ABCDE");

    /* floating type value with precision */
    printf("%9.2f\n",  3.141592);
    printf("%-9.2f\n", 3.141592);
    printf("%9.6f\n",  3.141592);
    printf("%-9.6f\n", 3.141592);

    /* integer type value with precision */
    printf("%.5d\n",   12);
    printf("%5.5d\n",  1234);
    printf("%8.5d\n",  1234);
    printf("%-8.5d\n", 1234);
    printf("%8.5d\n",  123456);
    printf("%-8.5d\n",  123456);

    /* convert integer type to short or long */
    printf("%.4hd\n",   (short) 123);
    printf("%6.4hd\n",  (short) 123);
    printf("%.2ld\n",   (long)  123);
    printf("%6.5ld\n", (long)  123);
    printf("%-6.5ld\n", (long)  123);

    return 0;
}