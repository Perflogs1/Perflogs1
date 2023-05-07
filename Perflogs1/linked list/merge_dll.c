#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *insert(struct node *head,int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    newnode->prev=NULL;
    if(head!=NULL)
    {
        head->prev=newnode;
    }
    return newnode;
}

struct node *sortlist(struct node *head)
{
    if(head==NULL && head->next==NULL)
    {
        return head;
    }
    struct node *current=head;
    int swapped;
    do{
        swapped=0;
        current=head;
        while(current->next!=NULL)
        {
            if(current->data>current->next->data)
        {
            int temp=current->data;
            current->data=current->next->data;
            current->next->data=temp;
            swapped=1;
        }
        current=current->next;
        }
    }while(swapped);
    return head;
}
struct node *mergelist(struct node *head1,struct node *head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    
    if(head1->data<head2->data)
    {
        head1->next=mergelist(head1->next,head2);
        head1->next->prev=head1;
        head1->prev=NULL;
        return head1;
    }
    else
    {
        head2->next=mergelist(head1,head2->next);
        head2->next->prev=head2;
        head2->prev=NULL;
        return head2;
    }
}

void displaylist(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main()
{
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    int num, i;
    printf("Enter the number of elements for the first linked list: ");
    scanf("%d", &num);
    printf("Enter the elements for the first linked list: ");
    for (i = 0; i < num; i++) {
        int data;
        scanf("%d", &data);
        head1 = insert(head1, data);
    }

    int num1;
    printf("Enter the number of elements for the second linked list: ");
    scanf("%d", &num1);
    printf("Enter the elements for the second linked list: ");
    for (i = 0; i < num1; i++) {
        int data;
        scanf("%d", &data);
        head2 = insert(head2, data);
    }
    printf("First list \n");
    sortlist(head1);
    displaylist(head1);
    printf("\n");
    printf("Second list \n");
    sortlist(head2);
    displaylist(head2);
    printf("\n");
    struct node *mergedlist=mergelist(head1,head2);
    printf("Merged lsit \n");
   
    displaylist(mergedlist);
    return 0;
}