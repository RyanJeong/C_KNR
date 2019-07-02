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
### p.13<br>
```c
#include <stdio.h>          //  표준 입출력 라이브러리의 함수를 이용

main()                      //  함수 main을 정의, 매개변수는 없다.
{                           //  main함수 시작
  printf("Hello, world\n"); //  문자출력을 위해 printf 함수를 호출
}                           //  main함수 종료
```
### p.14<br>
### p.18<br>
### p.21<br>
### p.22<br>
### p.24<br>
### p.25<br>
### p.26<br>
### p.27<br>
### p.28<br>
### p.30<br>
### p.32<br>
### p.35<br>
### p.37<br>
### p.38<br>
### p.39<br>
### p.42<br>

## 예제
* [1-1](./1-1)
