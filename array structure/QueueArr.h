#pragma once

#define Q_SIZE 10

class Queue
{
private:
	int* m_data;
	int* m_front_ptr;
	int* m_back_ptr;
	size_t m_size;
	size_t m_capacity;
private:
	int*& check_ptr(int*&);

public:
	Queue();
	~Queue();
	const bool isEmty() const;
	const bool isFull() const;
	void enqueue(int);
	void dequeue();
	void peek(int);
	void front() const;
	void size() const;
	void display();
	void clear();
	void reverse();
};

void PrintInstructions();
