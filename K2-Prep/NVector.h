#pragma once
#include <iostream>
// N-dimensional vector, as a geometrical vector
class NVector
{
private:
	double* data;
	int dataSize;

	void freeMem();
	void copyFrom(const NVector& other);
public:
	NVector();
	NVector(int size);
	NVector(const NVector& other);
	NVector& operator=(const NVector& other);
	~NVector();

	NVector& operator+=(const NVector& other);

	NVector& operator-=(const NVector& other);

	NVector& operator*=(double num);

	double operator[](int index) const; // get only
	double& operator[](int index); // get or set, because double& allows change to the num from data at index

	// return size
	int operator~() const;

	friend std::ostream& operator<<(std::ostream& os, const NVector& vec);
	friend std::istream& operator>>(std::istream& is, const NVector& vec);
}; 

NVector operator+(const NVector& lhs, const NVector& rhs);

NVector operator-(const NVector& lhs, const NVector& rhs);

NVector operator*(const NVector& lhs, double scalar);	
NVector operator*(double scalar, const NVector& rhs);	

// dot product / scalar multiplication
double operator%(const NVector& lhs, const NVector& rhs);

// if this and other are colinear
bool operator||(const NVector& lhs, const NVector& rhs);

// if this and other are perpendicular
bool operator|= (const NVector& lhs, const NVector& rhs);