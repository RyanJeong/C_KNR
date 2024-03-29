#include <ctype.h>
#include <stdio.h>

#include "tree.h"

#define MAXWORD 100

int getword(char *, int);

/* word frequency count */
int main(void)
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0]))
      root = addtree(root, word);
  }
  treeprint(root);

  return 0;
}
