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

    if (head == nullptr) {
        head = newNode;
        newNode->next = head; // (circular)
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}

void updateByValue(int oldValue, int newValue) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    Node* target = nullptr;

    do {
        if (temp->data == oldValue)
            target = temp; // update last match
        temp = temp->next;
    } while (temp != head);

    if (target == nullptr) {
        cout << "Value " << oldValue << " not found in the list.\n";
    } else {
        target->data = newValue;
        cout << "Value " << oldValue << " updated to " << newValue << ".\n";
    }
}

// Delete node
void deleteByValue(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    //  deleting head
    if (head->data == value) {
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            // Find last node
            Node* last = head;
            while (last->next != head)
                last = last->next;

            Node* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
        }
        cout << "Node with value " << value << " deleted.\n";
        return;
    }

    // Deleting non-head node
    do {
        prev = current;
        current = current->next;
        if (current->data == value) {
            prev->next = current->next;
            delete current;
            cout << "Node with value " << value << " deleted.\n";
            return;
        }
    } while (current != head);

    cout << "Value " << value << " not found in the list.\n";
}

int main() {
    int choice, value, oldValue, newValue;

    while (true) {
        cout << "\nMenu:\n";
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
    }

    return 0;
}
