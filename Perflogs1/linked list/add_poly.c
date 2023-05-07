#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int power;
    struct node *next;
};

void insert(struct node **head_ref,int coeff,int power)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->power=power;
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
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d x^%d ",temp->coeff,temp->power);
        if(temp->next!=NULL)
        {
            printf("+ ");
        }
         temp=temp->next;
       
    }
    printf("\n");
}

void add(struct node *head1,struct node *head2,struct node **result)
{
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->power==temp2->power)
        {
            insert(result,temp1->coeff+temp2->coeff,temp1->power);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->power>temp2->power)
        {
            insert(result,temp1->coeff,temp1->power);
            temp1=temp1->next;
        }
        else if(temp2->power>temp1->power)
        {
            insert(result,temp2->coeff,temp2->power);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        insert(result,temp1->coeff,temp1->power);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        insert(result,temp2->coeff,temp2->power);
        temp2=temp2->next;
    }
    
}
int main()
{
    int n1,n2,i,coeff,power;
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *result=NULL;
    printf("Enter the no of terms in the first polynomial: ");
    scanf("%d",&n1);
    for(int i=1;i<=n1;i++)
    {
        printf("Enter coeff and power for term %d: ",i);
        scanf("%d %d",&coeff,&power);
        insert(&head1,coeff,power);
    }
    printf("Enter the no of terms in the second polynomial: ");
    scanf("%d",&n2);
    for(int i=1;i<=n2;i++)
    {
        printf("Enter coeff and power for term %d: ",i);
        scanf("%d %d",&coeff,&power);
        insert(&head2,coeff,power);
    }
    
    printf("First polynomial: ");
     display(head1);

    printf("Second polynomial: ");
    display(head2);

    add(head1, head2, &result);

    printf("Resultant polynomial: ");
    display(result);
    
        return 0;
}