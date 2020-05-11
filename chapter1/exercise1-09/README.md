```c
/*
 *  Write a program to copy its input to its output, 
 *  replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

enum {
    OFF,    /*  start of blank  */
    ON      /*  end of blank    */
};

int main(void)
{
    int c, state;

    state = OFF;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!state) {
                putchar(c);
                state = ON;
            }
        } else {
            putchar(c);
            state = OFF;
        }
    }
  
    return 0;
}
```
