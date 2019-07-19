# 제2장 Types, Operators, and Expressions

## 요약
* 입력 버퍼 지우는 요령<br>
```c
while (getchar != '\n') {
	;
}
```
* fflush(stdout)은 출력 버퍼를 지우기 위한 목적으로만 사용
* 정수형<br>
	* signed 또는 unsigned로 나누어 사용할 수 있음<br>
	* shift 연산 가능(twice as wide)<br>
	* modulo operation<br>
* 실수형<br>
	* cannot be signed or unsigned<br>
	* the main issue is not in their range<br>
	* modulo operation is not naturally applicable to non-integer types<br>
* 계산 순서에 의존하여 프로그래밍 하는 습관은 좋지 못한 습관임(괄호를 사용하자)<br>
* 부호형을 우측으로 이동할 경우, 기종에 따라 0으로 채우기도(logical shift), 1로 채우기도 함(arithmetic shift)
* &: MASK, |: SET<br>
* 정수형 상수<br>

|자료형|표현|
|------|---|
|int|1234|
|unsigned int|1234u or 1234U|
|long|1234l or 1234L|
|unsigned long|1234ul or 1234UL|<br>
	8진수 또는 16진수에도 L이나 U와 같은 접미사를 사용할 수 있음 ex) 0xFUL(10진수 15의 무부호 배정도상수)
	
* 실수형 상수<br>

|자료형|표현|
|------|---|
|float|1.234f or 1.234F|
|double|1.234|
|long double|1.234l or 1.234L|<br>
* bit pattern(with escape sequence)<br>
	*	\000	: 한 개에서 세 개까지의 8진수 입력 가능<br>
	*	\xhh	: 한 개에서 두 개까지의 16진수 입력 가능<br>
* 문자상수 '\0'은 값이 0이고, NULL 문자를 나타내는데, 0을 사용하는 대신에 '\0'을 사용하는 이유는 이 표현이 문자로 사용된다는 것을 더 잘 표현하기 때문<br>
* "hello" "world" => "Helloworld"(문자열 상수 연결 가능하며, 긴 문자열을 여러 라인에 걸쳐 사용할 때 유용함)<br>
* 'x': 문자를 나타내는 정수, "x": 'x''\0'으로 구분되는 문자열<br>
* 외부(external) 변수와 정적(static) 변수는 따로 값을 지정하지 않으면 0으로 초기화됨<br>
* % 연산자는 실수형 변수엔 적용될 수 없으며, 음수에 적용 시 결과는 기종에 따라 좌우됨<br>
* 여러 항의 논리연산자가 열거된 조건문일 경우, 이미 참 또는 거짓이 명확한 조건이라면(즉 왼쪽에서 오른쪽으로 조건 검사를 수행하다가 결과가 명확하여 나머지 항들을 검사하지 않아도 되는 경우라면) 검사를 마치고, 그 이후의 항들은 검사하지 않음<br>
* 형 변환 법칙(전제조건: 무부호형 operand가 없어야 함, 있다면 예외 발생할 수 있음)<br>
	* If either operand is long double, convert the other to long double.<br>
	* Otherwise, if either operand is double, convert the other to double.<br>
	* Otherwise, if either operand is float, convert the other to float.<br>
	* Otherwise, convert char and short to int.<br>
	* Then, if either operand is long, convert the other to long.<br>
> For example, suppose that int is 16 bits and long is 32 bits. Then -1L < 1U, because 1U, which is an int, is promoted to a signed long. But -1L > 1UL, because -1L is promoted to unsigned long and thus appears to be a large positive number.<br>
* Since an argument of a function call is an expression, type conversions also take place when arguments are passed to functions. In the absence of a function prototype, char and short become int, and float becomes double. This is why we have declared function arguments to be int and double even when the function is called with char and float.(함수 선언을 꼭 하자!)<br> 
* ~0: 모든 bit가 1이다!<br>
* a[i] = i++;	// 코드가 모호하기 때문에, 코드를 분리하거나 괄호 사용<br>

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
