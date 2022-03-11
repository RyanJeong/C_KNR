#include <stdio.h>  /* size_t, ... */
#include <stdlib.h> /* exit(), malloc(), calloe(), ... */
#include <string.h> /* strlen */

#include "file.h"    
#include "student.h" /* Student type, ... */
#include "util.h"    /* offset, strDup(), ... */

void save(void)
{
  FILE    *fp;  
  Student *ptr, *high;

  if ((fp = fopen(FILENAME, "w")) == NULL) {
    fprintf(stderr, "save(): %s\n", ERR_FOPEN);
    exit(1);
  }
  fprintf(fp, "%lu %d\n", getNum(), getNamelen());
  if (ferror(fp)) {
    fprintf(stderr, "save(): %s\n", ERR_WRITE);
    exit(1);
  }
  ptr = getStudentPtr();
  for (high = ptr + getNum(); ptr < high; ++ptr) {
    if (fprintf(fp, "%s %d %c/%s\n", ptr->id, ptr->score, ptr->grade, ptr->name) == EOF) {
      break;
    }
    free(ptr->name);
  }
  if (ferror(fp)) {
    fprintf(stderr, "save(): %s\n", ERR_WRITE);
    exit(1);
  }
  free(getStudentPtr());
  /* if occurred error on the stream */
  if (fclose(fp)) {
    fprintf(stderr, "save(): %s\n", ERR_FCLOSE);
    exit(1);
  };
  puts("save(): The file has been saved successfully.");
}

void load(void)
{
  FILE    *fp;  
  Student *ptr;
  char    temp[MAXLINE];
  int     namelen, offset;
  size_t  num, size;
  
  /*   Trying to read a file that does not exist 
     is an error, and there may be other causes 
     of error as well, like trying to read a file 
     when you don’t have permission. */
  if ((fp = fopen(FILENAME, "r")) == NULL) {
    puts("load(): " WAR_FOPEN);
    setNamelen(strlen(LABEL2));
  } else {
    fscanf(fp, "%lu %d", &num, &namelen);
    if (ferror(fp)) {
      fprintf(stderr, "load(): %s\n", ERR_READ);
      exit(1);
    }
    offset = getOffset();
    size   = (num / offset + 1) * offset;
    ptr    = (Student *) calloc(size, sizeof(Student));
    if (!ptr) {
      fprintf(stderr, "load(): %s\n", ERR_ALLOC);
      exit(1);
    } 
    setNum(num);
    setNamelen(namelen);
    setStudentPtr(ptr);
    setSize(size);
    while (fscanf(fp, "%s %d %c/", ptr->id, &ptr->score, &ptr->grade) != EOF) {
      if (fgets(temp, MAXLINE, fp) == NULL) {
        fprintf(stderr, "load(): %s\n", ERR_FGETS);
        exit(1);
      }
      /* erase '\n' from the line */
      temp[strlen(temp)-1] = '\0';
      ptr->name = strDup(temp);
      if (!ptr->name) {
        fprintf(stderr, "load(): %s\n", ERR_ALLOC);
        exit(1);
      }
      ++ptr;
    }
    if (ferror(fp)) {
      fprintf(stderr, "load(): %s\n", ERR_READ);
      exit(1);
    }
    /* if occurred error on the stream */
    if (fclose(fp)) {
      fprintf(stderr, "load(): %s\n", ERR_FCLOSE);
      exit(1);
    };
    puts("load(): The file has been loaded successfully.");
  }
}