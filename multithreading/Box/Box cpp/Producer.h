#ifndef PRODUCER_H
#define PRODUCER_H
#include "Thread.h"
#include "WaitableQueue.h"
class Producer: public Thread
{
public:
    Producer(std::deque<int>& a_deq,Mutex& a_mutex,Semaphore& a_empty
    ,Semaphore& a_full,size_t numberOfItemsToProduce,
     size_t a_delay);
    void run();
private:
    std::deque<int>& m_deq;
    Mutex& m_mutex;
    Semaphore& m_empty;
    Semaphore& m_full;
    size_t m_itemsCounter; 
    size_t m_numOfItemsToProduce;
    size_t m_delay;
};


#endif
