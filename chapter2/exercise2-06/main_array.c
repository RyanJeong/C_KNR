/*
 *	Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y,
 *	leaving the other bits unchanged.
 */
#include <stdio.h>
#define MAX	33

void setbits(char *, int, int, int);

int main()
{
	int	c, p, n, y, limit, length;
	char	buffer[MAX];
	char	*p_buffer;

	p_buffer	= buffer;	
	limit		= (MAX - 1);
	length		= 0;
	puts("Index is starting from value 0");
	puts("Input x");
	for (length = 0; ((c = getchar()) != EOF); ++length) {
		if (c == '\n') {
			break;
		} else {
			*p_buffer++ = c;
		}
		if (length == limit) {
			while (getchar() != '\n') {
				;
			}
			break;
		}
	}
	*p_buffer = '\0';
	puts("Input p");
	scanf("%d", &p);
	getchar();
	puts("Input n");
	scanf("%d", &n);
	getchar();
	puts("Input y");
	scanf("%d", &y);
	getchar();
	printf("%s%s%s%d%s%d%s%d\n", 
		"\nx: ", buffer, 
		"\np: ", p,
		"\nn: ", n,
		"\ny: ", y);
	if ((n > length) || ((p - n + 1) < 0) || ((y - n + 1) < 0)) {
		puts("Error!");
	} else {
		setbits(buffer, p, n, y);
	}
	printf("%s%s\n", "result: ", buffer);

	return 0;
}

void setbits(char *x, int p, int n, int y)
{
	char	*src, *dest;
	int	x_length;
	
	src = x;
	for (x_length = 0; *src++; ++x_length) {
		;
	}
	src	= (x + x_length - y - 1);
	dest	= (x + x_length - p - 1);
	while (n--) {
		*dest++ = *src++;
	}

	return;
}
