#include <stdio.h>

int main(void)
{
  char s[] = "1 12.3 12.3 12.3 sscanf";
  int i;
  float f;
  double d;
  long double ld;
  char str[10];

  sscanf(s, "%d %f %lf %Lf %s", &i, &f, &d, &ld, str);
  /* 1 12.300000 12.300000 12.300000 sscanf */
  printf("%d %f %f %Lf %s\n", i, f, d, ld, str);

  return 0;
}
