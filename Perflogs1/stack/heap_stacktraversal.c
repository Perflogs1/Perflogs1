#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct stack{
    struct node * arr[size];
    int top;
};
struct stack s;
int isEmpty()
{
    if(s.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(s.top==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct node *temp)
{
    if(isFull())
    {
        printf("Stack is full \n");
        return;
    }
    else
    {
        s.arr[++s.top]=temp;
    }
}

struct node *pop()
{
    if(isEmpty())
    {
        printf("Stack is empty \n");
        return NULL;
    }
    else
    {
        return s.arr[s.top--];
    }
}

struct node *create(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *constructheapnodes(int nodes[],int n,int index)
{
    struct node *temp=NULL;
    if(index<n)
    {
        temp=create(nodes[index]);
        temp->left=constructheapnodes(nodes,n,2*index+1);
        temp->right=constructheapnodes(nodes,n,2*index+2);
    }
    return temp;
}

void heaptraversal(struct node *root)
{
    struct node *temp=root;
    while(temp!=NULL)
    {
        push(temp);
        temp=temp->left;
    }
    while(!isEmpty())
    {
        temp=pop();
        printf("%d ",temp->data);
        temp=temp->right;
        while(temp!=NULL)
        {
            push(temp);
            temp=temp->left;
        }
    }
}


int main() {
    s.top=-1;
    int n, i;
    printf("Enter the number of nodes in the heap: ");
    scanf("%d", &n);
    int nodes[n];
    printf("Enter the values of the nodes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &nodes[i]);
    }

    struct node* root = constructheapnodes(nodes, n, 0);


    printf("Heap traversal using stack: ");
    heaptraversal(root);

    return 0;
}
