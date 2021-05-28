#ifdef A
int printf(char *format, arg1 , arg2 , ... )

#include <stdio.h>

char line[10000];

/* getline: read a line into s, return length */
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

void f() {

int  month, day, year;
char monthname[20];

while (getline(line, sizeof(line)) > 0) {
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {
      printf("valid: %s\n", line); /* 25 Dec 1998 form */
    } else if (sscanf(line, "%d%d%d", &month, &day, &year) == 3) {
      printf("valid: %s\n", line); /* mm/dd/yy form */
    } else {
      printf("invalid: %s\n", line); /* invalid form */
    }
}
}
#endif

#ifndef B
#include <stdio.h>

void f()
{
  int n;

  scanf("%d", n);  /* ERROR! */
  scanf("%d", &n); /* OK */
}

FILE *fp;
FILE *fopen(char *name, char *mode);
int getc(FILE *fp);

void b()
{
  char *name, *mode;
  fp = fopen(name, mode);


}
#endif