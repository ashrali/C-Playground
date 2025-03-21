#include <iostream>
#include <algorithm>
#include <cmath>

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
      for (int place = 0; place < str.length(); place++)
      {
            if (isupper(str[place]))
            {
                  encrypteddata += char(int(str[place] - 'A' + shift) % 10 + 48);
            }
            else if (islower(str[place]))
            {
                  encrypteddata += char(int(str[place] - 'a' + shift) % 26 + 65);
            }
            else if (isdigit(str[place]))
            {
                  encrypteddata += char(int(str[place] - '0' + shift) % 26 + 97);
            }
            else if (isspace(str[place]))
            {
                  encrypteddata += 'n';
            }
            else
            {
                  encrypteddata += str[place];
            }
      }
      std::string encryptkey ;
      std::cout << "Enter key to encrypt data: ";
      std::getline(std::cin, encryptkey);
      std::string decryptkey ;
      std::cout<<"Enter key to decrypt data : ";
      std::getline(std::cin , decryptkey);
      if (encryptkey == decryptkey)
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