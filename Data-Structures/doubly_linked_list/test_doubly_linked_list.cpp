#include <iostream>
#include <cassert>
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
    cout << "List after insertions: " << listToString(head);

    // Delete a value
    head = deleteNode(head, 20);

    // Display list after deletion
    cout << "List after deleting 20: " << listToString(head);

    // Delete all values
    head = deleteNode(head, 5);
    head = deleteNode(head, 10);

    // Display list after all deletions
    cout << "List after deleting all: " << listToString(head);

    return 0;
}