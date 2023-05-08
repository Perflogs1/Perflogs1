#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int lbit, rbit;
    struct node *left;
    struct node *right;
    int flag;
};

struct node *createNode(int data)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->lbit = 0;
    n->rbit = 0;
    n->left = NULL;
    n->right = NULL;
    n->flag = 0;
    return n;
}

struct node *insertTBT(struct node *head, int data)
{
    struct node *n = createNode(data);
    struct node *prev = NULL;
    if (head->left == NULL)
    {
        head->left = n;
        n->lbit = 0;
        n->right = head;
        n->left = head;
        n->rbit = 0;
        head->lbit = 1;
        return head;
    }

    struct node *root = head->left;
    while (root != NULL)
    {
        prev = root;
        if (data < root->data)
        {
            if (root->lbit != 0)
            {
                root = root->left;
            }
            else
            {
                n->left = prev->left;
                n->right = prev;
                prev->left = n;
                prev->lbit = 1;
                break;
            }
        }
        else if (data > root->data)
        {
            if (root->rbit != 0)
            {
                root = root->right;
            }
            else
            {
                n->left = prev;
                n->right = prev->right;
                prev->right = n;
                prev->rbit = 1;
                break;
            }
        }
        else
        {
            free(n);
            return head;
        }
    }
    return head;
}

struct node *inSucc(struct node *T)
{
    struct node *Q = T->right;
    if (T->rbit != 0)
    {
        while (Q->lbit != 0)
        {
            Q = Q->left;
        }
    }
    return Q;
}

void inorder(struct node *head)
{
    struct node *T = head;
    while (1)
    {
        T = inSucc(T);
        if (T == head)
        {
            break;
        }
        printf("%d ", T->data);
    }
}

void preorder(struct node *head)
{
    struct node *T = head->left;
    while (head != T)
    {
        printf("%d ", T->data);
        if (T->lbit != 0)
        {
            T = T->left;
        }
        else
        {
            while (T->rbit == 0)
            {
                T = T->right;
            }
            T = T->right;
        }
    }
}

// void postorder(struct node* head) {
//     struct node* T = head->right;
//     struct node* prev = head;
//     while (T != head) {
//         if (T->flag == 0 && T->left != NULL) {
//             prev = T;
//             T = T->left;
//             T->flag = 2;
//         } else if (T->right != NULL && T->right->flag == 0) {
//             prev = T;
//             T = T->right;
//             T->flag = 2;
//         } else {
//             printf("%d ", T->data);
//             T->flag = 1;
//             prev = T;
//             T = prev->right;
//             if (prev->flag == 2 && T->flag == 2) {
//                 while (T->flag != 1) {
//                     prev = T;
//                     T = T->right;
//                 }
//                 T = prev;
//             }
//         }
//     }
// }

void postorder(struct node* head){
    struct node* T;
    T = head->left;
    T->flag = 2;  
    while (T != head) {
        if (T->left->flag != 1 && T->lbit != 0) {
            T = T->left;
            T->flag = 2;
        }
        else if (T->right->flag != 1 && T->rbit != 0) {
            T = T->right;
            T->flag = 3;
        }
        else {
            printf("%d ", T->data);
            if (T->flag == 2) {
                T->flag = 1;
                while (T->rbit != 0 && T->right != head) {
                    T = T->right;
                }
                T = T->right;
            }
            else {
                T->flag = 1;
                while (T->lbit != 0 && T->left != head) {
                    T = T->left;
                }
                T = T->left;
            }
        }
    }
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->lbit = 0;
    head->rbit = 1;
    head->right = head;
    head->left = NULL;

    head = insertTBT(head, 10);
    head = insertTBT(head, 5);
    head = insertTBT(head, 25);
    postorder(head);

    return 0;
}