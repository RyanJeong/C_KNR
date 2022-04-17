#include <ctype.h>  /*  isspace()   */
#include <stdio.h>
#include <stdlib.h> /*  srand(), rand() */
#include <time.h>   /*  time(NULL)  */

enum {
  ROCK,      /* 0  */
  PAPER,     /* 1  */
  SCISSORS,  /* 2  */
  SHAPES     /* 3  */
};

int main()
{
  int c;
  int shape;   /* 컴퓨터가 낸 손 모양, 가위 바위 보 중 하나 */
  int cnt;     /* 판 수 기록 */
  double win;  /* 사용자가 컴퓨터로부터 이긴 횟수 */

  printf("*** ROCK PAPER SCISSORS ***\n");
  c = 'h';
  cnt = 0;
  win = 0.0;
  srand(time(NULL));
  do {
    if (isspace(c))
      continue;

    /* 'A' -> 'a' */
    if (isupper(c))
      c = tolower(c);
    switch (c) {
      case 'r':
        shape = (rand() % SHAPES);
        ++cnt;
        printf("[#%3d] Player: [ROCK], Computer: ", cnt);
        if (shape == ROCK) {
          printf("[ROCK], Draw!\n");
        } else if (shape == PAPER) {
          printf("[PAPER], Computer wins!\n");
        } else {
          printf("[SCISSORS], Player wins!\n");
          ++win;
        }
        break;
      case 'p':
        shape = (rand() % SHAPES);
        ++cnt;
        printf("[#%3d] Player: [PAPER], Computer: ", cnt);
        if (shape == PAPER) {
          printf("[PAPER], Draw!\n");
        } else if (shape == SCISSORS) {
          printf("[SCISSORS], Computer wins!\n");
        } else {
          printf("[ROCK], Player wins!\n");
          ++win;
        }
        break;
      case 's':
        shape = (rand() % SHAPES);
        ++cnt;
        printf("[#%3d] Player: [SCISSORS], Computer: ", cnt);
        if (shape == SCISSORS) {
          printf("[SCISSORS], Draw!\n");
        } else if (shape == ROCK) {
          printf("[ROCK], Computer wins!\n");
        } else {
          printf("[PAPER], Player wins!\n");
          ++win;
        }
        break;
      case 'e':
        printf("Exit the game!\n");
        if (cnt)
          printf("Played: %3d, Win rate: %.2f%%\n",
              cnt, (win / (double) cnt) * 100.0);
        break;
      default:
        if (c != 'h')
          printf("Wrong input!\n");
        printf("r: Rock, p: Paper, s: Scissors, h: Help, e: Exit\n");
        break;
    }
    if (c == 'e')
      break;
  } while ((c = getchar()) != EOF);

  return 0;
}
