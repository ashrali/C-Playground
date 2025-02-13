#include <iostream>
#include <string>

class Binary
{
public:
    std::string bin;
    void inputBin();  // Function to input and validate binary number
    void binDisplay();  // Function to display binary number
};

// Function to input and validate binary number
void Binary::inputBin()
{
    while (true)
    {
        std::cout << "Enter a binary number: ";
        std::cin >> bin;  // Store user input into member variable bin

        // Check if the input contains only '0' and '1'
        bool isValid = true;
        for (char c : bin)
        {
            if (c != '0' && c != '1')
            {
                isValid = false;
                break;
            }
        }

        // If the input is valid, break the loop
        if (isValid)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input! Please enter a valid binary number (only 0s and 1s) \t." << std::endl;
        }
    }
}

// Function to display the binary number
void Binary::binDisplay()
{
    std::cout << "The binary number is: " << bin << std::endl;
}

int main()
{
    Binary b;  // Create an object of Binary class
    b.inputBin();  // Get the binary input from the user and validate it
    b.binDisplay();  // Display the entered binary number

    return 0;
}
