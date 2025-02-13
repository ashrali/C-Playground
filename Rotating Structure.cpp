#include <iostream>

// Function to print the 2D array
void print2DArray(char **arr, int height, int width)
{
    for (int rows = 0; rows < height; rows++)
    {
        for (int cols = 0; cols < width; cols++)
        {
            std::cout << arr[rows][cols] << " ";
        }
        std::cout << std::endl;
    }
}

// Getting the border elements
void getBorder(char **arr, int height, int width, char border[], int &size, int top, int left, int bottom, int right)
{
    size = 0;

    // Top row
    for (int rows = left; rows <= right; rows++)
    {
        border[size++] = arr[top][rows];
    }
    // Right column
    for (int rows = top + 1; rows <= bottom; rows++)
    {
        border[size++] = arr[rows][right];
    }
    // Bottom row
    for (int rows = right - 1; rows >= left; rows--)
    {
        border[size++] = arr[bottom][rows];
    }
    // Left column
    for (int rows = bottom - 1; rows > top; rows--)
    {
        border[size++] = arr[rows][left];
    }
}

// Shifting the border elements by 1 position (clockwise)
void shiftBorderClockwise(char border[], int size)
{
    if (size <= 1)
        return;

    // Store the last element of the border
    char temp = border[size - 1];

    // Shift all elements by 1 position to the right
    for (int num = size - 1; num > 0; num--)
    {
        border[num] = border[num - 1];
    }

    // Place the last element at the start
    border[0] = temp;
}

// Function to shift the border elements by 1 position (anti-clockwise) 
void shiftBorderAntiClockwise(char border[], int size)
{
    if (size <= 1)
        return;

    // Store the first element of the border
    char temp = border[0];

    // Shift all elements by 1 position to the left
    for (int num = 0; num < size - 1; num++)
    {
        border[num] = border[num + 1];
    }

    // Place the first element at the end
    border[size - 1] = temp;
}

// Plcing shifted border back into requird place
void setBorder(char **arr, int height, int width, char border[], int size, int top, int left, int bottom, int right)
{
    int index = 0;

    // Top row
    for (int rows = left; rows <= right; rows++)
    {
        arr[top][rows] = border[index++];
    }
    // Right column
    for (int rows = top + 1; rows <= bottom; rows++)
    {
        arr[rows][right] = border[index++];
    }
    // Bottom row
    for (int rows = right - 1; rows >= left; rows--)
    {
        arr[bottom][rows] = border[index++];
    }
    // Left column
    for (int rows = bottom - 1; rows > top; rows--)
    {
        arr[rows][left] = border[index++];
    }
}

// Rotate all internal rectangles
void rotateInternalRectangles(char **arr, int height, int width, char direction)
{
    int top = 0, left = 0, bottom = height - 1, right = width - 1;

    while (top < bottom && left < right)
    {
        int borderSize;
        char border[height * width]; // To store the border elements

        // Get the current border
        getBorder(arr, height, width, border, borderSize, top, left, bottom, right);

        // Rotation of border
        if (direction == 'c' || direction == 'C')
        {
            shiftBorderClockwise(border, borderSize);
        }
        else if (direction == 'a' || direction == 'A')
        {
            shiftBorderAntiClockwise(border, borderSize);
        }

        // Set the rotated border back into the matrix
        setBorder(arr, height, width, border, borderSize, top, left, bottom, right);

        // Move to the next inner rectangle
        top++;
        left++;
        bottom--;
        right--;
    }
}

int main()
{
    int height, width;
    std::cout << "Enter height of structure: ";
    std::cin >> height;
    std::cout << "Enter width of rectangle: ";
    std::cin >> width;

    // 2D array (matrix)
    char **arr = new char *[height];
    for (int num = 0; num < height; ++num)
    {
        arr[num] = new char[width];
    }

    // Input the elements of the 2D array
    std::cout << "Enter elements of structure (characters):\n";
    for (int rows = 0; rows < height; rows++)
    {
        for (int cols = 0; cols < width; cols++)
        {
            std::cin >> arr[rows][cols];
        }
    }

    // Output the original 2D array
    std::cout << "Original 2D Array:\n";
    print2DArray(arr, height, width);

    // Ask the user which direction to rotate the border
    char direction;
    std::cout << "Which direction would you like to rotate the border and internal rectangles? (c for clockwise, a for anti-clockwise): ";
    std::cin >> direction;

    // Rotate internal rectangles
    rotateInternalRectangles(arr, height, width, direction);

    // Output the matrix after the rotation
    std::cout << "Array after rotation:\n";
    print2DArray(arr, height, width);

    return 0;
}