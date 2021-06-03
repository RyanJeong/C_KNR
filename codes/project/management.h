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

void run(char *);
char calcGrade(int);
void menu(void);
void display(void);
void format(void);
void student(Student *);

void add(void);
void search(void);
void modify(void);
void delete(void);
void deleteAll(void);

#endif