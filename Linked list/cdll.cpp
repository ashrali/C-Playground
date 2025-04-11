#include <iostream>

class node {
public:
    int data;
    node *next;
    node *prev;

    node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

class doubly_circular_linked_list {
private:
    node *head;

public:
    doubly_circular_linked_list() {
        head = nullptr;
    }

    void insert(int d) {
        node *new_node = new node(d);

        if (head == nullptr) {
            head = new_node;
            head->next = head;
            head->prev = head;
        } else {
            node *tail = head->prev;
            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = head;
            head->prev = new_node;
        }
    }

    void display() {
        if (head == nullptr) {
            std::cout << "The list is empty!" << std::endl;
            return;
        }

        node *temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    void delete_node(int d) {
        if (head == nullptr) {
            std::cout << "The list is empty!" << std::endl;
            return;
        }

        node *curr = head;

        do {
            if (curr->data == d) {
                if (curr->next == curr && curr->prev == curr) {
                    delete curr;
                    head = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;

                    if (curr == head)
                        head = curr->next;

                    delete curr;
                }

                std::cout << "Node with value " << d << " deleted." << std::endl;
                return;
            }
            curr = curr->next;
        } while (curr != head);

        std::cout << "Node with value " << d << " not found!" << std::endl;
    }

    void update_node(int old_value, int new_value) {
        if (head == nullptr) {
            std::cout << "The list is empty!" << std::endl;
            return;
        }

        node *temp = head;
        do {
            if (temp->data == old_value) {
                temp->data = new_value;
                std::cout << "Node updated from " << old_value << " to " << new_value << "." << std::endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        std::cout << "Node with value " << old_value << " not found!" << std::endl;
    }
};
int main()
{
      doubly_circular_linked_list dll;
      int choice, value, old_value, new_value;

      while (true)
      {
            std::cout << "\nMenu:\n";
            std::cout << "1. Insert node\n";
            std::cout << "2. Display list\n";
            std::cout << "3. Delete node\n";
            std::cout << "4. Update node\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                  std::cout << "Enter value to insert: ";
                  std::cin >> value;
                  dll.insert(value);
                  break;

            case 2:
                  dll.display();
                  break;

            case 3:
                  std::cout << "Enter value to delete: ";
                  std::cin >> value;
                  dll.delete_node(value);
                  break;

            case 4:
                  std::cout << "Enter value to update: ";
                  std::cin >> old_value;
                  std::cout << "Enter new value: ";
                  std::cin >> new_value;
                  dll.update_node(old_value, new_value);
                  break;

            case 5:
                  std::cout << "Exiting program...\n";
                  return 0;

            default:
                  std::cout << "Invalid choice! Please try again.\n";
            }
      }

      return 0;
}