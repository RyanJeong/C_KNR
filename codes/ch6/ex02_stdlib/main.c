#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "key.h"

#define MAXWORD 100

int getword(char *, int);
int cmp(const void *, const void *);

/* count C keywords; pointer version */
int main(void)
{
    struct key *p;
    char       word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            /*
            #include <stdlib.h>
            void *bsearch(const void *key, const void *base,
                        size_t num, size_t size,
                        int (*compare)(const void *key, const void *element));
            */
            if ((p = (struct key *) bsearch(word, keytab, NKEYS, sizeof(struct key), cmp)) != NULL) {
                p->count++;
            }
        }
    }
    for (p = keytab; p < keytab + NKEYS; p++) {
        if (p->count > 0) {
            printf("%4d %s\n", p->count, p->word);
        }
    }

    return 0;
}

int cmp(const void *word, const void *key)
{

    return strcmp((char *) word, ((struct key *) key)->word);
}