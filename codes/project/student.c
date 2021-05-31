#include <stdio.h>
#include "student.h"

static size_t idx;
static size_t num;

void setIdx(size_t s)
{
  idx = s;

  return;
}

void setNum(size_t s)
{
  num = s;

  return;
}

size_t getIdx(void)
{

  return idx;
}

size_t getNum(void)
{

  return num;
}
