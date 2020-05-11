```c
/*
 *  Write a program that prints its input one word per line.
 */

#include <stdio.h>

int main(void)
{
    int c;
  
    while ((c = getchar()) != EOF) {
        if ((c == ' ') || (c == '\t')) {
            c = '\n';
        }
        putchar(c);
    }
  
    return 0;
}
```
