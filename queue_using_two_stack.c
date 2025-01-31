
//queueUsingTwoStack
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;
int count = 0;
void push1(int data) {
   if (top1 == MAX - 1) {
       printf("Overflow\n");
       return;
   }
   stack1[++top1] = data;
}
void push2(int data) {
   if (top2 == MAX - 1) {
       printf("Overflow\n");
       return;
   }
   stack2[++top2] = data;
}
int pop1() {
   if (top1 == -1) {
       printf("Stack1 Underflow\n");
       return -1;
   }
   return stack1[top1--];
}
int pop2() {
   if (top2 == -1) {
       printf("Stack2 Underflow\n");
       return -1;
   }
   return stack2[top2--];
}
void enqueue(int data) {
   push1(data);
   count++;
}
void dequeue() {
   if (top1 == -1 && top2 == -1) {
       printf("Queue is empty\n");
       return;
   }
   for (int i = 0; i < count; i++) {
       push2(pop1());
   }
   printf("Dequeued: %d\n", pop2());
   count--;
   for (int i = 0; i < count; i++) {
       push1(pop2());
   }
}
void display() {
   if (top1 == -1) {
       printf("Queue is empty\n");
       return;
   }
   printf("Queue elements: ");
   for (int i = 0; i <= top1; i++) {
       printf("%d ", stack1[i]);
   }
   printf("\n");
}
int main() {
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(40);
   enqueue(50);
   display();
   dequeue();
   display();
   enqueue(60);
   display();
   dequeue();
   display();
   return 0;
}