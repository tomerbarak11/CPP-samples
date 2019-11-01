#ifndef _RANDOM_BASE_H_
#define _RANDOM_BASE_H_

#include <cstddef>
#include <time.h>
#include <stdlib.h>
#include <iostream>


template <typename T>
class RandomBase
{
static bool s_done;
public:
	RandomBase();
	T get();
};

template <typename T>
RandomBase<T>::RandomBase()
{
	if (! s_done) {
		srand(time(0));
		s_done = true;
	}
}

template <typename T>
bool RandomBase<T>::s_done = false;

template <typename T>
T RandomBase<T>::get()
{
	return rand();
}

template <typename T>
class RandomRange : public RandomBase<T>
{
public:
	RandomRange(T const& a_from, T const& a_to);
	T get();
private:
	T m_from;
	T m_interval;
};

template <typename T>
RandomRange<T>::RandomRange(T const& a_from, T const& a_to)
: RandomBase<T>()
, m_from(a_from)
, m_interval(a_to - a_from)
{
}

template <typename T>
T RandomRange<T>::get()
{
	return (RandomBase<T>::get() % m_interval + m_from); 
}

#endif
