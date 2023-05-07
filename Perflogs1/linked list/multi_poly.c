#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int power;
    struct node *next;
};
void insert(struct node **head_ref,int coeff,int power)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node*));
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
void display(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%dx^%d ",temp->coeff,temp->power);
        if(temp->next!=NULL)
        {
            printf("+ ");
        }
        temp=temp->next;
    }
    printf("\n");
}
void multiply(struct node *head1,struct node *head2,struct node **result)
{
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL)
    {
        while(temp2!=NULL)
        {
            int coeff=temp1->coeff*temp2->coeff;
            int power=temp1->power+temp2->power;
            insert(result,coeff,power);
            temp2=temp2->next;
        }
        temp2=head2;
        temp1=temp1->next;
    }
}
int main()
{
    int n1,n2,coeff,power;
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *result=NULL;
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d",&n1);
    for(int i=1;i<=n1;i++)
    {
        printf("Enter the coeff and power for term %d: ",i);
        scanf("%d %d",&coeff,&power);
        insert(&head1,coeff,power);
    }
    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d",&n2);
    for(int i=1;i<=n2;i++)
    {
        printf("Enter the coeff and power for term %d: ",i);
        scanf("%d %d",&coeff,&power);
        insert(&head2,coeff,power);
    }
    printf("First polnomial: ");
    display(head1);
    
    printf("Second polynomial: ");
    display(head2);
    
    multiply(head1, head2, &result);
    
    printf("Resultant polynomial: ");
    display(result);
    
    return 0;
}