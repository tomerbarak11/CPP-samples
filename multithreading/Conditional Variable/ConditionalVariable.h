#ifndef CONDITIONALVARIABLE_H
#define CONDITIONALVARIABLE_H
#include <pthread.h>
#include "Mutex.h"

class ConditionalVariable: public Mutex
{
public:
    ConditionalVariable(Mutex& a_mutex);
    void wait();
    void signal();
    void broadcast();
    pthread_cond_t getCondition();

private:
    pthread_cond_t m_condition;
    Mutex& m_mutex;
};

#endif