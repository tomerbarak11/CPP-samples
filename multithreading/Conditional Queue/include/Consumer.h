#ifndef CONSUMER_H
#define CONSUMER_H
#include "WaitableQueue.h"
#include "Thread.h"
#include <unistd.h>
template<typename T>
class Consumer: public Thread
{
public:
    Consumer(WaitableQueue<T>& a_wq,size_t& a_numOfProducers,Mutex& a_numOfProducersMutex, size_t a_delay);
    void consume();
    void run();
    size_t getNumConsumed() const;

private:
    WaitableQueue<T>& m_wq;
    size_t& m_numOfProducers;
    Mutex& m_numOfProducersMutex;
    size_t m_delay;
    size_t m_numConsumed;

};

template<typename T>
Consumer<T>::Consumer(WaitableQueue<T>& a_wq,size_t& a_numOfProducers,Mutex& a_numOfProducersMutex, size_t a_delay)
: m_wq(a_wq)
, m_numOfProducers(a_numOfProducers)
, m_numOfProducersMutex(a_numOfProducersMutex)
, m_delay(a_delay)
, m_numConsumed(0)
{
}

template<typename T>
void Consumer<T>::run()
{
    while(1)
    {
        try
        {
            T item=m_wq.dequeue();
            std::cout<<"Dequeued item = "<<item<<"\n";
            ++m_numConsumed;   
        }
        catch(std::runtime_error& e)
        {
            std::cerr << e.what() << '\n';
            break;
        }
        usleep(m_delay);

    }
}

template<typename T>
size_t Consumer<T>::getNumConsumed() const
{
    return m_numConsumed;
}

#endif