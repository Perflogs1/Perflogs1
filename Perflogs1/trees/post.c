#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void insert_node(struct node **root, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    struct node *current = *root;
    while (1) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = new_node;
                return;
            }
            current = current->left;
        }
        else {
            if (current->right == NULL) {
                current->right = new_node;
                return;
            }
            current = current->right;
        }
    }
}

void preorder_traversal(struct node *root) {
    struct node *stack[1000];
    int top = -1;

    stack[++top] = root;
    while (top >= 0) {
        struct node *current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    printf("\n");
}

void postorder_traversal(struct node *root) {
    struct node *stack1[1000];
    struct node *stack2[1000];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;
    while (top1 >= 0) {
        struct node *current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }

    while (top2 >= 0) {
        struct node *current = stack2[top2--];
        printf("%d ", current->data);
    }
    printf("\n");
}

int count_nodes(struct node *root) {
    int count = 0;
    struct node *stack[1000];
    int top = -1;

    stack[++top] = root;
    while (top >= 0) {
        struct node *current = stack[top--];
        count++;

        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    return count;
}

void display_leaf_nodes(struct node *root) {
    if (root == NULL) {
        return;
    }

    struct node *stack[1000];
    int top = -1;

    stack[++top] = root;
    while (top >= 0) {
        struct node *current = stack[top--];

        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
        if (current->left == NULL && current->right == NULL) {
            printf("%d ", current->data);
        }
}
}

int main() {
    struct node *root = NULL;
    int data, choice;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert node\n");
        printf("2. Preorder traversal\n");
        printf("3. Postorder traversal\n");
        printf("4. Display total number of nodes\n");
        printf("5. Display leaf nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_node(&root, data);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder_traversal(root);
                break;
            case 3:
                printf("Postorder traversal: ");
                postorder_traversal(root);
                break;
            case 4:
                printf("Total number of nodes: %d\n", count_nodes(root));
                break;
            case 5:
                printf("Leaf nodes: ");
                display_leaf_nodes(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

