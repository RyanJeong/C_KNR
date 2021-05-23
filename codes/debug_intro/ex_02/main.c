#include <stdio.h>

#define SIZE 8

int main(void)
{
    int gap, i, j, temp, n;
    int v[SIZE] = { 17, 33, 10, 6, 41, 36, 14, 1 };

    n = SIZE;
    printf("Before: ");
    for (i = 0; i < SIZE; ++i) {
        printf("%2d%c", v[i], (i == SIZE - 1) ? '\n' : ' ');
    }
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; ++i) {
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                temp     = v[j];
                v[j]     = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
    printf("After:  ");
    for (i = 0; i < SIZE; ++i) {
        printf("%2d%c", v[i], (i == SIZE - 1) ? '\n' : ' ');
    }

    return 0;
}