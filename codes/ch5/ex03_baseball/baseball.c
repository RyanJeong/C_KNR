#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "baseball.h"

int getint(int *);

void init(void)
{
    srand(time(NULL)); /* Initialize the seed. */
    printf("*** Number Baseball Game ***\n"
           "You have 9 chances to find out the right answer with 10 numbers(0 - 9).\n");
}

int answer[PITCHES];
int guess[PITCHES];

void play(void)
{
    int n_strike, n_ball, i, j;

    setAnswer();
    for (i = 1; i <= INNINGS && n_strike != PITCHES; ++i) {
        n_strike = n_ball = 0;
        printf("Please enter three numbers (Each number must not be duplicated).\n");
        setGuess();
        for (j = 0; j < PITCHES; ++j) {
            if (answer[j] == guess[j]) {
                ++n_strike;
            } else if ((answer[j] == guess[(j + 1)%PITCHES]) || (answer[j] == guess[(j + 2)%PITCHES])) {
                ++n_ball;
            }
        }
        printf("[%d%s attempt] %d Strike%s, %d Ball%s\n",
               i,
               (i == 1) ? "st" : ((i == 2) ? "nd" : ((i == 3) ? "rd" : "th")),
               n_strike,
               (n_strike == 1) ? "" : "s",
               n_ball,
               (n_ball == 1) ? "" : "s");
    }
    printf("%s\n", (i > INNINGS) ? "You lose!" : "You win!");
}

void setAnswer(void)
{
    int i, num;
    int check[RANGE];

    /*  Init. the array */
    for (i = 0; i < RANGE; ++i) {
        check[i] = 0;
    }
    for (i = 0; i < PITCHES; answer[i++] = num) {
        while (check[num = (rand() % RANGE)]) {
            ;
        }
        check[num] = 1;
    }
}

void setGuess(void)
{
    int i, num;
    int check[RANGE];

    /*  Init. the array */
    for (i = 0; i < RANGE; ++i) {
        check[i] = 0;
    }
    i = 0;
    while (i < PITCHES && getint(&num) != EOF) {
        if (num < 0 || num > 9) {
            printf("Please enter only numbers between 0 and 9.\n");
        } else {
            if (check[num]) {
                printf("Number %d has already been entered. Please enter a different number\n", num);
            } else {
                check[num]  = 1;
                guess[i++] = num;
            }
        }
    }
}