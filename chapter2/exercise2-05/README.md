```c
#include <stdio.h>
#define MAX 100

void any(char *, char *);

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
	puts("Input s2");
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
	printf("s1: %s, s2: %s\n", s1, s2);
	any(s1, s2);

	return 0;
}

void any(char *s1, char *s2)
{
	int	c, i;
	char	*p_s1;

	while ((c = *s2++)) {
		p_s1 = s1;
		for (p_s1 = s1; *p_s1; ++p_s1) {
			if (*p_s1 == c) {
				break;
			}
		}
		i = (!*p_s1) ? (-1) : (p_s1 - s1);
		printf("%c\'s location: %d\n", c, i);
	}

	return;
}
```
