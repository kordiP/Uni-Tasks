#include <iostream>

const int differenceForCapitals = 32;

int sum(int numberA, int numberB)
{
    return numberA + numberB;
}

int powerOfIntegers(int number, int power)
{
    int result = 1;

    for (int i = 0; i < power; i++)
    {
        result *= number;
    }

    return result;
}

bool isEven(int number)
{
    return (number % 2 == 0);
}

bool isPositive(int number)
{
    return (number >= 0);
}

bool isNegative(int number)
{
    return (number < 0);
}

int absNum(int number)
{
    return (number >= 0 ? number : -number);
}

double fabsNum(double number)
{
    return (number >= 0 ? number : -number);
}

void print(char symbol, int times)
{
    for (int i = 0; i < times; i++)
    {
        std::cout << symbol;
    }
}

bool isLetter(char symbol)
{
    if (symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z')
    {
        return true;
    }
    return false;
}

bool isCapitalLetter(char symbol)
{
    if (symbol >= 'A' && symbol <= 'Z')
    {
        return true;
    }
    return false;
}

char toLower(char symbol) 
{

    if (isLetter(symbol) && isCapitalLetter(symbol))
    {
        return symbol + differenceForCapitals;
    }
    return '0';
}

char toUpper(char symbol)
{
    if (isLetter(symbol) && !isCapitalLetter(symbol))
    {
        return symbol - differenceForCapitals;
    }
    return '0';
}

int getLength(int number)
{
    int digitCounter = 0;

    while (number > 0)
    {
        digitCounter++;
        number /= 10;
    }

    return digitCounter;
}

int getNumberAt(int fromNumber, int indexNumber) 
{
    int bigNumberLength = getLength(fromNumber);
    int differenceForCalc = bigNumberLength - indexNumber;
    
    fromNumber /= powerOfIntegers(10, differenceForCalc);

    return fromNumber % 10;
}

bool isSquare(int number) 
{
    int biggestPossibleSquare = number / 2;
    
    for (int i = 1; i <= biggestPossibleSquare; i++)
    {
        if (i * i == number)
        {
            return true;
        }
    }

    return false;
}

int concatNumbers(int numberFront, int numberBack) // to-do 
{
    int digitsSecond = getLength(numberBack);
    return numberFront * (powerOfIntegers(10, digitsSecond)) + numberBack;
}

int main()
{
    std::cout << concatNumbers(123, 456);
}

