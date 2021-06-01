#ifndef __SCORE_H__
#define __SCORE_H__

enum {
    QUIT,
    ADD,
    DISPLAY,
    SEARCH,
    MODIFY,
    DELETE,
    DELETE_ALL
};

void run(void);
void menu(void);

#endif