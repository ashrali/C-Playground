#include <iostream>
#include <string>

const int MAX_ACCOUNTS = 100;

class NormalUser
{
private:
    std::string name;
    int accountNumber;
    double balance;

public:
    void createAccount()
    {
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;
        balance = 0.0;
    }

    void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
            balance -= amount;
    }

    void display() const
    {
        std::cout << "Account: " << accountNumber
                  << "\nHolder: " << name
                  << "\nBalance: $" << balance << "\n";
    }

    double getBalance() const { return balance; }
    int getNumber() const { return accountNumber; }
};

class Bank
{
private:
    NormalUser accounts[MAX_ACCOUNTS];
    int count = 0;

public:
    int addAccount()
    {
        if (count >= MAX_ACCOUNTS)
            return -1;
        accounts[count].createAccount();
        return count++;
    }

    bool isValidIndex(int index) const
    {
        return index >= 0 && index < count;
    }

    NormalUser &getAccount(int index)
    {
        return accounts[index];
    }

    void listAccounts() const
    {
        std::cout << "\n=== Accounts ===\n";
        for (int i = 0; i < count; i++)
        {
            std::cout << (i + 1) << ". " << accounts[i].getNumber() << "\n";
        }
    }

    int getAccountCount() const
    {
        return count;
    }
};

class Cashier
{
public:
    static void modifyAccount(Bank &bank, int index)
    {
        if (!bank.isValidIndex(index))
            return;

        int choice;
        double amount;
        NormalUser &acc = bank.getAccount(index);

        std::cout << "\n1. Deposit\n2. Withdraw\nChoice: ";
        std::cin >> choice;

        std::cout << "Amount: $";
        std::cin >> amount;

        if (choice == 1)
            acc.deposit(amount);
        else if (choice == 2)
            acc.withdraw(amount);

        acc.display();
    }
};

class Accountant
{
public:
    static void viewAccount(Bank &bank, int index)
    {
        if (bank.isValidIndex(index))
        {
            bank.getAccount(index).display();
        }
    }
};

class Manager
{
public:
    static void viewAll(Bank &bank)
    {
        bank.listAccounts();

        std::cout << "\nManager Options:\n"
                  << "1. Create New Account\n"
                  << "2. View Account Details\n"
                  << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            int result = bank.addAccount();
            if (result == -1)
            {
                std::cout << "Maximum accounts reached!\n";
            }
            else
            {
                std::cout << "Account created successfully! ID: " << result + 1 << "\n";
            }
        }
        else if (choice == 2)
        {
            int accNumber;
            std::cout << "Enter account number to view: ";
            std::cin >> accNumber;

            bool found = false;
            for (int i = 0; i < bank.getAccountCount(); ++i)
            {
                if (bank.getAccount(i).getNumber() == accNumber)
                {
                    bank.getAccount(i).display();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Account not found!\n";
            }
        }
        else
        {
            std::cout << "Invalid choice!\n";
        }
    }
};

int main()
{
    Bank bank;
    int choice;

    while (true)
    {
        std::cout << "\nBank System\n"
                  << "1. Create Account\n2. Cashier\n3. Accountant\n4. Manager\n5. Exit\n"
                  << "Choice: ";
        std::cin >> choice;

        if (choice == 5)
            break;

        switch (choice)
        {
        case 1:
        {
            int result = bank.addAccount();
            if (result == -1)
            {
                std::cout << "Max accounts reached!\n";
            }
            else
            {
                std::cout << "Account created! ID: " << result + 1 << "\n";
            }
            break;
        }
        case 2:
        {
            bank.listAccounts();
            int index;
            std::cout << "Select account: ";
            std::cin >> index;
            Cashier::modifyAccount(bank, index - 1);
            break;
        }
        case 3:
        {
            bank.listAccounts();
            int index;
            std::cout << "Select account: ";
            std::cin >> index;
            Accountant::viewAccount(bank, index - 1);
            break;
        }
        case 4:
            Manager::viewAll(bank);
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}