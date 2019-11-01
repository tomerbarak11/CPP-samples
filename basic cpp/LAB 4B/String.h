#ifndef STRING_CLASS_H
#define STRING_CLASS_H
/**
 *	@file String.h
 *
 *	@brief Day 4 - Homework 4B - String phase 3
 *
 *	Create a simple String class that will dynamically allocate memory
 *	memory allways allocated in multiples of a basic block that can be changed for
 *	for all string objects at once.
 *	Add static member with get/set mem-functions to control allocation alignment
 *	Allocations should be a multiple of this value (default = 32)
 *
 *	Add concatenation operations to support:
 * 		String += String
 *		c = String + String
 *		c = "string" + string
 *		c = String + "string"
 *
 *	Substring:	operator()(size_t start, size_t leng)
 *			returns a substring starting at 'start' position and has a length 'leng'
 *			e.g.:  String str ="1234567890"; str(4,3) returns string "567"
 *
 *		mem-function 'contains', which returns true if substring is found
 *		operator[]	that returns i'th character of  string
 *		mem-function 'findFirst', which finds the first occurence of char
 *		mem-function 'findLast',  which finds the last occurence of char
 *
 *	Interview question:
 * 		Efficiently find first duplicate character in the string
 */

#include <cstddef>
#include <cstring>
#include <iostream>

class String
{
public:
	String(const char* a_pStr = 0);
	~String();
	String(String const& a_source);
	String& operator=(String const& a_rhs);
	bool stringInit(const char* a_source);
	
// Info and Util
	size_t length() const;
	size_t capacity() const;

	const char* get() const ;
	void print(std::ostream& a_os) const;
	void set(const char* a_source);
// Concat
	String& operator+=(const char* a_rhs);
	String& operator+=(String const& a_rhs);
// Subscript & Substring
	char  operator[](size_t a_pos) const;
	char& operator[](size_t a_pos);
	String operator()(size_t a_start, size_t a_leng) const;

	bool contains(String const& a_what, bool a_caseSense = true) const;
	//  First, Last : return index
	int findFirst(char a_what) const;
	int findLast (char a_what) const;

// Find first duplicate char occurence
	char   findFirstDuplicate() const;

public:
	static bool isCaseSensitive();
	static void setCaseSensitive(bool a_sensitive);
	static size_t alignment();
	static void alignment(size_t a_block);

private:
	int compare(String const& a_other) const;

private:
	size_t	m_size;
	size_t	m_capacity;
	char*	m_chars;

private:
	static bool	s_caseSensitivity;
	static size_t STRING_ALLOC_ALIGNMENT;
	static const size_t STRING_ALLOC_ALIGNMENT_DEFAULT = 32;
};

std::ostream& operator<<(std::ostream& a_os, String const& a_rhs);
String const operator+(String const& a_lhs, String const& a_rhs);

String const operator+(String const& a_lhs, const char* a_rhs);
String const operator+(const char* a_lhs, String const& a_rhs);

bool operator==(String const& a_first, String const& a_second);
bool operator!=(String const& a_first, String const& a_second);
bool operator< (String const& a_first, String const& a_second);
bool operator> (String const& a_first, String const& a_second);
bool operator<=(String const& a_first, String const& a_second);
bool operator>=(String const& a_first, String const& a_second);

#endif // STRING_CLASS_H

