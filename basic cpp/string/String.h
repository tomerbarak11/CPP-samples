#ifndef STRING_CLASS_H
#define STRING_CLASS_H
/**
 * 	@file String.h
 *
 * 	@brief Day 3 - Homework 3C - String phase 1
 *
 *	Create a simple String class that will dynamically allocate memory
 * 	*	default CTOR
 *	*	CTOR from "const char*"
 *	*	copy CTOR
 *	*	DTOR
 *	*	assignment operator
 *
 *		mem-function 'length',	which returns length of the string
 *		mem-function 'get',		which returns "const char*"
 *		global function 'compare',	which compares 2 Strings (a, b)
 *			returns:	0 - if they are equal
 *						a negative number - a < b
 *						a positive number - a > b
 *		global stream op<< for printing
 */

#include <cstddef>
#include <iostream>

class String
{
public:
	String(const char* a_source = 0);
// Rule of 3
	~String();
	String(const String& a_source);
	String& operator=(const String& a_source);
// info
	size_t length() const;
	const char* get() const;
// utility
	void print(std::ostream& a_os) const;

private:
	char*	m_chars;
};

std::ostream& operator<<(std::ostream& a_os, String const& a_rhs);
int compare(const String& a_first, const String& a_second);

#endif // STRING_CLASS_H
