#include <ctype.h>
#include <string.h>
#include "qsort.h"

extern int order;  /*  1 if reserse order  */
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    void    swap(void *v[], int, int);
    int     i, last;

    if (left >= right) {    /* do nothing if array contains */

        return; /* fewer than two elements */
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if ((*comp)((order ? v[left] : v[i]), (order ? v[i] : v[left])) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {

        return -1;
    } else if (v1 > v2) {

        return 1;
    } else {

        return 0;
    }
}

/* atof: convert string s to double */
double atof(const char s[])
{
    double  val, power;
    int     i, sign;

    for (i = 0; isspace(s[i]); ++i) {   /* skip white space */
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = (10.0 * val + (s[i] - '0'));
    }
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = (10.0 * val + (s[i] - '0'));
        power *= 10;
    }

    return sign * val / power;
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
