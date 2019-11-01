#include "mu_test.h"
#include <iostream>

#include <cstddef>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using std::map;

template<typename K,typename V>
class Map
{
	public:
	//  CTOR
		Map();
		Map(const map<K, V> mg);


		bool operator=(Map const& a_item);

		// Insert element / array
		bool myInsert(K const& a_key,V const& a_value);

	// Remove element / array
		bool myRemove(K const& a_key);

	// boundary check
		bool isFull() const;
		bool isEmpty() const;
		
	// at
		bool atKey(K const& a_key, V& a_value) const;
		bool atValue(V const& a_value,K& a_key) const;

	// size
		size_t size() const;

	// print the contents of the stack
		void print() const;
		void trace() const;

	// Private mem-functions
	private:
		void dump(const char* a_header, size_t a_n) const;

	// Private members
	private:
	size_t m_maxSize;
	size_t m_size;
	
	std::map<K, V> byKey;
	std::map<V, K> byValue;

};

template <typename K,typename V>
Map<K,V>::Map()
:m_size(0)
{
}


template <typename K,typename V>
Map<K,V>::Map(const map<K, V> a_other)
:m_size(a_other.m_size)
,m_maxSize(a_other.max_size)

{
	delete [] byKey;
	delete [] byValue;
	
	std::map<std::string, int>::const_iterator bm = a_other.begin();
	std::map<std::string, int>::const_iterator em = a_other.end();
	
	while (bm != em)
	{
		byKey.insert ( std::pair<K,V>(bm->first,bm->second) );
		++bm;
	}	
	assert(byKey);	

	bm = a_other.begin();
	
	while (bm != em)
	{
		byValue.insert ( std::pair<K,V>(bm->second,bm->first) );
		++bm;
	}
	assert(byValue);		
}

template <typename K,typename V>
bool Map<K,V>::operator=(Map const& a_item)
{
	if(a_item==byKey&&a_item==byValue)
	{
		return true;
	}
}


template <typename K,typename V>
bool Map<K,V>::myInsert(K const& a_key,V const& a_value)
{
	if(isFull()==true)
	{
		return false;
	}
	if( ((byKey.find(a_key))==byValue.end()) &&	((byValue.find(a_value))==byKey.end()) )
	{
		byKey[a_key]=a_value;
		byValue[a_value]=a_key;
		return true;
	}
	return true;
}

template <typename K,typename V>
bool Map<K,V>::myRemove(K const& a_key)
{
	if(isEmpty()==true)
	{
		return false;
	}
	typename std::map<K,V>::const_iterator kIt=byValue.find(a_key);
	typename std::map<K,V>::const_iterator vIt=byKey.find(kIt->second);
	if(kIt!=byValue.end()&&vIt!=byKey.end())
	{
		byValue.erase(kIt);
		byKey.erase(vIt);
	}
	
	m_size--;
	return false;
}

template <typename K,typename V>
bool Map<K,V>::atKey(K const& a_key, V& a_value) const
{
	typename std::map<K,V>::const_iterator it=byKey.find(a_key);
	if(it!=byKey.end())
	{
		a_value=it->second;
		return true;
	}
	return false;
}


template <typename K,typename V>
bool Map<K,V>::atValue(V const& a_value,K& a_key) const
{
	typename std::map<K,V>::const_iterator it=byValue.find(a_value);
	if(it!=byValue.end())
	{
		a_key=it->second;
		return true;
	}
	return false;}

template <typename K,typename V>
bool Map<K,V>::isFull() const
{
	return (m_size==m_maxSize)?true:false;
}

template <typename K,typename V>
bool Map<K,V>::isEmpty() const
{
	return (m_size==0)?true:false;
}

template <typename K,typename V>
size_t Map<K,V>::size() const
{
	return m_size;
}

template <typename K,typename V>
void Map<K,V>::print() const
{
	dump("Printing\n",m_size);
}

template <typename K,typename V>
void Map<K,V>::trace() const
{
	dump("Tracing\n",m_maxSize);
}

template <typename K,typename V>
void Map<K,V>::dump(const char* a_header, size_t a_n) const
{  
	typename std::map<K,V>::iterator it;
	size_t i;
	for (it=byKey.begin(); it!=byKey.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << '\n';
	}
}
