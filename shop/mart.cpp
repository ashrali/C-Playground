#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 100; 

class Product {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Product() : id(0), name(""), price(0.0), quantity(0) {} 
    
    Product(int productId, string productName, double productPrice, int productQuantity) {
        id = productId;
        name = productName;
        price = productPrice;
        quantity = productQuantity;
    }

    // Getter methods
    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void reduceQuantity(int amount) {
        if(quantity >= amount) {
            quantity -= amount;
        }
    }
};

class Mart {
private:
    Product products[MAX_PRODUCTS];
    int productCount;

public:
    Mart() : productCount(0) {}

    void addProduct(Product p) {
        if(productCount < MAX_PRODUCTS) {
            products[productCount] = p;
            productCount++;
            cout << "Product added successfully!\n";
        } else {
            cout << "Error: Maximum product limit reached!\n";
        }
    }

    void displayProducts() const {
        cout << "\nAvailable Products (" << productCount << "/" << MAX_PRODUCTS << "):\n";
        cout << "----------------------------------------\n";
        for(int i = 0; i < productCount; i++) {
            cout << "ID: " << products[i].getId() 
                 << " | Name: " << products[i].getName() 
                 << " | Price: $" << products[i].getPrice() 
                 << " | Quantity: " << products[i].getQuantity() << endl;
        }
        cout << "----------------------------------------\n";
    }

    void sellProduct(int productId, int quantity) {
        for(int i = 0; i < productCount; i++) {
            if(products[i].getId() == productId) {
                if(products[i].getQuantity() >= quantity) {
                    products[i].reduceQuantity(quantity);
                    double total = products[i].getPrice() * quantity;
                    cout << "\nSold " << quantity << " " << products[i].getName()
                         << "(s). Total: $" << total << endl;
                    return;
                } else {
                    cout << "\nError: Insufficient quantity available!\n";
                    return;
                }
            }
        }
        cout << "\nError: Product not found!\n";
    }
};

int main() {
    Mart mart;
    int choice;

    do {
        cout << "\nMart Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Sell Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int id, quantity;
                string name;
                double price;

                cout << "Enter product ID: ";
                cin >> id;
                cin.ignore(); // Clear input buffer
                cout << "Enter product name: ";
                getline(cin, name);
                cout << "Enter product price: $";
                cin >> price;
                cout << "Enter product quantity: ";
                cin >> quantity;

                Product newProduct(id, name, price, quantity);
                mart.addProduct(newProduct);
                break;
            }
            case 2:
                mart.displayProducts();
                break;
            case 3: {
                int productId, quantity;
                cout << "Enter product ID: ";
                cin >> productId;
                cout << "Enter quantity to sell: ";
                cin >> quantity;
                mart.sellProduct(productId, quantity);
                break;
            }
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}