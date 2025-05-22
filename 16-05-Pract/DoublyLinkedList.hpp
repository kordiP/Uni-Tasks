#pragma once

template <typename T>
class DoublyLinkedList
{
private:
	struct Node
	{
	public:
		Node* next = nullptr;
		Node* previous = nullptr;
		T data;
	};

	Node* head;

	void freeMem();

	void returnHeadToStart();
	void returnHeadToBack();
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other) = delete;
	DoublyLinkedList& operator=(const DoublyLinkedList& other) = delete;
	~DoublyLinkedList();

	T& front();
	T& back();
	bool empty() const;
	size_t size() const;
	void clear();
	void pushBack(const T& obj);
	T& popBack();
	void pushFront(const T& obj);
	T& popFront();

	T& operator[](size_t);
	const T& operator[](size_t) const;
};

template<typename T>
void DoublyLinkedList<T>::freeMem()
{
	returnHeadToStart();

	while (head != nullptr)
	{
		head = head->next;
		delete[] head->previous;
	}
}

template<typename T>
void DoublyLinkedList<T>::returnHeadToStart()
{
	while (head.previous != nullptr)
	{
		head = head.previous;
	}
}

template<typename T>
void DoublyLinkedList<T>::returnHeadToBack()
{
	while (head.next != nullptr)
	{
		head = head.next;
	}
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = nullptr;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	freeMem();
}

template<typename T>
T& DoublyLinkedList<T>::front()
{
	returnHeadToStart();

	return head->data;
}

template<typename T> 
T& DoublyLinkedList<T>::back()
{
	returnHeadToBack();
	
	return head->data;
}

template<typename T>
bool DoublyLinkedList<T>::empty() const
{
	if (head != nullptr)
	{
		return false;
	}

	return true;
}

template<typename T>
size_t DoublyLinkedList<T>::size() const
{
	size_t sz = 0;
	if (empty())
	{
		return sz;
	}

	returnHeadToStart();
	while (head.next != nullptr)
	{
		sz++;
		head = head->next;
	}

	return sz;
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
	freeMem();
}

template<typename T>
void DoublyLinkedList<T>::pushBack(const T& obj)
{
	Node newN;
	newN.data = obj;
	
	if (head == nullptr)
	{
		head = newN;
	}
	else
	{
		returnHeadToBack();
		head.next = newN;
		newN.previous = head;
	}
}

template<typename T>
T& DoublyLinkedList<T>::popBack()
{
	returnHeadToBack();
	return head.data;
}

template<typename T>
void DoublyLinkedList<T>::pushFront(const T& obj)
{
	Node newN;
	newN.data = obj;

	if (head == nullptr)
	{
		head = newN;
	}
	else
	{
		returnHeadToStart();
		head.previous = newN; 
		newN.next = head;
	}
}

template<typename T>
T& DoublyLinkedList<T>::popFront()
{
	returnHeadToStart();
	return head.data;
}

template<typename T>
T& DoublyLinkedList<T>::operator[](size_t index)
{
	if (index >= size())
	{
		throw std::out_of_range("Too big.");
	}

	returnHeadToStart();
	for (size_t i = 0; i < index; i++)
	{
		head = head->next;
	}

	return head.data;
}

template<typename T>
const T& DoublyLinkedList<T>::operator[](size_t index) const
{
	if (index >= size())
	{
		throw std::out_of_range("Too big.");
	}

	returnHeadToStart();
	for (size_t i = 0; i < index; i++)
	{
		head = head->next;
	}

	return head.data;
}
