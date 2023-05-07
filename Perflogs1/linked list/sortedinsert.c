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
    struct node *temp=*head_ref;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    
}
struct node *SortedInsert(struct node *head,struct node *newnode)
{
    if(head==NULL ||head->data>=newnode->data)
    {
        newnode->next=head;
        return newnode;
    }
    struct node *current=head;
    while(current->next!=NULL && current->next->data<newnode->data)
    {
        current=current->next;
    }
    newnode->next=current->next;
    current->next=newnode;
    return head;
}
void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main()
{
    int n;
    struct node *head=NULL;
    printf("Enter the no of elements in the linked list \n");
    //int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        append(&head,data);
    }
    printf("Original list \n");
    display(head);
    int n1;
    printf("Enter the element you want to insert: ");
    scanf("%d",&n1);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n1;
    newnode->next=NULL;
    head=SortedInsert(head,newnode);
    printf("Changed list after inserting new element \n");
    display(head);
    return 0;
}
