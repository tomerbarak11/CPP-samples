#include "Mutex.h"
Mutex::Mutex()
{
    mutexInit();
}

void Mutex::mutexInit()
{
    pthread_mutex_init(&m_locker,NULL);
}

void Mutex::lock()
{
    pthread_mutex_lock(&m_locker);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&m_locker);
}

pthread_mutex_t& Mutex::getLocker()
{
    return m_locker;
}
