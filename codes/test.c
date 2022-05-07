#include <stdio.h>

#define WORLD "hello"
#define HELLO WORLD
#define HI HELLO  /* HI -> WORLD */

#define MAX(a, b) ((a > b) ? a : b)

#define SQUARE(x) (x) * (x)

#define dprint(expr) printf(#expr " = %g\n", expr)

void foo()
{
  int x = 10, y = 20;
  int *ip = &x;

  y = *ip + 1;  /* y is now 11 */
  printf("x: %d, y: %d\n", x, y);
  *ip += 1;  /* x is now 11 */
  printf("x: %d, y: %d\n", x, y);
  ++*ip;  /* x is now 12 */
  printf("x: %d, y: %d\n", x, y);
  (*ip)++;  /* x is now 13 */
  printf("x: %d, y: %d\n", x, y);
}
int main(void)
{
  int a[] = {1, 2, 3, 4, 5};

  printf("%d %d\n", *(a+3), a[3]);
  /* printf("%d\n", b); */

  int b = 400;
  printf("%d\n", b);
  printf("%s\n", WORLD);
  int x = 100;
  int y = 200;

  int i = 0;
  int j = 0;
  MAX(i++, j++);  /* ((i++ > j++) ? i++ : j++) */

  printf("%d\n", MAX(x, y)); /* printf("%d\n", ((x > y) ? x : y)) */

  SQUARE(x + 1);  /* x + 1 * x + 1 */

  dprint(x/y);

  printf("x/y" " = &g\n", x/y);

  /* the strings are concatenated, so the effect is */
  printf("x/y = &g\n", x/y);

  foo();

  return 0;
}
