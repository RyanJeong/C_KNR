/*
 *  Write a program to print the corresponding Celsius to Fahrenheit table.
 */
 
#include <stdio.h>
	
void main()
{
  int fahr, celsius;
  int lower, upper, step;

  lower	= 0;	/*	lower limit of temperature table	*/
  upper	= 300;	/*	upper limit	*/
  step	= 20;	/*	step size	*/
  fahr	= lower;
  while (fahr <= upper) {
    celsius = 9 * (fahr + 32) / 5;
    printf("%d\t%d\n", fahr, celsius);
    fahr += step;
  }
  
  return;
}
