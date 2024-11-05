#include <iostream>

// in functions, paramater array is the same as pointer, so working with reference, not value
// so any changes in the functions are also in the main in the array

void arrayInput(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void arrayOutput(int array[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i];
    }
}
int main()
{
    const int ARRAY_SIZE = 2;
    int array[ARRAY_SIZE] = {};
    arrayInput(array, ARRAY_SIZE);
    arrayOutput(array, ARRAY_SIZE);
}

