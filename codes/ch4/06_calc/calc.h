#ifndef __CALC_CALC_H__
#define __CALC_CALC_H__

#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

#endif  /* __CALC_CALC_H__ */