x = 0;
++i;
printf(...);

if (expression)
    statement1
else
    statement2


if (expression)
/* if (expression != 0) */

if (n > 0)
    if (a > b)
        z = a;
    else
        z = b;

if (n > 0) {
    if (a > b) 
        z = a;
}
else 
    z = b;

if (n >= 0)
    for (i = 0; i < n; ++i) 
        if (s[i] > 0) {
            printf("......");

            return i;
        }
else /* WRONG */
    printf("error -- n is negative\n");   

if (expression)
    statement
else if (expression)
    statement
else if (expression)
    statement
else if (expression)
    statement
else
    statement

while (expression)
statement

for (expr1 ; expr2 ; expr3)
statement

expr 1 ;
while (expr 2 ) {
statement
expr 3 ;
}

for (;;) {
...
}

while ((c = getchar()) == ' ' || c == '\n' || c = '\t')
    ; /* skip white space characters */

for (i = 0; i < n; i++)
    ...

skip white space, if any
get sign, if any
get integer part and convert it

#define TEST_MALLOC(x) ((x) = malloc(sizeof(*x)), assert(x))

do
    statement
while (expression);

do
    s[i++] = (n % 10) + '0'; /* get next digit */
while ((n /= 10) > 0);       /* delete it      */

for (i = 0; i < n; ++i) {
    if (a[i] < 0) { /* skip negative elements */
        continue;
    }
    ... /* do positive elements */
}

for (...)
    for (...) {
        ...
        if (disaster)
            goto error:
    }
}
...
error:
    clean up the mess


    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                goto found;
            }
        }
    }
    /* didn't find any common elements */
    ...
found:
    /* got one: a[i] == b[j ]*/
    ...

found = 0;
for (i = 0; (i < n) && !found; ++i) {
    for (j = 0; (j < m) && !found; ++j) {
        if (a[i] == b[j]) {
            found = 1;
        }
    }
}
if (found) {
    /* got one: a[i-1] == b[j-1] */
    ...
} else {
    /* didn't find any common element */  
    ...
}

    if (!condition1)
        goto cleanup;
    else if (!condition2)
        goto cleanup;
    else if (!condition3)
        goto cleanup;
    else if (!condition4)
        goto cleanup;
    ...
cleanup:
    clean up the mess


int flag;

flag = 0;
if (condition1)
    flag = 1;
else if (!flag && condition2)
    flag = 1;
else if (!flag && condition3)
    flag = 1;
else if (!flag && condition4)
    flag = 1;
...
if (flag) {
    clean up the mess
} else {
    ...
}

int cleanUp(void)
{
    if (condition1) {

        return 1;
    }
    else if (condition2) {

        return 1;
    }
    else if (condition3) {

        return 1;
    }
    else if (condition4) {

        return 1;
    }
    ...

    return 0;
}

do {
    if (condition1)
        break;
    else if (condition2)
        break;
    else if (condition3)
        break;
    else if (condition4)
        break;
    ...
} while (0);
clean up the mess

