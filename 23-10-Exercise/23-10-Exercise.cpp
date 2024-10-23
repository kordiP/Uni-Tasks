#include <iostream>

using namespace std;

int main()
{
    int number;
    cin >> number;

    for (int i = 0; i < number; i++)
    {
        int currentNumber;
        cin >> currentNumber;

        // to-do
    }
}

/*
int input;
    int resultCube;

    cin >> input;

    resultCube = input * input;

    while (resultCube > 0)
    {
        int currentNumber = resultCube % 10;

        resultCube /= 10;

        if (currentNumber == 0 && resultCube / 10 != 0)
        {
            continue;
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