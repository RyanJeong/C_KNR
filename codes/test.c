#include <stdio.h>
#include <ctype.h>

int skipWhite(FILE *f);

int main(void)
{
  char s[100];
  skipWhite(stdin);
  scanf("%s", s);
  printf("%s, %c(%d)", s, *s, *s);
  skipWhite(stdin);
  scanf("%s", s);
  printf("%s, %c(%d)", s, *s, *s);

  return 0;
}

int skipWhite(FILE *f)
{
  int c;

  do {
    c = getc(f);
  } while (isspace(c));

  return ungetc(c, f);
}