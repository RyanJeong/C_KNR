/* Student Score Management System */
#include <stdlib.h> /* atoi() */

#include "management.h" /* run()  */
#include "util.h"       /* offset */

int main(int argc, char *argv[])
{
  int offset = 0;

  if (argc == 2) {
    offset = atoi(*++argv);
  }
  setOffset(offset > 0 ? offset : DEFAULT_OFFSET);
  run();

  return 0;
}