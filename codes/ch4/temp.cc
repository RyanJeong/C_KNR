Ah Love! could you and I with Fate conspire
To grasp this sorry Scheme of Things entire,
Would not we shatter it to bits -- and then
Re-mould it nearer to the Heart's Desire!
'


while (there's another line)
if (the line contains the pattern)
print it

'


return-type function-name(argument declarations)
{
    declarations and statements
}
dummy() {}

return expression;

return (-1);

double atof();
double atof(void);

return atof(s); /* some compilers warn of it */
return (int) atof(s); /* The cast states explicitly that the operation is intended, and suppresses any warning. */

(1 + 2) * (4 + 5)

1 2 - 4 5 + *

while (next operator or operand is not end-of-file indicator)
    if (number)
        push it
    else if (operator)
        pop operands
        do operation
        push result
    else if (newline)
        pop and print top of stack
    else
        error

#include <Stdio.h>
#define MAX 3.14

function declarations for main

int main(void) { ... }

external variables for push and pop

void   push(double f) { ... }
double pop(void) { ... }

int    getop(char s[]) { ... }

routines called by getop


int main(void) { ... }

int    sp = 0;
double val[MAXVAL];

void push(double f) { ... }

double pop(void) { ... }

extern int    sp;
extern double val[];

int    sp;
double val[];


extern int sp = 0;
extern double val[ ];

void push(double f) { ... }
double pop(void) { ... }

int    sp = 0;

#define NUMBER ‘0’

void   push(double);
double pop(void);
int    getop(char []);
int    getch(void);
void   ungetch(int);

#include <stdio.h>
#include <stdlib.h>
#include “calc.h”
#define MAXOP 100
main() {
    …
}

#include <stdio.h>
#include “calc.h”
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
void push(double) {
    …
}
void pop(void) {
    …
}

#include <stdio.h>
#include <ctype.h>
#include “calc.h”
getop {
    …
}

#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void) {
    …
}
void ungetch(int) {
    …
}

static char buf[BUFSIZE]; /* buffer for ungetch */
static int  bufp = 0;     /* next free position in buf */

int getch(void) { ... }
void ungetch(int c) { ... }

register int  x;
register char c;

f(register unsigned m, register long n)
{
    register int i;
    ...
}

if (n > 0) {
    int i; /* declare a new i */
    
    for (i = 0; i < n; i++)
        ...
}

int x;
int y;

f (double x)
{
    double y;
    …
}

printf("%f\n", 2.884002e+14);
/* double atof(char s[]) */

int x = 3;
{
    int c;

    x = 4; /* wrongly entered as 'c' instead of 'x' */
    ...
}

int x = 1;
char squota = '\'';
long day = 1000L * 60L * 60L * 24L; /* milliseconds/day */


int binsearch(int x, int v[], int n)
{
    /*
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    */

    int low  = 0;
    int high = n - 1;
    int mid;
    ...
}

int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

char pattern[] = "ould";
/* is a shorthand for the longer but equivalent */
char pattern[] = { 'o', 'u', 'l', 'd', '\0' };

#include <filename>
#include "filename"

#define name replacement_text

#define YES 123

printf("YES");
printf(YESMAN);
#define forever for (;;) /* infinite loop */

#define max(A, B) ((A) > (B) ? (A) : (B))

x = max(p + q, r + s);  

/* will be replaced by the line */

x = ((p + q) > (r + s) ? (p + q) : (r + s));


max(i++, j++)

#define square(x) x * x /* WRONG */

square(z + 1)

#undef getchar

int getchar(void) { ... }

#define dprint(expr) printf(#expr " = %g\n", expr)

dprint(x/y)

printf("x/y" " = &g\n", x/y);

/* the strings are concatenated, so the effect is */
printf("x/y = &g\n", x/y);

/* paste(name, 1) creates the token name1 */
#define paste(front, back) front ## back

/*
#if !defined(HDR)
#define HDR

#endif
*/


#ifndef HDR
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
