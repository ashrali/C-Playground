#include <iostream>

class Box
{
private:
   int length;
   int width;
   int height;

public:
   // Constructor to initialize Box dimensions
   Box(int l, int w, int h) : length(l), width(w), height(h) {}

   // Declare the friend function
   friend void setDimensions(Box &b); // Pass by reference to modify the object
   friend void displayVolume(Box b);
};

// Friend function to set the dimensions of the box
void setDimensions(Box &b)
{
   std::cout << "Enter length of box: ";
   std::cin >> b.length;
   std::cout << "Enter width of box: ";
   std::cin >> b.width;
   std::cout << "Enter height of box: ";
   std::cin >> b.height;
}

// Friend function definition to display the volume of the box
void displayVolume(Box b)
{
   int volume = b.length * b.width * b.height;
   std::cout << "Volume of the box: " << volume << "cm^3 \n";
}

int main()
{
   // Create an object of the Box class with initial values
   Box box1(0, 0, 0);

   // Call the friend function to set the dimensions (allowing user input)
   setDimensions(box1);

   // Call the friend function to display the volume
   displayVolume(box1);

   return 0;
}
