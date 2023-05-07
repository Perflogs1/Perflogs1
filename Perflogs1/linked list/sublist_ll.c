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

void display(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    //printf("NULL \n");
}

void splitlist(struct node *list,struct node **left,struct node **right,int n)
{
    if(n<2)
    {
        *left=list;
        *right=NULL;
        return;
    }
    struct node *current=list;
    int traversecount=(n-1)/2;
    for(int i=0;i<traversecount;i++)
    {
        current=current->next;
    }
    *left=list;
    *right=current->next;
    current->next=NULL;
    
}

int main()
{
    struct node *head=NULL;
    
    int n;
    printf("Enter the total no of elements in the linked list: ");
    scanf("%d",&n);
    printf("Enter data: ");
    int data;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        append(&head,data);
    }
    printf("Original list \n");
    display(head);
    printf("\n");
    //struct node *list=NULL;
    struct node *left=NULL;
    struct node *right=NULL;
    splitlist(head,&left,&right,n);
    printf("Left list \n");
    display(left);
    printf("\n");
    printf("Right list \n");
    display(right);
    printf("\n");
    return 0;
}


