#include <iostream>
int main() {
    int digit;
    std::cout << "Enter the number of terms you want in the Fibonacci series: \n";
    std::cin >> digit;

    int Num_1 = 0;
    int Num_2 = 1;

    if (digit <= 0) {
        std::cout << "Enter a valid number greater than 0: ";
    }
    else if (digit == 1) {
        std::cout << "Fibonacci series up to " << Num_1 << " is: " << Num_1 ;
    }
    else {
        std::cout << "Fibonacci series up to " << digit << " terms: \n";
        
        // Print the first Fibonacci term
        std::cout << Num_1;

        // For the next term, print '1' correctly
        if (digit > 1) {
            std::cout << ", " << Num_2;  // Print the second term '1'
        }

        // Print the remaining Fibonacci terms starting from the third term
        for (int i = 3; i <= digit; i++) {
            int nextterm = Num_1 + Num_2;
            {
            std::cout << ", " << nextterm;
            }
            Num_1 = Num_2;
            Num_2 = nextterm;
        }
    }

    std::cout << "\n";
    return 0;
}
