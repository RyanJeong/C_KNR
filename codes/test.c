#include <stdio.h>
#include <stdlib.h>


typedef struct{
  int a;
  int b;
  int c;
  int d;
  int e;
} S;

int main(void)
{
  S *s;

  s = (S *) calloc(10, sizeof(S));
  printf("%ld %ld\n", sizeof s, sizeof *s);

  return 0;
}