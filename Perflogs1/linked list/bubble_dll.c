#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}
void insertatbeginning(struct node **head,int data)
{
    struct node *newnode=createnode(data);
    newnode->data=data;
    newnode->next=(*head);
    newnode->prev=NULL;
    if((*head)!=NULL)
    {
        (*head)->prev=newnode;
    }
    (*head)=newnode;
}

void swap(struct node *list1,struct node *list2)
{
    int temp=list1->data;
    list1->data=list2->data;
    list2->data=temp;
}

void bubblesort(struct node *head)
{
    struct node *current=head;
    struct node *last=NULL;
    int swapped;
    if(head==NULL)
    {
        return;
    }
    do{
        swapped=0;
        current=head;
        while(current->next!=last)
        {
            if(current->data>current->next->data)
            {
                swap(current,current->next);
                swapped=1;
            }
            current=current->next;
        }
        last=current;
    }while(swapped);
}

void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void displayoriginal(struct node *ptr)
{
    struct node *last=NULL;
    while(ptr!=NULL)
    {
        last=ptr;
        ptr=ptr->next;
    }
    
    while(last!=NULL)
    {
        printf("%d ",last->data);
        last=last->prev;
    }
}
int main() {
    struct node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        insertatbeginning(&head, data);
    }

    printf("Original list(in Original order): ");
    displayoriginal(head);


    bubblesort(head);
    printf("Sorted list: ");
    display(head);
   

    return 0;
}

