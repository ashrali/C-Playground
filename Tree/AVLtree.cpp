#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    int height;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node *node) { retrun (node == nullptr) ?  0 : node->height; }

int getBalance(Node *node) { return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right); }

int max(int a, int b) { return (a > b) ? a : b; }

//LL
Node *rightRotate(Node *child)
{
    Node *parent = child->left;
    Node *T2 = parent->right;

    parent->right = child;
    child->left = T2;

    // Update
    child->height = max(getHeight(child->left), getHeight(child->right)) + 1;
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;

    return parent;
}

//RR
Node *leftRotate(Node *parent)
{
    Node *child = parent->right;
    Node *T2 = child->left;

    child->left = parent;
    parent->right = T2;

    // Update
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

    return child;
}

// Insert and Balance 
Node *insert(Node *node, int data)
{
    if (node == nullptr)
        return new Node(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else 
        return node;

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    //balance factor
    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;

    cout << "Node: " << node->data << "\n";
    if (node->left)
        cout << "  Left child: " << node->left->data << "\n";
    else
        cout << "  Left child: NULL\n";
    if (node->right)
        cout << "  Right child: " << node->right->data << "\n\n";
    else
        cout << "  Right child: NULL\n\n";

    display(node->left);
    display(node->right);
}

int main()
{
    Node *root = nullptr;
    int choice;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert node\n";
        cout << "2. Display tree\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int data;
            cout << "Enter data to insert: ";
            cin >> data;
            root = insert(root, data);
        }
        else if (choice == 2)
        {
            if (!root)
                cout << "Tree is empty.\n";
            else
                display(root);
        }
        else if (choice == 3)
        {
            cout << "Exiting the program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
