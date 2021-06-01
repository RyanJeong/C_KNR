#include <ctype.h>  /* isspace() */
#include <stdio.h>
#include <string.h> /* strcpy(), memcpy() */

#include "util.h"
#include "student.h"

static int offset;
static size_t size;

void setOffset(int i)
{
  offset = i;

  return;
}

int getOffset(void)
{

  return offset;
}

void setSize(size_t s)
{
  size = s;

  return;
}

size_t getSize(void)
{

  return size;
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

Student *studentDup(Student *obj)
{
  Student *ptr;
  int     size;

  size = getSize() + getOffset();
  ptr  = (Student *) calloc(size, sizeof(Student));
  memcpy(ptr, obj, getSize());
  setSize(size);

  return ptr;
}