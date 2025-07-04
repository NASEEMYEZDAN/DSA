#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
};

Node* insertEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* deleteNode(Node* head, int value) {
    if (head == NULL)
        return NULL;

    Node* curr = head;
    Node* prev = NULL;

    if (head->data == value) {
        if (head->next == head) {
            free(head);
            return NULL;
        }
        while (curr->next != head)
            curr = curr->next;
        curr->next = head->next;
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    prev = head;
    curr = head->next;

    while (curr != head && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        printf("Value not found\n");
        return head;
    }

    prev->next = curr->next;
    free(curr);
    return head;
}

/*void display(Node* head) {
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
}*/

/*int main() {
    Node* head = NULL;
    int n, val;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    printf("Circular Linked List: ");
    display(head);

    printf("Enter value to delete: ");
    scanf("%d", &val);
    head = deleteNode(head, val);

    printf("After deletion: ");
    display(head);

    return 0;
}*/
