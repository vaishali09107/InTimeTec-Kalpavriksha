#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertData(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printLL(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void bubbleSort(struct Node* head) {
    struct Node *i, *j;
    int num;
    for(i = head; i != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            if(i->data > j->data) {
                num = i->data;
                i->data = j->data;
                j->data = num;
            }
        }
    }
}

int lengthLL(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

float median(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head->next->next;
    int len = lengthLL(head);
    float med = 0.0;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (len % 2 != 0) {
        med = slow->data;
    } else {
        med = (slow->data + slow->next->data) / 2.0;
    }

    return med;
}

void subtractMedianFromOddPositions(struct Node* head, float med) {
    struct Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (position % 2 != 0) {
            int result = temp->data - (int)med;
            if (result < 0) {
                temp->data = 0;
            } else {
                temp->data = result;
            }
        }
        temp = temp->next;
        position++;
    }
}
void printCipher(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        char ch = 'a' + temp->data;  
        printf("%c", ch);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertData(&head, 1);
    insertData(&head, 2);
    insertData(&head, 3);
    insertData(&head, 4);
    insertData(&head, 5);
    insertData(&head, 6);

    printf("Original List: ");
    printLL(head);

    bubbleSort(head);
    printf("After sorting: ");
    printLL(head);

    float med = median(head);
    printf("Median: %.2f\n", med);

    subtractMedianFromOddPositions(head, med);
    printf("After subtracting the median from odd positions (positive values): ");
    printLL(head);
    
    printf("Cipher : \n");
    printCipher(head);

    return 0;
}
