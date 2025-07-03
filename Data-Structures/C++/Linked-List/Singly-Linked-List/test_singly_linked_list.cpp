#include <iostream>
#include <cassert>
using namespace std;

// Forward declarations (or include your singly_linked_list.cpp here)
struct Node {
    int data;
    Node* next;
};

Node* insertEnd(Node* head, int value);
Node* insertBegin(Node* head, int value);
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

    // Test insert at end
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    assert(listToString(head) == "1 2 Null\n");

    // Test insert at beginning
    head = insertBegin(head, 0);
    assert(listToString(head) == "0 1 2 Null\n");

    // Test delete node
    head = deleteNode(head, 1);
    assert(listToString(head) == "0 2 Null\n");

    cout << "All test cases passed!" << endl;
    return 0;
}