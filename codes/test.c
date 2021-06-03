#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
  int a;
  int b;
  int c;
  int d;
  int e;
} S;

int main(void)
{
  S *s = (S *) calloc(10, sizeof(S));

  printf("%lu\n", sizeof s);
  printf("%lu\n", sizeof *s);

  return 0;
}