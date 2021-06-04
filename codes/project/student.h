#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stdio.h>

#define SIZE_ID 8

typedef struct {
  char   id[SIZE_ID+1]; /* 8 + '\0' */
  char   *name;
  int    score;
  char   grade;
} Student;

void    setNum(size_t);
size_t  getNum(void);
void    setNamelen(int);
int     getNamelen(void);
int     getMaxNamelen(void);
void    setStudentPtr(Student *);
Student *getStudentPtr(void);

#endif