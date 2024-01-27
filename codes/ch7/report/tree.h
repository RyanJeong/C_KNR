#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>

struct tnode {         /* the tree node: */
  char *word;          /* points to the text */
  int count;           /* number of occurrences */
  struct tnode *left;  /* left child */
  struct tnode *right; /* right child */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *, FILE *);
struct tnode *talloc(void);

#endif /* __TREE_H__ */
