#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int cmp(const void *, const void *);

int main(void)
{
    char *str[SIZE] = { 
      "Alpha", "Charlie", "Juliett", "Echo",  "Golf", 
      "Hotel", "India",   "Bravo",   "Delta", "Foxtrot" 
    };
    int  i;

    printf("Before: ");
    for (i = 0; i < SIZE; ++i) {
      printf("%10s%c", str[i], i == SIZE - 1 ? '\n' : ' ' );
    }
    /*
    void qsort (void *base, size_t num, size_t size,
                int (*compar)(const void *,const void *));
    */
    qsort(str, SIZE, sizeof(char *), cmp);
    printf("After : ");
    for (i = 0; i < SIZE; ++i) {
      printf("%10s%c", str[i], i == SIZE - 1 ? '\n' : ' ' );
    }

    return 0;
}

/* strcmp(const char *s, const char *t) */
/* *s = (char *) "Alpha", *t = (char *) "Beta" */
/* *s = (char *) "Beta",  *t = (char *) "Beta" */
/* *s = (char *) "Beta",  *t = (char *) "Alpha" */
int cmp(const void *s, const void *t)
{
    
    return strcmp(*(char **) s, *(char **) t);
}