#include <iostream>

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
class doubly_linked_list
{
private:
    node *head;
    node *tail;
public:
doubly_linked_list()
      {
            head = NULL;
            tail = NULL;
      }
      void insert(int d)
      {
            node *new_node = new node(d);
            if (head == NULL)
            {
                  head = new_node;
                  tail = new_node;
            }
            else
            {
                  tail->next = new_node;
                  new_node->prev = tail;
                  tail = new_node;
            }
      }
      void display()
      {
            node *temp = head;
            while (temp != NULL)
            {
                  std::cout << temp->data << " ";
                  temp = temp->next;
            }
            std::cout << std::endl;
      }
      };

int main()
{
      doubly_linked_list dll;
      dll.insert(1);
      dll.insert(2);
      dll.insert(3);
      dll.display(); 
      return 0;
}