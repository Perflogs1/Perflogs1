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

void RemoveDuplicates(struct node *head)
{
    struct node *current=head;
    while(current!=NULL)
    {
        if(current->next!=NULL && current->data==current->next->data)
        {
            struct node *temp=current->next;
            current->next=temp->next;
            free(temp);
        }
        else
        {
            current=current->next;
        }
    }
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
    printf("Enter the no of elements in the linked list: ");
    //int n;
    scanf("%d",&n);
    printf("Enter data: ");
    for(int i=0;i<n;i++)
    {
        int data;
        
        scanf("%d",&data);
        append(&head,data);
    }
    printf("Original list \n");
    display(head);
    RemoveDuplicates(head);
    printf("Changed list after removing duplicates \n");
    display(head);
    return 0;
}

