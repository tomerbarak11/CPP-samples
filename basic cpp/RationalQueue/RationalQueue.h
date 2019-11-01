#ifndef RATIONAL_QUEUE_H
#define RATIONAL_QUEUE_H
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

#include "Rational.h"
#include "DynamicRationalStack.h"

const size_t g_DEFAULT_QUEUE_SIZE = 8;

class RationalQueue
{
public:
//  CTOR
	RationalQueue(size_t a_capacity = g_DEFAULT_QUEUE_SIZE);

// Insert element / array
	bool   enqueue(const Rational& a_rational);
	size_t enqueue(Rational a_rationals[], size_t a_size);

// Remove element / array
	bool   dequeue(Rational& a_rational);
	size_t dequeue(Rational a_rationals[], size_t a_size);

// boundary check
	bool isFull() const;
	bool isEmpty() const;
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
	DynamicRationalStack	m_enStack;
	DynamicRationalStack	m_deStack;
};

#endif	/* RATIONAL_QUEUE_H */
