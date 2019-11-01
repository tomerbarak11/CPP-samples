#ifndef PRODUCER_H
#define PRODUCER_H
#include "Thread.h"
#include "WaitableQueue.h"
#include <unistd.h>

template<typename T>
class Producer: public Thread
{
public:
    Producer(WaitableQueue<T>& wq,size_t numberOfItemsToProduce, size_t a_delay);
    void run();
    T produce() const;
    size_t getNumProduced() const;
private:
    WaitableQueue<T>& m_wq;
    size_t m_numOfItemsToProduce;
    size_t m_delay;
    size_t m_numProduced;
};

template<typename T>
Producer<T>::Producer(WaitableQueue<T>& wq,size_t numberOfItemsToProduce, size_t a_delay)
: m_wq(wq)
, m_numOfItemsToProduce(numberOfItemsToProduce)
, m_delay(a_delay)
, m_numProduced()
{
}

template<typename T>
void Producer<T>::run()
{
    for(size_t i=0;i<m_numOfItemsToProduce;++i)
    {
        size_t item=produce();
        try
        {
            m_wq.enqueue(item);
            ++m_numProduced;
        }
        catch(std::runtime_error& e)
        {
            std::cerr << e.what() << '\n';
        }
        usleep(m_delay);

    }
}

template<typename T>
T Producer<T>::produce() const
{
    return rand()%m_numOfItemsToProduce;
}

template<typename T>
size_t Producer<T>::getNumProduced() const
{
    return m_numProduced;
}

#endif