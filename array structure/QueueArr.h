#pragma once

#define Q_SIZE 10

class Queue
{
private:
	int* m_data;
	int* m_data_end;
	int* m_front_ptr;
	int* m_back_ptr;
	size_t m_size;
	size_t m_capacity;
private:
	int* increase_ptr(int*);

public:
	Queue();
	~Queue();
	void enqueue(int);
	void dequeue();
	void peek(int);
	int front();
	bool isEmty();
	bool isFull();
	void display();
	void clear();
	size_t size();
	void reverse();
};