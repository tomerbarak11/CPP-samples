#ifndef PRODUCER_H
#define PRODUCER_H
#include "Thread.h"
#include "WaitableQueue.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

template<typename T>
class Producer: public Thread
{
public:
    Producer(WaitableQueue<T>& wq,size_t numberOfItemsToProduce, size_t a_delay);
    void run();
    T produce() const;
private:
    WaitableQueue<T>& m_wq;
    size_t m_numOfItemsToProduce;
    size_t m_delay;
};

template<typename T>
Producer<T>::Producer(WaitableQueue<T>& wq,size_t numberOfItemsToProduce, size_t a_delay)
: m_wq(wq)
, m_numOfItemsToProduce(numberOfItemsToProduce)
, m_delay(a_delay)
{
}

template<typename T>
void Producer<T>::run()
{
    for(size_t i=0;i<m_numOfItemsToProduce;++i)
    {
        usleep(m_delay);
        size_t item=produce();
        m_wq.enqueue(item);
    }
}

template<typename T>
T Producer<T>::produce() const
{
    srand (time(NULL));
    return rand()%m_numOfItemsToProduce;
}

#endif
