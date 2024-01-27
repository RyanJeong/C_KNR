#include "func.h"
#include "util.h" /* extern char *prog; */

int main(int argc, char *argv[])
{
  prog = argv[0];

  a();
  b();

  return 0;
}