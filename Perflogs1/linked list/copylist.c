#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void append(struct node **head_ref,int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *current=*head_ref;
    newnode->data=data;
    newnode->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=newnode;
        return;
    }
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;
    return;
}

struct node *CopyList(struct node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=head->data;
    newnode->next=NULL;
    struct node *tail=newnode;
    struct node *temp=head->next;
    while(temp!=NULL)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->data=temp->data;
        new->next=NULL;
        tail->next=new;
        tail=new;
        temp=temp->next;
    }
    return newnode;
}

void printlist(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    struct node *ptr=NULL;
    printf("Enter the no of elements you want to enter in the linked list \n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int d;
        printf("Enter data: ");
        scanf("%d",&d);
        append(&ptr,d);
    }
    struct node *copy=CopyList(ptr);
    printf("Original list \n");
    printlist(ptr);
    printf("\n");
    printf("Copied list \n");
    printlist(copy);
    return 0;
}
