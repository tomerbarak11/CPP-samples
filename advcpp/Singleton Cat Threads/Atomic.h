#ifndef ATOMIC_H
#define ATOMIC_H
#include <cstddef>
extern int g;

template<typename T>
class Atomic{
public:
    Atomic(size_t a_numOfRef);
    Atomic& operator++();
    Atomic& operator--();

    int operator++(int);
    int operator--(int);

    T getValue();
    void setValue(T a_value);
    operator T();
private:
   T m_value;
};

template<typename T>
Atomic<T>::Atomic(size_t a_numOfRef)
: m_value(a_numOfRef)
{
}

template<typename T>
Atomic<T>& Atomic<T>::operator++()
{
    __sync_add_and_fetch(&m_value, 1);
    return *this;
}

template<typename T>
Atomic<T>& Atomic<T>::operator--()
{
    __sync_sub_and_fetch(&m_value, 1);
    return *this;
}

template<typename T>
int Atomic<T>::operator++(int)
{
    T r=m_value;
    ++m_value;
    return r;
}

template<typename T>
int Atomic<T>::operator--(int)
{
    T r=m_value;
    --m_value;
    return r;
}

template<typename T>
T Atomic<T>::getValue()
{
    T t=__sync_add_and_fetch(&m_value, 0);
    return t;
}

template<typename T>
void Atomic<T>::setValue(T a_value)
{
    __sync_lock_test_and_set(&g,1);
    m_value=a_value;
    __sync_lock_release(&g);
}


template<typename T>
Atomic<T>::operator T()
{
    T t=__sync_add_and_fetch(&m_value, 0);
    return t;
}

#endif
