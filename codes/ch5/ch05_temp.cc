#include <stdlib.h>

void ff(void)
{
char c;
char *p;

p = &c;

double *dp, atof(char *);
int x = 1, y = 2, z[10];
int *ip;	/* ip is a pointer to int */

ip = &x;	/* ip now points to x */
y = *ip;	/* y is now 1 */
*ip = 0;	/* x is now 0 */
ip = &z[0]; /* ip now points to z[0] */

/* x = x + 10 */
*ip = *ip + 10;
}

void fff(void)
{
int x = 10, y = 20;
int *ip = &x;

int a[10][20];
int *b[20];

y = *ip + 1;  /* y is now 11 */
*ip += 1;  /* x is now 11 */
++*ip;  /* x is now 12 */
(*ip)++;  /* x is now 13 */
}

void ffff(void)
{
int *ip, *iq, i;

char *name[] = { "Illegal month", "Jan", "Feb", "Mar" };
char aname[][15] = { "Illegal month", "Jan", "Feb", "Mar" };
i = 3;
ip = &i;
iq = ip;
}
// int main(void)
// {
// char c;
// char *p;
// 
// int a[3][4];
// a[c][c];
// 
// /* unary operator & gives the address of an object */
// p = &c;
// 
// int x = 1, y = 2, z[10];
// int *ip;	/* ip is a pointer to int */
// 
// ip  = &x;	/* ip now points to x */
// y   = *ip;	/* y is now 1 */
// *ip = 0;	/* x is now 0 */
// ip  = &z[0]; /* ip now points to z[0] */
// 
// 
// int a[10];
// 
// int *pa;
// 
// pa = &a[0];
// 
// }
// 
// strlen("hello, world");    /* string constant */
// strlen(array);             /* char array[100]; */
// strlen(ptr);               /* char *ptr; */
// 
// char s[];
// char *s;
// 
// void f(int arr[]) { ... }
// void f(int *arr)  { ... }
// 
// f(&a[2]);
// f(a + 2);
// 
// printf("Hello, World!");
// 
// char *pmessage;
// 
// pmessage = "now is the time";
// 
// char amessage[] = "now is the time"; /* an array */
// char *pmessage  = "now is the time"; /* a pointer */
// 
// 
// daytab[i][j]   /* [row][col] */
// daytab[ i, j ] /* WRONG */
// 
// /* if the array daytab is to be passed to a function f, 
// the declaration of f would be */
// f(int daytab[2][13]) { … }
// /* 
// f(int daytab[ ][13]) { … }
// f(int (*daytab)[13]) { … }
// 
// int *daytab[13] /* an array of 13 pointers to integers */
// 
// char *name[] = { "Illegal month", "Jan", "Feb", "Mar" };
// char aname[][15] = { "Illegal month", "Jan", "Feb", "Mar" };
// 
// /* to pass command line arguments, we typically define main() with two arguments */
// int main(int argc, char *argv[])
// 
// /* if you do not intend to process command line arguments */
// int main(void)
// 
// int *comp(void *, void *);
// 
// int *f();       /* f   : function returning pointer to int */
// int (*pf)();    /* pf  : pointer to function returning int */
// 
// (*pfa[])()
// 