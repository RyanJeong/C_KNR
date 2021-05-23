#include <stdio.h>

#define SIZE 17

int main(void)
{
    int low, high, mid, x, is_match;
    int v[SIZE] = { 1, 3, 4, 6, 7, 8, 10, 13, 
                    14, 18, 19, 21, 24, 37, 40, 45, 71 };
    
    x        = 7;
    is_match = -1;
    low      = 0;
    high     = SIZE - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = (mid - 1);
        } else if (x > v[mid]) {
            low = (mid + 1);
        } else {
            is_match = mid; /*  found match */
            break;
        }
    }
    printf("%s\n", 
        is_match == -1 ? 
        "no match" : 
        "found match");

    return 0;
}