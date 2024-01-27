#include <ctype.h>
#include <stdio.h>

#include "key.h"

#define MAXWORD 100

struct key *binsearch(char *, struct key[], int);
int getword(char *, int);

/* count C keywords; pointer version */
int main(void)
{
  struct key *p;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) {
      if ((p = binsearch(word, keytab, NKEYS)) != NULL)
        p->count++;
    }
  }
  for (p = keytab; p < keytab + NKEYS; p++) {
    if (p->count > 0)
      printf("%4d %s\n", p->count, p->word);
  }

  return 0;
}
