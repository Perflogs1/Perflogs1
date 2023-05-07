#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct Stack{
    struct node *arr[MAX];
    int top;
};
struct Stack s;
void push(struct node *T ){
    if(s.top==MAX-1){
        printf("Stack is full, overflow...\n");
    }else{
        s.arr[++s.top]=T;
    }
}
struct node * pop(){
    struct node *temp;
    temp=s.arr[s.top];
    if(s.top==-1){
        printf("Stack is empty");
    }else{
        s.top--;
        return temp;
    }
}
bool isEmpty(){
    if(s.top==-1){
        return true;
    }else{
        return false;
    }
}
struct node *peep(){
    if(s.top==-1){
        return NULL;
    }else{
        return s.arr[s.top];
    }
}


struct node* insert(struct node* T, int data) {
    if (T == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < T->data) {
        T->left = insert(T->left, data);
    } else if (data > T->data) {
        T->right = insert(T->right, data);
    }
    return T;
}



struct node *delete_node(struct node *root,int x){
    struct node *p=NULL;
    struct node *T=root;
    while(T!=NULL){
        if(T->data>x){
            p=T;
            T=T->left;
        }else if(T->data<x){
            p=T;
            T=T->right;
        }else{
            break;
        }
    }
    while(1){
        if(T->left==NULL && T->right==NULL){
            if(x<p->data){
                p->left=NULL;
            }else{
                p->right=NULL;
            }
            free(T);
            return root;
        }
        if((T->left!=NULL && T->right==NULL) || (T->left==NULL && T->right!=NULL)){
            if(p==NULL){
                root=T->left;
                free(T);
                return root;
            }
            if(x<p->data){
                p->left=T->right;
            }else{
                p->right=T->left;
            }
            free(T);
            return root;
        }
        
        if(T->left!=NULL && T->right!=NULL){
            struct node *Q;
            Q=T->right;
            if(Q->left==NULL){
                T->data=Q->data;
                Q->left=T->left;
                free(T);
                return Q;
            }
            while(Q->left!=NULL){
                p=Q;
                Q=Q->left;
            }
            T->data=Q->data;
            T=Q;
        }
    }
}

void postOrder(struct node *root){
    struct node *curr=root;
    struct node *temp;
    while(curr!=NULL || !isEmpty()){
        if(curr!=NULL){
            push(curr);
            curr=curr->left;
        }
        else{
            temp=peep()->right;
            if(temp==NULL){
                temp=pop();
                printf("%d ",temp->data);
                while(!isEmpty() && temp==peep()->right){
                    temp=pop();
                    printf("%d ",temp->data);
                }
            }
            else{
                curr=temp;
            }
        }
    }

}
void inOrder(struct node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void main(){
    s.top=-1;
    struct node *root=NULL;
    printf("Data for root node: ");
    int p;
    scanf("%d",&p);
    root=insert(root,p);
    int choice;
    printf("1 to proceed and 0 stop: ");
    scanf("%d",&choice);
    while(choice!=0){
        printf("enter data for node: ");
        scanf("%d",&p);
        insert(root,p);
        printf("1 to proceed and 0 stop: ");
        scanf("%d",&choice);
    }
    printf("Following is the tree: \n");
    inOrder(root);
    printf("\n");
    int del;
    printf("Enter the element to be deleted: ");
    scanf("%d",&del);
    root=delete_node(root,del);
    postOrder(root);
}
