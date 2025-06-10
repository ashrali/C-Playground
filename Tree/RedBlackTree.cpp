#include <iostream>
using namespace std;

struct Node {
    int value;
    char color;
    Node *left, *right, *parent;
    Node(int val) : value(val), color('R'), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
    Node* root = nullptr;

    void rotateLeft(Node*& currentNode) {
        Node* rightChild = currentNode->right;
        currentNode->right = rightChild->left;
        if (rightChild->left)
            rightChild->left->parent = currentNode;
        rightChild->parent = currentNode->parent;

        if (!currentNode->parent)
            root = rightChild;
        else if (currentNode == currentNode->parent->left)
            currentNode->parent->left = rightChild;
        else
            currentNode->parent->right = rightChild;

        rightChild->left = currentNode;
        currentNode->parent = rightChild;
    }

    void rotateRight(Node*& currentNode) {
        Node* leftChild = currentNode->left;
        currentNode->left = leftChild->right;
        if (leftChild->right)
            leftChild->right->parent = currentNode;
        leftChild->parent = currentNode->parent;

        if (!currentNode->parent)
            root = leftChild;
        else if (currentNode == currentNode->parent->right)
            currentNode->parent->right = leftChild;
        else
            currentNode->parent->left = leftChild;

        leftChild->right = currentNode;
        currentNode->parent = leftChild;
    }

    void fixAfterInsert(Node*& insertedNode) {
        while (insertedNode != root && insertedNode->parent->color == 'R') {
            Node* parentNode = insertedNode->parent;
            Node* grandparentNode = parentNode->parent;

            bool isParentLeftChild = false;
            if (parentNode == grandparentNode->left)
                isParentLeftChild = true;
            else
                isParentLeftChild = false;

            Node* uncleNode;
            if (isParentLeftChild)
                uncleNode = grandparentNode->right;
            else
                uncleNode = grandparentNode->left;

            if (uncleNode && uncleNode->color == 'R') {
                parentNode->color = uncleNode->color = 'B';
                grandparentNode->color = 'R';
                insertedNode = grandparentNode;
            } else {
                bool isInsertedNodeOppositeChild = false;
                if (isParentLeftChild) {
                    if (insertedNode == parentNode->right)
                        isInsertedNodeOppositeChild = true;
                } else {
                    if (insertedNode == parentNode->left)
                        isInsertedNodeOppositeChild = true;
                }

                if (isInsertedNodeOppositeChild) {
                    if (isParentLeftChild)
                        rotateLeft(parentNode);
                    else
                        rotateRight(parentNode);
                    insertedNode = parentNode;
                    parentNode = insertedNode->parent;
                }

                if (isParentLeftChild)
                    rotateRight(grandparentNode);
                else
                    rotateLeft(grandparentNode);

                swap(parentNode->color, grandparentNode->color);
                insertedNode = parentNode;
            }
        }
        root->color = 'B';
    }

    void printNodes(Node* currentNode) {
        if (!currentNode)
            return;

        string position;
        if (currentNode == root)
            position = "Root";
        else if (currentNode == currentNode->parent->left)
            position = "Left";
        else
            position = "Right";

        cout << "Node: " << currentNode->value << currentNode->color
             << ", Position: " << position
             << ", Parent: ";
        if (currentNode->parent)
            cout << currentNode->parent->value;
        else
            cout << "None";
        cout << '\n';

        printNodes(currentNode->left);
        printNodes(currentNode->right);
    }

    Node* search(Node* currentNode, int value) {
        while (currentNode) {
            if (value == currentNode->value)
                return currentNode;
            else if (value < currentNode->value)
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
        }
        return nullptr;
    }

    Node* minimum(Node* currentNode) {
        while (currentNode->left)
            currentNode = currentNode->left;
        return currentNode;
    }

    void transplant(Node* targetNode, Node* replacementNode) {
        if (!targetNode->parent)
            root = replacementNode;
        else if (targetNode == targetNode->parent->left)
            targetNode->parent->left = replacementNode;
        else
            targetNode->parent->right = replacementNode;

        if (replacementNode)
            replacementNode->parent = targetNode->parent;
    }

