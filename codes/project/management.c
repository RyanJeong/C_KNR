#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* free() */
#include <string.h> /* strcpy() */

#include "file.h"
#include "management.h"
#include "util.h"    /* skipWhite(), cmp() */
#include "student.h" /* Student type, MAXNAME */

static char temp[MAXLINE];
static char *fname[] = {
  "",
  "add()",        /* ADD */
  "display()",    /* DISPLAY */
  "search()",     /* SEARCH */
  "modify()",     /* MODIFY */
  "delete()",     /* DELETE */
  "delete_all()"  /* DELETE_ALL */
};

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
}

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

void title(void)
{
  int width;

  width = SIZE_ID + 1 + getNamelen() + 1 + strlen(LABEL3) + 1 + strlen(LABEL4);
  print(LABEL1, LABEL2, LABEL3, LABEL4);
  while (width--) {
    putchar('-');
  }
  putchar('\n');
}

void student(Student *ptr)
{
  char score[4];
  char grade[2];

  itoa(ptr->score, score);
  *grade   = ptr->grade;
  grade[1] = '\0';
  print(ptr->id, ptr->name, score, grade);
}

void print(char *s1, char *s2, char *s3, char *s4)
{
  printf("%*s|%*s %*s %*s\n", 
         SIZE_ID, s1,
         getNamelen(), s2,
         (int) strlen(LABEL3), s3,
         (int) strlen(LABEL4), s4);
}

int isLine(int caller)
{
  if (getLine(temp, MAXLINE) < 0) {
    fprintf(stderr, "%s: %s\n", fname[caller], ERR_FGETS);
    exit(1);
  }
  if (strlen(temp) == 1 && *temp == 'q') {
    
    return 0;
  }

  return 1;
}

void add(void)
{
  Student *ptr;
  int     score;

  if (getNum() == getSize()) {
    ptr = studentDup(getStudentPtr());
    if (!ptr) {
      fprintf(stderr, "%s: %s\n", fname[ADD], ERR_ALLOC);
      exit(1);
    }
    setStudentPtr(ptr);
    setSize(getNum() + getOffset());
  } else {
    ptr = getStudentPtr();
  }
  ptr += getNum();
  /* ID */
  do {
    printf("Please enter an ID consisting of 8 characters.\n"
           "(If you want to stop, enter q): ");
    if (!isLine(ADD)) {
      return;
    }
    if (strlen(temp) != SIZE_ID) {
      puts("The ID is entered incorrectly.");
    } else if (bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp)) {
      puts("The ID already exists. Please enter a different ID.");
    } else {
      strcpy(ptr->id, temp);
      break;
    }
  } while (1);
  /* name */
  printf("Please enter a name.\n"
         "(enter q if you want to stop): ");
  if (!isLine(ADD)) {
    return;
  }
  ptr->name = strDup(temp);
  if (!ptr->name) {
    fprintf(stderr, "%s: %s\n", fname[ADD], ERR_ALLOC);
    exit(1);
  }
  /* score and grade */
  do {
    printf("Please enter a score of 0-100.\n"
           "(enter q if you want to stop): ");
    if (!isLine(ADD)) {
      free(ptr->name);
      return;
    }
    score = isdigit(*temp) ? atoi(temp) : -1;
    if (score < 0 || score > 100) {
      puts("The score is entered incorrectly.");
    } else {
      ptr->score = score;
      ptr->grade = calcGrade(score);
      break;
    }
  } while (1);
  setNum(getNum() + 1);
  setNamelen(getMaxNamelen());
  puts("A record has been added successfully.");
  title();
  student(ptr);
  qsort(getStudentPtr(), getNum(), sizeof(Student), cmpIds);
}

void display(void)
{
  Student *ptr, *high;

  if (!getNum()) {
    puts("There are no records to modify.");
  } else {
    title();
    ptr = getStudentPtr();
    for (high = ptr + getNum(); ptr < high; ++ptr) {
      student(ptr);
    }
  }
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
    if (!isLine(SEARCH)) {
      return;
    }
    if (strlen(temp) != SIZE_ID) {
      puts("The ID is entered incorrectly.");
    } else {
      ptr = (Student *) bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp);
      break;
    }
  } while (1);
  if (!ptr) {
    puts("There are no records for this ID.");
  } else {
    title();
    student(ptr);
  }
}

void modify(void)
{
  Student *ptr;
  int     score;
  char    *name;

  if (!getNum()) {
    puts("There are no records to modify.");
    return;
  } 
  do {
    printf("Please enter the student ID to be modified. The ID consists of 8 characters.\n"
           "(If you want to stop, enter q): ");
    if (!isLine(MODIFY)) {
      return;
    }
    if (strlen(temp) != SIZE_ID) {
      puts("The ID is entered incorrectly.");
    } else {
      ptr = (Student *) bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp);
      break;
    }
  } while (1);
  if (!ptr) {
    puts("There are no records for this ID.");
    return;
  }
  printf("Please enter a new name.\n"
         "(enter q if you want to stop or = if you don't want to change it): ");
  if (!isLine(MODIFY)) {
    return;
  }
  if (strlen(temp) == 1 && *temp == '=') {
    name = NULL;
  } else {
    name = strDup(temp);
    if (!name) {
      fprintf(stderr, "%s: %s\n", fname[MODIFY], ERR_ALLOC);
      exit(1);
    }
  }
  do {
    printf("Please enter a new score of 0-100.\n"
           "(enter q if you want to stop or = if you don't want to change it): ");
    if (!isLine(MODIFY)) {
      if (name) {
        free(name);
      }
      return;
    }
    if (strlen(temp) == 1 && *temp == '=') {
      score = -1;
      break;
    } else {
      score = isdigit(*temp) ? atoi(temp) : -1;
      if (score < 0 || score > 100) {
        puts("The score is entered incorrectly.");
      } else {
        break;
      }
    }
  } while (1);
  if (name) {
    free(ptr->name);
    ptr->name = name;
  }
  if (score >= 0) {
    ptr->score = score;
    ptr->grade = calcGrade(score);
  }
  setNamelen(getMaxNamelen());
  puts("The record has been modified successfully.");
  title();
  student(ptr);
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
    if (!isLine(DELETE)) {
      return;
    }
    if (strlen(temp) != SIZE_ID) {
      puts("The ID is entered incorrectly.");
    } else {
      ptr = (Student *) bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp);
      break;
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
  setNamelen(getMaxNamelen());
  puts("The record has been deleted successfully.");
}

void deleteAll(void)
{
  Student *ptr, *high;

  if (!getNum()) {
    puts("There are no records to delete.");
    return;
  }
  printf("Are you sure you want to delete all records? (y / n): ");
  if (getLine(temp, MAXLINE) < 0) {
    fprintf(stderr, "%s: %s\n", fname[DELETE_ALL], ERR_FGETS);
    exit(1);
  }
  if (strlen(temp) == 1 && *temp == 'y') {
    ptr = getStudentPtr();
    for (high = ptr + getNum(); ptr < high; ++ptr) {
      free(ptr->name);
    }
    setNum(0);
    setNamelen(strlen(LABEL2));
    puts("All records have been deleted successfully.");
  }
}