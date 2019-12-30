/*
 *  Extend atof to handle scientific notation of the form 123.45e-6
 *  where a floating-point number may be followed by e or E and an optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000 /* maximum input line length */

int     getLine(char *, int);
double  atofEx(char *);

int main()
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0) {
        printf("%lf\n", atofEx(line));
    }

    return 0;
}
/*
 *  atofEx: convert string s to double extension version
 *  ----------------
 *  Examples:
 *  123.45e-6
 *  123e-3
 *  123E4
 *  -123E+2
 */

double atofEx(char *s)
{
    double  val, power;
    int     sign, exSign, ex;

    while (isspace(*s)) {   /* skip white space */
        ++s;
    }
    sign = (*s == '-') ? (-1) : 1;
    if ((*s == '+') || (*s == '-')) {
        ++s;
    }
    val = 0.0;
    while (isdigit(*s)) {
        val = (10.0 * val) + (*s++ - '0');
    }
    if (*s == '.') {
        ++s;
    }
    power = 1.0;
    while (isdigit(*s)) {
        val     = (10.0 * val) + (*s++ - '0');
        power   *= 10;
    }
    if ((*s == 'e') || (*s == 'E')) {
        ++s;
    }
    exSign = (*s == '-') ? (-1) : 1;
    if ((*s == '+') || (*s == '-')) {
        ++s;
    }
    ex = 0;
    while (isdigit(*s)) {
        ex = (ex * 10) + (*s++ - '0');
    }
    if (exSign == (-1)) {
        while (ex--) {
            power *= 10.0;
        }
    } else {
        while (ex--) {
            power /= 10.0;
        }
    }

    return sign * (val / power);
}

/* getLine: get line into s, return length */
int getLine(char *s, int lim)
{
    int     c;
    char    *p;

    c = 0;
    p = s;
    /*  
     *  만약 lim의 값이 1이고, 입력으로 '\n'이 들어온다면, 
     *  (--lim > 0) 조건에서 만족하지 않으므로 while문을 벗어나고,
     *  ((c = getchar()) != EOF)를 수행하지 않았으므로 c에는 값이 들어오지 않는다(이런 경우 때문에 초기화를 꼭 해야함)
     *  그리고 다음 if문인 if (c == '\n') 조건에서 만족하지 않으므로 다음 if문으로 넘어가고,
     *  결국 lim이 1인 버퍼 안에는 '\0'만 들어가게 됨   
     */
    while ((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n')) {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';

    return (s - p);
}

