#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


#define size 4
struct queue{
  int front;
  int rear;
  int *arr;
};


int isfull(struct queue *ptr) {

  if ((ptr->rear + 1) % size == ptr->front) return 1;
  return 0;
}

int isEmpty(struct queue *ptr) {
  
  if (ptr->front == -1) return 1; 
  return 0;
}

int enqueue(struct queue *ptr, int val){
  if (isfull(ptr)){
     printf("Queue is full");
     return -1;
  }

  if (ptr->front == -1) {
     ptr->front = 0;
  }

  ptr->rear = (ptr->rear + 1) % size;
  
  ptr->arr[ptr->rear] = val;

  return ptr->arr[ptr->rear];
} 

  


int dequeue(struct queue *ptr) {
  if (isEmpty(ptr)) {
    printf("queue is Empty");
    return -1;
  }
  
  int data = ptr->arr[ptr->front];

  if (ptr->front == ptr->rear) {
     ptr->front = ptr->rear = -1;
  }
  else {
    ptr->front = (ptr->front + 1) % size;
  }

  return data;
}

int main() {
  struct queue *q = (struct queue *) malloc (sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  q->arr = (int *) malloc (size * sizeof(struct queue));

  assert (isEmpty(q) == 1);
  assert (enqueue(q, 20) == 20);
  assert (enqueue(q, 30) == 30);
  assert (enqueue(q, 40) == 40);
  assert (enqueue(q, 50) == 50); 
  assert (dequeue(q) == 20);
  assert (dequeue(q) == 30);
  assert (enqueue(q, 60) == 60);
  assert (enqueue (q, 70) == 70);
  assert (isfull(q) == 1);

  return 0;
}
