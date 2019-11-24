/*
sample input #0
				f-w
output
				s1=f-w
				s2=fghijklmnopqrstuvw

Sample input #1
				2-7
output
				s1=2-7
				s2=234567

Sample input #2
				a-b-c-f
output
				s1=a-b-c-f
				s2=abcdef

Sample input #3
				-a-b-c9-0-3b-s-
output
				s1=-a-b-c9-0-3b-s-
				s2=abc90123bcdefghijklmnopqrstuvwxyz

Sample input #4
				a-0-6b--pq-w9-0-3
output
				s1=a-0-6b--pq-w9-0-3
				s2=abcdefghijklmnopqrstuvwxyz0123456bcdefghijklmnopqrstuvw90123

Sample input #5
				9-0
output				
				9876543210
*/

/*
 *	Write a function expand(s1,s2) that expands shorthand notations
 *	like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
 *	Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 *	Arrange that a leading or trailing - is taken literally.
 */

#include <stdio.h>
#include <string.h>
#define MAX	(1 << 8)
#define ON 	1
#define OFF	0
#define ABS(x)	(((x > 0) - (x < 0)) * x)

int		_getline(char [], int);
void	expand(char *, char *);

int main(void)
{
	char	s1[MAX], s2[MAX];
	
	_getline(s1, MAX);
	expand(s1, s2);
	printf("%s\n%s\n", "Before: ", s1, "After: ", s2);

	return 0;
}

/*	_getline: read a line into s, return length	*/
int _getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	
	return i;
}

void expand(char *s1, char *s2) 
{
	int	state, temp;
	char	c, start, end;

	start	= end	= 0;
	state	= OFF;
	while (c = *s1++) {
		if (c == '-') {
			if (!start) {
				*s2++ = c;
			} else {
				state = ON;
			}
		} else {
			((state) ? end : start) = c;
			if (end && (ABS((start - end))) < 26) {	//	max('Z' - 'A' or 'z' - 'a' or '9' - '0')
				while (start - end) {
					*s2++ = (start < end) ? start++ : start--;
				}
			} else {
				
			}
		}
	}

	return;
}
