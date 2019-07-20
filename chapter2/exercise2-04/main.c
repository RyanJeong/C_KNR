/*
 *	Write an alternate version of squeeze(s1,s2) that deletes each character in the string s1 that matches any character in the string s2.	
 */
#include <stdio.h>
#define MAX 100

void squeeze(char *, char *);

int main(void)
{
	int	c, i, limit;
	char	s1[MAX], s2[MAX];

	limit = (MAX - 1);
	puts("Input s1");
	for (i = 0; ((c = getchar()) != EOF); ++i) {
		if (i == limit) {
			while (getchar() != '\n') {
				;
			}
			break;
		}
		if (c == '\n') {
			break;
		}
		s1[i] = c;
	}
	s1[i] = '\0';
	for (i = 0; ((c = getchar()) != EOF); ++i) {
		if (i == limit) {
			while (getchar() != '\n') {
				;
			}
			break;
		}
		if (c == '\n') {
			break;
		}
		s2[i] = c;
	}
	s2[i] = '\0';
	printf("s1: %s, 2s: %s\n", s1, s2);
	squeeze(s1, s2);

	return 0;
}

void squeeze(char *s1, char *s2)
{
	return;
}
