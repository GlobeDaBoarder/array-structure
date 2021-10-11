#include "QueueArr.h"
#include <iostream>
#define Q_SIZE 10

//private methods

int* Queue::increase_ptr(int* ptr)
{
	return  (ptr != m_data_end) ? ++ptr : m_data;
}


//public methods:


Queue::Queue()
	:m_data(new int[Q_SIZE]), m_capacity(Q_SIZE), m_back_ptr(m_data), m_front_ptr(m_data), m_size(0)
{
	m_data_end = m_data + m_capacity - 1;
}

Queue::~Queue()
{
	delete[] m_data;
}

void Queue::enqueue(int el)
{
	if (m_size == m_capacity - 1)
	{
		std::cout << "out of size" << std::endl;
		return;
	}

	*m_back_ptr = el;
	m_back_ptr = increase_ptr(m_back_ptr);
	++m_size;
}

void Queue::dequeue()
{
	if (m_back_ptr == m_front_ptr)
	{
		std::cout << "queue is empty. Nothing to delete" << std::endl; 
		return;
	}
	m_front_ptr = increase_ptr(m_front_ptr);
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
	if (ind_ptr > m_data_end)
	{
		ind_ptr = ind_ptr - m_capacity;
	}
	std::cout << *ind_ptr;
}