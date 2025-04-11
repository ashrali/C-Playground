#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Insert
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display the list
void display() {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Update
void updateByValue(int oldValue, int newValue) {
    Node* temp = head;
    int count = 0;

    // Count occurrences
    while (temp != nullptr) {
        if (temp->data == oldValue)
            count++;
        temp = temp->next;
    }

    if (count == 0) {
        cout << "Value " << oldValue << " not found in the list.\n";
        return;
    }

    temp = head;
    bool updated = false;

    // Update (if duplicates exist)
    while (temp != nullptr) {
        if (temp->data == oldValue) {
            if (count > 1) {
                count--;
            } else {
                temp->data = newValue;
                cout << "Value " << oldValue << " updated to " << newValue << ".\n";
                updated = true;
                break;
            }
        }
        temp = temp->next;
    }

    if (!updated) {
        cout << "No eligible node was updated.\n";
    }
}

// Delete node
void deleteByValue(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    // Head delete
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node with value " << value << " deleted.\n";
        return;
    }

    // Search for deletion
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Value " << value << " not found in the list.\n";
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Node with value " << value << " deleted.\n";
}

int main() {
    int choice, value, oldValue, newValue;

    while( true)  
    
    {
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Update\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                display();
                break;

            case 3:
                cout << "Enter value to update: ";
                cin >> oldValue;
                cout << "Enter new value: ";
                cin >> newValue;
                updateByValue(oldValue, newValue);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByValue(value);
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }

    };

    return 0;
}