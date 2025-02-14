#include <iostream>

int main()
{
    int height;
    std::cout << "Enter Height of rectangle : \n";
    std:: cin >> height;
    for (int rows = 1; rows <= height; rows++)
    {
        for (int cols = 1; cols <= height; cols++)
        {
            // Print '*' for the boundaries
            if (rows == 1 || rows == height || cols == 1 || cols == height)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " "; // Print space inside the boundaries
            }
        }
        std::cout << "\n"; // Move to the next row after finishing a row
    }
    return 0;
}