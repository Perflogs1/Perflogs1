#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
  char name[100];
  int marks;
  int roll;
} Student;

int compare(const void *a, const void *b) {
  Student *s1 = (Student *) a;
  Student *s2 = (Student *) b;

  if (s1->marks != s2->marks) {
    return s2->marks - s1->marks;
  }

  return strcmp(s1->name, s2->name);
}

void assignRollNumbers(Student students[], int n) {
  qsort(students, n, sizeof(Student), compare);

  for (int i = 0; i < n; i++) {
    students[i].roll = i + 1;
  }
}

void display(Student students[], int n) {
  printf("Roll No.\tName\t\tMarks\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t\t%s\t\t%d\n", students[i].roll, students[i].name, students[i].marks);
  }
}

int main() {
  printf("Enter the number of students: ");
  int n;
  scanf("%d", &n);

  Student students[n];

  for (int i = 0; i < n; i++) {
    printf("Enter the name of student %d: ", i + 1);
    scanf("%s", students[i].name);
    printf("Enter the marks of student %d: ", i + 1);
    scanf("%d", &students[i].marks);
  }

  assignRollNumbers(students, n);

  display(students, n);

  return 0;
}
