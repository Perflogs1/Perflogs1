#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void displaylist(struct node *ptr)
{
    struct node *temp=ptr;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}



void reverse(struct node **head)
{
    struct node *current=(*head);
    struct node *temp=NULL;
    while(temp!=NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->next;
    }
    if(temp!=NULL)
    {
        (*head)=temp->prev;
    }
}

int main()
{
    struct node *head=NULL;
    struct node *newnode=NULL;
    int n,data;
    printf("Enter no of elements you want to add: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter elements: ");
        scanf("%d",&data);
        newnode=createnode(data);
        newnode->next=head;
        if(head!=NULL)
        {
            head->prev=newnode;
        } 
        head=newnode;
        
    }
    

    reverse(&head);

    printf("Reversed list: ");
    displaylist(head);
    
    return 0;
}





