#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int emp_id;
    char name;
    char designation;
    int experience;
    int age;
    struct employee *left;
    struct employee *right;
};

struct employee *create_employee(int emp_id, char *name, char *designation, int experience, int age);
struct employee *insert_employee(struct employee *root, struct employee *emp);
struct employee *search_employee(struct employee *root, int emp_id);
void display_employee(struct employee *emp);
void display_ascending(struct employee *root);

int main() {
    int n, i, emp_id, experience, age;
    char name, designation;
    struct employee *root = NULL, *emp;

    printf("Enter the number of employee records: ");
    scanf("%d", &n);

    printf("Enter the details of the employees:\n");
    for (i = 0; i < n; i++) {
        printf("Employee %d:\n", i+1);
        printf("Emp-id: ");
        scanf("%d", &emp_id);
        printf("Name: ");
        scanf("%s", name);
        printf("Designation: ");
        scanf("%s", designation);
        printf("Experience: ");
        scanf("%d", &experience);
        printf("Age: ");
        scanf("%d", &age);
        emp = create_employee(emp_id, name, designation, experience, age);
        root = insert_employee(root, emp);
    }

    printf("Enter the emp-id to search: ");
    scanf("%d", &emp_id);
    emp = search_employee(root, emp_id);
    if (emp != NULL) {
        printf("Employee found:\n");
        display_employee(emp);
    } else {
        printf("Employee not found.\n");
    }

    printf("Employee records in ascending order of emp-id:\n");
    display_ascending(root);

    return 0;
}

struct employee *create_employee(int emp_id, char *name, char *designation, int experience, int age) {
    struct employee *new_emp = (struct employee *) malloc(sizeof(struct employee));
    new_emp->emp_id = emp_id;
    strcpy(new_emp->name, name);
    strcpy(new_emp->designation, designation);
    new_emp->experience = experience;
    new_emp->age = age;
    new_emp->left = NULL;
    new_emp->right = NULL;
    return new_emp;
}

struct employee *insert_employee(struct employee *root, struct employee *emp) {
    if (root == NULL) {
        return emp;
    }
    if (emp->emp_id < root->emp_id) {
        root->left = insert_employee(root->left, emp);
    } else if (emp->emp_id > root->emp_id) {
        root->right = insert_employee(root->right, emp);
    }
    return root;
}

struct employee *search_employee(struct employee *root, int emp_id) {
    if (root == NULL || root->emp_id == emp_id) {
        return root;
    }
    if (emp_id < root->emp_id) {
        return search_employee(root->left, emp_id);
    } else {
        return search_employee(root->right, emp_id);
    }
}

void display_employee(struct employee *emp) {
    printf("Emp-id: %d\n", emp->emp_id);
    printf("Name: %s\n", emp->name);
    printf("Designation: %s\n", emp->designation);
    printf("Experience: %d\n", emp->experience);
    printf("Age: %d\n", emp->age);
}

void display_ascending(struct employee *root) {
    if (root == NULL) {
        return;
    }
    display_ascending(root->left);
    display_employee(root);
    display_ascending(root->right);
}
