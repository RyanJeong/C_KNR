# 제8장 The UNIX System Interface

## 요약<br>

## 예제<br>
* [8-01](https://github.com/RyanJeong/C/tree/master/chapter8/exercise8-01) : Rewrite the program cat from Chapter 7 using read , write , open and close instead of their standard library equivalents. Perform experiments to determine the relative speeds of the two versions.<br>

* [8-02](https://github.com/RyanJeong/C/tree/master/chapter8/exercise8-02) : Rewrite fopen and \_fillbuf with fields instead of explicit bit operations. Compare code size and execution speed.<br>

* [8-03](https://github.com/RyanJeong/C/tree/master/chapter8/exercise8-03) : Design and write \_flushbuf, fflush and fclose.<br>

* [8-04](https://github.com/RyanJeong/C/tree/master/chapter8/exercise8-04) : The standard library function **int fseek(FILE \*fp, long offset, int origin)** is identical to lseek except that fp is a file pointer instead of a file descriptor and the return value is an int status, not a position. Write fseek. Make sure that your fseek coordinates properly with the buffering done for the other functions of the library.<br>

* [8-05](https://github.com/RyanJeong/C/tree/master/chapter8/exercise8-05) : Modify the fsize program to print the other information contained in the inode entry.<br>

* [8-06](https://github.com/RyanJeong/C/tree/master/chapter8/exercise8-06) : The standard library function calloc(n,size) returns a pointer to n objects of size size, with the storage initialized to zero. Write calloc, by calling malloc or by modifying it.<br>

* [8-07](https://github.com/RyanJeong/C/tree/master/chapter8/exercise8-07) : malloc accepts a size request without checking its plausibility; free believes that the block it is asked to free contains a valid size field. Improve these routines so they take more pains with error checking.<br>

* [8-08](https://github.com/RyanJeong/C/tree/master/chapter8/exercise8-08) : Write a routine bfree(p, n) that will free an arbitrary block p of n characters into the free list maintained by malloc and free. By using bfree, a user can add a static or external array to the free list at any time.<br>

## 소스코드<br>

