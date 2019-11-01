#include "ConditionalVariable.h"

ConditionalVariable::ConditionalVariable(Mutex& a_mutex)
: m_mutex(a_mutex)
{
}

void ConditionalVariable::wait()
{
    Mutex temp;
    pthread_cond_wait(&m_condition,&temp.getLocker());
}

void ConditionalVariable::signal()
{
    pthread_cond_signal(&m_condition);
}

void ConditionalVariable::broadcast()
{
    pthread_cond_broadcast(&m_condition);
}
