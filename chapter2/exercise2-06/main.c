/*
 *	Write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set to the rightmost n bits of y,
 *	leaving the other bits unchanged.
 */
#include <stdio.h>

unsigned	setbits(unsigned, int, int, unsigned);
void		printDecToBin(unsigned);
void		_printDecToBin(unsigned);

int main(void)
{
	unsigned	x, y, result;
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
		puts("Input y in binary");
		y = 0;
		while ((c = getchar()) != '\n') {
			y = (y << 1) + (c - '0');
		}
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
		puts("Input y in binary");
		scanf("%u", &y);
	} else {
		puts("Error!");

		return 1;
	}
	result = setbits(x, p, n, y);
	printf("Result in binary: ");
	printDecToBin(result);
	printf("\nResult in decimal :%u\n", result);

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{

	return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n));
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
