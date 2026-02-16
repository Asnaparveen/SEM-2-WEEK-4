#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at Beginning
void insertBeginning(int data) {
    struct Node* newNode = createNode(data);
    if(head != NULL)
        head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at Middle (Position)
void insertMiddle(int data, int pos) {
    if(pos == 1) {
        insertBeginning(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    newNode->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = newNode;

    newNode->prev = temp;
    temp->next = newNode;
}

// Delete at Beginning
void deleteBeginning() {
    if(head == NULL) return;

    struct Node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
}

// Delete at End
void deleteEnd() {
    if(head == NULL) return;

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

// Delete at Middle (Position)
void deleteMiddle(int pos) {
    if(head == NULL) return;

    if(pos == 1) {
        deleteBeginning();
        return;
    }

    struct Node* temp = head;

    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Traversal
void traverse() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    insertBeginning(5);
    insertMiddle(15, 3);

    printf("After Insertions:\n");
    traverse();

    deleteBeginning();
    deleteMiddle(2);
    deleteEnd();

    printf("After Deletions:\n");
    traverse();

    return 0;
}

