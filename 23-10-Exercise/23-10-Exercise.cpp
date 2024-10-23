#include <iostream>

using namespace std;

int main()
{
    int numberA;
    int numberB;

    cin >> numberA;
    cin >> numberB;

    for (int currentNumber = numberA; currentNumber < numberB; currentNumber++)
    {
        for (int del = 0; del < currentNumber; del++)
        {
            int currSum = 0;
            
        }
    }
}

/*
int size;
    char symbol;

    cin >> size;
    cin >> symbol;

    for (int row = 0; row < size - 1; row++)
    {
        for (int i = 0; i < size * 2 - row; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < row * 2 + 1; i++)
        {
            cout << symbol;
        }
        cout << endl;
    }

    for (int i = 0; i <= size; i++)
    {
        cout << " ";
    }

    for (int i = 0; i < size * 2 - 1; i++)
    {
        cout << symbol;
    }

    cout << endl;

    for (int row = size - 1; row > 0; row--)
    {
        for (int i = size * 2 - row + 1; i > 0; i--)
        {
            cout << " ";
        }
        for (int i = row * 2 - 1; i > 0; i--)
        {
            cout << symbol;
        }
        cout << endl;
    }
*/

/*
int number;
    int dupeCheck = 0;
    cin >> number;

    for (int a = 1; a < number; a++)
    {
        for (int b = 1; b < number; b++)
        {
            for (int c = 1; c < number; c++)
            {
                if ((a * a) + (b * b) == (c * c) && b != dupeCheck)
                {
                    cout << a << " " << b << " " << c << "\n";
                    dupeCheck = a;
                }
            }
        }
    }
*/

/*
int number;
    int sumOfAllNumbers = 0;
    int sumOfInputNumbers = 0;

    cin >> number;

    for (int i = 1; i <= number; i++)
    {
        sumOfAllNumbers += i;
    }

    for (int i = 1; i <= number - 1; i++)
    {
        int currentNumber;
        cin >> currentNumber;
        sumOfInputNumbers += currentNumber;
    }

    cout << (sumOfAllNumbers - sumOfInputNumbers);
*/

/*
 int input;
    int resultCube;
    bool passedFirstNonZeroDigit = false;

    cin >> input;

    resultCube = input * input;

    while (resultCube > 0)
    {
        int currentNumber = resultCube % 10;

        resultCube /= 10;

        if (currentNumber == 0 && !passedFirstNonZeroDigit)
        {
            continue;
        }
        else
        {
            passedFirstNonZeroDigit = true;
        }

        cout << currentNumber;
    }
*/

/* 1)
    
    int ladderSize;
cin >> ladderSize;

for (int i = 1; i <= ladderSize; i++)
{
for (int j = 1; j <= i; j++)
{
	cout << j;
}
cout << endl;
}

*/

/* 2)
int result;
    int numberX = 1;
    int numberY;

    cin >> result;

    int counter = result;

    while (counter > 1)
    {
        numberY = result - numberX;

        cout << "x = " << numberX << " y = " << numberY << "\n";

        numberX++;
        counter--;
    }*/

/*int input;
    int result = 1;
    cin >> input;

    for (int i = 1; i <= input; i++)
    {
        result *= i;
    }

    cout << result;*/

/*
int rows;
    int columns;
    int outputValue = 1;

    cin >> rows;
    cin >> columns;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            cout << outputValue++ << " ";
        }
        cout << endl;
    }
*/

/*
int numberToGuess;

    cin >> numberToGuess;

    while (true)
    {
        int currentGuess;
        cin >> currentGuess;

        if (currentGuess == numberToGuess)
        {
            cout << "win\n";
            break;
        }
        else if (currentGuess < numberToGuess)
        {
            cout << "too small\n";
        }
        else if (currentGuess > numberToGuess)
        {
            cout << "too big\n";
        }
    }
*/