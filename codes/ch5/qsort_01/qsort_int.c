#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int cmp(const void *, const void *);

int main(void)
{
    int arr[SIZE] = { 32, 15, 31, 76, 3, 99, 23, -56, -28, 2 };
    int i;

    printf("Before: ");
    for (i = 0; i < SIZE; ++i) {
      printf("%3d%c", arr[i], i == SIZE - 1 ? '\n' : ' ' );
    }
    /*
    void qsort (void *base, size_t num, size_t size,
                int (*compar)(const void *,const void *));
    */
    qsort(arr, SIZE, sizeof(int), cmp);
    printf("After : ");
    for (i = 0; i < SIZE; ++i) {
      printf("%3d%c", arr[i], i == SIZE - 1 ? '\n' : ' ' );
    }

    return 0;
}

/* *s = (int) 2, *t = (int) 3 */
/* *s = (int) 2, *t = (int) 2 */
/* *s = (int) 3, *t = (int) 2 */
int cmp(const void *s, const void *t)
{
    
    return (*(int *) s - *(int *) t);
}