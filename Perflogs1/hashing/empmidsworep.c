#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct employee {
    int emp_id;
    char emp_name[20];
    float emp_salary;
} Employee;

int hashFunction(int key) {
    int mid = key * key;
    mid /= 100; // Considering only the middle two digits of the square
    mid %= TABLE_SIZE;
    return mid;
}

void printHashTable(Employee hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", hashTable[i].emp_id, hashTable[i].emp_name, hashTable[i].emp_salary);
    }
}

int main() {
    Employee hashTable[TABLE_SIZE] = {0};
    int num_employees;
    printf("Enter the number of employees: ");
    scanf("%d", &num_employees);
    for (int i = 0; i < num_employees; i++) {
        Employee emp;
        printf("\nEnter details of employee %d:\n", i+1);
        printf("Employee ID: ");
        scanf("%d", &emp.emp_id);
        printf("Employee name: ");
        scanf("%s", emp.emp_name);
        printf("Employee salary: ");
        scanf("%f", &emp.emp_salary);
        int index = hashFunction(emp.emp_id);
        if (hashTable[index].emp_id == 0) {
            hashTable[index] = emp;
        } else {
            int j = index + 1;
            while (hashTable[j % TABLE_SIZE].emp_id != 0) {
                j++;
            }
            hashTable[j % TABLE_SIZE] = emp;
        }
    }
    printf("\nEmployee database:\n");
    printf("ID\tName\tSalary\n");
    printHashTable(hashTable, TABLE_SIZE);
    int search_id;
    printf("\nEnter the employee ID to search: ");
    scanf("%d", &search_id);
    int search_index = hashFunction(search_id);
    int count = 0;
    while (hashTable[search_index].emp_id != search_id) {
        search_index++;
        count++;
        if (count == TABLE_SIZE) {
            printf("Employee not found.\n");
            return 0;
        }
    }
    printf("\nEmployee found at index %d:\n", search_index);
    printf("ID\tName\tSalary\n");
    printf("%d\t%s\t%.2f\n", hashTable[search_index].emp_id, hashTable[search_index].emp_name, hashTable[search_index].emp_salary);
    return 0;
}

