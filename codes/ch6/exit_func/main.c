#include <stdio.h>

void foo(void);

int main(void)
{
  printf("Before foo()\n");
  foo();
  printf("After foo()\n");

  return 0;
}