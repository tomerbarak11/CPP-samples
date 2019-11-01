#ifndef RATIONAL_CLASS_H
#define RATIONAL_CLASS_H
/**
 * @file	Rational.h
 *
 * @brief	Day 1 - Homework 1B definition
 *
 *	Create a simple class representing a fraction of two int
 * 		default CTOR, CTOR from (int), CTOR from (int, int)
 *		mem-function:	print		print the fraction {int/int}
 *		mem-function:	mul(int)	Multiply two fractions
 *						mul(Rational const&)
 *			Same for Add, Subtract, Delete
 *		mem-function:	reduce()	to lowest common denominator
 *
 * @author	Alex-The-Teacher
 * @note	Provide this file to students (via Slack)
 */

class Rational
{
public:
// Default CTOR
	Rational();
// CTORs
	Rational(int _numer);
	Rational(int _numer, int _denom);
// Getters for unit test
	int numerator() const;
	int denominator() const;
// Print
	void print() const;
// Reduce
	void reduce();
// Multiply
	void mul(int a_numer);
	void mul(Rational a_other);
// Divide
	void div(int a_numer);
	void div(Rational a_other);
// Add
	void add(int a_numer);
	void add(Rational a_other);
// Sub
	void sub(int _numer);
	void sub(Rational a_other);

// Private data members
private:
	int		m_numer;
	int		m_denom;
};

#endif // RATIONAL_CLASS_H