    void fixAfterDelete(Node* currentNode) {
        while (currentNode != root && (!currentNode || currentNode->color == 'B')) {
            if (currentNode == currentNode->parent->left) {
                Node* sibling = currentNode->parent->right;

                if (sibling->color == 'R') {
                    sibling->color = 'B';
                    currentNode->parent->color = 'R';
                    rotateLeft(currentNode->parent);
                    sibling = currentNode->parent->right;
                }

                if ((!sibling->left || sibling->left->color == 'B') &&
                    (!sibling->right || sibling->right->color == 'B')) {
                    sibling->color = 'R';
                    currentNode = currentNode->parent;
                } else {
                    if (!sibling->right || sibling->right->color == 'B') {
                        if (sibling->left)
                            sibling->left->color = 'B';
                        sibling->color = 'R';
                        rotateRight(sibling);
                        sibling = currentNode->parent->right;
                    }

                    sibling->color = currentNode->parent->color;
                    currentNode->parent->color = 'B';
                    if (sibling->right)
                        sibling->right->color = 'B';
                    rotateLeft(currentNode->parent);
                    currentNode = root;
                }
            } else {
                Node* sibling = currentNode->parent->left;

                if (sibling->color == 'R') {
                    sibling->color = 'B';
                    currentNode->parent->color = 'R';
                    rotateRight(currentNode->parent);
                    sibling = currentNode->parent->left;
                }

                if ((!sibling->left || sibling->left->color == 'B') &&
                    (!sibling->right || sibling->right->color == 'B')) {
                    sibling->color = 'R';
                    currentNode = currentNode->parent;
                } else {
                    if (!sibling->left || sibling->left->color == 'B') {
                        if (sibling->right)
                            sibling->right->color = 'B';
                        sibling->color = 'R';
                        rotateLeft(sibling);
                        sibling = currentNode->parent->left;
                    }

                    sibling->color = currentNode->parent->color;
                    currentNode->parent->color = 'B';
                    if (sibling->left)
                        sibling->left->color = 'B';
                    rotateRight(currentNode->parent);
                    currentNode = root;
                }
            }
        }

        if (currentNode)
            currentNode->color = 'B';
    }

public:
    void insert(int value) {
        Node* newNode = new Node(value);
        Node* parentNode = nullptr;
        Node* currentNode = root;

        while (currentNode) {
            parentNode = currentNode;
            if (value < currentNode->value)
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
        }

        newNode->parent = parentNode;
        if (!parentNode)
            root = newNode;
        else if (value < parentNode->value)
            parentNode->left = newNode;
        else
            parentNode->right = newNode;

        fixAfterInsert(newNode);
    }

    void deleteValue(int value) {
        Node* nodeToDelete = search(root, value);
        if (!nodeToDelete) {
            cout << "Value " << value << " not found in tree.\n";
            return;
        }

        Node* nodeToMove = nodeToDelete;
        char originalColor = nodeToMove->color;

        Node* replacementChild = nullptr;

        if (!nodeToDelete->left) {
            replacementChild = nodeToDelete->right;
            transplant(nodeToDelete, nodeToDelete->right);
        } else if (!nodeToDelete->right) {
            replacementChild = nodeToDelete->left;
            transplant(nodeToDelete, nodeToDelete->left);
        } else {
            Node* successor = minimum(nodeToDelete->right);
            originalColor = successor->color;
            replacementChild = successor->right;

            if (successor->parent == nodeToDelete) {
                if (replacementChild)
                    replacementChild->parent = successor;
            } else {
                transplant(successor, successor->right);
                successor->right = nodeToDelete->right;
                successor->right->parent = successor;
            }

            transplant(nodeToDelete, successor);
            successor->left = nodeToDelete->left;
            successor->left->parent = successor;
            successor->color = nodeToDelete->color;
        }

        delete nodeToDelete;

        if (originalColor == 'B' && replacementChild != nullptr)
            fixAfterDelete(replacementChild);

        if (!root)
            cout << "Tree is now empty.\n";
    }

    void printTree() {
        cout << "\nFlat Red-Black Tree Listing:\n";
        if (root)
            printNodes(root);
        else
            cout << "Tree is empty.\n";
    }

    char getRootColor() {
        if (root)
            return root->color;
        else
            return '-';
    }
};

int main() {
    RedBlackTree tree;
    string input;

    cout << "=== Red-Black Tree Insertion & Deletion Program ===\n";

    while (true) {
        cout << "\nEnter value to insert, 'D' to delete, or 'S' to stop: ";
        cin >> input;

        if (input == "S" || input == "s")
            break;

        if (input == "D" || input == "d") {
            int valueToDelete;
            cin >> valueToDelete;
            tree.deleteValue(valueToDelete);
            tree.printTree();
            continue;
        }

        bool isValid = true;
        int startIndex = 0;
        if (input[0] == '-')
            startIndex = 1;

        for (int i = startIndex; i < input.size(); ++i) {
            if (!isdigit(input[i]))
                isValid = false;
        }

        if (!isValid) {
            cout << "Invalid input. Please enter an integer or 'S' to stop.\n";
            continue;
        }

        int value = 0;
        int sign = 1;
        if (input[0] == '-')
            sign = -1;

        for (int i = startIndex; i < input.size(); ++i) {
            value = value * 10 + (input[i] - '0');
        }
        value *= sign;

        tree.insert(value);
        tree.printTree();
    }

    cout << "\nFinal Tree Structure:\n";
    tree.printTree();
    return 0;
}