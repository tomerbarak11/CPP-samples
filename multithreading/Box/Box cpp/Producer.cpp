#include "Producer.h"
#include <unistd.h>
#include <iostream>

Producer::Producer(std::deque<int>& a_deq,Mutex& a_mutex,Semaphore& a_empty
    ,Semaphore& a_full,size_t numberOfItemsToProduce, size_t a_delay)
: m_deq(a_deq)
, m_mutex(a_mutex)
, m_empty(a_empty)
, m_full(a_full)
, m_numOfItemsToProduce(numberOfItemsToProduce)
, m_delay(a_delay)
{
}

void Producer::run()
{
    for(size_t i=0;i<m_numOfItemsToProduce;++i)
    {
        usleep(m_delay);
        m_empty.down();
        m_mutex.lock();
        /*
        if(m_itemsCounter>=m_deq.size())
        {
            m_itemsCounter=0;
        }
        */
        std::cout<<"enqueue "<<m_itemsCounter<<"\n";
        m_itemsCounter++;
        m_deq.push_back(m_itemsCounter);
        m_mutex.unlock();
        m_full.up();
    }
}