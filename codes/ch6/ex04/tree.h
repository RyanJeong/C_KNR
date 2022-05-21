#ifndef __WORD_TREE_H__
#define __WORD_TREE_H__

struct tnode {          /* the tree node: */
  char *word;           /* points to the text */
  int count;            /* number of occurrences */
  struct tnode *left;   /* left child */
  struct tnode *right;  /* right child */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);

#endif  /* __WORD_TREE_H__ */