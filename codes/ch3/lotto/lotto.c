#include <stdio.h>
#include <ctype.h>   /*  isdigit() */
#include <stdlib.h>  /*  srand(), rand() */
#include <time.h>    /*  time(NULL)  */

enum {
  LOTTO_SIZE = 6,
  MAX_NUM = 45  /* 1 ~ 45 */
};

int main(void)
{
  int c, i, j;
  int check[MAX_NUM]; /* 로또 번호 중복 값 검사용 배열 */
  int cnt;            /* 로또 번호 생성 횟수 */
  int num;            /* 임의의 숫자 보관 변수 */

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
    /* Initialize the seed.  */
    /* Exited before 1 second ends */
    for (j = 0; j < MAX_NUM; ++j)
      check[j] = 0;
    printf("Index: [%4d]:", i);
    for (j = 0; j < LOTTO_SIZE; ++j) {
      while (check[num = rand() % MAX_NUM]) { }
      /* 0 ~ 44 -> 1 ~ 45  */
      check[num++] = 1;
      printf("%3d", num);
    }
    putchar('\n');
  }

  return 0;
}
