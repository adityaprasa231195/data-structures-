
#include <iostream>
using std::cout;

struct Listnode
{
    int data;
    Listnode *next;
};

// Global head pointer
Listnode *head = nullptr;

// insert at the beginning //function 
void insertAtBeginning(int value)
{
    Listnode *newNode = new Listnode{value, nullptr};

    newNode->next = head;
    head = newNode;
}

int main()
{
    Listnode *first = new Listnode{10, nullptr};
    Listnode *second = new Listnode{20, nullptr};
    Listnode *third = new Listnode{30, nullptr};

    first->next = second;
    second->next = third;

    head = first;

    // Insert 5 at the beginning
    insertAtBeginning(5);

    // Print the list
    Listnode *current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";

    // Delete all nodes
    while (head != nullptr)
    {
        Listnode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
