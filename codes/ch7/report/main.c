#include <stdio.h>
#include <ctype.h>
#include "tree.h"

#define MAXWORD 100

int getword(char *, int);

/* word frequency count */
int main(void)
{
    struct tnode *root;
    char   word[MAXWORD];
    FILE   *fp;

    root = NULL;
    fp = fopen("in.txt", "r");
    if (!fp) {
        fprintf(stderr, "fopen() error!\n");
    }
    while (fscanf(fp, "%s", word) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);

    return 0;
}