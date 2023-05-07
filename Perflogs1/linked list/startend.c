#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to append the second list to the first list at the start
struct Node* appendToStart(struct Node* list1, struct Node* list2) {
    if(list1==NULL)
    {
        return list2;
    }
    if(list2==NULL)
    {
        return list1;
    }
    struct Node *ptr=list1;
    
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    //list2->prev=NULL;
    ptr->next=list2;
    list2->prev=ptr;
    return list1;
}

// Function to append the second list to the first list at the end
struct Node *appendtoEnd(struct Node *list1,struct Node *list2)
{
    if(list1==NULL)
    {
        return list2;
    }
    if(list2==NULL)
    {
        return list1;
    }
    struct Node *ptr=list2;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=list1;
    list1->prev=ptr;
    return list2;
}

// Function to display a doubly linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the program
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n1, n2;
    printf("Enter the number of elements in list 1: ");
    scanf("%d", &n1);
    printf("Enter the elements of list 1: \n");
    for (int i = 0; i < n1; i++) {
        int data;
        scanf("%d", &data);
        if (list1 == NULL) {
            list1 = createNode(data);
        } else {
            struct Node* ptr = list1;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            struct Node* newNode = createNode(data);
            newNode->prev = ptr;
            ptr->next = newNode;
        }
    }

    printf("Enter the number of elements in list 2: ");
    scanf("%d", &n2);
    printf("Enter the elements of list 2: \n");
    for (int i = 0; i < n2; i++) {
        int data;
        scanf("%d", &data);
        if (list2 == NULL) {
            list2 = createNode(data);
        } else {
            struct Node* ptr = list2;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            struct Node* newNode = createNode(data);
            newNode->prev = ptr;
            ptr->next = newNode;
        }
    }

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    int choice;
    printf("Enter choice: 1- appendToStart 2-appendtoend \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        struct Node *newList1=appendToStart(list1,list2);
        printf("List 1 after appending at start of list 2: ");
        displayList(newList1);
        break;
        case 2:
        struct Node *newList2=appendtoEnd(list1,list2);
        printf("List 1 after appending at end of list 2: ");
        displayList(newList2);
        break;
        default:
        printf("invalid choice \n");
        break;
    }
return 0;
}


