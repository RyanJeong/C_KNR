#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100

struct tnode {           /* the tree node: */
    char *word;          /* points to the text */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
};

struct tnode *addtree(struct tnode *, char *);
void         treeprint(struct tnode *);
int          getword(char *, int);

/* word frequency count */
int main(void)
{
    struct tnode *root;
    char   word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);

    return 0;
}

#include <string.h>

struct tnode *talloc(void);
char         *strdup(char *);

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

    return;
}

#include <stdlib.h>

/* talloc: make a tnode */
struct tnode *talloc(void)
{

    return (struct tnode *) malloc(sizeof(struct tnode));
}


char *strdup(char *s)
{
    char *p;

    /* make a duplicate of s */
    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p) { /* p != NULL */
        strcpy(p, s);
    }

    return p;
}
