```c
/*
 *  Write a program that prints its input one word per line.
 */

void main()
{
  int c;
  
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      c = '\n';
    }
    putchar(c);
  }
  
  return;
}
```
