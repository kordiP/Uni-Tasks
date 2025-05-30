#pragma once
#include <iostream>

template <typename T>
class MyVector
{
private:
	T* data;
	size_t size;
	size_t capacity;

	void copyFrom(const MyVector& other);
	void freeMem();
	void resize();
	size_t getCapacity() const;
public:
	MyVector();
	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	~MyVector();

	void pushBack(const T& element);
	T popBack();
	void insert(const T& element, int pos);
	void removeAt(int pos);
	void remove(T& element);
	const T& operator[](int index) const;
	T& operator[](int index);
	bool contains(const T& element) const;
	size_t getSize() const;
	void print() const;
	void clear();
};

template<typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
void MyVector<T>::freeMem()
{
	delete[] data;
}

template<typename T>
void MyVector<T>::resize()
{
	capacity *= 2;
	T* temp = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	freeMem();
	data = temp;
}

template<typename T>
MyVector<T>::MyVector() : size(0), capacity(4)
{
	data = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		freeMem();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
MyVector<T>::~MyVector()
{
	freeMem();
}

template<typename T>
void MyVector<T>::pushBack(const T& element)
{
	if (size >= capacity)
	{
		resize();
	}

	data[size++] = element;
}

template<typename T>
T MyVector<T>::popBack()
{
	if (size <= 0)
	{
		throw std::out_of_range("Zero size.");
	}
	return data[--size];
}

template<typename T>
void MyVector<T>::insert(const T& element, int pos)
{
	if (pos < 0 || pos >= size)
	{
		throw std::out_of_range("Cannot insert, out of range.");
	}

	if (size + 1 >= capacity)
	{
		resize();
	}

	T temp = data[pos];
	data[pos] = element;

	for (size_t i = pos + 1; i < size; i++)
	{
		T temp1 = data[i];
		data[i] = temp;
		temp = temp1;
	}

	data[size++] = temp;
}

template<typename T>
void MyVector<T>::removeAt(int pos)
{
	if (pos < 0 || pos >= size)
	{
		throw std::out_of_range("Invalid, must be more than 0 and less than size.");
	}

	for (size_t i = pos; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	size--;
}

template<typename T>
void MyVector<T>::remove(T& element)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] == element)
		{
			for (size_t j = i; j < size - 1; ++j)
			{
				data[j] = data[j + 1];
			}

			return;
		}
	}
}

template<typename T>
const T& MyVector<T>::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Invalid more than 0 and less than size.");
	}

	return data[index];
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Invalid more than 0 and less than size.");
	}

	return data[index];
}

template<typename T>
bool MyVector<T>::contains(const T& element) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
}

template<typename T>
size_t MyVector<T>::getSize() const
{
	return size;
}

template<typename T>
size_t MyVector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
void MyVector<T>::print() const
{
	for (size_t i = size - 1; i >= 0; i--)
	{
		std::cout << data[i];
	}
}

template<typename T>
void MyVector<T>::clear()
{
	size = 0;
}
