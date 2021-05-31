#include <ctype.h>  /* isspace() */
#include <stdio.h>
#include <string.h> /* strcpy() */
#include "util.h"

static int offset;

char *prog;

void setOffset(int i)
{
  offset = i;

  return;
}

int getOffset(void)
{

  return offset;
}

int skipWhite(FILE *f)
{
  int c;

  do {
    c = getc(f);
  } while (isspace(c));

  return ungetc(c, f);
}

char *strDup(char *s)
{
    char *p;

    /* make a duplicate of s */
    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p) { /* p != NULL */
        strcpy(p, s);
    }

    return p;
}