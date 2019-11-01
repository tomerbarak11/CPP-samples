#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H
#include <iostream>
#include <cassert>
#include "Atomic.h"
#include <algorithm>

static Atomic<size_t> s_AtomicForNulls=1;

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
    
    template<typename U>
    friend class SharedPointer;

    T& operator *() const;
    T* operator ->() const;
    bool operator ==(SharedPointer<T>const& a_other) const;
    bool operator !=(SharedPointer<T>const& a_other) const;

    void reset(SharedPointer<T>const& a_other);
    void swap(SharedPointer<T>& a_other);

    T* getMOther() const;
    size_t getMAtomic() const;
    Atomic<size_t>* getAtomicPtr() const;

    void copyIf(T* m_other,Atomic<size_t>*  a_counter);
    void destroy();

    typedef void(*PF)();
    operator PF() const;
    static void myFunc();

private:
    T* m_other;    
    Atomic<size_t>* m_atomic;
};

template<typename T>
void SharedPointer<T>::myFunc()
{
    assert(false);
}

template<typename T>
SharedPointer<T>::operator PF() const
{
    return ((m_other)? &myFunc : 0);
}

template<typename T>
SharedPointer<T>::SharedPointer(T* a_other)
: m_other(a_other)
{
    try
    {
        m_atomic=(a_other ? new Atomic<size_t>(0) : &s_AtomicForNulls);
    }
    catch(const std::exception& e)
    {
        delete a_other;
        std::cerr << e.what() << '\n';
    }

    ++*m_atomic;
}

template<typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T>const& a_other)
: m_other(a_other.m_other)
, m_atomic(a_other.m_atomic)
{
    ++*m_atomic;
}

template<typename T>
SharedPointer<T>::~SharedPointer()
{
    --*m_atomic;
    if(((m_atomic)->getValue()) == 0)
    {
        delete m_atomic;
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
    copyIf(a_other.m_other,a_other.m_atomic);
    return *this;
}

template<typename T>
template<typename U>
SharedPointer<T>::SharedPointer(SharedPointer<U>const& a_other)
: m_other(a_other.m_other)
, m_atomic(a_other.m_atomic)
{
    ++*m_atomic;
}

template<typename T>
template<typename U>
SharedPointer<T>& SharedPointer<T>::operator =(SharedPointer<U> const& a_other)
{
    if(this->m_other != a_other.m_other)
    {
        destroy();
        copyIf(a_other.m_other,a_other.m_atomic);
    }
    return *this;
}

template<typename T>
void SharedPointer<T>::destroy()
{
        if(m_atomic)
            assert(m_atomic!=0);
        {
        }
        if(--(*m_atomic) == 0)
        {
            delete m_atomic;
            delete m_other;
        }
}

template<typename T>
void SharedPointer<T>::copyIf(T* a_m_other,Atomic<size_t>* a_atomic)
{
    if(this->m_other != a_m_other)
    {
        m_other = a_m_other;
        m_atomic=a_atomic;
        if(m_atomic)
        {
            ++m_atomic;
        }
    }
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
Atomic<size_t>* SharedPointer<T>::getAtomicPtr() const
{
    return m_atomic;
}

template<typename T>
T* SharedPointer<T>::getMOther() const
{
    return m_other;
}

template<typename T>
size_t SharedPointer<T>::getMAtomic() const
{
    return m_atomic->getValue();
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
    std::swap(m_atomic,a_other.m_atomic);
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