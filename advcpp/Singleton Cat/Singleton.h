#ifndef SINGLETON_H
#define SINGLETON_H
#include "Uncopyable.h"
#include "Atomic.h"
#include "FirstFlag.h"
#include "FinishFlag.h"
#include <unistd.h>
#include <iostream>

template<typename T>
class Singleton:public Uncopyable
{
public:
    ~Singleton();
    size_t getOne() const;
    size_t getAtomicCounter() const;
    void setAtomicCounter(size_t a_size);
    template<typename D>
    static T& instance(D a_d);
private:
    static T* m_sInstance;
    static Atomic<size_t> *m_one;
    static Atomic<size_t> *m_atomicCounter;
    static FirstFlag m_first;
    static FinishFlag m_finish;
};

template<typename T>
T* Singleton<T>::m_sInstance=0;
template<typename T>
Atomic<size_t>* Singleton<T>::m_one=0;
template<typename T>
Atomic<size_t>* Singleton<T>::m_atomicCounter=0;
template<typename T>
FirstFlag Singleton<T>::m_first;
template<typename T>
FinishFlag Singleton<T>::m_finish;

template<typename T>
Singleton<T>::~Singleton()
{
    //delete m_atomicCounter;
    //delete m_one;
    //delete m_sInstance;
}


template<typename T>
template<typename D>
T& Singleton<T>::instance(D a_d)
{

    if(m_first.flip(false,true))   
    {
        try      
        {           
            m_sInstance=new T(a_d);
            m_finish.set();        
        }   
        catch(const std::exception& e) 
        {
            std::cerr << e.what() << '\n';       
        }

        try     
        {       
            m_one=new Atomic<size_t>(1);  
        }  
        catch(const std::exception& e)    
        {     
            std::cerr << e.what() << '\n';       
        }

        try     
        {       
            m_atomicCounter=new Atomic<size_t>(0);  
        }  
        catch(const std::exception& e)    
        {     
            std::cerr << e.what() << '\n';       
        }
    }  
    else    
    {       
        while(!m_finish.isSet())      
        {
            usleep(1);   
        }
    }
    ++*m_atomicCounter;
    T& q=*m_sInstance;  
    return q;
}

template<typename T>
size_t Singleton<T>::getOne() const
{
    return m_one->getValue();
}

template<typename T>
size_t Singleton<T>::getAtomicCounter() const
{
    return m_atomicCounter->getValue();
}

template<typename T>
void Singleton<T>::setAtomicCounter(size_t a_size)
{
    m_atomicCounter->setValue(a_size);
}

#endif
