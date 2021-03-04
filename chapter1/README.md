# 제1장 A Tutorial Introduction

## 요약
*   site_t: 가장 큰 사이즈를 담을 수 있는 unsigned 정수형을 나타냄<br>
*   변수형의 정밀도는 '기종'에 따라 다름<br>
    *   16-bit PDP-11   : 16-bit 부호숫자<br>
    *   32-bit CPU  : 32-bit 부호숫자<br>
* indentation: 프로그램의 구조를 알기 쉽도록 들여쓰기를 하는 것 <br>
* C에서 char 형과 int 형을 같이 계산할 경우 모든 변수는 int 형으로 간주됨(type cast)<br>
* 함수를 호출할 때 사용하는 매개변수: argument, actual argument<br>
* 함수 내에서 사용되는 매개변수: parameter, formal argument<br>
* 외부 변수 사용 시 extern 키워드를 사용해야 함 <br>
* && 또는 ||: 왼쪽부터 차례대로 조건 검사하며, 조건 검사 도중에 조건이 만족되는 식을 만날 경우 조건 검사를 마침 <br>
* long 형으로 값을 저장할 수 없을 때 double 형으로 값 저장함<br>
* 만약 함수 내부에서 외부 변수를 사용할 경우,<br>
    1. 외부 변수와 함수가 같은 파일 내에 선언된 경우, extern 키워드 선택 가능<br>
    2. 외부 변수와 함수가 서로 다른 파일에 선언된 경우, extern 키워드 필수<br>
* 문자를 처리하는 변수의 type을 char 형이 아닌 int 형을 사용하는 이유는 ASCII 코드와 같이 양의 정수로 이루어진 문자는 상관 없지만 EOF(-1)과 같은 값은 char 형으로 처리할 수 없음<br>
* Call by value? Call by reference? 
    * Call by value<br>
    >   One aspect of C functions may be unfamiliar to programmers who are used to some other languages, particularly Fortran.<br>
    **In C, all function arguments are passed "by value."** This means that the called function is given the values of its
    arguments in temporary variables rather than the originals.<br>
    This leads to some different properties than are seen with "call by reference" languages like Fortran or with var parameters in Pascal, **in which the called routine has access to the original argument, not a local copy.**<br>

    * [Call by reference](https://en.wikipedia.org/wiki/Evaluation_strategy#Call_by_reference)<br>
    >   Call by reference (or pass by reference) is an evaluation strategy where a function receives an implicit reference to a variable used as argument, rather than a copy of its value.<br>
    **This typically means that the function can modify (i.e., assign to) the variable used as argument—something that will be seen by its caller.**

    * ISO/IEC 9899:2011
        * 6.5.2.2 Function calls
        >   4. An argument may be an expression of any complete object type. In preparing for the call to a function, the arguments are evaluated, and **each parameter is assigned the value of the corresponding argument.**93)
        
        * Appendix 93)
        >   93) **A function may change the values of its parameters, but these changes cannot affect the values of the arguments.** On the other hand, it is possible to pass a pointer to an object, and the function may change the value of the object pointed to. A parameter declared to have array or function type is adjusted to have a pointer type as described in 6.9.1.
    
    * Example code
    ```C
    #include <stdio.h>

    void test(int *p)   /*  parameter   */
    {
        printf("2. [test()] addr: %p, value: %d\n", p, *p);
        ++(*p);
        printf("3. [test()] addr: %p, value: %d\n", p, *p);
        ++p;
        printf("4. [test()] addr: %p, value: %d\n", p, *p);

        return;
    }

    int main()
    {
        int b = 3;
        int *a = &b;    /*  will use as argument    */

        printf("1. [main()] addr: %p, value: %d\n", a, *a);
        test(a);
        printf("5. [main()] addr: %p, value: %d\n", a, *a);

        return 0;
    }
    ```
    * Results
    ```Text
    1. [main()] addr: 0x7ffcf711ad5c, value: 3
    2. [test()] addr: 0x7ffcf711ad5c, value: 3
    3. [test()] addr: 0x7ffcf711ad5c, value: 4
    4. [test()] addr: 0x7ffcf711ad60, value: -149836452
    5. [main()] addr: 0x7ffcf711ad5c, value: 4
    ```

