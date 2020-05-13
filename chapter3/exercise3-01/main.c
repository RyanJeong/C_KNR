/*
 *  Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside).
 *  Write a version with only one test inside the loop and measure the difference in run-time.
 */
#include <stdio.h>
#include <time.h>

enum {
    MAX = 32768
};

void binsearch1(int, int [], int);
void binsearch2(int, int [], int);

int main(void)
{
    int series[MAX], i, target;

    for (i = 0; i < MAX; ++i) {
        *(series + i) = i;
    }
    printf("%s\n%s\n", 
            "Binary search performance between two tests model and one test model.",
            "Input number between 0 to 32,767.");
    scanf("%d", &target);
    binsearch1(target, series, MAX);  
    binsearch2(target, series, MAX);  

    return 0;
}

void binsearch1(int x, int v[], int n)
{
    int     low, high, mid;
    clock_t time;

    time    = clock();
    low     = 0;
    high    = (n - 1);
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = (mid - 1);
        } else if (x > v[mid]) {
            low = (mid + 1);
        } else {

            break;  /*  found!  */
        }
    }
    printf("Binsearch1's result: %s, used time: %lf\n", (mid == x) ? "Found!" : "Not found...", (double) (time - clock()) / CLOCKS_PER_SEC);

    return;
}

void binsearch2(int x, int v[], int n)
{
    int     low, high, mid;
    clock_t time;

    time    = clock();
    low     = 0;
    high    = (n - 1);
    mid     = (low + high) >> 1;
    while ((low < high) && (x != v[mid])) {
        if (x > v[mid]) {
            low = (mid + 1);
        } else {
            high = (mid - 1);
        }
        mid = (low + high) >> 1;
    }
    printf("Binsearch1's result: %s, used time: %lf\n", (mid == x) ? "Found!" : "Not found...", (double) (time - clock()) / CLOCKS_PER_SEC);

    return;
}
