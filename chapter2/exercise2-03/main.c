/*
 *	Write the function htoi(s), which converts a string of hexadecimal digits
 *	(including an optional 0x or 0X) into its equivalent integer value.
 *	The allowable digits are 0 through 9, a through f, and A through F.	
 */

#include <stdio.h>

#define IS_NUMBER(n)        ((n) >= '0' && (n) <= '9')
#define IS_UPPERCASE(n)     ((n) >= 'A' && (n) <= 'F')
#define IS_LOWERCASE(n)     ((n) >= 'a' && (n) <= 'f')
#define IS_HEXADECIMAL(n)   (IS_NUMBER(n) || IS_UPPERCASE(n) || IS_LOWERCASE(n))

unsigned long htoi(char []);

int main(void)
{
    int i, len;

    char *test[] = {
        "Assignment #4",
        "01010110",
        "0123"
        "0x123",
        "0X456",
        "0xab",
        "0Xcd",
        "0xe",
        "0XF",
        "0X0C0BE",
        "abcdef",
        "123456",
        "dabedbefe",
        "xyz"
    };
    len = (int) (sizeof(test) / sizeof(char *));
    for(i = 0; i < len; ++i) {
        printf("%16s %16lu\n", test[i], htoi(test[i]));
    }

    return 0;
}

unsigned long htoi(char str[])
{
    char    c;
    int     i;
    long    result;

    result  = 0;
    i       = (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) ? 2 : 0;
    while (str[i]) {
        c = str[i++];
        if (IS_HEXADECIMAL(c)) {
            result = result * 16 + c - (IS_UPPERCASE(c) ? 'A' - 10 : (IS_LOWERCASE(c) ? 'a' - 10 : '0'));
        } else {
            
            return 0;
        }
    }

    return result;
}
