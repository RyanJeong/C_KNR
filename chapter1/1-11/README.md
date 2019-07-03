```c
/*
 *  How would you test the word count program? 
 *  What kinds of input are most likely to uncover bugs if there are any?
 */

void main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl 	  = nw = nc = 0;
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
	printf ("%d %d "d\n", nl, nw, nc);
  
  return;
}
```
## Result
### Environment: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
```
```
