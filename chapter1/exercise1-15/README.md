```c
/*
 *  Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
 */

#include <stdio.h>

enum {
    LOWER   = 0,
    UPPER   = 300,
    STEP    = 20
};

void fahrToCel(void);
void celToFahr(void);

int main(void)
{
    fahrToCel();
    celToFahr();
  
    return 0;
}

void fahrToCel()
{
    float fahr;

    printf("%s\n", "Fahrenheit to Celsius Conversion");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0)*(fahr - 32.0));
    }
}

void celToFahr()
{
    float celsius;
  
    printf("%s\n", "Celsius to Fahrenheit Conversion");
    for (celsius = LOWER; celsius <= UPPER; celsius += STEP) {
        printf("%3.0f %6.1f\n", celsius, (9.0 / 5.0 * celsius)+32);
    }
}
```
