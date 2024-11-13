#include <iostream>

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ", ";
    }
}

void inputArray(int array[], int size)
{
    if (array == nullptr || size < 1 || size > 1000)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

double averageValue(int array[], int size)
{
    double averageValue = 0;

    for (int i = 1; i < size; i++)
    {
        averageValue += array[i];
    }

    averageValue /= size * 1.0;

    return averageValue;
}

int closestValueToAverage(int array[], int size, double averageValue)
{
    double smallestDiff = array[0] - averageValue;
    int closestNumber = array[0];

    for (int i = 1; i < size; i++)
    {
        double currentDiff = array[i] - averageValue;

        if (abs(currentDiff) < abs(smallestDiff))
        {
            smallestDiff = currentDiff;
            closestNumber = array[i];
        }
    }

    return closestNumber;
}

int minInArray(int array[], int size)
{
    int smallestNumber = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < smallestNumber)
        {
            smallestNumber = array[i];
        }
    }
    return smallestNumber;
}

int maxInArray(int array[], int size)
{
    int biggest = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > biggest)
        {
            biggest = array[i];
        }
    }
    return biggest;
}

int main()
{
    const int ARRAY_SIZE = 4;
    int array[ARRAY_SIZE] = {};

    inputArray(array, ARRAY_SIZE);

    /* 
    1)
    double averageVal = averageValue(array, ARRAY_SIZE);
    int closestToAverage = closestValueToAverage(array, ARRAY_SIZE, averageVal);


    std::cout << averageVal << " " << closestToAverage;*/

    std::cout << minInArray(array, ARRAY_SIZE) << maxInArray(array, ARRAY_SIZE);
}
