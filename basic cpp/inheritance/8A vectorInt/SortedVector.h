#ifndef SORTED_VECTOR_H
#define SORTED_VECTOR_H

#include <cstddef>
#include <vector>

class SortedVector : private std::vector<int>
{
	typedef std::vector<int> MyVector;

public:
	typedef std::vector<int>::const_iterator const_iterator;

	bool insert(int a_item);
	bool remove(int a_item);

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

inline SortedVector::const_iterator SortedVector::begin() const
{
	return std::vector<int>::begin();
}

inline SortedVector::const_iterator SortedVector::end() const
{
	return std::vector<int>::end();
}

inline int SortedVector::front() const
{
	return std::vector<int>::front();
}

inline int SortedVector::back() const
{
	return std::vector<int>::back();
}

inline size_t SortedVector::size() const
{
	return std::vector<int>::size();
}

inline bool SortedVector::empty() const
{
	return std::vector<int>::empty();
}

inline int SortedVector::operator[](size_t a_position) const
{
	return std::vector<int>::operator[](a_position);
}

#endif	// SORTED_VECTOR_H


