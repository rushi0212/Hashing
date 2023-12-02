#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
struct Node {
    int data;
    struct Node* next;
};
struct Node* hashTable[TABLE_SIZE];
void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}
int hash(int key) {
    return key % TABLE_SIZE;
}
void insert(int key) {
    int index = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
int search(int key) {
    int index = hash(key);
    struct Node* current = hashTable[index];

    while (current != NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0; 
}
void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = hashTable[i];
        printf("Bucket %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    initializeHashTable();
    
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(6);
    
    printf("Hash table after insertions:\n");
    displayHashTable();
    
    int key = 15;
    if (search(key)) {
        printf("%d found in the hash table.\n", key);
    } else {
        printf("%d not found in the hash table.\n", key);
    }
    
    key = 10;
    if (search(key)) {
        printf("%d found in the hash table.\n", key);
    } else {
        printf("%d not found in the hash table.\n", key);
    }
    
    return 0;
}
