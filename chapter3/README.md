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

## 소스코드
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
```
### 3.7 Break and Continue<br>
```c
```
### 3.8 Goto and Labels<br>
```c
```
