#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

char *strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (!p) { /* p == NULL, a new word has arrived */
        p        = talloc();  /* make a new node */
        p->word  = strdup(w);
        p->count = 1;
        p->left  = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) > 0) { 
        /* greater than into right subtree */
        p->right = addtree(p->right, w);
    } else if (cond < 0) { 
        /* less than into left subtree */
        p->left = addtree(p->left, w);
    } else {  
        /* repeated word */
        p->count++;
    }

    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p) { /* p != NULL */
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}