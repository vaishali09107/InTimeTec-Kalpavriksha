#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

void enqueue(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;

    if(front == NULL && rear == NULL)
    {
        front=newNode;
        rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}

void display()
{
    struct Node* temp;
    if(front == NULL && rear ==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: \n");
    temp=front;
    while(temp!=NULL)
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }

    printf("\n");
}

void dequeue(){
    struct Node* temp=front;
    if(front== NULL && rear ==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element: %d\n",front->data);
    front=front->next;
    free(temp);
}
void peek()
{
    if(front== NULL && rear ==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Peek: %d\n",front->data);
}

int main()
{

    dequeue();
    display();
    peek();
    enqueue(11);
    enqueue(22);
    enqueue(33);
    enqueue(44);
    display();
    peek();
    dequeue();
    dequeue();
    display();
    peek();
    return 0;
}
