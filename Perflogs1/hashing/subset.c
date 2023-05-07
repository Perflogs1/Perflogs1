#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int key;
    struct node *next;
};

void insert_key(int key, struct node *hash_table[], int m);
int search_key(int key, struct node *hash_table[], int m);

int main() {
    int m, n, i, key, is_subset = 1;
    struct node **hash_table;

    printf("Enter the size of set S: ");
    scanf("%d", &m);

    printf("Enter the elements of set S:\n");
    hash_table = (struct node **) calloc(m, sizeof(struct node *));
    for (i = 0; i < m; i++) {
        scanf("%d", &key);
        insert_key(key, hash_table, m);
    }

    printf("Enter the size of set T: ");
    scanf("%d", &n);

    printf("Enter the elements of set T:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        if (search_key(key, hash_table, m) == -1) {
            is_subset = 0;
            break;
        }
    }

    if (is_subset) {
        printf("S is a subset of T.\n");
    } else {
        printf("S is not a subset of T.\n");
    }

    for (i = 0; i < m; i++) {
        struct node *temp = hash_table[i];
        while (temp != NULL) {
            struct node *temp2 = temp;
            temp = temp->next;
            free(temp2);
        }
    }
    free(hash_table);

    return 0;
}

void insert_key(int key, struct node *hash_table[], int m) {
    int loc = key % m;
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->key = key;
    new_node->next = NULL;
    if (hash_table[loc] == NULL) {
        hash_table[loc] = new_node;
    } else {
        struct node *temp = hash_table[loc];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int search_key(int key, struct node *hash_table[], int m) {
    int loc = key % m;
    struct node *temp = hash_table[loc];
    while (temp != NULL) {
        if (temp->key == key) {
            return loc;
        }
        temp = temp->next;
    }
    return -1;
}