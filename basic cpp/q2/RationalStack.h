#ifndef RATIONAL_STACK_H
#define RATIONAL_STACK_H
/**
 * @file	RationalStack.cpp
 *
 * @brief	Day 1 - Homework Exercise 1C
 *
 * 	Create a simple Stack of Rational (fractions) of predefined size
 *		default CTOR
 *		mem-function:	push	push Rational
 *		mem-function:	push	push array of Rationals
 *		mem-function:	pop		pop Rational from Stack
 * 		mem-function:	top		peek at the top of the Stack
 *		mem-function:	isFull() and isEmpty()
 *		mem-function:	size() returns current number of elements
 *		mem-function:	print() the current stack
 *		mem-function:	trace() for trace/debug -> print all data
 *
 * @author	Alex-The-Teacher (inspired by MhZ alias TryFinally)
 * @note	Provide this file to students (via Slack)
 */

#include <cstddef>		// size_t
#include "Rational.h"

#define RATIONAL_STACK_SIZE 8

class RationalStack
{
public:
// Default CTOR
	RationalStack();

// Operators:
//	Push element, return success
//	Push array, return number of items pushed
	bool	push(Rational a_item);
	size_t	push(Rational a_items[], size_t a_size);

//	Pop element, return success
	Rational	pop();
	Rational	top() const;

// Information:
//	boundary check
	bool isFull() const;
	bool isEmpty() const;
//	number of items
	size_t size() const;

// print the contents of the stack
	void print() const;
	void trace() const;

// Private (support) mem-functions
private:
	void dump(const char* a_header, size_t a_n) const;

// Private members
private:
	size_t		m_top;
	Rational	m_items[RATIONAL_STACK_SIZE];
};

#endif	/* RATIONAL_STACK_H */
