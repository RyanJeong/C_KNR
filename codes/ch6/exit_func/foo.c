#include <stdio.h>

void bar(void);

void foo(void)
{
  printf("Before bar()\n");
  bar();
  printf("After bar()\n");
}