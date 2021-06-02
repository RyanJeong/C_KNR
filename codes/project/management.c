/* skipWhite + fgets + *pos -> getLine 대체 */

#include <stdio.h>
#include <stdlib.h> /* free() */
#include <string.h> /* strcpy() */
#include "management.h"
#include "util.h" /* skipWhite(), cmp() */
#include "student.h" /* Student type, MAXNAME */

void run(char *arg)
{
  int c;

  setOffset(atoi(arg) > 0 ? atoi(arg) : DEFAULT_OFFSET);
  do {
    menu();
    skipWhite(stdin);
    /* scanf->정수 아닌 값 입력되면 버퍼 안에 있는 문자를 소비하지 못해 무한루프 */
    scanf("%d", &c);
    switch (c) {
    case ADD:
      break;
    case DISPLAY:
      break;
    case SEARCH:
      break;
    case MODIFY:
      break;
    case DELETE:
      break;
    case DELETE_ALL:
      break;
    default:
      /* help */
      break;
    }
  } while (c != QUIT);

  return;
}

char calcGrade(int i)
{
  char grade;

  if (i > 90 && i <= 100) {
    grade = 'A';
  } else if (i > 80 && i <= 90) {
    grade = 'B';
  } else if (i > 70 && i <= 80) {
    grade = 'C';
  } else if (i > 60 && i <= 70) {
    grade = 'D';
  } else if (i > 50 && i <= 60) {
    grade = 'E';
  } else {
    grade = 'F';
  }

  return grade;
}

void menu(void)
{
  printf("*** Student Score Management System ***\n"
          "\t------------------------\n"
          "\t[1] Add Student Record\n"
          "\t[2] Display Student List\n"
          "\t[3] Search Student Record (by ID)\n"
          "\t[4] Modify Student Record (by ID)\n"
          "\t[5] Delete Student Record (by ID)\n"
          "\t[6] Delete All Students\n"
          "\t[0] Save and quit\n"
          "\t------------------------\n"
          "Enter your choice:");

  return;
}

void add(void)
{
/* 크기 비교, 크기 부족하면 새로 할당, 입력, 종료 */
/* bsearch 사용해 id가 이미 등록되어있는지 확인할 것 */
/* 등록과 동시에 정렬을 매번 해야, id를 사용한 검색이나 삭제에 바로 사용할 수 있다.*/
/* 아이디 이름 점수만 등록 가능 */
/* 아이디는 8글자 문자열 */
/* 점수는 0 ~ 100점 사이 */
/* 점수 입력되면 등급은 알아서 계산할 수 있는 함수 만들 것 */
  return;
}

void display(void)
{
/* 전체 출력하되, 이름의 폭은 namelen에서 가져옴 */
  return;
}

void search(void)
{
/* id 기준으로 탐색, id가 들어있는 곳의 주소 가져와 출력 */
  return;
}

void modify(void)
{
/* 이름 또는 점수만 수정 가능하며, 점수 수정 시 grade도 연동해서 바꾸어야 함 */
  /* 
     성적 입력 -> 성적 새로 반영해 최신화
     그대로 두고자 한다 -> -1 입력 */
  char    temp[MAXWORD], *pos;
  int     score, namelen;
  Student *ptr;

  if (!getNum()) {
    puts("There are no records to modify.");
  } else {
    printf("Please enter the student ID to be modified: ");
    skipWhite(stdin);
    fgets(temp, MAXWORD, stdin);
    if ((pos = strrchr(temp, '\n'))) {
      *pos = '\0';
    }
    ptr = (Student *) bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp);
    if (!ptr) {
      puts("There are no records for this ID.");
    } else {
      printf("Please enter a new name. (If you don't want to change it, enter =): ");
      skipWhite(stdin);
      fgets(temp, MAXWORD, stdin);
      if ((pos = strrchr(temp, '\n'))) {
        *pos = '\0';
      }
      if (*temp != '=') {
        free(ptr->name);
        ptr->name = strDup(temp);
        if (!ptr->name) {
          fprintf(stderr, "modify(): %s\n", ERR_ALLOC);

          exit(1);
        }
        namelen = strlen(ptr->name);
        if (namelen > getNamelen()) {
          setNamelen(namelen);
        }
      } 
      do {
        printf("Please enter a new score. (If you don't want to change it, enter =): ");
        skipWhite(stdin);
        fgets(temp, MAXWORD, stdin);
        if ((pos = strrchr(temp, '\n'))) {
          *pos = '\0';
        }
        if (*temp == '=') {
          break;
        } else {
          score = atoi(temp);

        }
      } while (1);


/* 1. 문자열 길이가 1이면서 첫 문자가 '='인 경우는 그대로, */
/* 이름 저장할 배열 크기를 하나 상수로 지정하고(예: 100), 상수 크기의 문자 배열 하나 생성*/
/* 문자 배열에 일단 기록하고, 문자열의 길이만큼 strDup 함수 사용해 새로 할당한 곳의 주소를 기록 */
    }
  }

  return;
}

void delete(void)
{
  char    temp[MAXWORD], *pos;
  Student *ptr, *high;

  if (!getNum()) {
    puts("There are no records to delete.");
  } else {
    printf("Please enter the student ID to be deleted: ");
    skipWhite(stdin);
    fgets(temp, MAXWORD, stdin);
    if ((pos = strrchr(temp, '\n'))) {
      *pos = '\0';
    }
    ptr = (Student *) bsearch(temp, getStudentPtr(), getNum(), sizeof(Student), cmp);
    if (!ptr) {
      puts("There are no records for this ID.");
    } else {
      free(ptr++->name);
      high = getStudentPtr() + getNum();
      while (ptr != high) {
        strcpy((ptr - 1)->id, ptr->id);
        (ptr - 1)->name  = ptr->name;
        (ptr - 1)->score = ptr->score;
        (ptr - 1)->grade = ptr->grade;
      }
      setNum(getNum() - 1);
      puts("The record has been deleted successfully.");
    }
  }

  return;
}

/* Please enter the student ID to be deleted: */
void deleteAll(void)
{
  char    temp[MAXWORD];
  size_t  i;
  Student *ptr;

  if (!getNum()) {
    puts("There are no records to delete.");
  } else {
    printf("Are you sure you want to delete all records? (y / n): ");
    skipWhite(stdin);
    fgets(temp, MAXWORD, stdin);
    if (*temp == 'y') {
      ptr = getStudentPtr();
      for (i = getNum(); --i; ++ptr) {
        free(ptr->name);
      }
      setNum(0);
      puts("All records have been deleted successfully.");
    } else {
      puts("The command has been canceled.");
    }
  }

  return;
}