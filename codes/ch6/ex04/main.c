#include <stdio.h>

#include "table.h"

void itoa(int n, char s[]);

extern struct nlist *hashtab[HASHSIZE]; /* pointer table */

int main(int argc, char *argv[])
{
  char *str[] = { "OFF", "ON", "ERROR" };
  char buf[10];
  struct nlist *temp;
  int i, size;

  size = sizeof str / sizeof(char *);
  for (i = 0; i < size; ++i) {
    itoa(i, buf);
    /* return NULL if for any reason there is no room for a new entry */
    if (!install(str[i], buf))
      return -1;
  }
  for (i = 0; i < size; ++i) {
    /* if the string is to be found anywhere */
    if ((temp = lookup(str[i])))
      printf("%6s: %2s\n", temp->name, temp->defn);
  }
  install("ERROR", "-1");
  printf("%6s: %2s\n", lookup("ERROR")->name, lookup("ERROR")->defn);

  return 0;
}
