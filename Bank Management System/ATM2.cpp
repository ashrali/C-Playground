#include <iostream>
#include <fstream>
#include <string>

const int MAX_ACCOUNTS = 100;

int account_numbers[MAX_ACCOUNTS];
int pins[MAX_ACCOUNTS];
std::string usernames[MAX_ACCOUNTS];
int balances[MAX_ACCOUNTS];

int conversion(const std::string& str) {
    int result = 0;
    for (char ch : str) {
        if (ch >= '0' && ch <= '9') {
            result = result * 10 + (ch - '0');
        }
    }
    return result;
}

void detail(const std::string& line, int& account_num, int& pin, std::string& username, int& balance) {
    std::string temp;
    int part = 0;
    for (char ch : line) {
        if (ch == ',') {
            if (part == 0) {
                account_num = conversion(temp);
            } else if (part == 1) {
                pin = conversion(temp);
            } else if (part == 2) {
                username = temp;
            }
            part++;
        } else {
            temp += ch;
        }
    }
    balance = conversion(temp);
}

int readAccounts(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 0;
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line) && count < MAX_ACCOUNTS) {
        detail(line, account_numbers[count], pins[count], usernames[count], balances[count]);
        count++;
    }

    file.close();
    return count; 
}

bool writeAccounts(int count, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return false;
    }

    for (int i = 0; i < count; i++) {
        file << account_numbers[i] << ","
             << pins[i] << ","
             << usernames[i] << ","
             << balances[i] << std::endl;
    }

    file.close();
    return true;
}

int add(int deposit, int amount) {
    amount += deposit;
    std::cout << "Rs." << deposit << " deposited.\n||New balance: Rs." << amount << "||\n";
    return amount;
}

int withdraw(int amount_to_withdraw, int amount) {
    if (amount_to_withdraw > amount) {
        std::cout << "Insufficient funds! \n||Current balance: " << amount << "||\n";
        return amount;
    }
    amount -= amount_to_withdraw;
    std::cout << "Rs." << amount_to_withdraw << " withdrawn. \n";
    return amount;
}

void createNewAccount(int& accountCount) {
    if (accountCount >= MAX_ACCOUNTS) {
        std::cout << "Cannot create more accounts. Maximum limit reached!\n";
        return;
    }

    std::cout << "Enter new account number: ";
    std::cin >> account_numbers[accountCount];

    std::cout << "Enter new PIN: ";
    std::cin >> pins[accountCount];

    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter username: ";
    std::getline(std::cin, usernames[accountCount]);

    std::cout << "Enter initial balance: ";
    std::cin >> balances[accountCount];

    accountCount++;
    std::cout << "New account created successfully!\n";
}

int main() {
    const std::string filename = "accounts.txt";

    // Read accounts from file
    int accountCount = readAccounts(filename);
    if (accountCount == 0) {
        return 1;
    }

    int choice;
    while (true) {
        std::cout << "\n------------------\n";
        std::cout << "1. Login\n2. Create New Account\n3. Exit\n";
        std::cout << "------------------\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int account_num, pin;
                std::cout << "Enter account number: ";
                std::cin >> account_num;

                int currentIndex = -1;
                for (int i = 0; i < accountCount; i++) {
                    if (account_numbers[i] == account_num) {
                        currentIndex = i;
                        break;
                    }
                }

                if (currentIndex == -1) {
                    std::cout << "Invalid account number!\n";
                    break;
                }

                std::cout << "Enter your pin: ";
                std::cin >> pin;

                if (pins[currentIndex] != pin) {
                    std::cout << "Invalid PIN!\n";
                    break;
                }

                std::cout << "Username: " << usernames[currentIndex] << "\n";

                while (true) {
                    std::cout << "\n------------------\n";
                    std::cout << "1. Deposit\n2. Withdraw\n3. Logout\n";
                    std::cout << "------------------\nEnter choice: ";
                    std::cin >> choice;

                    switch (choice) {
                        case 1: {
                            int deposit;
                            std::cout << "Enter amount to deposit: ";
                            std::cin >> deposit;
                            balances[currentIndex] = add(deposit, balances[currentIndex]);
                            writeAccounts(accountCount, filename);
                            break;
                        }
                        case 2: {
                            int withdraw_amount;
                            std::cout << "Enter amount to withdraw: ";
                            std::cin >> withdraw_amount;
                            balances[currentIndex] = withdraw(withdraw_amount, balances[currentIndex]);
                            writeAccounts(accountCount, filename);
                            break;
                        }
                        case 3:
                            std::cout << "Logging out...\n";
                            break;
                        default:
                            std::cout << "Invalid choice!\n";
                    }

                    if (choice == 3) break; // Logout
                }
                break;
            }
            case 2:
                createNewAccount(accountCount);
                writeAccounts(accountCount, filename);
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}