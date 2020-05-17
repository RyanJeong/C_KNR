/*
 * Implement a simple version of the #define processor (i.e., no arguments)
 * suitable for use with C programs, based on the routines of this section.
 * You may also find getch and ungetch helpful.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {      /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

#define HASHSIZE 101
#define MAXWORD 100

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

unsigned        hash(char *);
struct nlist    *lookup(char *);
struct nlist    *install(char *, char *);
int             getword(char *, int);
char            *strdup(char *);

int main(void)
{
    char word[MAXWORD];
    
    while (getword(word, MAXWORD) != EOF) {

    }

    return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {

            return np;  /* found */
        }
    }

    return NULL;    /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist    *np;
    unsigned        hashval;

    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL) {

            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {    /* already there */
        free((void *) np->defn);    /*free previous defn */
    }
    if ((np->defn = strdup(defn)) == NULL) {

        return NULL;
    }

    return np;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int     c, getch(void);
    void    ungetch(int);
    char    *w;

    w = word;
    while (isspace(c = getch())) {
        ;
    }
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';

        return c;
    }
    for ( ; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}

/* make a duplicate of s */
char *strdup(char *s)
{
    char *p;

    /* make a duplicate of s */
    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL) {
        strcpy(p, s);
    }

    return p;
}
