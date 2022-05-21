#ifndef __TABLE_TABLE_H__
#define __TABLE_TABLE_H__

struct nlist {         /* table entry: */
  struct nlist *next;  /* next entry in chain */
  char *name;          /* defined name */
  char *defn;          /* replacement text */
};

#define HASHSIZE 101

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);

#endif /* __TABLE_TABLE_H__ */
