#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H
#define STACK_CAPACITY 64
/**
 * @file	Stack.h
 * @brief	Day 5 - Class Exercise 5A
 *
 * Convert Stack (fixed capacity from Day 1) into template
 *
 * Implement all required functions
 *
 */

#include <cstddef>
#include <iostream>
#include "stdio.h"

template<typename T>
class Stack
{
public:
	Stack(size_t a_capacity = 64);
	~Stack();
	Stack(Stack const& a_other);
	Stack& operator=(Stack const& a_rhs);

	bool push(T const& a_value);
	size_t pushAll(T const a_values[], size_t a_n);

	bool pop(T& a_value);
	bool top(T& a_top) const;

	size_t drain(Stack& a_destination);

	bool isFull() const;
	bool isEmpty() const;

	size_t size() const;
	size_t capacity() const;

private:
	size_t	m_capacity;
	size_t	m_top;
	T		*m_items;
};

template<typename T>
std::ostream& operator<<(std::ostream& a_os, Stack<T> const& a_rhs);

/*******************************************************************/
template<typename T>
Stack<T>::Stack(size_t a_capacity)
:m_capacity(a_capacity)
,m_top(0)
{
	m_items=new T[m_capacity];
	for(size_t i=0;i<STACK_CAPACITY;i++)
	{
		m_items[i]=0;
	}
	
}

template<typename T>
Stack<T>::Stack(Stack const& a_other)
:m_capacity(a_other.capacity())
,m_top(a_other.top())
{
	delete [] m_items;
	m_items=new T[m_capacity];
	for(size_t i=0;i<a_other.size();i++)
	{
		push(a_other.m_items[i]);
	}	
}

template<typename T>
Stack<T>::~Stack()
{
delete [] m_items;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack const& a_rhs)
{
	m_top=a_rhs.top();
	m_capacity=a_rhs.capacity();	
	delete [] m_items;
	m_items=new T[m_capacity];
	if(0==m_items)
	{
		return 0;
	}
	for(size_t i=0;i<a_rhs.size();i++)
	{
		push(a_rhs.m_items[i]);
	}
}

template<typename T>
bool Stack<T>::push(T const& a_value)
{
	if(isFull()==true)
	{
		return false;
	}
	m_items[m_top+1]=a_value;
	m_top++;
	return true;
}

template<typename T>
size_t Stack<T>::pushAll(T const a_values[], size_t a_n)
{
	if(isFull()==true)
	{
		return 0;
	}
	for(int i=0;i<a_n;i++)
	{
		if(isFull()==true)
		{
			return i;
		}
		push(a_values.m_items[i]);
		m_top++;
	}
	return a_n;
}

template<typename T>
bool Stack<T>::pop(T& a_value)
{
	if(isEmpty()==true)
	{
		return false;
	}
	a_value=m_items[m_top];
	m_top--;
	return true;
}

template<typename T>
bool Stack<T>::isFull() const
{
	if(m_top==m_capacity)
	{
		return true;
	}
	return false;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	if(m_top==0)
	{
		return true;
	}
	return false;
}

template<typename T>
bool Stack<T>::top(T& a_top) const
{
	if(isEmpty()==true)
	{
		return false;
	}
	a_top=m_items[m_top-1];
	return true;
}

template<typename T>
size_t Stack<T>::drain(Stack& a_destination)
{
	size_t count=0;
	T popped;
	for(int i=m_top-1;i>=0;i--)
	{
		if(isEmpty()==true)
		{
			break;
		}
		pop(a_destination);
		push(a_destination);
		count++;
	}
	return count;
}

template<typename T>
size_t Stack<T>::size() const
{
	return m_top;
}

template<typename T>
size_t Stack<T>::capacity() const
{
	return STACK_CAPACITY;
}

#endif	// STACK_TEMPLATE_H

