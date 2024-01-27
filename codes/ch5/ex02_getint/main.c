#include <stdio.h>

enum { SIZE = 5 };

int main(void)
{
  int n, array[SIZE], getint(int *);

  for (n = 0; n < SIZE && getint(&array[n]) != EOF; ++n) {}
  for (n = 0; n < SIZE; ++n)
    printf("%d ", array[n]);

  return 0;
}
