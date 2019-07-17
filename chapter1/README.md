# 제1장 언어소개

## 요약
*	site_t: 가장 큰 사이즈를 담을 수 있는 unsigned 정수형을 나타냄<br>
*	변수형의 정밀도는 '기종'에 따라 다름<br>
	*	16-bit PDP-11	: 16-bit 부호숫자<br>
	*	32-bit CPU	: 32-bit 부호숫자<br>
* indentation: 프로그램의 구조를 알기 쉽도록 들여쓰기를 하는 것 <br>
* C에서 char 형과 int 형을 같이 계산할 경우 모든 변수는 int 형으로 간주됨(type cast)<br>
* 함수를 호출할 때 사용하는 매개변수: argument, actual argument<br>
* 함수 내에서 사용되는 매개변수: parameter, formal argument<br>
* 외부 변수 사용 시 extern 키워드를 사용해야 함 <br>
* && 또는 ||: 왼쪽부터 차례대로 조건 검사하며, 조건 검사 도중에 조건이 만족되는 식을 만날 경우 조건 검사를 마침 <br>
* long 형으로 값을 저장할 수 없을 때 double 형으로 값 저장함<br>
* 만약 함수 내부에서 외부 변수를 사용할 경우,<br>
	1. 외부 변수와 함수가 같은 파일 내에 선언된 경우, extern 키워드 선택 가능<br>
	2. 외부 변수와 함수가 서로 다른 파일에 선언된 경우, extern 키워드 필수<br>
* 문자를 처리하는 변수의 type을 char 형이 아닌 int 형을 사용하는 이유는 ASCII 코드와 같이 양의 정수로 이루어진 문자는 상관 없지만 EOF(-1)과 같은 값은 char 형으로 처리할 수 없음<br>

## 소스코드
### 1.1 Getting Started<br>
```c
#include <stdio.h>          		// * include information about standard library

main()                      		// * define a function named main
					//   that receives no argument values
{					// * statements of main are enclosed in braces
					// * main calls library function printf to 
	printf("Hello, world\n");	//   print this sequence of characters; 
					//   \n represents the newline character
}					
```
```c
#include <stdio.h>

main()
{
	printf("hello, ");
	printf("world");
	printf("\n");
}
```
### 1.2 Variables and Arithmetic Expressions<br>
```c
#include <stdio.h>

/*	print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300	*/
	
main()
{
	int fahr, celsius;
	int lower, upper, step;
	
	lower	= 0;	/*	lower limit of temperature table	*/
	upper	= 300;	/*	upper limit	*/
	step	= 20;	/*	step size	*/
	fahr 	= lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
```
```c
#include <stdio.h>

	/*	print Fahrenheit-Celsius table
		for fahr = 0, 20, ..., 300; floatinq-point version	*/
main()
{
	float	fahr, celsius;
	int	lower, upper, step;

	lower	= 0;	/*	lower limit of temperature table	*/
	upper	= 300;	/*	upper limit	*/
	step	= 20;	/*	step size	*/
	fahr 	= lower;
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
```
### 1.3 The For Statement<br>
```c
#include <stdio.h>

/* print Fahrenheit-Celsius table */

main( )
{
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}
}
```
### 1.4 Symbolic Constants<br>
```c
#include <stdio.h>
#define	LOWER	0	/*	lower limit of temperature table	*/
#define	UPPER	300	/*	upper limit	*/
#define	STEP	20	/*	step size	*/

/* print Fahrenheit-Celsius table */

main ()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}
}
```
### 1.5 Character Input and Output<br>
```c
#include <stdio.h>

/* copy input to output; 1st version */

main( )
{
	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}
```
```c
#include <stdio.h>

/* copy input to output; 2nd version */

main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}
```
```c
#include <stdio.h>

/*	count characters in input; 1st version	*/

main( )
{
	long nc;

	nc = 0;
	while (getchar() != EOF) {
		++nc;
	}
	printf ("%ld\n", nc);
}
```
```c
#include <stdio.h>

/*	count characters in input; 2nd version	*/

main( )
{
	double nc;
	
	for (nc = 0; getchar() != EOF; ++nc) {
		;
	}
	printf("%.Of\n", nc);
}
```
```c
#include <stdio.h>

/*	count lines in input	*/

main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		}
	}
	printf("%d\n", nl);
}
```
```c
#include <stdio.h>
#define IN	1	/*	inside a word	*/
#define OUT	0	/*	outside a word	*/

/*	count lines, words, and characters in input	*/

main()
{
	int c, nl, nw, nc, state;

	state 	= OUT;
	nl 	= nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		if ((c == ' ') || (c == '\n') || (c == '\t')) {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf ("%d %d %d\n", nl, nw, nc);
}
```
### 1.6 Arrays<br>
```c
#include <stdio.h>

/*	count digits, white space, others	*/

main()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i) {
		ndigit[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++ndigit[c - '0'];
		} else if ((c == ' ') || (c == '\n') || (c == '\t')) {
			++nwhite;
		} else {
			++nother;
		}
	}
	printf("digits =");
	for (i = 0; i < 10; ++i) {
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);
}
```
### 1.7 Functions<br>
```c
#include <stdio.h>

int power(int m, int n);

/*	test power function	*/

main ()
{
	int i;
	
	for (i = 0; i < 10; ++i) {
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	}
	
	return;
}
/*
 *	power:
 *	raise base to n-th power; n >= 0
 */
 
int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i) {
		p = p * base;
	}
	
	return p;
}
```
### 1.8 Arguments-Call by Value<br>
```c
/*
 *	power:
 *	raise base to n-th power; n>=O; version 2
 */
 
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n) {
		p = p * base;
	}
	
	return p;
}
```

