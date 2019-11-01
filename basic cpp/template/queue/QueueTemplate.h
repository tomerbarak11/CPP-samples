#ifndef QUEUE_TEMPLATE_H
#define QUEUE_TEMPLATE_H
/**
 * @file	RationalQueue.h
 *
 * @brief	Day 2 - Homework Exercise 2C - Definition
 *		Create a simple Queue made of two Stacks (constant size)
 *		+	CTOR
 *		+	mem-function:	enqueue single Rational
 *		+	mem-function:	enqueue array of Rationals
 *		+	mem-function:	dequeue single Rational
 *		+	mem-function:	dequeue array of Rationals
 *		+	mem-function:	isFull() and isEmpty()
 *		+	mem-function:	size()		returns current number of items
 *		+	mem-function:	print()		print the current stack
 *			mem-function:	trace()		trace/debug print all data
 *
 * @author	Alex-The-Teacher (inspired by MhZ alias TryFinally)
 * @note	Provide this file to students (via Slack)
 */

#include <cstddef>
#include <cassert>
#include <iostream>

const size_t g_DEFAULT_QUEUE_SIZE = 8;

template <typename T>
class TemplateQueue
{
public:
//  CTOR
	TemplateQueue(size_t a_capacity = g_DEFAULT_QUEUE_SIZE);
	TemplateQueue(T const& a_other);
	~TemplateQueue();
	TemplateQueue& operator=(TemplateQueue const& a_item);
	// Insert element / array
	bool   enqueue(const T& a_item);
	size_t enqueue(T a_item[], size_t a_size);

// Remove element / array
	bool   dequeue(T& a_item);
	size_t dequeue(T a_item[], size_t a_size);

// boundary check
	bool isFull() const;
	bool isEmpty() const;
	bool front(T& a_item);

// size
	size_t size() const;
	size_t capacity() const;

// print the contents of the stack
	void print() const;
	void trace() const;

// Private mem-functions
private:
	void dump(const char* a_header, size_t a_n) const;

// Private members
private:
	size_t m_capacity;
	size_t m_head;
	size_t m_tail;
	size_t m_size;
	T	*m_items;
};

template <typename T>
TemplateQueue<T>::TemplateQueue(size_t a_initialCapacity)
:m_capacity(a_initialCapacity)
,m_head(0)
,m_tail(-1)
,m_size(0)
{
	m_items=new T[m_capacity];
	assert(m_items);	
	assert(a_initialCapacity>0);
}

template <typename T>
TemplateQueue<T>::TemplateQueue(T const& a_other)
:m_capacity(a_other.m_capacity)
,m_head(a_other.m_head)
,m_tail(a_other.m_tail)
,m_size(a_other.m_size)
{
	delete [] m_items;
	m_items=new T[m_capacity];
	assert(m_items);	
	assert(m_capacity>0);
}

template <typename T>
TemplateQueue<T>::~TemplateQueue()
{
	delete [] m_items;
}

template <typename T>
TemplateQueue<T>& TemplateQueue<T>::operator=(TemplateQueue const& a_item)
{
	if(this!=a_item)
	{
		delete [] m_items;
		m_capacity=a_item.m_capacity;
		m_items=new T[m_capacity];
		m_head=a_item.m_head;
		m_tail=a_item.m_tail;
		while(m_head!=m_tail)
		{
			if(enqueue(a_item)==false)
			{
				return 0;
			}
		}
		
		assert(m_items);
		assert(m_capacity>0);	
		return *this;
	}
	return *this;
}

template <typename T>
bool TemplateQueue<T>::enqueue(const T& a_item)
{
	if(isFull()==true)
	{
		return false;
	}
	m_tail=(m_tail+1)%m_capacity;
	m_items[m_tail]=a_item;
	m_size++;
	return true;
}

template <typename T>
size_t TemplateQueue<T>::enqueue(T a_items[], size_t a_size)
{
	for(int i=0;i<a_size;i++)
	{
		if(isFull()==true)
		{
			return i;
		}
		m_tail=(m_tail+1)%m_capacity;
		m_items[m_tail]=a_items[i];
		m_size++;
	}
	return a_size;
}

template <typename T>
bool TemplateQueue<T>::dequeue(T& a_item)
{
	if(isEmpty()==true)
	{
		return false;
	}
	a_item=m_items[m_head];
	m_head=(m_head+1)%m_capacity;
	m_size--;
	return true;
}

template <typename T>
size_t TemplateQueue<T>::dequeue(T a_items[], size_t a_size)
{
	for(int i=0;i<a_size;i++)
	{
		if(isEmpty()==true)
		{
			return i;
		}
		a_items=m_items[m_head];
		m_head=(m_head+1)%m_capacity;
		m_size--;
	}
	return a_size;
}

template <typename T>
bool TemplateQueue<T>::isFull() const
{
	return (m_size==m_capacity)?true:false;
}

template <typename T>
bool TemplateQueue<T>::isEmpty() const
{
	return (m_size==0)?true:false;
}

template <typename T>
size_t TemplateQueue<T>::size() const
{
	return m_size;
}

template <typename T>
size_t TemplateQueue<T>::capacity() const
{
	return m_capacity;
}

template <typename T>
void TemplateQueue<T>::print() const
{
	dump("Printing\n",m_size);
}

template <typename T>
void TemplateQueue<T>::trace() const
{
	dump("Tracing\n",m_capacity);
}

template <typename T>
bool TemplateQueue<T>::front(T& a_item)
{
	if(isEmpty()==true)
	{
		return false;
	}	
	 a_item=m_items[m_head];
	 return true;
}

template <typename T>
void TemplateQueue<T>::dump(const char* a_header, size_t a_n) const
{
	size_t i;
	std::cout<<a_header;
	for(i=0;i<a_n;i++)
	{
		std::cout<<m_items[(i+m_head)%m_capacity];
		std::cout<<"\n";
	}	
}

#endif	/* RATIONAL_QUEUE_H */
