#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};typedef struct Node Node;



void printLinkedList(Node* head) {
    Node* current = head;

    while (current->next) {
        printf("%d -> ", current->value);
        current = current->next;
    }
}


void createLinkedlist(Node* head, int n) {
    Node *current = head;
    int x;

    for (size_t i = 0; i < n; i++) {
        printf("Enter the value you want to insert : \n");
        scanf("%d", &x);
        current->value = x;
        current = current->next;
        printf("\n%d\n", i);
    }
    current->next = NULL;
    printf("head's next is: %d", head->next->value);
}


int main(int argc, char const *argv[]) {
    
    int n = 3;

    Node* head = (Node*)malloc(sizeof(Node));
    createLinkedlist(head, n);

    printLinkedList(head);
    
    
    
    return 0;
}
