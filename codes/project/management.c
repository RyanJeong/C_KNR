#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* free() */
#include <string.h> /* strcpy() */

#include "file.h"
#include "management.h"
#include "util.h"    /* skipWhite(), cmp() */
#include "student.h" /* Student type, MAXNAME */

static char temp[MAXLINE];

void run(char *arg)
{
  int c;

  setOffset(atoi(arg) > 0 ? atoi(arg) : DEFAULT_OFFSET);
  load();
  do {
    menu();
    /* scanf("%d", &c);
    scanf-> not consume characters which not digit characters */
    if (getLine(temp, MAXLINE) < 0) {
      fprintf(stderr, "run(): %s\n", ERR_FGETS);
      exit(1);
    }
    c = isdigit(*temp) ? atoi(temp) : INVALID;
    switch (c) {
    case ADD:
      add();
      break;
    case DISPLAY:
      display();
      break;
    case SEARCH:
      search();
      break;
    case MODIFY:
      modify();
      break;
    case DELETE:
      delete();
      break;
    case DELETE_ALL:
      deleteAll();
      break;
    case QUIT:
      save();
      break;
    default: /* INVALID */
      puts("Invalid input. Try again.");
      /* help */
      break;
    }
  } while (c != QUIT);

  return;
}

char calcGrade(int i)
{
  char grade;

  if (i >= 90 && i <= 100) {
    grade = 'A';
  } else if (i >= 80 && i < 90) {
    grade = 'B';
  } else if (i >= 70 && i < 80) {
    grade = 'C';
  } else if (i >= 60 && i < 70) {
    grade = 'D';
  } else if (i >= 50 && i < 60) {
    grade = 'E';
  } else {
    grade = 'F';
  }

  return grade;
}

void menu(void)
{
  printf("\n*** Student Score Management System ***\n"
         "\t------------------------\n"
         "\t[1] Add Student Record\n"
         "\t[2] Display Student List\n"
         "\t[3] Search Student Record (by ID)\n"
         "\t[4] Modify Student Record (by ID)\n"
         "\t[5] Delete Student Record (by ID)\n"
         "\t[6] Delete All Students\n"
         "\t[0] Save and Quit\n"
         "\t------------------------\n"
         "Enter your choice:");

  return;
}

void format(void)
{
  int width;

  width = SIZE_ID + 1 + getNamelen() + 1 + strlen(LABEL3) + 1 + strlen(LABEL4);
  printf("%*s %*s %*s %*s\n", 
          SIZE_ID, LABEL1,
          getNamelen(), LABEL2,
          (int) strlen(LABEL3), LABEL3,
          (int) strlen(LABEL4), LABEL4);
  while (width--) {
    putchar('-');
  }
  putchar('\n');

  return;
}

void student(Student *ptr)
{
  printf("%s %*s %*d %*c\n", 
         ptr->id, 
         getNamelen(), ptr->name, 
         (int) strlen(LABEL3), ptr->score, 
         (int) strlen(LABEL4), ptr->grade);

  return;
}

void display(void)
{
  Student *ptr, *high;

  if (!getNum()) {
    puts("There are no records to modify.");
  } else {
    format();
    ptr = getStudentPtr();
    for (high = ptr + getNum(); ptr < high; ++ptr) {
      student(ptr);
    }
  }

  return;
}

void add(void)
{
  Student *ptr;
  int     score, namelen;

  if (getNum() == getSize()) {
    ptr = studentDup(getStudentPtr());
    if (!ptr) {
      fprintf(stderr, "add(): %s\n", ERR_ALLOC);
      exit(1);
    }
    setStudentPtr(ptr);
    setSize(getNum() + getOffset());
  } else {
    ptr = getStudentPtr();
  }
  ptr += getNum();
  do {
    printf("Please enter an ID consisting of 8 characters.\n"
           "(If you want to stop, enter q): ");
    if (getLine(temp, MAXLINE) < 0) {
      fprintf(stderr, "modify(): %s\n", ERR_FGETS);
      exit(1);
    }
    if (strlen(temp) == SIZE_ID) {
      if (bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp)) {
        puts("The ID already exists. Please enter a different ID.");
      } else {
        strcpy(ptr->id, temp);
        break;
      }
    } else if (strlen(temp) == 1 && *temp == 'q') {

      return;
    } else {
      puts("The ID is entered incorrectly.");
    }
  } while (1);
  do {
    printf("Please enter a name.\n"
           "(enter q if you want to stop): ");
    if (getLine(temp, MAXLINE) < 0) {
      fprintf(stderr, "modify(): %s\n", ERR_FGETS);
      exit(1);
    }
    if (strlen(temp) == 1 && *temp == 'q') {

      return;
    }
    ptr->name = strDup(temp);
    namelen   = strlen(ptr->name);
    if (namelen > getNamelen()) {
      setNamelen(namelen);
    }
  } while (0);
  do {
    printf("Please enter a score of 0-100.\n"
           "(enter q if you want to stop): ");
    if (getLine(temp, MAXLINE) < 0) {
      fprintf(stderr, "modify(): %s\n", ERR_FGETS);
      exit(1);
    }
    if (strlen(temp) == 1 && *temp == 'q') {

      return;
    } else {
      score = isdigit(*temp) ? atoi(temp) : -1;
      if (score >= 0 && score <= 100) {
        ptr->score = score;
        ptr->grade = calcGrade(score);
        break;
      } else {
        puts("The score is entered incorrectly.");
      }
    }
  } while (1);
  setNum(getNum() + 1);
  puts("A record has been added successfully.");
  format();
  student(ptr);
  qsort(getStudentPtr(), getNum(), sizeof(Student), cmpIds);

  return;
}

