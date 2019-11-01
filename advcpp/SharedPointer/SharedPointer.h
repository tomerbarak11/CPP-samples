#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H
#include <iostream>
#include <cassert>
#include "Counter.h"
#include <algorithm>

static Counter s_CounterForNulls=1;

template<typename T>
class SharedPointer
{
public:
    explicit SharedPointer(T* a_other=0);
    ~SharedPointer();

    SharedPointer(SharedPointer<T>const& a_other);
    SharedPointer<T>& operator =(SharedPointer<T> const& a_other);
    
    template<typename U>
    SharedPointer(SharedPointer<U>const& a_other);
    template<typename U>
    SharedPointer<T>& operator =(SharedPointer<U> const& a_other);
    
    T& operator *() const;
    T* operator ->() const;
    bool operator ==(SharedPointer<T>const& a_other) const;
    bool operator !=(SharedPointer<T>const& a_other) const;

    void reset(SharedPointer<T>const& a_other);
    void swap(SharedPointer<T>& a_other);

    operator bool() const;

    T* getMOther() const;
    size_t getMCounter() const;
    Counter* getCounterPtr() const;

    void copyIf(T* m_other,Counter*  a_counter);
    void destroy();

private:    

private:
    T* m_other;    
    Counter* m_counter;    
    
};

template<typename T>
SharedPointer<T>::SharedPointer(T* a_other)
: m_other(a_other)
, m_counter(a_other ? new Counter(0) : &s_CounterForNulls)
{   
    ++*m_counter;
}

template<typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T>const& a_other)
: m_other(a_other.m_other)
, m_counter(a_other.m_counter)
{
    ++*m_counter;
}

template<typename T>
SharedPointer<T>::~SharedPointer()
{
    --*m_counter;
    if(((m_counter)->getValue()) == 0)
    {
        delete m_counter;
        delete m_other;
    }    
}

template<typename T>
T& SharedPointer<T>::operator *() const
{
    return *m_other;
}

template<typename T>
T* SharedPointer<T>::operator ->() const
{
    return m_other;
}

template<typename T>
SharedPointer<T>& SharedPointer<T>::operator =(SharedPointer<T> const& a_other)
{
    copyIf(a_other.getMOther(),a_other.m_counter);
    return *this;
}

template<typename T>
template<typename U>
SharedPointer<T>::SharedPointer(SharedPointer<U>const& a_other)
: m_other(a_other.getMOther())
, m_counter(a_other.getCounterPtr())
{
    ++*m_counter;
}

template<typename T>
template<typename U>
SharedPointer<T>& SharedPointer<T>::operator =(SharedPointer<U> const& a_other)
{
    if(this->m_other != a_other.getMOther())
    {
        destroy();
        copyIf(a_other.getMOther(),a_other.getCounterPtr());
    }
    return *this;
}

template<typename T>
void SharedPointer<T>::destroy()
{
        if(m_counter)
            assert(m_counter!=0);
        {
        }
        if(--(*m_counter) == 0)
        {
            delete m_counter;
            delete m_other;
        }
}

template<typename T>
void SharedPointer<T>::copyIf(T* a_m_other,Counter*  a_counter)
{
    if(this->m_other != a_m_other)
    {
        m_other = a_m_other;
        m_counter=a_counter;
        if(m_counter)
        {
            ++m_counter;
        }
    }
}

template<typename T>
SharedPointer<T>::operator bool() const
{
    return m_other!=0;
}

template<typename T>
bool SharedPointer<T>::operator ==(SharedPointer<T>const& a_other) const
{
    return m_other==a_other.m_other;
}

template<typename T>
bool SharedPointer<T>::operator !=(SharedPointer<T>const& a_other) const
{
    return m_other!=a_other.m_other;
}

template<typename T>
Counter* SharedPointer<T>::getCounterPtr() const
{
    return m_counter;
}

template<typename T>
T* SharedPointer<T>::getMOther() const
{
    return m_other;
}

template<typename T>
size_t SharedPointer<T>::getMCounter() const
{
    return m_counter->getValue();
}

template<typename T>
void SharedPointer<T>::reset(SharedPointer<T>const& a_other)
{
    destroy();
    *this=a_other;
}

template<typename T>
void SharedPointer<T>::swap(SharedPointer<T>& a_other)
{
    std::swap(m_other,a_other.m_other);
    std::swap(m_counter,a_other.m_counter);
}


template<typename T>
bool operator ==(SharedPointer<T>const& a_a,SharedPointer<T>const& a_b)
{
    return a_a.m_other==a_b.m_other;
}

template<typename T>
bool operator !=(SharedPointer<T>const& a_a,SharedPointer<T>const& a_b)
{
    return a_a.m_other!=a_b.m_other;
}

#endif
