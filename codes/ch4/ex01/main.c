#include "util.h" /* extern char *prog; */
#include "func.h" 

int main(int argc, char *argv[])
{
  prog = argv[0];

  a();
  b();

  return 0;
}