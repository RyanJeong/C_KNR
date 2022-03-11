#include <stdlib.h>
#include <stdio.h>

void f(void)
{
  printf("Before exit()\n");
  exit(127);
  printf("After exit()\n");
}