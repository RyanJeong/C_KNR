```c
/*  
 *  Modify the temperature conversion program 
 *  to print a heading above the table.
 */

#include <stdio.h>

main()
{
  int fahr, celsius;
  int lower, upper, step;

  lower	= 0;	  /*	lower limit of temperature table	*/
  upper	= 300;	/*	upper limit	*/
  step	= 20;	  /*	step size	*/
  fahr = lower;
  printf("print Fahrenheit-Celsius table\n");
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
}
```
