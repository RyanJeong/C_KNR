#include <stdio.h>

int main(void)
{
  int a, b;

  while (scanf("%d %d", &a, &b) != EOF)
    printf("%d + %d = %d\n", a, b, a + b);

  return 0;
}
