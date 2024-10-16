#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int fourDigitInput;
    int firstNumber;
    int secondNumber;

    cin >> fourDigitInput;

    firstNumber = (fourDigitInput / 1000) * 10 + fourDigitInput % 10;
    secondNumber = (fourDigitInput / 100 - (fourDigitInput / 1000) * 10) * 10 + ((fourDigitInput % 100 - fourDigitInput % 10) / 10);

    if (firstNumber > secondNumber)
    {
        cout << "greater";
    }
    else if (secondNumber > firstNumber)
    {
        cout << "less";
    }
    else 
    {
        cout << "equal";
    }

    cout << "\n" << firstNumber << " " << secondNumber;
}

/*
int firstNumber;
    int secondNumber;
    int thirdNumber;
    int biggestNumber;
    int middleNumber;
    int smallestNumber;

    cin >> firstNumber;
    cin >> secondNumber;
    cin >> thirdNumber;

    if (firstNumber >= secondNumber)
    {
        if (firstNumber >= thirdNumber)
        {
            biggestNumber = firstNumber;
            middleNumber = secondNumber;
            smallestNumber = thirdNumber;
        }
        else
        {
            biggestNumber = thirdNumber;
            middleNumber = firstNumber;
            smallestNumber = secondNumber;
        }
        if (secondNumber >= thirdNumber)
        {

        }
        else
        {

        }
    }
    else if (thirdNumber >= secondNumber)
    {

    }
*/

/*
int arabicNumeral;

    cin >> arabicNumeral;

    switch (arabicNumeral)
    {
    case 1:
        cout << "I";
        break;
    case 2:
        cout << "II";
        break;
    case 3:
        cout << "III";
        break;
    case 4:
        cout << "IV";
        break;
    case 5:
        cout << "V";
        break;
    case 6:
        cout << "VI";
        break;
    case 7:
        cout << "VII";
        break;
    case 8:
        cout << "VIII";
        break;
    case 9:
        cout << "IX";
        break;
    default:
        cout << "NO.";
        break;
    }
*/

/* 6?/
char inputChar;
    cin >> inputChar;

    if (inputChar >= 'a' && inputChar <= 'z')
    {
        cout << (char)toupper(inputChar);
    }
    else if (inputChar >= 'A' && inputChar <= 'Z')
    {
        cout << (char)tolower(inputChar);
    }
    else
    {
        cout << "Validn't char.";
    }
*/

/*
int firstCoef;
    int secondCoef;
    int thirdCoef;
    int discriminant;

    double firstResult;
    double secondResult;

    cin >> firstCoef;
    cin >> secondCoef;
    cin >> thirdCoef;

    discriminant = secondCoef * secondCoef - 4 * firstCoef * thirdCoef;

    if (discriminant < 0)
    {
        cout << "not solvable in real numbers";
    }
    else if (discriminant == 0)
    {
        firstResult = -secondCoef / (2 * firstCoef);
        secondCoef = firstCoef;

        cout << "1 result: " << firstResult;
    }
    else
    {
        firstResult = -secondCoef + sqrt(discriminant) / (2 * firstCoef);
        secondResult = -secondCoef - sqrt(discriminant) / (2 * firstCoef);

        cout << "2 results: " << firstResult << " | " << secondResult;
    }
*/

/* 5/
int sideA;
    int sideB;
    int sideC;

    cin >> sideA;
    cin >> sideB;
    cin >> sideC;

    if (sideA + sideB >= sideC && sideA + sideC >= sideB && sideB + sideC >= sideA && sideA > 0 && sideB > 0 && sideC > 0)
    {
        cout << "valid";
    }
    else
    {
        cout << "no";
    }
*/

/* 4/
int gradePercentage;

    cin >> gradePercentage;

    if (gradePercentage >= 90 && gradePercentage <= 100)
    {
        cout << "6+";
    }
    else if (gradePercentage >= 80)
    {
        cout << "6";
    }
    else if (gradePercentage >= 70)
    {
        cout << "5";
    }
    else if (gradePercentage >= 60)
    {
        cout << "4";
    }
    else if (gradePercentage >= 40)
    {
        cout << "3";
    }
    else if (gradePercentage < 40)
    {
        cout << "2";
    }
    else
    {
        cout << "Out of range";
    }
*/

/*
int firstNumber;
    int secondNumber;
    int biggestNumber;

    cin >> firstNumber;
    cin >> secondNumber;

    biggestNumber = firstNumber >= secondNumber ? firstNumber : secondNumber;

    cout << "Bigger number is: " << biggestNumber;
*/

/* 1/
    int yearInput;
    cin >> yearInput;

    if (yearInput % 4 == 0)
    {
        if (yearInput % 100 == 0 && yearInput % 400 == 0) 
        {
            cout << "It's a leap yeaaaar! Hoooray!";
        }
        else 
        {
            cout << "not";
        }
    }
    else
    {
        cout << "no";
    }
*/

/*
char inputSymbol;
    cin >> inputSymbol;

    inputSymbol = tolower(inputSymbol);
    if (inputSymbol >= 'a' && inputSymbol <= 'z')
    {
        switch (inputSymbol)
        {
        case 'a':
        case 'i':
        case 'o':
        case 'u':
        case 'e':
            cout << "Vowel";
            break;
        default:
            cout << "Voweln't";
            break;
        }
    }*/