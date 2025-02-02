#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    float num1, num2, result;
    char operation;

    cout << "Enter the first number: " << endl;
    cin >> num1;
    cout << "Enter the operation (+, -, *, /): "<< endl;
    cin >> operation;
    cout << "Enter the second number: " <<endl;
    cin >> num2;
    cout << setprecision(10);
    switch (operation)
    {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;

        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;

        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;

        case '/':
            if (num2 != 0)
            {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            }
            else
            {
                cout << "Error: Division by zero is undefined." << endl;
            }
            break;

        default:
            cout << "Invalid operation!" << endl;
    }

  return 0;
}
