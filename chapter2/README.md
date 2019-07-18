# 제2장 Types, Operators, and Expressions

## 요약
*	t<br>
	*	tt<br>

## 소스코드
### 2.3 Constants<br>
```c
/*	bit patterns(\000 or \xhh)	*/
#define	VTAB	'\013'	/*	ASCII vertical tab	*/
#define	BELL	'\007'	/*	ASCII bell character	*/
#define	VTAB	'\xb'	/*	ASCII vertical tab	*/
#define	BELL	'\x7'	/*	ASCII bell character	*/
```
```c
/*	strlen: return length of s	*/
int strlen(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\0') {
		++i;
	}

	return i;
}
```
```c
/*	enum	*/
enum boolean {
	NO, YES
};

enum escapes {
	BELL		= '\a',
	BACKSPACE	= '\b',
	TAB		= '\t',
	NEWLINE		= '\n',
	VTAB		= '\v',
	RETURN		= '\r'
};

enum months {
	JAN	= 1,
	FEB, MAR, APR, MAY,
	JUN, JUL, AUG, SEP,
	OCT, NOV, DEC
};	/*	FEB is 2, MAR is 3, ...	*/
```
### 2.5 Arithmetic Operators<br>
```c
/*	leap year	*/
if ((!(year % 4) && (year % 100)) || !(year % 400)) {
	printf("%d is a leap year\n", year);
} else {
	printf("%d is not a leap year\n", year);
}
```
### 2.7 Type Conversions<br>
```c
/*	atoi: convert s to integer	*/
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; (s[i] >= '0') && (s[i] <= '9'); ++i) {
		n = (10 * n) + (s[i] - '0');
	}

	return n;
}
```
```c
/*	lower: convert c to lower case; ASCII only	*/
int lower(int c)
{
	if ((c >= 'A') && (c <= 'Z')) {

		return (c + ('a' - 'A'));
	} else {

		return c;
	}
}
```
#### Convention rules
* If either operand is long double, convert the other to long double.
* Otherwise, if either operand is double, convert the other to double.
* Otherwise, if either operand is float, convert the other to float. 
* Otherwise, convert char and short to int.
* Then, if either operand is long, convert the other to long.
> For example, suppose that int is 16 bits and long is 32 bits. Then
-1L < 1U, because 1U, which is an int, is promoted to a signed long. But -1L > 1UL, because -1L is promoted to unsigned long and thus appears to be a large positive number.
```c
unsigned long int next = 1;

/*	rand: return pseudo-random integer on 0..32,767	*/
int rand(void)
{
	next = (next * 1103515245) + 12345;
	
	return (unsigned int) (next / 65536) % 32768;
}

/*	srand: set seed for rand()	*/
void srand(unsigned int seed)
{
	next = seed;
}
```
### 2.8 Increment and Decrement Operators
```c
/*	squeeze: delete all c from s	*/
void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; ++i) {
		if (s[i] != c) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
	
	return;
}
```
```c
/*	strcat: concatenate t to end of s; s must be big enough	*/
void strcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') {	/*	find end of s	*/
		++i;
	}
	while ((s[i++] = t[j++]) != '\0') {	/*	copy t	*/
		;
	}

	return;
}
```
### 2.9 Bitwise Operators
```c
/*	AND operator, used to mask off some set of bits;	*/
n &= 0177;
```
```c
/*	OR operator, used to turn bits on;	*/
x |= SET_ON;
```
```c
/*	getbits: get n bits from position p	*/
unsigned getbits(unsigned x, int p, int n)
{

	return (x >> (p + 1 - n)) & ~(~0 << n);
}
```
### 2.10 Assignment Operators and Expressions
```c
/*	bitcount: count 1 bits in x	*/
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1) {
		if (x & 0x) {
			++b;
		}
	}

	return b;
}
```
### 2.11 Conditional Expressions
```c
for (i = 0; i < n; ++i) {
	printf("%6d%c", a[i], ((i % 10) == 9) || (i == (n - 1)) ? '\n' : ' ');
}
```
```c
printf("You have %d item%s\n", n, (n == 1) ? "" : "s");
```
### 2.12 Precedence and Order of Evaluation
```c
printf("%d %d\n", ++n, power(2, n));	/*	WRONG	*/
```
```c
++n;
printf("%d %d\n", n, power(2, n));
```
```
a[i] = i++;	/*	?	*/
```
