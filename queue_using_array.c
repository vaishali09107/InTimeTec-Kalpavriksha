#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int data)
{
    if(rear == MAX -1)
    {
        printf("Queue is overflow\n");
        return;
    }
    else if(front ==-1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear]=data;
    }
    else{
        queue[++rear]=data;
    }
}

void dequeue()
{
    if( front==-1 && rear ==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front == rear)
    {
        front=rear=-1;
    }
    else{
        printf("dequeued elemnt : %d\n",queue[front]);
        front++;
    }


}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("Queue elements are: \n");
    for(int i=front;i<rear;i++)
    {
        printf("%d \n",queue[i]);
    }

}

void peek()
{
    if(front == -1 && rear==-1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("Peek : %d\n",queue[front]);
}
int main(){

    peek();
    display();
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
}