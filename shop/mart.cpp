#include <iostream>
#include <string>

const int MAX_PRODUCTS = 100;

class Product
{
private:
    int id;
    std::string name;
    double price;
    int quantity;
    std::string type;

public:
    Product()
    {
        id = 0;
        name = "";
        price = 0.0;
        quantity = 0;
        type = "";
    }

    Product(int productId, std::string productName, double productPrice, int productQuantity, std::string productType)
    {
        id = (productId), name = (productName), price = (productPrice), quantity = (productQuantity), type = (productType);
    }

    int getId() const
    {
        return id;
    }
    std::string getName() const
    {
        return name;
    }
    double getPrice() const
    {
        return price;
    }
    int getQuantity() const
    {
        return quantity;
    }
    std::string getType() const // Added getter for type
    {
        return type;
    }

    void reduceQuantity(int amount)
    {
        if (quantity >= amount)
        {
            quantity -= amount;
        }
    }
};

class Mart
{
private:
    Product products[MAX_PRODUCTS];
    int productCount;
    int lastProductId;

public:
    Mart()
    {
        productCount = 0;
        lastProductId = 1;
    }

    void addProduct(Product p)
    {
        if (productCount < MAX_PRODUCTS)
        {
            products[productCount] = p;
            productCount++;
            lastProductId++; // Increment ID for next product
            std::cout << "Product added successfully!\n";
        }
        else
        {
            std::cout << "Error: Maximum product limit reached!\n";
        }
    }

    int getNextProductId()
    {
        return lastProductId;
    }

    void displayProducts() const
    {
        std::cout << "\nAvailable Products (" << productCount << "/" << MAX_PRODUCTS << "):\n";
        std::cout << "----------------------------------------\n";
        for (int product_num = 0; product_num < productCount; product_num++)
        {
            std::cout << "Product Type: " << products[product_num].getType()
                      << " | ID: " << products[product_num].getId()
                      << " | Name: " << products[product_num].getName()
                      << " | Price: $" << products[product_num].getPrice()
                      << " | Quantity: " << products[product_num].getQuantity() << std::endl;
        }
        std::cout << "----------------------------------------\n";
    }

    void sellProduct(int productId, int quantity)
    {
        for (int product_num = 0; product_num < productCount; product_num++)
        {
            if (products[product_num].getId() == productId)
            {
                if (products[product_num].getQuantity() >= quantity)
                {
                    products[product_num].reduceQuantity(quantity);
                    double total = products[product_num].getPrice() * quantity;
                    std::cout << "\nSold " << quantity << " " << products[product_num].getName()
                              << "(s). Total: $" << total << std::endl;
                    return;
                }
                else
                {
                    std::cout << "\nError: Insufficient quantity available!\n";
                    return;
                }
            }
        }
        std::cout << "\nError: Product not found!\n";
    }
};

int main()
{
    Mart mart;
    int choice;

    do
    {
        std::cout << "\nMart Management System\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. Display Products\n";
        std::cout << "3. Sell Product\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int quantity;
            std::string name, type;
            double price;

            std::cout << "Enter product type: ";
            std::cin.ignore();
            std::getline(std::cin, type);
            std::cout << "Enter product name: ";
            std::getline(std::cin, name);
            int id = mart.getNextProductId(); // Get the next product ID
            std::cout << "Product ID: " << id << "\n";
            std::cout << "Enter product price: $";
            std::cin >> price;
            std::cout << "Enter product quantity: ";
            std::cin >> quantity;

            Product newProduct(id, name, price, quantity, type);
            mart.addProduct(newProduct);
            break;
        }
        case 2:
            mart.displayProducts();
            break;
        case 3:
        {
            int productId, quantity;
            std::cout << "Enter product ID: ";
            std::cin >> productId;
            std::cout << "Enter quantity to sell: ";
            std::cin >> quantity;
            mart.sellProduct(productId, quantity);
            break;
        }
        case 4:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}