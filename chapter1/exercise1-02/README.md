```c
/*  
 *  Experiment to find out what happens when printf's argument string contains \c, 
 *  where c is some character not listed above.
 */
 
#include <stdio.h>

int main(void)
{
    printf("a:\a");
    printf("b:\b");
    printf("c:\c");/*  Unknown escape sequence */
    printf("d:\d");/*  Unknown escape sequence */
    printf("e:\e");
    printf("f:\f");
    printf("g:\g");/*  Unknown escape sequence */
    printf("h:\h");/*  Unknown escape sequence */
    printf("i:\i");/*  Unknown escape sequence */
    printf("j:\j");/*  Unknown escape sequence */
    printf("k:\k");/*  Unknown escape sequence */
    printf("l:\l");/*  Unknown escape sequence */
    printf("m:\m");/*  Unknown escape sequence */
    printf("n:\n");
    printf("o:\o");/*  Unknown escape sequence */
    printf("p:\p");/*  Unknown escape sequence */
    printf("q:\q");/*  Unknown escape sequence */
    printf("r:\r");
    printf("s:\s");/*  Unknown escape sequence */
    printf("t:\t");
  
    /*
     *  \u below stands for unicode.
     *  warning: universal character names are only valid in C++ and C99
     *  without anything it will give the error incomplete universal character.
     *  we will give 2603 unicode codepoint which stands for snowman
     */
   
    printf("u:\u2603");
    printf("v:\v");
    printf("w:\w");/*  Unknown escape sequence */
  
    /*  \x is for hexadecimals. It should be followed by valid hexadecimal.
     *  Lets give D as hexadecimal value 
     */
   
    printf("x:\xD");
    printf("y:\y");/*  Unknown escape sequence */
    printf("z:\z");/*  Unknown escape sequence */
    printf("A:\A");/*  Unknown escape sequence */
    printf("B:\B");/*  Unknown escape sequence */
    printf("C:\C");/*  Unknown escape sequence */
    printf("D:\D");/*  Unknown escape sequence */
    printf("E:\E");
    printf("F:\F");/*  Unknown escape sequence */
    printf("G:\G");/*  Unknown escape sequence */
    printf("H:\H");/*  Unknown escape sequence */
    printf("I:\I");/*  Unknown escape sequence */
    printf("J:\J");/*  Unknown escape sequence */
    printf("K:\K");/*  Unknown escape sequence */
    printf("L:\L");/*  Unknown escape sequence */
    printf("M:\M");/*  Unknown escape sequence */
    printf("N:\N");/*  Unknown escape sequence */
    printf("O:\O");/*  Unknown escape sequence */
    printf("P:\P");/*  Unknown escape sequence */
    printf("Q:\Q");/*  Unknown escape sequence */
    printf("R:\R");/*  Unknown escape sequence */
    printf("S:\S");/*  Unknown escape sequence */
    printf("T:\R");/*  Unknown escape sequence */
  
    /*
     *  \U below stands for unicode.
     *  error: incomplete universal character name \U
     *  without anything it will give the error incomplete universal character.
     *  we will give 2603 unicode codepoint which stands for snowman
     */

    printf("U:\U00002603");
    printf("V:\V");/*  Unknown escape sequence */
    printf("W:\W");/*  Unknown escape sequence */
    printf("X:\X");/*  Unknown escape sequence */
    printf("Y:\Y");/*  Unknown escape sequence */
    printf("Z:\Z");/*  Unknown escape sequence */
    printf("0:\0");/*  Unknown escape sequence */
    printf("1:\1");
    printf("2:\2");
    printf("3:\3");
    printf("4:\4");
    printf("5:\5");
    printf("6:\6");
    printf("7:\7");
    printf("8:\8");/*  Unknown escape sequence */
    printf("9:\9");/*  Unknown escape sequence */
    printf("~:\~");/*  Unknown escape sequence */
    printf("`:\`");/*  Unknown escape sequence */
    printf("!:\!");/*  Unknown escape sequence */
    printf("@:\@");/*  Unknown escape sequence */
    printf("#:\#");/*  Unknown escape sequence */
    printf("$:\$");/*  Unknown escape sequence */
    printf("%:\%");/*  Unknown escape sequence, spurious trailing % in format */
    printf("^:\^");/*  Unknown escape sequence */
    printf("&:\&");/*  Unknown escape sequence */
    printf("*:\*");/*  Unknown escape sequence */
    printf("(:\(");
    printf("):\)");/*  Unknown escape sequence */
    printf("_:\_");/*  Unknown escape sequence */
    printf("-:\-");/*  Unknown escape sequence */
    printf("+:\+");/*  Unknown escape sequence */
    printf("{:\{");
    printf("[:\[");
    printf("}:\}");/*  Unknown escape sequence */
    printf("]:\]");/*  Unknown escape sequence */
    printf("|:\|");/*  Unknown escape sequence */
    printf("\:\\");/*  Unknown escape sequence */
    printf("a:\a");
    printf("::\:");/*  Unknown escape sequence */
    printf(";:\;");/*  Unknown escape sequence */
    printf("\":\"");
    printf("':\'");
    printf("<:\<");/*  Unknown escape sequence */
    printf(",:\,");/*  Unknown escape sequence */
    printf(">:\>");/*  Unknown escape sequence */
    printf(".:\.");/*  Unknown escape sequence */
    printf("?:\?");
    printf("/:\/");/*  Unknown escape sequence */
  
    return 0;
}
```
