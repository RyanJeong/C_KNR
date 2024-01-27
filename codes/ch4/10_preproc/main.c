#include <stdio.h>

#define STUDENT(num) printf("Student #" #num " = %d\n", student##num)

int main(void)
{
  int student1, student2, student3;

  student1 = 100;
  student2 = 200;
  student3 = 300;

  STUDENT(1);
  STUDENT(2);
  STUDENT(3);

  return 0;
}
