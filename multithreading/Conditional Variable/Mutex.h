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
    pthread_mutex_t& getLocker();
private:
    pthread_mutex_t m_locker;    
};

#endif
