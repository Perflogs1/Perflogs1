#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct queue{
    struct node *arr[size];
    int front;
    int rear;
};
struct stack{
    struct node *arr1[size];
    int top;
};
struct stack s;
struct queue q;

int isEmptyQ()
{
    if(q.front==-1 && q.rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmptyS()
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

int isFullS()
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
    if(isFullS())
    {
        printf("Stack is full \n");
        return;
    }
    else
    {
        s.arr1[++s.top]=temp;
    }
}

struct node *pop()
{
    if(isEmptyS())
    {
        printf("Stack is empty \n");
        return NULL;
    }
    else
    {
        return s.arr1[s.top--];
    }
}

void enqueue(struct node *temp)
{
    if(q.rear==size-1)
    {
        printf("Queue is full \n");
        return ;
    }
    else
    {
        q.rear=(q.rear+1)%size;
    }
    q.arr[q.rear]=temp;
}

struct node *dequeue()
{
    if(isEmptyQ())
    {
        printf("Queue is empty \n");
        return NULL;
    }
    if(q.front==q.rear)
    {
         return q.arr[q.front];
         q.front=q.rear=-1;
    }
    else
    {
        q.front=(q.front+1)%size;
    }
    return q.arr[q.front];
}

void clear()
{
    if(s.top==-1)
    {
        return;
    }
    else
    {
        while(s.top!=-1)
        {
            s.top--;
        }
        
        
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

struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    {
        return create(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}
void mirrorimage(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    push(root);
    while(!isEmptyS())
    {
        struct node *current=pop();
        struct node *temp=current->left;
        current->left=current->right;
        current->right=temp;
        if(current->left!=NULL)
        {
            push(current->left);
        }
        if(current->right!=NULL)
        {
            push(current->right);
        }
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int height(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int level_count=0;
    int h=0;
    q.front=q.rear=0;
    enqueue(root);
    while(q.front<q.rear)
    {
        level_count=q.rear-q.front;
        while(level_count>0)
        {
            struct node *current=dequeue();
            if(current->left!=NULL)
            {
                enqueue(current->left);
            }
            if(current->right!=NULL)
            {
                enqueue(current->right);
            }
            level_count--;
        }
        h++;
    }
    return h;
}
int main()
{
    s.top=-1;
    int n;
    q.front=q.rear=0;
    printf("Enter the no of nodes in the BST: ");
    scanf("%d",&n);
    struct node *root=NULL;
    printf("Enter data: ");
    for(int i=0;i<n;i++)
    {
        int data;
        
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("Inorder traversal of the tree before mirror image \n");
    inorder(root);
    printf("\n");
    printf("Mirror image of the tree: ");
    mirrorimage(root);
    inorder(root);
    clear();
    printf("\n");
    printf("Height of the tree: %d \n",height(root));
    printf("\n");
    return 0;
}