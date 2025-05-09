#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void addNodes(Node* node) {
    char choice;

    std::cout << "Do you want to add a left child to node " << node->data << "? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        int leftValue;
        std::cout << "Enter value for left child: ";
        std::cin >> leftValue;
        node->left = createNode(leftValue);
        addNodes(node->left);
    }

    std::cout << "Do you want to add a right child to node " << node->data << "? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        int rightValue;
        std::cout << "Enter value for right child: ";
        std::cin >> rightValue;
        node->right = createNode(rightValue);
        addNodes(node->right);
    }
}

void printTree(Node* node) {
    if (node == nullptr) return;

    std::cout << "Node: " << node->data << std::endl;
    if (node->left != nullptr) {
        std::cout << "  Left child: " << node->left->data << std::endl;
    }
    if (node->right != nullptr) {
        std::cout << "  Right child: " << node->right->data << std::endl;
    }

    printTree(node->left);
    printTree(node->right);
}

bool updateNodeValues(Node* node, int oldValue, int newValue) {
    if (node == nullptr) return false;

    if (node->data == oldValue) {
        node->data = newValue;
        return true;
    }

    if (updateNodeValues(node->left, oldValue, newValue)) 
    return true;
    if (updateNodeValues(node->right, oldValue, newValue))
     return true;

    return false; 
}

int main() {
    int rootValue;
    std::cout << "Enter value for root node: ";
    std::cin >> rootValue;

    Node* root = createNode(rootValue);
    addNodes(root);

    std::cout << "\nInitial Tree:\n";
    printTree(root);

    char choice;
    do {
        int oldVal, newVal;
        std::cout << "\nDo you want to update a node value? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            std::cout << "Enter value to search and update: ";
            std::cin >> oldVal;
            std::cout << "Enter new value: ";
            std::cin >> newVal;

            if (updateNodeValues(root, oldVal, newVal)) {
                std::cout << "Value updated successfully.\n";
            } else {
                std::cout << "Value not found in the tree.\n";
            }

            std::cout << "\nUpdated Tree:\n";
            printTree(root);
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}