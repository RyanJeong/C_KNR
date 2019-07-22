/*
 *	Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted
 *	(i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 */

#include <stdio.h>

unsigned	invert(unsigned, int, int);
void		printDecToBin(unsigned);
void		_printDecToBin(unsigned);

int main(void)
{
	unsigned	x, result;
	int		p, n, c;
	
	puts("Select mode, 1: input binary, 2: input decimal");
	c = getchar();
	if (getchar() != '\n') {
		puts("Error!");
		
		return 1;
	} else if (c == '1') {
		puts("Input x in binary");
		x = 0;
		while ((c = getchar()) != '\n') {
			x = (x << 1) + (c - '0');
		}
		puts("Input p");
		scanf("%d", &p);
		getchar();
		puts("Input n");
		scanf("%d", &n);
		getchar();
	} else if (c == '2') {
		puts("Input x in decimal");
		scanf("%u", &x);
		getchar();
		puts("Input p");
		scanf("%d", &p);
		getchar();
		puts("Input n");
		scanf("%d", &n);
		getchar();
	} else {
		puts("Error!");

		return 1;
	}
	result = invert(x, p, n);
	printf("Result in binary: ");
	printDecToBin(result);
	printf("\nResult in decimal :%u\n", result);

	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	
	return (x ^ (~(~0 << n) << (p + 1 - n)));
}

void printDecToBin(unsigned u)
{
	(u) ? _printDecToBin(u) : putchar('0');

	return;
}

void _printDecToBin(unsigned u)
{
	if (u) {
		_printDecToBin((u >> 1));	
		putchar((u & 01) + '0');
	}

	return;	
}
