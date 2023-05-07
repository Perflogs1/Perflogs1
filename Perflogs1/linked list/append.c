#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

struct node *Append(struct node *a,struct node *b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    struct node *ptr=a;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=b;
    b->prev=ptr;
    b=NULL;
    return a;
}

void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    struct node *list1=NULL;
    struct node *list2=NULL;
    int n1,n2;
    printf("Enter the no of elements for list1: ");
    scanf("%d",&n1);
    printf("Enter elements: \n");
    for(int i=0;i<n1;i++)
    {
        int data;
        scanf("%d",&data);
        if(list1==NULL)
        {
            list1=createnode(data);
        }
        else
        {
            struct node *ptr=list1;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            struct node *newnode=createnode(data);
            newnode->prev=ptr;
            ptr->next=newnode;
        }
    }
    
    printf("Enter the no of elements for list2: ");
    scanf("%d",&n2);
    printf("Enter elements: \n");
    for(int i=0;i<n2;i++)
    {
        int data;
        scanf("%d",&data);
        if(list2==NULL)
        {
            list2=createnode(data);
        }
        else
        {
            struct node *ptr=list2;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            struct node *newnode=createnode(data);
            newnode->prev=ptr;
            ptr->next=newnode;
        }
    }
    
    printf("List b after appending to the end of a\n");
    struct node *applist=Append(list1,list2);
    display(applist);
    return 0;
}


