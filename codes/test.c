#include <stdio.h>
#include <math.h>

int main(void)
{
struct nlist {          /* table entry: */
    struct nlist *next; /* next entry in chain */
    char         *name; /* defined name */
    char         *defn; /* replacement text */
};

struct nlist *np;

printf("%ld\n", sizeof(*np));

return 0;
}