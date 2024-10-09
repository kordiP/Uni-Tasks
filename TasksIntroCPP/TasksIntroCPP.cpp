#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	
}

// 1) cout << "Oh what\na happy day!\nOh yes,\nwhat a happy day!\n";

/* 2) 
	double side1 = 5.4, side2 = 7.9;
	double area = side1 * side2;
	double perimeter = 2 * side1 + 2 * side2;

	cout << "Area: " << area << "\nPerimeter: " << perimeter;
*/

/* 3)
	double amountBGN, amountUSD, amountEUR;

	cin >> amountBGN;

	amountUSD = 0.56 * amountBGN;
	amountEUR = 0.51 * amountBGN;

	cout << "EUR: " << amountEUR << "\nUSD: " << amountUSD;
*/

/* 4)
	double side1, side2, area, perimeter;

	cout << "Please enter the length of the first side: ";
	cin >> side1;

	cout << "Thanks, now the length of the second side: ";
	cin >> side2;

	area = side1 * side2;
	perimeter = 2 * side1 + 2 * side2;

	cout << "Area: " << area << "\nPerimeter: " << perimeter;
*/

/* 5)
	int num1, num2;
	cin >> num1 >> num2;
	if (num1 > num2)
	{
		cout << "false";
	}
	else 
	{
		cout << "true";
	}
*/

/* 6)
	int num1, num2, remainder, quotient;
	cin >> num1 >> num2;

	quotient = num1 / num2;
	remainder = num1 % num2;

	cout << "The quotient of the division is: " << quotient << "\nThe remainder of the division is: " << remainder;
*/

/* 7)
	int applesCount, pearsCount, bananasCount;

	cout << "Apples: ";
	cin >> applesCount;

	cout << "Pears: ";
	cin >> pearsCount;

	cout << "Bananas: ";
	cin >> bananasCount;

	cout << "Pesho, don't forget to buy " << applesCount << " apples, " << pearsCount << " pears and " << bananasCount << " bananas!";
*/

/* 8)
	double radius, circumference, area;
	const double PI = 3.14159265;

	cin >> radius;

	circumference = 2 * PI * radius;
	area = PI * radius * radius;

	cout << "Circumference: " << circumference << "\nArea: " << area;
*/

/* 9)
	double coefA, coefB, coefC, result1, result2, discriminant;

	cout << "Enter a: ";
	cin >> coefA;

	cout << "Enter b: ";
	cin >> coefB;

	cout << "Enter c: ";
	cin >> coefC;

	discriminant = pow(coefB, 2) - (4 * coefC * coefA);

	if (discriminant > 0)
	{
		result1 = (( - coefB + sqrt(discriminant)) / 2 * coefA);
		result2 = ((-coefB - sqrt(discriminant)) / 2 * coefA);
		cout << "x1: " << result1 << "\nx2: " << result2;
	}
	else if (discriminant == 0)
	{
		result1 = (-1 * coefB) / 2 * coefA;
		cout << "x1 = x2 : " << result1;
	}
	else 
	{
		cout << "No solutions in real numbers";
	}
*/

/* 10)
	int num1, num2, tmp;
	cin >> num1 >> num2;

	tmp = num2;
	num2 = num1;
	num1 = tmp;

	cout << "num1: " << num1 << "\nnum2: " << num2;
*/

/* 11)
	int num1, num2, maxNum, minNum;
	cin >> num1 >> num2;

	maxNum = max(num1, num2);
	minNum = min(num1, num2);

	cout << "min: " << minNum << "\nmax: " << maxNum;
*/

/* 12)
	int seconds, minutes, hours, days;
	
	cin >> seconds;

	minutes = seconds / 60;
	hours = minutes / 60;
	days = hours / 24;

	seconds -= minutes * 60;
	minutes -= hours * 60;
	hours -= days * 24;

	cout << days << " days, " << hours << " hours, " << minutes << " minutes and " << seconds << " seconds";
*/

/* 13)
	double x1, y1, x2, y2, distance;

	cout << "x1: ";
	cin >> x1;
	cout << "y1: ";
	cin >> y1;
	cout << "x2: ";
	cin >> x2;
	cout << "y2: ";
	cin >> y2;

	distance = sqrt(pow(x2 - x1,2) + pow(y2-y1, 2));
	
	cout << "distance: " << distance;
*/

/* 14)
	long long cardNumber;
	int lastFour;

	cin >> cardNumber;
	
	lastFour = cardNumber % 10000;

	cout << "XXXXXXXXXXXX" << lastFour;
*/
