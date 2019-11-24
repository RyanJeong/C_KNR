# 제3장 Control Flow<br>

## 요약
* (Expression + ;) = Statement<br>
* 중괄호는 복합문 또는 블록을 구성하기 위해 사용하며, 중괄호 끝에는 semicolon이 오지 않음<br>
* switch는 else-if의 세련된 표현<br>
* switch의 default는 switch의 case보다 아래에 적는 것이 보통이며, 논리 흐름의 안정성을 위해 default가 맨 마지막에 등장하더라도 break를 사용하는 것이 권장됨<br>
* for vs. while<br>
```c
//	exp1, exp3: assignment or called function
//	exp2: relational expression
//	초기치를 설정하는 경우에는 for statement가 적합

//	for statement
for (exp1; exp2; exp3) {
	...
}

//	while loop
exp1;
while (exp2) {
	exp3;
}
```
* comma(,) 연산은 왼쪽에서 오른쪽으로 순차 계산되며, macro 구조 내에서 가끔 사용됨<br>
* do-while: while문과 혼동을 막기 위해 중괄호{} 사용<br>
* break가 사용되는 구문: switch, for, while, do-while<br>
* continue가 사용되는 구문: for, while, do-while<br>
* goto-label: 다수의 중첩문을 한 번에 빠져나와여 하는 경우에 사용되며, 특별한 경우가 아닌 경우에는 사용하지 않음<br>

## 예제<br>
* [3-01](https://github.com/RyanJeong/C/tree/master/chapter3/exercise3-01) : Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.<br>

* [3-02](https://github.com/RyanJeong/C/tree/master/chapter3/exercise3-02) : Write a function escape(s, t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.<br>

* [3-03](https://github.com/RyanJeong/C/tree/master/chapter3/exercise3-03) : Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.<br>

* [3-04](https://github.com/RyanJeong/C/tree/master/chapter3/exercise3-04) : In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2 to the power (wordsize - 1)). Explain why not. Modify it to print that value correctly regardless of the machine on which it runs.<br>

* [3-05](https://github.com/RyanJeong/C/tree/master/chapter3/exercise3-05) : Write the function itob(n, s, b) that converts the integer n into a base b character representation in the string s .In particular, itob(n, s, 16) formats n as a hexadecimal integer in s.<br>

* [3-06](https://github.com/RyanJeong/C/tree/master/chapter3/exercise3-06) : Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.<br>

## 소스코드<br>
### 3.3 Else-if<br>
```c
/* binsearch: find x in v[O] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
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
```
### 3.4 Switch<br>
```c
#include <stdio.h>

int main()	/*	count digits, white space, others	*/
{
	int c, i, nwhite, nother, ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i) {
		ndigit[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		switch (c) {
		case '0': case '1':
		case '2': case '3': 
		case '4': case '5':
		case '6': case '7':
		case '8': case '9':
			++ndigit[c-'0'];
			break;
		case ' ':
		case '\n':
		case '\t':
			++nwhite;
			break;
		default:
			++nother;
			break;
		}
	}
	printf("digits =");
	for (i = 0; i < 10; ++i) {
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}
```
### 3.5 Loops--While and For<br>
```c
while (((c = getchar()) == ' ') || (c == '\n') || (c == '\t')) {
	;	/*	skip white space characters	*/
}
```
```c
#include <ctype.h>

/*	atoi: convert s to integer; version 2	*/
int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); ++i) {	/*	skip white space	*/
		;
	}
	sign = (s[i] == '-') ? (-1) : 1;
	if ((s[i] == '+') || (s[i] == '-')) {	/*	skip sign	*/
		++i;
	}
	for (n = 0; isdigit(s[i]); ++i) {
		n = (n * 10) + (s[i] - '0');
	}

	return (sign * n);
}
```
```c
/*	shellsort: sort v[0] ... v[n-1] into increasing order	*/
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = (n / 2); gap > 0; gap /= 2) {
		for (i = gap; i <n; ++i) {
			for (j = (i - gap); j >= 0 && v[j] > v[j+gap]; j -= gap) {
				temp		= v[j];
				v[j]		= v[j+gap];
				v[j+gap]	= temp;
			}
		}
	}

	return;
}
```
```c
#include <string.h>

/*	reverse: reverse string s in place	*/
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = (strlen(s) - 1); i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

	return;
}
```
```c
for (i = 0, j = (strlen(s) - 1); i < j; ++i, --j) {
	c = s[i], s[i] = s[j], s[j] = c;
}
```
### 3.6 Loops--Do-while<br>
```c
/*	itoa: convert n to characters in s	*/
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0) {	/*	record sign	*/
		n = (-n);	/*	make n positive	*/
	}
	i = 0;
	do {
		s[i++] = (n % 10) + '0';	/*	get next digit	*/
	} while ((n /= 10) > 0);	/*	delete it	*/
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);

	return;
}
```
### 3.7 Break and Continue<br>
```c
/*	trim: remove trailing blanks, tabs, newlines	*/
int trim(char s[])
{
	int n;

	for (n = (strlen(s) - 1); n >= 0; --n) {
		if ((s[n] != ' ') && (s[n] != '\t') && (s[n] != '\n')) {
			break;
		}
	}
	s[n+1] = '\0';

	return n;
}
```
```c
for (i = 0; i < n; ++i) {
	if (a[i] < 0) {	/*	skip negative elements	*/
		continue;
	}
	...	/*	do positive elements	*/
}
```
### 3.8 Goto and Labels<br>
```c
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (a[i] == b[j]) {
				goto found;
			}	/*	didn't find any common elements	*/
		}
	}
	...
found:
	/*	got one: a[i] == b[j]	*/
	...
```
```c
found = 0;
for (i = 0; (i < n) && !found; ++i) {	//	++i -> found check
	for (j = 0; (j < m) && !found; ++j) {	//	++j -> found check
		if (a[i] == b[j]) {
			found = 1;
		}
	}
}
if (found) {
	...	/*	got one: a[i-1] == b[j-1]	*/
} else {
	...	/*	didn't find any common element	*/
}
```