## 예제
* [1-01](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-01) : Run the "hello world" program on your system. Experiment with leaving out parts of the program, to see what error messages you get.<br>

* [1-02](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-02) : Experiment to find out what happens when printf 's argument string contains \c, where c is some character not listed above.<br>

* [1-03](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-03) : Modify the temperature conversion program to print a heading above the table.<br>

* [1-04](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-04) : Write a program to print the corresponding Celsius to Fahrenheit table.<br>

* [1-05](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-05) : Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.<br>

* [1-06](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-06) : Verify that the expression getchar() != EOF is 0 or 1.<br>

* [1-07](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-07) : Write a program to print the value of EOF.<br>

* [1-08](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-08) : Write a program to count blanks, tabs, and newlines.<br>

* [1-09](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-09) : Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.<br>

* [1-10](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-10) : Write a program to copy its input to its output, replacing each tab by \t , each backspace by \b , and each backslash by \\ . This makes tabs and backspaces visible in an unambiguous way.<br>

* [1-11](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-11) : How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?<br>

* [1-12](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-12) : Write a program that prints its input one word per line.<br>

* [1-13](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-13) : Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.<br>

* [1-14](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-14) : Write a program to print a histogram of the frequencies of different characters in its input.<br>

* [1-15](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-15) : Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.<br>

* [1-16](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-16) : Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.<br>

* [1-17](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-17) : Write a program to print all input lines that are longer than 80 characters.<br>

* [1-18](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-18) : Write a program to remove all trailing blanks and tabs from each line of input, and to delete entirely blank lines.<br>

* [1-19](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-19) : Write a function reverse(s) that reverses the character string s . Use it to write a program that reverses its input a line at a time.<br>

* [1-20](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-20) : Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?<br>

* [1-21](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-21) : Write a program entab that replaces strings of blanks with the minimum number of tabs and blanks to achieve the same spacing. Use the same stops as for detab . When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?<br>

* [1-22](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-22) : Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n -th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.<br>

* [1-23](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-23) : Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments do not nest.<br>

