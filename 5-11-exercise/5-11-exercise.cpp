#include <iostream>

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ", ";
    }
}

int linearSearchArray(int array[], int size, int targetVal)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == targetVal)
        {
            return i;
        }
    }
}

void reverseArray(int array[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int tmp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = tmp;
    }
}

void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            // ...
        }
        if (array[i] > array[i + 1])
        {
            int tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
        }
    }
}

void binarySearch(int array[], int size)
{

}

int main()
{
    const int size = 5;
    int array[size] = {1, 5, 4, 3, 5};
    
    bubbleSort(array, size);
    printArray(array, size);
}

