#include <stdio.h>

int ungetc(int c, FILE *fp);

int skipWhite(FILE *f)
{
  int c;

  do {
    c = getc(f);
  } while (isspace(c));

  return ungetc(c, f);
}
