#include <ctype.h> /*  isdigit() */
#include <stdio.h>
#include <stdlib.h> /*  srand(), rand() */
#include <time.h>   /*  time(NULL)  */

enum {
  LOTTO_SIZE = 6,
  MAX_NUM = 45 /* 1 ~ 45 */
};

int main(void)
{
  int c, i, j;
  int cnt; /* 로또 번호 생성 횟수 */

  printf("*** LOTTO NUMBER GENERATOR ***\n"
         "How many lines do you want to generate?\n");
  cnt = 0;
  while ((c = getchar()) != EOF) {
    if (!isdigit(c))
      break;
    cnt = (cnt * 10) + (c - '0');
  }
  if (!cnt) {
    printf("Please input a positive number.\n");

    return 1;
  }

  srand(time(NULL));
  for (i = 1; i <= cnt; ++i) {
    printf("Index: [%4d]:", i);
    for (j = 0; j < LOTTO_SIZE; ++j)
      printf("%3d", rand() % MAX_NUM);
    putchar('\n');
  }

  return 0;
}
