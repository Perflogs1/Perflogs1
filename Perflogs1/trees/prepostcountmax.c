#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node{
    int data;
    struct node *left;
    struct node *right;
    int flg;
};
struct stack{
    struct node *arr[size];
    int top;
};
struct stack s;
struct node *top()
{
    if(s.top==-1)
    {
        return NULL;
    }
    else
    {
        return s.arr[s.top];
    }
}
struct node *pop()
{
    if(s.top==-1)
    {
        return NULL;
    }
    else
    {
        return s.arr[s.top--];
    }
}

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

struct node *insert(struct node *root,int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->flg=0;
    if(root==NULL)
    {
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
        return root;
    }
    else
    {
        struct node *temp=root;
        while(1)
        {
            if(temp->data>data)
            {
                if(temp->left!=NULL)
                {
                    temp=temp->left;
                }
                else
                {
                    newnode->data=data;
                    newnode->left=NULL;
                    newnode->right=NULL;
                    temp->left=newnode;
                    return root;
                }
            }
            else
            {
                if(temp->right!=NULL)
                {
                    temp=temp->right;
                }
                else
                {
                    newnode->data=data;
                    newnode->left=NULL;
                    newnode->right=NULL;
                    temp->right=newnode;
                    return root;
                }
            }
        }
    }
}


void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    struct node *temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            if(temp->right!=NULL)
            {
                push(temp->right);
            }
            temp=temp->left;
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
}

void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    struct node *temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            push(temp);
            temp=temp->left;
        }
        if(top()->flg==1)
        {
            if(!isEmpty())
            {
                temp=pop();
                printf("%d ",temp->data);
                temp=NULL;
            }
            if(isEmpty())
            {
                break;
            }
        }
        else
        {
            top()->flg=1;
            temp=top()->right;
        }
    }

}

int countnodes(struct node *root)
{
    int c=0;
    if(root==NULL)
    {
        return c;
    }
    push(root);
    while(!isEmpty())
    {
        struct node *temp=pop();
        c++;
        if(temp->right!=NULL)
        {
            push(temp->right);
        }
        if(temp->left!=NULL)
        {
            push(temp->left);
    
        }
    }
    return c;
}

int maximum(struct node *root)
{
    if(root==NULL)
    {
        return -1;
    }
    push(root);
    int max=-1;
    while(!isEmpty())
    {
        struct node *current=pop();
        if(current->data>max)
        {
            max=current->data;
        }
        if(current->left!=NULL)
        {
            push(current->left);
        }
        if(current->right!=NULL)
        {
            push(current->right);
        }
    }
    return max;
}

void mirrorimage(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    push(root);
    while(!isEmpty())
    {
        struct node *current=pop();
        struct node *temp=current->right;
        current->right=current->left;
        current->left=temp;
        if(current->right!=NULL)
    {
        push(current->right);
    }
    if(current->left!=NULL)
    {
        push(current->left);
    }
    }
}

int main()
{
    s.top = -1;
    int n;
    printf("Enter the number of nodes in the BST:");
    scanf("%d", &n);
    printf("Enter the data of nodes:");
    struct node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Pre-Order Traversal:\n");
    preorder(root);
    clear();
    printf("\n");
    printf("Postorder Traversal:\n");
    postorder(root);
    clear();
    printf("\n");
    printf("The Number Of Nodes In the Tree: %d", countnodes(root));
    printf("\n");
    clear();
    printf("The mirror image of the tree: \n");
    mirrorimage(root);
    printf("\n");
    preorder(root);
    clear();
    printf("\n");
    printf("The maximum element of the tree is: %d \n",maximum(root));
    clear();
    printf("\n");
    
    return 0;
}




