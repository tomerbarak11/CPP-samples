#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <list>
#include <iostream>
#include "math.h"
#include "Buckets.h"
template<typename K,typename V,typename H>
class HashTable
{
public:
    typedef typename Buckets<K,V,H>::Pair Pair;
public:
    explicit HashTable(size_t a_capacity = c_LargePrimeNumber);

    bool insert(K const& a_key,V const& a_value);
    bool remove(K const& a_key,V const& a_value);

    bool contains(K const& a_key) const;

    bool find(K const& a_key, V& a_value) const;

	V& find(K const& a_key) const;

    size_t size()const;
    size_t capacity()const;

    V& operator[](K const& k);
    
	double loadFactor() const;
		
private:
    size_t indexOf(K const& a_key) const;
    static size_t GetPrimeNumberBiggerThen(size_t);
    static bool IsPrime(size_t);
    size_t numberOfBuckets() const;

	size_t vec_capacity;
    size_t m_size;
	Buckets<K,V,H> m_buckets;
    static const size_t c_LargePrimeNumber = 997;
};

template<typename K, typename V, typename H>
HashTable<K,V,H>::HashTable(size_t a_capacity)
: vec_capacity(GetPrimeNumberBiggerThen(a_capacity))
, m_size(0)
, m_buckets(a_capacity)
{
	vec_capacity=GetPrimeNumberBiggerThen(a_capacity);
}

template<typename K, typename V, typename H>
size_t HashTable<K,V,H>::indexOf(K const& a_key) const
{
	H hasher;
	return hasher(a_key) % vec_capacity ;
}

template<typename K, typename V, typename H>
size_t HashTable<K,V,H>::size()const
{
	return m_size;
}

template<typename K, typename V, typename H>
size_t HashTable<K,V,H>::capacity()const
{
	return vec_capacity;
}

template<typename K, typename V, typename H>
bool HashTable<K,V,H>::contains(K const& a_key) const
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
bool HashTable<K,V,H>::find(K const& a_key, V& a_value) const
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
V& HashTable<K,V,H>::find(K const& a_key) const
{
	for(size_t i=0 ;i < m_size; ++i)
	{
		for(size_t j=0 ;j < m_buckets[i].size(); ++j)
		{
			if(m_buckets[i].second==a_key)
			{
				return m_buckets[i].first;
			}
		}
	}
	/*TODO* RETURN*/
}

template<typename K, typename V, typename H>
bool HashTable<K,V,H>::insert(K const& a_key, V const& a_value)
{
	V tempVal;

	if (find(a_key, tempVal))
	{
		std::cout<<"Found this key\n";
		return false;
	}

	size_t listIndex = indexOf(a_key);
	Pair newPair;
	newPair.m_key = a_key;
	newPair.m_value = a_value;

	m_buckets.myPushBack(listIndex,newPair);

	++m_size;
	return true;
}	

template<typename K, typename V, typename H>
bool HashTable<K,V,H>::remove(K const& a_key,V const& a_value)
{
	V tempVal;
	if (!find(a_key, tempVal))
	{
		return false;
	}
	size_t listIndex = indexOf(a_key);
	Pair newPair;
	newPair.m_key = a_key;
	newPair.m_value = a_value;
	
	if(m_buckets.myErase(listIndex,newPair))
	{
		--m_size;
		return true;
	}
	return false;
}

template<typename K, typename V, typename H>
size_t HashTable<K,V,H>:: GetPrimeNumberBiggerThen (size_t _num)
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
bool HashTable<K,V,H>::IsPrime(size_t a_num) 
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
size_t HashTable<K,V,H>::numberOfBuckets() const
{
	size_t count=0;
	for(size_t i=0 ; i < c_LargePrimeNumber; ++i)
	{
		if(!m_buckets[i].empty())
		{
			++count;
		}
	}
	return count;
}

template<typename K, typename V, typename H>
double HashTable<K,V,H>::loadFactor() const
{
	if(0==numberOfBuckets())
	{
		return -1;
	}
	
	return (double)size()/(double)numberOfBuckets();
}

template<typename K, typename V, typename H>
V& HashTable<K,V,H>::operator[](K const& a_key)
{
	V& value;
	if (!m_size)
	{
		return false;
	}
	size_t listIndex = indexOf(a_key);
	typename std::list<Pair>::const_iterator it= m_buckets[listIndex].begin();
	typename std::list<Pair>::const_iterator end= m_buckets[listIndex].end();

	for (; it != end; ++it)
	{
    	if ((*it).m_key == a_key)
    	{
			value=(*it).m_value;
    		return true;
    	}
	}
	return false;
}

#endif
