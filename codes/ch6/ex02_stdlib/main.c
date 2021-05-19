#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "key.h"

#define MAXWORD 100

int getword(char *, int);
int compareStr(const void *, const void *);

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
            if ((p = (struct key *) bsearch(word, keytab, NKEYS, sizeof(struct key), compareStr)) != NULL) {
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

int compareStr(const void *word, const void *key)
{
    const char *s = (const char *) word;
    const char *t = (const char *) ((struct key *) key)->word;

    return strcmp(s, t);
}