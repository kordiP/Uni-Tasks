#include "NVector.h"

void NVector::freeMem()
{
	delete[] data;
	data = nullptr;
}

void NVector::copyFrom(const NVector& other)
{
	dataSize = other.dataSize;
	data = new double[dataSize];

	for (size_t i = 0; i < dataSize; i++)
	{
		data[i] = other.data[i];
	}
}

NVector::NVector()
{
	dataSize = 0;
	data = nullptr;
}

NVector::NVector(int size)
{
	this->dataSize = size;
	data = new double[size];
}

NVector::NVector(const NVector& other)
{
	copyFrom(other);
}

NVector& NVector::operator=(const NVector& other)
{
	if (this != &other)
	{
		freeMem();
		copyFrom(other);
	}

	return *this;
}

NVector::~NVector()
{
	freeMem();
}

NVector& NVector::operator+=(const NVector& other)
{
	if (dataSize != other.dataSize)
		throw std::invalid_argument("The vectors should have the same size!");

	for (int i = 0; i < dataSize; i++)
		data[i] += other.data[i];

	return *this;
}

NVector& NVector::operator-=(const NVector& other)
{
	if (dataSize != other.dataSize)
		throw std::invalid_argument("The vectors should have the same size!");

	for (int i = 0; i < dataSize; i++)
		data[i] -= other.data[i];

	return *this;
}

NVector& NVector::operator*=(double num)
{
	for (int i = 0; i < dataSize; i++)
	{
		data[i] *= num;
	}

	return *this;
}

// get only
double NVector::operator[](int index) const
{
	if (index >= dataSize)
	{
		throw std::out_of_range("Index out of range.");
	}

	return data[index];
}

// get or set, because double& allows change to the num from data at index
double& NVector::operator[](int index)
{
	if (index >= dataSize)
	{
		throw std::out_of_range("Index out of range.");
	}

	return data[index];
}

// return size
int NVector::operator~() const
{
	return dataSize;
}

std::ostream& operator<<(std::ostream& os, const NVector& vec)
{
	os << "< ";
	for (size_t i = 0; i < vec.dataSize; i++)
	{
		os << vec.data[i] << ", ";
	}
	os << "> " << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, const NVector& vec)
{
	for (int i = 0; i < vec.dataSize; i++)
	{
		is >> vec[i];
	}

	return is;
}

NVector operator+(const NVector& lhs, const NVector& rhs)
{
	NVector result(lhs);
	result += rhs;

	return result;
}

NVector operator-(const NVector& lhs, const NVector& rhs)
{
	NVector result(lhs);
	result -= rhs;

	return result;
}

NVector operator*(const NVector& lhs, double scalar)
{
	NVector result(lhs);
	result *= scalar;
	
	return result;
}

NVector operator*(double scalar, const NVector& rhs)
{
	NVector result;
	result *= scalar;

	return result;
}

// dot product / scalar multiplication
double operator%(const NVector& lhs, const NVector& rhs)
{
	if (~lhs != ~rhs)
		throw "The vectors should have the same size!";

	size_t res = 0;
	for (int i = 0; i < ~lhs; i++)
		res += lhs[i] * rhs[i];

	return res;
}

// if this and other are colinear
bool operator||(const NVector& lhs, const NVector& rhs)
{
	// don't understand
	const double EPSILON = 1e-6;
	if (~lhs != ~rhs) {
		throw "The vectors should have the same size!";
	}

	double ratio = 0.0;
	bool ratioSet = false;

	for (size_t i = 0; i < ~lhs; ++i)
	{
		// Skip if both components are zero
		if (abs(lhs[i]) < EPSILON && abs(rhs[i]) < EPSILON)
		{
			continue;
		}
		// If one component is zero but the other is not, vectors are not parallel
		if (abs(lhs[i]) < EPSILON || abs(rhs[i]) < EPSILON)
		{
			return false;
		}

		// Calculate the ratio of the current components
		double currentRatio = (double)lhs[i] / rhs[i]; //we guarantee that rhs is not 0
		// If the ratio is not set, set it. Otherwise, compare it with the current ratio
		if (!ratioSet)
		{
			ratio = currentRatio;
			ratioSet = true;
		}
		else if (std::abs(ratio - currentRatio) > EPSILON)
		{ // Use a small epsilon for floating point comparison
			// If the ratios are different, vectors are not parallel
			return false;
		}
	}
	return true;
}

// if this and other are perpendicular
bool operator|=(const NVector& lhs, const NVector& rhs)
{
	return lhs % rhs == 0;
}
