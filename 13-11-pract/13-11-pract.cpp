#include <iostream>

const int ARRAY_SIZE = 3;

int smallestElement(int array[ARRAY_SIZE][ARRAY_SIZE])
{
    int smallest = array[0][0];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            if (smallest > array[i][j]) smallest = array[i][j];
        }
    }
        return smallest;
}

bool isTriangleMatrix(int array[ARRAY_SIZE][ARRAY_SIZE])
{
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

void transponateMatrix(int array[ARRAY_SIZE][ARRAY_SIZE])
{
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }
}

void printMatrix(int array[ARRAY_SIZE][ARRAY_SIZE])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool isMagicCube(int array[ARRAY_SIZE][ARRAY_SIZE])
{
    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    int rowsSums[ARRAY_SIZE] = {};

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        mainDiagonalSum += array[i][i];
        secondaryDiagonalSum += array[i][ARRAY_SIZE - i - 1];

        int currentRowSum = 0;
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            currentRowSum += array[i][j];
        }
        rowsSums[i] = currentRowSum;
    }

    if (mainDiagonalSum != secondaryDiagonalSum)
    {
        return false;
    }

    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        if (rowsSums[i] != rowsSums[i + 1])
        {
            return false;
        }
    }

    return true;
}

int matrixSum[ARRAY_SIZE][ARRAY_SIZE] = {};

void sumOfMatrices(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix2[ARRAY_SIZE][ARRAY_SIZE])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            matrixSum[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }
}

void matrixMultiplyByNum(int matrix[ARRAY_SIZE][ARRAY_SIZE], int number)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            matrixSum[i][j] = matrix[i][j] * number;
        }
    }
}

int** multiplyMatrices(int** matrix1, int matrix1RowCount, int matrix1ColCount, int** matrix2, int matrix2RowCount, int matrix2ColCount)
{
    // todo
}

int main()
{

}