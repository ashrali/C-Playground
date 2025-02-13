#include <iostream>

class Base
{
   public:   
   int a = 6;
   void display()
   {
      std::cout << "Base class" << a <<"\n";
   }
};

class drived : public Base
{
       public :
       int b = 10;
       void display()
       {
         std::cout << "drived class" << b <<"\n";
         std::cout << "Base class" << a <<"\n";
       }
};

int main()
{
   drived obj;
     obj.display();
}