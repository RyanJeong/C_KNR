/*  
 *  Write a program to print a histogram of the frequencies of different characters in its input.
 */
 
#include<stdio.h>

#define TNO 128 /*  Total number of characters is 128: 0 - 127 */

int count[TNO]; /*  init. all elements to 0 */

void main(void)
{
  int c, i;
  
  while ((c = getchar()) != EOF) {
    ++count[c];
  }
  for (i = 0; i < TNO; ++i) {
    putchar(i);
    while (count[i]) {
      putchar('*');
      --count[i];
    }
    putchar('\n');
  }
  
  return;
}
