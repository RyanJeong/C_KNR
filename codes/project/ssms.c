/* Student Score Management System */
#include <stdio.h>
#include <string.h> /* strcmp() */
#include <stdlib.h> /* atoi()   */
#include "util.h"   /* offset   */
#include "score.h"  /* run()    */

extern char *prog;

int main(int argc, char *argv[])
{
  int offset = 0;

  prog = argv[0];
  if (argc == 2) {
    offset = atoi(*++argv);
  }
  setOffset(offset > 0 ? offset : DEFAULT_OFFSET);
  run();

  return 0;
}