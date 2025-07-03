#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* insertFront(Node* head, int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (head) head->prev = newNode;
    return newNode;
}

Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* deleteNode(Node* head, int value) {
    Node* temp = head;
    while (temp && temp->data != value) temp = temp->next;

    if (!temp) {
        printf("Value not found.\n");
        return head;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
    printf("Deleted.\n");
    return head;
}

void displayForward(Node* head) {
    Node* temp = head;
    printf("Forward: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;

    printf("Backward: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/*int main() {
    Node* head = nullptr;
    int choice, value;

    while (true) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Display forward\n");
        printf("5. Display backward\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        cin >> choice;

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                cin >> value;
                head = insertFront(head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                cin >> value;
                head = insertEnd(head, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                cin >> value;
                head = deleteNode(head, value);
                break;
            case 4:
                displayForward(head);
                break;
            case 5:
                displayBackward(head);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}*/
