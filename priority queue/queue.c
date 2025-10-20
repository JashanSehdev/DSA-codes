#include<stdio.h>
#include<stdlib.h>

#define max_size 8

typedef struct {
    void *data;
    int priority;
} Element;

int parent (int i) {return (i - 1) / 2;}

int left (int i) {return (i * 2) + 1;}

int right (int i) {return (i * 2) + 2;}

typedef struct {
    Element pq [max_size];
    int size;
    int (*compare) (void*,void*); 
} priorityQueue;

void swap (Element *a, Element *b) {
    Element element = *a;
    *a = *b;
    *b = element;
}

priorityQueue* createPQ(int (*compare) (void*, void*)) {
    priorityQueue *pq = (priorityQueue*) malloc (sizeof(priorityQueue));
    pq->size = 0;
    pq->compare = compare;
    return pq;
}


void insert (priorityQueue *pq, void *data, int priority) {
    if (pq->size == max_size) return;

    Element e = {data, priority};
    pq->pq[pq->size] = e;
    int i = pq->size;
    pq->size++;
    //min heap based on priority
    while ( i!=0 && pq->pq[parent(i)].priority > pq->pq[i].priority) {
        swap(&pq->pq[parent(i)], &(pq->pq[i]));
        i = parent(i);
    } 
}

void heapify (priorityQueue *pq, int i) {
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if ( l <pq->size && pq->pq[l].priority < pq->pq[smallest].priority) {
        smallest = l;
    }

    if (r < pq->size && pq->pq[r].priority < pq->pq[smallest].priority) {
        smallest = r;
    }

    while(smallest!=i){
        swap(&pq->pq[smallest], &pq->pq[i]);
        heapify(pq, smallest);
    }
}

void *extractMin(priorityQueue *pq){
    if (pq->size <= 0) return NULL;

    Element root = pq->pq[0];
    pq->pq[0] = pq->pq[pq->size - 1];
    pq->size--;

    return root.data;
}

int compareInt (void *a, void *b) {
    return (*(int*)a - *(int*)b);
}

void printInt (void *data) {
    printf("%d", *(int*)data);
}

void printPQ (priorityQueue *pq, void (*print) (void*)){
    printf("Priority Queue: \n");
    for (int i = 0; i < pq->size ; ++i) {
        print (pq->pq[i].data);
        printf(" %d \n", pq->pq[i].priority);
    }
}

int main() {
    priorityQueue *pq = createPQ(compareInt);

    int a = 10, b = 5, c = 2, d = 30;

    insert(pq, &a, 3);
    insert(pq, &b, 2);
    insert(pq, &c, 5);
    insert(pq, &d, 1);

    printPQ(pq, printInt);

    int *min = (int*)extractMin(pq);
    printf("Extracted min: %d\n", *min);

    printf("Extracted min: %d\n",*(int*)extractMin(pq));   
    printf("Extracted min: %d\n",*(int*)extractMin(pq));
    printPQ(pq, printInt);
    free(pq);


    return 0;
}


// to get size we have to put pointer name size