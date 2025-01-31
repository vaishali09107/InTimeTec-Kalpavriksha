//stackUsingTwoqueue

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
       printf("Queue is full!\n");
       return;
   }
   q->array[++(q->rear)] = data;
}
int dequeue(struct Queue* q) {
   if (isEmpty(q)) {
       printf("Queue is empty!\n");
       return -1;
   }
   return q->array[(q->front)++];
}
void push(struct Queue* q1, struct Queue* q2, int data) {
   enqueue(q2, data);
   while (!isEmpty(q1)) {
       enqueue(q2, dequeue(q1));
   }
   struct Queue temp = *q1;
   *q1 = *q2;
   *q2 = temp;
}
int pop(struct Queue* q1) {
   if (isEmpty(q1)) {
       printf("Stack is empty!\n");
       return -1;
   }
   return dequeue(q1);
}
int peek(struct Queue* q1) {
   if (isEmpty(q1)) {
       printf("Stack is empty!\n");
       return -1;
   }
   return q1->array[q1->front];
}
void display(struct Queue* q1) {
   if (isEmpty(q1)) {
       printf("Stack is empty!\n");
       return;
   }
   for (int i = q1->front; i <= q1->rear; i++) {
       printf("%d\n", q1->array[i]);
   }
}
int main() {
   struct Queue q1, q2;
   initializeQueue(&q1);
   initializeQueue(&q2);
   push(&q1, &q2, 10);
   push(&q1, &q2, 20);
   push(&q1, &q2, 30);
   display(&q1);
   printf("Popped element: %d\n", pop(&q1));
   printf("Popped element: %d\n", pop(&q1));
   display(&q1);
   printf("Peek/top element: %d\n", peek(&q1));
   return 0;
}