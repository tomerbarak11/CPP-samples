#include "SortedVector.h"
#include <algorithm>

class PredicateGT
{
public:
	PredicateGT(int a_what)
	: m_what(a_what)
	{}

	bool operator()(int a_item) {
		return a_item > m_what;
	}

private:
	int m_what;
};

class PredicateEQ
{
public:
	PredicateEQ(int a_what)
	: m_what(a_what)
	{}

	bool operator()(int a_item) {
		return a_item == m_what;
	}

private:
	int m_what;
};

bool SortedVector::insert(int a_item)
{
	bool done = false;
	PredicateGT pFO(a_item);
	MyVector::iterator b = MyVector::begin();
	MyVector::iterator e = MyVector::end();
	MyVector::iterator p = std::find_if(b, e, pFO);

	MyVector::insert(p, a_item);
	done = true;

	return done;
}

bool SortedVector::remove(int a_item)
{
	bool done = false;
	PredicateEQ pFO(a_item);
	MyVector::iterator b = MyVector::begin();
	MyVector::iterator e = MyVector::end();
	MyVector::iterator p = std::find_if(b, e, pFO);
	
	MyVector::erase(p);
	done = true;

	return done;
}
