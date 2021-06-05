#include <stdio.h>

int main(void)
{
  int a[] = {1, 2, 3, 4, 5};

  printf("%d %d\n", *(a+3), a[3]);

  return 0;
}