#include "MutexLocker.h"

MutexLocker::MutexLocker(pthread_mutex_t& a_locker)
: m_locker(&a_locker)
{
}

pthread_mutex_t* MutexLocker::getLocker()
{
    return m_locker;
}

void MutexLocker::pthread_mutex_initFunc()
{
    pthread_mutex_init(m_locker,NULL);
}

void MutexLocker::pthread_mutex_lockFunc()
{
    pthread_mutex_lock(m_locker);
}

void MutexLocker::pthread_mutex_unlockFunc()
{
    pthread_mutex_unlock(m_locker);
}
