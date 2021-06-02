#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__

enum {
    QUIT,
    ADD,
    DISPLAY,
    SEARCH,
    MODIFY,
    DELETE,
    DELETE_ALL
};

void run(char *);
char calcGrade(int);
void menu(void);
void add(void);
void display(void);
void search(void);
void modify(void);
void delete(void);
void deleteAll(void);

#endif