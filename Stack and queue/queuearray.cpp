#include <iostream>
#include <string>
#include <queue>

int arr[100];
int front = -1;
int rear = -1;
int size = 100;

int main() {
    int choice, value;
    do {
        std::cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                if ((rear + 1) % size == front) {
                    std::cout << "Queue is full" << std::endl;
                } else {
                    std::cout << "Enter value to enqueue: ";
                    std::cin >> value;
                    rear = (rear + 1) % size;
                    arr[rear] = value;
                    if (front == -1) {
                        front = 0;
                    }
                }
                  break;
                  case 2:
                  if (front == -1) {
                        std::cout << "Queue is empty" << std::endl;
                  } else {
                        std::cout << "Dequeued element: " << arr[front] << std::endl;
                        if (front == rear) {
                              front = rear = -1; // Queue is empty
                        } else {
                              front = (front + 1) % size;
                        }
                  }
                  break;
                  case 3:
                  if (front == -1) {
                        std::cout << "Queue is empty" << std::endl;
                  } else {
                        std::cout << "Queue elements: ";
                        for (int i = front; i != rear; i = (i + 1) % size) {
                              std::cout << arr[i] << " ";
                        }
                        std::cout << arr[rear] << std::endl; // Print the last element
                  }
                  break;
                  case 4:
                  std::cout << "Exiting..." << std::endl;
                  break;
                  default:
                  std::cout << "Invalid choice" << std::endl;
            }
      } while (choice != 4);
      return 0;
      }