#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};


Node* insertEnd(Node *head, int value)
{
    Node *newNode= new Node;
    newNode->data=value;
    newNode->next=nullptr;
    if(head==nullptr)
    {
        return newNode;
    }
    Node *temp=head;
    while(temp->next!=nullptr)
        temp=temp->next;
    temp->next=newNode;
    return head;
}


Node *insertBegin(Node *head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    return newNode;
}


Node *deleteNode(Node *head, int value)
{
    if(head==nullptr)
        return nullptr;
    if(head->data==value)
    {
        Node *temp=head->next;
        delete head;
        return temp;
    }
    Node *temp=head;
    while(temp->next!=nullptr && temp->next->data!=value)
        temp=temp->next;
    if(temp->next==nullptr)
        return head; 
    Node *toDelete=temp->next;
    temp->next=toDelete->next;
    delete toDelete;
    return head;
}


void displayList(Node *head)
{
    if (head== nullptr)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }
    while(head!=nullptr)
    {
        std::cout << head->data << " ";
        head=head->next;
    }
    cout<< "Null\n";
}


/*
int main()
{
    Node *head=nullptr;
    int choice, value;
    do
    {
        cout<<"1. Insert at End\n";
        cout<<"2. Insert at Beginning\n";
        cout<<"3. Delete Node\n";
        cout<<"4. Display List\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";  
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter value to insert at end: ";
                cin>>value;
                head = insertEnd(head, value);
                break;
            case 2:
                cout<<"Enter value to insert at beginning: ";
                cin>>value;
                head = insertBegin(head, value);
                break;
            case 3:
                cout<<"Enter value to delete: ";
                cin>>value;
                head = deleteNode(head, value);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }     
    } while(choice != 5);
    return 0;
}
*/

