#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};typedef struct Node Node;

Node* head;

void inputArraySize(int* n) {
    do {
        printf("Enter the linked list size: \n");
        scanf("%d", n);
    } while (*n > 10);
}

void createLinkedList(int n) {
    int x;
    Node* temp = malloc(sizeof(Node));
    printf("Enter value: \n");
    scanf("%d", &x);
    temp->value = x;
    temp->next = NULL;
    head = temp;
    for (size_t i = 1; i < n; i++) {
        Node* temp2 = malloc(sizeof(Node));
        temp->next = temp2;
        printf("Enter value: \n");
        scanf("%d", &x);
        temp2->value = x;
        temp2->next = NULL;
        temp = temp2;
    }
    
}

void printLinkedList() {
    Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("NULL");
}

void countLengthLinkedList() {
    int length = 0;
    Node* current = head;

    while (current) {
        length++;
        current = current->next;
    }

    printf("\nThe length of the Linked List is : %d\n", length);
    
}

void countOccurencesLinkedList(int value) {
    int occurrences = 0;
    Node* current = head;

    while (current) {
        if (current->value == value) {
            occurrences++;
        }
        current = current->next;
    }
    printf("\nThe number of occurences of the Linked List : %d\n", occurrences);
}

int getIndexOfNode(int value) {
    Node* current = head;
    int index = 0;

    while (current) {
        if (current->value == value) {
            return index;
        }
        index++, current = current->next;
    }
    return -1;
}

void deleteElementLinkedList(int value) {
    Node* current = head;
    int deleteIndex = getIndexOfNode(value);
    int index = 0;

    for (size_t i = 0; i < deleteIndex - 1; i++) {
        current = current->next;
    }

    Node* current1 = current->next;
    current->next = current1->next;
    free(current1);
    
}

int main() {

    int n;

    inputArraySize(&n);

    createLinkedList(n);
    
    printLinkedList();

    countLengthLinkedList();

    countOccurencesLinkedList(3);

    deleteElementLinkedList(3);
        
    printLinkedList();
    
    return 0;
}