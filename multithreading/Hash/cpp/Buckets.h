#ifndef BUCKETS_H
#define BUCKETS_H
#include <vector>
#include <list>


template<typename K,typename V,typename H>
class Buckets
{
public:
	struct Pair
	{
		K m_key;
		V m_value;
	};
    

public:
    Buckets(size_t a_capacity);
    std::list<Pair> operator[](size_t index) const;
    void resizeFunc(size_t a_size);
    size_t mySize() const;
    void insert(size_t listIndex,Pair newPair);
	void updateValue(size_t listIndex,Pair newPair);
    void myRemove(size_t listIndex,Pair newPair);
    void myErase(size_t listIndex,Pair newPair);
	bool isEmpty() const;
	bool isFull() const;

	//iterators
	typename std::vector<std::list<Pair> >::iterator begin();
	typename std::vector<std::list<Pair> >::iterator end();
	typename std::vector<std::list<Pair> >::iterator next();


protected:
        std::vector<std::list<Pair> > m_hashMap;
};


template<typename K, typename V, typename H>
Buckets<K,V,H>::Buckets(size_t a_capacity)
: m_hashMap(a_capacity)
{
}

template<typename K, typename V, typename H>
std::list<typename Buckets<K,V,H>::Pair> Buckets<K,V,H>::operator[](size_t index) const
{
    return m_hashMap[index];
}

template<typename K, typename V, typename H>
void Buckets<K,V,H> ::resizeFunc(size_t a_size)
{
    m_hashMap.resize(a_size);
}

template<typename K, typename V, typename H>
size_t Buckets<K,V,H> ::mySize() const
{
    return m_hashMap.size();
}

template<typename K, typename V, typename H>
void Buckets<K,V,H> ::insert(size_t listIndex,Pair newPair)
{
    m_hashMap[listIndex].push_back(newPair);
}

template<typename K, typename V, typename H>
void Buckets<K,V,H> ::updateValue(size_t listIndex,Pair newPair)
{
	for(typename std::list<Pair>::iterator it = m_hashMap[listIndex].begin();it !=m_hashMap[listIndex].end(); ++it)
	{
		if(newPair.m_key==(*it).m_key)
		{
			(*it).m_value+=newPair.m_value;
			return;
		}
	}
	return;
}

template<typename K, typename V, typename H>
void Buckets<K,V,H> ::myRemove(size_t listIndex,Pair newPair)
{
    m_hashMap[listIndex].remove(newPair);
}

template<typename K, typename V, typename H>
void Buckets<K,V,H> ::myErase(size_t listIndex,Pair newPair)
{
	for(typename std::list<Pair>::iterator it = m_hashMap[listIndex].begin();it !=m_hashMap[listIndex].end(); ++it)
	{
		if(newPair.m_key==(*it).m_key)
		{
			m_hashMap[listIndex].erase(it,it);
		}
	}
}

template<typename K, typename V, typename H>
typename std::vector<std::list<typename Buckets<K,V,H>::Pair> >::iterator Buckets<K,V,H>::begin()
{
	typename std::vector<std::list<Pair> >::iterator theEnd=m_hashMap.end();
	for(typename std::vector<std::list<Pair> >::iterator it = m_hashMap.begin();it !=theEnd; ++it)
	{
		if(*it)
		{
			return it;
		}
	}
	return 0;
}

template<typename K, typename V, typename H>
typename std::vector<std::list<typename Buckets<K,V,H>::Pair> >::iterator Buckets<K,V,H>::end()
{
	typename std::vector<std::list<Pair> >::iterator theBegin=m_hashMap.begin();
	for(typename std::vector<std::list<Pair> >::iterator it = m_hashMap.end();it !=theBegin; --it)
	{
		if(*it)
		{
			return it;
		}
	}
	return 0;
}

template<typename K, typename V, typename H>
bool Buckets<K,V,H>::isEmpty() const
{
	return m_hashMap.size()==0;
}

template<typename K, typename V, typename H>
bool Buckets<K,V,H>::isFull() const
{
	return m_hashMap.size()==m_hashMap.max_size();
}

#endif
