#ifndef __FILE_H__
#define __FILE_H__

#define FILENAME "db.dj"

enum {
  OK,
  ERROR,

  /* for macro PRINT_ERROR */
  FUNC_LOAD,
  FUNC_SAVE
}

void load(void);
void save(void);
#endif