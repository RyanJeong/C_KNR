#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* free() */
#include <string.h> /* strcpy() */

#include "file.h"
#include "management.h"
#include "util.h"    /* skipWhite(), cmp() */
#include "student.h" /* Student type, MAXNAME */

static char temp[MAXLINE];
static char *fname[] = {
  "",
  "add()",        /* ADD */
  "display()",    /* DISPLAY */
  "search()",     /* SEARCH */
  "modify()",     /* MODIFY */
  "delete()",     /* DELETE */
  "delete_all()"  /* DELETE_ALL */
};

void menu(void)
{
  printf("\n*** Student Score Management System ***\n"
         "\t------------------------\n"
         "\t[1] Add Student Record\n"
         "\t[2] Display Student List\n"
         "\t[3] Search Student Record (by ID)\n"
         "\t[4] Modify Student Record (by ID)\n"
         "\t[5] Delete Student Record (by ID)\n"
         "\t[6] Delete All Students\n"
         "\t[0] Save and Quit\n"
         "\t------------------------\n"
         "Enter your choice:");

  return;
}

void run(char *arg)
{

  return;
}

char calcGrade(int i)
{
  char grade;

  return grade;
}

void title(void)
{

  return;
}

void student(Student *ptr)
{

  return;
}

void print(char *s1, char *s2, char *s3, char *s4)
{

  return;
}

int isLine(int caller)
{

  return 1;
}

void add(void)
{

  return;
}

void display(void)
{

  return;
}

void search(void)
{

  return;
}

void modify(void)
{

  return;
}

void delete(void)
{

  return;
}

void deleteAll(void)
{

  return;
}