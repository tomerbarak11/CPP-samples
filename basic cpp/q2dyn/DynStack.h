#ifndef DYN_STACK_H
#define DYN_STACK_H
/**
 *	@file DynStack.h
 *
 *	@brief	Define Dynamic Stack of int's with specified (at CTOR) capacity
 *
 */

#include <cstddef>		// size_t
#include <iostream>


class DynStack {
public:
// CTOR
	DynStack(size_t a_capacity = s_DEFAULT_STACK_CAPACITY);
	DynStack(DynStack const& a_other);
// DTOR
	~DynStack();

// mem-functions
// Operations
	bool push(int a_value);
	bool pop(int& a_value);
	bool top(int& a_value) const;

// State
	bool isFull() const;
	bool isEmpty() const;

	// automatic inline in-body
	//		size_t size() const { return m_top; }
	size_t size() const;
	size_t capacity() const;

// print the contents of the stack
	void print(std::ostream& a_os = std::cout) const;
	void trace(std::ostream& a_os = std::cout) const;
// Private mem-functions
private:
	void dump(std::ostream& a_os, const char* a_header, size_t a_n) const;

// Data members
private:
const	size_t	m_capacity;
		size_t	m_top;
		int*	m_items;

static const size_t s_DEFAULT_STACK_CAPACITY = 16;

};

// All state and accessors are inline
inline bool DynStack::isFull() const
{
	return (m_top == m_capacity);
}

inline bool DynStack::isEmpty() const
{
	return (m_top == 0);
}

inline size_t DynStack::size() const
{
	return m_top;
}

inline size_t DynStack::capacity() const
{
	return m_capacity;
}

#endif // DYN_STACK_H
