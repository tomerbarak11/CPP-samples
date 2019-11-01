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
    void myPushBack(const size_t listIndex,const Pair newPair);
    void myRemove(const size_t listIndex,const Pair newPair);
    bool myErase(const size_t listIndex,const Pair newPair);

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
void Buckets<K,V,H> ::myPushBack(const size_t listIndex,const Pair newPair)
{
    m_hashMap[listIndex].push_back(newPair);
}

template<typename K, typename V, typename H>
void Buckets<K,V,H> ::myRemove(const size_t listIndex,const Pair newPair)
{

    m_hashMap[listIndex].remove(newPair);
}

template<typename K, typename V, typename H>
bool Buckets<K,V,H> ::myErase(const size_t listIndex,const Pair newPair)
{
	for(typename std::list<Pair>::iterator it = m_hashMap[listIndex].begin();it !=m_hashMap[listIndex].end(); ++it)
	{
		if(newPair.m_key==(*it).m_key)
		{
			m_hashMap[listIndex].erase(it);

			return true;
		}
	}
    return false;

}

#endif