#include <iostream>

typedef struct worker
{
    std::string name;
    std::string phone_number;
    std::string EMail_id;
    int salary;
} wo;

union payment
{
    int Dollar;
    float pound;
    char currency_name;
};

bool is_valid_name(const std::string& name)
{
    for (char c : name)
    {
        // Check if character is not between 'A' and 'Z' or 'a' and 'z'
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
        {
            return false; // Invalid if any character is not a letter
        }
    }
    return true;
}

int main()
{
    wo Ashar;

    // Get and validate name
    std::cout << "Enter name of worker (only alphabets allowed): \n";
    while (true) 
    {
        std::cin >> Ashar.name;
        if (is_valid_name(Ashar.name))
        {
            break; // Name is valid, exit loop
        }
        else
        {
            std::cout << "Invalid name. Please enter a name with only alphabetic characters: \n";
        }
    }

    std::cout << "Enter phone number of worker: \n";
    std::cin >> Ashar.phone_number;

    std::cout << "Enter salary of worker: \n";
    std::cin >> Ashar.salary;

    std::cout << "Enter Email id of worker: \n";
    std::cin >> Ashar.EMail_id;

    union payment pay;

    // Ask user for which payment mode they want to use
    int choice;
    std::cout << "Choose payment mode: \n";
    std::cout << "1. Dollar\n";
    std::cout << "2. Pound\n";
    std::cout << "3. Currency name\n";
    std::cout << "Enter choice (1/2/3): ";
    std::cin >> choice;

    switch(choice)
    {
        case 1:
            std::cout << "Enter Pay in dollars: \n";
            std::cin >> pay.Dollar;
            break;
        case 2:
            std::cout << "Enter Pay in pounds: \n";
            std::cin >> pay.pound;
            break;
        case 3:
            std::cout << "Enter currency name (single character): \n";
            std::cin >> pay.currency_name;
            break;
        default:
            std::cout << "Invalid choice. Defaulting to Dollar.\n";
            std::cin >> pay.Dollar;
            break;
    }

    // Display worker information
    std::cout << "Worker's Phone number is : \t" << Ashar.phone_number << "\n";
    std::cout << "Worker's E-mail id is : \t" << Ashar.EMail_id << "\n";
    std::cout << "Worker's salary is : \t" << Ashar.salary << "\n";
    std::cout << "Worker's name is : \t" << Ashar.name << "\n";

    // Display chosen payment mode
    if (choice == 1) {
        std::cout << "Worker's payment in dollars is : \t" << pay.Dollar << "\n";
    } else if (choice == 2) {
        std::cout << "Worker's payment in pounds is : \t" << pay.pound << "\n";
    } else if (choice == 3) {
        std::cout << "Worker's payment currency name is : \t" << pay.currency_name << "\n";
    }

    return 0;
}
