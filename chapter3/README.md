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
```
### 3.4 Switch<br>
```c
```
### 3.5 Loops--While and For<br>
```c
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
