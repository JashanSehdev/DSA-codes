#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    void *data;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    void (*print)(void*);
    void (*freeData)(void*);
}LinkedList;

Node *createNode(void *data) {
    Node *newNode = (Node *) malloc (sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LinkedList *createLinkedList(void (*print)(void*), void (*freeData)(void*)) {
    LinkedList *list = (LinkedList *) malloc (sizeof(LinkedList));
    list->head = NULL;
    list->print = print;
    list->freeData = freeData;
    return list;
}

void insertEnd(LinkedList *list, void *val){
    // if Linked list is Empty
    Node *newNode = createNode(val);
    if(list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node *temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void deleteNode(LinkedList *list, void *val, int (*compare)(void *,void *)) {

    if (list->head == NULL) return;

    if (list->head->data == val) {
        Node *next = list->head->next;
        list->freeData(list->head->data);
        free(list->head);
        list->head = next;
        return;
    }

    Node *prev = NULL;
    Node *temp = list->head;

    while (temp != NULL && compare(temp->data,val) != 0){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("data not found\n");
        return;
    }

    prev->next = temp->next;
    list->freeData(temp->data);
    free(temp);
    //done;
    
}

void printList (LinkedList *list) {
    if (list->head == NULL) return;

    Node *temp = list->head;

    while (temp != NULL) {
        list->print(temp->data);
        printf (" -> ");
        temp = temp->next;
    }

    printf ("NULL \n");
}

void freeList(LinkedList *list) {
    Node *temp = list->head;

    while (temp != NULL) {
        Node *next = temp->next;
        list->freeData(temp->data);
        free(temp);
        temp = next;
    }

    free(list);
}

void printInt (void *data) {
    printf("%d", *(int*) data);
}

void freeInt (void *data) {
    free(data);
}


int compareInt (void *a, void *b) {
    return *(int *)a - *(int *)b;
}



int main() {
    LinkedList *list = createLinkedList(printInt,freeInt);
// Dynamically allocate integers
    int *a = malloc(sizeof(int)); *a = 10;
    int *b = malloc(sizeof(int)); *b = 20;
    int *c = malloc(sizeof(int)); *c = 30;

    insertEnd(list, a);
    insertEnd(list, b);
    insertEnd(list, c);

    printf("Linked List: ");
    printList(list);

    printf("Deleting 20...\n");
    deleteNode(list, b, compareInt);

    printf("After Deletion: ");
    printList(list);

    freeList(list);
    return 0;
}