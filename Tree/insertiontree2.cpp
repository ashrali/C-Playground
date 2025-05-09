#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* node, int data) {
    if (node == nullptr)
        return new Node(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data >= node->data)
        node->right = insert(node->right, data);
    return node;
}

void display(Node* node) {
    if (node == nullptr) return;

    cout << "Node: " << node->data << "\n";

    cout << "  Left child: ";
    if (node->left)
        cout << node->left->data << "\n";
    else
        cout << "NULL\n";

    cout << "  Right child: ";
    if (node->right)
        cout << node->right->data << "\n";
    else
        cout << "NULL\n";

    cout << endl;

    display(node->left);
    display(node->right);
}

int main() {
    Node* root = nullptr;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert node\n";
        cout << "2. Display tree\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int data;
            cout << "Enter data to insert: ";
            cin >> data;
            root = insert(root, data);
        }
        else if (choice == 2) {
            if (!root)
                cout << "Tree is empty.\n";
            else
                display(root);
        }
        else if (choice == 3) {
            cout << "Exiting the program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}