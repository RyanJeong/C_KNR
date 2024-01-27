#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

char *strdup(char *s);

struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

  return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
    if (!strcmp(s, np->name))
      return np; /* found */
  }

  return NULL; /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if (!(np = lookup(name))) {
    /* not found */
    np = (struct nlist *) malloc(sizeof(*np));
    if (!np || !(np->name = strdup(name)))
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {
    /* already there */
    free((void *) np->defn); /* free previous defn */
  }
  if (!(np->defn = strdup(defn)))
    return NULL;

  return np;
}
