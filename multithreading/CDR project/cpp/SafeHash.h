#ifndef SAFEHASH_H
#define SAFEHASH_H
#include <vector>
#include <list>
#include <iostream>
#include "math.h"
#include "Buckets.h"
#include "Mutex.h"
#include <math.h>
template<typename K,typename V,typename H>
class SafeHash
{
public:
    typedef typename Buckets<K,V,H>::Pair Pair;
public:
    explicit SafeHash(size_t a_capacity, size_t a_numberOfMutexes);

    bool updateIf(K const& a_key,V const& a_value);
    bool remove(K const& a_key,V const& a_value);

    bool contains(K const& a_key) const;

    bool find(K const& a_key, V& a_value) const;

	V* find(K const& a_key) const;

    size_t size()const;
    size_t capacity()const;

    size_t getSize()const;
    size_t getCapacity()const;

    V& operator[](K const& k);
    
	double loadFactor() const;

	size_t indexOfMutex(K const& a_key) const;
	Mutex getMutex(size_t a_index) const;

private:
    size_t indexOf(K const& a_key) const;
    static size_t GetPrimeNumberBiggerThen(size_t);
    static bool IsPrime(size_t);
    size_t numberOfBuckets() const;
	const size_t vec_capacity;
    size_t m_size;
	Buckets<K,V,H> m_buckets;
	const size_t m_capacity;
	std::vector<Mutex> m_vectorMutex;
	Mutex inserterMutex;
	Mutex removerMutex;
	Mutex m_inserterAndRemoverMutex;
	size_t m_numberOfMutex;
	int m_prop;
};

template<typename K, typename V, typename H>
SafeHash<K,V,H>::SafeHash(size_t a_capacity, size_t a_numberOfMutexes)
: vec_capacity(GetPrimeNumberBiggerThen(a_capacity))
, m_size(0)
, m_buckets(a_capacity)
, m_capacity(a_capacity)
, m_vectorMutex(a_numberOfMutexes)
, m_numberOfMutex(a_numberOfMutexes)
, m_prop((a_capacity+a_numberOfMutexes-1)/a_numberOfMutexes)
{
}

template<typename K, typename V, typename H>
size_t SafeHash<K,V,H>::indexOf(K const& a_key) const
{
	H hasher;
	return hasher(a_key) % m_capacity;
}

template<typename K, typename V, typename H>
size_t SafeHash<K,V,H>::size()const
{
	return m_size;
}

template<typename K, typename V, typename H>
size_t SafeHash<K,V,H>::capacity()const
{
	return vec_capacity;
}

template<typename K, typename V, typename H>
bool SafeHash<K,V,H>::contains(K const& a_key) const
{
	if (!m_size)
	{
		return false;
	}
	size_t listIndex = indexOf (a_key);

	typename std::list<Pair>::const_iterator it= m_buckets[listIndex].begin();
	typename std::list<Pair>::const_iterator end= m_buckets[listIndex].end();


	for (; it != end; ++it)
	{
    	if ((*it).m_key == a_key)
    	{
    		return true;
    	}
	}
	return false;
}

template<typename K, typename V, typename H>
bool SafeHash<K,V,H>::find(K const& a_key, V& a_value) const
{
	if (!m_size)
	{
		return false;
	}

	size_t listIndex = indexOf (a_key);
	typename std::list<Pair>::const_iterator it= m_buckets[listIndex].begin();
	typename std::list<Pair>::const_iterator end= m_buckets[listIndex].end();
	for (; it != end; ++it)
	{

    	if ((*it).m_key == a_key)
    	{
    		a_value = (*it).m_value;
    		return true;
    	}
	}
	return false;
}

template<typename K, typename V, typename H>
bool SafeHash<K,V,H>::updateIf(K const& a_key, V const& a_value)
{
	V tempVal;

	if (m_buckets.isFull()||find(a_key, tempVal))
	{
		return false;
	}

	size_t listIndex = indexOf(a_key);
	Pair newPair;
	newPair.m_key = a_key;
	newPair.m_value = a_value;
	size_t indexMutex=indexOfMutex(a_key);
	(getMutex(indexMutex)).lock();
	if (find(a_key, tempVal))
	{
		m_buckets.updateValue(listIndex,newPair);
		m_buckets.insert(listIndex,newPair);
	    (getMutex(indexMutex)).unlock();
		return true;
	}

	(getMutex(indexMutex)).lock();
	m_buckets.insert(listIndex,newPair);
	++m_size;
    (getMutex(indexMutex)).unlock();
	return true;
}

template<typename K, typename V, typename H>
bool SafeHash<K,V,H>::remove(K const& a_key,V const& a_value)
{
	V tempVal;
	if (m_buckets.isEmpty()||!find(a_key, tempVal))
	{
		return false;
	}
	size_t listIndex = indexOf(a_key);
	Pair newPair;
	newPair.m_key = a_key;
	newPair.m_value = a_value;
	size_t indexMutex=indexOfMutex(a_key);
    (getMutex(indexMutex)).lock();
	m_buckets.myErase(listIndex,newPair);
	--m_size;
	(getMutex(indexMutex)).unlock();
	return true;
}

template<typename K, typename V, typename H>
size_t SafeHash<K,V,H>:: GetPrimeNumberBiggerThen (size_t _num)
{
	size_t i = _num;
	while (1)
	{
		if (IsPrime(i))
		{
			return i;
		}
		++i;
	}	
	return i;
}

template<typename K, typename V, typename H>
bool SafeHash<K,V,H>::IsPrime(size_t a_num) 
{ 
	size_t i =0;
	double root = sqrt (a_num);
	if (a_num <= 2)
	{
		return false;
	}
	for (i = 2; i < root; ++i) 
	{
		if (a_num % i == 0) 
		{
			return false;         
		}
	}
	return true; 
}

template<typename K, typename V, typename H>
size_t SafeHash<K,V,H>::numberOfBuckets() const
{
	size_t count=0;
	for(size_t i=0 ; i < m_size; ++i)
	{
		if(!m_buckets[i].empty())
		{
			++count;
		}
	}
	return count;
}

template<typename K, typename V, typename H>
double SafeHash<K,V,H>::loadFactor() const
{
	if(0==numberOfBuckets())
	{
		return -1;
	}
	
	return (double)size()/(double)numberOfBuckets();
}

template<typename K, typename V, typename H>
V& SafeHash<K,V,H>::operator[](K const& a_key)
{
	V& value;

	if (find(a_key))
	{
		std::cout<<"Container is full\n";
		return value;
	}
	
	size_t listIndex = indexOf(a_key);
	typename std::list<Pair>::const_iterator it= m_buckets[listIndex].begin();
	typename std::list<Pair>::const_iterator end= m_buckets[listIndex].end();

	for (; it != end; ++it)
	{
    	if ((*it).m_key == a_key)
    	{
			value=(*it).m_value;
    		return value;
    	}
	}
	return value;
}

template<typename K, typename V, typename H>
size_t SafeHash<K,V,H>::getSize() const
{
	return m_size;
}

template<typename K, typename V, typename H>
size_t SafeHash<K,V,H>::getCapacity() const
{
	return m_capacity;
}

template<typename K, typename V, typename H>
size_t SafeHash<K,V,H>::indexOfMutex(K const& a_key) const
{
	return a_key/m_prop;
}

template<typename K, typename V, typename H>
Mutex SafeHash<K,V,H>::getMutex(size_t a_index) const
{
	return m_vectorMutex[a_index];
}

#endif
