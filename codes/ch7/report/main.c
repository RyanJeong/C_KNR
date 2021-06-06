#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

#define MAXWORD 100

int getword(char *, int);

/* word frequency count */
int main(void)
{
    struct tnode *root;
    char   word[MAXWORD];
    FILE   *ifp, *ofp;

    root = NULL;
    ifp = fopen("in.txt", "r");
    ofp = fopen("out.txt", "w");
    if (!ifp || !ofp) {
        fprintf(stderr, "fopen() error!\n");
        exit(1);
    }
    while (fscanf(ifp, "%s", word) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    if (ferror(ifp)) {
        fprintf(stderr, "fscanf() error!\n");
        exit(1);
    }
    treeprint(root, ofp);
    if (ferror(ofp)) {
        fprintf(stderr, "fprintf() error!\n");
        exit(1);
    }
    if (fclose(ifp) || fclose(ofp)) {
        fprintf(stderr, "fclose() error!\n");
        exit(1);
    };

    return 0;
}