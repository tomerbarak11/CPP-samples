#ifndef _SORTED_VECTOR_H_
#define _SORTED_VECTOR_H_

#include <algorithm>

#include <cstddef>
#include <vector>

template<typename T>
class SortedVector : private std::vector<T>
{
	typedef std::vector<T> MyVector;

public:
	typedef typename std::vector<T>::const_iterator const_iterator;

	bool insert(T a_item);
	bool remove(T a_item);

// 
	const_iterator begin() const;
	const_iterator end() const;

// we should not allow modification of items
	int front() const;
	int back() const;
	int operator[](size_t a_position) const;

	size_t size() const;
	bool empty() const;

};



/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#include "SortedVector.h"
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

template<typename T>
bool SortedVector<T>::insert(T a_item)
{
	bool done = false;
	PredicateGT<T> pFO(a_item);
	typename MyVector::iterator b = MyVector::begin();
	typename MyVector::iterator e = MyVector::end();
	typename MyVector::iterator p = std::find_if(b, e, pFO);

	MyVector::insert(p, a_item);
	done = true;


	return done;
}

template<typename T>
bool SortedVector<T>::remove(T a_item)
{
	bool done = false;
	PredicateEQ<T> pFO(a_item);
	typename MyVector::iterator b = MyVector::begin();
	typename MyVector::iterator e = MyVector::end();
	typename MyVector::iterator p = std::find_if(b, e, pFO);
	
	MyVector::erase(p);
	done = true;
	return done;
}


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


template<typename T>
inline typename SortedVector<T>::const_iterator SortedVector<T>::begin() const
{
	return std::vector<T>::begin();
}

template<typename T>
inline typename SortedVector<T>::const_iterator SortedVector<T>::end() const
{
	return std::vector<T>::end();
}

template<typename T>
inline int SortedVector<T>::front() const
{
	return std::vector<T>::front();
}

template<typename T>
inline int SortedVector<T>::back() const
{
	return std::vector<T>::back();
}

template<typename T>
inline size_t SortedVector<T>::size() const
{
	return std::vector<T>::size();
}

template<typename T>
inline bool SortedVector<T>::empty() const
{
	return std::vector<T>::empty();
}

template<typename T>
inline int SortedVector<T>::operator[](size_t a_position) const
{
	return std::vector<T>::operator[](a_position);
}

#endif	// SORTED_VECTOR_H


