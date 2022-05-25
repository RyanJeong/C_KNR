#include <stdio.h>

int main(void) /* rudimentary calculator */
{
  double sum, v;

  sum = 0;
  /* warning: the arguments to scanf and sscanf must be pointers. */
  while (scanf("%lf", &v) == 1) {
    printf("\t%.2f\n", sum += v);
  }

  return 0;
}
