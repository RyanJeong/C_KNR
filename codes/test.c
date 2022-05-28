#include <stdio.h>

int main(void)
{
  int n;
  char c;

  /* > 1 d */
  scanf("%d", &n);
  getchar();
  scanf("%c", &c);
  /* int: 1, char: */
  printf("int: %d, char: %c\n", n, c);

  return 0;
}

int foo()
{
  int n;
  char c;

  /* A directive composed of ' ' will be ignore
     following while-space */
  scanf("%d %c", &n, &c);

  scanf("%d", &n);
  getchar();  /* use getchar() to consume ' ' */
  scanf("%c", &c);

  return 0;
}
