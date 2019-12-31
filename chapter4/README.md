# 제4장 Functions and Program Structure

## 요약<br>
*   C 프로그램은 여러 개의 함수들로 이루어진 구조이며, 하나 또는 여러 개의 소스파일로 나뉠 수 있음(이때, 각 소스파일은 개별 compile됨)<br>

*   Function declare<br>
    *   형이 정의되지 않은 함수는 return type이 int type으로 임의 지정됨<br>
>   The function atof must be declared and defined consistently. If atof itself and the call to it in main have inconsistent types in the same source file, the error will be detected by the compiler.<br>
But if (as is more likely) atof were compiled separately, the mismatch would not be detected, atof would return a double that main would treat as an int, and meaningless answers would result.<br>
In the light of what we have said about how declarations must match definitions, this might seem surprising. The reason a mismatch can happen is that if there is no function prototype, a function is implicitly declared by its first appearance in an expression, such as<br>
```C
sum += atof(line)
```
>   If a name that has not been previously declared occurs in an expression and is followed by a left parentheses, it is declared by context to be a function name, the function is assumed to return an int, and nothing is assumed about its arguments. Furthermore, if a function declaration does not include arguments, as in<br>
```C
double atof();
```
>   that too is taken to mean that nothing is to be assumed about the arguments of atof; all parameter checking is turned off. This special meaning of the empty argument list is intended to permit older C programs to compile with new compilers. But it's a bad idea to use it with new C programs. If the function takes arguments, declare them; if it takes no arguments, use void.<br>

* 모호성<br>
>   \+ and \* are commutative operators, the order in which the popped operands are combined is irrelevant, but for \- and \/ the left and right operand must be distinguished. In<br>
```C
push(pop() - pop()); /* WRONG */
```
>   the order in which the two calls of pop are evaluated is not defined. To guarantee the right order, it is necessary to pop the first value into a temporary variable as we did in main.<br>

* Scope<br>
```C
main() { ... }

int sp = 0;
double val[MAXVAL];

void push(double f) { ... }
double pop(void) { ... }
```
>   then the variables sp and val may be used in push and pop simply by naming them; no further declarations are needed. But these names are not visible in main, nor are push and pop themselves.<br>
On the other hand, if an external variable is to be referred to before it is defined, or if it is defined in a different source file from the one where it is being used, then an extern declaration is mandatory. <br>

```C
if (n > 0) {
    int i; /* declare a new i */
    
    for (i = 0; i < n; i++)
        ...
}
```
>   the scope of the variable i is the \'true\' branch of the if; this i is unrelated to any i outside the block.<br>
An automatic variable declared and initialized in a block is initialized each time the block is entered.<br>

* Header<br>
>   There is a tradeoff between the desire that each file have access only to the information it needs for its job and the practical reality that it is harder to maintain more header files.<br>
Up to some moderate program size, it is probably best to have one header file that contains everything that is to be shared between any two parts of the program; that is the decision we made here.<br>
For a much larger program, more organization and more headers would be needed.<br>

* External<br>
>   The
adjective \'external\' is used in contrast to \'internal\', which describes the arguments and variables defined inside functions.<br>
External variables are defined outside of any function, and are thus potentionally available to many functions.<br>
Functions themselves are always external, because C does not allow functions to be defined inside other functions.<br>
By default, external variables and functions have the property that all references to them by the same name, even from functions compiled separately, are references to the same thing. (The standard calls this property external linkage.)<br>

* Static<br>
    *   정적변수(static variable)는 루틴 수행이 종료되어도 사라지지 않으며, 초기화는 한 번만 이루어짐<br>
>   The external static declaration is most often used for variables, but it can be applied to functions as well. **Normally, function names are global, visible to any part of the entire program. If a function is declared static, however, its name is invisible outside of the file in which it is declared**.<br>

* Register<br>
    *   레지스터(register)는 자동변수 또는 매개변수에만 사용 가능하며, 프로그램을 더욱 빠르게 수행시킬 수 있음<br>
>   A register declaration advises the compiler that the variable in question will be heavily used.<br>
The idea is that register variables are to be placed in machine registers, which may result in smaller and faster programs. **But compilers are free to ignore the advice.**<br>

| memory |
|----------|
| Register |
| .data variables |
| .bss variables |
| ... |
| stack |
| heap |

    *   .data 영역은 초기화된 전역변수 또는 정적변수가 존재<br>
    *   .bss 영역은 초기화되지 않은 전역변수 또는 정적변수가 존재하며, 모든 값은 0으로 초기화함<br>

* Initialization<br>
```C
int low = 0;
int high = n - 1;
int mid;
...
 
```
```C
int low, high, mid;
 
low = 0;
high = n - 1;
...

```
>   In effect, initialization of automatic variables are just shorthand for assignment statements.<br> 
Which form to prefer is largely a matter of taste. We have generally used explicit assignments, because initializers in declarations are harder to see and further away from the point of use.<br>


