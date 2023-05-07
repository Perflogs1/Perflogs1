#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
}*top;
void push(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(!temp)
    {
        printf("We cannot allocate memory \n");
    }
    printf("Enter element you want to push: ");
    scanf("%d",&data);
    temp->data=data;
    if(top==NULL)
    {
        temp->next=NULL;
        temp->prev=NULL;
        top=temp;
    }
    else
    {
        top->next=temp;
        temp->prev=top;
        top=temp;
    }
}

int pop()
{
    if(top==NULL)
    {
        printf("Stack is empty \n");
        return 0;
    }
    if(top->next==NULL && top->prev==NULL)
    {
        int a=top->data;
        struct node *temp=top;
        temp=top;
        top=NULL;
        free(temp);
        return a;
    }
    struct node *temp=top;
    top=top->prev;
    top->next=NULL;
    free(temp);
}

void display()
{
    struct node *temp=top;
    if(temp==NULL)
    {
        printf("No elements in the stack \n");
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

int main()
{
    int choice,data;
    int data1;
    while(1)
    {
        printf("1-push elements \n");
    printf("2-pop elements \n");
    printf("3-display elements \n");
    printf("choose choice \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:push(data);
        break;
        case 2: 
        pop();
        printf("Data is popped \n");
        break;
        case 3:display();
        break;
        default:printf("invalid choice \n");
        exit(1);
        break;
    }
    }
    return 0;
    
}