### 1.9 Character Arrays<br>
```c
#include <stdio.h>
#define MAXLINE 1000	/*	maximum input line size	*/

int 	_getline(char line[], int maxline);
void 	_copy(char to[], char from[]);

/*	print longest input line	*/

main()
{
	int len;		/*	current line length	*/
	int max;		/*	maximum length seen so far	*/
	char line[MAXLINE];	/*	current input line	*/
	char longest[MAXLINE];	/*	longest line saved here	*/

	max = 0;
	while ((len = _getline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			_copy(longest, line);
		}
	}
	if (max > 0) {
		/*	there was a line	*/
		printf("%s\n", longest);
	}
	
	return;
}

/*	_getline: read a line into s, return length	*/

int _getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	
	return i;
}

/*	_copy: copy 'from' into 'to'; assume to is big enough	*/

void _copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
```
### 1.10 External Variables and Scope<br>
```c
#include <stdio.h>
#define MAXLINE 1000		/*	maximum input line size	*/

int 	max;			/*	maximum length seen so far	*/
char 	line[MAXLINE];		/*	current input line	*/
char 	longest[MAXLINE];	/*	longest line saved here	*/

int 	_getline(void);
void 	_copy(void);

/*	print longest input line	*/

main()
{
	int 		len;
	extern int 	max;
	extern char 	longest[];
	
	max = 0;
	while ((len = _getline()) > 0) {
		if (len > max) {
			max = len;
			_copy();
		}
	}
	if (max > 0) {
		/*	there was a line	*/
		printf("%s\n", longest);
	}
	
	return;
}

/*	_getline: read a line into s, return length	*/

int _getline()
{
	int 		c, i;
	extern char 	line[];
	
	/*
	 *	if (i < (MAXLINE - 1)) {
	 *		if ((c = getchar()) != EOF) {
	 *			if (c != '\n') {
	 *				...
	 */
	for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	/*
	 *	MAXLINE	: 4
	 *	INPUT	: H I \n \0
	 *	---------------------
	 *		i = 0 -> store H, c = H
	 *		i = 1 -> store I, c = I
	 *		i = 2 -> store \n, c = \n
	 *		i = 3 -> escape for statement{ i < (MAXLINE - 1) }, c = \n
	 *		if (c == '\n') {
	 *			line[i] = c;
	 *			++i;
	 *		}
	 *		i = 4 -> result: H I \n \n
	 *		line[i] = '\0' // ERROR!!(out of range)
	 */
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	
	return i;
}

/*	_copy: copy 'from' into 'to'; assume to is big enough	*/

void _copy()
{
	int 		i;
	extern char 	line[], longest[];
	
	i = 0;
	while ((longest[i] = line[i]) != '\0') {
		++i;
	}
}
```
```c
/*	_getlineAdvanced: read a line into s, return length	*/

int _getlineAdvanced()
{
	int 		c, i;
	extern char 	line[];
	
	for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if ((i < (MAXLINE - 1)) && (c == '\n')) {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	
	return i;
}

/*	_copy: copy 'from' into 'to'; assume to is big enough	*/
```
