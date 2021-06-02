#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(void)
{
  char s[MAX], *pos;

  fgets(s, MAX, stdin);
  if ((pos = strrchr(s, '\n'))) {
    *pos = '\0';
  }
  printf("%s %d", s, strlen(s));

  return 0;
}