#ifndef _SORTED_CONTAINER_H_
#define _SORTED_CONTAINER_H_
#include <cstddef>
#include <time.h>
#include <stdlib.h>
#include <iostream>

template <typename T>
class SortedContainer
{
public:
	virtual bool insert(T a_item)=0;
};

template<typename T>
class PredicateGT
{
public:
	PredicateGT(T a_what)
	: m_what(a_what)
	{}

	bool operator()(T a_item) {
		return a_item > m_what;
	}

private:
	T m_what;
};

template<typename T>
class PredicateEQ
{
public:
	PredicateEQ(T a_what)
	: m_what(a_what)
	{}

	bool operator()(T a_item) {
		return a_item == m_what;
	}

private:
	T m_what;
};
#endif
