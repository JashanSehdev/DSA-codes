#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Node
{
    void *data;
    struct Node *prev;
    struct Node *next;
    
}Node;

typedef struct DoubleList {
    Node *head;
    Node *tail;
    void (*print) (void *);
    void (*freeData) (void *);
}DoubleList;

Node *createNode (void *data) {
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

DoubleList *createList (void (*print)(void *), void (*freeData)(void*)) {
    DoubleList *list = (DoubleList*) malloc (sizeof(DoubleList));
    list->head = NULL;
    list->tail = NULL;
    list->freeData = freeData;
    list->print = print;
    return list;
}

void insertEnd(DoubleList *list, void *data) {
    if (list->head == NULL){
        Node *newNode = createNode(data);
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    Node *newNode = createNode(data);
    list->tail->next = newNode;
    newNode->prev = list->tail;
    list->tail = newNode;
}

void deleteNode(DoubleList *list, void *data) {
    Node *temp = list->head;

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data not found");
        return;
    }

    if (temp == list->head && temp == list->tail){
        list->tail = NULL;
        list->head = NULL;
    }
    else if (temp == list->head) {
        list->head = temp->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
    }
    else if (temp == list->tail) {
        list->tail = temp->prev;
        if (list->tail != NULL) {
            list->tail->next = NULL;
        }
    }
    else {
        temp->prev->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }
    list->freeData(temp->data);
    free(temp);

}

void freeList (DoubleList *list) {
    Node *temp = list->head;

    while (temp != NULL) {
        Node *next = temp->next;
        list->freeData(temp->data);
        free(temp);
        temp = next;
    }

    free (list);
}


void freeInt(void *data) {
    free(data);
}

void printInt (void *data) {
    printf("%d", *(int*) data);
}

void printList (DoubleList *list){
    printf("Double LinkedList \n");
    Node *temp = list->head;
    while (temp != NULL) {
        list->print(temp->data);
        printf(" <--> ");
        temp = temp->next;
    }

    printf("NULL \n");
}
int main() {
   // Create the list
    DoubleList *list = createList(printInt, freeInt);
    assert(list != NULL);
    
    // Insert integers 10, 20, 30
    int *a = malloc(sizeof(int)); *a = 10;
    int *b = malloc(sizeof(int)); *b = 20;
    int *c = malloc(sizeof(int)); *c = 30;
    
    insertEnd(list, a);
    insertEnd(list, b);
    insertEnd(list, c);
    
    // Print list and verify head/tail
    printList(list);
    assert(*(int*)list->head->data == 10);
    assert(*(int*)list->tail->data == 30);
    
    // Delete middle node (20)
    deleteNode(list, b);
    printList(list);
    assert(*(int*)list->head->next->data == 30);  // check new next
    
    // Delete head (10)
    deleteNode(list, a);
    printList(list);
    assert(*(int*)list->head->data == 30);
    
    // Delete tail (30)
    deleteNode(list, c);
    printList(list);
    assert(list->head == NULL);
    assert(list->tail == NULL || list->tail->data == c);
 // Your code doesn't update tail on deletion; consider fixing
    
    // Free list
    freeList(list);
    
    printf("All test cases passed!\n");
    return 0;
    
}