#include <stdio.h>
#include "score.h"
#include "util.h" /* skipWhite() */

void run(void)
{
  int c;

  do {
    menu();
    /* call scanf() after skipWhite() to ignore white-space */
    skipWhite(stdin);
    scanf("%d", &c);
    printf("  %d\n", c);
  } while (c != QUIT);

  return;
}

void menu(void)
{
  printf("*** Student Score Management System ***\n"
          "------------------------\n"
          "[1] Add Student Record\n"
          "[2] Display Student List\n"
          "[3] Search Student Record (by ID)\n"
          "[4] Modify Student Record (by ID)\n"
          "[5] Delete Student Record (by ID)\n"
          "[6] Delete All Students\n"
          "[0] Save and quit\n"
          "------------------------\n"
          "Enter your choice:");

  return;
}