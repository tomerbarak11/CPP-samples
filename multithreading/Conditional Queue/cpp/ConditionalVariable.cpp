#include "ConditionalVariable.h"

ConditionalVariable::ConditionalVariable()
{
    pthread_cond_init(&m_condition,NULL);
}

void ConditionalVariable::wait()
{
    pthread_cond_wait(&m_condition,&m_mutex);
}

void ConditionalVariable::signal()
{
    pthread_cond_signal(&m_condition);
}

void ConditionalVariable::broadcast()
{
    pthread_cond_broadcast(&m_condition);
}

pthread_mutex_t ConditionalVariable::getMutex() const
{
    return m_mutex;
}

void ConditionalVariable::lock()
{
    pthread_mutex_lock(&m_mutex);
}

void ConditionalVariable::unlock()
{
    pthread_mutex_unlock(&m_mutex);
}