/*
 *	Write the function htoi(s), which converts a string of hexadecimal digits
 *	(including an optional 0x or 0X) into its equivalent integer value.
 *	The allowable digits are 0 through 9, a through f, and A through F.	
 */

//	not completed yet
int main()
{
	int c, num;

	num = 0;
	if ((c = getchar()) == '0') {
		c = getchar();
		if ((c == 'x') || (c == 'X')) {
			
	while ((c = getchar()) != EOF) {
		// do something ... 
	}
	printf("%d\n", num);

	return 0;
}
