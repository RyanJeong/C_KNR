/*
 * Write a program to remove all comments from a C program. Don’t forget to handle quoted strings and character constants properly.
 * C comments don’t nest.
 */

#include <stdio.h>

enum {
    FALSE,
    TRUE
};

void singleComment(void);
void multiComment(void);

int main(void)
{
/*
 *  c       :  used for getchar();
 *  isQuote : check c is '"'
 *  isSlash : check c is '/'
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

    return;
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

    return;
}
