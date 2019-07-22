```c
/*
 *	Write the function htoi(s), which converts a string of hexadecimal digits
 *	(including an optional 0x or 0X) into its equivalent integer value.
 *	The allowable digits are 0 through 9, a through f, and A through F.	
 */

#include <stdio.h>

int main()
{
	int		c;
	long long	num;

	num = 0;
	if ((c = getchar()) == '0') {
		c = getchar();
		if ((c != 'x') && (c != 'X')) {
			puts("Error!");
			
			return 1;
		}
	} else {
		if ((c >= '0') && (c <= '9')) {
			num = (num * 16) + (c - '0');
		} else if ((c >= 'a') && (c <= 'f')) {
			num = (num * 16) + (c - 'a' + 10);
		} else if ((c >= 'A') && (c <= 'F')) {
			num = (num * 16) + (c - 'A' + 10);
		} else {
			puts("Error!");

			return 1;
		}
	}
	while ((c = getchar()) != EOF) {
		if ((c >= '0') && (c <= '9')) {
			num = (num * 16) + (c - '0');
		} else if ((c >= 'a') && (c <= 'f')) {
			num = (num * 16) + (c - 'a' + 10);
		} else if ((c >= 'A') && (c <= 'F')) {
			num = (num * 16) + (c - 'A' + 10);
		} else if (c == '\n') {
			break;
		} else {
			puts("Error!");

			return 1;
		}
	}
	printf("%lld\n", num);

	return 0;
}
```
