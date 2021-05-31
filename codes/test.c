#include <stdio.h>
#include <ctype.h>

/*
#define PASTE(front, back)           front ## back
#define PRINT_ERROR(prog, func, str) fprintf(stderr, #PASTE(
  */

enum {
  MAIN
};
#define ERRORMAIN "TTTTT"
#define P(prog, str) printf(#prog" : %s", ERROR ## str)

int main(void)
{
  P("main", MAIN);

  return 0;
}