#include "QueueArr.h"
#include <iostream>
#define Q_SIZE 11

//private methods

int*& Queue::check_ptr(int*& ptr)
{
	if (ptr > m_data + m_capacity - 1)
	{
		ptr = ptr - m_capacity;
	}
	return ptr;
}


//public methods:


Queue::Queue()
	:m_data(new int[Q_SIZE]), m_capacity(Q_SIZE), m_back_ptr(m_data), m_front_ptr(m_data), m_size(0)
{
}

Queue::~Queue()
{
	delete[] m_data;
}

const bool Queue::isEmty() const
{
	return (m_size == 0);
}

const bool Queue::isFull() const
{
	return (m_size == m_capacity - 1);
}

void Queue::enqueue(int el)
{
	if (this->isFull())
	{
		std::cout << "out of size" << std::endl;
		return;
	}

	*m_back_ptr = el;
	m_back_ptr = check_ptr(++m_back_ptr);
	++m_size;
}

void Queue::dequeue()
{
	if (this->isEmty())
	{
		std::cout << "queue is empty. Nothing to delete" << std::endl; 
		return;
	}
	m_front_ptr = check_ptr(++m_front_ptr);
	--m_size;
}


void Queue::peek(int ind)
{
	if (ind > m_size || ind < 1)
	{
		std::cout << "Index ou of bounds of the queue" << std::endl;
		return;
	}

	int* ind_ptr = m_front_ptr + ind - 1;
	std::cout << "element with index #" << ind << "is " << *check_ptr(ind_ptr) << std::endl;
}

void Queue::front() const
{
	std::cout << "Front element is: " <<  * m_front_ptr << std::endl;
}

void Queue::size() const
{
	std::cout << "size is: " << m_size << std::endl;
}

void Queue::display() 
{
	int* it = m_front_ptr;
	std::cout << "All elements of queue:" << std::endl;
	while (it != m_back_ptr)
	{
		std::cout << *it << ' ';
		it = check_ptr(++it);
	}
	std::cout << std::endl;
}

void Queue::clear()
{
	m_back_ptr = m_data;
	m_front_ptr = m_data;
	m_size = 0;

	std::cout << "The queue is cleared!" << std::endl;
}



void Queue::reverse()
{
	int* el_copy = new int[m_size];
	int* it = m_front_ptr;
	for (int i = 0; i < m_size; ++i)
	{
		el_copy[i] = *it;
		check_ptr(++it);
	}

	it = m_front_ptr;
	for (int i = m_size - 1; i >= 0; --i)
	{
		*it = el_copy[i];
		check_ptr(++it);
	}

	std::cout << "The queue is reversed!" << std::endl;

	delete[] el_copy;
}