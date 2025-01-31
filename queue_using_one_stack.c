//queueUsingOneStack
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(int data) {
   if (top == MAX - 1) {
       printf("Queue Overflow\n");
       return;
   }
   stack[++top] = data;
}
int pop() {
   if (top == -1) {
       printf("Queue Underflow\n");
       return -1;
   }
   return stack[top--];
}
void enqueue(int data) {
   push(data);
}
int dequeue() {
   if (top == -1) {
       printf("Queue is empty\n");
       return -1;
   }
   int x = pop();  
   if (top == -1) {
       return x;
   }
   int item = dequeue();
   push(x);  
   return item;
}
void display() {
   if (top == -1) {
       printf("Queue is empty\n");
       return;
   }
   printf("Queue elements: ");
   for (int i = 0; i <= top; i++) {
       printf("%d ", stack[i]);
   }
   printf("\n");
}
int main() {
   enqueue(100);
   enqueue(200);
   enqueue(300);
   enqueue(400);
   enqueue(500);
   display();
   printf("Dequeued: %d\n", dequeue());
   display();
   enqueue(60);
   display();
   printf("Dequeued: %d\n", dequeue());
   display();
   return 0;
}