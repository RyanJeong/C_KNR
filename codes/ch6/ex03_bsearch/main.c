/* ch5/ex08_sort2_01 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/* 
qsort: https://www.cplusplus.com/reference/cstdlib/qsort/
int compar (const void* p1, const void* p2);

return value | meaning
-------------+------------------------------------------------------------------
<0           | The element pointed to by p1 goes before the element pointed to
             | by p2
-------------+------------------------------------------------------------------
0            | The element pointed to by p1 is equivalent to the element pointed
             | to by p2
-------------+------------------------------------------------------------------
>0           | The element pointed to by p1 goes after the element pointed to by
             | p2

bsearch: https://www.cplusplus.com/reference/cstdlib/bsearch/
int compar (const void* pkey, const void* pelem);

return value | meaning
-------------+------------------------------------------------------------------
<0           | The element pointed to by pkey goes before the element pointed to
             | by pelem
-------------+------------------------------------------------------------------
0            | The element pointed to by pkey is equivalent to the element
             | pointed to by pelem
-------------+------------------------------------------------------------------
>0           | The element pointed to by pkey goes after the element pointed to
             | by pelem
*/

int cmp(const void *, const void *);

int main(void)
{
  int arr[SIZE] = { 32, 15, 31, 76, 3, 99, 23, -56, -28, 2 };
  int i, target;

  printf("Before: ");
  for (i = 0; i < SIZE; ++i)
    printf("%3d%c", arr[i], i == SIZE - 1 ? '\n' : ' ');
  qsort(arr, SIZE, sizeof(int), cmp);
  printf("After : ");
  for (i = 0; i < SIZE; ++i)
    printf("%3d%c", arr[i], i == SIZE - 1 ? '\n' : ' ');

  target = 16;
  printf("%d %s\n", target, (bsearch(&target, arr, SIZE, sizeof(int), cmp) ?
      "is found" : "is not found"));
  target = 32; 
  printf("%d %s\n", target, (bsearch(&target, arr, SIZE, sizeof(int), cmp) ?
      "is found" : "is not found"));

  return 0;
}

int cmp(const void *s, const void *t)
{
  return (*(int *) s - *(int *) t);
}

