#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>

/* enum F_'FUNCTION_REAL_NAME' + _NAME */
#define F_A_NAME "a()"
#define F_B_NAME "b()"

#define MSG "Test"
#define PRINT(prog, name, content) \
  printf("%s, " name##_NAME ": " #content "\n", prog)

extern char *prog;

#endif