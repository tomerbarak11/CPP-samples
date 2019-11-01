#ifndef CONSUMER_H
#define CONSUMER_H
#include "WaitableQueue.h"
#include "Thread.h"

class Consumer: public Thread
{
public:
    Consumer(std::deque<int>& a_deq,Mutex& a_mutex,Semaphore& a_empty
    ,Semaphore& a_full,size_t a_delay);
    void consume();
    void run();
private:
    std::deque<int>& m_deq;
    Mutex& m_mutex;
    Semaphore& m_empty;
    Semaphore& m_full;
    size_t m_delay;
};

#endif
