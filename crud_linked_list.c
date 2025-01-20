#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

struct Node* insertAtBegin(struct Node* head, int data)
{
    struct Node* new_node = createNode(data);
    new_node->next = head;
    return new_node;
}

struct Node* insertAtEnd(struct Node* head, int data) 
{
    struct Node* new_node = createNode(data);
    if (head == NULL) 
    {
        return new_node;
    }
    struct Node* temp = head;
    
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return head; 
}

struct Node* insertAtPosition(struct Node* head, int pos, int data) 
{
    if (pos < 1) 
    {
        printf("Invalid position\n");
        return head;
    }

    struct Node* new_node = createNode(data);
    
    if (pos == 1) 
    {
        new_node->next = head;
        return new_node;
    }

    struct Node* temp = head;
    
    for (int i = 1; i < pos - 1; i++) 
    {
        if (temp == NULL) {
            printf("Position out of range.\n");
            free(new_node);
            return head;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range.\n");
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}

void printList(struct Node* head)
{
    struct Node* curr = head;
    printf("Linked List: ");
    
    while (curr != NULL) 
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    
    printf("\n");
}

struct Node* updateAtPosition(struct Node* head, int pos, int data) 
{
    if (pos < 1) 
    {
        printf("Invalid position.\n");
        return head;
    }

    struct Node* temp = head;

    for (int i = 1; i < pos; i++) 
    {
        if (temp == NULL) 
        {
            printf("Position out of range\n");
            return head;
        }
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Position out of range.\n");
        return head;
    }

    temp->data = data; 
    return head;
}

struct Node* deleteFromStart(struct Node* head) 
{
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    
    struct Node* temp = head;
    head = head->next; 
    free(temp); 
    printf("Deleted from start\n");
    
    return head;
}

struct Node* deleteFromEnd(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is already empty.\n");
        return head;
    }

    if (head->next == NULL)
    { 
        free(head);
        printf("Last element deleted.\n");
        return NULL; 
    }

    struct Node* temp = head;

    while (temp->next->next != NULL)
    { 
        temp = temp->next;
    }

    free(temp->next); 
    temp->next = NULL; 
    printf("Last element deleted.\n");

    return head;
}

struct Node* deleteAtPosition(struct Node* head, int pos) 
{
   if (pos < 1)
   {
       printf("Invalid position.\n");
       return head;
   }

   if (head == NULL) 
   {
       printf("List is already empty.\n");
       return head;
   }

   if (pos == 1)
   { 
       struct Node* temp = head;
       head = head->next;
       free(temp); 
       printf("Element at position %d deleted.\n", pos);
       return head;
   }

   struct Node* temp = head;

   for (int i = 1; i < pos - 1; i++) 
   {
       if (temp == NULL || temp->next == NULL)
       {
           printf("Position out of range.\n");
           return head;
       }
       temp = temp->next; 
   }

   struct Node* delete_node = temp->next;

   if (delete_node == NULL) 
   { 
       printf("Position out of range.\n");
       return head; 
   }

   temp->next = delete_node->next; 
   free(delete_node); 
   printf("Element at position %d deleted.\n", pos);

   return head; 
}

int main() 
{

   struct Node* head = NULL;

   int choice, data, pos;
   int operations;
   
   printf("Enter the number of operstions: \n");
   scanf("%d",&operations);
   printf("\nMenu:\n");
       printf("1 x: Add x to the end.\n");
       printf("2 x: Add x at the beginning.\n");
       printf("3 pos x: Add x at position pos (1-indexed).\n");
       printf("4: Display all elements.\n");
       printf("5 pos x: Update element at position pos to x.\n");
       printf("6: Delete first element.\n");
       printf("7: Delete last element.\n");
       printf("8 pos: Delete element at position pos (1-indexed).\n");
       printf("9: Exit.\n");
   do {
    
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               printf("Enter new data: ");
               scanf("%d", &data);
               head = insertAtEnd(head, data);
               break;

           case 2:
               printf("Enter new data: ");
               scanf("%d", &data);
               head = insertAtBegin(head, data);
               break;

           case 3:
               printf("Enter the position: ");
               scanf("%d", &pos);
               printf("Enter new data: ");
               scanf("%d", &data);
               head = insertAtPosition(head, pos, data);
               break;

           case 4:
               printList(head);
               break;

           case 5:
               printf("Enter the position to update: ");
               scanf("%d", &pos);
               printf("Enter the new data: ");
               scanf("%d", &data);
               head = updateAtPosition(head, pos, data);
               break;

           case 6:
               head = deleteFromStart(head);
               break;

           case 7:
               head = deleteFromEnd(head);
               break;

           case 8:
               printf("Enter the position to delete: ");
               scanf("%d", &pos);
               head = deleteAtPosition(head, pos);
               break;
           case 9:
               exit(0);
           default:
               printf("Invalid choice\n");
       }
   } while (choice != operations);

   return 0;
}
