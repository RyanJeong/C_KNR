```C
/*
 *  Write the function strrindex(s, t), which returns the position of the rightmost occurrence of t in s,
 *  or -1 if there is none.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getLine(char *, int);
int strrindex(char *, char *);

/*
 *  Examples:
 * 
 * Could, would, and should are all used to talk about possible events or situations, but each one tells us something different.
 * Could is used to say that an action or event is possible. Would is used to talk about a possible or imagined situation, and is often used when that possible situation is not going to happen. Should is used to say that something is the proper or best thing to do, or to say that someone ought to do something or must do something.
 */
char *pattern = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0) {
        printf("%d\n", strrindex(line, pattern));
    }

    return 0;
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

/* strrindex: returns the position of the rightmost occurrence of t in s, -1 if none */
int strrindex(char *s, char *t)
{
    int     sLen, tLen, tLenTemp;
    char    *temp;

    sLen = tLen = 0;
    temp = s;
    while (*temp++ != '\0') {
        ++sLen;
    }
    temp = t;
    while (*temp++ != '\0') {
        ++tLen;
    }
    if ((sLen > 0) && (tLen > 0)) {
        --tLen; /*  길이와 인덱스는 1 차이가 나므로 */
        while (sLen--) {
            if (tLen > sLen) {  /*  tLen이 sLen보다 더 길면, 패턴을 찾을 수가 없음  */

                return (-1);
            } 
            if (*(s + sLen) == *(t + tLen)) {
                tLenTemp = tLen;
                --sLen;     /*  sLen번째 비교 끝났으므로 1 감산 */
                --tLenTemp; /*  tLen번째 비교 끝났으므로 1 감산 */
                while (tLenTemp && (*(s + sLen) == *(t + tLenTemp))) {
                    --sLen;
                    --tLenTemp;
                }
                if (!tLenTemp) {

                    return sLen;
                }
            }
        }
    }
    
    return -1;
}
```
