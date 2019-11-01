#ifndef DYNAMIC_RATIONAL_STACK_H
#define DYNAMIC_RATIONAL_STACK_H
/**
 * @file	DynamicRationalStack.h
 *
 * @brief	Day 2 - Homework Exercise 2B
 * 		Create a Dynamic Stack of Rational (fractions) objects
 * 		Stack will start with initial capacity
 *		It will grow on demand by a given factor defaulted to 1.5;
 *		It will not shrink
 *		+	CTOR, DTOR, CCTOR, op=
 * 		+	push(Rational const &)	push new item
 * 		+	push(Rational [])		push array of items
 * 		+	pop(Rational &)			remove
 * 		+	top(Rational &)			peek at top of stack
 * 		+	drain(Stack&)			move all items to another Stack
 * 		+	isFull(), isEmpty, size(), capacity()
 * 		+	print/trace				print current items / all items*
 *
 * @author	Alex-The-Teacher (inspired by MhZ alias TryFinally)
 *
 * @note	This file should be provided to class (after review) as base only
 * 		Students shold amend it as needed
 */
#include <cstddef>
#include <iostream>

#include "Rational.h"
#define s_DEFAULT_STACK_INITIAL_SIZE 5
#define s_DEFAULT_STACK_GROWTH_FACTOR 1.5
class DynamicRationalStack
{
public:
	DynamicRationalStack(size_t a_initialCapacity = s_DEFAULT_STACK_INITIAL_SIZE
						,float a_growFactor = s_DEFAULT_STACK_GROWTH_FACTOR);
	~DynamicRationalStack();
	DynamicRationalStack(DynamicRationalStack const& a_other);
// Stack Operations
	bool	push(Rational const& a_rational);
	size_t	push(Rational a_rationals[], size_t a_size);

	bool	pop (Rational& a_rational);
	bool	top (Rational& a_rational) const;
//	Needed for H02C-Queue
	size_t drain(DynamicRationalStack& a_into);
// Information
	bool isFull() const;
	bool isEmpty() const;
	size_t size() const;
	size_t capacity() const;
// Display
	void print(std::ostream& a_os = std::cout) const;
	void trace(std::ostream& a_os = std::cout) const;

private:
	void dump(std::ostream& a_os, const char* a_header, size_t a_n) const;

private:
	size_t		m_capacity;
	float		m_growFactor;
	size_t		m_top;
	Rational*	m_items;
};

#endif	// DYNAMIC_RATIONAL_STACK_H
