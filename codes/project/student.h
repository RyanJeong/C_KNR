#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stdio.h>

typedef struct {
  size_t idx;
  char   *name;
  int    score;
  char   grade;
} Student;
void   setIdx(size_t);
void   setNum(size_t);
size_t getIdx(void);
size_t getNum(void);
#endif
