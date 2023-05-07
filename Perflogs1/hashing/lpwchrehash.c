#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 100

struct node {
    int key;
    struct node *next;
};

void insert_key_linear_probing(int key, int hash_table[], int n);
void insert_key_chaining(int key, struct node *hash_table[], int n);
void rehash(int **hash_table, int *n);

int main() {
    int n, k, i, j, key, loc, choice;
    int *hash_table;
    struct node **hash_table_chaining;

    printf("Enter the size of the hash table: ");
    scanf("%d", &n);

    printf("Enter the number of keys to be stored (<= %d): ", n);
    scanf("%d", &k);

    if (k > MAX_KEYS) {
        printf("Error: Maximum number of keys exceeded.\n");
        return 1;
    }

    hash_table = (int *) calloc(n, sizeof(int));
    hash_table_chaining = (struct node **) calloc(n, sizeof(struct node *));

    printf("Enter the keys to be stored:\n");
    for (i = 0; i < k; i++) {
        scanf("%d", &key);
        loc = key % n;

        printf("Collision resolution technique:\n");
        printf("1. Linear probing with chaining\n");
        printf("2. Rehashing technique\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_key_linear_probing(key, hash_table, n);
                break;
            case 2:
                insert_key_chaining(key, hash_table_chaining, n);
                break;
            default:
                printf("Error: Invalid choice.\n");
                return 1;
        }
    }

    printf("Hash table contents:\n");
    for (i = 0; i < n; i++) {
        printf("%d: ", i);
        if (hash_table_chaining[i] != NULL) {
            struct node *temp = hash_table_chaining[i];
            while (temp != NULL) {
                printf("%d ", temp->key);
                temp = temp->next;
            }
        } else {
            printf("%d", hash_table[i]);
        }
        printf("\n");
    }

    free(hash_table);
    for (i = 0; i < n; i++) {
        struct node *temp = hash_table_chaining[i];
        while (temp != NULL) {
            struct node *temp2 = temp;
            temp = temp->next;
            free(temp2);
        }
    }
    free(hash_table_chaining);

    return 0;
}

void insert_key_linear_probing(int key, int hash_table[], int n) {
    int loc = key % n;
    int i = loc;
    while (hash_table[i] != 0) {
        i = (i + 1) % n;
        if (i == loc) {
            printf("Error: Hash table is full.\n");
            exit(1);
        }
    }
    hash_table[i] = key;
}

void insert_key_chaining(int key, struct node *hash_table[], int n) {
    int loc = key % n;
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

void rehash(int **hash_table, int *n) {
    int i, j, *old_hash_table;
    old_hash_table = *hash_table;
    *n *= 2;
    *hash_table = (int *) calloc(*n, sizeof(int));
    for (i = 0; i < *n/2; i++) {
        if (old_hash_table[i] != 0) {
            j = old_hash_table[i] % *n;
            while ((*hash_table)[j] != 0) {
                j = (j + 1) % *n;
            }
        }
    }
}
