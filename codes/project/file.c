#include <stdio.h>
#include "student.h" /* Struct *, ... */
#include "file.h"    /* FILENAME */
#include "util.h"    /* offset, strDup(), ... */

extern char *prog;

void load(void)
{
  FILE    *fp;  
  Student *ptr;
  char    *buf;
  int     num, namelen, offset, size;

  fp = fopen(FILENAME, "r");
  /*   Trying to read a file that does not exist 
     is an error, and there may be other causes 
     of error as well, like trying to read a file 
     when you don’t have permission. */
  if (fp != NULL) {
    fscanf(fp, "%d %d", &num, &namelen);
    setNum(num);
    setNamelen(namelen);
    offset = getOffset();
    size   = (num / offset) + 1;
    ptr    = (Student *) calloc(size, sizeof(Student));
    buf    = (char *) malloc(namelen + 1); /* + '\0' */
    if (!ptr || !buf) {
      fprintf(stderr, "%s load(): Memory allocation failed.\n", prog);
      exit(1);
    } else {
      while (!feof(fp)) {
        fscanf("%s %s %d %c", ptr->id, buf, ptr->score, ptr->grade);
        ptr->name = strDup(buf);
        if (!ptr->name) {

        }
      }
    }

  }

  return;
}

void save(void)
{

  return;
}