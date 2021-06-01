#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stdio.h>

typedef struct {
  char   id[9]; /* 8 + '\0' */
  char   *name;
  int    score;
  char   grade;
} Student;

void    setNum(size_t);
size_t  getNum(void);
void    setNamelen(int);
int     getNamelen(void);
void    setStudentPtr(Student *);
Student *getStudentPtr(void);

#endif