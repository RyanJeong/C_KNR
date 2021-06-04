#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__

#include "student.h"

enum {
    QUIT,
    ADD,
    DISPLAY,
    SEARCH,
    MODIFY,
    DELETE,
    DELETE_ALL,
    INVALID
};

void menu(void);

void run(char *);
char calcGrade(int);
void print(char *, char *, char *, char *);
void title(void);
void student(Student *);
int  getId(int);

void add(void);
void display(void);
void search(void);
void modify(void);
void delete(void);
void deleteAll(void);

#endif