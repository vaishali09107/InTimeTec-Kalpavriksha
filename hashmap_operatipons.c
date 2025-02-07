#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct Node{
    int key;
    int value;
    struct Node* next;
}Node;
typedef struct{
    Node* buckets[SIZE];
}hashMap;

int hashFunction(int key)
{
    return key% SIZE;
}

void initializeHashMap(hashMap *map)
{
    for(int i=0;i<SIZE;i++)
    {
        map->buckets[i]=NULL;
    }
}

void insertData(hashMap *map,int key,int value)
{
    int index=hashFunction(key);
    Node* current=map->buckets[index];
    while(current !=NULL)
    {
        if(current->key==key)
        {
            current->value=value;
            return;
        }
        current=current->next;
    }

    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->value=value;
    newNode->next=map->buckets[index];
    map->buckets[index]=newNode;

}

int search(hashMap* map,int key)
{
    int index=hashFunction(key);
    Node* current=map->buckets[index];
    while(current !=NULL)
    {
        if(current->key==key)
        {
            
            return current->value;
        }
        current=current->next;
    }
    return -1;
}
void deleteData(hashMap* map,int key)
{
    int index=hashFunction(key);
    Node* current=map->buckets[index];
    Node* prev=NULL;
    while(current !=NULL)
    {
        if(current->key==key)
        {
            if(prev == NULL)
            {
                map->buckets[index]=current->next;
            }
            else{
                prev->next=current->next;
            }
            printf("Deleted key %d\n",key);
            return;
        }
        prev=current;
        current=current->next;
    }
    printf("key %d not found\n",key);

}

void displayHashMap(hashMap *map)
{
    for(int i=0;i<SIZE;i++)
    {
        Node* current=map->buckets[i];
        if(current !=NULL)
        {
            printf("Index %d: ",i);
            while(current !=NULL)
            {
                printf("(%d %d)",current->key,current->value);
                current=current->next;
            }
            printf(" NULL\n");

        }
    }
}

int main() {
   hashMap map;
   initializeHashMap(&map);
   int choice, key, value;
   while (1) {
       printf("\nEnter your choice:\n");
       printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
       scanf("%d", &choice);
       switch (choice) {
           case 1:
               printf("Enter key: ");
               scanf("%d", &key);
               printf("Enter value: ");
               scanf("%d", &value);
               insertData(&map, key, value);
               break;
           case 2:
               printf("Enter key: ");
               scanf("%d", &key);
               value = search(&map, key);
               if (value == -1) {
                   printf("Key %d not found.\n", key);
               } else {
                   printf("Value: %d\n", value);
               }
               break;
           case 3:
               printf("Enter key: ");
               scanf("%d", &key);
               deleteData(&map, key);
               break;
           case 4:
               displayHashMap(&map);
               break;
           case 5:
               printf("Exiting program.\n");
               return 0;
           default:
               printf("Invalid choice! Please try again.\n");
       }
   }
}
