#include "QueueArr.h"
#include <iostream>
#define Q_SIZE 10

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
	if (m_front_ptr == m_back_ptr)
	{
		return 1;
	}
	return 0;
}

const bool Queue::isFull() const
{
	if (m_size == m_capacity - 1)
	{
		return 1;
	}
	return 0;
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
	if (ind > m_capacity - 1 || ind < 1)
	{
		std::cout << "wrong index. Try again" << std::endl;
		return;
	}

	int* ind_ptr = m_front_ptr + ind - 1;
	std::cout << *check_ptr(ind_ptr) << std::endl;
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
}

void Queue::clear()
{
	m_back_ptr = m_data;
	m_front_ptr = m_data;
}
