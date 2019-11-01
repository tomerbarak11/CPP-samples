#ifndef WAITABLEQUEUE_H
#define WAITABLEQUEUE_H
#include <queue>
#include <cstddef>
#include "ConditionalVariable.h"
#include <iostream>
#include <unistd.h>
template<typename T>
class WaitableQueue
{
public:
    WaitableQueue(size_t a_size);
    ~WaitableQueue();
    void enqueue(T a_item);
    T dequeue();
    void destroy();
    size_t getNumbOfProduced() const;
    size_t getNumbOfConsumed() const;
    size_t getSize() const;
    bool isFull() const;
    bool isEmpty() const;

private:
    std::queue<T> m_queue;
    ConditionalVariable m_cond;
    size_t m_capacity;
    bool m_isBeingDestroyed;
    size_t m_numberOfWaiting;
};



template<typename T>
WaitableQueue<T>::WaitableQueue(size_t a_size)
: m_capacity(a_size)
, m_isBeingDestroyed(false)
, m_numberOfWaiting(0)
{
}

template<typename T>
WaitableQueue<T>::~WaitableQueue()
{
    m_cond.lock();
    m_isBeingDestroyed=true;
    m_cond.unlock();
    if(m_numberOfWaiting>0)
    {
        m_cond.broadcast();
        m_cond.wait();
    }
}

template<typename T>
void WaitableQueue<T>::enqueue(T a_item)
{
    m_cond.lock();

    while(!m_isBeingDestroyed && isFull())
    {
        ++m_numberOfWaiting;
        m_cond.wait();
        --m_numberOfWaiting;
    }

    if(m_isBeingDestroyed)
    {
        if(m_numberOfWaiting==0)
        {
            m_cond.signal();
        }
        m_cond.unlock();
        throw std::runtime_error("enqueue");
    }
    else
    {
        std::cout<<"Enqueue item = "<<a_item<<"\n";
        m_queue.push(a_item);
        m_cond.signal(); 
        m_cond.unlock();
    }
}

template<typename T>
T WaitableQueue<T>::dequeue()
{
    m_cond.lock();

    while(!m_isBeingDestroyed && isEmpty())
    {
        ++m_numberOfWaiting;
        m_cond.wait();
        --m_numberOfWaiting;
    }

    if(m_isBeingDestroyed)
    {
        if(m_numberOfWaiting==0)
        {
            m_cond.signal();
        }
        m_cond.unlock();
        throw std::runtime_error("dequeue");
    }

    else
    {
        T ret=m_queue.front();
        m_queue.pop();
        m_cond.signal(); 
        m_cond.unlock();
        return ret;
    }
}

template<typename T>
void WaitableQueue<T>::destroy()
{
    m_cond.lock();
    m_isBeingDestroyed=true;
    m_cond.unlock();
}

template<typename T>
bool WaitableQueue<T>::isFull() const
{
    return m_queue.size()==m_capacity;
}

template<typename T>
bool WaitableQueue<T>::isEmpty() const
{
    return m_queue.size()==0;
} 

template<typename T>
size_t WaitableQueue<T>::getSize() const
{
    return m_queue.size();
}

#endif