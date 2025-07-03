#include <iostream>
#include <cassert>
#include <cstdio>
using namespace std;

// Forward declarations (should match your doubly_linked_list.cpp)
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* insertEnd(Node* head, int value);
Node* insertFront(Node* head, int value);
Node* deleteNode(Node* head, int value);

// Helper function for testing
string listToString(Node* head) {
    string result;
    while (head != nullptr) {
        result += to_string(head->data) + " ";
        head = head->next;
    }
    result += "Null\n";
    return result;
}

int main() {
    Node* head = nullptr;

    // Insert values
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertFront(head, 5);

    // Display list after insertions
    printf("List after insertions: %s", listToString(head).c_str());

    // Delete a value
    head = deleteNode(head, 20);

    // Display list after deletion
    printf("List after deleting 20: %s", listToString(head).c_str());

    // Delete all values
    head = deleteNode(head, 5);
    head = deleteNode(head, 10);

    // Display list after all deletions
    printf("List after deleting all: %s", listToString(head).c_str());

    return 0;
}