#include <string.h>

struct a {
    int  len;
    char *str;
};

int main(void)
{
    char     s[] = "Hello, world!";
    int      l   = strlen(s);
    struct a sa  = { l, s };
    struct a *p  = &sa;

    ++p->len;   /* increments len, not p 
                  implied parenthesization is ++(p->len) */
    sa.len = l;
    (++p)->len; /* increments p before accessing len */
    p = &sa;
    (p++)->len; /* increments p afterward
                  set of parentheses is unnecessary. */
    p = &sa;
    p++->len;
    p = &sa;

    printf("%c\n", *p->str);     /* fetches whatever str points to */
    printf("%c\n", *p->str++);   /* increments str after accessing whatever it points to */
    printf("%c\n", (*p->str)++); /* increments whatever str points to */
    printf("%c\n", *p++->str);   /* increments p after accessing whatever str points to */

    return 0;
}