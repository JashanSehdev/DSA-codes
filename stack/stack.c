#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define maxsize 80

struct stack {

	int top;
	int size;
	int* arr;

};


int isEmpty (struct stack *ptr) {
	if (ptr->top == -1) return 1;
	return 0;
}

int isFull (struct stack *ptr) {
	if (ptr->top == ptr->size-1) {
		return 1;
	}
	return 0; // if stack is not full
}

// to add element in the stack
int add (struct stack *ptr, int value) {
	if (!isFull(ptr)) {
		int top = ++ptr->top;
		ptr->arr[top] = value;
		return ptr->arr[top];
	}
	else {
		return -1; //if stack has been full
	}
}

int pop (struct stack *ptr) {
	if (!isEmpty(ptr)) {
		int val = ptr->arr[ptr->top--];
		return val; 
	}
	return -1; //if a stack has been empty
}

int top (struct stack *ptr) {
	if (isEmpty(ptr)) return -1;
	return ptr->arr[ptr->top];
}
int main() {
	struct stack *s = (struct stack *) malloc (sizeof(struct stack));
	s->size = 80; 
	s->top = -1;
	s->arr = (int *) malloc(s->size * sizeof(int));
	assert(isEmpty(s) == 1);
	assert(add(s, 1) == 1);
	assert(add(s, 2) == 2);
	assert(pop(s) == 2);
	assert(top(s) == 1);



	return 0;
}
