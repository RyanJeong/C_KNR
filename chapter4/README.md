# 제4장 Functions and Program Structure

## 요약<br>

## 예제<br>
* [4-01](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-01) : Write the function strrindex(s, t), which returns the position of the rightmost occurrence of t in s, or -1 if there is none.<br>

* [4-02](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-02) : Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.<br>

* [4-03](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-03) : Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.<br>

* [4-04](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-04) : Add commands to print the top element of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.<br>

* [4-05](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-05) : Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.<br>

* [4-06](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-06) : Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.) Add a variable for the most recently printed value.<br>

* [4-07](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-07) : Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch?<br>

* [4-08](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-08) : Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.<br>

* [4-09](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-09) : Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.<br>

* [4-10](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-10) : An alternate organization uses getline to read an entire input line; this makes getch and ungetch unnecessary. Revise the calculator to use this approach.<br>

* [4-11](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-11) : Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.<br>

* [4-12](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-12) : Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.<br>

* [4-13](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-13) : Write a recursive version of the function reverse(s), which reverses the string s in place.<br>

* [4-14](https://github.com/RyanJeong/C/tree/master/chapter4/exercise4-14) : Define a macro swap(t, x, y) that interchanges two arguments of type t. (Block structure will help.)<br>

## 소스코드<br>
