#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node{
    int flg;
    int data;
    struct node *left;
    struct node *right;
};

struct stack{
    struct node *arr[size];
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

void push(struct node *temp)
{
    if(s.top==size-1)
    {
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
    newnode->flg=0;
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
    if(data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}


void inorder(struct node *root)
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

void preorder(struct node *root)
{
    struct node *temp=root;
    while(temp!=NULL)
    {
        push(temp);
        printf("%d ",temp->data);
        temp=temp->left;
    }
    while(!isEmpty())
    {
        temp=pop();
        temp=temp->right;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            push(temp);
            temp=temp->left;
        }
    }
    
}
void mirrorimage(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    push(root);
    struct node *temp=root;
    while(!isEmpty())
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

void leafnodes(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    
    struct node *temp=root;
    int c=0;
    while(1)
    {
        while(temp!=NULL)
        {
            if(temp->left==NULL && temp->right==NULL)
            {
                printf("%d ",temp->data);
                c++;
            }
            if(temp->left!=NULL)
            {
                push(temp->left);
            }
            temp=temp->right;
        }
        if(!isEmpty())
        {
            temp=pop();
        }
        else
        {
            break;
        }
    }
    printf("\nNumber of leaf nodes in the BST: %d",c);
}

int main()
{
    s.top=-1;
    int n;
    struct node *root=NULL;
    printf("Enter the no of nodes in the BST: ");
    scanf("%d",&n);
    int data;
    for(int i=0;i<n;i++)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("Inorder traversal of the tree: ");
    inorder(root);
    clear();
    printf("\n");
    printf("Preorder traversal of the tree: ");
    preorder(root);
    clear();
    printf("\n");
    printf("Mirror image of the tree: ");
    mirrorimage(root);
    preorder(root);
    clear();
    printf("\n");
    printf("Leaf nodes of the tree: ");
    leafnodes(root);
    clear();
    printf("\n");
    return 0;
}


