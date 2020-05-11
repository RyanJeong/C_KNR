```c
/*
 * Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks
 * to achieve the same spacing. Use the same tab stops as for detab. 
 * When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
 */

#include <stdio.h>

int main(void)
{
    int n, c, index, count;

    index = count = 0;
    printf("Tab size?\n");
    scanf("%d", &n);
    getchar();  /*  skip '\n'   */
    printf("Set tab size: %d, expressed blank as +(purpose to check it works.)\n", n);
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++count;
            if (!((index + count) % n)) {
                while (count) {
                    ++index;
                    --count;
                    putchar(' ');
                }
            }
        } else if (c == '\t') {
            count = n - (index % n);
            while (count) {
                ++index;
                --count;
                putchar(' ');
            }
        } else {
            while (count) {
                ++index;
                --count;
                putchar('+');
            }
            putchar(c);
            (c == '\n') ? (index = 0) : ++index;        
        }
    }
    
    return 0;
}
```