void search(void)
{
  Student *ptr;

  if (!getNum()) {
    puts("There are no records to search.");

    return;
  }
  do {
    printf("Please enter the student ID to be searched. The ID consists of 8 characters.\n"
           "(If you want to stop, enter q): ");
    if (getLine(temp, MAXLINE) < 0) {
      fprintf(stderr, "search(): %s\n", ERR_FGETS);
      exit(1);
    }
    if (strlen(temp) == SIZE_ID) {
      ptr = (Student *) bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp);
      break;
    } else if (strlen(temp) == 1 && *temp == 'q') {

      return;
    } else {
      puts("The ID is entered incorrectly.");
    }
  } while (1);
  if (!ptr) {
    puts("There are no records for this ID.");
  } else {
    format();
    student(ptr);
  }

  return;
}

void modify(void)
{
  /* TODO! */
  Student *ptr;
  int     score, namelen;
  char    *name;

  score = -1;
  name  = NULL;
  if (!getNum()) {
    puts("There are no records to modify.");

    return;
  } 
  do {
    printf("Please enter the student ID to be modified. The ID consists of 8 characters.\n"
           "(If you want to stop, enter q): ");
    if (getLine(temp, MAXLINE) < 0) {
      fprintf(stderr, "modify(): %s\n", ERR_FGETS);
      exit(1);
    }
    if (strlen(temp) == SIZE_ID) {
      ptr = (Student *) bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp);
      break;
    } else if (strlen(temp) == 1 && *temp == 'q') {

      return;
    } else {
      puts("The ID is entered incorrectly.");
    }
  } while (1);
  if (!ptr) {
    puts("There are no records for this ID.");

    return;
  }
  do {
    printf("Please enter a new name.\n"
            "(enter q if you want to stop or = if you don't want to change it): ");
    if (getLine(temp, MAXLINE) < 0) {
      fprintf(stderr, "modify(): %s\n", ERR_FGETS);
      exit(1);
    }
    if (strlen(temp) == 1 && *temp == 'q') {
      
      return;
    } else if (strlen(temp) == 1 && *temp == '=') {
      break;
    } else {
      name = strDup(temp);
      if (!name) {
        fprintf(stderr, "modify(): %s\n", ERR_ALLOC);
        exit(1);
      }
    } 
  } while (0);
  do {
    printf("Please enter a new score of 0-100.\n"
            "(enter q if you want to stop or = if you don't want to change it): ");
    if (getLine(temp, MAXLINE) < 0) {
      fprintf(stderr, "modify(): %s\n", ERR_FGETS);
      exit(1);
    }
    if (strlen(temp) == 1 && *temp == 'q') {
      
      return;
    } else if (strlen(temp) == 1 && *temp == '=') {
      break;
    } else {
      score = isdigit(*temp) ? atoi(temp) : -1;
      if (score >= 0 && score <= 100) {
        free(ptr->name);
        ptr->name = name;
        namelen   = strlen(ptr->name);
        if (namelen > getNamelen()) {
          setNamelen(namelen);
        }
        ptr->score = score;
        ptr->grade = calcGrade(score);
        break;
      } else {
        puts("The score is entered incorrectly.");
      }
    }
  } while (1);
  puts("The record has been modified successfully.");
  format();
  student(ptr);

  return;
}

void delete(void)
{
  Student *ptr, *high, *prev;

  if (!getNum()) {
    puts("There are no records to delete.");

    return;
  }
  do {
    printf("Please enter the student ID to be deleted. The ID consists of 8 characters.\n"
           "(If you want to stop, enter q): ");
    if (getLine(temp, MAXLINE) < 0) {
      fprintf(stderr, "delete(): %s\n", ERR_FGETS);
      exit(1);
    }
    if (strlen(temp) == SIZE_ID) {
      ptr = (Student *) bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp);
      break;
    } else if (strlen(temp) == 1 && *temp == 'q') {

      return;
    } else {
      puts("The ID is entered incorrectly.");
    }
  } while (1);
  if (!ptr) {
    puts("There are no records for this ID.");

    return;
  }
  free(ptr++->name);
  for (high = getStudentPtr() + getNum(); ptr < high; ++ptr) {
    prev = ptr - 1;
    strcpy(prev->id, ptr->id);
    prev->name  = ptr->name;
    prev->score = ptr->score;
    prev->grade = ptr->grade;
  }
  setNum(getNum() - 1);
  puts("The record has been deleted successfully.");

  return;
}

/* Please enter the student ID to be deleted: */
void deleteAll(void)
{
  Student *ptr, *high;

  if (!getNum()) {
    puts("There are no records to delete.");

    return;
  }
  printf("Are you sure you want to delete all records? (y / n): ");
  if (getLine(temp, MAXLINE) < 0) {
    fprintf(stderr, "deleteAll(): %s\n", ERR_FGETS);
    exit(1);
  }
  if (*temp == 'y') {
    ptr = getStudentPtr();
    for (high = ptr + getNum(); ptr < high; ++ptr) {
      free(ptr->name);
    }
    setNum(0);
    puts("All records have been deleted successfully.");
  }

  return;
}