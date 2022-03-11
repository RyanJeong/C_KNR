```C
/*
 *  Given the basic framework, it's straightforward to extend the calculator.
 *  Add the modulus (%) operator and provisions for negative numbers.
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

enum {
    MAXOP   = 100,  /* max size of operand or operator */
    NUMBER  = '0',  /* signal that a number was found */
    MAXVAL  = 100,  /* maximum depth of val stack */
    BUFSIZE = 100   /* max size of the buffer   */
};

int     getop(char []);
void    push(double);
double  pop(void);
int     getch(void);
void    ungetch(int);

char    buf[BUFSIZE];   /* buffer for ungetch */
int     bufp = 0;       /* next free position in buf */
int     sp = 0;         /* next free stack position */
double  val[MAXVAL];    /* value stack */

/* reverse Polish calculator */

/*
 *  Examples:
 *  --------------
 *  2   3   4   + -
 *  2   8   2   + /
 *  3   6   2   / *
 *  2   0       /
 *  0   2       /
 *  2   .3      +
 *  -3  -3      -
 *  -3  -4      -
 *  -4  -3      -
 *  -1  -3      *
 *  -3  9       *
 *  4   3       %
 *  4   0       %
 *  -4  3       %
 *  4   -3      %
 *  -4  -3      %
 */
int main(void)
{
    char    s[MAXOP];
    int     type;
    double  op2;

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push((type == '/') ? (pop() / op2) : (((int) pop()) % ((int) op2)));
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}


/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0) {

        return val[--sp];
    } else {
        printf("error: stack empty\n");

        return 0.0;
    }
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {  /*  ignore white spaces */
        ;
    }
    s[1]    = '\0';    /*  for debug output    */
    i       = 0;
    if (c == '-') {
        if (isdigit(c = getch())) {
            s[++i]  = c;
        } else {
            /*  s[0]    = '-';  '-' already located at index 0  */
            ungetch(c); /*  restore a character c, ungetch()  */

            return '-';
        }
    }
    if (!isdigit(c) && c != '.') {

        return c; /* not a number */
    }
    if (isdigit(c)) {   /* collect integer part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if (c == '.') { /* collect fraction part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c); /*  keep white space into the buffer    */
    }

    return NUMBER;
}

/* getch: get a (possibly pushed-back) character */
int getch(void)
{

    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
```
