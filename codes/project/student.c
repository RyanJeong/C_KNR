#include <stdio.h> /* size_t */

#include "student.h"

static size_t  num;
static int     namelen;
static Student *studentPtr;

void setNum(size_t s)
{
  num = s;

  return;
}

size_t getNum(void)
{

  return num;
}

void setNamelen(int i)
{
  namelen = i;

  return;
}

int getNamelen(void)
{

  return namelen;
}

void setStudentPtr(Student *ptr)
{
  studentPtr = ptr;

  return;
}

Student *getStudentPtr(void)
{

  return studentPtr;
}