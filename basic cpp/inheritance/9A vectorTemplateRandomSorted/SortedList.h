#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include "SortedContainer.h"

#include <cstddef>
#include <list>
#include <algorithm>

template<typename T>
class SortedList : private std::list<T>, public SortedContainer<T>
{
	typedef std::list<T> MyList;

public:
	typedef typename std::list<T>::const_iterator const_iterator;

	bool insert(T a_item);
	bool remove(T a_item);

// 
	const_iterator begin() const;
	const_iterator end() const;

// we should not allow modification of items
	int front() const;
	int back() const;
	//int operator[](size_t a_position) const;

	size_t size() const;
	bool empty() const;

};

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


template<typename T>
bool SortedList<T>::insert(T a_item)
{
	bool done = false;
	PredicateGT<T> pFO(a_item);
	typename MyList::iterator b = MyList::begin();
	typename MyList::iterator e = MyList::end();
	typename MyList::iterator p = std::find_if(b, e, pFO);

	MyList::insert(p, a_item);
	done = true;

	return done;
}

template<typename T>
bool SortedList<T>::remove(T a_item)
{
	bool done = false;
	PredicateEQ<T> pFO(a_item);

	MyList::remove_if(pFO);
	done = true;

	return done;
}


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

template<typename T>
inline typename SortedList<T>::const_iterator SortedList<T>::begin() const
{
	return std::list<int>::begin();
}

template<typename T>
inline typename SortedList<T>::const_iterator SortedList<T>::end() const
{
	return std::list<T>::end();
}

template<typename T>
inline int SortedList<T>::front() const
{
	return std::list<T>::front();
}

template<typename T>
inline int SortedList<T>::back() const
{
	return std::list<T>::back();
}

template<typename T>
inline size_t SortedList<T>::size() const
{
	return std::list<T>::size();
}

template<typename T>
inline bool SortedList<T>::empty() const
{
	return std::list<T>::empty();
}

/*
inline int SortedVector::operator[](size_t a_position) const
{
	return std::list<int>::operator[](a_position);
}
*/
#endif	// SORTED_VECTOR_H


