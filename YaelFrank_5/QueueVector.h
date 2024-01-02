#pragma once

#include "Queue.h"
template <class T>
class QueueVector:public Queue<T>
{

	T* data;
	int capacity;
	int head;
	int rear;

    public:
		QueueVector(int c = 100);
		~QueueVector();
		QueueVector(const QueueVector& other);
		void clear();
		void enqueue(T value);
		T dequeue();
		T front() const;
		bool isEmpty() const;
};

//ממוש הפונקציות
template <class T>
QueueVector<T>::QueueVector(const QueueVector& other) 
{
	capacity = other.capacity;
	data = new T[capacity];
	head = other.head;
	rear = other.rear;
	for (int i = head; i < rear; i++)
	{
		data[i] = other.data[i];
	}
}
template <class T>
QueueVector<T>::QueueVector(int c)
{
	capacity = c+1;
	data = new T[capacity];
	head = rear = 0;
}
template <class T>
QueueVector<T>::~QueueVector() 
{
	delete[] data;
}
template <class T>
void QueueVector<T>::clear()
{
 head= rear = 0;
}
template <class T>
void QueueVector<T>::enqueue(T value)
{
	if ((rear + 1) % capacity == head % capacity)
		throw ("Error: Queue is full. No more elements can be inserted.");
	else
	{
		data[rear] = value;
		rear = (rear + 1) % capacity;
	}
}
template <class T>
T QueueVector<T>::dequeue()
{
	if (head == rear)
		throw ("Error: Queue is empty.");
	else
	{
		T value = data[head];
		head = (head + 1) % capacity;
		return value;
	}
}
template <class T>
T QueueVector<T>::front()const
{
	if (head == rear)
		throw ("Error: Queue is empty.");
	return data[head % capacity];
}
template <class T>
bool QueueVector<T>::isEmpty()const {
	return head == rear;
}
