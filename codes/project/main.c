/* Student Score Management System */
#include "management.h" /* run() */

int main(int argc, char *argv[])
{
  run((argc == 2) ? *++argv : "0");

  return 0;
}