#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
  char line[MAXLINE];
  int found;
  int len;

  found = 0;
  do {
    int c;
    int i, j, k;
    int lim;

    i = 0;
    lim = MAXLINE;
    while ((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n'))
      line[i++] = c;
    if (c == '\n')
      line[i++] = c;
    line[len = i] = '\0';

    for (i = 0; line[i] != '\0'; ++i) {
      for (j = i, k = 0; (pattern[k] != '\0') && (line[j] == pattern[k]);
           ++j, ++k) {}
      if (k > 0 && pattern[k] == '\0') {
        ++found;
        printf("%s", line);
        break;
      }
    }
  } while (len > 0);

  return found;
}
