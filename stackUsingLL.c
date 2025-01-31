#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* top=NULL;

void push(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=top;
    top=newNode;
    
}
void display()
{
    struct Node* temp=top;
    if(temp==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack element :\n");
    while(temp != NULL)
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Peek: %d\n",top->data);

}

void pop()
{
    struct Node* temp=top;
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped element: %d\n",top->data);
    top=top->next;
    free(temp);

}

int main()
{
    display();
    peek();
    pop();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    display();
    pop();
    display();
    peek();

    return 0;
}