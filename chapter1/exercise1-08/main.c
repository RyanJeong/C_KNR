/*
 *  Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

void main()
{
  int c;
  int nb, nt, nl;

  nb = nt = nl;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++nb;
    }
    if (c == '\t') {
      ++nt;
    }
    if (c == '\n') {
      ++nl;
    }
  }
  printf("Blanks: %d, Tabs: %d, Newlines: %d\n", nb, nt, nl);
  
  return;
}
