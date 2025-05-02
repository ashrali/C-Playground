#include <iostream>
#include <string>
#include <queue>

using namespace std;


struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;
int queueSize = 0; // Tracks the current size of the queue
const int maxSize = 100; // Maximum size of the queue

void enqueue(int value) {
    if (queueSize == maxSize) {
        cout << "Queue is full" << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    queueSize++;
}

void dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = front;
    cout << "Dequeued element: " << front->data << endl;
    front = front->next;
    delete temp; // Free memory
    queueSize--;
    if (front == nullptr) {
        rear = nullptr; // Queue is empty
    }
}

void display() {
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    return 0;
}