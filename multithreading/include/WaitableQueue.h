#ifndef WAITABLEQUEUE_H
#define WAITABLEQUEUE_H
#include "Mutex.h"
#include "Semaphore.h"
#include <queue>
#include <cstddef>
#include <iostream>

template<typename T>
class WaitableQueue
{
public:
    WaitableQueue(size_t a_size);
    void enqueue(T a_item);
    void dequeue();
    size_t getNumbOfProduced() const;
    size_t getNumbOfConsumed() const;
    size_t getNumOfItems() const;
    size_t createItemSize_t();
private:
    std::queue<T> m_deq;
    Mutex m_mutex;
    Semaphore m_empty;
    Semaphore m_full;
    size_t m_itemsCounter;
    size_t m_numbOfProduced;
    size_t m_numbOfConsumed;

};

template<typename T>
WaitableQueue<T>::WaitableQueue(size_t a_size)
: m_mutex()
, m_empty(a_size)
, m_full(0)
, m_itemsCounter(0)
, m_numbOfProduced(0)
, m_numbOfConsumed(0)
{
}

template<typename T>
void WaitableQueue<T>::enqueue(T a_item)
{
    m_empty.down();
    m_mutex.lock();
    std::cout<<"enqueue "<<m_itemsCounter<<"\n";
    m_deq.push(a_item);
    ++m_itemsCounter;
    ++m_numbOfProduced;
    m_mutex.unlock();
    m_full.up();
}

template<typename T>
void WaitableQueue<T>::dequeue()
{
    m_full.down();
    m_mutex.lock();
    std::cout<<"dequeue "<<m_deq.front()<<"\n";
    m_deq.pop();
    --m_itemsCounter;
    ++m_numbOfConsumed;
    m_mutex.unlock();
    m_empty.up();
}

template<typename T>
size_t WaitableQueue<T>::getNumOfItems() const
{
    return m_itemsCounter;
}

template<typename T>
size_t WaitableQueue<T>::getNumbOfProduced() const
{
    return m_numbOfProduced;
}

template<typename T>
size_t WaitableQueue<T>::getNumbOfConsumed() const
{
    return m_numbOfConsumed;
}

#endif