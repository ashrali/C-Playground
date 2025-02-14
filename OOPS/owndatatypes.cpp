#include <iostream>
#include <cstring> // For strlen function
#include "headerfile.h"

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
    std::string choice;
    std::cout << "Choose payment mode: \n";
    std::cout << "1. Dollar\n";
    std::cout << "2. Pound\n";
    std::cout << "3. Currency name\n";

    // Loop until a valid choice is made
    while (true)
    {
        std::cout << "Enter choice (1/2/3): ";
        std::cin >> choice;
        if (is_valid_choice(choice))
        {
            int option = std::stoi(choice);  // Convert string to int
            if (option >= 1 && option <= 3)
            {
                break; // Exit loop if choice is valid
            }
            else
            {
                std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            }
        }
        else
        {
            std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
        }
    }

    // Convert choice to integer
    int choice_num = std::stoi(choice);

    switch (choice_num)
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
        // Loop to ensure that the user enters a currency name with at least 3 characters
        std::cout << "Enter currency name (at least 3 characters): \n";
        while (true)
        {
            std::cin >> pay.currency_name;
            if (strlen(pay.currency_name) >= 3)
            {
                break; // Valid currency name, exit loop
            }
            else
            {
                std::cout << "Currency name must be at least 3 characters long. Please try again: \n";
            }
        }
        break;
    default:
        std::cout << "Invalid choice. Defaulting to Dollar payment.\n";
        std::cin >> pay.Dollar;
        break;
    }

    // Display worker information
    std::cout << "Worker's Phone number is: \t" << Ashar.phone_number << "\n";
    std::cout << "Worker's E-mail id is: \t" << Ashar.EMail_id << "\n";
    std::cout << "Worker's salary is: \t" << Ashar.salary << "\n";
    std::cout << "Worker's name is: \t" << Ashar.name << "\n";

    // Display chosen payment mode
    if (choice_num == 1)
    {
        std::cout << "Worker's payment in dollars is: \t" << pay.Dollar << "\n";
    }
    else if (choice_num == 2)
    {
        std::cout << "Worker's payment in pounds is: \t" << pay.pound << "\n";
    }
    else if (choice_num == 3)
    {
        std::cout << "Worker's payment currency name is: \t" << pay.currency_name << "\n";
    }
   
    return 0;
}
