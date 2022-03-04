#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};typedef struct Node Node;

Node* head;


void enterLinkedListSize(int* n) {
    do {
        printf("Enter linked list size: \n");
        scanf("%d", n);
    } while (*n > 10);
}


void printLinkedList() {
    Node* current = head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}


void createLinkedList(int n) {
    int x;
    head = malloc(sizeof(Node));
    printf("Enter value: \n");
    scanf("%d", &x);
    head->value = x;
    head->next = NULL;
    Node* temp1 = head;
    for (size_t i = 1; i < n; i++) {
        Node* temp2 = malloc(sizeof(Node));
        temp1->next = temp2;
        printf("Enter value: \n");
        scanf("%d", &x);
        temp2->value = x;
        temp2->next = NULL;
        temp1 = temp2;
    }

}




// cd "c:\Users\farou\OneDrive\Bureau\Programming\leetcode\" && gcc practice.c -o practice && "c:\Users\farou\OneDrive\Bureau\Programming\leetcode\"practice



void countLinkedListElements() {
    Node* current = head;

    int length = 0;

    while (current) {
        length++;
        current = current->next;
    }

    printf("The length of the entered Linked List is : %d\n", length);
    
}


void countOccurrencesLinkedList(int value) {
    int occurrences = 0;
    Node* current = head;

    while (current) {
        if (current->value == value) {
            occurrences++;
        }
        current = current->next;
    }

    printf("The number of occurrences of %d is : %d\n", value, occurrences);
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

void deleteLinkedListElement(int value) {
    Node* current = head;
    int deleteIndex = getIndexOfNode(value);

    if (deleteIndex == -1) {
        return;
    } else if (deleteIndex == 0) {
        head = current->next;
        free(current);
        return;
    }

    for (size_t i = 0; i < deleteIndex - 1; i++) {
        current = current->next;
    }
    Node* current1 = current->next;
    current->next = current1->next;
    free(current1);
}


void insertLinkedList(int value) {
    Node* current = head;
    Node* prev = NULL;
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;

    if (current->value >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }
    while (current) {
        prev = current;
        current = current->next;
        if (current && current->value >= value && prev->value <= value) {
            prev->next = newNode;
            newNode->next = current;
            return;
        }
    }
    prev->next = newNode;
    newNode->next = NULL;
}


void reverseLinkedList() {
    Node* current = head;
    Node* previous = NULL;
    
    while (current) {
        Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

int main() {
    int n;
    
    enterLinkedListSize(&n);

    createLinkedList(n);

    printLinkedList();

    countLinkedListElements();

    countOccurrencesLinkedList(69);

    deleteLinkedListElement(69);

    printf("\nLinked List after deleting element: \n");
    printLinkedList();

    printf("\nLinked List after inserting element: \n");
    insertLinkedList(4);
    printLinkedList();

    printf("\nLinked List after getting reversed: \n");
    reverseLinkedList();
    printLinkedList();
    
    return 0;
}