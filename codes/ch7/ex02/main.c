#include <stdio.h>   /* printf */
#include <stdarg.h>  /* va_list, va_start, va_arg, va_end */

int findmax(int, ...);
void minprintf(char *fmt, ...);

int main(void)
{
  int max;

  max = findmax(5, 23, 1, 52, -3, 7);
  minprintf("The largest value is %d.\n", max);

  return 0;
}

int findmax(int n, ...)
{
  va_list ap;  /* points to each unnamed arg in turn */
  int i, val, largest;

  va_start(ap, n);  /* make ap point to 1st unnamed arg */
  largest = va_arg(ap, int);
  for (i = 1; i < n; ++i) {
    val = va_arg(ap, int);
    largest = (val > largest) ? val : largest;
  }
  va_end(ap); /* clean up when done */

  return largest;
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
  va_list ap;  /* points to each unnamed arg in turn */
  char *p, *sval;
  int ival;
  double dval;

  /* make ap point to 1st unnamed arg */
  va_start(ap, fmt);
  for (p = fmt; *p; ++p) {
    if (*p != '%') {  /* ordinary characters */
      putchar(*p);
      continue;
    }
    switch (*++p) {  /* conversion specifications */
    case 'd':
      ival = va_arg(ap, int);
      printf("%d", ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%f", dval);
      break;
    case 's':
      for (sval = va_arg(ap, char *); *sval; ++sval)
        putchar(*sval);
      break;
    default:
      putchar(*p);
      break;
    }
  }
  va_end(ap); /* clean up when done */
}
