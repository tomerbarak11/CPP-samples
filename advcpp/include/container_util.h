#ifndef CONTAINER_UTIL_H
#define CONTAINER_UTIL_H

#include <tr1/unordered_map>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
template<typename T>
typename std::vector<T>::const_iterator firstUnique(std::vector<T> const& a_v)
{
	std::tr1::unordered_map<T,int> map;
	for(size_t i=0;i<a_v.size();i++)
	{
		std::pair<T,int> item (a_v[i],1);
		typename std::tr1::unordered_map<T,int>::iterator it = map.find (a_v[i]);
		if (it != map.end())
		{
			++(it->second);
		}
		map.insert(item);
	}
	typename std::vector<T>::const_iterator it=a_v.begin();
	for(size_t i=0;it!=a_v.end();it++,i++)
	{
		if(map[a_v[i]]==1)
		{
			return it;
		}
	}
	return it;
}

template<typename T>
typename std::vector<T>::const_iterator firstDuplicate(std::vector<T> const& a_v)
{
	std::tr1::unordered_map<T,int> map;
	for(size_t i=0;i<a_v.size();i++)
	{
		std::pair<T,int> item (a_v[i],1);
		typename std::tr1::unordered_map<T,int>::iterator it = map.find (a_v[i]);
		if (it != map.end())
		{
			++(it->second);
		}
		map.insert(item);
	}
	typename std::vector<T>::const_iterator it=a_v.begin();
	for(size_t i=0;it!=a_v.end();it++,i++)
	{
		if(map[a_v[i]]>1)
		{
			return it;
		}
	}
	return it;
}
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
template<typename C>
typename C::const_iterator firstUniqueContainer(C const& a_container)
{
	typedef typename C::value_type value_type;
	std::tr1::unordered_map<value_type,int> map;
	
	for(size_t i=0;i<a_container.size();i++)
	{
		typename std::pair<value_type,int> item (a_container[i],1);
		typename std::tr1::unordered_map<value_type,int>::iterator it = map.find (a_container[i]);
		if (it != map.end())
		{
			++(it->second);
		}
		map.insert(item);
	}
	typename C::const_iterator it=a_container.begin();
	for(size_t i=0;it!=a_container.end();it++,i++)
	{
		if(map[a_container[i]]==1)
		{
			return it;
		}
	}
	return it;
}

template<typename C>
typename C::const_iterator firstDuplicateContainer(C const& a_container)
{
	typedef typename C::value_type value_type;
	std::tr1::unordered_map<value_type,int> map;
	
	for(size_t i=0;i<a_container.size();i++)
	{
		typename std::pair<value_type,int> item (a_container[i],1);
		typename std::tr1::unordered_map<value_type,int>::iterator it = map.find (a_container[i]);
		if (it != map.end())
		{
			++(it->second);
		}
		map.insert(item);
	}
	typename C::const_iterator it=a_container.begin();
	for(size_t i=0;it!=a_container.end();it++,i++)
	{
		if(map[a_container[i]]>1)
		{
			return it;
		}
	}
	return it;
}

#endif
