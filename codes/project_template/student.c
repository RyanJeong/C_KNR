#include <stdio.h>  /* size_t */
#include <string.h> /* strlen() */

#include "util.h"   /* LABEL */
#include "student.h"

static size_t  num;
static int     namelen;
static Student *studentPtr;

void setNum(size_t s)
{
  num = s;
}

size_t getNum(void)
{
  return num;
}

void setNamelen(int i)
{
  namelen = i;
}

int getNamelen(void)
{
  return namelen;
}

int getMaxNamelen(void)
{
  Student *ptr, *high;
  int     namelen;

  ptr     = getStudentPtr();
  high    = ptr + getNum();
  for (namelen = strlen(LABEL2); ptr < high; ++ptr) {
    if (namelen < strlen(ptr->name)) {
      namelen = strlen(ptr->name);
    }
  }

  return namelen;
}

void setStudentPtr(Student *ptr)
{
  studentPtr = ptr;
}

Student *getStudentPtr(void)
{
  return studentPtr;
}