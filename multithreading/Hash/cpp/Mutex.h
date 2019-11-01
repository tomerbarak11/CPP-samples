#ifndef MUTEX_H
#define MUTEX_H
#include <pthread.h>

class Mutex
{
public:
    Mutex();
    void mutexInit();
    void lock();
    void unlock();
    pthread_mutex_t& getMutex();
protected:
    pthread_mutex_t m_mutex;    
};

#endif
