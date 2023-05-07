#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node* left;
  struct node* right;
};

struct node* newNode(int key) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct node* insert(struct node* root, int key) {
  if (root == NULL) {
    return newNode(key);
  }

  if (key < root->key) {
    root->left = insert(root->left, key);
  } else if (key > root->key) {
    root->right = insert(root->right, key);
  }

  return root;
}

struct node* minValueNode(struct node* node) {
  struct node* current = node;

  while (current && current->left != NULL) {
    current = current->left;
  }

  return current;
}

struct node* delete(struct node* root, int key) {
  if (root == NULL) {
    return root;
  }

  if (key < root->key) {
    root->left = delete(root->left, key);
  } else if (key > root->key) {
    root->right = delete(root->right, key);
  } else {
    if (root->left == NULL) {
      struct node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node* temp = root->left;
      free(root);
      return temp;
    }

    struct node* temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = delete(root->right, temp->key);
  }

  return root;
}

struct node* search(struct node* root, int key) {
  if (root == NULL || root->key == key) {
    return root;
  }

  if (key < root->key) {
    return search(root->left, key);
  }

  return search(root->right, key);
}

void inorder(struct node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

int main() {
  struct node* root = NULL;
  int choice, key;

  do {
    printf("\nBinary Search Tree Operations\n");
    printf("-------------------------------\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Find\n");
    printf("4. Show\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter key to insert: ");
        scanf("%d", &key);
        root = insert(root, key);
        break;
      case 2:
        printf("Enter key to delete: ");
        scanf("%d", &key);
        root = delete(root, key);
        break;
      case 3:
        printf("Enter key to find: ");
        scanf("%d", &key);
        if (search(root, key) != NULL) {
          printf("Key found\n");
        } else {
          printf("Key not found\n");
        }
        break;
      case 4:
        printf("BST: ");
        inorder(root);
        printf("\n");
        break;
      case 5:
        printf("Exiting program\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 5);

  return 0;
}