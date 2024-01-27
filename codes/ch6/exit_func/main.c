#include <stdio.h>

/*
void bar(void);
void foo(void);
*/

void bar(void)
{
  exit(127);
}

void foo(void)
{
  printf("Before bar()\n");
  bar();
  printf("After bar()\n");
}

int main(void)
{
  printf("Before foo()\n");
  foo();
  printf("After foo()\n");

  return 0;
}