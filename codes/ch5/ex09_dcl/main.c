#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "gettoken.h"

#define MAXTOKEN 100

int tokentype;            /* type of last token */
char token[MAXTOKEN];     /* last token string */
char name[MAXTOKEN];      /* identifier name */
char datatype[MAXTOKEN];  /* data type = char, int, etc. */
char out[1000];           /* output string */

/* convert declaration to words */
int main(void)
{
  while (gettoken() != EOF) {  /* 1st token on line */
    strcpy(datatype, token);   /* is the datatype */
    out[0] = '\0';
    dcl();  /* parse rest of line */
    if (tokentype != '\n')
      printf("syntax error\n");
    printf("%s: %s %s\n", name, out, datatype);
  }

  return 0;
}
