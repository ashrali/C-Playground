
#include <iostream>

int main()
{
    int height;
    std::cout << "Enter Height of Pyramid: \n";
    std::cin >> height;

    for (int rows = 1; rows <= height; rows++)
    {
        // Print spaces before the stars
        for (int spaces = 1; spaces <= height - rows; spaces++)
        {
            std::cout << " ";
        }

        // Print stars (odd number of stars)
        for (int stars = 1; stars <= (2 * rows - 1); stars++)
        {
            // Hollow pyramid logic: don't print stars in the middle of rows after the first one
            if (stars == 1 || stars == (2 * rows - 1) || rows == height)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
        }

        std::cout << "\n";
    }

    return 0;
}
