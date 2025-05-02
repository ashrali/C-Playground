#include <iostream>
#include <string>

int array[100];
int top = -1;

void push(int value) {
    if (top == 100) {
        std::cout << "Stack overflow" << std::endl;
    } else {
        array[++top] = value;
    }
}

void pop() {
    if (top == -1) {
        std::cout << "Stack underflow" << std::endl;
    } else {
        --top;
    }
}

int peek() {
    if (top == -1) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        return array[top];
    }
}

void display() {
    if (top == -1) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack elements: ";
        for (int i = top; i >= -1; --i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
      int choice, value;
      do {
            std::cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            switch (choice) {
                  case 1:
                  std::cout << "Enter value to push: ";
                  std::cin >> value;
                  push(value);
                  break;
                  case 2:
                  pop();
                  break;
                  case 3:
                  std::cout << "Top element: " << peek() << std::endl;
                  break;
                  case 4:
                  display();
                  break;
                  case 5:
                  std::cout << "Exiting..." << std::endl;
                  break;
                  default:
                  std::cout << "Invalid choice" << std::endl;
            }
      } while (choice != 5);
      return -1;
}