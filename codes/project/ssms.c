/* Student Score Management System */
#include <stdio.h>
#include <string.h> /* strcmp() */
#include <stdlib.h> /* atoi()   */
#include "util.h"   /* offset   */
#include "score.h"  /* run()    */

int main(int argc, char *argv[])
{
  int offset = 0;

  if (argc != 2) {
    /* stdrr */
    printf("Usage: ssms OFFSET\n");
    exit(1);
  }
  offset = atoi(*++argv);
  setOffset(offset > 0 ? offset : DEFAULT_OFFSET);
  run();

  return 0;
}