#include <iostream>
using namespace std;
int main()
{
      int a[3][3], b[3][3], c[3][3] = {0};
      cout << "Enter the elements of first matrix: \n";
      for (int rows= 0; rows< 3; rows++)
      {
            for (int columns = 0; columns < 3; columns++)
            {
                  cin >> a[rows][columns];
            }
      }
      cout << "Enter the elements of second matrix: \n";
      for (int rows= 0; rows< 3; rows++)
      {
            for (int columns = 0;columns < 3;columns++)
            {
                  cin >> b[rows][columns];
            }
      }
      cout << "Matrix A & B:" << endl;
      for (int rows= 0; rows< 3; rows++)
      {
            for (int columns = 0;columns < 3;columns++)
            {
                  cout << a[rows][columns] << " ";
            }
            cout << " ";
            for (int columns = 0; columns < 3;columns++)
            {
                  cout << b[rows][columns] << " ";
            }
            cout << endl;
      }
    for (int rows= 0; rows< 3; rows++)
    {
        for (int columns = 0;columns < 3;columns++)
        {
            for (int index = 0; index < 3; index++)
            {
                c[rows][columns] += a[rows][index] * b[index][columns];
            }
        }
    }
    cout << "Matrix A * B:" << endl;
    for (int rows= 0; rows< 3; rows++)
    {
        for (int columns = 0;columns < 3;columns++)
        {
            cout << c[rows][columns] << " ";
        }
        cout << endl;
    }
    return 0;
}