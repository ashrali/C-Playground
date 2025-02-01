#include <iostream>

int main()
{
    //For height of Diamond
    int height;
    std::cout <<"Enter height of Pyramid(half) \n";
    std::cin >>height;
    
    //Loop for rows
    for (int rows= 1; rows<= 2 * height- 1; rows++)
    {//Loop for cols
        for (int cols = 1; cols <= 2 * height- 1; cols++)
        {
            if (rows <= height)
            {
                if (cols >= height- rows+ 1 && cols <= height+ rows- 1)
                {
                    std::cout << "*";
                }
                else
                {
                    std::cout << " ";
                }
            }
            else
            {
                if (cols >= rows- height+ 1 && cols <= 3 * height- rows- 1)
                {
                 std::cout << "*";
                }
                else
                {
                std::cout << " ";
                }
            }
            if (cols ==( 2 * height)-1)
                break;
        }
        std::cout << "\n";
    }
    return 0;
}
