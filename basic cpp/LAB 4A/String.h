#ifndef STRING_CLASS_H
#define STRING_CLASS_H
/**
 * 	@file String.h
 *
 * 	@brief Day 4 - Class Lab 4A - String phase 2
 *
 *	Create a simple String class that will dynamically allocate memory
 * 		default CTOR
 *		CTOR from "const char*"
 *		copy CTOR
 *		DTOR
 *		assignment operator
 *
 *		mem-function 'length',	which returns length of the string
 *		mem-function 'get',		which returns "const char*"
 *		mem-function 'compare',	which compares 2 Strings (a, b)
 *		according to caseSensitivity settings (can be true or false)
 *			returns:	0 - if they are equal
 *						a negative number - a < b
 *						a positive number - a > b
 * 		keep track of number of String objects
 * 		mem-function 'count',	which returns the current number of String objects
 *		global stream op<< for printing
 *		global op< for checking lexicographical order
 */
#include <cstddef>
#include <iostream>

class String
{
public:
	String(const char* a_pStr = 0);
	~String();
	String(const String& a_other);
	String& operator=(const String& a_rhs);

	bool stringInit(const char* a_source);


// Info
	const char* get() const;
	size_t length() const;
	void print(std::ostream& a_os) const;

	void set(const char* a_source);


// Sensitivity mode
static bool isCaseSensitive();
static void setCaseSensitive(bool a_sensitive);
// Number of Strings
static size_t objectCount();

private:
	char*	m_chars;

static bool		s_caseSensitivity;
static size_t	s_numberOfObjects;
};

std::ostream& operator<<(std::ostream& _os, String const& _rhs);
// Compare
int compare(String const& a_first, String const& a_second);
bool operator<(const String& _first, const String& _second);

#endif // STRING_CLASS_H
