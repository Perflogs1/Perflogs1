#include<stdio.h>
#include<stdlib.h>
struct node{
    int rollno;
    int marks;
    struct node *left;
    struct node *right;
};

struct node *create(int rollno,int marks)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->rollno=rollno;
    newnode->marks=marks;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root,int rollno,int marks)
{
    if(root==NULL)
    {
        return create(rollno,marks);
    }
    if(marks<root->marks)
    {
        root->left=insert(root->left,rollno,marks);
    }
    else if(marks>root->marks)
    {
        root->right=insert(root->right,rollno,marks);
    }
    return root;
}

void assignrollnos(struct node *root,int *rollno)
{
    if(root!=NULL)
    {
        assignrollnos(root->right,rollno);
        root->rollno=(*rollno)++;
        assignrollnos(root->left,rollno);
    }
}

void printrollnos(struct node *root)
{
    if(root!=NULL)
    {
        printrollnos(root->right);
        printf("Roll no: %d Marks: %d \n",root->rollno,root->marks);
        printrollnos(root->left);
    }
}

int main()
{
    
    int n;
    struct node *root=NULL;
    int roll_no=0;
    printf("Enter the no of students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int marks;
        printf("Enter marks for student %d: ",i+1);
        scanf("%d",&marks);
        root=insert(root,0,marks);
    }
    assignrollnos(root,&roll_no);
    printf("Roll numbers assigned: ");
    printrollnos(root);
    return 0;
}