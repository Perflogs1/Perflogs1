#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head,*tail;
int dequeue()
{
    int data=head->data;
    (head->prev)->next=NULL;
    head=head->prev;
    return data;
}
void enqueue(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL && tail==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        newnode->next=tail;
        tail->prev=newnode;
        tail=newnode;
    }
}

int main()
{
    int n,data;
    printf("Enter the no of elements you want to enter: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        enqueue(data);
    }
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
    int n1;
    printf("enter the no of elements you want to dequeue: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        int x=dequeue();
        printf("dequeued elements= %d \n",x);
    }
    temp=head;
    printf("dequeued list \n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
    return 0;
}
