#include <iostream>
#include <algorithm>

int main()
{
      int shift;
      std::cout << "Enter data to be encrypted : ";
      std::string str;
      std::getline(std::cin, str);
      std::cout << "Enter shift value : ";
      std::cin >> shift;
      std::cin.ignore();
      std::string encrypteddata = "";
      for (int i = 0; i < str.length(); i++)
      {
            if (isupper(str[i]))
            {
                  encrypteddata += char(int(str[i] - 'A' + shift) % 10 + 48);
            }
            else if (islower(str[i]))
            {
                  encrypteddata += char(int(str[i] - 'a' + shift) % 26 + 65);
            }
            else if (isdigit(str[i]))
            {
                  encrypteddata += char(int(str[i] - '0' + shift) % 26 + 97);
            }
            else
            {
                  encrypteddata += str[i];
            }
      }
      std::string key;
      std::cout << "Enter key : ";
      std::getline(std::cin, key);
      if (key == "1234")
      {
            std::cout << "Decrypted data : " << str << "\n";
      }
      else
      {
            std::reverse(encrypteddata.begin(), encrypteddata.end());
            std::cout << "Encrypted data : " << encrypteddata;
      }
      return 0;
}