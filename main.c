#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};typedef struct Node Node;

Node* head;


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


void inputArraySize(int* n) {
    do {
        printf("Enter the Linked List size: \n");
        scanf("%d", n);
    } while (*n > 6);
}


int main() {
    // Node* head = malloc(sizeof(Node));
    // Node* second = malloc(sizeof(Node));
    // Node* third = malloc(sizeof(Node));

    // head->value = 69;
    // second->value = 79;
    // third->value = 89;

    // head->next = second;
    // second->next = third;
    // third->next = NULL;
    int n;

    inputArraySize(&n);

    printf("n = %d", n);
    
    createLinkedList(n);

    printLinkedList();

    
    return 0;
}