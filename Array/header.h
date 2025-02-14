int input_array_output()
{
      int arr_1[3][3];
      int arr_2[3][3];
      int arr_3[3][3]={0};

      std::cout << "Enter the elements of the 1st matrix : \n";

      for (int rows = 0; rows < 3; rows++)
      {
            for (int columns = 0; columns < 3; columns++)
            {
                  std::cin >> arr_1[rows][columns];
            }
      }
     
      std::cout << "Enter the elements of the 2nd matrix : \n";

      for (int rows = 0; rows < 3; rows++)
      {
            for (int columns = 0; columns < 3; columns++)
            {
                  std::cin >> arr_2[rows][columns];
            }
      }


      for (int rows = 0; rows < 3; rows++)
      {
            for (int columns = 0; columns < 3; columns++)
            {
                  arr_3[rows][columns] += arr_1[rows][columns] + arr_2[rows][columns]; 
            }
      }

           std::cout << "Matrix Sum : \n";
           
            for (int rows = 0; rows < 3; rows++)
      {
            for (int columns = 0; columns < 3; columns++)
            {
                  std::cout << arr_3[rows][columns] <<" ";
            }
            std::cout << "\n";
      }

      return 0;
}