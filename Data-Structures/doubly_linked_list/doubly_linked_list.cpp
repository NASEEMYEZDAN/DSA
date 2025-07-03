#include <iostream>
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
        cout << "Value not found.\n";
        return head;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Deleted.\n";
    return head;
}

void displayForward(Node* head) {
    Node* temp = head;
    cout << "Forward: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayBackward(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;

    cout << "Backward: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

/*int main() {
    Node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete a node\n";
        cout << "4. Display forward\n";
        cout << "5. Display backward\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                head = insertFront(head, value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                head = insertEnd(head, value);
                break;
            case 3:
                cout << "Enter value to delete: ";
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
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}*/
