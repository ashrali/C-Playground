#include <iostream>

class Animal
{
      private:
   char owner_name;
   std::string owner_number;
   public:
   std::string name;
   std::string breed;
   int age;
 
   void owner_info();
   void Animal_info();
   void display_data()
   {
      std::cout<<"Name: "<<name<<std::endl;
      std::cout<<"Breed: "<<breed<<std::endl;
      std::cout<<"Age: "<<age<<std::endl;
      
   };

};

void:: Animal ::owner_info()
{
     std::cout<<"Owner Name: "<<owner_name<<std::endl;
     std::cout<<"Owner Number: "<<owner_number<<std::endl;
}

void Animal::Animal_info()
{
      std::cout << "Enter Animal's name : \n ";
      std::cin >> name;
      std::cout << "Enter Animal's breed : \n ";
      std::cin >> breed;
      std::cout << "Enter Animal's age : \n ";
      std::cin >> age;
}

int main()
{
    Animal animal;

    animal.Animal_info();

    animal.display_data();

    animal.owner_info();

}