#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int data)
{
    if(top==MAX -1)
    {
        printf("Stack overflow\n");
        return;
    }
    else{
        stack[++top]=data;
    }

}

void pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
        return;
    }
    else{
        printf("Popped element : %d\n",stack[top]);
        top--;
    }
}

void peek()
{
    printf("peek element is: %d\n",stack[top]);
}

void display()
{
    printf("Stack: ");
    for(int i=top;i>=0;--i)
    {
        printf("%d\n",stack[i]);
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    display();
    pop();
    display();
    pop();
    display();
    peek();

}