//stackUsingOneQueue

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Queue {
   int array[MAX];
   int front, rear;
};
void initializeQueue(struct Queue* q) {
   q->front = 0;
   q->rear = -1;
}
int isEmpty(struct Queue* q) {
   return (q->front > q->rear);
}

int isFull(struct Queue* q) {
   return (q->rear == MAX - 1);
}

void enqueue(struct Queue* q, int data) {
   if (isFull(q)) {
       printf("Stack is full!\n");
       return;
   }
   q->array[++(q->rear)] = data;
}

int dequeue(struct Queue* q) {
   if (isEmpty(q)) {
       printf("Stack is empty!\n");
       return -1;
   }
   return q->array[(q->front)++];
}

void push(struct Queue* q, int data) {
   enqueue(q, data);
   int n = q->rear - q->front;
   for (int i = 0; i < n; i++) {
       enqueue(q, dequeue(q));
   }
}

int pop(struct Queue* q) {
   if (isEmpty(q)) {
       printf("Stack is empty!\n");
       return -1;
   }
   return dequeue(q);
}

int peek(struct Queue* q) {
   if (isEmpty(q)) {
       printf("Stack is empty!\n");
       return -1;
   }
   return q->array[q->front];
}

void display(struct Queue* q) {
   if (isEmpty(q)) {
       printf("Stack is empty!\n");
       return;
   }
   printf("Stack elements:\n");
   for (int i = q->front; i <= q->rear; i++) {
       printf("%d\n", q->array[i]);
   }
}
int main() {
   struct Queue q;
   initializeQueue(&q);
   push(&q, 10);
   push(&q, 20);
   push(&q, 30);
   display(&q);
   printf("Popped element: %d\n", pop(&q));
   printf("Popped element: %d\n", pop(&q));
   display(&q);
   printf("Peek/top element: %d\n", peek(&q));
   return 0;
}