## 예제<br>
* [4-01](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-01) : Write the function strrindex(s, t), which returns the position of the rightmost occurrence of t in s, or -1 if there is none.<br>

* [4-02](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-02) : Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.<br>

* [4-03](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-03) : Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.<br>

* [4-04](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-04) : Add commands to print the top element of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.<br>

* [4-05](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-05) : Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.<br>

* [4-06](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-06) : Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.) Add a variable for the most recently printed value.<br>

* [4-07](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-07) : Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch?<br>

* [4-08](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-08) : Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.<br>

* [4-09](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-09) : Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.<br>

* [4-10](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-10) : An alternate organization uses getline to read an entire input line; this makes getch and ungetch unnecessary. Revise the calculator to use this approach.<br>

* [4-11](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-11) : Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.<br>

* [4-12](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-12) : Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.<br>

* [4-13](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-13) : Write a recursive version of the function reverse(s), which reverses the string s in place.<br>

* [4-14](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-14) : Define a macro swap(t, x, y) that interchanges two arguments of type t. (Block structure will help.)<br>

## 소스코드<br>
### 4.1 Basics of Functions<br>
```c
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
main()
{
    char    line[MAXLINE];
    int     found;

    found = 0;
    while (getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }

    return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while ((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n')) {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; (t[k] != '\0') && (s[j] == t[k]); j++, k++) {
            ;
        }
        if ((k > 0) && (t[k] == '\0')) {

            return i;
        }
    }

    return -1;
}
```
### 4.2 Functions Returning Non-integers<br>
```C
#include <ctype.h>
/* atof: convert string s to double */
double atof(char s[])
{
    double  val, power;
    int     i, sign;

    for (i = 0; isspace(s[i]); ++i) {   /* skip white space */
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    return sign * val / power;
}
```
```C
#include <stdio.h>

#define MAXLINE 100

/* rudimentary calculator */
main()
{
    double  sum, atof(char []);
    char    line[MAXLINE];

    int getline(char line[], int max);
    sum = 0;
    while (getline(line, MAXLINE) > 0) {
        printf("\t%g\n", sum += atof(line));
    }

    return 0;
}
```
```C
/* atoi: convert string s to integer using atof */
int atoi(char s[])
{
    double atof(char s[]);
    
    return (int) atof(s);
}
```
### 4.3 External Variables<br>
```C
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
main()
{
    int     type;
    double  op2;
    char    s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}
```
```C
#define MAXVAL 100 /* maximum depth of val stack */

int     sp = 0; /* next free stack position */
double  val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }

    return;
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0) {

        return val[--sp];
    } else {
        printf("error: stack empty\n");

        return 0.0;
    }
}
```
```C
#include <ctype.h>

int     getch(void);
void    ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {

        return c; /* not a number */
    }
    i = 0;
    if (isdigit(c)) {   /* collect integer part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if (c == '.') { /* collect fraction part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}
```
```C
#define BUFSIZE 100

char    buf[BUFSIZE]; /* buffer for ungetch */
int     bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{

    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }

    return;
}
```
### 4.7 Register Variables<br>
```C
register int    x;
register char   c;
```
### 4.10 Recursion<br>
```C
#include <stdio.h>

/* printd: print n in decimal */
void printd(int n)
{
    if (n < 0) { 
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
    
    return;
}
```
```C
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int     i, last;
    void    swap(int v[], int i, int j);

    if (left >= right) { /* do nothing if array contains */

        return; /* fewer than two elements */
    }
    swap(v, left, (left + right) / 2); /* move partition elem */
    last = left; /* to v[0] */
    for (i = left + 1; i <= right; i++) {  /* partition */
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last); /* restore partition elem */
    qsort(v, left, last-1);
    qsort(v, last+1, right);

    return;
}
```
```C
/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

    return;
}
```
### 4.11 The C Preprocessor<br>
```C
/*  4.11.1 File Inclusion   */
#include "filename"
#include <filename>
```
```C
/*  4.11.2 Macro Substitution   */
#define forever     for (;;) /* infinite loop */
#define max(A, B)   ((A) > (B) ? (A) : (B))

#undef getchar

#define dprint(expr) printf(#expr " = %g\n", expr)
/*
    dprint(x/y)
the macro is expanded into
    printf("x/y" " = &g\n", x/y);
and the strings are concatenated, so the effect is
    printf("x/y = &g\n", x/y);
Within the actual argument, each " is replaced by \" and each \ by \\,
so the result is a legal string constant. 
*/

#define paste(front, back) front ## back
/*  paste(name, 1) creates the token name1. */
```
```C
/*  4.11.3 Conditional Inclusion    */
#if !defined(HDR)
#define HDR
/* contents of hdr.h go here */
#endif

#if SYSTEM == SYSV
#define HDR "sysv.h"
#elif SYSTEM == BSD
#define HDR "bsd.h"
#elif SYSTEM == MSDOS
#define HDR "msdos.h"
#else
#define HDR "default.h"
#endif
#include HDR

#ifndef HDR
#define HDR
/* contents of hdr.h go here */
#endif
```
