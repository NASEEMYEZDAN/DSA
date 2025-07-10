#include <stdio.h>
#include <stdlib.h>

// Forward declarations (should match your circular_linked_list.cpp)
struct Node {
    int data;
    Node* next;
};

Node* insertEnd(Node* head, int value);
Node* deleteNode(Node* head, int value);

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert positive values
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    // Insert negative values
    head = insertEnd(head, -5);
    head = insertEnd(head, -15);

    printf("Circular Linked List after insertions: ");
    display(head);

    // Delete a positive value
    head = deleteNode(head, 20);
    printf("After deleting 20: ");
    display(head);

    // Delete a negative value
    head = deleteNode(head, -5);
    printf("After deleting -5: ");
    display(head);

    // Delete all values
    head = deleteNode(head, -45);
    head = deleteNode(head, -12);
    head = deleteNode(head, 15);

    printf("After deleting all: ");
    display(head);

    return 0;
}