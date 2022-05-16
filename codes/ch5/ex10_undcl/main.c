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

/* undcl: convert word descriptions to declarations */
int main(void)
{
  int type;
  char temp[1000+MAXTOKEN];

  while (gettoken() != EOF) {
    strcpy(out, token);
    while ((type = gettoken()) != '\n') {
      if (type == PARENS || type == BRACKETS) {
        strcat(out, token);
      } else if (type == '*') {
        sprintf(temp, "(*%s)", out);
        strcpy(out, temp);
      } else if (type == NAME) {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      } else {
        printf("invalid input at %s\n", token);
      }
    }
    printf("%s\n", out);
  }

  return 0;
}
