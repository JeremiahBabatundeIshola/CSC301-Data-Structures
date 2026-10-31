
#include <iostream>
using namespace std;

// Define the structure of a node.
struct Node {
    int data;
    Node* next;
};

// Insert a new node at the beginning of the list.
void insertAtBeginning(Node*& head, int value) {
    // Create a new node and store the value.
    Node* newNode = new Node;
    newNode->data = value;

    // Connect the new node to the current first node.
    newNode->next = head;

    // Make the new node the first node.
    head = newNode;
}

// Display all nodes in the list.
void displayList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}


void insertAtEnd(Node*& head, int value) {
    // Create a new node.
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;



    // If the list is empty, make this node the head.
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Find the last node.
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    // Attach the new node at the end.
    current->next = newNode;
}

void insertAtPosition(Node*& head, int value, int position) {
    // Position must be 1 or greater.
    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    // Position 1 means insertion at the beginning.
    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    // Find the node immediately before the target position.
    Node* current = head;

    for (int i = 1; i < position - 1; i++) {
        if (current == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        current = current->next;
    }

    // Check whether the position is beyond the list.
    if (current == nullptr) {
        cout << "Invalid position." << endl;
        return;
    }

    // Create and connect the new node.
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
}


void deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "Cannot delete: list is empty." << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Value deleted." << endl;
        return;
    }

    Node* current = head;

    while (current->next != nullptr &&
           current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Value not found." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    cout << "Value deleted." << endl;
}


void deleteByPosition(Node*& head, int position) {
    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    if (head == nullptr) {
        cout << "Cannot delete: list is empty." << endl;
        return;
    }

    // Delete the first node if position is 1.
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted." << endl;
        return;
    }

    // Find the node before the target position.
    Node* current = head;

    for (int i = 1; i < position - 1; i++) {
        if (current == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }
        current = current->next;
    }

    // Check that the target node exists.
    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position." << endl;
        return;
    }

    // Remove the target node.
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    cout << "Node deleted." << endl;
}



int main() {
    Node* head = nullptr;
    int count, value;

    cout << "How many numbers do you want to insert? ";
    cin >> count;

    if (count < 0) {
        cout << "Invalid number of nodes." << endl;
        return 0;
    }

    // Read values and insert them at the end.
    for (int i = 0; i < count; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    // Display the original list.
    cout << "Original list: ";
    displayList(head);

    // Test insertion at the beginning.
    cout << "Enter a value to insert at the beginning: ";
    cin >> value;
    insertAtBeginning(head, value);

    cout << "After insertion at beginning: ";
    displayList(head);

    // Test insertion at the end.
    cout << "Enter a value to insert at the end: ";
    cin >> value;
    insertAtEnd(head, value);

    cout << "After insertion at end: ";
    displayList(head);

    // Test insertion at a specified position.
int position;

    cout << "Enter a value to insert in the middle: ";
    cin >> value;

    cout << "Enter the position for insertion: ";
    cin >> position;

        insertAtPosition(head, value, position);

    cout << "After insertion at position: ";
    displayList(head);

    // Test deletion by value.
    cout << "Enter a value to delete: ";
    cin >> value;
    deleteByValue(head, value);

    cout << "After deletion: ";
    displayList(head);

    // Test deletion by position.
    cout << "Enter the position to delete: ";
    cin >> position;

    deleteByPosition(head, position);

    cout << "After deleting position: ";
    displayList(head);

    // Test deletion from an empty list.
    Node* emptyList = nullptr;

    cout << "Testing empty list deletion:" << endl;
    deleteByValue(emptyList, 10);
    deleteByPosition(emptyList, 1);

    return 0;
}




