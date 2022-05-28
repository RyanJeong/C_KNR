#ifndef A
#include <stdio.h>
int foo() 
{
  char arr[100];
  printf("\n");
  sprintf(arr, "\n");

}

#include <stdio.h>

char line[10000];

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void f() {
  int month, day, year;
  char monthname[20];

  while (getline(line, sizeof(line)) > 0) {
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
      printf("valid: %s\n", line);  /* 25 Dec 1998 form */
    else if (sscanf(line, "%d%d%d", &month, &day, &year) == 3)
      printf("valid: %s\n", line);  /* mm/dd/yy form */
    else
      printf("invalid: %s\n", line);  /* invalid form */
  }
}

#endif

#ifndef B
#include <stdio.h>

void f()
{
  int n;

  scanf("%d", n); /* ERROR! */
  scanf("%d", &n); /* OK */
}

FILE *fp;
FILE *fopen(char *name, char *mode);
int getc(FILE *fp);
int putc(int c, FILE *fp);

#define getchar() getc(stdin)
#define putchar(c) putc((c), stdout)

int fscanf(FILE *fp, char *format, ...);
int fprintf(FILE *fp, char *format, ...);

int ferror(FILE *fp);
int feof(FILE *fp);

char *fgets(char *line, int maxline, FILE *fp);
int fputs(char *line, FILE *fp);

#ifdef getchar
#undef getchar
#endif
int getchar(void);
char *gets(char *line);

#ifdef putchar
#undef putchar
#endif
int putchar(int c);
int puts(char *line);

int fclose(FILE *stream);

void b()
{
  char *name, *mode;
  fp = fopen(name, mode);
}
#endif
