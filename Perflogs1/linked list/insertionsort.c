#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void append(struct node **head_ref,int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=newnode;
        return;
    }
    struct node *current=*head_ref;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;
    
}

void display(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insertionsort(struct node **head)
{
    struct node *sorted_list = NULL;
    struct node *current = *head;

    while (current != NULL) {
        struct node *next_node = current->next;
        struct node *sorted_current = sorted_list;
        struct node *prev = NULL;

        while (sorted_current != NULL && sorted_current->data < current->data) {
            prev = sorted_current;
            sorted_current = sorted_current->next;
        }

        if (prev == NULL) {
            current->next = sorted_list;
            sorted_list = current;
        } else {
            current->next = prev->next;
            prev->next = current;
        }

        current = next_node;
    }

    *head = sorted_list;
}
        
int main()
{
    struct node *head=NULL;
    int n;
    printf("Enter the no of elements in the Linked List \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       int data;
       printf("Enter data: ");
       scanf("%d",&data);
       append(&head,data);
    }
    printf("Original list: ");
    display(head);
    insertionsort(&head);
    printf("Sorted list: ");
    display(head);
    return 0;
}
