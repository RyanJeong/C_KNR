#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include "student.h"

#define DEFAULT_OFFSET 100
#define MAXLINE        100

#define WAR_FOPEN  "Either the file does not exist or you do not have a permission to read the file."

#define ERR_FGETS  "The EOF is encountered or a read error is occurred while attempting to read a character."
#define ERR_FOPEN  "Error in opening the file. You do not have permissions to access the file."
#define ERR_READ   "Error in reading from the file."
#define ERR_WRITE  "Error in writing to the file."
#define ERR_ALLOC  "Memory allocation failed."
#define ERR_FCLOSE "Error in flushing buffers or in outputting data."

void    setOffset(int);
int     getOffset(void);
void    setSize(size_t);
size_t  getSize(void);
int     skipWhite(FILE *);
int     getLine(char *, int);
char    *strDup(char *);
Student *studentDup(Student *obj);
int     cmp(const void *, const void *);

#endif
