#include "IncMutex.h"
#include <unistd.h>
#include <iostream>

IncMutex::IncMutex(int& a_global,size_t a_count, size_t a_delay,MutexLocker &a_locker)
: IncThread(a_global,a_count,a_delay)
, m_locker(a_locker)
{
}

void IncMutex::run()
{
    m_locker.pthread_mutex_initFunc();
    for(size_t i=0;i<IncThread::m_count;i++)
    {
        m_locker.pthread_mutex_lockFunc(); 

        ++((IncThread::m_global));

        m_locker.pthread_mutex_unlockFunc(); 
        usleep(IncThread::m_delay);
    }
}


