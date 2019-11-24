# 제5장 Pointers and Arrays

## 요약<br>

## 예제<br>
* [5-01](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-01) : As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input.<br> 

* [5-02](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-02) : Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?<br> 

* [5-03](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-03) : Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s, t) copies the string t to the end of s.<br> 

* [5-04](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-04) : Write the function strend(s, t) , which returns 1 if the string t occurs at the end of the string s, and zero otherwise.<br> 

* [5-05](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-05) : Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s, t, n) copies at most n characters of t to s. Full descriptions are in Appendix B.<br> 

* [5-06](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-06) : Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).<br> 

* [5-07](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-07) : Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage. How much faster is the program?<br> 

* [5-08](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-08) : There is no error-checking in day_of_year or month_day. Remedy this defect.<br> 

* [5-09](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-09) : Rewrite the routines day_of_year and month_day with pointers instead of indexing.<br> 

* [5-10](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-10) : Write the program expr , which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example, expr 2 3 4 + * evaluates 2 x (3 + 4).<br> 

* [5-11](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-11) : Modify the programs entab and detab (written as exercises in Chapter 1) to accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.<br> 

* [5-12](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-12) : Extend entab and detab to accept the shorthand entab -m +n to mean tab stops every n columns, starting at column m . Choose convenient (for the user) default behavior.<br> 

* [5-13](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-13) : Write the program tail, which prints the last n lines of its input. By default, n is 10, say, but it can be changed by an optional argument, so that tail -n prints the last n lines. The program should behave rationally no matter how unreasonable the input or the value of n. Write the program so it makes the best use of available storage; lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size.<br> 

* [5-14](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-14) : Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order. Be sure that -r works with -n.<br> 

* [5-15](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-15) : Add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting; for example, a and A compare equal.<br> 

* [5-16](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-16) : Add the -d ("directory order") option, which makes comparisons only on letters, numbers and blanks. Make sure it works in conjunction with -f.<br> 

* [5-17](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-17) : Add a field-handling capability, so sorting may be done on fields within lines, each field sorted according to an independent set of options. (The index for this book was sorted with -df for the index category and -n for the page numbers.)<br> 

* [5-18](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-18) : Make dcl recover from input errors.<br> 

* [5-19](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-19) : Modify undcl so that it does not add redundant parentheses to declarations.<br> 

* [5-20](https://github.com/RyanJeong/C/tree/master/chapter5/exercise5-20) : Expand dcl to handle declarations with function argument types, qualifiers like const , and so on.<br> 

## 소스코드<br>

