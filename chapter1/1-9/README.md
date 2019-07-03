```c
/*
 *  Write a program to copy its input to its output, 
 *  replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>
#define ON	1	/*	start of blank	*/
#define OFF	0	/*	end of blank	*/

void main()
{
  int c, state;

  state = OFF;
  while ((c = getchar()) != EOF) {
    if ((c == ' ') && (!state)) {
      putchar(c);
      state = ON;
    } else {
      putchar(c);
      state = OFF;
  }
  
  return;
}
```
