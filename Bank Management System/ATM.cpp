#include <iostream>
#include "headerfile.h"

int main()
{
      int account_num,pin,deposit, withdraw_amount, balance = 0, choice;
      std::cout << "Enter account number : \n";
      std::cin >> account_num;
      if(account_num == 1000||1001||1002||1003)
      {
            std::cout << "Enter your pin : ";
            std::cin >> pin;
      }
      if((account_num == 1000 && pin == 1111)||(account_num == 1001 && pin == 2222)||(account_num == 1002 && pin == 3333)||(account_num == 1003 && pin == 4444))
      {
            if (account_num == 1000 && pin == 1111)
            {
                  std::cout << "Username : A\n";
            }
            if (account_num == 1001 && pin == 2222)
            {
                  std::cout << "Username : B\n";
            }
            if (account_num == 1002 && pin == 3333)
            {
                  std::cout << "Username : C\n";
            }
            if (account_num == 1003 && pin == 4444)
            {
                  std::cout << "Username : D\n";
            }
      while (true)
      {
            std::cout << "What do you want to do ? \n";
            std::cout << "------------------\n";
            std::cout << "1.Deposit\n";
            std::cout << "2.Withdraw\n";
            std::cout << "3.Exit \n";
            std::cout <<"-------------------\n";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
            {
                  std::cout << "Enter amount to deposit: ";
                  std::cin >> deposit;

                  balance = add(deposit, balance);
            }
            break;
            case 2:
            {
                  std::cout << "Enter amount to withdraw: ";
                  std::cin >> withdraw_amount;

                  balance = withdraw(withdraw_amount, balance);
            }
            break;
            case 3:
            {
                  return 0;
            }    
            default:
                    std::cout << "Invalid Choice!";
            }
      }
      }
      else
      {
            std::cout << "Invalid account number or pin!\nTry again!";
      }
      return 0;
}