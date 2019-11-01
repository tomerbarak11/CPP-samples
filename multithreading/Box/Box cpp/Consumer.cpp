#include "Consumer.h"
#include <unistd.h>
#include "WaitableQueue.h"
#include <iostream>
Consumer::Consumer(std::deque<int>& a_deq,Mutex& a_mutex,Semaphore& a_empty
    ,Semaphore& a_full,size_t a_delay)
: m_deq(a_deq)
, m_mutex(a_mutex)
, m_empty(a_empty)
, m_full(a_full)
, m_delay(a_delay)
{
}

void Consumer::run()
{
    while(1)
    {
        usleep(m_delay);
        m_full.down();
        m_mutex.lock();
        std::cout<<"dequeue "<<m_deq.front()<<"\n";
        m_deq.pop_front();
        //m_itemsCounter--;
        m_mutex.unlock();
        m_empty.up();
    }
}