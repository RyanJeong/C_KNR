#include <stdio.h>
#include <string.h>
#include "dcl.h"
#include "gettoken.h"

extern int  tokentype; /* main.c */
extern char token[];   /* main.c */
extern char name[];    /* main.c */
extern char out[];     /* main.c */

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;

    /* count *'s */
    for (ns = 0; gettoken() == '*'; ++ns) { 
        ;
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

    if (tokentype == '(') { /* ( dcl ) */
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
        }
    } else if (tokentype == NAME) { /* variable name */
        strcpy(name, token);
    } else {
        printf("error: expected name or (dcl)\n");
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