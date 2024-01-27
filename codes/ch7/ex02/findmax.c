#include <stdarg.h> /* va_list, va_start, va_arg, va_end */

int findmax(int n, ...)
{
  va_list ap; /* points to each unnamed arg in turn */
  int i, val, largest;

  va_start(ap, n); /* make ap point to 1st unnamed arg */
  largest = va_arg(ap, int);
  for (i = 1; i < n; ++i) {
    val = va_arg(ap, int);
    largest = (val > largest) ? val : largest;
  }
  va_end(ap); /* clean up when done */

  return largest;
}
