#include <string.h>
#include <stdio.h>

struct a {
  int len;
  char *str;
};

int main(void)
{
  char s[] = "Hello, world!";
  int l = strlen(s);
  struct a sa = { l, s };
  struct a *p = &sa;

  /* increments len, not p implied parenthesization is ++(p->len) */
  ++p->len;
  sa.len = l;
  /* increments p before accessing len */
  (++p)->len;
  p = &sa;
  /* increments p afterward set of parentheses is unnecessary. */
  (p++)->len;
  p = &sa;
  p++->len;
  p = &sa;

  /* fetches whatever str points to */
  printf("%c\n", *p->str);
  /* increments str after accessing whatever it points to */
  printf("%c\n", *p->str++);
  /* increments whatever str points to */
  printf("%c\n", (*p->str)++);
  /* increments p after accessing whatever str points to */
  printf("%c\n", *p++->str);

  return 0;
}
