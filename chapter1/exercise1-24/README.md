```c
/*
 * Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces.
 * Don’t forget about quotes, both single and double, escape sequences, and comments.
 * (This program is hard if you do it in full generality.)
 * add check routine at () {} [] '' based on exerciese 1-23
 */

#include <stdio.h>

enum {
    FALSE,
    TRUE
};

void    singleComment(void);
void    multiComment(void);
int     checkParen(void);
int     checkCurly(void);
int     checkSquare(void);
int     checkSingleQuote(void);

int main(void)
{
/*
 *  c       : used for getchar();
 *  isQuote     : check c is '"'
 *  isSlash     : check c is '/'
 */
    int c, isQuote, isSlash;

    isQuote = isSlash = FALSE;
    while ((c = getchar()) != EOF) {
        if (!isQuote) {
            if (c == '"') {
                isQuote = TRUE;
                putchar('"');
            } else {
                if (!isSlash && (c == '/')) {
                    isSlash = TRUE;
                } else if (isSlash && (c == '/')) {
                    isSlash = FALSE;
                    singleComment();
                } else if (isSlash && (c == '*')) {
                    isSlash = FALSE;
                    multiComment();
                } else {
                    if (isSlash) {
                        putchar('/');
                    }
                    isSlash = FALSE;
                    putchar(c);
                    switch (c) {
                        case '(':
                            if (checkParen()) {
                        
                                return 1;
                            }
                            break;
                        case '{':
                            if (checkCurly()) {
                        
                                return 1;
                            }
                            break;
                        case '[':
                            if (checkSquare()) {
                        
                                return 1;
                            }
                            break;
                        case '\'':
                            if (checkSingleQuote()) {
                        
                                return 1;
                            }
                            break;
                        case ')':
                        case '}':
                        case ']':
                            puts("");
                            puts("Syntax Error!");

                            return 1;
                        default:
                            break;
                    }
                }
            }
        } else {
            if (c == '"') {
                isQuote = FALSE;
            }
            putchar(c);
        }
    }

    return 0;
}

/*
 *  singleComment(void) : get character until c = '\n'
 */
void singleComment(void)
{
/*
 *  c : used for getchar();
 */
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar('\n');
            break;
        }
    }   
}

/*
 *  multiComment(void)  : get character until c_n = '*' && c_(n + 1) = '/'
 */
void multiComment(void)
{
/*
 *  c           : used for getchar();
 *  isAsterisk  : check c is '*'
 */
    int c, isAsterisk;

    isAsterisk = FALSE;
    while ((c = getchar()) != EOF) {
        if (!isAsterisk && (c == '*')) {
            isAsterisk = TRUE;
        } else if (isAsterisk && (c == '/')) {
            break;
        } else {
            isAsterisk = FALSE;
        }
    }   
}

/*
 *  checkParen(void)    : check syntax error on parenthesis
 */
int checkParen(void)
{
/*
 *  c : used for getchar();
 */
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        if ((c == '(') || (c == ')') || (c == '\n')) {
            if (c != ')') {
                puts("");
                puts("Syntax Error!");
                
                return 1;
            }
            break;
        }
    }

    return 0;
}

/*
 *  checkCurly(void)    : check syntax error on curly brackets
 */
int checkCurly(void)
{
/*  
 *  c : used for getchar();
 */
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        if ((c == '{') || (c == '}') || (c == '\n')) {
            if (c != '}') {
                puts("");
                puts("Syntax Error!");
                
                return 1;
            }
            break;
        }
    }

    return 0;
}

/*
 *  checkSquare(void)   : check syntax error on square brackets
 */
int checkSquare(void)
{
/*
 *  c : used for getchar();
 */
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        if ((c == '[') || (c == ']') || (c == '\n')) {
            if (c != ']') {
                puts("");
                puts("Syntax Error!");

                return 1;
            }
            break;
        }
    }

    return 0;
}

/*
 *  checkSingleQuote(void)  : check syntax error on single quote
 */
int checkSingleQuote(void)
{
/*
 *  c : used for getchar();
 */
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        if ((c == '\'') || (c == '\n')) {
            if (c != '\'') {
                puts("");
                puts("Syntax Error!");
    
                return 1;
            }
            break;
        }
    }

    return 0;
}
```
