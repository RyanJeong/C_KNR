```C
/*  main.c  */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum {
    NAME,
    PARENS,
    BRACKETS,

    NO = 0,
    YES,
    
    MAXTOKEN = 100,
    MAXLEN   = 1000
};

void    dcl(void);
void    dirdcl(void);
int     gettoken(void);

int     tokentype;          /* type of last token */
char    token[MAXTOKEN];    /* last token string */
char    name[MAXTOKEN];     /* identifier name */
char    datatype[MAXTOKEN]; /* data type = char, int, etc. */
char    out[MAXLEN];        /* a word description of a C declaration */
int     isError;            /* find error from a C declaration */

/* convert declaration to words */
int main(void) 
{
    /* 1st token on line */
    while (gettoken() != EOF) { 
        /* is the datatype */
        strcpy(datatype, token); 
        out[0] = '\0';
        name[0] = '\0';
        /* parse rest of line */
        dcl(); 
        if (tokentype != '\n') {
            printf("syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }

    return 0;
}

/* return next token */
int gettoken(void) 
{
    int     c, getch(void);
    void    ungetch(int);
    char    *p = token;

    if (isError) {
        isError = NO;

        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t') {
        ;
    }
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");

            return tokentype = PARENS;
        } else {
            ungetch(c);

            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; ) {
            ;
        }
        *p = '\0';

        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); ) {
            *p++ = c;
        }
        *p = '\0';

        ungetch(c);
        return tokentype = NAME;
    } else {

        return tokentype = c;
    }
}

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;

    /* count *'s */
    for (ns = 0; gettoken() == '*'; ) { 
        ns++;
    }
    dirdcl();
    while (ns-- > 0) {
        strcat(out, " pointer to");
    }
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;

    /* ( dcl ) */
    if (tokentype == '(') { 
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
            isError = YES;
        }
    } else if (tokentype == NAME) { /* variable name */
        strcpy(name, token);
    } else {
        printf("error: expected name or (dcl)\n");
        isError = YES;
    }
    while ((type=gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS) {
            strcat(out, " function returning");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

/*  getch.c */
#include <stdio.h>

#define BUFSIZE 100

static char    buf[BUFSIZE];       /* buffer for ungetch */
static int     bufp = 0;           /* next free position in buf */

/* get a (possibly pushed-back) character */
int getch(void)
{

    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters \n");
    } else {
        buf[bufp++] = c;
    }
}
```
