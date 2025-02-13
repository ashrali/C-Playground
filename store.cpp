#include <iostream>
#include <string>

class Shop
{
    int id;
    int price;
    std::string name;
    static int counter;

public:
    // Getter functions
    void get_name();
    void get_id();
    void get_price();
    
    // Display item
    void display_item() const;

    // Function to display all items
    static void display_items(Shop store[], int item_count);
};

int Shop::counter = 0; // Initialize the static counter

void Shop::get_id()
{
    std::cout << "Enter id of item: ";
    std::cin >> id;
}

void Shop::get_price()
{
    std::cout << "Enter price of item: ";
    std::cin >> price;
}

void Shop::get_name()
{
    std::cout << "Enter name of item: ";
    std::cin >> name;
}

void Shop::display_item() const
{
    std::cout << "Item " << counter << " -> Name: " << name << ", Price: " << price << ", ID: " << id << "\n";
}

void Shop::display_items(Shop store[], int item_count)
{
    std::cout << "\nList of items:\n";
    for (int i = 0; i < item_count; ++i)
    {
        counter++;
        store[i].display_item();
    }
}

int main()
{
    const int MAX_ITEMS = 100;  // Set the maximum number of items
    Shop store[MAX_ITEMS];  // Fixed-size array of Shop objects
    int item_count;

    std::cout << "Enter number of items: ";
    std::cin >> item_count;

    // Ensure that the number of items doesn't exceed MAX_ITEMS
    if (item_count > MAX_ITEMS)
    {
        std::cout << "Cannot enter more than " << MAX_ITEMS << " items.\n";
        return 1;
    }

    for (int i = 0; i < item_count; ++i)
    {
        store[i].get_id();
        store[i].get_price();
        store[i].get_name();
    }

    Shop::display_items(store, item_count);  // Display all items

    return 0;
}