* [1-24](https://github.com/RyanJeong/C/tree/master/chapter1/exercise1-24) : Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)<br>

## 소스코드
### 1.1 Getting Started<br>
```c
#include <stdio.h>            // * include information about standard library

main()                        // * define a function named main
                              //   that receives no argument values
{                             // * statements of main are enclosed in braces
                              // * main calls library function printf to 
    printf("Hello, world\n"); //   print this sequence of characters; 
                              //   \n represents the newline character
}                   
```

```c
#include <stdio.h>

main()
{
    printf("hello, ");
    printf("world");
    printf("\n");
}
```

### 1.2 Variables and Arithmetic Expressions<br>
```c
#include <stdio.h>

/*  print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300  */
main()
{
    int fahr, celsius;
    int lower, upper, step;
    
    lower = 0;    /*  lower limit of temperature table    */
    upper = 300;  /*  upper limit */
    step  = 20;   /*  step size   */

    fahr  = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

```c
#include <stdio.h>

/*  print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floatinq-point version  */
main()
{
    float fahr, celsius;
    int   lower, upper, step;

    lower = 0;    /*  lower limit of temperature table    */
    upper = 300;  /*  upper limit */
    step  = 20;   /*  step size   */

    fahr  = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

### 1.3 The For Statement<br>
```c
#include <stdio.h>

/* print Fahrenheit-Celsius table */
main( )
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
```

### 1.4 Symbolic Constants<br>
```c
#include <stdio.h>
#define LOWER   0   /*  lower limit of temperature table    */
#define UPPER   300 /*  upper limit */
#define STEP    20  /*  step size   */

/* print Fahrenheit-Celsius table */
main ()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
```
### 1.5 Character Input and Output<br>
```c
#include <stdio.h>

/* copy input to output; 1st version */
main( )
{
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
```

```c
#include <stdio.h>

/* copy input to output; 2nd version */
main()
{
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
```

```c
#include <stdio.h>

/*  count characters in input; 1st version  */
main( )
{
    long nc;

    nc = 0;
    while (getchar() != EOF) {
        ++nc;
    }
    printf ("%ld\n", nc);
}
```

```c
#include <stdio.h>

/*  count characters in input; 2nd version  */
main( )
{
    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc) {
        ;
    }
    printf("%.Of\n", nc);
}
```

```c
#include <stdio.h>

/*  count lines in input    */
main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
    }
    printf("%d\n", nl);
}
```

```c
#include <stdio.h>

#define IN  1   /*  inside a word   */
#define OUT 0   /*  outside a word  */

/*  count lines, words, and characters in input */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl    = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if ((c == ' ') || (c == '\n') || (c == '\t')) {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf ("%d %d %d\n", nl, nw, nc);
}
```

### 1.6 Arrays<br>
```c
#include <stdio.h>

/*  count digits, white space, others   */
main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c-'0'];
        } else if ((c == ' ') || (c == '\n') || (c == '\t')) {
            ++nwhite;
        } else {
            ++nother;
        }
    }

    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
```

### 1.7 Functions<br>
```c
#include <stdio.h>

int power(int m, int n);

/*  test power function */
main ()
{
    int i;
    
    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
    
    return 0;
}

/* power: raise base to n-th power; n >= 0 */
/*        (old-style version) */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i) {
        p = p * base;
    }
    
    return p;
}
```

### 1.8 Arguments-Call by Value<br>
```c
/* power: raise base to n-th power; n>=O; version 2 */
int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n) {
        p = p * base;
    }
    
    return p;
}
```

### 1.9 Character Arrays<br>
```c
#include <stdio.h>

#define MAXLINE 1000    /*  maximum input line size */

int     getline(char line[], int maxline);
void    copy(char to[], char from[]);

/*  print longest input line    */
main()
{
    int len;               /*  current line length */
    int max;               /*  maximum length seen so far  */
    char line[MAXLINE];    /*  current input line  */
    char longest[MAXLINE]; /*  longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) { /* there was a line */
        printf("%s\n", longest);
    }
    
    return 0;
}

/*  getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

/*  copy: copy 'from' into 'to'; assume to is big enough   */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
```

### 1.10 External Variables and Scope<br>

```c
#include <stdio.h>

#define MAXLINE 1000      /*  maximum input line size */

int     max;              /*  maximum length seen so far  */
char    line[MAXLINE];    /*  current input line  */
char    longest[MAXLINE]; /*  longest line saved here */

int     getline(void);
void    copy(void);

/* print longest input line; specialized version */
main()
{
    int         len;
    extern int  max;
    extern char longest[];
    
    max = 0;
    while ((len = getline()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) { /* there was a line */
        printf("%s\n", longest);
    }
    
    return 0;
}

/*  getline: specialized version */
int getline()
{
    int         c, i;
    extern char line[];
    
    /*
     *  if (i < (MAXLINE - 1)) {
     *      if ((c = getchar()) != EOF) {
     *          if (c != '\n') {
     *              ...
     */
    for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    /*
     *  MAXLINE : 4
     *  INPUT   : H I \n \0
     *  ---------------------
     *      i = 0 -> store H, c = H
     *      i = 1 -> store I, c = I
     *      i = 2 -> store \n, c = \n
     *      i = 3 -> escape for statement{ i < (MAXLINE - 1) }, c = \n
     *      if (c == '\n') {
     *          line[i] = c;
     *          ++i;
     *      }
     *      i = 4 -> result: H I \n \n
     *      line[i] = '\0' // ERROR!!(out of range)
     */
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    
    return i;
}

/*  copy: specialized version */
void copy()
{
    int         i;
    extern char line[], longest[];
    
    i = 0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}
```
