//	need to fix it
/*
 *	Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside).
 *	Write a version with only one test inside the loop and measure the difference in run-time.
 */
#include <stdio.h>
#include <time.h>
#define MAX 32768

int binsearch1(int, int [], int);
int binsearch2(int, int [], int);

int main()
{
	int	series[MAX], i, target;
	clock_t	start, end;
	double	cpu_time_used;

	for (i = 0; i < MAX; ++i) {
		*(series + i) = i;
	}
  
	printf("%s\n%s\n", 
			"Binary search performance between two tests model and one test model.",
			"Input number between 0 to 32,767.");
	fflush(stdout);
	scanf("%d", &target);

	
	start	= clock();
	end	= clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	return 0;
}

int binsearch1(int x, int v[], int n)
{
	int low, high, mid;

	low	= 0;
	high	= (n - 1);
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = (mid - 1);
		} else if (x > v[mid]) {
			low = (mid + 1);
		} else {

			return mid;	// found match
		}
	}

	return (-1);	// no match
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low	= 0;
	high	= (n - 1);
	while ((low <= high) || (x != v[mid])) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = (mid - 1);
		} else if (x > v[mid]) {
			low = (mid + 1);
		} else {

			return mid;	// found match
		}
	}

	return (-1);	// no match
}
