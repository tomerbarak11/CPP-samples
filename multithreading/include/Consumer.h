#ifndef CONSUMER_H
#define CONSUMER_H
#include "WaitableQueue.h"
#include "Thread.h"
#include <unistd.h>

template<typename T>
class Consumer: public Thread
{
public:
    Consumer(WaitableQueue<T>& a_wq, size_t a_delay);
    void consume();
    void run();
private:
    WaitableQueue<T>& m_wq;
    size_t m_delay;
};

template<typename T>
Consumer<T>::Consumer(WaitableQueue<T>& a_wq, size_t a_delay)
: m_wq(a_wq)
, m_delay(a_delay)
{
}

template<typename T>
void Consumer<T>::run()
{
    while(1)
    {
        usleep(m_delay);
        m_wq.dequeue();
    }
}

#endif
