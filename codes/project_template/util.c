#include <ctype.h>  /* isspace() */
#include <string.h> /* strcpy(), memcpy() */
#include <stdlib.h> /* malloc() */

#include "student.h" /* Student type */
#include "util.h"

static int    offset;
static size_t size;

void setOffset(int i)
{
  offset = i;
}

int getOffset(void)
{
  return offset;
}
void setSize(size_t s)
{
  size = s;
}

size_t getSize(void)
{
  return size;
}

/*reverse: reverse string s in place*/
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = (strlen(s) - 1); i < j; ++i, --j) {
        c    = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) { /* record sign     */
        n = (-n);         /* make n positive */
    }
    i = 0;
    do {
        s[i++] = (n % 10) + '0'; /* get next digit */
    } while ((n /= 10) > 0);     /* delete it      */
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int skipWhite(FILE *f)
{
  int c;

  do {
    c = getc(f);
  } while (isspace(c));

  return ungetc(c, f);
}

int getLine(char *line, int max)
{
  char *pos;

  /* call fgets() after skipWhite() to ignore white-space */
  skipWhite(stdin);
  /*   The fgets() function returns a pointer to the string buffer if successful. 
     A NULL return value indicates an error or an end-of-file condition. */
  if (fgets(line, max, stdin) == NULL) {

    return -1;
  } else {
    /* erase '\n' from the line */
    if ((pos = strrchr(line, '\n'))) {
      *pos = '\0';
    }

    return strlen(line);
  }
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

  ptr = (Student *) calloc(getNum() + getOffset(), sizeof(Student));
  memcpy(ptr, obj, getSize());
  free(obj);

  return ptr;
}

int cmpIds(const void *id1, const void *id2)
{

  return strcmp((char *) id1, (char *) id2);
}

int cmp(const void *id, const void *student)
{

  return strcmp((char *) id, ((Student *) student)->id);
}