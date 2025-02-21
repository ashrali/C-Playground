int add(int deposit, int amount)
{
      amount += deposit;
      std::cout << "Rs." << deposit << " deposited.\n||New balance: Rs." << amount <<"||\n";
      return amount;
}

int withdraw(int amount_to_withdraw, int amount)
{
      if (amount_to_withdraw > amount)
      {
            std::cout << "Insufficient funds! \n||Current balance: " << amount << "||\n";
            return amount;
      }
      amount -= amount_to_withdraw;
      std::cout << "Rs." << amount_to_withdraw << " withdrawn. \n" ;
      return amount;
}
