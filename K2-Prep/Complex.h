#pragma once
#include <iostream>

class Complex
{
private:
	double real;
	double imaginary;
public:
	double getReal() const;
	double getImaginary() const;

	Complex& setReal(double realPart);
	Complex& setImaginary(double imPart);

	const Complex complexConjugated() const;

	Complex& operator+=(const Complex& other);
	Complex operator+(const Complex& other);

	Complex& operator-=(const Complex& other);
	Complex operator-(const Complex& other);

	Complex& operator*=(const Complex& other);
	Complex operator*(const Complex& other);

	Complex& operator/=(const Complex& other);
	Complex operator/(const Complex& other);

	bool operator==(const Complex& other);
	bool operator!=(const Complex& other);

	friend std::ostream& operator<<(std::ostream& os, const Complex& num);
	friend std::istream& operator>>(std::istream& is, Complex& num);
};