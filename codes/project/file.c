#include <stdio.h>  /* size_t, ... */
#include <stdlib.h> /* exit(), malloc(), calloe(), ... */

#include "file.h"    
#include "student.h" /* Student type, ... */
#include "util.h"    /* offset, strDup(), ... */

void load(void)
{
  FILE    *fp;  
  Student *ptr;
  char    *buf;
  int     namelen, offset;
  size_t  num, size;
  
  /*   Trying to read a file that does not exist 
     is an error, and there may be other causes 
     of error as well, like trying to read a file 
     when you don’t have permission. */
  if ((fp = fopen(FILENAME, "r")) == NULL) {
    puts("load(): " WAR_FOPEN);
  } else {
    fscanf(fp, "%lu %d", &num, &namelen);
    if (ferror(fp)) {
      fprintf(stderr, "load(): %s\n", ERR_READ);

      exit(1);
    }
    offset = getOffset();
    size   = (num / offset) + 1;
    ptr    = (Student *) calloc(size, sizeof(Student));
    buf    = (char *) malloc(namelen + 1); /* + '\0' */
    if (!ptr || !buf) {
      fprintf(stderr, "load(): %s\n", ERR_ALLOC);

      exit(1);
    } 
    setNum(num);
    setNamelen(namelen);
    setStudentPtr(ptr);
    setSize(size);
    while (fscanf(fp, "%s %s %d %c", ptr->id, buf, &ptr->score, &ptr->grade) != EOF) {
      ptr->name = strDup(buf);
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

  return;
}

void save(void)
{
  FILE    *fp;  
  Student *ptr;
  int     i;

  if ((fp = fopen(FILENAME, "w")) == NULL) {
    fprintf(stderr, "save(): %s\n", ERR_FOPEN);

    exit(1);
  }
  ptr = getStudentPtr();
  fprintf(fp, "%lu %d\n", getNum(), getNamelen());
  if (ferror(fp)) {
    fprintf(stderr, "save(): %s\n", ERR_WRITE);

    exit(1);
  }
  for (i = getNum(); --i; ++ptr) {
    if (fprintf(fp, "%s %s %d %c\n", ptr->id, ptr->name, ptr->score, ptr->grade) == EOF) {
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

  return;
}