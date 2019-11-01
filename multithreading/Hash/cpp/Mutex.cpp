#include "Mutex.h"
Mutex::Mutex()
{
    mutexInit();
}

void Mutex::mutexInit()
{
    pthread_mutex_init(&m_mutex,NULL);
}

void Mutex::lock()
{
    pthread_mutex_lock(&m_mutex);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&m_mutex);
}

pthread_mutex_t& Mutex::getMutex()
{
    return m_mutex;
}
