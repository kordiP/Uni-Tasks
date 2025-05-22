#include "Complex.h"

double Complex::getReal() const
{
	return real;
}

double Complex::getImaginary() const
{
	return imaginary;
}

Complex& Complex::setReal(double realPart)
{
	this->real = realPart;

	return *this;
}

Complex& Complex::setImaginary(double imPart)
{
	this->imaginary = imPart;

	return *this;
}

const Complex Complex::complexConjugated() const
{
	Complex c;

	c.setReal(this->real);
	c.setImaginary(this->getImaginary() * (-1));

	return c;
}

Complex& Complex::operator+=(const Complex& other)
{
	real += other.real;
	imaginary += other.imaginary;
	return *this;
}

Complex Complex::operator+(const Complex& other)
{
	Complex c;
	c.setReal(real + other.real);
	c.setImaginary(imaginary + other.imaginary);
	return c;
}
// everything beyond is the same
Complex& Complex::operator-=(const Complex& other)
{
	return *this;
}

Complex Complex::operator-(const Complex& other)
{
	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	return *this;
}

Complex Complex::operator*(const Complex& other)
{
	return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
	return *this;
}

Complex Complex::operator/(const Complex& other)
{
	return *this;
}

bool Complex::operator==(const Complex& other)
{
	return false;
}

bool Complex::operator!=(const Complex& other)
{
	return false;
}

std::ostream& operator<<(std::ostream& os, const Complex& num)
{
	os << num.real << " " << num.imaginary << "*i";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& num)
{
	is >> num.real;
	is >> num.imaginary;
	// ?
	return is;
}
