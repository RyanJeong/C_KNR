/* #define UPPER_Z '\132' /* 90 to octal */
/* #define VTAB    '\013' /* ASCII vertical tab */
/* #define BELL    '\007' /* ASCII bell character */

/* #define UPPER_Z '\x5A' /* 90 to hexadecimal */
/* #define VTAB    '\xb' /* ASCII vertical tab */
/* #define BELL    '\x7' /* ASCII vertical tab */

#include <stdio.h>

int main(void)
{
    printf("A\rB\n");
    printf("This is useful for splitting up long strings across several source lines.\n");

    printf("This is useful "
        "for splitting up long strings "
        "across several source lines.\n");

    return 0;
}

#define MAXLINE 1000
char line[MAXLINE+1];
/* or */
#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];

/*

"I am a string"
"" /* the empty string */

/*

"Hello, " "World!" 

/* is equivalent to */

/*
"Hello, World!"
*/

enum boolean { NO, YES };
enum escapes {
    BELL        = '\a',    
    BACKSPACE   = '\b',   
    TAB         = '\t', 
    NEWLINE     = '\n', 
    VTAB        = '\v',        
    RETURN      = '\r' };
enum months {
    JAN = 1, FEB, MAR, 
    APR, MAY, JUN, 
    JUL, AUG, SEP, 
    OCT, NOV, DEC }; /* FEB is 2, MAR is 3, etc. */



int  lower, upper, step;
char c, line[1000];

int  lower;
int  upper;
int  step;
char c;
char line[1000];

char  esc   = '\\';
int   i     = 0;
int   limit = (MAXLINE + 1);
float eps   = 10e-5;

const double e      = 2.71828182845905;
const char msg[]    = "warning: ";

int strlen(const char[]);   /*  매개변수로 받는 값은 고정임 */

/* leap year */
if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    printf("%d is a leap year\n", year);
} else {
    printf("%d is not a leap year\n", year);
}

if (i < lim - 1) { ... }   /* i < (lim - 1) */

if (i < lim - 1 && (c = getchar()) != '\n' && c != EOF) { ... }

if (!valid) { ... }

if (valid == 0)  { ... }


sqrt((double) 2);    /* 정수를 double 형으로 변환하고자 하는 경우 */
/* ----------------------------------------------------------- */
double sqrt(double); /* 제곱근 계산 함수 */
root2 = sqrt(2);     /*  함수 선언을 수행했으므로, cast 연산자 필요 없음 */

/*  ++i */
i = i + 1;
return i;

/*  i++ */
const int temp = i;
i = i + 1;
return temp;

int a, b;

b = 3;
a = b++; /*  a = 3, b = 4    */
a = b;   /*  a = 4, b = 4    */
a = ++b; /*  a = 5, b = 5    */

i += 2  /*  i = i + 2   */

/*  a = a op b to a op= b   */
+ - * / % << >> & ^ |   /* not(~) is not included   */

x *= y + 1
/*  
 *  1. x *= (y + 1)
 *  2. x = x * (y + 1)
 */

yyval[yypv[p3+p4] + yypv[p1]] += 2;
yyval[yypv[p3+p4] + yypv[p1]] = yyval[yypv[p3+p4] + yypv[p1]] + 2;

while ((c = getchar()) != EOF) { ... }

if (a > b) {
    c = a;
} else {
    c = b;
}

c = (a > b) ? a : b;

/*
for (i = 0; i < n; ++i) {
    if ((i % 10) == 9 || i == (n - 1)) {
        printf("%6d\n");
    } else {
        printf("%6d ");
    }
}
*/
for (i = 0; i < n; ++i) {
    printf("%6d%c", a[i], ((i % 10) == 9) || (i == (n - 1)) ? '\n' : ' ');
}


/*
if (n == 1) {
    printf("You have %d item\n");
} else {
    printf("You have %d items\n");
}
*/
printf("You have %d item%s\n", n, (n == 1) ? "" : "s");


x++ * y * z + w++;
/*
 *  1. [1]  x++, w++가 연산 우선순위가 가장 높음 
 *  2. [2]  우선순위가 높은 식을 묶음   (x++) * y * z + (w++)
 *  3. [1]  * 연산자의 우선순위가 다음으로 높음
 *  4. [2]  * 연산자의 결합 방향은 왼쪽에서 오른쪽 방향이므로, 
 *          ((x++) * y) * z + (w++)
 *          (((x++) * y) * z) + (w++)
 *  5. [1]  + 연산자의 우선순위가 다음으로 높음
 *  6. [2]  + 연산자의 결합 방향은 왼쪽에서 오른쪽 방향이므로, 
 *          ((((x++) * y) * z) + (w++))
 */

x * y + z++;    /*  ((x * y) + (z++));  */
/*
 *  +  연산자를 사용하려면 (x * y), (z++) 연산이 선행되어야 함
 *  즉, * 연산이 + 연산보다 먼저 수행되어야 하며, 
 *  ++ 연산이 + 연산보다 먼저 수행되어야 함
 *  그러나, (x * y) 연산과 (z++) 연산 중에서 어느 연산이 먼저 수행되는가?
 */

/*  Case 1.
 *  side effect가 있는 함수일 경우, 결과가 달라질 수 있음
 *  Global variable, ...
 */
x = f() + g();

/*  Case 2.
 *  ++n;
 *  printf("%d %d\n", n, power(2, n));
 */
printf("%d %d\n", ++n, power(2, n));

/*  Case 3.  */
a[i] = i++;

/*  Case 4.  */
a + a + ++a;    /*  ((a + a) + (++a))   */
a + a + a++;    /*  ((a + a) + (a++))   */


int   i;
char  c;
float x;

i = c;
c = i;

x = i;
i = x;

(type name) expression

i = 1;
++i;

i = 1;
--i;

expr1 op= expr2

expr1 = (expr1) op (expr2)


expr1 ? expr2 : expr3

(n > 0) ? f : n

switch (expression) {
    case 10: statements
    case const-expr: statements
    default: statements
}

