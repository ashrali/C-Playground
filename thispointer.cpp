#include <iostream>

class A
{
   int a;
public:
  
      A& setdata(int a)
     {
      this->a = a;
      return *this;
 } 
     void getdata()
     {
      std::cout << "Value of a = " << a << std::endl;
      }

     
};

int main()
{
    A a;
    a.setdata(10).getdata();
}