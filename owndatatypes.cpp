#include <iostream>
#include <cstring>  // For strlen function

typedef struct worker {
    std::string name;
    std::string phone_number;
    std::string EMail_id;
    int salary;
} wo;

union payment {
    int Dollar;
    float pound;
    char currency_name[20]; // Or you can replace this with std::string
};

bool is_valid_name(const std::string &name) {
    for (char c : name) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            return false; // Invalid if any character is not a letter
        }
    }
    return true;
}

int main() {
    wo Ashar;

    // Get and validate name
    std::cout << "Enter name of worker (only alphabets allowed): \n";
    while (true) {
        std::cin >> Ashar.name;
        if (is_valid_name(Ashar.name)) {
            break; // Name is valid, exit loop
        } else {
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

    // Loop until a valid choice is made
    while (true) {
        std::cout << "Enter choice (1/2/3): ";
        std::cin >> choice;
        if (choice >= 1 && choice <= 3) {
            break;  // Exit loop if choice is valid
        } else {
            std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }

    switch (choice) {
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
        while (true) {
            std::cin >> pay.currency_name;
            if (strlen(pay.currency_name) >= 3) {
                break;  // Valid currency name, exit loop
            } else {
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
    if (choice == 1) {
        std::cout << "Worker's payment in dollars is: \t" << pay.Dollar << "\n";
    } else if (choice == 2) {
        std::cout << "Worker's payment in pounds is: \t" << pay.pound << "\n";
    } else if (choice == 3) {
        std::cout << "Worker's payment currency name is: \t" << pay.currency_name << "\n";
    }

    return 0;
}
