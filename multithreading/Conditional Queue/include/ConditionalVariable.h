#ifndef CONDITIONALVARIABLE_H
#define CONDITIONALVARIABLE_H
#include <pthread.h>
#include "Mutex.h"

class ConditionalVariable: public Mutex
{
public:
    ConditionalVariable();
    void wait();
    void signal();
    void broadcast();
    void lock();
    void unlock();

    pthread_mutex_t getMutex() const;

private:
    pthread_cond_t m_condition;
};

#endif